#include "AbstractTransaction.h"

using namespace wxwidgets::controller;

/**
 * The AbstractTransaction constructor.
 */
AbstractTransaction::AbstractTransaction(IControllerManager& controllerManager) : 
    m_controllerManager(controllerManager)
{
}

/**
 * The AbstractTransaction destructor.
 */
AbstractTransaction::~AbstractTransaction() 
{
}

/**
 * Gets a controller manager.
 */
IControllerManager& AbstractTransaction::GetControllerManager() 
{
    return m_controllerManager;
}
