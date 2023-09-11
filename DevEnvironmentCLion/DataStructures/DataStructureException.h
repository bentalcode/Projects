#ifndef DATA_STRUCTURE_EXCEPTION_H_022aaf90_2524_48d9_9553_56c90b790cbe
#define DATA_STRUCTURE_EXCEPTION_H_022aaf90_2524_48d9_9553_56c90b790cbe

#include "BaseException.h"

namespace datastructures {

    /**
     * The DataStructureException captured errors in the data structure module.
     */
    class DataStructureException : public base::BaseException
    {
    public:
        explicit DataStructureException(const std::string& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        DataStructureException(
            const std::string& errorMessage,
            std::exception& innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };

}

#endif // DATA_STRUCTURE_EXCEPTION_H_022aaf90_2524_48d9_9553_56c90b790cbe
