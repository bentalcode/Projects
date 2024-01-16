#pragma once

#include "ITabularFile.h"
#include "TabularHeaderParser.h"
#include "TabularRecordParser.h"
#include "IFile.h"
#include "ITabularTable.h"

namespace TabularData {

/**
 * The TabularFile class implements a Tabular File.
 */
class TabularFile final : public ITabularFile {
public:
    /**
     * Creates a Tabular File.
     */
    static ITabularFileSharedPtr Make(
        const std::wstring& path, 
        ITabularHeaderParserSharedPtr headerParser = TabularHeaderParser::Make(),
        ITabularRecordParserSharedPtr recordParser = TabularRecordParser::Make());

    /**
     * The Tabular File constructor.
     */
    TabularFile(
        const std::wstring& path, 
        ITabularHeaderParserSharedPtr headerParser, 
        ITabularRecordParserSharedPtr recordParser);

    /**
     * The TabularFile destructor.
     */
    virtual ~TabularFile();

    /**
     * Gets file.
     */
    virtual const IFile& GetFile() const override;

    /**
     * Gets tabular table.
     */
    virtual const ITabularTable& GetTabularTable() const override;

private:
    /**
     * Creates a tabular table.
     */
    ITabularTableSharedPtr CreateTabularTable();

    /**
     * Parses a tabular header.
     */
    ITabularHeaderSharedPtr ParseTabularHeader(base::IIterator<IRecordSharedPtr>& recordIterator);

    //
    // The file...
    //
    IFileSharedPtr m_file;

    //
    // The Tabular Table of file...
    //
    ITabularTableSharedPtr m_tabularTable;

    //
    // The Tabular Header Parser...
    //
    ITabularHeaderParserSharedPtr m_headerParser;

    //
    // The Tabular Record Parser...
    //
    ITabularRecordParserSharedPtr m_recordParser;
};

} // namespace TabularData
