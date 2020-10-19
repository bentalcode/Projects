#ifndef CAN_RULE_GENERATOR_H_026c25f3_2777_4ec6_8ea7_90730f5f84ab
#define CAN_RULE_GENERATOR_H_026c25f3_2777_4ec6_8ea7_90730f5f84ab

#include "RandomGenerator.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        class CANRuleGenerator
        {
        protected:
            /**
             * The CANSignal constructor.
             */
            CANRuleGenerator();

        public:
            /**
             * The CANRuleGenerator destructor.
             */
            virtual ~CANRuleGenerator() = 0;

            /**
             * The copy/move constructors.
             */
            CANRuleGenerator(const CANRuleGenerator&) = delete;
            CANRuleGenerator(CANRuleGenerator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANRuleGenerator& operator=(const CANRuleGenerator&) = delete;
            CANRuleGenerator& operator=(CANRuleGenerator&&) = delete;

        protected:
            /**
             * Generates a random generator.
             */
            inline base::IRandomGenerator& randomGenerator();

            /**
             * Generates a new transmitting node name.
             */
            const std::string& generateTransmittingNodeName();

        private:
            static const std::string defaultNodeName;
            static const std::string nodeNamePrefix;
            static unsigned int numberOfNodes;

            /**
             * Generates a new transmitting node name.
             */
            const std::string& generateTransmittingNodeName(const std::vector<std::string>& transmittingNodeNames);

            /**
             * Gets the transmitting node names.
             */
            static std::vector<std::string>* getTransmittingNodeNames();

            base::RandomGenerator m_randomGenerator;
        };

        base::IRandomGenerator& CANRuleGenerator::randomGenerator()
        {
            return m_randomGenerator;
        }
    }
}

#endif // CAN_RULE_GENERATOR_H_026c25f3_2777_4ec6_8ea7_90730f5f84ab
