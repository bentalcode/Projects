#pragma once

#include "ITabularTableWriter.h"
#include "IWriter.h"
#include <filesystem>

namespace TabularData {

/**
 * The TabularTableWriter class implements a writer of a Tabular Table.
 */
class TabularTableWriter final : public ITabularTableWriter {
public:
    /**
     * Creates a Tabular Table Writer.
     */
    static ITabularTableWriterSharedPtr Make(
        const std::wstring& path,
        const std::wstring& separator);

    /**
     * The TabularTableWriter constructor.
     */
    TabularTableWriter(
        const std::wstring& path,
        const std::wstring& separator);

    /**
     * The TabularTableWriter destructor.
     */
    virtual ~TabularTableWriter();

    /**
     * Writes a header.
     */
    virtual void WriteHeader(const ITabularHeader& header) override;

    /**
     * Writes a record.
     */
    virtual void WriteRecord(const ITabularRecord& record) override;

    /**
     * Writes a new line.
     */
    void NewLine() override;

private:
    /**
     * Creates a line.
     */
    static std::wstring CreateLine(
        const std::vector<std::wstring>& tokens, 
        const std::wstring& separator);

    IWriterSharedPtr m_writer;
    std::wstring m_separator;
};

} // namespace TabularData