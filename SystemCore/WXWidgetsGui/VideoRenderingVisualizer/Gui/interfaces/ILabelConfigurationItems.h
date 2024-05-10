#pragma once

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { namespace Gui {

/**
 * The ILabelConfigurationItems interface defines configuration items of label.
 */
class ILabelConfigurationItems : public GuiConfiguration::IConfigurationItems {
public:
    ILabelConfigurationItems() = default;
    virtual ~ILabelConfigurationItems() = default;

    /**
     * Gets label of main left window.
     */
    virtual const std::wstring& GetMainLeftWindowLabel() const = 0;

    /**
     * Gets label of main right window.
     */
    virtual const std::wstring& GetMainRightWindowLabel() const = 0;

    /**
     * Gets label of main left top window.
     */
    virtual const std::wstring& GetMainLeftTopWindowLabel() const = 0;

    /**
     * Gets label of main left bottom window.
     */
    virtual const std::wstring& GetMainLeftBottomWindowLabel() const = 0;

    /**
     * Gets label of main left top window - upper sub window.
     */
    virtual const std::wstring& GetMainLeftTopWindowUpperSubWindowLabel() const = 0;

    /**
     * Gets label of main left top window - lower sub window.
     */
    virtual const std::wstring& GetMainLeftTopWindowLowerSubWindowLabel() const = 0;

    /**
     * Gets label of main right top window.
     */
    virtual const std::wstring& GetMainRightTopWindowLabel() const = 0;

    /**
     * Gets label of main right bottom window.
     */
    virtual const std::wstring& GetMainRightBottomWindowLabel() const = 0;

    /**
     * Gets label of main right top window - upper sub window.
     */
    virtual const std::wstring& GetMainRightTopWindowUpperSubWindowLabel() const = 0;

    /**
     * Gets label of main right top window - lower sub window.
     */
    virtual const std::wstring& GetMainRightTopWindowLowerSubWindowLabel() const = 0;
};

}

}  // namespace VideoRenderingVisualizer::Gui
