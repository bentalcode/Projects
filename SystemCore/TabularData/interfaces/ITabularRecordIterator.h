#ifndef I_TABULAR_RECORD_ITERATOR_H_54bf049d_9053_4e6b_9596_3672afda3515
#define I_TABULAR_RECORD_ITERATOR_H_54bf049d_9053_4e6b_9596_3672afda3515

#include "IIterator.h"

namespace tabular_data {

/**
 * The ITabularRecordIterator interface defines a Tabular Record Iterator.
 */
class ITabularRecordIterator : public Utilities::IIterator<ITabularRecordIterator> {
public: 
	ITabularRecordIterator() = default;
	virtual ~ITabularRecordIterator() = default;

	/**
     * Clones an iterator.
     */
	ITabularRecordIteratorSharedPtr Clone();
};

/**
 * Defines the Shared Ptr of Tabular Record Iterator.
 */
using ITabularRecordIteratorSharedPtr = std::shared_ptr<ITabularRecordIterator>;

} // namespace tabular_data

#endif // I_TABULAR_RECORD_ITERATOR_H_54bf049d_9053_4e6b_9596_3672afda3515
