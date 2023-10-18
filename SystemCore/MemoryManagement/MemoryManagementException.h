#ifndef MEMORY_MANAGEMENT_EXCEPTION_H_e4911ad4_a19f_4da4_83d2_e9dc0120e402
#define MEMORY_MANAGEMENT_EXCEPTION_H_e4911ad4_a19f_4da4_83d2_e9dc0120e402

#include "BaseException.h"

namespace memory_management {

    /**
     * The MemoryManagementException captured errors in the memory management module.
     */
    class MemoryManagementException : public base::BaseException {
    public:
        /**
         * The MemoryManagementException constructor.
         */
        MemoryManagementException(
            long statusCode,
            const std::wstring& errorMessage) :
            BaseException(statusCode, errorMessage)
        {
        }
    };

}

#endif // MEMORY_MANAGEMENT_EXCEPTION_H_e4911ad4_a19f_4da4_83d2_e9dc0120e402
