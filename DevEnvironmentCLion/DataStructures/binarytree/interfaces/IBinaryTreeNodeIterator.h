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
             * The copy/move constructors.
             */
            IBinaryTreeNodeIterator(const IBinaryTreeNodeIterator&) = delete;
            IBinaryTreeNodeIterator(IBinaryTreeNodeIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IBinaryTreeNodeIterator& operator=(const IBinaryTreeNodeIterator&) = delete;
            IBinaryTreeNodeIterator& operator=(IBinaryTreeNodeIterator&&) = delete;

            /**
             * Gets the skip iterator.
             */
            virtual base::ISkipIteratorPtr getSkipIterator() const = 0;
        };

        template <typename T>
        using IBinaryTreeNodeIteratorPtr = std::shared_ptr<IBinaryTreeNodeIterator<T>>;
    }
}

#endif // I_BINARY_TREE_NODE_ITERATOR_H_cf6609bf_dae0_482a_beca_c05df516d948
