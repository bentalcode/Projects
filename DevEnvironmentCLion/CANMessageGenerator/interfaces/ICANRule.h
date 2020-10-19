#ifndef I_CAN_RULE_H_96fe6fd1_99c3_4b70_bb92_b2a453c85554
#define I_CAN_RULE_H_96fe6fd1_99c3_4b70_bb92_b2a453c85554

#include <memory>

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The ICANRule interface defines a rule of a controller area network.
         */
        class ICANRule
        {
        public:
            /**
             * The constructor.
             */
            ICANRule() = default;

            /**
             * The destructor.
             */
            virtual ~ICANRule() = default;

            /**
             * The copy/move constructors.
             */
            ICANRule(const ICANRule&) = delete;
            ICANRule(ICANRule&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICANRule &operator=(const ICANRule&) = delete;
            ICANRule &operator=(ICANRule&&) = delete;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const = 0;

            /**
             * Writers the content of the rule.
             */
            virtual void writeRule(std::ostream& putput) const = 0;
        };

        using ICANRulePtr = std::shared_ptr<ICANRule>;
    }
}

#endif // I_CAN_RULE_H_96fe6fd1_99c3_4b70_bb92_b2a453c85554
