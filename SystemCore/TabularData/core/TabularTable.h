#ifndef TABULAR_TABLE_H_f5e8cb8a_87e5_4177_a739_1da7bfa042e7
#define TABULAR_TABLE_H_f5e8cb8a_87e5_4177_a739_1da7bfa042e7

#include "ITabularTable.h"

namespace tabular_data {

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

} // namespace tabular_data

#endif // TABULAR_TABLE_H_f5e8cb8a_87e5_4177_a739_1da7bfa042e7

