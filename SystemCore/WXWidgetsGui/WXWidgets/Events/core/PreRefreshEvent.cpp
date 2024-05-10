#include "PreRefreshEvent.h"

using namespace wxwidgets;

/**
 * Creates a pre refresh event.
 */
IWXEventSharedPtr PreRefreshEvent::Create(IGuiTransactionSharedPtr guiTransaction)
{
    return std::make_shared<PreRefreshEvent>(guiTransaction);
}

/**
 * The PreRefreshEvent constructor.
 */
PreRefreshEvent::PreRefreshEvent(IGuiTransactionSharedPtr guiTransaction) : 
    AbstractWXEvent<PreRefreshEventInternal>(
        std::make_shared<PreRefreshEventInternal>(guiTransaction)), 
    m_guiTransaction(guiTransaction)
{
}

/**
 * The PreRefreshEvent destructor.
 */
PreRefreshEvent::~PreRefreshEvent() 
{
}

/**
 * Gets a GUI transaction.
 */
IGuiTransactionSharedPtr PreRefreshEvent::GetGuiTransaction()
{
    return m_guiTransaction;
}
