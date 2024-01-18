#include "ConsoleFileFinderCommand.h"
#include "ConsoleWindowManager.h"
#include "ConsoleFileFinderCommandParameters.h"
#include "FileFinder.h"
#include "FileConsole.h"

using namespace consolefilefinder;

/**
 * Creates a console file finder command.
 */
IConsoleFileFinderCommandSharedPtr ConsoleFileFinderCommand::Make()
{
    return std::make_shared<ConsoleFileFinderCommand>();
}

/**
 * The ConsoleFileFinderCommand constructor.
 */
ConsoleFileFinderCommand::ConsoleFileFinderCommand() :
    m_consoleWindowManager(ConsoleWindowManager::Make())
{
}

/**
 * The ConsoleFileFinderCommand destructor.
 */
ConsoleFileFinderCommand::~ConsoleFileFinderCommand()
{
}

/**
 * Runs the command.
 */
void ConsoleFileFinderCommand::Run()
{
    //
    // Initialize command...
    //
    Initialize();

    //
    // Find files...
    //
    std::list<std::wstring> files;

    IFileFinderSharedPtr fileFinder = FileFinder::Make();
    fileFinder->FindFiles(
        m_parameters->GetPath(),
        m_parameters->GetFilePatterns(),
        files);

    for (const std::wstring& file : files) {
        ProcessFile(file);
    }

    //
    // Create a console windows...
    //
    CreateConsoleWindows();
}

/**
 * Gets the command.
 */
command::ICommand& ConsoleFileFinderCommand::GetCommand()
{
    return *this;
}

/**
 * Initializes the command.
 */
void ConsoleFileFinderCommand::Initialize()
{
    m_parameters = ConsoleFileFinderCommandParameters::Make(command::AbstractCommand::GetParameters());
}

/**
 * Processes file.
 */
void ConsoleFileFinderCommand::ProcessFile(const std::wstring& path)
{
    IFileConsoleSharedPtr fileConsole = FileConsole::Make(path);
    fileConsole->Display();
}

/**
 * Creates console windows.
 */
void ConsoleFileFinderCommand::CreateConsoleWindows()
{
    m_consoleWindowManager->CreateWindow(L"Window1");
}
