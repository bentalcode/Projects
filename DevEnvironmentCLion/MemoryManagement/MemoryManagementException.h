#ifndef MEMORY_MANAGEMENT_EXCEPTION_H_b39389da_ca78_495e_b11a_e0ce6b593682
#define MEMORY_MANAGEMENT_EXCEPTION_H_b39389da_ca78_495e_b11a_e0ce6b593682

#include "PreCompiled.h"
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

#endif // MEMORY_MANAGEMENT_EXCEPTION_H_b39389da_ca78_495e_b11a_e0ce6b593682
