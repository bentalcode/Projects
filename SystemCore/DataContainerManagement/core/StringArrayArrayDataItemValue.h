#ifndef STRING_ARRAY_ARRAY_DATA_ITEM_VALUE_H_51b6c153_21c5_457b_bf48_65ef67c13f14
#define STRING_ARRAY_ARRAY_DATA_ITEM_VALUE_H_51b6c153_21c5_457b_bf48_65ef67c13f14

#include "AbstractDataItemValue.h"

namespace DataContainerManagement {

    /**
     * The StringArrayDataItemValue class implements an array of string array value of data items.
     */
    class StringArrayArrayDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type array of string array.
         */
        static IDataItemValueSharedPtr Create(const std::vector<std::vector<std::wstring>>& values);

        /**
         * The StringArrayArrayDataItemValue constructor.
         */
        explicit StringArrayArrayDataItemValue(const std::vector<std::vector<std::wstring>>& values);

        /**
         * The StringArrayArrayDataItemValue destructor.
         */
        virtual ~StringArrayArrayDataItemValue();

        /**
         * Gets an array of string array value of a data item.
         */
        virtual const std::vector<std::vector<std::wstring>>& GetStringArrayArray() const override;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        std::vector<std::vector<std::wstring>> m_values;
    };

} // namespace DataContainerManagement

#endif // STRING_ARRAY_ARRAY_DATA_ITEM_VALUE_H_51b6c153_21c5_457b_bf48_65ef67c13f14
