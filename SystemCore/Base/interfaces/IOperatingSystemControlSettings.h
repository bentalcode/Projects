#ifndef I_OPERATING_SYSTEM_CONTROL_SETTINGS_H_424ac884_4e82_47ba_82fb_5e51a24ff680
#define I_OPERATING_SYSTEM_CONTROL_SETTINGS_H_424ac884_4e82_47ba_82fb_5e51a24ff680

#include "IOperatingSystemPathSettings.h"

namespace base {

    namespace environment {

        /**
         * The IOperatingSystemControlSettings interface defines a control settings of an operating system.
         */
        class IOperatingSystemControlSettings {
        public:
            /**
             * The IOperatingSystemControlSettings constructor.
             */
            IOperatingSystemControlSettings() = default;

            /**
             * The IOperatingSystemControlSettings destructor.
             */
            virtual ~IOperatingSystemControlSettings() = default;

            /**
             * Gets paths settings.
             */
            virtual IOperatingSystemPathSettingsSharedPtr GetPathSettings() const = 0;
        };

        /**
         * Defines the Shared Ptr of Operating System Control Settings.
         */
        using IOperatingSystemControlSettingsSharedPtr = std::shared_ptr<IOperatingSystemControlSettings>;

    }

} // namespace base

#endif // I_OPERATING_SYSTEM_CONTROL_SETTINGS_H_424ac884_4e82_47ba_82fb_5e51a24ff680
