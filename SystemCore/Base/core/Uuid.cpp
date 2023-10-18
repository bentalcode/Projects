#include "Uuid.h"
#include "ErrorCodes.h"
#include "StringUtils.h"
#include "combaseapi.h"
#include <vector>
#include "BaseException.h"

using namespace base;

/**
 * Creates a new instance of a uuid.
 */
IUuidSharedPtr Uuid::New()
{
    _GUID guid = {};
    CreateUuid(guid);
    
    return Make(guid);
}

/**
 * Creates a new instance of a uuid.
 */
IUuidSharedPtr Uuid::Make(const _GUID& guid)
{
    return std::make_shared<Uuid>(guid);
}

/**
 * The UUID constructor.
 */
Uuid::Uuid(const _GUID& guid) : 
    m_guid(guid)
{  
}

/**
 * The UUID destructor.
 */
Uuid::~Uuid() 
{
}

/**
 * Gets a string representation ofthis instance.
 */
std::wstring Uuid::ToString() const
{
    LPOLESTR pBuffer = nullptr;

    HRESULT hr = ::StringFromCLSID(m_guid, &pBuffer);

    if (!SUCCEEDED(hr)) {
        long errorCode = ErrorCodes::HResultToErrorCode(hr);

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Uuid class Has failed converting a UUID to a String"
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    std::wstring::value_type* pResult = reinterpret_cast<std::wstring::value_type*>(pBuffer);
    size_t length = wcslen(pResult);

    std::wstring str(pResult, length);

    ::CoTaskMemFree(pBuffer);
        
    return str;
}

/**
 * Parses a uuid from a string.
 */
IUuidSharedPtr Uuid::Parse(const std::wstring& str)
{
    _GUID guid = {};
    long errorCode = TryParseUuid(str, guid);

    if (errorCode != ErrorCodes::SUCCESS) {
        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Uuid class Has failed converting a UUID to a String"
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    return Make(guid);
}

/**
 * Tries to parse a uuid from string.
 */
IUuidSharedPtr Uuid::TryParse(const std::wstring& str) 
{
    _GUID guid = {};
    long statusCode = TryParseUuid(str, guid);

    return statusCode == ErrorCodes::SUCCESS ? Make(guid) : nullptr;
}

/**
 * Checks whether a string is a valid uuid.
 */
bool Uuid::IsUuid(const std::wstring& str)
{
    IUuidSharedPtr uuid = TryParse(str);
    return uuid != nullptr;
}

/**
 * Tries to parse a guid from string.
 */
long Uuid::TryParseUuid(const std::wstring& str, _GUID& guid)
{
    std::string guidStr = StringUtils::WideStringToString(str);

    LPCOLESTR pGuidStr = reinterpret_cast<LPCOLESTR>(guidStr.c_str());

    HRESULT hr = ::CLSIDFromString(pGuidStr, &guid);

    return ErrorCodes::HResultToErrorCode(hr);
}

/**
 * Creates a uuid from string.
 */
void Uuid::CreateUuid(_GUID& guid) 
{
    HRESULT hr = ::CoCreateGuid(&guid);

    if (!SUCCEEDED(hr)) {
        long errorCode = ErrorCodes::HResultToErrorCode(hr);
        
        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Uuid class Has failed generating a new UUID"
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }
}
