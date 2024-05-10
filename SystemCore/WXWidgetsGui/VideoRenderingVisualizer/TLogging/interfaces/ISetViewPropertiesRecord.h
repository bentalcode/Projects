#ifndef I_SET_VIEW_PROPERTIES_RECORD_H_a8d1e6c8_40cf_4d11_a938_00d5e7e6efda
#define I_SET_VIEW_PROPERTIES_RECORD_H_a8d1e6c8_40cf_4d11_a938_00d5e7e6efda

#include "ITLogRecord.h"
#include <string>
#include <map>

namespace tlogging {

    /**
     * The ISetViewPropertiesRecord interface defines a Set View Properties Record.
     */
    class ISetViewPropertiesRecord : public ITLogRecord {
    public:
        ISetViewPropertiesRecord() = default;
        virtual ~ISetViewPropertiesRecord() = default;

        /**
         * Gets an optional header.
         */
        virtual const std::wstring& GetHeader() const = 0;

        //
        // Defines the properties of configuration.
        //
        using PropertyMap = std::map<std::wstring, std::wstring>;
        using PropertyMapSharedPtr = std::shared_ptr<PropertyMap>;

        /**
         * Checks whether a property exists.
         */
        virtual bool HasProperty(const std::wstring& name) const = 0;

        /**
         * Gets a value of a property.
         */
        virtual const std::wstring& GetPropertyValue(const std::wstring& name) const = 0;

        /**
         * Gets properties of configuration.
         */
        virtual const PropertyMap& GetProperties() const = 0;
    };

    /**
     * Defines the Shared Ptr of Set View Properties Record.
     */
    using ISetViewPropertiesRecordSharedPtr = std::shared_ptr<ISetViewPropertiesRecord>;

} // namespace tlogging

#endif // I_SET_VIEW_PROPERTIES_RECORD_H_a8d1e6c8_40cf_4d11_a938_00d5e7e6efda
