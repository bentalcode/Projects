#ifndef ABSTRACT_DATA_ITEM_VALUE_H_99a451ed_2965_4725_9a43_891f8655dabc
#define ABSTRACT_DATA_ITEM_VALUE_H_99a451ed_2965_4725_9a43_891f8655dabc

#include "IDataItemValue.h"
#include "ILoggers.h"

namespace DataContainerManagement {

    /**
     * The AbstractDataItemValue class implements an abstract value of a data item.
     */
    class AbstractDataItemValue : public IDataItemValue {
    public:
        /**
         * The AbstractDataItemValue constructor.
         */
        AbstractDataItemValue();

        /**
         * The AbstractDataItemValue destructor.
         */
        virtual ~AbstractDataItemValue();

        /**
         * Gets a boolean value.
         */
        virtual bool GetBoolean() const override;

        /**
         * Gets an integer value.
         */
        virtual int GetInteger() const override;

        /**
         * Gets a long value.
         */
        virtual long GetLong() const override;

        /**
         * Gets a double value.
         */
        virtual double GetDouble() const override;

        /**
         * Gets a string value.
         */
        virtual const std::wstring& GetString() const override;

        /**
         * Gets a date time.
         */
        virtual const base::DateTime& GetDateTime() const override;

        /**
         * Gets a duration value.
         */
        virtual const base::Duration& GetDuration() const override;

        /**
         * Gets a string array value.
         */
        virtual const std::vector<std::wstring>& GetStringArray() const override;

        /**
         * Gets a string array value.
         */
        virtual const std::vector<std::vector<std::wstring>>& GetStringArrayArray() const override;

    private:
        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace DataContainerManagement

#endif // ABSTRACT_DATA_ITEM_VALUE_H_99a451ed_2965_4725_9a43_891f8655dabc
