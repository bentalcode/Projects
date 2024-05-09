#include "SetViewPropertiesRecord.h"
#include "SmartPointers.h"
#include "ITLogProcessor.h"
#include "Loggers.h"
#include "TloggingException.h"

using namespace tlogging;

/**
 * Creates a Set View Properties Record.
 */
ITLogRecordSharedPtr SetViewPropertiesRecord::Make(
    const std::wstring& header,
    const PropertyMapSharedPtr properties,
    const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<SetViewPropertiesRecord>(
        header,
        properties, 
        logRecord);
}

/**
 * The SetViewPropertiesRecord constructor.
 */
SetViewPropertiesRecord::SetViewPropertiesRecord(
    const std::wstring& header,
    const PropertyMapSharedPtr properties,
    const logging::ILogRecordSharedPtr logRecord) :
    m_loggers(logging::Loggers::Make((typeid(tlogging::SetViewPropertiesRecord))))
{
    base::SmartPointers::Validate<PropertyMap>(properties);
    base::SmartPointers::Validate<logging::ILogRecord>(logRecord);

    m_header = header;
    m_properties = properties;
    m_logRecord = logRecord;
}

/**
 * The SetViewPropertiesRecord destructor.
 */
SetViewPropertiesRecord::~SetViewPropertiesRecord() 
{
}

/**
 * Gets an optional header.
 */
const std::wstring& SetViewPropertiesRecord::GetHeader() const 
{
    return m_header;
}

/**
 * Checks whether a property exists.
 */
bool SetViewPropertiesRecord::HasProperty(const std::wstring& name) const
{
    return m_properties->find(name) != m_properties->end();
}

/**
 * Gets a value of a property.
 */
const std::wstring& SetViewPropertiesRecord::GetPropertyValue(const std::wstring& name) const
{
    const std::wstring* property = FindProperty(name);

    if (property == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"SetViewPropertiesRecord does not have property: " << name 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw TLoggingException(errorCode, errorMessage);
    }

    return *property;
}

/**
 * Gets properties of configuration.
 */
const ISetViewPropertiesRecord::PropertyMap& SetViewPropertiesRecord::GetProperties() const
{
    return *m_properties;
}

/**
 * Gets a log record.
 */
logging::ILogRecord& SetViewPropertiesRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Finds a property by name.
 */
const std::wstring* SetViewPropertiesRecord::FindProperty(const std::wstring& name) const
{
    ISetViewPropertiesRecord::PropertyMap::const_iterator propertyIterator = m_properties->find(name);
    return propertyIterator != m_properties->end() ? &propertyIterator->second : nullptr;
}

/**
 * Processes a record.
 */
void SetViewPropertiesRecord::Process(ITLogProcessor& processor) const
{
    processor.Process(*this);
}
