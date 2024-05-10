#pragma once

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer {
    
namespace Gui {

/**
 * The IAppConfigurationItems interface defines configuration items of app.
 */
class IAppConfigurationItems : public GuiConfiguration::IConfigurationItems {
public:
    IAppConfigurationItems() = default;
    virtual ~IAppConfigurationItems() = default;

    /**
     * Gets name of a app.
     */
    virtual const std::wstring& GetAppName() const = 0;

    /**
     * Gets log path.
     */
    virtual const std::wstring& GetLogPath() const = 0;
};

} // namespace Gui

}  // namespace VideoRenderingVisualizer
