#ifndef MEMORY_MANAGEMENT_EXCEPTION_H
#define MEMORY_MANAGEMENT_EXCEPTION_H

#include <exception>

class MemoryManagementException : public std::runtime_error
{
public:
    explicit MemoryManagementException(const std::string& errorMessage) : std::runtime_error(errorMessage) {}

    inline std::string getErrorMessage()
    {
        return this->what();
    }
};

#endif // MEMORY_MANAGEMENT_EXCEPTION_H
