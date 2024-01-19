#include "NamedPipes.h"
#include "ConsoleWindowsException.h"

using namespace console_windows;

/**
 * Creates a pipe.
 */
HANDLE NamedPipes::CreatePipe(
    const std::wstring& pipeName,
    DWORD openMode,
    DWORD pipeMode,
    size_t readCapacity,
    size_t writeCapacity)
{
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

    return handle;
}

/**
 * Opens a pipe.
 */
HANDLE NamedPipes::OpenPipe(
    const std::wstring& pipeName,
    DWORD desiredAccess,
    unsigned int numOfAttempts,
    long retryDurationInMilliseconds)
{
    DWORD shareMode = 0;
    LPSECURITY_ATTRIBUTES securityAttributes = nullptr;
    DWORD creationDisposition = OPEN_EXISTING;
    DWORD flagsAndAttributes = 0;
    HANDLE templateFile = nullptr;

    long errorCode = 0;

    for (unsigned int index = 0; index < numOfAttempts; ++index) {
        HANDLE handle = ::CreateFileW(
            pipeName.c_str(),
            desiredAccess,
            shareMode,
            securityAttributes,
            creationDisposition,
            flagsAndAttributes,
            templateFile);

        if (handle == INVALID_HANDLE_VALUE) {
            errorCode = GetLastError();

            if (errorCode != ERROR_PIPE_BUSY) {

                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"Console Pipe has failed opening named pipe: " << pipeName
                    << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();
                throw ConsoleWindowsException(errorCode, errorMessage);
            }

            if (!WaitNamedPipeW(pipeName.c_str(), retryDurationInMilliseconds)) {
                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"Console Pipe has failed opening named pipe or wait to it when being busy: " << pipeName
                    << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();
                throw ConsoleWindowsException(errorCode, errorMessage);
            }
        }

        return handle;
    }

    std::wstringstream errorMessageStream;
    errorMessageStream
        << L"Console Pipe has failed opening named pipe: " << pipeName
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();
    throw ConsoleWindowsException(errorCode, errorMessage);
}

/**
 * Connects to pipe.
 */
void NamedPipes::ConnectPipe(
    const std::wstring& pipeName,
    HANDLE handle)
{
    LPOVERLAPPED lpOverlapped = nullptr;

    if (!::ConnectNamedPipe(handle, lpOverlapped))
    {
        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
            errorMessageStream
                << L"Console Pipe has failed connecting to named pipe: " << pipeName
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw ConsoleWindowsException(errorCode, errorMessage);
    }
}

/**
 * Disconnects from pipe.
 */
bool NamedPipes::DisconnectPipe(
    const std::wstring& pipeName,
    HANDLE handle)
{
    BOOL status = DisconnectNamedPipe(handle);
    return status == TRUE;
}
