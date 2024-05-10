#pragma once

#include "IGuiPaths.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The GuiPaths class defines path of components in GUI module.
 */
class GuiPaths final : public IGuiPaths {
public:
    /**
     * Reads GUI paths.
     */
    static const IGuiPaths& Read();

    /**
     * Creates GUI Paths.
     */
    static IGuiPathsSharedPtr Make();

    /**
     * The GuiPaths constructor.
     */
    GuiPaths();

    /**
     * The GuiPaths destructor.
     */
    virtual ~GuiPaths();

    /**
     * Gets app.
     */
    virtual const std::wstring& GetApp() const override;

    /**
     * Gets main frame.
     */
    virtual const std::wstring& GetMainFrame() const override;

    /**
     * Gets frame of main frame.
     */
    virtual const std::wstring& GetMainFrameFrame() const override;

    /**
     * Gets top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBar() const override;

    /**
     * Gets file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenu() const override;

    /**
     * Gets view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenu() const override;

    /**
     * Gets help menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarHelpMenu() const override;

    /**
     * Gets open menu item of file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenMenuItem() const override;

    /**
     * Gets exit menu item of file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenuExitMenuItem() const override;

    /**
     * Gets rendering pipelines visualizer menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItem() const override;

    /**
     * Gets event viewer menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerMenuItem() const override;

    /**
     * Gets log statisitcs menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItem() const override;

    /**
     * Gets app log menu item of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogMenuItem() const override;

    /**
     * Gets about menu item of help menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItem() const override;

    /**
     * Gets open folder dialog of file menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenFolderDialog() const override;

    /**
     * Gets rendering pipelines visualizer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialog() const override;

    /**
     * Gets event viewer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerDialog() const override;

    /**
     * Gets log statistics dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsDialog() const override;

    /**
     * Gets app log dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogDialog() const override;

    /**
     * Gets splitter window of main window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainWindowSplitterWindow() const override;

    /**
     * Gets label of main left window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftWindowLabel() const override;

    /**
     * Gets label of main right window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightWindowLabel() const override;

    /**
     * Gets splitter window of main left window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftWindowSplitterWindow() const override;

    /**
     * Gets label of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowLabel() const override;

    /**
     * Gets label of main left bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftBottomWindowLabel() const override;

    /**
     * Gets splitter window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowSplitterWindow() const override;

    /**
     * Gets static text of main left bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftBottomWindowStaticText() const override;

    /**
     * Gets label of upper sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowUpperSubWindowLabel() const override;

    /**
     * Gets label of lower sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowLowerSubWindowLabel() const override;

    /**
     * Gets list box of upper sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowUpperSubWindowListBox() const override;

    /**
     * Gets list box of lower sub window of main left top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainLeftTopWindowLowerSubWindowListBox() const override;

    /**
     * Gets splitter window of main right window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightWindowSplitterWindow() const override;

    /**
     * Gets label of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowLabel() const override;

    /**
     * Gets label of main right bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightBottomWindowLabel() const override;

    /**
     * Gets splitter window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowSplitterWindow() const override;

    /**
     * Gets list view of main right bottom window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightBottomWindowListView() const override;

    /**
     * Gets label of upper sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowUpperSubWindowLabel() const override;

    /**
     * Gets label of lower sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowLowerSubWindowLabel() const override;

    /**
     * Gets canvas of upper sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowUpperSubWindowCanvas() const override;

    /**
     * Gets slider of lower sub window of main right top window of main frame.
     */
    virtual const std::wstring& GetMainFrameMainRightTopWindowLowerSubWindowSlider() const override;

    /**
     * Gets html window of rendering pipelines visualizer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialogHtmlWindow() const override;

    /**
     * Gets list view of event viewer dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerDialogListView() const override;

    /**
     * Gets list view of log statistics dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsDialogListView() const override;

    /**
     * Gets app log of log statistics dialog of view menu of top menu bar of main frame.
     */
    virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogDialogListView() const override;

private:
    static const std::wstring APP;
    static const std::wstring MAIN_FRAME;
    static const std::wstring MAIN_FRAME_FRAME;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_HELP_MENU;

    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_MENU_ITEM;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_EXIT_MENU_ITEM;
    
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_MENU_ITEM;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_MENU_ITEM;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_MENU_ITEM;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_MENU_ITEM;
    
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM;

    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_FOLDER_DIALOG;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPLINES_VISUALIZER_DIALOG;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_DIALOG;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_DIALOG;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_DIALOG;
            
    static const std::wstring MAIN_FRAME_MAIN_WINDOW_SPLITTER_WINDOW;
    static const std::wstring MAIN_FRAME_MAIN_LEFT_WINDOW_LABEL;
    static const std::wstring MAIN_FRAME_MAIN_RIGHT_WINDOW_LABEL;
    
    static const std::wstring MAIN_FRAME_MAIN_LEFT_WINDOW_SPLITTER_WINDOW;
    static const std::wstring MAIN_FRAME_MAIN_LEFT_TOP_WINDOW_LABEL;
    static const std::wstring MAIN_FRAME_MAIN_LEFT_BOTTOM_WINDOW_LABEL;
    
    static const std::wstring MAIN_FRAME_MAIN_LEFT_TOP_WINDOW_SPLITTER_WINDOW;
    static const std::wstring MAIN_FRAME_MAIN_LEFT_BOTTOM_WINDOW_STATIC_TEXT;

    static const std::wstring MAIN_FRAME_MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL;
    static const std::wstring MAIN_FRAME_MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL;
    static const std::wstring MAIN_FRAME_MAIN_LEFT_TOP_WINDOW_UPPER_SUB_WINDOW_LIST_BOX;
    static const std::wstring MAIN_FRAME_MAIN_LEFT_TOP_WINDOW_LOWER_SUB_WINDOW_LIST_BOX;

    static const std::wstring MAIN_FRAME_MAIN_RIGHT_WINDOW_SPLITTER_WINDOW;
    static const std::wstring MAIN_FRAME_MAIN_RIGHT_TOP_WINDOW_LABEL;
    static const std::wstring MAIN_FRAME_MAIN_RIGHT_BOTTOM_WINDOW_LABEL;

    static const std::wstring MAIN_FRAME_MAIN_RIGHT_TOP_WINDOW_SPLITTER_WINDOW;
    static const std::wstring MAIN_FRAME_MAIN_RIGHT_BOTTOM_WINDOW_LIST_VIEW;

    static const std::wstring MAIN_FRAME_MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_LABEL;
    static const std::wstring MAIN_FRAME_MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_LABEL;
    static const std::wstring MAIN_FRAME_MAIN_RIGHT_TOP_WINDOW_UPPER_SUB_WINDOW_CANVAS;
    static const std::wstring MAIN_FRAME_MAIN_RIGHT_TOP_WINDOW_LOWER_SUB_WINDOW_SLIDER;

    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_DIALOG_HTML_WINDOW;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_DIALOG_LIST_VIEW;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_DIALOG_LIST_VIEW;
    static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_DIALOG_LIST_VIEW;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
