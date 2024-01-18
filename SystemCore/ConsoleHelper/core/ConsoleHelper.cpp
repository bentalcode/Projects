#include "ConsoleHelper.h"
#include "ConsoleHelperParameters.h"
#include "ConsolePipe.h"
#include "ErrorMessages.h"
#include "ConsoleHelperException.h"
#include <iostream>

using namespace console_helper;

const size_t ConsoleHelper::DEFAULT_BUFFER_SIZE = 1024;

/**
 * Creates a Console Helper command.
 */
IConsoleHelperSharedPtr ConsoleHelper::Make()
{
    return std::make_shared<ConsoleHelper>();
}

/**
 * The ConsoleHelper constructor.
 */
ConsoleHelper::ConsoleHelper()
{
}

/**
 * The ConsoleHelper destructor.
 */
ConsoleHelper::~ConsoleHelper()
{
}

/**
 * Runs the command.
 */
void ConsoleHelper::Run()
{
    //
    // Initialize command...
    //
    Initialize();

    //
    // Update title of console...
    //
    UpdateConsoleTitle(m_parameters->GetConsoleTile());

    //
    // Refresh data of console...
    //
    while (IsRunning()) {
        RefreshConsoleData(*m_pipe);
    }
}

/**
 * Gets the command.
 */
command::ICommand& ConsoleHelper::GetCommand()
{
    return *this;
}

/**
 * Initializes the command.
 */
void ConsoleHelper::Initialize()
{
    m_parameters = ConsoleHelperParameters::Make(command::AbstractCommand::GetParameters());
    m_pipe = OpenPipe(m_parameters->GetPipeName());
}

/**
 * Checks whether the process is running.
 */
bool ConsoleHelper::IsRunning() const
{
    return m_running;
}

/**
 * Sets title of console.
 */
void ConsoleHelper::UpdateConsoleTitle(const std::wstring& title)
{
    BOOL status = ::SetConsoleTitleW(title.c_str());

    if (!status) {
        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"Console Helper has failed updating console title: " << title
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw ConsoleHelperException(errorCode, errorMessage);
    }
}

/**
 * Refresh console data.
 */
void ConsoleHelper::RefreshConsoleData(
    console_windows::IConsolePipe& pipe,
    size_t bufferSize)
{
    console_windows::IConsolePipe::Buffer buffer(bufferSize);
    size_t numOfCharactersRead = pipe.Read(buffer);

    if (numOfCharactersRead > 0) {
        const std::wstring::value_type* data = &buffer[0];
        std::wcout.write(data, numOfCharactersRead);
    }
}

/**
 * Opens pipe for reading.
 */
console_windows::IConsolePipeSharedPtr ConsoleHelper::OpenPipe(const std::wstring& pipeName)
{
    return console_windows::ConsolePipe::Open(
        pipeName,
        console_windows::ConsolePipe::Mode::Read);
}
