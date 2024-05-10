#ifndef I_CLIENT_CONFIGURATION_174e87f4_308f_473c_9cce_ecd017cea47d
#define I_CLIENT_CONFIGURATION_174e87f4_308f_473c_9cce_ecd017cea47d

#include <memory>
#include <string>
#include <vector>

namespace GuiConfiguration {

    /**
     * The IClientConfiguration class defines an interface of configuration of a client.
     */
    class IClientConfiguration {
    public:
        IClientConfiguration() = default;
        virtual ~IClientConfiguration() = default;

        /**
         * Gets name of client.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Sets a boolean property.
         */
        virtual void SetBooleanProperty(const std::wstring& path, bool value) = 0;

        /**
         * Gets a boolean property.
         */
        virtual bool GetBooleanProperty(const std::wstring& path) const = 0;

        /**
         * Sets an integer property.
         */
        virtual void SetIntegerProperty(const std::wstring& path, int value) = 0;

        /**
         * Gets an integer property.
         */
        virtual int GetIntegerProperty(const std::wstring& path) const = 0;

        /**
         * Sets a long property.
         */
        virtual void SetLongProperty(const std::wstring& path, long value) = 0;

        /**
         * Gets a long property.
         */
        virtual long GetLongProperty(const std::wstring& path) const = 0;

        /**
         * Sets a string property.
         */
        virtual void SetStringProperty(const std::wstring& path, const std::wstring& value) = 0;

        /**
         * Gets a string property.
         */
        virtual const std::wstring& GetStringProperty(const std::wstring& path) const = 0;

        /**
         * Sets a string array property.
         */
        virtual void SetStringArrayProperty(const std::wstring& path, const std::vector<std::wstring>& value) = 0;

        /**
         * Gets a string array property.
         */
        virtual const std::vector<std::wstring>& GetStringArrayProperty(const std::wstring& path) const = 0;

        /**
         * Sets a string array array property.
         */
        virtual void SetStringArrayArrayProperty(const std::wstring& path, const std::vector<std::vector<std::wstring>>& value) = 0;

        /**
         * Gets a string array array property.
         */
        virtual const std::vector<std::vector<std::wstring>>& GetStringArrayArrayProperty(const std::wstring& path) const = 0;
    };

    //
    // Defines the Shared Ptr of Client Configuration.
    //
    using IClientConfigurationSharedPtr = std::shared_ptr<IClientConfiguration>;

} // namespace GuiConfiguration

#endif // I_CLIENT_CONFIGURATION_174e87f4_308f_473c_9cce_ecd017cea47d
