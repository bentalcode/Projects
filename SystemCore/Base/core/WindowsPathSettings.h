#ifndef WINDOWS_PATH_SETTINGS_H_4043691b_122f_48cf_9fc4_cdb62a4c22a6
#define WINDOWS_PATH_SETTINGS_H_4043691b_122f_48cf_9fc4_cdb62a4c22a6

#include "IOperatingSystemPathSettings.h"

namespace base {

    namespace environment {

        /**
         * The WindowsPathSettings class implements path settings of a windows operating system.
         */
        class WindowsPathSettings final : public IOperatingSystemPathSettings {
        public:
            /**
             * The WindowsPathSettings constructor.
             */
            WindowsPathSettings();

            /**
             * The WindowsPathSettings destructor.
             */
            virtual ~WindowsPathSettings();

            /**
             * Creates a path separator.
             */
            virtual std::wstring GetPathSeparator() const override;

            /**
             * Creates a path.
             */
            virtual IPathSharedPtr CreatePath(const std::wstring& path) const override;

            /**
             * Creates a path builder.
             */
            virtual IPathBuilderSharedPtr CreatePathBuilder() const override;
        };

    } // namespace environment

} // namespace base

#endif // namespace WINDOWS_PATH_SETTINGS_H_4043691b_122f_48cf_9fc4_cdb62a4c22a6
