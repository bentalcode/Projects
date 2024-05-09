#include "CompositorInformationCollection.h"
#include "ModelCollection.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a collection of compositor information.
 */
ICompositorInformationCollectionSharedPtr CompositorInformationCollection::Make()
{
    return std::make_shared<CompositorInformationCollection>();
}

/**
 * The CompositorInformationCollection constructor.
 */
CompositorInformationCollection::CompositorInformationCollection() : 
    m_impl(std::make_shared<ModelCollection<std::wstring, ICompositorInformation>>())
{
}

/**
 * The CompositorInformationCollection destructor.
 */
CompositorInformationCollection::~CompositorInformationCollection() 
{
}

/**
 * Adds an item.
 */
void CompositorInformationCollection::AddItem(const ICompositorInformationSharedPtr item)
{
    m_impl->AddItem(item);
}

/**
 * Removes an item.
 * Returns true in case item has been removed, and false in case item has not been found.
 */
bool CompositorInformationCollection::RemoveItem(const std::wstring& id)
{
    return m_impl->RemoveItem(id);
}

/**
 * Gets a specific item.
 */
const ICompositorInformationSharedPtr CompositorInformationCollection::GetItem(const std::wstring& id) const
{
    return m_impl->GetItem(id);
}

/**
 * Checks whether a specific item exists.
 */
bool CompositorInformationCollection::HasItem(const std::wstring& id) const
{
    return m_impl->HasItem(id);
}

/**
 * Gets size of a collection.
 */
size_t CompositorInformationCollection::Size() const
{
    return m_impl->Size();
}

/**
 * Checks whether a collection is empty.
 */
bool CompositorInformationCollection::Empty() const
{
    return m_impl->Empty();
}

/**
 * Gets an iterator.
 */
base::IIteratorSharedPtr<ICompositorInformationSharedPtr> CompositorInformationCollection::GetIterator() const
{
    return m_impl->GetIterator();
}
