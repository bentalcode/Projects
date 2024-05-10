#ifndef ABSTRACT_GUI_WINDOW_H_58563775_161d_46fe_a883_db552e24c07c
#define ABSTRACT_GUI_WINDOW_H_58563775_161d_46fe_a883_db552e24c07c

#include "IGuiWindow.h"
#include "ILoggers.h"

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        class IGuiManager;

        /**
         * The AbstractGuiWindow class implements an abstract GUI Window.
         */
        class AbstractGuiWindow : public IGuiWindow {
        protected:
            /**
             * The AbstractGuiWindow constructor.
             */
            AbstractGuiWindow(
                const std::wstring& name,
                IGuiManager& guiManager);

        public:
            /**
             * The AbstractGuiWindow destructor.
             */
            virtual ~AbstractGuiWindow();

        protected:
            /**
             * Gets GUI manager.
             */
            IGuiManager& GetGuiManager();

            /**
             * Gets logger of GUI component.
             */
            logging::ILoggerSharedPtr GetLogger();

        private:
            //
            // The name of the window...
            //
            std::wstring m_name;

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;

            //
            // The loggers of the window...
            //
            logging::ILoggersSharedPtr m_loggers;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // ABSTRACT_GUI_WINDOW_H_58563775_161d_46fe_a883_db552e24c07c
