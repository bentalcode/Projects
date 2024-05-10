#pragma once

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
namespace Gui {

/**
 * The IFrameConfigurationItems interface defines configuration items of frames.
 */
class IFrameConfigurationItems : public GuiConfiguration::IConfigurationItems {
public:
    IFrameConfigurationItems() = default;
    virtual ~IFrameConfigurationItems() = default;

    /**
     * Gets name of main frame.
     */
    virtual const std::wstring& GetMainFrameName() const = 0;

    /**
     * Gets status text of main frame.
     */
    virtual const std::wstring& GetMainFrameStatusText() const = 0;
};

}

}  // namespace VideoRenderingVisualizer::Gui
