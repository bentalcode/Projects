#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

#include "PreCompiled.h"
#include <exception>

/**
 * The BaseException captured errors in the base module.
 */
class BaseException : public std::runtime_error
{
public:
    explicit BaseException(const std::string& errorMessage) : std::runtime_error(errorMessage) {}

    /**
     * Gets an error message.
     */
    inline std::string getErrorMessage()
    {
        return this->what();
    }
};

#endif // BASE_EXCEPTION_H
