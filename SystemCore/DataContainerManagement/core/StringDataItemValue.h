#ifndef ABSTRACT_DATA_ITEM_VALUE_H_803b55db_fe7e_43c3_abfd_fdcd9f80e364
#define ABSTRACT_DATA_ITEM_VALUE_H_803b55db_fe7e_43c3_abfd_fdcd9f80e364

#include "AbstractDataItemValue.h"

namespace DataContainerManagement {

    /**
     * The StringDataItemValue class implements a string value of a data item.
     */
    class StringDataItemValue final : public AbstractDataItemValue {
    public:
        /**
         * Creates a data item of type string.
         */
        static IDataItemValueSharedPtr Create(const std::wstring& value);

        /**
         * The StringDataItemValue constructor.
         */
        explicit StringDataItemValue(const std::wstring& value);

        /**
         * The StringDataItemValue destructor.
         */
        virtual ~StringDataItemValue();

        /**
         * Gets a string value of a data item.
         */
        virtual const std::wstring& GetString() const override;

        /**
         * Checks whether values are equals.
         */
        virtual bool Equals(const IDataItemValue& other) const override;

    private:
        std::wstring m_value;
    };

} // namespace DataContainerManagement

#endif // ABSTRACT_DATA_ITEM_VALUE_H_803b55db_fe7e_43c3_abfd_fdcd9f80e364

