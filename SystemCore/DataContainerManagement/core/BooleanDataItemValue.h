#ifndef BOOLEAN_DATA_ITEM_VALUE_H_b9f0dd68_579b_4917_b6ab_d4eaad64229a
#define BOOLEAN_DATA_ITEM_VALUE_H_b9f0dd68_579b_4917_b6ab_d4eaad64229a

#include "AbstractDataItemValue.h"

namespace DataContainerManagement {

    /**
     * The BooleanDataItemValue class implements a boolean value of a data item.
     */
    class BooleanDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type boolean.
         */
        static IDataItemValueSharedPtr Create(bool value);

        /**
         * The BooleanDataItemValue constructor.
         */
        explicit BooleanDataItemValue(bool value);

        /**
         * The BooleanDataItemValue destructor.
         */
        virtual ~BooleanDataItemValue();

        /**
         * Gets a boolean value of a data item.
         */
        virtual bool GetBoolean() const override;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        bool m_value;
    };

} // namespace DataContainerManagement

#endif // BOOLEAN_DATA_ITEM_VALUE_H_b9f0dd68_579b_4917_b6ab_d4eaad64229a
