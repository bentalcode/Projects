#pragma once

#include <string>
#include <memory>

namespace VideoRenderingVisualizer {
    
namespace Gui {

/**
 * The IGuiPaths interface defines paths of GUI components.
 */
class IGuiPaths {
public:
    IGuiPaths() = default;
    virtual ~IGuiPaths() = default;

    /**
     * Gets app.
     */
    virtual const std::wstring& GetApp() const = 0;

    /**
     * Gets main frame.
     */
    virtual const std::wstring& GetMainFrame() const = 0;

    /**
     * Gets frame of main frame.
     */
    virtual const std::wstring& GetMainFrameFrame() const = 0;

    /**
     * Gets top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBar() const = 0;

    /**
     * Gets file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenu() const = 0;

    /**
     * Gets view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenu() const = 0;

    /**
     * Gets help menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarHelpMenu() const = 0;

    /**
     * Gets open menu item of file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenMenuItem() const = 0;

    /**
     * Gets exit menu item of file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenuExitMenuItem() const = 0;

    /**
     * Gets rendering pipelines visualizer menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItem() const = 0;

    /**
     * Gets rendering pipelines visualizer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialog() const = 0;
   
    /**
     * Gets event viewer menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerMenuItem() const = 0;

    /**
     * Gets log statisitcs menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItem() const = 0;

    /**
     * Gets app log menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogMenuItem() const = 0;

    /**
     * Gets about menu item of help menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItem() const = 0;

    /**
     * Gets open folder dialog of file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenFolderDialog() const = 0;

    /**
     * Gets event viewer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerDialog() const = 0;

    /**
     * Gets log statistics dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsDialog() const = 0;

    /**
     * Gets app log dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogDialog() const = 0;

    /**
     * Gets splitter window of main window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainWindowSplitterWindow() const = 0;

    /**
     * Gets label of main left window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftWindowLabel() const = 0;

    /**
     * Gets label of main right window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightWindowLabel() const = 0;

    /**
     * Gets splitter window of main left window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftWindowSplitterWindow() const = 0;

    /**
     * Gets label of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowLabel() const = 0;

    /**
     * Gets label of main left bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftBottomWindowLabel() const = 0;

    /**
     * Gets splitter window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowSplitterWindow() const = 0;

    /**
     * Gets static text of main left bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftBottomWindowStaticText() const = 0;

    /**
     * Gets label of upper sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowUpperSubWindowLabel() const = 0;

    /**
     * Gets label of lower sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowLowerSubWindowLabel() const = 0;

    /**
     * Gets list box of upper sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowUpperSubWindowListBox() const = 0;

    /**
     * Gets list box of lower sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowLowerSubWindowListBox() const = 0;

    /**
     * Gets splitter window of main right window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightWindowSplitterWindow() const = 0;

    /**
     * Gets label of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowLabel() const = 0;

    /**
     * Gets label of main right bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightBottomWindowLabel() const = 0;

    /**
     * Gets splitter window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowSplitterWindow() const = 0;

    /**
     * Gets list view of main right bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightBottomWindowListView() const = 0;

    /**
     * Gets label of upper sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowUpperSubWindowLabel() const = 0;

    /**
     * Gets label of lower sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowLowerSubWindowLabel() const = 0;

    /**
     * Gets canvas of upper sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowUpperSubWindowCanvas() const = 0;

    /**
     * Gets slider of lower sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowLowerSubWindowSlider() const = 0;

    /**
     * Gets html window of rendering pipelines visualizer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialogHtmlWindow() const = 0;

    /**
     * Gets list view of event viewer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerDialogListView() const = 0;

    /**
     * Gets list view of log statistics dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsDialogListView() const = 0;

    /**
     * Gets list view of app log dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogDialogListView() const = 0;
};

//
// Defines the Shared Ptr of Gui Paths.
//
using IGuiPathsSharedPtr = std::shared_ptr<IGuiPaths>;

} // namespace Gui

}  // namespace VideoRenderingVisualizer
