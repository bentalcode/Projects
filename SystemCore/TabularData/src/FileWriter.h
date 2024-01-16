#pragma once

#include "IWriter.h"
#include <fstream>
#include <string>
#include <filesystem>

namespace TabularData {

/**
 * The FileWriter class implements a writer.
 */
class FileWriter final : public IWriter {
public:
    /**
     * Creates a File Writer.
     */
    static IWriterSharedPtr Make(const std::wstring& path);

    /**
     * The FileWriter constructor.
     */
    explicit FileWriter(const std::wstring& path);

    /**
     * The FileWriter destructor.
     */
    virtual ~FileWriter();

    /**
     * Writes a line.
     */
    virtual void WriteLine(const std::wstring& line) override;

    /**
     * Writes a new line.
     */
    virtual void NewLine() override;

private:
    /**
     * Opens a file stream.
     */
    static void OpenFileStream(
        const std::wstring& path,
        std::wofstream& stream);

    /**
     * Closes file stream.
     */
    static void CloseFileStream(std::wofstream& stream);

    std::wofstream m_stream;
};

} // namespace TabularData
