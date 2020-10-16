#ifndef CAN_MESSAGE_ID_H_b8bbd0d8_2ad9_42fc_88e8_e99750de9e26
#define CAN_MESSAGE_ID_H_b8bbd0d8_2ad9_42fc_88e8_e99750de9e26

#include "ICANMessageId.h"

namespace controllerareanetweok {
    namespace messagegenerator {

        /**
         * The CANMessageId class implements an id of a controller area network message.
         */
        class CANMessageId final : public ICANMessageId
        {
        public:
            /**
             * Creates a new messages id.
             */
            static ICANMessageIdPtr make(unsigned int mainId, unsigned int extendedId);

            /**
             * The CANMessageId Constructor.
             */
            CANMessageId(unsigned int mainId, unsigned int extendedId);

            /**
             * The CANMessageId destructor.
             */
            virtual ~CANMessageId();

            /**
             * The copy/move constructors.
             */
            CANMessageId(const CANMessageId&) = default;
            CANMessageId(CANMessageId&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANMessageId& operator=(const CANMessageId&) = default;
            CANMessageId& operator=(CANMessageId&&) = delete;

            /**
             * Gets the main id. Bits: {28, 27, 26, ... 0}.
             */
            virtual unsigned int getMainId() const override;

            /**
             * Gets the extended id. Bits: {31, 30, 29}.
             */
            virtual unsigned int getExtendedId() const override;

            /**
             * Gets the id.
             */
            virtual unsigned int getId() const override;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            unsigned int m_mainId;
            unsigned int m_extendedId;
        };

    }
}

#endif // CAN_MESSAGE_ID_H_b8bbd0d8_2ad9_42fc_88e8_e99750de9e26
