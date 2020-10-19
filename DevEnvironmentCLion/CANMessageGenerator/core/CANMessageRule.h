#ifndef CAN_MESSAGE_RULE_H_4df98489_7bcb_4739_a058_af2497c46a48
#define CAN_MESSAGE_RULE_H_4df98489_7bcb_4739_a058_af2497c46a48

#include "ICANMessageRule.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The CANMessageRule class implements a rule of a controller area network messages.
         *
         * BO_ 2364540158 EEC1: 8 Vector_XXX
         *
         * A message starts with BO_ and the ID must be unique and in decimal (not hexadecimal)
         * The DBC ID adds adds 3 extra bits for 29 bit CAN IDs to serve as an ‘extended ID’ flag
         * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores
         * The length (DLC) must be an integer between 0 and 1785
         * The sender is the name of the transmitting node, or Vector__XXX if no name is available
         */
        class CANMessageRule final : public ICANMessageRule
        {
        public:
            /**
             * Creates a new rule.
             */
            static ICANMessageRulePtr make(
                ICANMessageIdPtr id,
                ICANMessageNamePtr name,
                short length,
                const std::string& transmittingNodeName,
                const std::vector<ICANSignalRulePtr>& signalRules);

            /**
             * The CANMessageRule constructor.
             */
            CANMessageRule(
                ICANMessageIdPtr id,
                ICANMessageNamePtr name,
                short length,
                const std::string& transmittingNodeName,
                const std::vector<ICANSignalRulePtr>& signalRules);

            /**
             * The CANMessageRule destructor.
             */
            virtual ~CANMessageRule();

            /**
             * The copy/move constructors.
             */
            CANMessageRule(const CANMessageRule&) = delete;
            CANMessageRule(CANMessageRule&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANMessageRule& operator=(const CANMessageRule&) = delete;
            CANMessageRule& operator=(CANMessageRule&&) = delete;

            /**
             * Gets the identifier of the message.
             */
            virtual const ICANMessageId& getId() const override;

            /**
             * Gets the name of the message.
             */
            virtual const ICANMessageName& getName() const override;

            /**
             * The length (DLC) must be an integer between 0 and 1785.
             */
            virtual unsigned short getLength() const override;

            /**
             * Gets the name of the transmitting node.
             */
            virtual const std::string& getTransmittingNodeName() const override;

            /**
             * Gets the signal rules.
             */
            virtual const std::vector<ICANSignalRulePtr>& getSignalRules() const override;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const override;

            /**
             * Writers the content of the rule.
             */
            virtual void writeRule(std::ostream& output) const override;

        private:
            static const std::string messageSyntax;
            static int minimumDataLength;
            static int maximumDataLength;

            ICANMessageIdPtr m_id;
            ICANMessageNamePtr m_name;
            short m_length;
            std::string m_transmittingNodeName;
            std::vector<ICANSignalRulePtr> m_signalRules;
        };

    }
}

#endif // CAN_MESSAGE_RULE_H_4df98489_7bcb_4739_a058_af2497c46a48
