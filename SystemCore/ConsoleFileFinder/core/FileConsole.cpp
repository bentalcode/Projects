#include "FileConsole.h"
#include "File.h"
#include "Console.h"
#include <iostream>

using namespace consolefilefinder;

/**
 * Creates a file finder.
 */
IFileConsoleSharedPtr FileConsole::Make(const std::wstring& path)
{
    return std::make_shared<FileConsole>(path);
}

/**
 * The FileConsole constructor.
 */
FileConsole::FileConsole(const std::wstring& path) :
    m_file(tabular_data::File::Make(path)),
    m_console(Console::Make(std::wcout))
{
}

/**
 * The FileConsole destructor.
 */
FileConsole::~FileConsole()
{
}

/**
 * Displays content of a file.
 */
void FileConsole::Display()
{
    base::IIteratorSharedPtr<tabular_data::IRecordSharedPtr> iterator = m_file->GetIterator();

    while (iterator->HasNext()) {
        tabular_data::IRecordSharedPtr record = iterator->Next();
        const std::wstring line = record->GetContent();
        m_console->WriteLine(line);
    }
}