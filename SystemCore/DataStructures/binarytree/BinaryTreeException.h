#ifndef BINARY_TREE_EXCEPTION_H_ba525542_0ded_4f84_b5fb_0226534e09e2
#define BINARY_TREE_EXCEPTION_H_ba525542_0ded_4f84_b5fb_0226534e09e2

#include "DataStructureException.h"

namespace datastructures {
    namespace binarytree {

        /**
         * The BinaryTreeException captured errors in the binary tree module.
         */
        class BinaryTreeException : public DataStructureException
        {
        public:
            /**
             * The BinaryTreeException constructor.
             */
            BinaryTreeException(
                long statusCode,
                const std::string& errorMessage) :
                DataStructureException(statusCode, errorMessage)
            {
            }
        };
    }
}

#endif // BINARY_TREE_EXCEPTION_H_ba525542_0ded_4f84_b5fb_0226534e09e2
