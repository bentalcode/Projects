#ifndef LONG_DATA_ITEM_VALUE_H_ade6e894_72e8_440d_b46e_986567d44c87
#define LONG_DATA_ITEM_VALUE_H_ade6e894_72e8_440d_b46e_986567d44c87

#include "AbstractDataItemValue.h"

namespace DataContainerManagement {

    /**
     * The LongDataItemValue class implements a long value of a data item.
     */
    class LongDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type long.
         */
        static IDataItemValueSharedPtr Create(long value);

        /**
         * The LongDataItemValue constructor.
         */
        explicit LongDataItemValue(long value);

        /**
         * The LongDataItemValue destructor.
         */
        virtual ~LongDataItemValue();

        /**
         * Gets a long value of a data item.
         */
        virtual long GetLong() const override;

        /**
         * Checks whether values equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        long m_value;
    };

} // namespace DataContainerManagement

#endif // LONG_DATA_ITEM_VALUE_H_ade6e894_72e8_440d_b46e_986567d44c87
