#ifndef I_CAN_SIGNAL_RULE_H_61b97c69_8d48_42ff_bd0d_0d9b16e45ebc
#define I_CAN_SIGNAL_RULE_H_61b97c69_8d48_42ff_bd0d_0d9b16e45ebc

#include "ICANRule.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The ICANSignalRule interface defines a rule of signals of a controller area network messages.
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
        class ICANSignalRule : public ICANRule
        {
        public:
            /**
             * The constructor.
             */
            ICANSignalRule() = default;

            /**
             * The destructor.
             */
            virtual ~ICANSignalRule() = default;

            /**
             * The copy/move constructors.
             */
            ICANSignalRule(const ICANSignalRule&) = delete;
            ICANSignalRule(ICANSignalRule&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICANSignalRule &operator=(const ICANSignalRule&) = delete;
            ICANSignalRule &operator=(ICANSignalRule&&) = delete;

            /**
             * Gets the bit start.
             * The bit start counts from 0 and marks the start of the signal in the data payload.
             */
            virtual size_t getBitStart() const = 0;

            /**
             * Gets the bit length.
             * The bit length is the signal length.
             */
            virtual size_t getBitLength() const = 0;

            /**
             * Returns true if the byte order is big endian.
             * Returns false of the byte order is little endian.
             */
            virtual bool byteOrderBigEndian() const = 0;

            /**
             * Returns if the value type is unsigned.
             */
            virtual bool valueTypeUnsigned() const = 0;

            /**
             * Gets the scale.
             * physical_value = offset + scale * raw_value_decimal
             */
            virtual float getScale() const = 0;

            /**
             * Gets the offset.
             * physical_value = offset + scale * raw_value_decimal
             */
            virtual int getOffset() const = 0;

            /**
             * Gets the minimum.
             */
            virtual int getMinimum() const = 0;

            /**
             * Gets the maximum.
             */
            virtual int getMaximum() const = 0;

            /**
             * Gets the unit.
             */
            virtual const std::string& getUnit() const = 0;

            /**
             * Gets the transmitting node name.
             */
            virtual const std::string& getTransmittingNodeName() const = 0;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const = 0;

            /**
             * Writers the content of the rule.
             */
            virtual void writeRule(std::ostream& output) const = 0;
        };

        using ICANSignalRulePtr = std::shared_ptr<ICANSignalRule>;
    }
}

#endif // I_CAN_SIGNAL_RULE_H_61b97c69_8d48_42ff_bd0d_0d9b16e45ebc
