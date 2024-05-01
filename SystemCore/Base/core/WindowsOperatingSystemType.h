#ifndef OperatingSystemType_H_ea3d79a4_110f_4ab4_ac27_649f43cb32ef
#define OperatingSystemType_H_ea3d79a4_110f_4ab4_ac27_649f43cb32ef

#include "IOperatingSystemType.h"

namespace base {

    namespace environment {

        namespace windows {

            /**
             * The WindowsOperatingSystemType class implements an Operating System Type.
             */
            class WindowsOperatingSystemType final : public IOperatingSystemType {
            public:
                WindowsOperatingSystemType();
                virtual ~WindowsOperatingSystemType();

                /**
                 * Checks whether this is an operating system based on the system value.
                 */
                virtual bool IsOperatingSystem(const std::wstring& value) const override;
            };

        } // namespace windows

    } // namespace environment

} // namespace base

#endif // namespace OperatingSystemType_H_ea3d79a4_110f_4ab4_ac27_649f43cb32ef
