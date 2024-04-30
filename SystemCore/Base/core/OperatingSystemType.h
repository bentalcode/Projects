#ifndef OPERATING_SYSTEM_TYPE_H_4020f0a8_26ec_4c90_8a73_4cde561011b5
#define OPERATING_SYSTEM_TYPE_H_4020f0a8_26ec_4c90_8a73_4cde561011b5

namespace base {

    namespace environment {

        /**
         * The OperatingSystemType defines types of supported operating systems.
         */
        enum class OperatingSystemType {
            OPERATING_SYSTEM_WINDOWS,
            OPERATING_SYSTEM_UNIX,
            OPERATING_SYSTEM_MAC,
            OPERATING_SYSTEM_POSIX_UNIX
        };

    }

} // namespace base

#endif // namespace OPERATING_SYSTEM_TYPE_H_4020f0a8_26ec_4c90_8a73_4cde561011b5
