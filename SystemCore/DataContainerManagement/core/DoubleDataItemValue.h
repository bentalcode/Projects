#ifndef DOUBLE_DATA_ITEM_VALUE_H_28965aab_8564_4107_a41c_36b8f025f93d
#define DOUBLE_DATA_ITEM_VALUE_H_28965aab_8564_4107_a41c_36b8f025f93d

#include "AbstractDataItemValue.h"

namespace DataContainerManagement {

    /**
     * The DoubleDataItemValue class implements a double value of a data item.
     */
    class DoubleDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type double.
         */
        static IDataItemValueSharedPtr Create(double value);

        /**
         * The DoubleDataItemValue constructor.
         */
        explicit DoubleDataItemValue(double value);

        /**
         * The DoubleDataItemValue destructor.
         */
        virtual ~DoubleDataItemValue();

        /**
         * Gets a double value of a data item.
         */
        virtual double GetDouble() const override;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        double m_value;
    };

} // namespace DataContainerManagement

#endif // DOUBLE_DATA_ITEM_VALUE_H_28965aab_8564_4107_a41c_36b8f025f93d
