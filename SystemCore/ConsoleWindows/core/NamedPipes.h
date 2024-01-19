#ifndef NAMED_PIPES_H_15bd1cd3_3c33_45ae_bebf_dc29f60135f5
#define NAMED_PIPES_H_15bd1cd3_3c33_45ae_bebf_dc29f60135f5

#include <string>
#include <windows.h>

namespace console_windows {

    /**
     * The NamedPipes class implements utilities of named pipes.
     */
    class NamedPipes final {
    public:
        /**
         * Creates a pipe.
         */
        static HANDLE CreatePipe(
            const std::wstring& pipeName,
            DWORD openMode,
            DWORD pipeMode,
            size_t readCapacity,
            size_t writeCapacity);

        /**
         * Opens a pipe.
         */
        static HANDLE OpenPipe(
            const std::wstring& pipeName,
            DWORD desiredAccess,
            unsigned int numOfAttempts,
            long retryDurationInMilliseconds);

        /**
         * Connects to pipe.
         */
        static void ConnectPipe(
            const std::wstring& pipeName,
            HANDLE handle);

        /**
         * Disconnects from pipe.
         */
        static bool DisconnectPipe(
            const std::wstring& pipeName,
            HANDLE handle);

    };

} // namespace console_windows

#endif // NAMED_PIPES_H_15bd1cd3_3c33_45ae_bebf_dc29f60135f5

