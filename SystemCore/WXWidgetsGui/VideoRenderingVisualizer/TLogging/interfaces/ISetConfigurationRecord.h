#ifndef I_SET_CONFIGURATION_RECORD_H_d3b5137e_cc67_46d5_8b7b_1f64a81f72ef
#define I_SET_CONFIGURATION_RECORD_H_d3b5137e_cc67_46d5_8b7b_1f64a81f72ef

#include "ITLogRecord.h"
#include <string>
#include <map>

namespace tlogging {

    /**
     * The ISetConfigurationRecord interface defines a Set Configuration Record.
     */
    class ISetConfigurationRecord : public ITLogRecord {
    public:
        ISetConfigurationRecord() = default;
        virtual ~ISetConfigurationRecord() = default;

        //
        // Defines properties of configuration.
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
     * Defines the Shared Ptr of Set Configuration Record.
     */
    using ISetConfigurationRecordSharedPtr = std::shared_ptr<ISetConfigurationRecord>;

} // namespace tlogging

#endif // I_SET_CONFIGURATION_RECORD_H_d3b5137e_cc67_46d5_8b7b_1f64a81f72ef
