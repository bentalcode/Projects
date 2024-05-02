#ifndef I_DATA_ITEM_VALUE_H_c2992008_ef85_4fd2_92d7_bc3f4b45f8c1
#define I_DATA_ITEM_VALUE_H_c2992008_ef85_4fd2_92d7_bc3f4b45f8c1

#include <memory>
#include <string>
#include <vector>
#include "Duration.h"

namespace DataContainerManagement {

    /**
     * The IDataItemValue class defines an interface of a value of a data item.
     */
    class IDataItemValue {
    public:
        /**
         * The IDataItemValue constructor.
         */
        IDataItemValue() = default;

        /**
         * The IDataItemValue destructor.
         */
        virtual ~IDataItemValue() = default;

        /**
         * Gets a boolean value.
         */
        virtual bool GetBoolean() const = 0;

        /**
         * Gets an integer value.
         */
        virtual int GetInteger() const = 0;

        /**
         * Gets a long value.
         */
        virtual long GetLong() const = 0;

        /**
         * Gets a double value.
         */
        virtual double GetDouble() const = 0;

        /**
         * Gets a string value.
         */
        virtual const std::wstring& GetString() const = 0;

        /**
         * Gets a date time.
         */
        virtual const base::DateTime& GetDateTime() const = 0;

        /**
         * Gets a duration value.
         */
        virtual const base::Duration& GetDuration() const = 0;

        /**
         * Gets a string array value.
         */
        virtual const std::vector<std::wstring>& GetStringArray() const = 0;

        /**
         * Gets an array of string array value of a data item.
         */
        virtual const std::vector<std::vector<std::wstring>>& GetStringArrayArray() const = 0;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const = 0;
    };

    /**
     * Defines an equality operator for Data Item Values.
     */
    inline bool operator==(const IDataItemValue& left, const IDataItemValue& right)
    {
        return left.Equals(right);
    }

    /**
     * Defines a not equality operator for Data Item Values.
     */
    inline bool operator!=(const IDataItemValue& left, const IDataItemValue& right)
    {
        return !(left == right);
    }

    //
    // Defines the Shared Ptr of Data Item Value.
    //
    using IDataItemValueSharedPtr = std::shared_ptr<IDataItemValue>;

} // namespace DataContainerManagement

#endif // I_DATA_ITEM_VALUE_H_c2992008_ef85_4fd2_92d7_bc3f4b45f8c1
