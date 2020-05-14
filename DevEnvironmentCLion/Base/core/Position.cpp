#include "PreCompiled.h"

#include "Position.h"

using namespace base;

/**
 * The Position constructor.
 */
Position::Position(long row, long column) :
    m_row(row),
    m_column(column)
{
}

/**
 * The Position destructor.
 */
Position::~Position()
{
}

/**
 * The Position copy constructor.
 */
Position::Position(const Position& position) :
    m_row(position.m_row),
    m_column(position.m_column)
{
}

/**
 * The Position assignment operator constructor.
 */
Position& Position::operator=(const Position& position)
{
    if (this == &position)
    {
        return *this;
    }

    m_row = position.m_row;
    m_column = position.m_column;

    return *this;
}
