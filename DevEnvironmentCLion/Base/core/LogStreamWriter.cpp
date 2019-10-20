#include "PreCompiled.h"

#include "LogStreamWriter.h"

using namespace base;

/**
 * The LogStreamWriter default constructor.
 */
LogStreamWriter::LogStreamWriter() :
    m_errorStream(std::cout),
    m_warningStream(std::cout),
    m_informationalStream(std::cout),
    m_debugStream(std::cout)
{
}

/**
 * The LogStreamWriter constructor.
 */
LogStreamWriter::LogStreamWriter(
    std::ostream& errorStream,
    std::ostream& warningStream,
    std::ostream& informationalStream,
    std::ostream& debugStream) :
    m_errorStream(errorStream),
    m_warningStream(warningStream),
    m_informationalStream(informationalStream),
    m_debugStream(debugStream)
{
}

/**
 * The LogStreamWriter destructor.
 */
LogStreamWriter::~LogStreamWriter()
{
}
