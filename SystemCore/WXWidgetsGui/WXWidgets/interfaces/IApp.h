#ifndef I_APP_H_3d61a005_9f2e_40a1_8711_9a9dfa90037e
#define I_APP_H_3d61a005_9f2e_40a1_8711_9a9dfa90037e

#include "IGuiController.h"
#include "WXObjectPtr.h"

class wxAppConsole;

namespace WXWidgets {

    /**
     * The IApp interface defines an app.
     */
    class IApp {
    public:
        IApp() = default;
        virtual ~IApp() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const std::wstring& name,
            IGuiControllerSharedPtr guiController) = 0;

        /**
         * The on app initialization logic.
         */
        virtual void OnAppInitialization() = 0;

        /**
         * The on app exit logic.
         */
        virtual void OnAppExit() = 0;

        /**
         * Gets an app console.
         */
        virtual wxAppConsole& GetAppConsole() = 0;
    };

    //
    // Defines the WX Object Ptr of App.
    //
    using IAppPtr = WXObjectPtr<IApp>;

}  // namespace WXWidgets

#endif // I_APP_H_3d61a005_9f2e_40a1_8711_9a9dfa90037e
