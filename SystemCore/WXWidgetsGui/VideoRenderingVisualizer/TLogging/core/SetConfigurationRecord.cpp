#include "SetConfigurationRecord.h"
#include "SmartPointers.h"
#include "ITLogProcessor.h"
#include "Loggers.h"
#include "TLoggingException.h"

using namespace tlogging;

/**
 * Creates a Set Configuration Record.
 */
ITLogRecordSharedPtr SetConfigurationRecord::Make(
    const PropertyMapSharedPtr properties,
    const logging::ILogRecordSharedPtr logRecord)
{
    return std::make_shared<SetConfigurationRecord>(
        properties, 
        logRecord);
}

/**
 * The SetConfigurationRecord constructor.
 */
SetConfigurationRecord::SetConfigurationRecord(
    const PropertyMapSharedPtr properties,
    const logging::ILogRecordSharedPtr logRecord) :
    m_loggers(logging::Loggers::Make(typeid(SetConfigurationRecord)))
{
    base::SmartPointers::Validate<PropertyMap>(properties);
    base::SmartPointers::Validate<logging::ILogRecord>(logRecord);

    m_properties = properties;
    m_logRecord = logRecord;
}

/**
 * The SetConfigurationRecord destructor.
 */
SetConfigurationRecord::~SetConfigurationRecord() 
{
}

/**
 * Checks whether a property exists.
 */
bool SetConfigurationRecord::HasProperty(const std::wstring& name) const 
{
    return m_properties->find(name) != m_properties->end();
}

/**
 * Gets a value of a property.
 */
const std::wstring& SetConfigurationRecord::GetPropertyValue(const std::wstring& name) const 
{
    const std::wstring* property = FindProperty(name);

    if (property == nullptr) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"SetConfigurationRecord does not have property: " << name 
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
const ISetConfigurationRecord::PropertyMap& SetConfigurationRecord::GetProperties() const 
{
    return *m_properties;
}

/**
 * Gets a log record.
 */
logging::ILogRecord& SetConfigurationRecord::GetLogRecord() const
{
    return *m_logRecord;
}

/**
 * Finds a property by name.
 */
const std::wstring* SetConfigurationRecord::FindProperty(const std::wstring& name) const
{
    PropertyMap::const_iterator propertyIterator = m_properties->find(name);
    return propertyIterator != m_properties->end() ? &propertyIterator->second : nullptr;
}

/**
 * Processes a record.
 */
void SetConfigurationRecord::Process(ITLogProcessor& processor) const
{
    processor.Process(*this);
}
