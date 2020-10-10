#ifndef NODE_EXCEPTION_H_73f8ea0b_4f06_4ba3_99b4_a72327204a7c
#define NODE_EXCEPTION_H_73f8ea0b_4f06_4ba3_99b4_a72327204a7c

#include "DataStructureException.h"

namespace datastructures {
    namespace node {

        /**
        * The NodeException captured errors in the node module.
        */
        class NodeException : public DataStructureException
        {
        public:
            explicit NodeException(const std::string& errorMessage) :
                DataStructureException(errorMessage)
            {
            }

            NodeException(
                const std::string& errorMessage,
                std::exception& innerException) :
                DataStructureException(errorMessage, innerException)
            {
            }
        };
    }
};


#endif // NODE_EXCEPTION_H_73f8ea0b_4f06_4ba3_99b4_a72327204a7c
