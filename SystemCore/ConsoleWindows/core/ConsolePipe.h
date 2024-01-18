#ifndef I_CONSOLE_PIPE_H_6be5926f_61de_4b2a_8f28_6143581483ef
#define I_CONSOLE_PIPE_H_6be5926f_61de_4b2a_8f28_6143581483ef

#include "IConsolePipe.h"
#include <WinHandle.h>

namespace console_windows {

    /**
     * The ConsolePipe class implements a dedicated named pipe
     * for reading data for displaying in console.
     */
    class ConsolePipe final : public IConsolePipe {
    public:
        /**
         * Creates a Console Pipe.
         */
        static IConsolePipeSharedPtr Create(
            const std::wstring& name,
            Mode mode,
            size_t readCapacity,
            size_t writeCapacity);

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
            const std::wstring& name,
            HANDLE handle,
            State state);

        /**
         * The ConsolePipe destructor.
         */
        virtual ~ConsolePipe();

        /**
         * Gets name of pipe.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Reads data from pipe and returns the number of characters written to buffer.
         */
        virtual size_t Read(Buffer& buffer) override;

        /**
         * Writes data to pipe and returns number of characters written.
         */
        virtual size_t Write(const Buffer& buffer) override;

    private:
        static const std::wstring PIPE_NAME_PREFIX;

        /**
         * Closes the pipe.
         */
        void ClosePipe();

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

        //
        // The name of the pipe...
        //
        std::wstring m_name;

        //
        // The handle of the named pipe...
        //
        using PipeHandle = base::windows::WinHandle;
        using PipeHandleUniquePtr = base::windows::WinHandleUniquePtr;
        PipeHandleUniquePtr m_handle;

        //
        // The current state of the pipe...
        //
        State m_state;
    };

} // namespace console_windows

#endif // I_CONSOLE_PIPE_H_6be5926f_61de_4b2a_8f28_6143581483ef

