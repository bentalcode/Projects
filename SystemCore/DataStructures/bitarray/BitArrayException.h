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
            /**
             * The BitArrayException constructor.
             */
            BitArrayException(
                long statusCode,
                const std::wstring& errorMessage) :
                    DataStructureException(
                        statusCode,
                        errorMessage)
            {
            }
        };
    }
};


#endif // BIT_ARRAY_EXCEPTION_H_c4f45a2b_bc64_4fc5_b4a4_2e37c4fac88a
