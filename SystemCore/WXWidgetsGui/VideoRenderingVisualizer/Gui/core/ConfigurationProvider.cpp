#include "ConfigurationProvider.h"
#include "GuiConfigurationFactory.h"
#include <memory>

using namespace VideoRenderingVisualizer::Gui;

//
// The Singletone data...
//
IConfigurationProviderSharedPtr ConfigurationProvider::INSTANCE;
std::mutex ConfigurationProvider::MUTEX;

/**
 * Gets an instance of configuration.
 */
IConfigurationProviderSharedPtr ConfigurationProvider::GetInstance()
{
    if (!INSTANCE) {
        std::lock_guard<std::mutex> lock(MUTEX);

        if (!INSTANCE) {
            INSTANCE = ConfigurationProvider::Create();
        }
    }

    return INSTANCE;
}

/**
 * Creates a GUI Configuration Factory.
 */
IConfigurationProviderSharedPtr ConfigurationProvider::Create()
{
    return std::make_shared<ConfigurationProvider>();
}

/**
 * The ConfigurationProvider constructor.
 */
ConfigurationProvider::ConfigurationProvider()
{
    m_guiConfigurationManager = CreateGuiConfigurationManager();
}

/**
 * The ConfigurationProvider destructor.
 */
ConfigurationProvider::~ConfigurationProvider() 
{
}

/**
 * Gets a configuration manager of GUI.
 */
GuiConfiguration::IGuiConfigurationManagerSharedPtr ConfigurationProvider::GetGuiConfigurationManager() const
{
    return m_guiConfigurationManager;
}

/**
 * Creates a GUI configuration manager.
 */
GuiConfiguration::IGuiConfigurationManagerSharedPtr ConfigurationProvider::CreateGuiConfigurationManager()
{
    IGuiConfigurationFactorySharedPtr configurationFactory = GuiConfigurationFactory::Make();
    
    GuiConfiguration::IGuiConfigurationManagerSharedPtr configurationManager =
        configurationFactory->CreateConfigurationManager();
    
    return configurationManager;
}
