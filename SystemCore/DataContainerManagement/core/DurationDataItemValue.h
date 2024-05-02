#ifndef DURATION_DATA_ITEM_VALUE_H_f4db16c2_3ad4_40cc_bde7_b96bd917a58f
#define DURATION_DATA_ITEM_VALUE_H_f4db16c2_3ad4_40cc_bde7_b96bd917a58f

#include "AbstractDataItemValue.h"
#include "Duration.h"

namespace DataContainerManagement {

    /**
     * The DurationDataItemValue class implements a duration value of a data item.
     */
    class DurationDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type duration.
         */
        static IDataItemValueSharedPtr Create(const base::Duration& value);

        /**
         * The DurationDataItemValue constructor.
         */
        explicit DurationDataItemValue(const base::Duration& value);

        /**
         * The DurationDataItemValue destructor.
         */
        virtual ~DurationDataItemValue();

        /**
         * Gets a duration value of a data item.
         */
        virtual const base::Duration& GetDuration() const override;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        base::Duration m_value;
    };

} // namespace DataContainerManagement

#endif // DURATION_DATA_ITEM_VALUE_H_f4db16c2_3ad4_40cc_bde7_b96bd917a58f
