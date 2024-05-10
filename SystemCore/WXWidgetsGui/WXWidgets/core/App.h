#ifndef APP_440859ed_071f_410a_a14d_15257e71e8c5
#define APP_440859ed_071f_410a_a14d_15257e71e8c5

#include "AbstractApp.h"

namespace wxwidgets {

    /**
     * The App class implements an app.
     */
    class App : public AbstractApp {
    public:
        /**
         * The App constructor.
         */
        App();

        /**
         * The App destructor.
         */
        virtual ~App();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const std::wstring& name,
            IGuiControllerSharedPtr guiController) override;
    };

} // namespace wxwidgets

#endif // APP_440859ed_071f_410a_a14d_15257e71e8c5
