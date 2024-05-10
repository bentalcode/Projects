#pragma once

#include "IDataItems.h"

namespace VideoRenderingVisualizer {
    
namespace Gui {

/**
 * The IGuiDataItems interface defines data items of GUI.
 */
class IGuiDataItems : public WXWidgets::IDataItems {
public:
    IGuiDataItems() = default;
    virtual ~IGuiDataItems() = default;

    /**
     * Gets a compositor id.
     */
    virtual const std::wstring& GetCompositorId() const = 0;

    /**
     * Gets events start interval time.
     */
    virtual const std::wstring& GetEventsStartIntervalTime() const = 0;

    /**
     * Gets events end interval time.
     */
    virtual const std::wstring& GetEventsEndIntervalTime() const = 0;

    /**
     * Gets rendering pipelines start interval time.
     */
    virtual const std::wstring& GetRenderingPipelinesStartIntervalTime() const = 0;

    /**
     * Gets rendering pipelines end interval time.
     */
    virtual const std::wstring& GetRenderingPipelinesEndIntervalTime() const = 0;
};

} // namespace Gui

}  // namespace VideoRenderingVisualizer
