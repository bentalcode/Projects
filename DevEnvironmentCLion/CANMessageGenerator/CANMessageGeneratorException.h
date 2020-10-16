#ifndef CAN_MESSAGE_GENERATOR_EXCEPTION_H_857ffa77_84e4_42b5_a9ca_ab084024265a
#define CAN_MESSAGE_GENERATOR_EXCEPTION_H_857ffa77_84e4_42b5_a9ca_ab084024265a

#include "BaseException.h"

namespace controllerareanetweok {
    namespace messagegenerator {

        /**
         * The CANMessageGeneratorException class implements an exception for capturing errors
         * in the CAN Message Generator module.
         */
        class CANMessageGeneratorException : public base::BaseException {
        public:
            explicit CANMessageGeneratorException(const std::string &errorMessage) :
                base::BaseException(errorMessage)
            {
            }

            CANMessageGeneratorException(
                const std::string &errorMessage,
                std::exception &innerException) :
                base::BaseException(errorMessage, innerException)
            {
            }
        };

    }
}

#endif // CAN_MESSAGE_GENERATOR_EXCEPTION_H_857ffa77_84e4_42b5_a9ca_ab084024265a
