#include "ThreadIdTransformer.h"
#include "StringUtils.h"

using namespace logging;

/**
 * Creates a Thread Id Transformer.
 */
tabular_data::IValueTransformerSharedPtr<std::thread::id> ThreadIdTransformer::Make()
{
    return std::make_shared<ThreadIdTransformer>();
}

/**
 * The ThreadIdTransformer constructor.
 */
ThreadIdTransformer::ThreadIdTransformer()
{
}

/**
 * The ThreadIdTransformer destructor.
 */
ThreadIdTransformer::~ThreadIdTransformer()
{
}

/**
 * Transforms a value to a thread id.
 */
std::thread::id ThreadIdTransformer::Transform(const std::wstring& value) const
{
    unsigned long id = std::stoi(value);
    std::thread::id threadId(id);
    return threadId;
}
