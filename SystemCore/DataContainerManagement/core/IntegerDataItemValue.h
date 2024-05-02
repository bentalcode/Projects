#ifndef INTEGER_DATA_ITEM_VALUE_H_f9d0f038_90da_48f1_a0db_344b27412257
#define INTEGER_DATA_ITEM_VALUE_H_f9d0f038_90da_48f1_a0db_344b27412257

#include "AbstractDataItemValue.h"

namespace DataContainerManagement {

    /**
     * The IntegerDataItemValue class implements an integer value of a data item.
     */
    class IntegerDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type integer.
         */
        static IDataItemValueSharedPtr Create(int value);

        /**
         * The IntegerDataItemValue constructor.
         */
        explicit IntegerDataItemValue(int value);

        /**
         * The IntegerDataItemValue destructor.
         */
        virtual ~IntegerDataItemValue();

        /**
         * Gets an integer value of a data item.
         */
        virtual int GetInteger() const override;

        /**
         * Checks whether values equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        int m_value;
    };

} // namespace DataContainerManagement

#endif // INTEGER_DATA_ITEM_VALUE_H_f9d0f038_90da_48f1_a0db_344b27412257
