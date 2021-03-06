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
             * The copy/move constructors.
             */
            IGraphTraversal(const IGraphTraversal&) = delete;
            IGraphTraversal(IGraphTraversal&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IGraphTraversal& operator=(const IGraphTraversal&) = delete;
            IGraphTraversal& operator=(IGraphTraversal&&) = delete;

            /**
             * Performs a Breadth-First search.
             */
            virtual void breadthFirstSearch(
                const IVertex<TKey, TValue>& vertex,
                base::IVisitorPtr<IVertexPtr<TKey, TValue>>& visitor) const = 0;

            /**
             * Performs a Depth-First search.
             */
            virtual void depthFirstSearch(
                const IVertex<TKey, TValue>& vertex,
                base::IVisitorPtr<IVertexPtr<TKey, TValue>> visitor) const = 0;
        };

        template <typename TKey, typename TValue>
        using IGraphTraversalPtr = std::shared_ptr<IGraphTraversal<TKey, TValue>>;

    }
}

#endif // I_GRAPH_TRAVERSAL_H_ec66b507_75ca_44aa_85ed_a74bf7070ada
