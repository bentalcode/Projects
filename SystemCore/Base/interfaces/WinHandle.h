#ifndef WINDOWS_HANDLE_H_be4ac0b3_c800_4a0e_a434_1a8b3c366a72
#define WINDOWS_HANDLE_H_be4ac0b3_c800_4a0e_a434_1a8b3c366a72

#include "Handle.h"
#include <windows.h>

namespace base {

    namespace windows {

        /**
         * The Handle Releaser releases a windows handle.
         */
        class HandleReleaser final {
        public:
            /**
             * Releases the handle.
             */
            static void Release(HANDLE handle)
            {
                ::CloseHandle(handle);
            }
        };

        using WinHandle = Handle<HANDLE, HandleReleaser>;

    }  // namespace windows

}  // namespace base

#endif // WINDOWS_HANDLE_H_be4ac0b3_c800_4a0e_a434_1a8b3c366a72
