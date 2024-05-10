#ifndef I_APP_COFIGURATION_ITEMS_H_657051f9_023a_451b_b564_cbca692f1f81
#define I_APP_COFIGURATION_ITEMS_H_657051f9_023a_451b_b564_cbca692f1f81

#include "IConfigurationItems.h"

#include <string>

namespace VideoRenderingVisualizer {
    
    namespace Gui {

        /**
         * The IAppConfigurationItems interface defines configuration items of app.
         */
        class IAppConfigurationItems : public GuiConfiguration::IConfigurationItems {
        public:
            IAppConfigurationItems() = default;
            virtual ~IAppConfigurationItems() = default;

            /**
             * Gets name of a app.
             */
            virtual const std::wstring& GetAppName() const = 0;

            /**
             * Gets log path.
             */
            virtual const std::wstring& GetLogPath() const = 0;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_APP_COFIGURATION_ITEMS_H_657051f9_023a_451b_b564_cbca692f1f81
