#ifndef I_CAN_RULE_GENERATOR_ID_H_4e7c309f_272c_4b37_bea2_49414f3a3135
#define I_CAN_RULE_GENERATOR_ID_H_4e7c309f_272c_4b37_bea2_49414f3a3135

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The ICANRuleGenerator interface defines a generator of a CAN rule.
         */
        template <typename T>
        class ICANRuleGenerator
        {
        public:
            /**
             * The constructor.
             */
            ICANRuleGenerator() = default;

            /**
             * The destructor.
             */
            virtual ~ICANRuleGenerator() = default;

            /**
             * The copy/move constructors.
             */
            ICANRuleGenerator(const ICANRuleGenerator&) = delete;
            ICANRuleGenerator(ICANRuleGenerator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICANRuleGenerator &operator=(const ICANRuleGenerator&) = delete;
            ICANRuleGenerator &operator=(ICANRuleGenerator&&) = delete;

            /**
             * Generates a new rule.
             */
            virtual T generate(const std::string& name) = 0;
        };

        template <typename T>
        using ICANRuleGeneratorPtr = std::shared_ptr<ICANRuleGenerator<T>>;
    }
}

#endif // I_CAN_RULE_GENERATOR_ID_H_4e7c309f_272c_4b37_bea2_49414f3a3135
