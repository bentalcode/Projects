#pragma once

#include "ITabularTable.h"

namespace TabularData {

/**
 * The TabularTable class implements a Tabular Table.
 */
class TabularTable final : public ITabularTable {
public:
    /**
     * Creates a Tabular Table.
     */
    static ITabularTableSharedPtr Make(
        const ITabularHeaderSharedPtr header,
        base::IIteratorSharedPtr<ITabularRecordSharedPtr> recordIterator);

    /**
     * The TabularTable constructor.
     */
    TabularTable(
        const ITabularHeaderSharedPtr header,
        base::IIteratorSharedPtr<ITabularRecordSharedPtr> recordIterator);

    /**
     * The TabularTable destructor.
     */
    virtual ~TabularTable();

    /**
     * Gets a header of tabular table.
     */
    virtual const ITabularHeaderSharedPtr GetHeader() const override;

    /**
     * Gets an iterator of records of tabular table.
     */
    virtual base::IIteratorSharedPtr<ITabularRecordSharedPtr> GetRecordIterator() const override;

private:
    ITabularHeaderSharedPtr m_header;
    base::IIteratorSharedPtr<ITabularRecordSharedPtr> m_recordIterator;
};

} // namespace TabularData
