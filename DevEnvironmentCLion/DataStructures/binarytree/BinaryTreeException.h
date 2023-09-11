#ifndef BINARY_TREE_EXCEPTION_H_ba525542_0ded_4f84_b5fb_0226534e09e2
#define BINARY_TREE_EXCEPTION_H_ba525542_0ded_4f84_b5fb_0226534e09e2

#include "BaseException.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeException captured errors in the binary tree module.
         */
        class BinaryTreeException : public base::BaseException
        {
        public:
            explicit BinaryTreeException(const std::string& errorMessage) :
                base::BaseException(errorMessage)
            {
            }

            BinaryTreeException(
                const std::string& errorMessage,
                std::exception& innerException) :
                base::BaseException(errorMessage, innerException)
            {
            }
        };
    }
}

#endif // BINARY_TREE_EXCEPTION_H_ba525542_0ded_4f84_b5fb_0226534e09e2
