#ifndef DATA_STRUCTURE_EXCEPTION_H_022aaf90_2524_48d9_9553_56c90b790cbe
#define DATA_STRUCTURE_EXCEPTION_H_022aaf90_2524_48d9_9553_56c90b790cbe

#include "BaseException.h"

namespace datastructures {

    /**
     * The DataStructureException captured errors in the data structure module.
     */
    class DataStructureException : public BaseException
    {
    public:
        explicit DataStructureException(const std::string& errorMessage) :
            BaseException(errorMessage)
        {
        }

        DataStructureException(
            const std::string& errorMessage,
            std::exception& innerException) :
            BaseException(errorMessage, innerException)
        {
        }
    };
}

#endif // DATA_STRUCTURE_EXCEPTION_H_022aaf90_2524_48d9_9553_56c90b790cbe
