#ifndef PRIORITY_QUEUE_H_cb2d4fd5_4eca_44fa_87c0_b5621e88c392
#define PRIORITY_QUEUE_H_cb2d4fd5_4eca_44fa_87c0_b5621e88c392

#include "DataStructureException.h"

namespace datastructures {
    namespace priority_queue {

        /**
         * The PriorityQueueException captured errors in the priority queue module.
         */
        class PriorityQueueException : public DataStructureException
        {
        public:
            /**
             * The PriorityQueueException constructor.
             */
            PriorityQueueException(
                long statusCode,
                const std::wstring& errorMessage) :
                DataStructureException(statusCode, errorMessage)
            {
            }
        };
    }
};


#endif // PRIORITY_QUEUE_H_cb2d4fd5_4eca_44fa_87c0_b5621e88c392
