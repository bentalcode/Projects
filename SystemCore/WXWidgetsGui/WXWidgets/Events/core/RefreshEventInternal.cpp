#include "RefreshEventInternal.h"
#include "WXObjectId.h"

using namespace wxwidgets;

const RefreshEventInternal::Type RefreshEventInternal::TYPE(wxNewEventType());

/**
 * Gets an event id.
 */
int RefreshEventInternal::GetId()
{
    return WXObjectId::NextId();
}

/**
 * The RefreshEventInternal constructor.
 */
RefreshEventInternal::RefreshEventInternal(IGuiTransactionSharedPtr guiTransaction) : 
    wxCommandEvent(
        RefreshEventInternal::TYPE, 
        RefreshEventInternal::GetId()), 
    m_guiTransaction(guiTransaction)
{
}

/**
 * The RefreshEventInternal destructor.
 */
RefreshEventInternal::~RefreshEventInternal() 
{
}

/**
 * Clones an event.
 */
wxEvent* RefreshEventInternal::Clone() const
{
    return new RefreshEventInternal(*this);
}

/**
 * Gets a GUI transaction.
 */
IGuiTransactionSharedPtr RefreshEventInternal::GetGuiTransaction() 
{
    return m_guiTransaction;
}
