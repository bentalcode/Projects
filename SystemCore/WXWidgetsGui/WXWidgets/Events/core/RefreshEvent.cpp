#include "RefreshEvent.h"

using namespace wxwidgets;

/**
 * Creates a refresh event.
 */
IWXEventSharedPtr RefreshEvent::Create(IGuiTransactionSharedPtr guiTransaction)
{
    return std::make_shared<RefreshEvent>(guiTransaction);
}

/**
 * The RefreshEvent constructor.
 */
RefreshEvent::RefreshEvent(IGuiTransactionSharedPtr guiTransaction) : 
    AbstractWXEvent<RefreshEventInternal>(
        std::make_shared<RefreshEventInternal>(guiTransaction)), 
    m_guiTransaction(guiTransaction)
{
}

/**
 * The RefreshEvent destructor.
 */
RefreshEvent::~RefreshEvent() 
{
}

/**
 * Gets a GUI transaction.
 */
IGuiTransactionSharedPtr RefreshEvent::GetGuiTransaction()
{
    return m_guiTransaction;
}
