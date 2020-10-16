#ifndef I_CAN_MESSAGE_RULE_H_667825c6_2579_4ff3_b821_3a66b588365b
#define I_CAN_MESSAGE_RULE_H_667825c6_2579_4ff3_b821_3a66b588365b

#include "ICANRule.h"
#include "CANMessageId.h"
#include "CANMessageName.h"
#include "ICANSignalRule.h"

namespace controllerareanetweok {
    namespace messagegenerator {

        /**
         * The ICANMessageRule interface defines a rule of a controller area network messages.
         *
         * BO_ 2364540158 EEC1: 8 Vector_XXX
         *
         * A message starts with BO_ and the ID must be unique and in decimal (not hexadecimal)
         * The DBC ID adds adds 3 extra bits for 29 bit CAN IDs to serve as an ‘extended ID’ flag
         * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores
         * The length (DLC) must be an integer between 0 and 1785
         * The sender is the name of the transmitting node, or Vector__XXX if no name is available
         */
        class ICANMessageRule : public ICANRule
        {
        public:
            /**
             * The constructor.
             */
            ICANMessageRule() = default;

            /**
             * The destructor.
             */
            virtual ~ICANMessageRule() = default;

            /**
             * The copy/move constructors.
             */
            ICANMessageRule(const ICANMessageRule&) = delete;
            ICANMessageRule(ICANMessageRule&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICANMessageRule &operator=(const ICANMessageRule&) = delete;
            ICANMessageRule &operator=(ICANMessageRule&&) = delete;

            /**
             * Gets the identifier of the message.
             */
            virtual const ICANMessageId& getId() const = 0;

            /**
             * Gets the name of the message.
             */
            virtual const ICANMessageName& getName() const = 0;

            /**
             * The length (DLC) must be an integer between 0 and 1785.
             */
            virtual unsigned short getLength() const = 0;

            /**
             * Gets the name of the transmitting node.
             */
            virtual const std::string& getTransmittingNodeName() const = 0;

            /**
             * Gets the signal rules.
             */
            virtual const std::vector<ICANSignalRulePtr>& getSignalRules() const = 0;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const = 0;

            /**
             * Writers the content of the rule.
             */
            virtual void writeRule(std::ostream& output) const = 0;
        };

        using ICANMessageRulePtr = std::shared_ptr<ICANMessageRule>;
    }
}

#endif // I_CAN_MESSAGE_RULE_H_667825c6_2579_4ff3_b821_3a66b588365b
