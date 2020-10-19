#ifndef JITTER_MESSAGE_HANDLER_EXCEPTION_H_ebca9ab7_b8e5_40fd_af25_dbc2488d18f9
#define JITTER_MESSAGE_HANDLER_EXCEPTION_H_ebca9ab7_b8e5_40fd_af25_dbc2488d18f9

#include "BaseException.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The JitterMessageHandlerException class implements an exception for capturing errors
         * in the CAN Message Generator module.
         */
        class JitterMessageHandlerException : public base::BaseException {
        public:
            explicit JitterMessageHandlerException(const std::string &errorMessage) :
                base::BaseException(errorMessage)
            {
            }

            JitterMessageHandlerException(
                const std::string &errorMessage,
                std::exception &innerException) :
                base::BaseException(errorMessage, innerException)
            {
            }
        };

    }
}

#endif // JITTER_MESSAGE_HANDLER_EXCEPTION_H_ebca9ab7_b8e5_40fd_af25_dbc2488d18f9
