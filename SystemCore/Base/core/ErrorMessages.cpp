#include "ErrorMessages.h"
#include "ErrorCodes.h"

using namespace base;

/**
 * Gets error code message.
 */
const std::wstring ErrorMessages::GetErrorCodeMessage(long errorCode) 
{
    std::wstringstream stream;
    stream << L"; ErrorCode: " << ErrorCodes::GetErrorCodeString(errorCode);

    return stream.str();
}