#ifndef HTML_WINDOW_83651732_4817_4b03_b77a_b722c9f8b489
#define HTML_WINDOW_83651732_4817_4b03_b77a_b722c9f8b489

#include "IHtmlWindow.h"
#include "Window.h"
#include "WXObjectId.h"
#include <wx/html/htmlwin.h>

namespace wxwidgets {

    /**
     * The HTML Window class implements a HTML window.
     */
    class HtmlWindow : public IHtmlWindow, public Window, public wxHtmlWindow {
    public:
        /**
         * Creates a HTML window.
         */
        static WXObjectPtr<IHtmlWindow> Make(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxHW_DEFAULT_STYLE);

        /**
         * The HtmlWindow constructor.
         */
        HtmlWindow(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxHW_NO_SELECTION);

        /**
         * The HtmlWindow destructor.
         */
        virtual ~HtmlWindow();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Loads file.
         */
        virtual void LoadFile(const std::wstring& path) override;

        /**
         * Updates data container (content).
         */
        static void UpdateDataContainerContent(
            DataContainerManagement::IDataContainer& data,
            const std::wstring& content);

    protected:
        /**
         * Updates data from data container.
         * Returns true in case data has been updated.
         */
        virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

        /**
         * Updates component.
         */
        virtual void Update() override;

    private:
        //
        // The current content...
        //
        std::wstring m_content;
    };

} // namespace wxwidgets

#endif // HTML_WINDOW_83651732_4817_4b03_b77a_b722c9f8b489
