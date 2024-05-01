#include "LogWriter.h"
#include "TabularTableWriter.h"
#include "LogHeader.h"
#include "ILogRecord.h"
#include <iostream>
#include <experimental/filesystem>

using namespace logging;

/**
 * Creates a Log Writer.
 */
ILogWriterSharedPtr LogWriter::Make(
    const std::wstring& path,
    const std::wstring& separator)
{
    return std::make_shared<LogWriter>(path, separator);
}

/**
 * The LogWriter constructor.
 */
LogWriter::LogWriter(
    const std::wstring& path,
    const std::wstring& separator)
{
    //
    // Initialize a new log...
    //
    Initialize(
        path, 
        separator);
}

/**
 * The LogWriter destructor.
 */
LogWriter::~LogWriter() 
{
}

/**
 * Writes header.
 */
void LogWriter::WriteHeader(const ILogHeader& header)
{
    tabular_data::ITabularHeaderSharedPtr logHeader = header.ToHeader();
    m_writer->WriteHeader(*logHeader);
}

/**
 * Writes record.
 */
void LogWriter::WriteRecord(const ILogRecord& record)
{
    tabular_data::ITabularRecordSharedPtr logRecord = record.ToRecord();
    m_writer->WriteRecord(*logRecord);
}

/**
 * Writes a new line.
 */
void LogWriter::NewLine()
{
    m_writer->NewLine();
}

/**
 * Initializes a new log.
 */
void LogWriter::Initialize(
    const std::wstring& path,
    const std::wstring& separator)
{
    //
    // Deletes previous log...
    //
    bool status = DeleteLog(path);

    if (status) {
        std::wcout << L"Previous log has been deleted from: " << path;
    }

    //
    // Verify that the logs directory exists...
    //
    std::experimental::filesystem::path filePath(path);
    std::wstring logsPath = filePath.parent_path();

    if (!LogsDirectoryExists(logsPath)) {
        status = CreateLogsDirectory(logsPath);

        if (!status) {
            std::wcout << L"Logs path of has failed to be created: " << path;
        }
    }

    //
    // Create Tabular Table Writer...
    //
    m_writer = tabular_data::TabularTableWriter::Make(path, separator);
}

/**
 * Deletes log.
 */
bool LogWriter::DeleteLog(const std::wstring& path)
{
    if (!std::experimental::filesystem::exists(path)) {
        return false;
    }

    return std::experimental::filesystem::remove(path);
}

/**
 * Checks whethet logs directory exists.
 */
bool LogWriter::LogsDirectoryExists(const std::wstring& path) const
{
    return std::experimental::filesystem::exists(path);
}

/**
 * Create logs path.
 */
bool LogWriter::CreateLogsDirectory(const std::wstring& path)
{
    return std::experimental::filesystem::create_directories(path);
}
