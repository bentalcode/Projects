#ifndef ABSTRACT_APP_1b202bb1_3962_47a3_89ff_9cb575a9404b
#define ABSTRACT_APP_1b202bb1_3962_47a3_89ff_9cb575a9404b

#include "IApp.h"
#include "GuiComponent.h"
#include "wx/app.h"

namespace WXWidgets {

    /**
     * The AbstractApp class implements an abstract base class of an app.
     */
    class AbstractApp : public IApp, public GuiComponent, public wxApp {
    public:
        /**
         * The AbstractApp constructor.
         */
        AbstractApp();

        /**
         * The AbstractApp destructor.
         */
        virtual ~AbstractApp();

        /**
         * Initializes a GUI component.
         */
        void Initialize(
            const std::wstring&
            name, IGuiControllerSharedPtr guiController);

        /**
         * The on app exit logic - Default Implemention.
         */
        virtual void OnAppExit() override;

        /**
         * Gets an app console.
         */
        virtual wxAppConsole& GetAppConsole() override;

        /**
         * The On Trigger Start Refreshing callback.
         */
        virtual void OnTriggerStartRefreshing() override;

    protected:
        /**
         * The internal on init callback.
         */
        virtual bool OnInit() override;

        /**
         * The internal on exit callback.
         */
        virtual int OnExit() override;
    };

}  // namespace WXWidgets

#endif // ABSTRACT_APP_1b202bb1_3962_47a3_89ff_9cb575a9404b
