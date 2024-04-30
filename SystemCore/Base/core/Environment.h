#ifndef ENVIRONMENT_H_b8d01526_0aab_49e2_9163_8b6d52bef053
#define ENVIRONMENT_H_b8d01526_0aab_49e2_9163_8b6d52bef053

#include "OperatingSystemType.h"

namespace base {

    namespace environment {

        /**
         * The Environment class implements complementary APIs for current environment.
         */
        class Environment final
        {
        public:
            /**
             * Checks whether the current operating system is windows.
             */
            static bool IsWindows();

            /**
             * Gets the current type of the operating system.
             */
            static base::environment::OperatingSystemType GetOperatingSystem();

        private:
            Environment() = delete;
            ~Environment() = delete;
        };

    } // namespace environment

} // namespace base

#endif // ENVIRONMENT_H_b8d01526_0aab_49e2_9163_8b6d52bef053
