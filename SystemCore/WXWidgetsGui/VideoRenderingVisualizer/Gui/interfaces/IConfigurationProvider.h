#pragma once

#include "IGuiConfigurationManager.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The IConfigurationProvider class defines an interface of a provider of a configuration.
 */
class IConfigurationProvider {
public:
    IConfigurationProvider() = default;
    virtual ~IConfigurationProvider() = default;

    /**
     * Gets a configuration manager of GUI.
     */
    virtual GuiConfiguration::IGuiConfigurationManagerSharedPtr GetGuiConfigurationManager() const = 0;
};

//
// Defines the Shared Ptr of Configuration Provider.
//
using IConfigurationProviderSharedPtr = std::shared_ptr<IConfigurationProvider>;

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
