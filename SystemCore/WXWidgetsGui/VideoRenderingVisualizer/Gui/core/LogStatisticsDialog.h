#pragma once

#include "Dialog.h"
#include "IGuiManager.h"
#include "IListView.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The LogStatisticsDialog class implements a dialog of Log Statistics.
 */
class LogStatisticsDialog final : public WXWidgets::Dialog {
public:
    /**
     * Creates a Log Statistics Dialog.
     */
    static WXWidgets::IDialogPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The LogStatisticsDialog constructor.
     */
    LogStatisticsDialog(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The LogStatisticsDialog destructor.
     */
    virtual ~LogStatisticsDialog();

private:
    /**
     * Initializes a GUI component.
     */
    void Initialize(IGuiManager& guiManager);

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;

    //
    // The list view of logs statistics...
    //
    WXWidgets::IListViewPtr m_logStatisticsListView;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
