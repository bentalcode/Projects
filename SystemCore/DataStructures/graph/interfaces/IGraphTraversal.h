#ifndef I_GRAPH_TRAVERSAL_H_ec66b507_75ca_44aa_85ed_a74bf7070ada
#define I_GRAPH_TRAVERSAL_H_ec66b507_75ca_44aa_85ed_a74bf7070ada

#include "IVertex.h"
#include "IVisitor.h"

namespace datastructures {
    namespace graph {

        /**
         * The IGraphTraversal interface defines various traversals of a graph.
         */
        template <typename TKey, typename TValue>
        class IGraphTraversal
        {
        public:
            /**
             * The constructor.
             */
            IGraphTraversal() = default;

            /**
             * The destructor.
             */
            virtual ~IGraphTraversal() = default;

            /**
             * The Copy/move constructors.
             */
            IGraphTraversal(const IGraphTraversal&) = delete;
            IGraphTraversal(IGraphTraversal&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IGraphTraversal& operator=(const IGraphTraversal&) = delete;
            IGraphTraversal& operator=(IGraphTraversal&&) = delete;

            /**
             * Performs a Breadth-First search.
             */
            virtual void BreadthFirstSearch(
                const IVertex<TKey, TValue>& vertex,
                base::IVisitorPtr<IVertexPtr<TKey, TValue>>& visitor) const = 0;

            /**
             * Performs a Depth-First search.
             */
            virtual void DepthFirstSearch(
                const IVertex<TKey, TValue>& vertex,
                base::IVisitorPtr<IVertexPtr<TKey, TValue>> visitor) const = 0;
        };

        /**
         * Defines the SharedPtr Of Graph Traversal.
         */
        template <typename TKey, typename TValue>
        using IGraphTraversalSharedPtr = std::shared_ptr<IGraphTraversal<TKey, TValue>>;

    }
}

#endif // I_GRAPH_TRAVERSAL_H_ec66b507_75ca_44aa_85ed_a74bf7070ada
