#ifndef CAN_MESSAGE_RULE_H_4df98489_7bcb_4739_a058_af2497c46a48
#define CAN_MESSAGE_RULE_H_4df98489_7bcb_4739_a058_af2497c46a48

#include "ICANSignalRule.h"

namespace controllerareanetweok {
    namespace messagegenerator {

        /**
         * The CANSignalRule class implements a rule of signals of a controller area network message.
         */
        class CANSignalRule final : public ICANSignalRule
        {
        public:
            /**
             * Creates a new rule.
             */
            static ICANSignalRulePtr make(
                const std::string& name,
                size_t bitStart,
                size_t bitLength,
                bool byteOrderBigEndian,
                bool valueTypeUnsigned,
                float scale,
                int offset,
                int minimum,
                int maximum,
                const std::string& unit,
                const std::string& transmittingNodeName);

            /**
             * The CANSignal constructor.
             */
            explicit CANSignalRule(
                const std::string& name,
                size_t bitStart,
                size_t bitLength,
                bool byteOrderBigEndian,
                bool valueTypeUnsigned,
                float scale,
                int offset,
                int minimum,
                int maximum,
                const std::string& unit,
                const std::string& transmittingNodeName);

            /**
             * The CANSignalRule destructor.
             */
            virtual ~CANSignalRule();

            /**
             * The copy/move constructors.
             */
            CANSignalRule(const CANSignalRule&) = default;
            CANSignalRule(CANSignalRule&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANSignalRule& operator=(const CANSignalRule&) = default;
            CANSignalRule& operator=(CANSignalRule&&) = delete;

            /**
             * Gets the name of the signal.
             */
            virtual const std::string& getName() const override;

            /**
             * Gets the bit start.
             * The bit start counts from 0 and marks the start of the signal in the data payload.
             */
            virtual size_t getBitStart() const override;

            /**
             * Gets the bit length.
             * The bit length is the signal length.
             */
            virtual size_t getBitLength() const override;

            /**
             * Returns true if the byte order is big endian.
             * Returns false of the byte order is little endian.
             */
            virtual bool byteOrderBigEndian() const override;

            /**
             * Returns if the value type is unsigned.
             */
            virtual bool valueTypeUnsigned() const override;

            /**
             * Gets the scale.
             * physical_value = offset + scale * raw_value_decimal
             */
            virtual float getScale() const override;

            /**
             * Gets the offset.
             * physical_value = offset + scale * raw_value_decimal
             */
            virtual int getOffset() const override;

            /**
             * Gets the minimum.
             */
            virtual int getMinimum() const override;

            /**
             * Gets the maximum.
             */
            virtual int getMaximum() const override;

            /**
             * Gets the unit.
             */
            virtual const std::string& getUnit() const override;

            /**
             * Gets the transmitting node name.
             */
            virtual const std::string& getTransmittingNodeName() const override;

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
            static const std::string byteOrderBigEndianSyntax;
            static const std::string byteOrderLittleEndianSyntax;
            static const std::string valueTypeUnsignedSyntax;
            static const std::string valueTypeSignedSyntax;

            std::string m_name;
            size_t m_bitStart;
            size_t m_bitLength;
            bool m_byteOrderBigEndian;
            bool m_valueTypeUnsigned;
            float m_scale;
            int m_offset;
            int m_minimum;
            int m_maximum;
            std::string m_unit;
            std::string m_transmittingNodeName;
        };

    }
}

#endif // CAN_MESSAGE_RULE_H_4df98489_7bcb_4739_a058_af2497c46a48
