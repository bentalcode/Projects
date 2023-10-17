#ifndef I_GRAPH_LOGIC_H_0f714d5e_2b5f_446c_a128_f7a064131ddd
#define I_GRAPH_LOGIC_H_0f714d5e_2b5f_446c_a128_f7a064131ddd

#include "IGraphDefinition.h"

namespace datastructures {
    namespace graph {

        /**
         * The IGraphLogic interface defines a graph definition.
         */
        template <typename TKey, typename TValue>
        class IGraphLogic
        {
        public:
            /**
             * The constructor.
             */
            IGraphLogic() = default;

            /**
             * The destructor.
             */
            virtual ~IGraphLogic() = default;

            /**
             * The Copy/move constructors.
             */
            IGraphLogic(const IGraphLogic&) = delete;
            IGraphLogic(IGraphLogic&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IGraphLogic& operator=(const IGraphLogic&) = delete;
            IGraphLogic& operator=(IGraphLogic&&) = delete;

            /**
             * Detects whether a graph Contains a loop.
             */
            virtual bool DetectLoop() const = 0;

            /**
             * Performs a topological search of a graph.
             */
            virtual void TopologicalSearch(
                std::list<IVertexSharedPtr<TKey, TValue>>& result) const = 0;

            /**
             * Finds paths by performing a Breadth-First search.
             */
            virtual void FindPathsWithBreadthFirstSearch(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkSharedPtr<TKey, TValue>>& result) const = 0;

            /**
             * Finds paths by performing a Depth-First search.
             */
            virtual void FindPathsWithDepthFirstSearch(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkSharedPtr<TKey, TValue>>& result) const = 0;

            /**
             * Finds the shortest paths from the Source vertex to all other Vertices in the given graph.
             */
            virtual void FindShortestPaths(
                IVertexSharedPtr<TKey, TValue> src,
                const EdgeWeightMap<TKey, TValue>& weights,
                VertexShortestPathsMap<TKey, TValue>& result) const = 0;
        };

        /**
         * Defines the SharedPtr Of Graph Logic.
         */
        template <typename TKey, typename TValue>
        using IGraphLogicSharedPtr = std::shared_ptr<IGraphLogic<TKey, TValue>>;
    }
}

#endif // I_GRAPH_LOGIC_H_0f714d5e_2b5f_446c_a128_f7a064131ddd
