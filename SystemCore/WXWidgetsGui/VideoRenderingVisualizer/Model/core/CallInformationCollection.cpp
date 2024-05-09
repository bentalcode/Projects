#include "CallInformationCollection.h"
#include "ModelCollection.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a collection of calls information.
 */
ICallInformationCollectionSharedPtr CallInformationCollection::Make()
{
    return std::make_shared<CallInformationCollection>();
}

/**
 * The CallInformationCollection constructor.
 */
CallInformationCollection::CallInformationCollection() : 
    m_impl(std::make_shared<ModelCollection<std::wstring, ICallInformation>>())
{
}

/**
 * The CallInformationCollection destructor.
 */
CallInformationCollection::~CallInformationCollection() 
{
}

/**
 * Adds an item.
 */
void CallInformationCollection::AddItem(const ICallInformationSharedPtr item)
{
    m_impl->AddItem(item);
    m_loggingObjectAddressToCall.insert(std::make_pair(item->GetLoggingObjectMemoryAddress(), item));
}

/**
 * Removes an item.
 * Returns true in case item has been removed, and false in case item has not been found.
 */
bool CallInformationCollection::RemoveItem(const std::wstring& id)
{
    return m_impl->RemoveItem(id);
}

/**
 * Gets a specific item.
 */
const ICallInformationSharedPtr CallInformationCollection::GetItem(const std::wstring& id) const
{
    return m_impl->GetItem(id);
}

/**
 * Checks whether a specific item exists.
 */
bool CallInformationCollection::HasItem(const std::wstring& id) const
{
    return m_impl->HasItem(id);
}

/**
 * Gets size of a collection.
 */
size_t CallInformationCollection::Size() const
{
    return m_impl->Size();
}

/**
 * Checks whether a collection is empty.
 */
bool CallInformationCollection::Empty() const
{
    return m_impl->Empty();
}

/**
 * Gets an iterator.
 */
base::IIteratorSharedPtr<ICallInformationSharedPtr> CallInformationCollection::GetIterator() const
{
    return m_impl->GetIterator();
}

/**
 * Finds corresponding call by logging object.
 * Returns nullptr in case no corresponding call has not been found.
 */
ICallInformationSharedPtr CallInformationCollection::FindCallByLoggingObject(const std::wstring& memoryAddress) 
{
    LoggingObjectAddressToCallMap::const_iterator callIterator = m_loggingObjectAddressToCall.find(memoryAddress);
    return callIterator != m_loggingObjectAddressToCall.end() ? callIterator->second : nullptr;
}

/**
 * Finds corresponding call by logging object.
 * Returns nullptr in case no corresponding call has not been found.
 */
const ICallInformationSharedPtr CallInformationCollection::FindCallByLoggingObject(const std::wstring& memoryAddress) const
{
    CallInformationCollection& thisInstance = const_cast<CallInformationCollection&>(*this);
    return thisInstance.FindCallByLoggingObject(memoryAddress);
}
