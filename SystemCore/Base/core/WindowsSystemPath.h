#ifndef WINDOWS_SYSTEM_PATH_TYPE_H_94f3b77c_db93_4741_b93e_89a82e902f58
#define WINDOWS_SYSTEM_PATH_TYPE_H_94f3b77c_db93_4741_b93e_89a82e902f58

#include "WindowsSystemPath.h"
#include <vector>
#include <string>
#include <memory>
#include "WindowsSystemPathType.h"

namespace base {

    namespace environment {

     namespace windows {

            /**
             * The WindowsSystemPath class implements a windows system path.
             */
            class WindowsSystemPath final {
            public:
                /**
                 * The WindowsSystemPath constructor.
                 */
                explicit WindowsSystemPath();

                /**
                 * The WindowsSystemPath destructor.
                 */
                virtual ~WindowsSystemPath();

                /**
                 * Gets type of a path.
                 */
                static WindowsSystemPathType GetPathType(const std::wstring& path);

                /**
                 * Checks whether a path is a device path.
                 */
                static bool IsDevicePath(const std::wstring& path);

                /**
                 * Checks whether a path is a UNC path.
                 */
                static bool IsUncPath(const std::wstring& path);

                /**
                 * Checks whether a path is a DOS path.
                 */
                static bool IsDosPath(const std::wstring& path);

                /**
                 * Checks whether a path is a legacy device path.
                 */
                static bool IsLegacyDevicePath(const std::wstring& path);

                /**
                 * Checks whether a path is a Relative to Root of Current Drive path.
                 */
                static bool IsRelativeToRootOfCurrentDrivePath(const std::wstring& path);

                /**
                 * Checks whether a path is a Relative to Current Directory of Specified Drive path.
                 */
                static bool IsRelativeToCurrentDirectoryOfSpecifiedDrivePath(const std::wstring& path);

                /**
                 * Checks whether a path is a Relative to Current Directory.
                 */
                static bool IsRelativeToCurrentDirectory(const std::wstring& path);

                /**
                 * Checks whether a path is valid.
                 */
                static bool IsPathValid(const std::wstring& path);

            private:
                static const std::vector<std::wstring> DEVICE_PATH_PREFIXES1;
                static const std::vector<std::wstring> DEVICE_PATH_PREFIXES2;
                static const std::wstring UNC_PATH_PREFIX;
                static const std::wstring DOS_ROOT_NAME_POSTFIX;
                static const std::wstring LEGACY_DEVICE_PATH_PREFIX;
                static const std::wstring RELATIVE_TO_ROOT_OF_CURRENT_DRIVE_PREFIX;
                static const std::wstring RELATIVE_TO_CURRENT_DIRECTORY_OF_SPECIFIED_DRIVE_POSTFIX;

                /**
                 * Validates path.
                 */
                static void ValidatePath(const std::wstring& path);

                /**
                 * Formats a path.
                 */
                static std::wstring FormatPath(const std::wstring& path);

                /**
                 * Checks whether a path is a device path.
                 */
                static bool InternalIsDevicePath(const std::wstring& path);

                /**
                 * Checks whether a path is a device1 path.
                 */
                static bool InternalIsDevice1Path(const std::wstring& path);

                /**
                 * Checks whether a path is a device2 path.
                 */
                static bool InternalIsDevice2Path(const std::wstring& path);

                /**
                 * Checks whether a path is a UNC path.
                 */
                static bool InternalIsUncPath(const std::wstring& path);

                /**
                 * Checks whether a path is a DOS path.
                 */
                static bool InternalIsDosPath(const std::wstring& path);

                /**
                 * Checks whether a path is a legacy device path.
                 */
                static bool InternalIsLegacyDevicePath(const std::wstring& path);

                /**
                 * Checks whether a path is a Relative to Root of Current Drive path.
                 */
                static bool InternalIsRelativeToRootOfCurrentDrivePath(const std::wstring& path);

                /**
                 * Checks whether a path is a Relative to Current Directory of Specified Drive path.
                 */
                static bool InternalIsRelativeToCurrentDirectoryOfSpecifiedDrivePath(const std::wstring& path);

                /**
                 * Checks whether a path is mataching to specified properties.
                 */
                static bool IsPathMatch(
                    const std::wstring& path,
                    const std::vector<std::wstring>& prefixes);

                /**
                 * Gets Device path prefixes.
                 */
                static void GetDevicePathPrefixes1(std::vector<std::wstring>& prefixes);
                static void GetDevicePathPrefixes2(std::vector<std::wstring>& prefixes);

                /**
                 * Gets UNC path prefixes.
                 */
                static void GetUncPathPrefixes(std::vector<std::wstring>& prefixes);

                 /**
                  * Gets DOS path prefixes.
                  */
                 static void GetDosPathPrefixes(std::vector<std::wstring>& prefixes);

                 /**
                  * Gets Legacy Device path prefixes.
                  */
                 static void GetLegacyDevicePathPrefixes(std::vector<std::wstring>& prefixes);

                 /**
                  * Gets Relative to Root of Current Drive path prefixes.
                  */
                 static void GetRelativeToRootOfCurrentDrivePathPrefixes(std::vector<std::wstring>& prefixes);

                 /**
                  * Gets relative to Current Directory of a Specified Drive path prefixes.
                  */
                 static void GetRelativeToCurrentDirectoryOfSpecifiedDrivePathPrefixes(std::vector<std::wstring>& prefixes);

                 /**
                  * Gets root names.
                  */
                 using RootNames = std::vector<std::wstring::value_type>;
                 using RootNamesSharedPtr = std::shared_ptr<RootNames>;
                 static RootNamesSharedPtr GetRootNames();

                 /**
                  * Creates root names.
                  */
                 static RootNamesSharedPtr CreateRootNames();
            };

        } // namespace windows

    } // namespace environment

} // namespace base

#endif // namespace WINDOWS_SYSTEM_PATH_TYPE_H_94f3b77c_db93_4741_b93e_89a82e902f58
