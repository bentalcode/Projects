#ifndef TEXT_CONTROL_db212461_cb0a_45b8_9eb8_15e72b235133
#define TEXT_CONTROL_db212461_cb0a_45b8_9eb8_15e72b235133

#include "ITextControl.h"
#include "Window.h"
#include "WXObjectId.h"
#include "wx/textctrl.h"

namespace wxwidgets {

    /**
     * The Text Control class implements a text control.
     */
    class TextControl : public ITextControl, public Window, public wxTextCtrl {
    public:
        /**
         * Creates a text control.
         */
        static ITextControlPtr Make(
            wxWindow& parent,
            const wxString& name,
            const wxString& value = wxEmptyString,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTE_READONLY,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The TextControl constructor.
         */
        TextControl(
            wxWindow& parent,
            const wxString& name,
            const wxString& value,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            long style,
            const wxValidator& validator);

        /**
         * The TextControl destructor.
         */
        virtual ~TextControl();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Sets a value.
         */
        virtual void SetValue(const wxString& value) override;

        /**
         * Updates data container (value).
         */
        static void UpdateDataContainerValue(
            DataContainerManagement::IDataContainer& data,
            const std::wstring& value);

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
        // The current value of text...
        //
        std::wstring m_value;
    };

} // namespace wxwidgets

#endif // TEXT_CONTROL_db212461_cb0a_45b8_9eb8_15e72b235133
