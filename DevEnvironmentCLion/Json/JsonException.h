#ifndef JSON_EXCEPTION_H_6e9f066c_d5d8_49c6_8f9d_3c10fab28234
#define JSON_EXCEPTION_H_6e9f066c_d5d8_49c6_8f9d_3c10fab28234

#include "BaseException.h"

namespace json {

    /**
     * The JsonException captured errors in the json module.
     */
    class JsonException : public base::BaseException
    {
    public:
        explicit JsonException(const std::string& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        explicit JsonException(
            const std::string& errorMessage,
            std::exception& innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };

}

#endif // JSON_EXCEPTION_H_6e9f066c_d5d8_49c6_8f9d_3c10fab28234
