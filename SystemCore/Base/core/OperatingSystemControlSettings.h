#ifndef OPERATING_SYSTEM_CONTROL_SETTINGS_H_647c2733_832d_4b6c_a755_40e209e1d5cd
#define OPERATING_SYSTEM_CONTROL_SETTINGS_H_647c2733_832d_4b6c_a755_40e209e1d5cd

#include "IOperatingSystemControlSettings.h"

namespace base {

    namespace environment {

        /**
         * The OperatingSystemControlSettings class implements a control settings of an operating system.
         */
        class OperatingSystemControlSettings final : public IOperatingSystemControlSettings {
        public:
            /**
             * The OperatingSystemControlSettings constructor.
             */
            explicit OperatingSystemControlSettings(const IOperatingSystemPathSettingsSharedPtr pathSettings);

            /**
             * The OperatingSystemControlSettings destructor.
             */
            virtual ~OperatingSystemControlSettings();

            /**
             * Gets paths settings.
             */
            virtual IOperatingSystemPathSettingsSharedPtr GetPathSettings() const override;

        private:
            IOperatingSystemPathSettingsSharedPtr m_pathSettings;
        };

    } // namespace environment

} // namespace base

#endif // namespace OPERATING_SYSTEM_CONTROL_SETTINGS_H_647c2733_832d_4b6c_a755_40e209e1d5cd
