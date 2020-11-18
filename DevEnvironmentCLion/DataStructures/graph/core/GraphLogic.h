#ifndef GRAPH_LOGIC_H_a8416e83_484a_4abb_8edc_4f2cd9ee9857
#define GRAPH_LOGIC_H_a8416e83_484a_4abb_8edc_4f2cd9ee9857

#include "IGraphLogic.h"
#include "IGraph.h"
#include "Walk.h"

namespace datastructures {
    namespace graph {

        /**
         * The GraphLogic class implements logic of a graph.
         */
        template <typename TKey, typename TValue>
        class GraphLogic final : public IGraphLogic<TKey, TValue>
        {
        public:
            /**
             * The GraphLogic constructor.
             */
            explicit GraphLogic(const IGraph<TKey, TValue>& graph);

            /**
             * The GraphLogic destructor.
             */
            virtual ~GraphLogic();

            /**
             * The copy/move constructors.
             */
            GraphLogic(const GraphLogic&) = delete;
            GraphLogic(GraphLogic&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            GraphLogic& operator=(const GraphLogic&) = delete;
            GraphLogic& operator=(GraphLogic&&) = delete;

            /**
             * Detects whether a graph contains a loop.
             */
            virtual bool detectLoop() const override;

            /**
             * Performs a topological search of a graph.
             */
            virtual void topologicalSearch(
                std::list<IVertexPtr<TKey, TValue>>& result) const override;

            /**
             * Finds paths by performing a Breadth-First search.
             */
            virtual void findPathsWithBreadthFirstSearch(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkPtr<TKey, TValue>>& result) const override;

            /**
             * Finds paths by performing a Depth-First search.
             */
            virtual void findPathsWithDepthFirstSearch(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkPtr<TKey, TValue>>& result) const override;

            /**
             * Finds the shortest paths from the source vertex to all other vertices in the given graph.
             */
            virtual void findShortestPaths(
                IVertexPtr<TKey, TValue> src,
                const EdgeWeightMap<TKey, TValue>& weights,
                VertexShortestPathsMap<TKey, TValue>& result) const override;

        private:
            /**
             * Detects whether a graph contains a loop.
             */
            bool detectLoop(
                IVertexPtr<TKey, TValue> vertex,
                VertexSet<TKey, TValue>& visitedVertices,
                VertexSet<TKey, TValue>& searchVertices) const;

            /**
             * Tries to perform a topological search of a graph.
             */
            bool topologicalSearch(
                IVertexPtr<TKey, TValue> vertex,
                std::set<IVertexPtr<TKey, TValue>>& visitedVertices,
                std::set<IVertexPtr<TKey, TValue>>& currPath,
                std::stack<IVertexPtr<TKey, TValue>>& result) const;

            /**
             * Finds paths by performing a Breadth-First search.
             */
            void findPathsWithBreadthFirstSearch(
                IVertexPtr<TKey, TValue> source,
                IVertexPtr<TKey, TValue> destination,
                std::list<IWalkPtr<TKey, TValue>>& result) const;

            /**
             * Finds paths by performing a Depth-First search.
             */
            void findPathsWithDepthFirstSearch(
                IVertexPtr<TKey, TValue> source,
                IVertexPtr<TKey, TValue> destination,
                IWalk<TKey, TValue>& currPath,
                std::set<IVertexPtr<TKey, TValue>>& visited,
                std::list<IWalkPtr<TKey, TValue>>& result) const;

            /**
             * Gets weight of an edge.
             */
            static long getEdgeWeight(
                const EdgeWeightMap<TKey, TValue>& weights,
                IEdgePtr<TKey, TValue> edge);

            /**
             * Gets shortest distance of a vertex.
             */
            static long getShortestDistance(
                const VertexShortestPathsMap<TKey, TValue>& shortestPathsMap,
                IVertexPtr<TKey, TValue> vertex);

            const IGraph<TKey, TValue>& m_graph;
        };

        /**
         * The GraphLogic constructor.
         */
        template <typename TKey, typename TValue>
        GraphLogic<TKey, TValue>::GraphLogic(const IGraph<TKey, TValue>& graph) :
            m_graph(graph)
        {
        }

