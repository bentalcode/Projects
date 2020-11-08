#ifndef I_GRAPH_LOGIC_H_0f714d5e_2b5f_446c_a128_f7a064131ddd
#define I_GRAPH_LOGIC_H_0f714d5e_2b5f_446c_a128_f7a064131ddd

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
             * The copy/move constructors.
             */
            IGraphLogic(const IGraphLogic&) = delete;
            IGraphLogic(IGraphLogic&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IGraphLogic& operator=(const IGraphLogic&) = delete;
            IGraphLogic& operator=(IGraphLogic&&) = delete;

            /**
             * Detects whether a graph contains a loop.
             */
            virtual bool detectLoop() const = 0;

            /**
             * Performs a topological search of a graph.
             */
            virtual void topologicalSearch(
                std::list<IVertexPtr<TKey, TValue>>& result) const = 0;

            /**
             * Finds paths by performing a Breadth-First search.
             */
            virtual void findPathsWithBreadthFirstSearch(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkPtr<TKey, TValue>>& result) const = 0;

            /**
             * Finds paths by performing a Depth-First search.
             */
            virtual void findPathsWithDepthFirstSearch(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkPtr<TKey, TValue>>& result) const = 0;

            /**
             * Finds the shortest paths from the source vertex to all other vertices in the given graph.
             */
            virtual void findShortestPaths(
                const IVertex<TKey, TValue>& src,
                const std::map<IEdgePtr<TKey, TValue>, size_t> weights,
                std::map<IVertexPtr<TKey, TValue>, size_t>& result) const = 0;
        };

        template <typename TKey, typename TValue>
        using IGraphLogicPtr = std::shared_ptr<IGraphLogic<TKey, TValue>>;

    }
}

#endif // I_GRAPH_LOGIC_H_0f714d5e_2b5f_446c_a128_f7a064131ddd
