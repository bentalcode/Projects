#pragma once

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
namespace Gui {

/**
 * The IMenuConfigurationItems interface defines configuration items of menus.
 */
class IMenuConfigurationItems : public GuiConfiguration::IConfigurationItems {
public:
    IMenuConfigurationItems() = default;
    virtual ~IMenuConfigurationItems() = default;
};

}

}  // namespace VideoRenderingVisualizer::Gui