        /**
         * The GraphLogic destructor.
         */
        template <typename TKey, typename TValue>
        GraphLogic<TKey, TValue>::~GraphLogic()
        {
        }

        /**
         * Detects whether a graph contains a loop.
         */
        template <typename TKey, typename TValue>
        bool GraphLogic<TKey, TValue>::detectLoop() const
        {
            VertexSet<TKey, TValue> visitedVertices;
            VertexSet<TKey, TValue> searchVertices;

            const VertexSet<TKey, TValue>& vertices = m_graph.vertices();
            for (IVertexPtr<TKey, TValue> vertex : vertices)
            {
                if (visitedVertices.find(vertex) != visitedVertices.end())
                {
                    continue;
                }

                if (detectLoop(vertex, visitedVertices, searchVertices))
                {
                    return true;
                }

                assert(searchVertices.empty());
            }

            return false;
        }

        /**
         * Performs a topological search of a graph.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::topologicalSearch(std::list<IVertexPtr<TKey, TValue>>& result) const
        {
            std::stack<IVertexPtr<TKey, TValue>> resultStack;
            std::set<IVertexPtr<TKey, TValue>> visitedVertices;
            std::set<IVertexPtr<TKey, TValue>> currPath;

            const VertexSet<TKey, TValue>& vertices = m_graph.vertices();
            for (IVertexPtr<TKey, TValue> vertex : vertices)
            {
                if (visitedVertices.find(vertex) != visitedVertices.end())
                {
                    continue;
                }

                if (!topologicalSearch(
                        vertex,
                        visitedVertices,
                        currPath,
                        resultStack))
                {
                    std::string errorMessage =
                        "The graph contains a loop, aborting topological search. No topological search is possible.";

                    throw GraphException(errorMessage);
                }

                assert(currPath.empty());
            }

            while (!resultStack.empty())
            {
                result.push_back(resultStack.top());
                resultStack.pop();
            }
        }

        /**
         * Finds paths by performing a Breadth-First search.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findPathsWithBreadthFirstSearch(
            const IRoute<TKey, TValue>& route,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
            findPathsWithBreadthFirstSearch(route.source(), route.destination(), result);
        }

        /**
         * Finds paths by performing a Depth-First search.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findPathsWithDepthFirstSearch(
            const IRoute<TKey, TValue>& route,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
            IVertexPtr<TKey, TValue> source = route.source();
            IVertexPtr<TKey, TValue> destination = route.destination();

            IWalkPtr<TKey, TValue> currPath = Walk<TKey, TValue>::make();
            std::set<IVertexPtr<TKey, TValue>> visited;

            findPathsWithDepthFirstSearch(
                source,
                destination,
                *currPath,
                visited,
                result);
        }

        /**
         * Finds the shortest paths from the source vertex to all other vertices in the given graph.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findShortestPaths(
            IVertexPtr<TKey, TValue> src,
            const EdgeWeightMap<TKey, TValue>& weights,
            VertexShortestPathsMap<TKey, TValue>& result) const
        {
            base::SmartPointers::validate(src);

            //
            // Initializes the distances map...
            //
            for (IVertexPtr<TKey, TValue> vertex : m_graph.vertices())
            {
                long initializedDistance = *vertex == *src ? 0 : std::numeric_limits<long>::max();
                result.insert(std::make_pair(vertex, initializedDistance));
            }

            using Dqueue = std::deque<std::pair<IVertexPtr<TKey, TValue>, long>>;
            Dqueue queue;
            queue.push_back(std::make_pair(src, 0));

#ifdef _DEBUG
            std::function<void(const typename Dqueue::value_type& value, std::ostream& stream)> queueFunctor =
                [](const typename Dqueue::value_type& value, std::ostream& stream)
            {
                IVertexPtr<TKey, TValue> vertex = value.first;
                long distance = value.second;
                stream << "Vertex=" << *vertex << ", Distance=" << distance;
            };

            std::function<void(const typename VertexShortestPathsMap<TKey, TValue>::value_type& value, std::ostream& stream)> resultFunctor =
                [](const typename VertexShortestPathsMap<TKey, TValue>::value_type& value, std::ostream& stream)
            {
                IVertexPtr<TKey, TValue> vertex = value.first;
                long distance = value.second;
                stream << "Vertex=" << *vertex << ", Distance=" << distance;
            };

            std::string queueContent = base::Collections::toString(queue, queueFunctor);
            std::string resultContent = base::Collections::toString(result, resultFunctor);
#endif

            while (!queue.empty())
            {
                std::pair<IVertexPtr<TKey, TValue>, long> currElement = queue.front();
                queue.pop_front();

                IVertexPtr<TKey, TValue> currVertex = currElement.first;
                long currDistance = currElement.second;

                EdgeSet<TKey, TValue> adjacentEdges;
                m_graph.getAdjacencyMatrix().getAdjacentEdges(currVertex, adjacentEdges);

                for (IEdgePtr<TKey, TValue> adjacentEdge : adjacentEdges)
                {
                    IVertexPtr<TKey, TValue> nextVertex = adjacentEdge->destination();
                    long edgeWeight = getEdgeWeight(weights, adjacentEdge);

                    long nextDistance = currDistance + edgeWeight;
                    long nextVertexDistance = getShortestDistance(result, nextVertex);

                    if (nextDistance < nextVertexDistance)
                    {
                        result[nextVertex] = nextDistance;
                        queue.push_back(std::make_pair(nextVertex, nextDistance));
#ifdef _DEBUG
                        queueContent = base::Collections::toString(queue, queueFunctor);
                        resultContent = base::Collections::toString(result, resultFunctor);
#endif
                    }
                }
            }
        }

        /**
         * Detects whether a graph contains a loop.
         */
        template <typename TKey, typename TValue>
        bool GraphLogic<TKey, TValue>::detectLoop(
            IVertexPtr<TKey, TValue> vertex,
            VertexSet<TKey, TValue>& visitedVertices,
            VertexSet<TKey, TValue>& searchVertices) const
        {
            typename VertexSet<TKey, TValue>::iterator visitedVertexIterator = visitedVertices.find(vertex);

            if (visitedVertexIterator != visitedVertices.end())
            {
                return false;
            }

            visitedVertices.insert(visitedVertexIterator, vertex);
            searchVertices.insert(vertex);

            VertexSet<TKey, TValue> adjacentVertices;
            m_graph.getAdjacencyMatrix().getAdjacentVertices(vertex, adjacentVertices);

            for (IVertexPtr<TKey, TValue> nextVertex : adjacentVertices)
            {
                if (searchVertices.find(nextVertex) != searchVertices.end())
                {
                    return true;
                }

                if (visitedVertices.find(nextVertex) != visitedVertices.end())
                {
                    continue;
                }

                if (detectLoop(nextVertex, visitedVertices, searchVertices))
                {
                    return true;
                }
            }

            searchVertices.erase(vertex);

            return false;
        }

