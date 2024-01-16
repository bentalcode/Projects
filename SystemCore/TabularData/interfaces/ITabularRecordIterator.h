#pragma once

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
