#include "WXObjectId.h"

using namespace wxwidgets;

/**
 * The WXObjectId constructor.
 */
WXObjectId::WXObjectId() : 
    m_id(0) 
{
}

/**
 * The WXObjectId destructor.
 */
WXObjectId::~WXObjectId() 
{
}

int WXObjectId::NextId()
{
    static WXObjectId objectId;
    return objectId.Next();
}

/**
 * Gets the next identifier.
 */
int WXObjectId::Next()
{
    ++m_id;
    return m_id;
}
