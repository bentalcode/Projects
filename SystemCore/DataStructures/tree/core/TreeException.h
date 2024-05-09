#ifndef TREE_EXCEPTION_H_9f0b2e50_7875_4870_b9f7_6c5d64f1daf3
#define TREE_EXCEPTION_H_9f0b2e50_7875_4870_b9f7_6c5d64f1daf3

#include "DataStructureException.h"

namespace datastructures {

    namespace tree {

        /**
         * The TreeException captured errors in tree module.
         */
        class TreeException : public DataStructureException
        {
        public:
            /**
             * The TreeException constructor.
             */
            TreeException(
                long statusCode,
                const std::wstring& errorMessage) :
                DataStructureException(statusCode, errorMessage)
            {
            }
        };

    } // namespace tree

} // namespace datastructures

#endif // TREE_EXCEPTION_H_9f0b2e50_7875_4870_b9f7_6c5d64f1daf3
