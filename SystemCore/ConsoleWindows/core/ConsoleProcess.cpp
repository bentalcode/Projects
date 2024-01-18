#include "ConsoleProcess.h"
#include "ErrorMessages.h"
#include "StringUtils.h"
#include "ConsoleWindowsException.h"

using namespace console_windows;

/**
 * Creates a Console Process.
 */
IConsoleProcessSharedPtr ConsoleProcess::Make(
    const std::wstring& executablePath,
    const std::wstring& commandArgs)
{
    return std::make_shared<ConsoleProcess>(
        executablePath,
        commandArgs);
}

/**
 * The ConsoleProcess constructor.
 */
ConsoleProcess::ConsoleProcess(
    const std::wstring& executablePath,
    const std::wstring& commandArgs)
{
    ::SecureZeroMemory(
        &m_processInformation,
        sizeof(m_processInformation));

    CreateProcess(
        executablePath,
        commandArgs,
        m_processInformation);
}

/**
 * The ConsoleProcess destructor.
 */
ConsoleProcess::~ConsoleProcess()
{
    Terminate();
}

/**
 * Terminates the running process.
 */
void ConsoleProcess::Terminate(int exitCode)
{
    TerminateProcess(m_processInformation, exitCode);
}

/**
 * Creates a process.
 */
void ConsoleProcess::CreateProcess(
    const std::wstring& executablePath,
    const std::wstring& commandArgs,
    PROCESS_INFORMATION& processInformation)
{
    STARTUPINFOW information;
    ::GetStartupInfoW(&information);

    size_t bufferSize = MAX_PATH;
    std::vector<std::wstring::value_type> commandLine(bufferSize, L'\0');

    base::StringUtils::CopyString(
        commandArgs.c_str(),
        commandArgs.size(),
        &commandLine[0],
        bufferSize);

    LPSECURITY_ATTRIBUTES pProcessAttributes = nullptr;
    LPSECURITY_ATTRIBUTES pThreadAttributes = nullptr;
    BOOL inheritHandles = FALSE;
    DWORD creationFlags = CREATE_NEW_CONSOLE;
    LPVOID pEnvironment = nullptr;
    LPCWSTR currentDirectory = nullptr;

    if (!CreateProcessW(
            nullptr,
            &commandLine[0],
            pProcessAttributes,
            pThreadAttributes,
            inheritHandles,
            creationFlags,
            pEnvironment,
            currentDirectory,
            &information,
            reinterpret_cast<LPPROCESS_INFORMATION>(&processInformation))) {

        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"The Console Process has failed creating process: " << executablePath
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw ConsoleWindowsException(
            errorCode,
            errorMessage);
    }
}

/**
 * Terminates a process.
 */
void ConsoleProcess::TerminateProcess(
    PROCESS_INFORMATION& processInformation,
    int exitCode)
{
    HANDLE hThread = processInformation.hThread;
    HANDLE hProcess = processInformation.hProcess;

    if (hThread != INVALID_HANDLE_VALUE)
    {
        ::TerminateThread(hThread, exitCode);
        ::CloseHandle(hThread);
        processInformation.hThread = INVALID_HANDLE_VALUE;
    }

    if (hProcess != INVALID_HANDLE_VALUE) {
        ::TerminateProcess(hProcess, exitCode);
        ::CloseHandle(hProcess);
        processInformation.hProcess = INVALID_HANDLE_VALUE;
    }
}
