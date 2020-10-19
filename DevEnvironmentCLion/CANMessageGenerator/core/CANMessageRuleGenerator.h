#ifndef CAN_MESSAGE_RULE_GENERATOR_H_fdd2274a_7ee2_45c2_821a_00ccb5c3f025
#define CAN_MESSAGE_RULE_GENERATOR_H_fdd2274a_7ee2_45c2_821a_00ccb5c3f025

#include "ICANRuleGenerator.h"
#include "CANRuleGenerator.h"
#include "ICANMessageRule.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The ICANMessageRuleGenerator class implements a generator of CAN message rules.
         */
        class CANMessageRuleGenerator final : public CANRuleGenerator, public ICANRuleGenerator<ICANMessageRulePtr>
        {
        public:
            /**
             * The CANMessageRuleGenerator constructor.
             */
            CANMessageRuleGenerator();

            /**
             * The CANMessageRuleGenerator destructor.
             */
            virtual ~CANMessageRuleGenerator();

            /**
             * The copy/move constructors.
             */
            CANMessageRuleGenerator(const CANMessageRuleGenerator&) = delete;
            CANMessageRuleGenerator(CANMessageRuleGenerator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANMessageRuleGenerator& operator=(const CANMessageRuleGenerator&) = delete;
            CANMessageRuleGenerator& operator=(CANMessageRuleGenerator&&) = delete;

            /**
             * Generates a new CAN signal rule.
             */
            virtual ICANMessageRulePtr generate(const std::string& name) override;

        private:
            static const short minLength;
            static const short int maxLength;

            static const size_t minNumberOfSignalRules;
            static const size_t maxNumberOfSignalRules;

            /**
             * Generates a message id.
             */
            ICANMessageIdPtr generateMessageId();

            /**
             * Generates a new length.
             */
            short generateLength();

            /**
             * Generates new signal rules.
             */
            void generateSignalRules(const std::string& name, std::vector<ICANSignalRulePtr>& rules);

            /**
             * Generates a new id.
             */
            unsigned int generateId(size_t startBitIndex, size_t endBitEndIndex);

            ICANRuleGeneratorPtr<ICANSignalRulePtr> m_signalRuleGenerator;
        };

    }
}

#endif // CAN_MESSAGE_RULE_GENERATOR_H_fdd2274a_7ee2_45c2_821a_00ccb5c3f025
