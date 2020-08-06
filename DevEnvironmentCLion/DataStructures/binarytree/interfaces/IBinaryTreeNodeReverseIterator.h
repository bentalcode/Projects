#ifndef I_BINARY_TREE_NODE_REVERSE_ITERATOR_H_8b0a18de_29db_4442_b351_f2f582642e9f
#define I_BINARY_TREE_NODE_REVERSE_ITERATOR_H_8b0a18de_29db_4442_b351_f2f582642e9f

#include "IReverseIterator.h"
#include "ISkipIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTreeBodeReverseIterator interface defines a reverse iterator of binary nodes.
         */
        template<typename T>
        class IBinaryTreeBodeReverseIterator : public base::IReverseIterator<T> {
        public:
            /**
             * The IBinaryTreeBodeReverseIterator constructor.
             */
            IBinaryTreeBodeReverseIterator() = default;

            /**
             * The IBinaryTreeBodeReverseIterator destructor.
             */
            virtual ~IBinaryTreeBodeReverseIterator() = default;

            /**
             * The copy/move constructors.
             */
            IBinaryTreeBodeReverseIterator(const IBinaryTreeBodeReverseIterator&) = delete;
            IBinaryTreeBodeReverseIterator(IBinaryTreeBodeReverseIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IBinaryTreeBodeReverseIterator& operator=(const IBinaryTreeBodeReverseIterator&) = delete;
            IBinaryTreeBodeReverseIterator& operator=(IBinaryTreeBodeReverseIterator&&) = delete;

            /**
             * Gets the skip iterator.
             */
            virtual base::ISkipIteratorPtr getSkipIterator() const = 0;
        };
    }
}

#endif // I_BINARY_TREE_NODE_REVERSE_ITERATOR_H_8b0a18de_29db_4442_b351_f2f582642e9f
