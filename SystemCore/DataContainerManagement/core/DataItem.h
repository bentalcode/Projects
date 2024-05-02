#ifndef DATA_ITEM_H_d34368e8_1b01_49f1_ba11_3aa7cd468cc4
#define DATA_ITEM_H_d34368e8_1b01_49f1_ba11_3aa7cd468cc4

#include "IDataItem.h"
#include "IDataItemValue.h"
#include "ILoggers.h"

namespace DataContainerManagement {

    /**
     * The DataItem class implements a generic data item.
     */
    class DataItem final : public IDataItem {
    public:
        /**
         * Creates a boolean data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            bool value);

        /**
         * Creates an integer data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            int value);

        /**
         * Creates a long data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            long value);

        /**
         * Creates a double data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            double value);

        /**
         * Creates a string data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            const std::wstring& value);

        /**
         * Creates a date-time data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            const base::DateTime& value);

        /**
         * Creates a duration data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            const base::Duration& value);

        /**
         * Creates a string array data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            const std::vector<std::wstring>& value);

        /**
         * Creates an array of string array data item.
         */
        static IDataItemSharedPtr Create(
            const std::wstring& name,
            const std::vector<std::vector<std::wstring>>& value);

        /**
         * The DataItem constructor.
         */
        DataItem(
            const std::wstring& name,
            IDataItemValueSharedPtr value);

        /**
         * The DataItem destructor.
         */
        virtual ~DataItem();

        /**
         * Gets the name of a data item.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets the value of a data item.
         */
        virtual const IDataItemValueSharedPtr GetValue() const override;

    private:
        logging::ILoggersSharedPtr m_loggers;

        std::wstring m_name;
        IDataItemValueSharedPtr m_value;
    };

} // namespace DataContainerManagement

#endif // DATA_ITEM_H_d34368e8_1b01_49f1_ba11_3aa7cd468cc4
