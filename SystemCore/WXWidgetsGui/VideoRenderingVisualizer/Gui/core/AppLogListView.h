#pragma once

#include "ListView.h"
#include <filesystem>

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The AppLogListView class implements a list view of app log.
 */
class AppLogListView final : public WXWidgets::ListView {
public:
    /**
     * Creates an App Log List View.
     */
    static WXWidgets::IListViewPtr Make(
        wxWindow& parent, 
        const std::filesystem::path& logPath,
        IGuiManager& guiManager);

    /**
     * The AppLogListView constructor.
     */
    AppLogListView(
        wxWindow& parent, 
        const std::filesystem::path& logPath,
        IGuiManager& guiManager);

    /**
     * The AppLogListView destructor.
     */
    virtual ~AppLogListView();

private:
    /**
     * Initializes a GUI component.
     */
    void Initialize(IGuiManager& guiManager);

    /**
     * Gets list view information.
     */
    void GetListViewInformation(
        std::vector<std::wstring>& headers, 
        std::vector<std::vector<std::wstring>>& values) const;

    /**
     * Gets list view headers.
     */
    void GetListViewHeaders(std::vector<std::wstring>& headers) const;

    /**
     * Gets list view values.
     */
    void GetListViewValues(std::vector<std::vector<std::wstring>>& values) const;

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;

    //
    // The path of log...
    //
    std::filesystem::path m_logPath;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
