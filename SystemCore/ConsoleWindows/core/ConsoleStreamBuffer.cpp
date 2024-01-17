#include "ConsoleStreamBuffer.h"
#include "SmartPointers.h"

using namespace console_windows;

/**
 * Creates a Console Stream Buffer.
 */
static IConsoleStreamBufferSharedPtr Make(
    const std::wstring& name,
    size_t size)
{
    return std::make_shared<ConsoleStreamBuffer>(
        name,
        size);
}

/**
 * The ConsoleStreamBuffer constructor.
 */
ConsoleStreamBuffer::ConsoleStreamBuffer(
    const std::wstring& name,
    size_t size) :
    m_name(name),
    m_size(size)
{
}

/**
 * The ConsoleStreamBuffer destructor.
 */
ConsoleStreamBuffer::~ConsoleStreamBuffer()
{
}

/**
 * Initializes the console stream buffer.
 */
void ConsoleStreamBuffer::Initialize(IConsolePipeSharedPtr pipe)
{
    base::SmartPointers::Validate(pipe);
    m_pipe = pipe;

    m_buffer.resize(m_size);

    const auto begin = m_buffer.data();
    const auto end = begin + m_buffer.size();

    setp(begin, end);
}

/**
 * Publishes stream buffer.
 */
void ConsoleStreamBuffer::Publish()
{
    const auto size = pptr() - pbase();
    if (size > 0)
    {
        m_pipe->Write(m_buffer);
        setp(m_buffer.data(), m_buffer.data() + m_buffer.size());
    }
}

std::basic_streambuf<std::wstring::value_type>::int_type ConsoleStreamBuffer::overflow(int_type character)
{
    Publish();

    if (character != traits_type::eof())
    {
        *pptr() = character;
        pbump(1);
        return character;
    }

    return traits_type::eof();
}

int ConsoleStreamBuffer::sync()
{
    Publish();
    return 0;
}