        /**
         * Performs a topological search of a graph.
         */
        template <typename TKey, typename TValue>
        bool GraphLogic<TKey, TValue>::topologicalSearch(
            IVertexPtr<TKey, TValue> vertex,
            std::set<IVertexPtr<TKey, TValue>>& visitedVertices,
            std::set<IVertexPtr<TKey, TValue>>& currPath,
            std::stack<IVertexPtr<TKey, TValue>>& result) const
        {
            if (visitedVertices.find(vertex) != visitedVertices.end())
            {
                return true;
            }

            visitedVertices.insert(vertex);
            currPath.insert(vertex);

            VertexSet<TKey, TValue> adjacentVertices;
            m_graph.getAdjacencyMatrix().getAdjacentVertices(vertex, adjacentVertices);

            for (IVertexPtr<TKey, TValue> nextVertex : adjacentVertices)
            {
                if (currPath.find(nextVertex) != currPath.end())
                {
                    return false;
                }

                if (visitedVertices.find(nextVertex) != visitedVertices.end())
                {
                    continue;
                }

                if (!topologicalSearch(
                        nextVertex,
                        visitedVertices,
                        currPath,
                        result)) {

                    return false;
                }
            }

            currPath.erase(vertex);
            result.push(vertex);

            return true;
        }

