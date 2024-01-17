#pragma once

#include "IConsolePipe.h"
#include <Windows.h>
#include <vector>
#include <string>
#include <WinHandle.h>

namespace console_windows {

    /**
     * The ConsolePipe class implements a dedicated named pipe
     * for reading data for displaying in console.
     */
    class ConsolePipe final : public IConsolePipe {
    public:
        /**
         * Defines the states of pipe.
         */
        enum class State
        {
            Client,
            ServerConnected,
            ServerDisconnected
        };

        /**
         * Defines the mode of accessing console pipe.
         */
        enum class Mode
        {
            Read,
            Write,
            Both
        };

        /**
         * Defines the buffer for reading/writing from/to console pipe.
         */
        using Buffer = std::vector<BYTE>;

        /**
         * Creates a Console Pipe.
         */
        static IConsolePipeSharedPtr Create(
            const std::wstring& name,
            Mode mode,
            size_t writeCapacity,
            size_t readCapacity);

        /**
         * Opens a Console Pipe.
         */
        static IConsolePipeSharedPtr Open(
            const std::wstring& name,
            Mode mode);

        /**
         * The ConsolePipe constructor.
         */
        ConsolePipe(
            HANDLE handle,
            const std::wstring& name,
            State state);

        /**
         * The ConsolePipe destructor.
         */
        virtual ~ConsolePipe();

        /**
         * Reads data from pipe and returns the number of bytes written to buffer.
         */
        size_t Read(Buffer& buffer);

        /**
         * Writes data to pipe and returns number of bytes written.
         */
        size_t Write(const Buffer& buffer);

    private:
        static const std::wstring PIPE_NAME_PREFIX;

        /**
         * Connects to pipe.
         */
        bool Connect();

        /**
         * Disconnects from pipe.
         */
        bool Disconnect();

        /**
         * Gets create pipe mode.
         */
        static DWORD CreatePipeMode(Mode mode);

        /**
         * Gets open pipe mode.
         */
        static DWORD OpenPipeMode(Mode mode);

        /**
         * Creates name of a pipe.
         */
        static std::wstring CreatePipeName(const std::wstring& name);

        using PipeHandle = base::windows::WinHandle;
        using PipeHandleUniquePtr = base::windows::WinHandleUniquePtr;
        PipeHandleUniquePtr m_handle;
        std::wstring m_name;
        State m_state;
        size_t m_readCapacity;
        size_t m_writeCapacity;
        size_t m_numOfAttempts;
    };

} // namespace console_windows
