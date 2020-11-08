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
                const IVertex<TKey, TValue>& src,
                const std::map<IEdgePtr<TKey, TValue>, size_t> weights,
                std::map<IVertexPtr<TKey, TValue>, size_t>& result) const override;

        private:
            IGraph<TKey, TValue> m_graph;
        };

        /**
         * The GraphLogic constructor.
         */
        template <typename TKey, typename TValue>
        GraphLogic::GraphLogic(const IGraph<TKey, TValue>& graph) :
            m_graph(graph)
        {
        }

        /**
         * The GraphLogic destructor.
         */
        virtual GraphLogic::~GraphLogic()
        {
        }

        /**
         * Detects whether a graph contains a loop.
         */
        bool GraphLogic::detectLoop() const
        {
            return true;
        }

        /**
         * Performs a topological search of a graph.
         */
        void GraphLogic::topologicalSearch(std::list<IVertexPtr<TKey, TValue>>& result) const
        {
        }

        /**
         * Finds paths by performing a Breadth-First search.
         */
        void GraphLogic::findPathsWithBreadthFirstSearch(
            const IRoute<TKey, TValue>& route,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
        }

        /**
         * Finds paths by performing a Depth-First search.
         */
        void GraphLogic::findPathsWithDepthFirstSearch(
            const IRoute<TKey, TValue>& route,
            std::list<IWalkPtr<TKey, TValue>>& result) const
        {
        }

        /**
         * Finds the shortest paths from the source vertex to all other vertices in the given graph.
         */
        void GraphLogic::findShortestPaths(
            const IVertex<TKey, TValue>& src,
            const std::map<IEdgePtr<TKey, TValue>, size_t> weights,
            std::map<IVertexPtr<TKey, TValue>, size_t>& result) const
        {
        }
    }
}

#endif // GRAPH_LOGIC_H_a8416e83_484a_4abb_8edc_4f2cd9ee9857
