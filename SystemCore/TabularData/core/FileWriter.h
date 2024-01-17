#ifndef FILE_WRITER_H_9973ea8b_b642_4f61_8616_505ab330c3ea
#define FILE_WRITER_H_9973ea8b_b642_4f61_8616_505ab330c3ea

#include "IWriter.h"
#include <fstream>
#include <string>
#include <filesystem>

namespace tabular_data {

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

} // namespace tabular_data

#endif // FILE_WRITER_H_9973ea8b_b642_4f61_8616_505ab330c3ea

