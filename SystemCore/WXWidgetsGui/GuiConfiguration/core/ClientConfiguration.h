#ifndef CLIENT_CONFIGURATION_0d8f5c5f_0907_4fd7_a08d_46aa5e08e4ca
#define CLIENT_CONFIGURATION_0d8f5c5f_0907_4fd7_a08d_46aa5e08e4ca

#include "IClientConfiguration.h"
#include "IDataContainer.h"
#include "IDataCatalog.h"
#include "DataItem.h"

namespace GuiConfiguration {

    /**
     * The ClientConfiguration class implements configuration of client.
     */
    class ClientConfiguration final : public IClientConfiguration {
    public:
        /**
         * Creates client configuration.
         */
        static IClientConfigurationSharedPtr Make(const std::wstring& name);

        /**
         * The ClientConfiguration constructor.
         */
        explicit ClientConfiguration(const std::wstring& name);

        /**
         * The ClientConfiguration destructor.
         */
        virtual ~ClientConfiguration();

        /**
         * Gets name of client.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Sets a boolean property.
         */
        virtual void SetBooleanProperty(const std::wstring& path, bool value) override;

        /**
         * Gets a boolean property.
         */
        virtual bool GetBooleanProperty(const std::wstring& path) const override;

        /**
         * Sets an integer property.
         */
        virtual void SetIntegerProperty(const std::wstring& path, int value) override;

        /**
         * Gets an integer property.
         */
        virtual int GetIntegerProperty(const std::wstring& path) const override;

        /**
         * Sets a long property.
         */
        virtual void SetLongProperty(const std::wstring& path, long value) override;

        /**
         * Gets a long property.
         */
        virtual long GetLongProperty(const std::wstring& path) const override;

        /**
         * Sets a string property.
         */
        virtual void SetStringProperty(const std::wstring& path, const std::wstring& value) override;

        /**
         * Gets a string property.
         */
        virtual const std::wstring& GetStringProperty(const std::wstring& path) const override;

        /**
         * Sets a string array property.
         */
        virtual void SetStringArrayProperty(const std::wstring& path, const std::vector<std::wstring>& value) override;

        /**
         * Gets a string array property.
         */
        virtual const std::vector<std::wstring>& GetStringArrayProperty(const std::wstring& path) const override;

        /**
         * Sets a string array array property.
         */
        virtual void SetStringArrayArrayProperty(const std::wstring& path, const std::vector<std::vector<std::wstring>>& value) override;

        /**
         * Gets a string array array property.
         */
        virtual const std::vector<std::vector<std::wstring>>& GetStringArrayArrayProperty(const std::wstring& path) const override;

    private:
        /**
         * Sets a property.
         */
        template <typename T>
        void SetProperty(const std::wstring& path, const T& value);

        DataContainerManagement::IDataContainerSharedPtr m_dataContainer;
    };

    /**
     * Sets a property.
     */
    template <typename T>
    void ClientConfiguration::SetProperty(const std::wstring& path, const T& value)
    {
        DataContainerManagement::IDataCatalog& dataCatalog = m_dataContainer->GetCatalog();
        dataCatalog.RegisterDataItem(path);

        DataContainerManagement::IDataItemSharedPtr dataItem = DataContainerManagement::DataItem::Create(
            path,
            value);

        m_dataContainer->SetDataItem(dataItem);
    }

} // namespace GuiConfiguration

#endif // CLIENT_CONFIGURATION_0d8f5c5f_0907_4fd7_a08d_46aa5e08e4ca
