#include "ConsolePipe.h"
#include "AbstractRetryLogic.h"
#include "RetryHandler.h"
#include "ConsoleWindowsException.h"
#include <namedpipeapi.h>
#include <thread>
#include <assert.h>

using namespace console_windows;

const std::wstring ConsolePipe::PIPE_NAME_PREFIX = L"\\\\.\\pipe\\";

class RetryOpenFile final : public client_server::AbstractRetryLogic
{
public:
    RetryOpenFile(
        const std::wstring& pipeName,
        DWORD desiredAccess) :
        AbstractRetryLogic(L"RetryOpenFile"),
        m_pipeName(pipeName),
        m_desiredAccess(desiredAccess)
    {
    }

    virtual ~RetryOpenFile()
    {
    }

    /**
     * Runs the logic for opening a pipe.
     */
    virtual void Run() override {
        DWORD shareMode = 0;
        LPSECURITY_ATTRIBUTES securityAttributes = nullptr;
        DWORD creationDisposition = OPEN_EXISTING;
        DWORD flagsAndAttributes = 0;
        HANDLE templateFile = nullptr;

        for (int index = 0; index < 3; ++index) {
            HANDLE handle = ::CreateFileW(
                m_pipeName.c_str(),
                m_desiredAccess,
                shareMode,
                securityAttributes,
                creationDisposition,
                flagsAndAttributes,
                templateFile);

            if (handle == INVALID_HANDLE_VALUE) {
                long errorCode = GetLastError();

                if (errorCode != ERROR_PIPE_BUSY) {

                    std::wstringstream errorMessageStream;
                    errorMessageStream
                        << L"Console Pipe has failed opening named pipe: " << m_pipeName
                        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                    std::wstring errorMessage = errorMessageStream.str();
                    throw ConsoleWindowsException(errorCode, errorMessage);
                }

                long timeout = 1 * 1000;
                if (!WaitNamedPipeW(m_name.c_str(), timeout)) {
                    long errorCode = base::ErrorCodes::ACCESS_DENIED;

                    std::wstringstream errorMessageStream;
                    errorMessageStream
                        << L"Console Pipe has failed opening named pipe: " << m_pipeName
                        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                    std::wstring errorMessage = errorMessageStream.str();
                    throw ConsoleWindowsException(errorCode, errorMessage);
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
            }

            m_handle = handle;
            break;
        }
    }

    /**
     * Gets handle.
     */
    HANDLE GetHandle() const {
        return m_handle;
    }

private:
    std::wstring m_name;
    std::wstring m_pipeName;
    DWORD m_desiredAccess;
    HANDLE m_handle;
};

/**
 * Creates a ConsolePipe.
 */
IConsolePipeSharedPtr ConsolePipe::Create(
    const std::wstring& name,
    Mode mode,
    size_t readCapacity,
    size_t writeCapacity)
{
    std::wstring pipeName = CreatePipeName(name);
    DWORD openMode = CreatePipeMode(mode);
    DWORD pipeMode = PIPE_TYPE_MESSAGE | PIPE_READMODE_BYTE | PIPE_WAIT;
    DWORD maxNumOfInstances = 1;
    DWORD defaultTimeOut = 1;
    LPSECURITY_ATTRIBUTES securityAttributes = nullptr;

    HANDLE handle = ::CreateNamedPipeW(
        pipeName.c_str(),
        openMode,
        pipeMode,
        maxNumOfInstances,
        writeCapacity,
        readCapacity,
        defaultTimeOut,
        securityAttributes);

    if (handle == INVALID_HANDLE_VALUE) {
        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"The Console Pipe has failed creating named pipe: " << pipeName
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw ConsoleWindowsException(errorCode, errorMessage);
    }

    return std::make_shared<ConsolePipe>(
        name,
        handle,
        State::ServerDisconnected);
}

/**
 * Opens a Console Pipe.
 */
IConsolePipeSharedPtr ConsolePipe::Open(
    const std::wstring& name,
    Mode mode)
{
    std::wstring pipeName = CreatePipeName(name);
    DWORD desiredAccess = OpenPipeMode(mode);

    client_server::IRetryHandlerSharedPtr retryHandler = client_server::RetryHandler::MakeDefault();
    RetryOpenFile retryOpenFile(pipeName, desiredAccess);
    retryHandler->Retry(retryOpenFile);

    return std::make_shared<ConsolePipe>(
        name,
        retryOpenFile.GetHandle(),
        State::Client);
}

/**
 * The ConsolePipe constructor.
 */
ConsolePipe::ConsolePipe(
    const std::wstring& name,
    HANDLE handle,
    State state) :
    m_name(name),
    m_handle(std::make_unique<PipeHandle>(handle)),
    m_state(state)
{
}

/**
 * The ConsolePipe destructor.
 */
ConsolePipe::~ConsolePipe()
{
    ClosePipe();
}

/**
 * Gets name of pipe.
 */
const std::wstring& ConsolePipe::GetName() const
{
    return m_name;
}

/**
 * Reads data from pipe and returns the number of characters written to buffer.
 */
size_t ConsolePipe::Read(Buffer& buffer)
{
    assert(!buffer.empty());
    Connect();

    size_t characterSize = sizeof(std::wstring::value_type);
    DWORD numberOfBytesToRead = buffer.size() * characterSize;
    DWORD numberOfBytesRead = 0;
    LPOVERLAPPED pOverlapped = nullptr;

    if (!::ReadFile(
            m_handle->get(),
            &buffer[0],
            numberOfBytesToRead,
            &numberOfBytesRead,
            pOverlapped)) {

        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"The Console Pipe has failed reading from named pipe: " << m_name
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw ConsoleWindowsException(errorCode, errorMessage);
    }

    size_t numberOfCharactersWritten = numberOfBytesRead / characterSize;
    buffer.resize(numberOfCharactersWritten);
    return numberOfCharactersWritten;
}

/**
 * Writes data to pipe and returns number of characters written.
 */
size_t ConsolePipe::Write(const Buffer& buffer)
{
    if (buffer.empty()) {
        return 0;
    }

    Connect();

    size_t characterSize = sizeof(std::wstring::value_type);
    DWORD numberOfBytesToWrite = buffer.size() * characterSize;
    DWORD numberOfBytesWritten = 0;
    LPOVERLAPPED pOverlapped = nullptr;

    if (!::WriteFile(
            m_handle->get(),
            &buffer[0],
            numberOfBytesToWrite,
            &numberOfBytesWritten,
            pOverlapped)) {

        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
        << L"The Console Pipe has failed writing to named pipe: " << m_name
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw ConsoleWindowsException(errorCode, errorMessage);
    }

    size_t numberOfCharactersWritten = numberOfBytesWritten / characterSize;
    return numberOfCharactersWritten;
}

/**
 * Closes the pipe.
 */
void ConsolePipe::ClosePipe()
{
    if (m_handle) {
        Disconnect();
        m_handle.release();
    }
}

/**
 * Connects to pipe.
 */
bool ConsolePipe::Connect()
{
    if (m_state != State::ServerDisconnected) {
        return false;
    }

    LPOVERLAPPED lpOverlapped = nullptr;
    if (!::ConnectNamedPipe(m_handle->get(), lpOverlapped))
    {
        long errorCode = GetLastError();

        if (errorCode != ERROR_PIPE_CONNECTED) {
            m_handle.release();

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"Console Pipe has failed connecting to named pipe " << m_name
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw ConsoleWindowsException(errorCode, errorMessage);
        }
    }

    m_state = State::ServerConnected;
    return true;
}

/**
 * Disconnects from pipe.
 */
bool ConsolePipe::Disconnect()
{
    if (m_state != State::ServerConnected) {
        return false;
    }

    BOOL status = DisconnectNamedPipe(m_handle->get());

    m_state = State::ServerDisconnected;
    return true;
}

/**
 * Gets create pipe mode.
 */
DWORD ConsolePipe::CreatePipeMode(Mode mode)
{
    if (mode == Mode::Read) {
        return PIPE_ACCESS_INBOUND;
    }
    else if (mode == Mode::Write) {
        return PIPE_ACCESS_OUTBOUND;
    }
    else if (mode == Mode::Both) {
        return PIPE_ACCESS_DUPLEX;
    }
    else {
        long errorCode = base::ErrorCodes::INVALID_ARG;
        std::wstring errorMessage = L"The pipe mode is not supported.";

        throw ConsoleWindowsException(errorCode, errorMessage);
    }
}

/**
 * Gets open pipe mode.
 */
DWORD ConsolePipe::OpenPipeMode(Mode mode)
{
    if (mode == Mode::Read) {
        return GENERIC_READ;
    }
    else if (mode == Mode::Write) {
        return GENERIC_WRITE;
    }
    else if (mode == Mode::Both) {
        return GENERIC_READ | GENERIC_WRITE;
    }
    else {
        long errorCode = base::ErrorCodes::INVALID_ARG;
        std::wstring errorMessage = L"The pipe mode is not supported.";

        throw ConsoleWindowsException(errorCode, errorMessage);
    }
}

/**
 * Creates name of a pipe.
 */
std::wstring ConsolePipe::CreatePipeName(const std::wstring& name)
{
    return PIPE_NAME_PREFIX + name;
}
