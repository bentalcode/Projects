#pragma once

#include "IGuiComponentsConfiguration.h"
#include "GuiConfigurationException.h"
#include "Loggers.h"
#include <map>

namespace GuiConfiguration {

/**
 * The GuiComponentsConfiguration class implements configuration of components.
 */
template <typename ConfigurationType>
class GuiComponentsConfiguration final : public IGuiComponentsConfiguration<ConfigurationType> {
public:
    /**
     * The GuiComponentsConfiguration constructor.
     */
    GuiComponentsConfiguration();

    /**
     * The GuiComponentsConfiguration destructor.
     */
    virtual ~GuiComponentsConfiguration();

    /**
     * Adds a configuration of a component by path.
     */
    virtual void AddConfiguration(
        const std::wstring& path, 
        typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr configuration) override;

    /**
     * Gets a configuration of a component by path.
     */
    virtual const typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr GetConfiguration(const std::wstring& path) const override;

    /**
     * Checks whether a configuration of a component exists.
     */
    virtual bool ConfigurationExists(const std::wstring& path) const override;

private:
    /**
     * Finds a configuration of a component by path.
     */
    const typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr FindConfiguration(const std::wstring& path) const;

    using ComponentConfigurationMap = std::map<std::wstring, typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr>;
    ComponentConfigurationMap m_componentConfigurationMap;

    logging::ILoggersSharedPtr m_loggers;
};

/**
 * The GuiComponentsConfiguration constructor.
 */
template <typename ConfigurationType>
GuiComponentsConfiguration<ConfigurationType>::GuiComponentsConfiguration() : 
    m_loggers(logging::Loggers::Make(typeid(GuiConfiguration::GuiComponentsConfiguration<ConfigurationType>)))
{
}

/**
 * The GuiComponentsConfiguration destructor.
 */
template <typename ConfigurationType>
GuiComponentsConfiguration<ConfigurationType>::~GuiComponentsConfiguration()
{
}

/**
 * Adds a configuration of a component by path.
 */
template <typename ConfigurationType>
void GuiComponentsConfiguration<ConfigurationType>::AddConfiguration(
    const std::wstring& path, 
    typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr configuration)
{
    if (ConfigurationExists(path)) {
        long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The configuration of GUI component with path: " << path << L" is already defined"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw GuiConfigurationException(errorCode, errorMessage);
    }

    m_componentConfigurationMap.insert(std::make_pair(path, configuration));
}

/**
 * Gets a configuration of a component by path.
 */
template <typename ConfigurationType>
const typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr
GuiComponentsConfiguration<ConfigurationType>::GetConfiguration(const std::wstring& path) const
{
    typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr configuration = FindConfiguration(path);

    if (configuration == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The configuration of GUI component with path: " << path << L" has not been found"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw GuiConfigurationException(errorCode, errorMessage);
    }

    return configuration;
}

/**
 * Checks whether a configuration of a component exists.
 */
template <typename ConfigurationType>
bool GuiComponentsConfiguration<ConfigurationType>::ConfigurationExists(const std::wstring& path) const
{
    return m_componentConfigurationMap.find(path) != m_componentConfigurationMap.end();
}

/**
 * Finds a configuration of a component by path.
 */
template <typename ConfigurationType>
const typename IGuiComponentsConfiguration<ConfigurationType>::ConfigurationTypeSharedPtr
GuiComponentsConfiguration<ConfigurationType>::FindConfiguration(const std::wstring& path) const
{
    typename ComponentConfigurationMap::const_iterator configurationIterator = m_componentConfigurationMap.find(path);

    if (configurationIterator == m_componentConfigurationMap.end()) {
        return nullptr;
    }

    return configurationIterator->second;
}

} // namespace GuiConfiguration
