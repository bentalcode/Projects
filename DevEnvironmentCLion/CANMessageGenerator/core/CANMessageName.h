#ifndef CAN_MESSAGE_NAME_H_805f39c1_b8e0_4232_995c_ad3d43742841
#define CAN_MESSAGE_NAME_H_805f39c1_b8e0_4232_995c_ad3d43742841

#include "ICANMessageName.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The CANMessageName class implements an name of a controller area network message.
         */
        class CANMessageName final : public ICANMessageName
        {
        public:
            /**
             * Creates a new message name.
             */
            static ICANMessageNamePtr make(const std::vector<std::string::value_type>& name);

            /**
             * The CANMessageName Constructor.
             */
            explicit CANMessageName(const std::vector<std::string::value_type>& name);

            /**
             * The CANMessageName destructor.
             */
            virtual ~CANMessageName();

            /**
             * The copy/move constructors.
             */
            CANMessageName(const CANMessageName&) = delete;
            CANMessageName(CANMessageName&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANMessageName& operator=(const CANMessageName&) = delete;
            CANMessageName& operator=(CANMessageName&&) = delete;

            /**
             * Gets the name of a CAN message.
             * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores.
             */
            virtual std::vector<std::string::value_type> getName() const override;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const override;


        private:
            static const size_t minNameLength;
            static const size_t maxNameLength;

            /**
             * Validates the name of the message.
             */
            static void validateName(const std::vector<std::string::value_type>& name);

            /**
             * Validates that the name of the character is valid.
             */
            static bool validNameCharacter(std::string::value_type character);

            std::vector<std::string::value_type> m_name;
        };

    }
}

#endif // CAN_MESSAGE_NAME_H_805f39c1_b8e0_4232_995c_ad3d43742841
