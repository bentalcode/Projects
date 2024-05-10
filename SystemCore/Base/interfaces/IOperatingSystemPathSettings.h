#ifndef I_OPERATING_SYSTEM_PATH_SETTINGS_H_35059260_4fa3_417a_90ee_0c4346f0d278
#define I_OPERATING_SYSTEM_PATH_SETTINGS_H_35059260_4fa3_417a_90ee_0c4346f0d278

#include "IPath.h"
#include "IPathBuilder.h"

namespace base {

    namespace environment {

        /**
         * The IOperatingSystemPathSettings interface defines settings of paths of an operating system.
         */
        class IOperatingSystemPathSettings {
        public:
            /**
            * The IOperatingSystemPathSettings constructor.
            */
            IOperatingSystemPathSettings() = default;

            /**
             * The IOperatingSystemPathSettings destructor.
             */
            virtual ~IOperatingSystemPathSettings() = default;

            /**
             * Gets a path separator.
             */
            virtual std::wstring GetPathSeparator() const = 0;

            /**
             * Creates a path.
             */
            virtual IPathSharedPtr CreatePath(const std::wstring& path) const = 0;

            /**
             * Creates a path builder.
             */
            virtual IPathBuilderSharedPtr CreatePathBuilder() const = 0;
        };

        /**
         * Defines the Shared Ptr of Operating System Path Settings.
         */
        using IOperatingSystemPathSettingsSharedPtr = std::shared_ptr<IOperatingSystemPathSettings>;

    } // namespace environment

} // namespace base

#endif // I_OPERATING_SYSTEM_PATH_SETTINGS_H_35059260_4fa3_417a_90ee_0c4346f0d278
