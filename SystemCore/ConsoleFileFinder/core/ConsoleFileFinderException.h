#ifndef CONSOLE_FILE_FINDER_EXCEPTION_H_d57de0f4_e6a5_4675_aa50_9ce84121077b
#define CONSOLE_FILE_FINDER_EXCEPTION_H_d57de0f4_e6a5_4675_aa50_9ce84121077b

#include "BaseException.h"

namespace consolefilefinder {

    /**
     * The ConsoleFileFinderException captured errors in the Console File Finder module.
     */
    class ConsoleFileFinderException : public base::BaseException
    {
    public:
        /**
         * The ConsoleFileFinderException constructor.
         */
        ConsoleFileFinderException(
            long statusCode,
            const std::wstring& errorMessage) :
            base::BaseException(statusCode, errorMessage)
        {
        }
    };

}

#endif // CONSOLE_FILE_FINDER_EXCEPTION_H_d57de0f4_e6a5_4675_aa50_9ce84121077b
