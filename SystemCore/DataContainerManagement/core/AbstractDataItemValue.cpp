#include "AbstractDataItemValue.h"
#include "ErrorMessages.h"
#include "DataContainerException.h"
#include "Loggers.h"
#include <assert.h>

using namespace DataContainerManagement;

/**
 * The AbstractDataItemValue constructor.
 */
AbstractDataItemValue::AbstractDataItemValue() : 
    m_loggers(logging::Loggers::Make(typeid(DataContainerManagement::AbstractDataItemValue)))
{
}

/**
 * The AbstractDataItemValue destructor.
 */
AbstractDataItemValue::~AbstractDataItemValue() 
{
}

/**
 * Gets a boolean value.
 */
bool AbstractDataItemValue::GetBoolean() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a boolean value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);
    
    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets an integer value.
 */
int AbstractDataItemValue::GetInteger() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting an integer value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets a long value.
 */
long AbstractDataItemValue::GetLong() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a long value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets a double value.
 */
double AbstractDataItemValue::GetDouble() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a double value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets a string value.
 */
const std::wstring& AbstractDataItemValue::GetString() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a string value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets a date time value.
 */
const base::DateTime& AbstractDataItemValue::GetDateTime() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a date-time value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets a duration value.
 */
const base::Duration& AbstractDataItemValue::GetDuration() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a duration value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets a string value.
 */
const std::vector<std::wstring>& AbstractDataItemValue::GetStringArray() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a string array value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}

/**
 * Gets a string array value.
 */
const std::vector<std::vector<std::wstring>>& AbstractDataItemValue::GetStringArrayArray() const
{
    assert(false);

    long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The data item is not supporting a string array array value" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    throw data_container_exception(errorCode, errorMessage);
}
