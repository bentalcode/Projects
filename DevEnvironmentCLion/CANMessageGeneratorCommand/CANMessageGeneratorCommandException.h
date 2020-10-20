#ifndef CAN_MESSAGE_GENERATOR_COMMAND_EXCEPTION_H_f5d491e1_8993_4676_b1f5_316350a077a1
#define CAN_MESSAGE_GENERATOR_COMMAND_EXCEPTION_H_f5d491e1_8993_4676_b1f5_316350a077a1

#include "BaseException.h"

namespace controllerareanetwork {
    namespace messagegeneratorcommand {

        /**
         * The CANMessageGeneratorCommandException class implements an exception for capturing errors
         * in the CAN Message Generator Command module.
         */
        class CANMessageGeneratorCommandException : public base::BaseException {
        public:
            explicit CANMessageGeneratorCommandException(const std::string &errorMessage) :
                base::BaseException(errorMessage)
            {
            }

            CANMessageGeneratorCommandException(
                const std::string &errorMessage,
                std::exception &innerException) :
                base::BaseException(errorMessage, innerException)
            {
            }
        };

    }
}

#endif // CAN_MESSAGE_GENERATOR_COMMAND_EXCEPTION_H_f5d491e1_8993_4676_b1f5_316350a077a1
