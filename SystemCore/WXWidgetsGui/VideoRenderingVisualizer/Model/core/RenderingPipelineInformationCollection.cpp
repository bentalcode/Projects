#include "RenderingPipelineInformationCollection.h"
#include "ModelCollection.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a collection of rendering pipelines information.
 */
IRenderingPipelineInformationCollectionSharedPtr RenderingPipelineInformationCollection::Make()
{
    return std::make_shared<RenderingPipelineInformationCollection>();
}

/**
 * The RenderingPipelineInformationCollection constructor.
 */
RenderingPipelineInformationCollection::RenderingPipelineInformationCollection() : 
    m_impl(std::make_shared<ModelCollection<std::wstring, IRenderingPipelineInformation>>())
{
}

/**
 * The RenderingPipelineInformationCollection destructor.
 */
RenderingPipelineInformationCollection::~RenderingPipelineInformationCollection() 
{
}

/**
 * Adds an item.
 */
void RenderingPipelineInformationCollection::AddItem(const IRenderingPipelineInformationSharedPtr item)
{
    m_impl->AddItem(item);
}

/**
 * Removes an item.
 * Returns true in case item has been removed, and false in case item has not been found.
 */
bool RenderingPipelineInformationCollection::RemoveItem(const std::wstring& id)
{
    return m_impl->RemoveItem(id);
}

/**
 * Gets a specific item.
 */
const IRenderingPipelineInformationSharedPtr RenderingPipelineInformationCollection::GetItem(const std::wstring& id) const
{
    return m_impl->GetItem(id);
}

/**
 * Checks whether a specific item exists.
 */
bool RenderingPipelineInformationCollection::HasItem(const std::wstring& id) const
{
    return m_impl->HasItem(id);
}

/**
 * Gets size of a collection.
 */
size_t RenderingPipelineInformationCollection::Size() const
{
    return m_impl->Size();
}

/**
 * Checks whether a collection is empty.
 */
bool RenderingPipelineInformationCollection::Empty() const
{
    return m_impl->Empty();
}

/**
 * Gets an iterator.
 */
base::IIteratorSharedPtr<IRenderingPipelineInformationSharedPtr> RenderingPipelineInformationCollection::GetIterator() const
{
    return m_impl->GetIterator();
}
