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
        /**
         * The DataStructureException constructor.
         */
        DataStructureException(
            long statusCode,
            const std::wstring& errorMessage) :
            base::BaseException(statusCode, errorMessage)
        {
        }
    };

}

#endif // DATA_STRUCTURE_EXCEPTION_H_022aaf90_2524_48d9_9553_56c90b790cbe
