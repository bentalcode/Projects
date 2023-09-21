#include "ErrorMessages.h"
#include <sstream>

using namespace base;

/**
 * Gets error code message.
 */
const std::wstring ErrorMessages::GetErrorCodeMessage(long errorCode) 
{
    std::wstringstream stream;
    stream << ErrorMessages::GetErrorCodeMessage(errorCode);
    return stream.str();
}
