#ifndef MAIN_LEFT_BOTTOM_WINDOW_H_f36ad632_c80e_4e4f_852c_3277b6bb0165
#define MAIN_LEFT_BOTTOM_WINDOW_H_f36ad632_c80e_4e4f_852c_3277b6bb0165

#include "AbstractGuiWindow.h"
#include "IStaticText.h"

class wxWindow;

namespace VideoRenderingVisualizer { 

    namespace Gui {

        /**
         * The MainLeftBottomWindow class implements a gui of Main Left Bottom Window.
         */
        class MainLeftBottomWindow final : public AbstractGuiWindow {
        public:
            /**
             * Creates a Main Left Bottom Window.
             */
            static IGuiWindowSharedPtr Make(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainLeftBottomWindow constructor.
             */
            MainLeftBottomWindow(
                wxWindow& parent,
                IGuiManager& guiManager);

            /**
             * The MainLeftBottomWindow destructor.
             */
            virtual ~MainLeftBottomWindow();

            /**
             * Gets a window.
             */
            virtual wxwidgets::IWindow& GetWindow() override;

        private:
            /**
             * Initializes a window.
             */
            void Initialize(wxWindow& parent);

            wxwidgets::IStaticTextPtr m_staticText;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_LEFT_BOTTOM_WINDOW_H_f36ad632_c80e_4e4f_852c_3277b6bb0165
