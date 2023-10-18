#ifndef I_BINARY_TREE_NODE_ITERATOR_H_cf6609bf_dae0_482a_beca_c05df516d948
#define I_BINARY_TREE_NODE_ITERATOR_H_cf6609bf_dae0_482a_beca_c05df516d948

#include "IIterator.h"
#include "ISkipIterator.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The IBinaryTreeNodeIterator interface defines an iterator of binary tree nodes.
         */
        template <typename T>
        class IBinaryTreeNodeIterator : public base::IIterator<T>
        {
        public:
            /**
             * The IBinaryTreeNodeIterator constructor.
             */
            IBinaryTreeNodeIterator() = default;

            /**
             * The IBinaryStreamNodeIterator destructor.
             */
            virtual ~IBinaryTreeNodeIterator() = default;

            /**
             * The Copy/move constructors.
             */
            IBinaryTreeNodeIterator(const IBinaryTreeNodeIterator&) = delete;
            IBinaryTreeNodeIterator(IBinaryTreeNodeIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IBinaryTreeNodeIterator& operator=(const IBinaryTreeNodeIterator&) = delete;
            IBinaryTreeNodeIterator& operator=(IBinaryTreeNodeIterator&&) = delete;

            /**
             * Gets the skip iterator.
             */
            virtual base::ISkipIteratorSharedPtr GetSkipIterator() const = 0;
        };

        /**
         * Defines SharedPtr of Binary Tree Node Iterator.
         */
        template <typename T>
        using IBinaryTreeNodeIteratorSharedPtr = std::shared_ptr<IBinaryTreeNodeIterator<T>>;
    }
}

#endif // I_BINARY_TREE_NODE_ITERATOR_H_cf6609bf_dae0_482a_beca_c05df516d948
