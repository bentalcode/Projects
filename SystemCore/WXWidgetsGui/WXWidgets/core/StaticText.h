#ifndef STATIC_TEXT_79498382_4ffd_4dbb_a25b_56c7972ae2c3
#define STATIC_TEXT_79498382_4ffd_4dbb_a25b_56c7972ae2c3

#include "IStaticText.h"
#include "Window.h"
#include "WXObjectId.h"
#include <wx/stattext.h>

namespace WXWidgets {

    /**
     * The Static Text class implements a static text.
     */
    class StaticText : public IStaticText, public Window, public wxStaticText {
    public:
        /**
         * Creates a static text.
         */
        static WXObjectPtr<IStaticText> Make(
            wxWindow& parent,
            const wxString& name,
            const wxString& label = wxEmptyString,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTE_MULTILINE);

        /**
         * The StaticText constructor.
         */
        StaticText(
            wxWindow& parent,
            const wxString& name,
            const wxString& label = wxEmptyString,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTE_MULTILINE);

        /**
         * The StaticText destructor.
         */
        virtual ~StaticText();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Sets text.
         */
        virtual void SetText(const std::wstring& text) override;

        /**
         * Updates data container (text).
         */
        static void UpdateDataContainerText(
            DataContainerManagement::IDataContainer& data,
            const std::wstring& text);

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
        // The current text...
        //
        std::wstring m_text;
    };

} // namespace WXWidgets

#endif // STATIC_TEXT_79498382_4ffd_4dbb_a25b_56c7972ae2c3
