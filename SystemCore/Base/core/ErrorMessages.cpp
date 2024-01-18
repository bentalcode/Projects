#include "ErrorMessages.h"
#include <sstream>

using namespace base;

/**
 * Gets error code message.
 */
const std::wstring ErrorMessages::GetErrorCodeMessage(long errorCode) 
{
    std::wstringstream stream;
    stream << L"; ErrorCode: 0x" << std::hex << errorCode;
    return stream.str();
}