        /**
         * Finds paths by performing a Breadth-First search.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findPathsWithBreadthFirstSearch(
            IVertexPtr<TKey, TValue> source,
            IVertexPtr<TKey, TValue> destination,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
            std::queue<std::pair<IVertexPtr<TKey, TValue>, IWalkPtr<TKey, TValue>>> queue;
            queue.push(std::make_pair(source, Walk<TKey, TValue>::make()));

            while (!queue.empty())
            {
                std::pair<IVertexPtr<TKey, TValue>, IWalkPtr<TKey, TValue>> currElement = queue.front();
                queue.pop();

                IVertexPtr<TKey, TValue> currVertex = currElement.first;
                IWalkPtr<TKey, TValue> currPath = currElement.second;

                currPath->addVertex(currVertex);

                if (*currVertex == *destination)
                {
                    IWalkPtr<TKey, TValue> newResult = Walk<TKey, TValue>::copy(*currPath);
                    result.push_back(newResult);
                }
                else
                {
                    VertexSet<TKey, TValue> adjacentVertices;
                    m_graph.getAdjacencyMatrix().getAdjacentVertices(currVertex, adjacentVertices);

                    for (IVertexPtr<TKey, TValue> nextVertex : adjacentVertices)
                    {
                        if (currPath->visited(*nextVertex))
                        {
                            continue;
                        }

                        IWalkPtr<TKey, TValue> nextWalk = Walk<TKey, TValue>::copy(*currPath);
                        nextWalk->addVertex(nextVertex);

                        queue.push(std::make_pair(nextVertex, nextWalk));
                    }
                }
            }
        }

        /**
         * Finds paths by performing a Depth-First search.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findPathsWithDepthFirstSearch(
            IVertexPtr<TKey, TValue> source,
            IVertexPtr<TKey, TValue> destination,
            IWalk<TKey, TValue>& currPath,
            std::set<IVertexPtr<TKey, TValue>>& visited,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
            if (visited.find(source) != visited.end())
            {
                return;
            }

            if (*source == *destination)
            {
                IWalkPtr<TKey, TValue> newResult = Walk<TKey, TValue>::copy(currPath);
                newResult->addVertex(source);
                result.push_back(newResult);

                return;
            }

            currPath.addVertex(source);
            visited.insert(source);

            VertexSet<TKey, TValue> adjacentVertices;
            m_graph.getAdjacencyMatrix().getAdjacentVertices(source, adjacentVertices);

            for (IVertexPtr<TKey, TValue> nextVertex : adjacentVertices)
            {
                if (visited.find(nextVertex) != visited.end())
                {
                    return;
                }

                findPathsWithDepthFirstSearch(
                    nextVertex,
                    destination,
                    currPath,
                    visited,
                    result);
            }

            currPath.removeLastVertex();
            visited.erase(source);
        }
    }

    /**
     * Gets weight of an edge.
     */
    template <typename TKey, typename TValue>
    long GraphLogic<TKey, TValue>::getEdgeWeight(
        const EdgeWeightMap<TKey, TValue>& weights,
        IEdgePtr<TKey, TValue> edge)
    {
        typename EdgeWeightMap<TKey, TValue>::const_iterator edgeIterator = weights.find(edge);

        if (edgeIterator == weights.end())
        {
            std::string errorMessage = "The weight of an edge is not defined in the adjacent matrix of the graph.";
            throw GraphException(errorMessage);
        }

        return edgeIterator->second;
    }

    /**
     * Gets shortest distance of a vertex.
     */
    template <typename TKey, typename TValue>
    long GraphLogic<TKey, TValue>::getShortestDistance(
        const VertexShortestPathsMap<TKey, TValue>& shortestDistancesMap,
        IVertexPtr<TKey, TValue> vertex)
    {
        typename VertexShortestPathsMap<TKey, TValue>::const_iterator vertexIterator = shortestDistancesMap.find(vertex);

        if (vertexIterator == shortestDistancesMap.end())
        {
            std::string errorMessage = "The vertex does not exist in the shortest distances map.";
            throw GraphException(errorMessage);
        }

        return vertexIterator->second;
    }
}

#endif // GRAPH_LOGIC_H_a8416e83_484a_4abb_8edc_4f2cd9ee9857
