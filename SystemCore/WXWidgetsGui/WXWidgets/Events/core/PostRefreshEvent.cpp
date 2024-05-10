#include "PostRefreshEvent.h"

using namespace wxwidgets;

/**
 * Creates a post refresh event.
 */
IWXEventSharedPtr PostRefreshEvent::Create(IGuiTransactionSharedPtr guiTransaction)
{
    return std::make_shared<PostRefreshEvent>(guiTransaction);
}

/**
 * The PostRefreshEvent constructor.
 */
PostRefreshEvent::PostRefreshEvent(IGuiTransactionSharedPtr guiTransaction) : 
    AbstractWXEvent<PostRefreshEventInternal>(
        std::make_shared<PostRefreshEventInternal>(guiTransaction)), 
    m_guiTransaction(guiTransaction)
{
}

/**
 * The PostRefreshEvent destructor.
 */
PostRefreshEvent::~PostRefreshEvent() 
{
}

/**
 * Gets a GUI transaction.
 */
IGuiTransactionSharedPtr PostRefreshEvent::GetGuiTransaction()
{
    return m_guiTransaction;
}
