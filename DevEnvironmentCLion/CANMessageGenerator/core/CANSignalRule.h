#ifndef CAN_SIGNAL_RULE_H_a0e156fd_5a57_4b5d_a6d2_fc279ffb773b
#define CAN_SIGNAL_RULE_H_a0e156fd_5a57_4b5d_a6d2_fc279ffb773b

#include "ICANSignalRule.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The CANSignalRule class implements a rule of signals of a controller area network messages.
         *
         * SG_ EngineSpeed : 24|16@1+ (0.125,0) [0|8031.875] "rpm" Vector_XXX
         *
         * Each message contains 1+ signals that start with SG_
         * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores
         * The bit start counts from 0 and marks the start of the signal in the data payload
         * The bit length is the signal length
         * The @1 specifies that the byte order is little-endian/Intel (vs @0 for big-endian/Motorola)
         * The + informs that the value type is unsigned (vs - for signed signals)
         * The (scale,offset) values are used in the physical value linear equation (more below)
         * The [min|max and unit are optional meta information (they can be set to [0|0| or "")
         * The receiver is the name of the receiving node (again, Vector__XXX is used as default)
         */
        class CANSignalRule final : public ICANSignalRule
        {
        public:
            /**
             * Creates a new rule.
             */
            static ICANSignalRulePtr make(
                ICANMessageNamePtr name,
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
            CANSignalRule(
                ICANMessageNamePtr name,
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
            CANSignalRule(const CANSignalRule&) = delete;
            CANSignalRule(CANSignalRule&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANSignalRule& operator=(const CANSignalRule&) = delete;
            CANSignalRule& operator=(CANSignalRule&&) = delete;

            /**
             * Gets the name of the message.
             */
            virtual const ICANMessageName& getName() const override;

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

            ICANMessageNamePtr m_name;
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

#endif // CAN_SIGNAL_RULE_H_a0e156fd_5a57_4b5d_a6d2_fc279ffb773b
