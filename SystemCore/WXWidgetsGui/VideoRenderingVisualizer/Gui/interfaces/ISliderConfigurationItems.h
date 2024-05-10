#pragma once

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
namespace Gui {

/**
 * The ISliderConfigurationItems interface defines configuration items of sliders.
 */
class ISliderConfigurationItems : public GuiConfiguration::IConfigurationItems {
public:
    ISliderConfigurationItems() = default;
    virtual ~ISliderConfigurationItems() = default;

    /**
     * Gets name of main right top window lower sub window - min number of units.
     */
    virtual const unsigned int GetMainRightTopWindowLowerSubWindowSliderMinNumberOfUnits() const = 0;

    /**
     * Gets name of main right top window lower sub window - max number of units.
     */
    virtual const unsigned int GetMainRightTopWindowLowerSubWindowSliderMaxNumberOfUnits() const = 0;
};

}

}  // namespace VideoRenderingVisualizer::Gui
