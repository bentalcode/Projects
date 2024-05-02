#ifndef DATE_TIME_DATA_ITEM_VALUE_H_a34d940c_2ebc_4bf3_9c8c_238700530bfd
#define DATE_TIME_DATA_ITEM_VALUE_H_a34d940c_2ebc_4bf3_9c8c_238700530bfd

#include "AbstractDataItemValue.h"
#include "DateTime.h"

namespace DataContainerManagement {

    /**
     * The DateTimeDataItemValue class implements a date time value of a data item.
     */
    class DateTimeDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type date time.
         */
        static IDataItemValueSharedPtr Create(const base::DateTime& value);

        /**
         * The DateTimeDataItemValue constructor.
         */
        explicit DateTimeDataItemValue(const base::DateTime& value);

        /**
         * The DateTimeDataItemValue destructor.
         */
        virtual ~DateTimeDataItemValue();

        /**
         * Gets a date time value of a data item.
         */
        virtual const base::DateTime& GetDateTime() const override;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        base::DateTime m_value;
    };

} // namespace DataContainerManagement

#endif // DATE_TIME_DATA_ITEM_VALUE_H_a34d940c_2ebc_4bf3_9c8c_238700530bfd
