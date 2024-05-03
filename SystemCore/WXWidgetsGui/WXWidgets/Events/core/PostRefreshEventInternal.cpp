#include "PostRefreshEventInternal.h"
#include "WXObjectId.h"

using namespace WXWidgets;

const PostRefreshEventInternal::Type PostRefreshEventInternal::TYPE(wxNewEventType());

/**
 * Gets an event id.
 */
int PostRefreshEventInternal::GetId()
{
    return WXObjectId::NextId();
}

/**
 * The PostRefreshEventInternal constructor.
 */
PostRefreshEventInternal::PostRefreshEventInternal(IGuiTransactionSharedPtr guiTransaction) : 
    wxCommandEvent(
        PostRefreshEventInternal::TYPE, 
        PostRefreshEventInternal::GetId()), 
    m_guiTransaction(guiTransaction)
{
}

/**
 * The PostRefreshEventInternal destructor.
 */
PostRefreshEventInternal::~PostRefreshEventInternal() 
{
}

/**
 * Clones an event.
 */
wxEvent* PostRefreshEventInternal::Clone() const
{
    return new PostRefreshEventInternal(*this);
}

/**
 * Gets a GUI transaction.
 */
IGuiTransactionSharedPtr PostRefreshEventInternal::GetGuiTransaction() 
{
    return m_guiTransaction;
}
