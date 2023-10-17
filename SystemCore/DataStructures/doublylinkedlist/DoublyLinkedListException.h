#ifndef DOUBLY_LINKED_LIST_EXCEPTION_H_2d9d6842_465c_415d_b87c_7516363a1b47
#define DOUBLY_LINKED_LIST_EXCEPTION_H_2d9d6842_465c_415d_b87c_7516363a1b47

#include "DataStructureException.h"

namespace datastructures {
    namespace doublylinkedlist {

        /**
         * The DoublyLinkedListException captured errors in the doubly linked list module.
         */
        class DoublyLinkedListException : public DataStructureException
        {
        public:
            /**
             * The DoublyLinkedListException constructor.
             */
            DoublyLinkedListException(
                long statusCode,
                const std::string& errorMessage) :
                DataStructureException(statusCode, errorMessage)
            {
            }
        };
    }
};


#endif // DOUBLY_LINKED_LIST_EXCEPTION_H_2d9d6842_465c_415d_b87c_7516363a1b47
