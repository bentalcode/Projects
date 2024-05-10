#include "PreRefreshEventInternal.h"
#include "WXObjectId.h"

using namespace wxwidgets;

const PreRefreshEventInternal::Type PreRefreshEventInternal::TYPE(wxNewEventType());

/**
 * Gets an event id.
 */
int PreRefreshEventInternal::GetId()
{
    return WXObjectId::NextId();
}

/**
 * The PreRefreshEventInternal constructor.
 */
PreRefreshEventInternal::PreRefreshEventInternal(IGuiTransactionSharedPtr guiTransaction) : 
    wxCommandEvent(
        PreRefreshEventInternal::TYPE, 
        PreRefreshEventInternal::GetId()), 
    m_guiTransaction(guiTransaction)
{
}

/**
 * The PreRefreshEventInternal destructor.
 */
PreRefreshEventInternal::~PreRefreshEventInternal() 
{
}

/**
 * Clones an event.
 */
wxEvent* PreRefreshEventInternal::Clone() const
{
    return new PreRefreshEventInternal(*this);
}

/**
 * Gets a GUI transaction.
 */
IGuiTransactionSharedPtr PreRefreshEventInternal::GetGuiTransaction() 
{
    return m_guiTransaction;
}
