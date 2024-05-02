#ifndef STRING_ARRAY_DATA_ITEM_VALUE_H_a54b4bf3_ca5e_46ad_872a_225c2aa2fbd8
#define STRING_ARRAY_DATA_ITEM_VALUE_H_a54b4bf3_ca5e_46ad_872a_225c2aa2fbd8

#include "AbstractDataItemValue.h"

namespace DataContainerManagement {

    /**
     * The StringArrayDataItemValue class implements a string array value of data items.
     */
    class StringArrayDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type string array.
         */
        static IDataItemValueSharedPtr Create(const std::vector<std::wstring>& values);

        /**
         * The StringArrayDataItemValue constructor.
         */
        explicit StringArrayDataItemValue(const std::vector<std::wstring>& values);

        /**
         * The StringArrayDataItemValue destructor.
         */
        virtual ~StringArrayDataItemValue();

        /**
         * Gets a string array value of a data item.
         */
        virtual const std::vector<std::wstring>& GetStringArray() const override;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        std::vector<std::wstring> m_values;
    };

} // namespace DataContainerManagement

#endif // STRING_ARRAY_DATA_ITEM_VALUE_H_a54b4bf3_ca5e_46ad_872a_225c2aa2fbd8
