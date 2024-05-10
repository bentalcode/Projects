#pragma once

#include "IFrameConfigurationItems.h"
#include <string>

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The FrameConfigurationItems class implements configuration items of frames.
 */
class FrameConfigurationItems final : public IFrameConfigurationItems {
public:
    /**
     * Reads frame configuration items from configuration catalog.
     */
    static const IFrameConfigurationItems& Read();

    /**
     * Creates frame configuration items.
     */
    static GuiConfiguration::IConfigurationItemsSharedPtr Make();

    /**
     * The FrameConfigurationItems constructor.
     */
    FrameConfigurationItems();

    /**
     * The FrameConfigurationItems destructor.
     */
    virtual ~FrameConfigurationItems();

    /**
     * Gets category name of data items.
     */
    virtual const std::wstring& GetName() const override;

    /**
     * Gets name of main frame.
     */
    virtual const std::wstring& GetMainFrameName() const override;

    /**
     * Gets status text of main frame.
     */
    virtual const std::wstring& GetMainFrameStatusText() const override;

private:
    static const std::wstring NAME;
    static const std::wstring MAIN_FRAME_NAME;
    static const std::wstring MAIN_FRAME_STATUS_TEXT;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
