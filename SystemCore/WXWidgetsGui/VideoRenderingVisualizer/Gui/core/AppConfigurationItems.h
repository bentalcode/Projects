#pragma once

#include "IAppConfigurationItems.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The AppConfigurationItems class implements configuration items of an app.
 */
class AppConfigurationItems final : public IAppConfigurationItems {
public:
    /**
     * Reads app configuration items from configuration catalog.
     */
    static const IAppConfigurationItems& Read();

    /**
     * Creates app configuration items.
     */
    static GuiConfiguration::IConfigurationItemsSharedPtr Make();

    /**
     * The AppConfigurationItems constructor.
     */
    AppConfigurationItems();

    /**
     * The AppConfigurationItems destructor.
     */
    virtual ~AppConfigurationItems();

    /**
     * Gets category name of data items.
     */
    virtual const std::wstring& GetName() const override;

    /**
     * Gets name of an app.
     */
    virtual const std::wstring& GetAppName() const override;

    /**
     * Gets log path.
     */
    virtual const std::wstring& GetLogPath() const override;

private:
    static const std::wstring NAME;
    static const std::wstring APP_NAME;
    static const std::wstring LOG_PATH;
};

} // namespace Gui

}  // namespace VideoRenderingVisualizer
