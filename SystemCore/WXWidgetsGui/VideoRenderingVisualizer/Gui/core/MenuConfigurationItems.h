#pragma once

#include "IMenuConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
namespace Gui {

/**
 * The MenuConfigurationItems class implements configuration items of menus.
 */
class MenuConfigurationItems final : public IMenuConfigurationItems {
public:
    /**
     * Reads menu configuration items from configuration catalog.
     */
    static const IMenuConfigurationItems& Read();

    /**
     * Creates menu configuration items.
     */
    static GuiConfiguration::IConfigurationItemsSharedPtr Make();

    /**
     * The MenuConfigurationItems constructor.
     */
    MenuConfigurationItems();

    /**
     * The MenuConfigurationItems destructor.
     */
    virtual ~MenuConfigurationItems();

    /**
     * Gets category name of data items.
     */
    virtual const std::wstring& GetName() const override;

private:
    static const std::wstring NAME;
};

}

}  // namespace VideoRenderingVisualizer::Gui
