#ifndef MEMORY_MANAGEMENT_EXCEPTION_H_88690fcf_1e63_4a80_871b_b294928ee1f0
#define MEMORY_MANAGEMENT_EXCEPTION_H_88690fcf_1e63_4a80_871b_b294928ee1f0

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

#endif // MEMORY_MANAGEMENT_EXCEPTION_H_88690fcf_1e63_4a80_871b_b294928ee1f0
