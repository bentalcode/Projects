#ifndef MEMORY_MANAGEMENT_EXCEPTION_H_e4911ad4_a19f_4da4_83d2_e9dc0120e402
#define MEMORY_MANAGEMENT_EXCEPTION_H_e4911ad4_a19f_4da4_83d2_e9dc0120e402

#include <exception>

/**
 * The MemoryManagementException captured errors in the memory management module.
 */
class MemoryManagementException : public std::runtime_error
{
public:
    explicit MemoryManagementException(const std::string& errorMessage) : std::runtime_error(errorMessage) {}

    /**
     * Gets an error message.
     */
    inline std::string getErrorMessage()
    {
        return this->what();
    }
};

#endif // MEMORY_MANAGEMENT_EXCEPTION_H_e4911ad4_a19f_4da4_83d2_e9dc0120e402
