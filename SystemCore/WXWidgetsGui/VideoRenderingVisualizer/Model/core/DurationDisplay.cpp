#include "DurationDisplay.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * The DurationDisplay constructor.
 */
DurationDisplay::DurationDisplay(const base::DurationSharedPtr duration) :
	m_duration(duration) 
{
}

/**
 * The DurationDisplay destructor.
 */
DurationDisplay::~DurationDisplay()
{
}

/**
 * Gets duration.
 */
const base::DurationSharedPtr DurationDisplay::GetDuration() const
{
    return m_duration;
}
