#include "ConsoleWindow.h"
#include "ConsoleStreamBuffer.h"
#include "ConsoleProcess.h"
#include "ConsolePipe.h"
#include "Uuid.h"
#include "StringUtils.h"
#include "SmartPointers.h"

using namespace console_windows;

//
// Defines the default size of console...
//
const size_t ConsoleWindow::DEFAULT_BUFFER_SIZE = 4096;

/**
 * Creates a ConsoleWindow.
 */
IConsoleWindowSharedPtr ConsoleWindow::Make(
    const std::wstring& name,
    const std::wstring& executablePath,
    size_t bufferSize)
{
    IConsoleStreamBufferSharedPtr pipeBuffer = ConsoleStreamBuffer::Make(
        name,
        bufferSize);

    return std::make_shared<ConsoleWindow>(
        name,
        executablePath,
        pipeBuffer);
}

/**
 * The ConsoleWindow constructor.
 */
ConsoleWindow::ConsoleWindow(
    const std::wstring& name,
    const std::wstring& executablePath,
    IConsoleStreamBufferSharedPtr pipeBuffer) :
    std::wostream(base::SmartPointers::ValidateAndReturn(pipeBuffer).get()),
    m_name(name),
    m_pipeBuffer(pipeBuffer),
    m_pipe(CreatePipe(m_name))
{
    //
    // Initialize the pipe buffer with the pipe...
    //
    m_pipeBuffer->Initialize(m_pipe);

    //
    // Create the process for running the console...
    //
    std::wstring consoleName = name;
    std::wstring pipeName = m_pipe->GetName();

    m_process = CreateConsoleProcess(
        executablePath,
        consoleName,
        pipeName);
}

/**
 * The ConsoleWindow destructor.
 */
ConsoleWindow::~ConsoleWindow()
{
}

/**
 * Gets console stream.
 */
std::wostream& ConsoleWindow::GetConsoleStream()
{
    return *this;
}

/**
 * Creates a pipe.
 */
IConsolePipeSharedPtr ConsoleWindow::CreatePipe(const std::wstring& name)
{
    std::wstring uniqueName = CreateUniquePipeName(name);
    IConsolePipe::Mode mode = IConsolePipe::Mode::Write;

    size_t readCapacity = 0;
    size_t writeCapacity = DEFAULT_BUFFER_SIZE;

    return ConsolePipe::Create(
        uniqueName,
        mode,
        readCapacity,
        writeCapacity);
}

/**
 * Creates a console process.
 */
IConsoleProcessSharedPtr ConsoleWindow::CreateConsoleProcess(
    const std::wstring& executableName,
    const std::wstring& consoleName,
    const std::wstring& pipeName)
{
    std::wstring commandLine = BuildCommandLine(
        executableName,
        consoleName,
        pipeName);

    return ConsoleProcess::Make(
        executableName,
        commandLine);
}

/**
 * Creates a unique pipe name.
 */
std::wstring ConsoleWindow::CreateUniquePipeName(const std::wstring& name)
{
    std::wstring id = base::Uuid::New()->ToString();
    id = id.substr(1, id.size() - 2);

    std::wstringstream nameStream;
    nameStream
        << name
        << L"_"
        << id;

    return nameStream.str();
}

/**
 * Builds command line.
 */
std::wstring ConsoleWindow::BuildCommandLine(
    const std::wstring& executableName,
    const std::wstring& title,
    const std::wstring& pipeName)
{
    std::wstringstream commandStream;
    commandStream
        << executableName
        << L" \""
        << title
        << "\" \""
        << pipeName
        << "\"";

    return commandStream.str();
}
