#ifndef GRAPH_LOGIC_H_a8416e83_484a_4abb_8edc_4f2cd9ee9857
#define GRAPH_LOGIC_H_a8416e83_484a_4abb_8edc_4f2cd9ee9857

#include "IGraphLogic.h"
#include "IGraph.h"

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
            explicit GraphLogic(IGraphPtr<TKey, TValue> graph);

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
                const IVertex<TKey, TValue>& src,
                const std::map<IEdgePtr<TKey, TValue>, size_t> weights,
                std::map<IVertexPtr<TKey, TValue>, size_t>& result) const override;

        private:
            /**
             * Detects whether a graph contains a loop.
             */
            bool detectLoop(
                IVertexPtr<TKey, TValue> vertex,
                VertexSet<TKey, TValue>& visitedVertices,
                VertexSet<TKey, TValue>& searchVertices) const;
                    
            IGraphPtr<TKey, TValue> m_graph;
        };

        /**
         * The GraphLogic constructor.
         */
        template <typename TKey, typename TValue>
        GraphLogic<TKey, TValue>::GraphLogic(IGraphPtr<TKey, TValue> graph) :
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

            for (IVertexPtr<TKey, TValue> vertex : m_graph->vertices()) {

                if (visitedVertices.find(vertex) != visitedVertices.end()) {
                    continue;
                }

                if (detectLoop(vertex, visitedVertices, searchVertices)) {
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
        }

        /**
         * Finds paths by performing a Breadth-First search.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findPathsWithBreadthFirstSearch(
            const IRoute<TKey, TValue>& route,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
        }

        /**
         * Finds paths by performing a Depth-First search.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findPathsWithDepthFirstSearch(
            const IRoute<TKey, TValue>& route,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
        }

        /**
         * Finds the shortest paths from the source vertex to all other vertices in the given graph.
         */
        template <typename TKey, typename TValue>
        void GraphLogic<TKey, TValue>::findShortestPaths(
            const IVertex<TKey, TValue>& src,
            const std::map<IEdgePtr<TKey, TValue>, size_t> weights,
            std::map<IVertexPtr<TKey, TValue>, size_t>& result) const
        {
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
            m_graph->getAdjacencyMatrix().getAdjacentVertices(vertex, adjacentVertices);

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
    }
}

#endif // GRAPH_LOGIC_H_a8416e83_484a_4abb_8edc_4f2cd9ee9857
