#pragma once

#include "IGuiWindow.h"
#include "ILoggers.h"

namespace VideoRenderingVisualizer { 
    
namespace Gui {

class IGuiManager;

/**
 * The AbstractGuiWindow class implements an abstract GUI Window.
 */
class AbstractGuiWindow : public IGuiWindow {
protected:
    /**
     * The AbstractGuiWindow constructor.
     */
    AbstractGuiWindow(
        const std::wstring& name, 
        IGuiManager& guiManager);

public:
    /**
     * The AbstractGuiWindow destructor.
     */
    virtual ~AbstractGuiWindow();

protected:
    /**
     * Gets GUI manager.
     */
    IGuiManager& GetGuiManager();

    /**
     * Gets logger of GUI component.
     */
    Logging::ILoggerSharedPtr GetLogger();

private:
    //
    // The name of the window...
    //
    std::wstring m_name;

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;

    //
    // The loggers of the window...
    //
    Logging::ILoggersSharedPtr m_loggers;
};

}

}  // namespace VideoRenderingVisualizer::Gui
