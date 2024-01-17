#pragma once

#include "IIterator.h"
#include "ITabularRecord.h"
#include "ITabularRecordParser.h"

namespace tabular_data {

/**
 * The TabularRecordIterator class implements a Tabular Record Iterator.
 */
class TabularRecordIterator final : public base::IIterator<ITabularRecordSharedPtr> {
public:
    /**
     * Creates a Tabular Record Iterator.
     */
    static base::IIteratorSharedPtr<ITabularRecordSharedPtr> Make(
        base::IIteratorSharedPtr<IRecordSharedPtr> recordIterator,
        ITabularRecordParserSharedPtr recordParser);

    /**
     * The TabularRecordIterator constructor.
     */
    TabularRecordIterator(
        base::IIteratorSharedPtr<IRecordSharedPtr> recordIterator,
        ITabularRecordParserSharedPtr recordParser);

    /**
     * The TabularRecordIterator destructor.
     */
    virtual ~TabularRecordIterator();

    /**
     * Checks whether there is a next element.
     */
    virtual bool HasNext() const override;

    /**
     * Gets the next element.
     */
    virtual ITabularRecordSharedPtr Next() override;

    /**
     * Resets the iterator.
     */
    virtual void Reset() override;

private:
    //
    // The iterator of records...
    //
    base::IIteratorSharedPtr<IRecordSharedPtr> m_recordIterator;

    //
    // The Tabular Record Parser...
    //
    ITabularRecordParserSharedPtr m_recordParser;

    //
    // The current index...
    //
    size_t m_currRecordIndex;
};

} // namespace tabular_data
