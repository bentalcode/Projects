#ifndef CAN_SIGNAL_RULE_GENERATOR_H_f9d4baed_429a_4ced_b37f_538b5d6c0599
#define CAN_SIGNAL_RULE_GENERATOR_H_f9d4baed_429a_4ced_b37f_538b5d6c0599

#include "ICANRuleGenerator.h"
#include "CANRuleGenerator.h"
#include "ICANSignalRule.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The CANSignalRuleGenerator class implements a generator of CAN signal rules.
         */
        class CANSignalRuleGenerator final : public CANRuleGenerator, public ICANRuleGenerator<ICANSignalRulePtr>
        {
        public:
            /**
             * The CANSignalRuleGenerator constructor.
             */
            CANSignalRuleGenerator();

            /**
             * The CANSignalRuleGenerator destructor.
             */
            virtual ~CANSignalRuleGenerator();

            /**
             * The copy/move constructors.
             */
            CANSignalRuleGenerator(const CANSignalRuleGenerator&) = delete;
            CANSignalRuleGenerator(CANSignalRuleGenerator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANSignalRuleGenerator& operator=(const CANSignalRuleGenerator&) = delete;
            CANSignalRuleGenerator& operator=(CANSignalRuleGenerator&&) = delete;

            /**
             * Generates a new CAN signal rule.
             */
            virtual ICANSignalRulePtr generate(const std::string& name) override;

        private:
            static const short dataMinSizeInBits;
            static const short dataMaxSizeInBits;

            static const float minPhysicalValue;
            static const float maxPhysicalValue;

            static const size_t maxRawValueSizeInBits;

            static const int minValue;
            static const int maxValue;

            using NameUnitMap = std::map<std::string, std::vector<std::string>>;

            /**
             * Generates the size of the data.
             */
            size_t generateDataSize(
                size_t dataMinSizeInBits,
                size_t dataMaxSizeInBits);

            /**
             * Generates a bit start and bit length for the relevant data.
             */
            std::pair<size_t, size_t> generateBitStartAndBitLength(
                size_t dataBitLength,
                size_t maxRawValueBitLength);

            /**
             * Generates whether the byte order is big endian.
             */
            bool generateByteOrderBigEndian();

            /**
             * Generates whether the value type is unsigned.
             */
            bool generateValueTypeUnsigned();

            /**
             * Generates an offset and a scale for calculating the physical data.
             * physical_value = offset + scale * raw_value_decimal.
             */
            std::pair<float, int> generateScaleAndOffset(
                float physicalValue,
                bool valueTypeUnsigned,
                size_t bitLength);

            /**
             * Generates minimum maximum values.
             */
            std::pair<int, int> generateMinimumMaximumValues(int from, int to);

            /**
             * Generates a unit.
             */
            std::string generateUnit(const std::string& name);

            /**
             * Generates a unit.
             */
            std::string generateUnit(
                const std::string& name,
                const NameUnitMap& nameToUnitsMap);

            /**
             * Creates a name-units map.
             */
            static NameUnitMap* createNameUnitsMap();
        };

    }
}

#endif // CAN_SIGNAL_RULE_GENERATOR_H_f9d4baed_429a_4ced_b37f_538b5d6c0599
