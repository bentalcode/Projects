#ifndef MEMORY_MANAGEMENT_EXCEPTION_H
#define MEMORY_MANAGEMENT_EXCEPTION_H

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

#endif // MEMORY_MANAGEMENT_EXCEPTION_H
