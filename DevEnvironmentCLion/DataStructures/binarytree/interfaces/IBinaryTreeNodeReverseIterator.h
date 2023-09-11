#ifndef I_BINARY_TREE_NODE_REVERSE_ITERATOR_H_8b0a18de_29db_4442_b351_f2f582642e9f
#define I_BINARY_TREE_NODE_REVERSE_ITERATOR_H_8b0a18de_29db_4442_b351_f2f582642e9f

//#include "IReverseIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTreeNodeReverseIterator interface defines a reverse iterator of binary nodes.
         */
        template <typename T>
        class IBinaryTreeNodeReverseIterator : public base::IReverseIterator<T> {
        public:
            /**
             * The IBinaryTreeNodeReverseIterator constructor.
             */
            IBinaryTreeNodeReverseIterator() = default;

            /**
             * The IBinaryTreeNodeReverseIterator destructor.
             */
            virtual ~IBinaryTreeNodeReverseIterator() = default;

            /**
             * The copy/move constructors.
             */
            IBinaryTreeNodeReverseIterator(const IBinaryTreeNodeReverseIterator&) = delete;
            IBinaryTreeNodeReverseIterator(IBinaryTreeNodeReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IBinaryTreeNodeReverseIterator& operator=(const IBinaryTreeNodeReverseIterator&) = delete;
            IBinaryTreeNodeReverseIterator& operator=(IBinaryTreeNodeReverseIterator&&) = delete;

            /**
             * Gets the skip iterator.
             */
            virtual base::ISkipIteratorPtr getSkipIterator() const = 0;
        };

        template <typename T>
        using IBinaryTreeNodeReverseIteratorPtr = std::shared_ptr<IBinaryTreeNodeReverseIterator<T>>;
    }
}

#endif // I_BINARY_TREE_NODE_REVERSE_ITERATOR_H_8b0a18de_29db_4442_b351_f2f582642e9f
