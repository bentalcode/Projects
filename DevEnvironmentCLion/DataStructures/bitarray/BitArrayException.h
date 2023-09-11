#ifndef BIT_ARRAY_EXCEPTION_H_c4f45a2b_bc64_4fc5_b4a4_2e37c4fac88a
#define BIT_ARRAY_EXCEPTION_H_c4f45a2b_bc64_4fc5_b4a4_2e37c4fac88a

#include "DataStructureException.h"

namespace datastructures {
    namespace bitarray {

        /**
        * The BitArrayException captured errors in the bit array module.
        */
        class BitArrayException : public DataStructureException
        {
        public:
            explicit BitArrayException(const std::string& errorMessage) :
                DataStructureException(errorMessage)
            {
            }

            BitArrayException(
                const std::string& errorMessage,
                std::exception& innerException) :
                DataStructureException(errorMessage, innerException)
            {
            }
        };
    }
};


#endif // BIT_ARRAY_EXCEPTION_H_c4f45a2b_bc64_4fc5_b4a4_2e37c4fac88a
