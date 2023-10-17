#ifndef LINKED_LIST_EXCEPTION_H_5de4cbd0_7d30_43fe_af08_46d84f594876
#define LINKED_LIST_EXCEPTION_H_5de4cbd0_7d30_43fe_af08_46d84f594876

#include "DataStructureException.h"

namespace datastructures {
    namespace linkedlist {

        /**
         * The LinkedListException captured errors in the linked list module.
         */
        class LinkedListException : public DataStructureException
        {
        public:
            /**
             * The LinkedListException constructor.
             */
            LinkedListException(
                long statusCode,
                const std::string& errorMessage,
                std::exception& innerException) :
                DataStructureException(statusCode, innerException)
            {
            }
        };
    }
};


#endif // LINKED_LIST_EXCEPTION_H_5de4cbd0_7d30_43fe_af08_46d84f594876
