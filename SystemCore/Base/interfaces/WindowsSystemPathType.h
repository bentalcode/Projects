#ifndef WINDOWS_SYSTEM_PATH_TYPE_H_8db0b37d_d57a_4db7_8059_aac49f44d1ab
#define WINDOWS_SYSTEM_PATH_TYPE_H_8db0b37d_d57a_4db7_8059_aac49f44d1ab

namespace base {

    namespace environment {

        namespace windows {

            /**
             * The WindowsSystemPathType defines types of supported system paths in Windows.
             */
            enum class WindowsSystemPathType {
                DEVICE_PATH,
                UNC_PATH,
                DOS_PATH,
                LEGACY_DEVICE_PATH,
                RELATIVE_TO_ROOT_CURRENT_DRIVE,
                RELATIVE_TO_CURRENT_DIRECTORY_OF_SPECIFIED_DRIVE,
                RELATIVE_TO_CURRENT_DIRECTORY
            };

        } // namespace windows

    } // namespace environment

} // namespace base

#endif // namespace WINDOWS_SYSTEM_PATH_TYPE_H_8db0b37d_d57a_4db7_8059_aac49f44d1ab
