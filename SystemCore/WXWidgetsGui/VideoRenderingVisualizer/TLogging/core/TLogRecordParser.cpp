#include "TLogRecordParser.h"
#include "TLogRecordType.h"
#include "Loggers.h"
#include "CallStartedRecord.h"
#include "CallEndedRecord.h"
#include "CompositorCreatedRecord.h"
#include "CompositorDestroyedRecord.h"
#include "AddViewRecord.h"
#include "RemoveViewRecord.h"
#include "SetConfigurationRecord.h"
#include "SetViewPropertiesRecord.h"
#include "Volume.h"
#include "Indexes.h"
#include "StringUtils.h"
#include "Position.h"
#include <regex>
#include <assert.h>
#include <stack>

#include "TloggingException.h"

using namespace tlogging;

const std::wstring TLogRecordParser::CALL_STARTED = L"CreateMediaFlow\\(\\) enter";
const std::wstring TLogRecordParser::CALL_ENDED = L"Terminate\\(\\) enter";
const std::wstring TLogRecordParser::COMPOSITOR_CREATED = L"Compositor created";
const std::wstring TLogRecordParser::COMPOSITOR_DESTROYED = L"Compositor destroyed";
const std::wstring TLogRecordParser::ADD_VIEW = L"AddView";
const std::wstring TLogRecordParser::REMOVE_VIEW = L"RemoveView";
const std::wstring TLogRecordParser::SET_CONFIGURATION = L"SetConfiguration";
const std::wstring TLogRecordParser::SET_VIEW_PROPERTIES = L"SetViewProperties";
const std::wstring TLogRecordParser::ECS_SETTINGS = L"ECS settings";
const std::wstring TLogRecordParser::SET_DIMENSIONS = L"Set Dimensions";

const std::wstring TLogRecordParser::CALL_STARTED_RECORD_REGEX = 
    CALL_STARTED + L", CallId:[\\s]+([0-9A-Fa-f]{8}-[0-9A-Fa-f]{4}-[0-9A-Fa-f]{4}-[0-9A-Fa-f]{4}-[0-9A-Fa-f]{12}), "
    "RemoteUri:[\\s]+([^,]*),[\\s]+callKey:[\\s]([^,]*),[\\s]+SecurityLevel:[\\s]([^,]*),[\\s]BypassInfo:([\\s]+0x[0-"
    "9A-Fa-f]{16})";

const std::wstring TLogRecordParser::CALL_ENDED_RECORD_REGEX = 
    CALL_ENDED;

const std::wstring TLogRecordParser::COMPOSITOR_CREATED_RECORD_REGEX = 
    COMPOSITOR_CREATED + L"[\\s]+([1-9-]+)";

const std::wstring TLogRecordParser::COMPOSITOR_DESTROYED_RECORD_REGEX = 
    COMPOSITOR_DESTROYED + L"[\\s]+([1-9-]+)";

const std::wstring TLogRecordParser::ADD_VIEW_RECORD_REGEX = 
    ADD_VIEW + L"[\\s]+([0-9]+) views total add view id=([0-9]+) x=([0-9]+.?[0.9]+) y=([0-9]+.?[0.9]+) "
    "width=([0-9]+.?[0.9]+) height=([0-9]+.?[0.9]+)";

const std::wstring TLogRecordParser::REMOVE_VIEW_RECORD_REGEX = 
    REMOVE_VIEW + L"[\\s]+([0-9]+) views total removed view id=([0-9]+)";

const std::wstring TLogRecordParser::SET_CONFIGURATION_RECORD_REGEX1A =
    SET_CONFIGURATION + L"[\\s]+([^\\s]+=[^\\s]*)";

const std::wstring TLogRecordParser::SET_CONFIGURATION_RECORD_REGEX1B =
    SET_CONFIGURATION + L"[\\s]+([^\\s]+=[^\\s]*([\\s]+[^\\s]+=[^\\s]*)*)";

const std::wstring TLogRecordParser::SET_CONFIGURATION_RECORD_REGEX2A = 
    SET_CONFIGURATION + L"[\\s]+" + ECS_SETTINGS + L"[^\\s]*[\\s]+" + L"([^\\s]+=[^\\s]*)";

const std::wstring TLogRecordParser::SET_CONFIGURATION_RECORD_REGEX2B = 
    SET_CONFIGURATION + L"[\\s]+" + ECS_SETTINGS + L"[^\\s]*[\\s]+" + L"([^\\s]+=[^\\s]*([\\s]+[^\\s]+=[^\\s]*)*)";

const std::wstring TLogRecordParser::SET_VIEW_PROPERTIES_RECORD_REGEX1A =
    SET_VIEW_PROPERTIES + L"[\\s]+([^\\s]+=[^\\s]*)";

const std::wstring TLogRecordParser::SET_VIEW_PROPERTIES_RECORD_REGEX1B =
    SET_VIEW_PROPERTIES + L"[\\s]+([^\\s]+=[^\\s]*([\\s]+[^\\s]+=[^\\s]*)*)";

const std::wstring TLogRecordParser::SET_VIEW_PROPERTIES_RECORD_REGEX2A =
    SET_VIEW_PROPERTIES + L"[\\s]+" + SET_DIMENSIONS + L"[^\\s][\\s]+([^\\s]+=[^\\s]*)";

const std::wstring TLogRecordParser::SET_VIEW_PROPERTIES_RECORD_REGEX2B =
    SET_VIEW_PROPERTIES + L"[\\s]+" + SET_DIMENSIONS + L"[^\\s][\\s]+([^\\s]+=[^\\s]*([\\s]+[^\\s]+=[^\\s]*)*)";

const std::wstring::value_type TLogRecordParser::KEY_VALUE_SEPARATOR = L'=';
const std::wstring::value_type TLogRecordParser::TOKEN_SEPARATOR = L' ';

namespace TLogRecordParserCreators {

/**
 * The CallStartedRecordCreator class implements a Call Started Record Creator.
 */
class CallStartedRecordCreator final {
public:
    /**
     * The CallStartedRecordCreator constructor.
     */
    explicit CallStartedRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser) 
    {
    }

    /**
     * The CallStartedRecordCreator constructor.
     */
    virtual ~CallStartedRecordCreator() 
    {
    }

    /**
     * Creates a Call Started Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseCallStartedRecord(content, regex, record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

/**
 * The CallEndedRecordCreator class implements a Call Ended Record Creator.
 */
class CallEndedRecordCreator final {
public:
    /**
     * The CallEndedRecordCreator constructor.
     */
    explicit CallEndedRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser) 
    {
    }

    /**
     * The CallEndedRecordCreator constructor.
     */
    virtual ~CallEndedRecordCreator() 
    {
    }

    /**
     * Creates a Call Ended Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseCallEndedRecord(content, regex, record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

/**
 * The CompositorCreatedRecordCreator class implements a Compositor Created Record Creator.
 */
class CompositorCreatedRecordCreator final {
public:
    /**
     * The CompositorCreatedRecordCreator constructor.
     */
    explicit CompositorCreatedRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser) 
    {
    }

    /**
     * The CompositorCreatedRecordCreator constructor.
     */
    virtual ~CompositorCreatedRecordCreator() 
    {
    }

    /**
     * Creates a Compositor Created Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseCompositorCreatedRecord(
            content, 
            regex, 
            record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

/**
 * The CompositorDestroyedRecordCreator class implements a Compositor Destroyed Record Creator.
 */
class CompositorDestroyedRecordCreator final {
public:
    /**
     * The CompositorDestroyedRecordCreator constructor.
     */
    explicit CompositorDestroyedRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser) 
    {
    }

    /**
     * The CompositorDestroyedRecordCreator constructor.
     */
    virtual ~CompositorDestroyedRecordCreator() 
    {
    }

    /**
     * Creates a Compositor Destroyed Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseCompositorDestroyedRecord(
            content, 
            regex, 
            record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

/**
 * The AddViewRecordCreator class implements an Add View Record Creator.
 */
class AddViewRecordCreator final {
public:
    /**
     * The AddViewRecordCreator constructor.
     */
    explicit AddViewRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser) 
    {
    }

    /**
     * The AddViewRecordCreator constructor.
     */
    virtual ~AddViewRecordCreator()
    {
    }

    /**
     * Creates an Add View Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseAddViewRecord(
            content, 
            regex, 
            record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

/**
 * The RemoveViewRecordCreator class implements a Remove View Record Creator.
 */
class RemoveViewRecordCreator final {
public:
    /**
     * The RemoveViewRecordCreator constructor.
     */
    explicit RemoveViewRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser) 
    {
    }

    /**
     * The RemoveViewRecordCreator constructor.
     */
    virtual ~RemoveViewRecordCreator() 
    {
    }

    /**
     * Creates a Remove View Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseRemoveViewRecord(
            content, 
            regex, 
            record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

/**
 * The SetConfigurationRecordCreator class implements a Set Configuration Record Creator.
 */
class SetConfigurationRecordCreator final {
public:
    /**
     * The SetConfigurationRecordCreator constructor.
     */
    explicit SetConfigurationRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser) 
    {
    }

    /**
     * The SetConfigurationRecordCreator constructor.
     */
    virtual ~SetConfigurationRecordCreator() 
    {
    }

    /**
     * Creates a Set Configuration Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseSetConfigurationRecord(
            content, 
            regex, 
            record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

/**
 * The SetViewPropertiesRecordCreator class implements a Set View Properties Record Creator.
 */
class SetViewPropertiesRecordCreator final {
public:
    /**
     * The SetViewPropertiesRecordCreator constructor.
     */
    explicit SetViewPropertiesRecordCreator(const ITLogRecordParser& recordParser) : 
        m_recordParser(recordParser)
    {
    }

    /**
     * The SetViewPropertiesRecordCreator constructor.
     */
    virtual ~SetViewPropertiesRecordCreator() 
    {
    }

    /**
     * Creates a Set View Properties Record.
     */
    ITLogRecordSharedPtr operator()(
        const std::wstring& content, 
        const std::wstring& regex,
        const logging::ILogRecordSharedPtr record)
    {
        return m_recordParser.ParseSetViewPropertiesRecord(
            content, 
            regex, 
            record);
    }

private:
    const ITLogRecordParser& m_recordParser;
};

}  // namespace TLogRecordParserCreators

/**
 * Creates a TLog Parser.
 */
ITLogRecordParserSharedPtr TLogRecordParser::Make()
{
    return std::make_shared<TLogRecordParser>();
}

/**
 * The TLogRecordParser constructor.
 */
TLogRecordParser::TLogRecordParser() : 
    m_loggers(logging::Loggers::Make(typeid(tlogging::TLogRecordParser)))
{
    //
    // Create a mapping between a record regex to a record type...
    //
    CreateRecordRegexToTypeMap(m_recordRegexToRecordTypeMap);

    //
    // Create a mapping between a record type to a record creator...
    //
    CreateRecordTypeToCreatorMap(m_recordTypeToRecordCreatorMap);
}

/**
 * The TLogRecordParser destructor.
 */
TLogRecordParser::~TLogRecordParser() 
{
}

/**
 * Parses a TLog record.
 */
ITLogRecordSharedPtr TLogRecordParser::Parse(const logging::ILogRecordSharedPtr record) const
{
    std::wstring content = record->GetLoggingMessage();
    std::wstring optimizedContent;

    TryOptimizeContent(
        content, 
        optimizedContent);

    TLogRecordType recordType;
    std::wstring matchingRegex;

    bool status = ParseRecordType(
        optimizedContent, 
        recordType, 
        matchingRegex);

    if (!status) {
        return nullptr;
    }

    ITLogRecordSharedPtr tLogRecord = Parse(
        optimizedContent,
        recordType, 
        matchingRegex, 
        record);

    return tLogRecord;
}

/**
 * Parses a TLog record.
 */
ITLogRecordSharedPtr TLogRecordParser::Parse(
    const std::wstring& content,
    TLogRecordType recordType, 
    const std::wstring& matchingRegex,
    const logging::ILogRecordSharedPtr record) const
{
    //
    // Find the corresponding record creator...
    //
    RecordTypeToRecordCreatorMap::const_iterator recordCreatorIterator = 
        m_recordTypeToRecordCreatorMap.find(recordType);

    if (recordCreatorIterator == m_recordTypeToRecordCreatorMap.end()) {
        long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The TLogRecordParser has detected an unsupported record type: " << TLogRecordTypeToString(recordType)
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw TLoggingException(errorCode, errorMessage);
    }

    ITLogRecord::ICreatorFunctorSharedPtr creatorFunctor = recordCreatorIterator->second;
    return creatorFunctor->operator()(content, matchingRegex, record);
}

/**
 * Parses a type of a TLog record.
 */
bool TLogRecordParser::ParseRecordType(
    const std::wstring& content, 
    TLogRecordType& type, 
    std::wstring& matchingRegex) const
{
    matchingRegex.clear();

    //
    // Find the corresponding record type...
    //
    for (const RecordRegexToRecordTypeMap::value_type& recordRegexToType : m_recordRegexToRecordTypeMap) {
        const std::wstring& regex = recordRegexToType.first;
        const std::wregex recordRegex(regex);                

        std::wsmatch matches;
        if (std::regex_match(content, matches, recordRegex)) {
            TLogRecordType recordType = recordRegexToType.second;
            type = recordType;
            matchingRegex = regex;

            return true;
        } 
    } 
    
    return false;
}

/**
 * Parses a Call Started record.
 */
ITLogRecordSharedPtr TLogRecordParser::ParseCallStartedRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::CALL_STARTED;
    size_t numberOfTokensToParse = 5;
    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);

    std::wstring callId = tokens[0];
    std::wstring remoteUri = tokens[1];
    std::wstring callKey = tokens[2];
    std::wstring securityLevel = tokens[3];
    std::wstring bypassInformation = tokens[4];
    
    return CallStartedRecord::Make(
        callId, 
        remoteUri, 
        callKey, 
        securityLevel, 
        bypassInformation,
        record);
}

/**
 * Parses a Call Ended record.
 */
ITLogRecordSharedPtr TLogRecordParser::ParseCallEndedRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::CALL_ENDED;
    size_t numberOfTokensToParse = 0;
    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);

    return CallEndedRecord::Make(record);
}

/**
 * Parses a Compositor Created record.
 */
ITLogRecordSharedPtr TLogRecordParser::ParseCompositorCreatedRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::COMPOSITOR_CREATED;
    size_t numberOfTokensToParse = 1; 
    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);

    std::wstring compositorId = tokens[0]; 
    return CompositorCreatedRecord::Make(compositorId, record);
}

/**
 * Parses a Compositor Destroyed record.
 */
ITLogRecordSharedPtr TLogRecordParser::ParseCompositorDestroyedRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::COMPOSITOR_DESTROYED;
    size_t numberOfTokensToParse = 1;
    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);

    std::wstring compositorId = tokens[0];
    return CompositorDestroyedRecord::Make(compositorId, record);
}

/**
 * Parses an Add View record.
 */
ITLogRecordSharedPtr TLogRecordParser::ParseAddViewRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::ADD_VIEW;
    size_t numberOfTokensToParse = 6;
    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);

    size_t numOfViews = std::stol(tokens[0]);
    std::wstring viewId = tokens[1];
    int viewPositionX = std::stoi(tokens[2]);
    int viewPositionY = std::stoi(tokens[3]);
    size_t viewVolumeLength = 0; 
    size_t viewVolumeWidth = std::stol(tokens[4]);
    size_t viewVolumeHeight = std::stol(tokens[5]);
    
    base::IPositionSharedPtr<int> position = base::Position<int>::Make(
        viewPositionX, 
        viewPositionY);
    
    IVolumeSharedPtr<size_t> volume = Volume<size_t>::Make(
        viewVolumeLength, 
        viewVolumeWidth, 
        viewVolumeHeight);

    return tlogging::AddViewRecord::Make(
        viewId, 
        position, 
        volume,
        numOfViews,
        record);
}

/**
 * Parses a Remove View record.
 */
tlogging::ITLogRecordSharedPtr TLogRecordParser::ParseRemoveViewRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::REMOVE_VIEW;
    size_t numberOfTokensToParse = 2;
    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);
    
    size_t numOfViews = std::stol(tokens[0]);
    std::wstring viewId = tokens[1];

    return tlogging::RemoveViewRecord::Make(
        viewId, 
        numOfViews,
        record);
}

/**
 * Parses a Set Configuration record.
 */
ITLogRecordSharedPtr TLogRecordParser::ParseSetConfigurationRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::SET_CONFIGURATION;
    size_t numberOfTokensToParse =
        (regex == SET_CONFIGURATION_RECORD_REGEX1A) || (regex == SET_CONFIGURATION_RECORD_REGEX2A) ? 1 : 2;
    
    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);

    std::wstring propertiesTokens = tokens[0];
    ISetConfigurationRecord::PropertyMapSharedPtr properties = std::make_shared<ISetConfigurationRecord::PropertyMap>();
    ParseKeyValues(propertiesTokens, *properties);

    return tlogging::SetConfigurationRecord::Make(
        properties, 
        record);
}

/**
 * Parses a Set View Properties record.
 */
tlogging::ITLogRecordSharedPtr TLogRecordParser::ParseSetViewPropertiesRecord(
    const std::wstring& content,
    const std::wstring& regex,
    const logging::ILogRecordSharedPtr record) const
{
    TLogRecordType recordType = TLogRecordType::SET_VIEW_PROPERTIES;
    size_t numberOfTokensToParse =
        (regex == SET_VIEW_PROPERTIES_RECORD_REGEX1A) || (regex == SET_VIEW_PROPERTIES_RECORD_REGEX2A) ? 1 : 2;

    std::vector<std::wstring> tokens;

    ParseRecordTokens(
        recordType, 
        content, 
        regex, 
        numberOfTokensToParse, 
        tokens);

    std::wstring header;

    if (regex == SET_VIEW_PROPERTIES_RECORD_REGEX2A || regex == SET_VIEW_PROPERTIES_RECORD_REGEX2B) {
        header = SET_DIMENSIONS;
    }

    std::wstring propertiesTokens = tokens[0];
    ISetConfigurationRecord::PropertyMapSharedPtr properties = std::make_shared<ISetConfigurationRecord::PropertyMap>();
    ParseKeyValues(propertiesTokens, *properties);

    return SetViewPropertiesRecord::Make(
        header, 
        properties, 
        record);
}

/**
 * Creates a Record Regex to Record Type mapping.
 */
void TLogRecordParser::CreateRecordRegexToTypeMap(RecordRegexToRecordTypeMap& map)
{
    assert(map.empty());

    map.insert(std::make_pair(CALL_STARTED_RECORD_REGEX, TLogRecordType::CALL_STARTED));
    map.insert(std::make_pair(CALL_ENDED_RECORD_REGEX, TLogRecordType::CALL_ENDED));
    map.insert(std::make_pair(COMPOSITOR_CREATED_RECORD_REGEX, TLogRecordType::COMPOSITOR_CREATED));
    map.insert(std::make_pair(COMPOSITOR_DESTROYED_RECORD_REGEX, TLogRecordType::COMPOSITOR_DESTROYED));
    map.insert(std::make_pair(ADD_VIEW_RECORD_REGEX, TLogRecordType::ADD_VIEW));
    map.insert(std::make_pair(REMOVE_VIEW_RECORD_REGEX, TLogRecordType::REMOVE_VIEW));
    map.insert(std::make_pair(SET_CONFIGURATION_RECORD_REGEX1A, TLogRecordType::SET_CONFIGURATION));
    map.insert(std::make_pair(SET_CONFIGURATION_RECORD_REGEX1B, TLogRecordType::SET_CONFIGURATION));
    map.insert(std::make_pair(SET_CONFIGURATION_RECORD_REGEX2A, TLogRecordType::SET_CONFIGURATION));
    map.insert(std::make_pair(SET_CONFIGURATION_RECORD_REGEX2B, TLogRecordType::SET_CONFIGURATION));
    map.insert(std::make_pair(SET_VIEW_PROPERTIES_RECORD_REGEX1A, TLogRecordType::SET_VIEW_PROPERTIES));
    map.insert(std::make_pair(SET_VIEW_PROPERTIES_RECORD_REGEX1B, TLogRecordType::SET_VIEW_PROPERTIES));
    map.insert(std::make_pair(SET_VIEW_PROPERTIES_RECORD_REGEX2A, TLogRecordType::SET_VIEW_PROPERTIES));
    map.insert(std::make_pair(SET_VIEW_PROPERTIES_RECORD_REGEX2B, TLogRecordType::SET_VIEW_PROPERTIES));
}

/**
 * Creates a Record Type to a Record Creator mapping.
 */
void TLogRecordParser::CreateRecordTypeToCreatorMap(RecordTypeToRecordCreatorMap& map) const
{
    assert(map.empty());

    ITLogRecord::ICreatorFunctorSharedPtr callStartedRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::CallStartedRecordCreator{ *this });

    ITLogRecord::ICreatorFunctorSharedPtr callEndedRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::CallEndedRecordCreator{ *this });

    ITLogRecord::ICreatorFunctorSharedPtr compositorCreatedRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::CompositorCreatedRecordCreator{ *this });

    ITLogRecord::ICreatorFunctorSharedPtr compositorDestroyedRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::CompositorDestroyedRecordCreator{ *this });

    ITLogRecord::ICreatorFunctorSharedPtr addViewRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::AddViewRecordCreator{ *this });

    ITLogRecord::ICreatorFunctorSharedPtr removeViewRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::RemoveViewRecordCreator{ *this });

    ITLogRecord::ICreatorFunctorSharedPtr setConfigurationRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::SetConfigurationRecordCreator{ *this });

    ITLogRecord::ICreatorFunctorSharedPtr setViewPropertiesRecordFunctor =
        std::make_shared<ITLogRecord::ICreatorFunctor>(TLogRecordParserCreators::SetViewPropertiesRecordCreator{ *this });

    map.insert(std::make_pair(TLogRecordType::CALL_STARTED, callStartedRecordFunctor));
    map.insert(std::make_pair(TLogRecordType::CALL_ENDED, callEndedRecordFunctor));
    map.insert(std::make_pair(TLogRecordType::COMPOSITOR_CREATED, compositorCreatedRecordFunctor));
    map.insert(std::make_pair(TLogRecordType::COMPOSITOR_DESTROYED, compositorDestroyedRecordFunctor));
    map.insert(std::make_pair(TLogRecordType::ADD_VIEW, addViewRecordFunctor));
    map.insert(std::make_pair(TLogRecordType::REMOVE_VIEW, removeViewRecordFunctor));
    map.insert(std::make_pair(TLogRecordType::SET_CONFIGURATION, setConfigurationRecordFunctor));
    map.insert(std::make_pair(TLogRecordType::SET_VIEW_PROPERTIES, setViewPropertiesRecordFunctor));
}

/**
 * Parses tokens of a record.
 */
void TLogRecordParser::ParseRecordTokens(
    TLogRecordType recordType,
    const std::wstring& content,
    const std::wstring& regex, 
    size_t numberOfTokensToParse,
    std::vector<std::wstring>& tokens) const
{
    bool status = TryParseRecordTokens(
        recordType,
        content,
        regex, 
        numberOfTokensToParse, 
        tokens);

    if (!status) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The TLogRecordParser has failed parsing record type : " << TLogRecordTypeToString(recordType) 
            << L" with content: " << content
            << L", Total Matching : " << tokens.size() << L" / " << numberOfTokensToParse 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw TLoggingException(errorCode, errorMessage);
    }
}

/**
 * Tries to parse tokens of a record.
 */
bool TLogRecordParser::TryParseRecordTokens(
    TLogRecordType recordType, 
    const std::wstring& content, 
    const std::wstring& regex,
    size_t numberOfTokensToParse, 
    std::vector<std::wstring>& tokens) const
{
    assert(tokens.empty());
    tokens.reserve(numberOfTokensToParse);

    const std::wregex tokensRegex(regex);

    std::wsmatch matches;
    if (!std::regex_match(content, matches, tokensRegex)) {
        return false;
    }

    size_t numberOfMatching = matches.size();

    if (numberOfMatching > 0) {
        --numberOfMatching;
    }

    for (size_t index = 1; index <= numberOfMatching; ++index) {
        std::wssub_match base_sub_match = matches[index];
        std::wstring token = base_sub_match.str();

        tokens.push_back(token);
    }

    return numberOfMatching == numberOfTokensToParse;
}

/**
 * Parses key values from the following string format: { key=value key=value key=value ... } 
 */
void TLogRecordParser::ParseKeyValues(
    const std::wstring& str, 
    ISetConfigurationRecord::PropertyMap& properties,
    std::wstring::value_type keyValueSeparator,
    std::wstring::value_type tokenSeparator)
{
    if (str.size() <= 1) {
        return;
    }

    size_t startIndex = 0;
    size_t endIndex = str.size() - 1;

    while (true) {
        size_t equalIndex = str.find_first_of(keyValueSeparator, startIndex);

        if (equalIndex == std::wstring::npos) {
            break;
        }

        std::wstring key;
        std::wstring value;

        if (equalIndex > 0) {
            key = FindLeftToken(
                str, 
                startIndex, 
                equalIndex - 1, 
                tokenSeparator);
        }

        if (equalIndex < endIndex) {
            value = FindRightToken(
                str, 
                equalIndex + 1, 
                endIndex, 
                tokenSeparator);
        }

        properties.insert(std::make_pair<>(key, value));

        startIndex = equalIndex + value.size() + 1; 
    }
}

/**
 * Finds left token.
 */
std::wstring TLogRecordParser::FindLeftToken(
    const std::wstring& str, 
    size_t startIndex, 
    size_t endIndex,
    std::wstring::value_type separator)
{
    assert(startIndex < str.size());
    assert(endIndex < str.size());

    if (startIndex > endIndex || str.at(endIndex) == separator) {
        return L" ";
    }

    size_t currIndex = endIndex;

    while (currIndex >= startIndex) {
        std::wstring::value_type character = str.at(currIndex);

        if (character == separator) {
            ++currIndex;
            break;
        }

        if (currIndex == 0) {
            break;
        }

        --currIndex;
    }

    size_t tokenSize = base::Indexes::Size(currIndex, endIndex);
    return str.substr(currIndex, tokenSize);
}

/**
 * Finds right token.
 */
std::wstring TLogRecordParser::FindRightToken(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    std::wstring::value_type separator)
{
    assert(startIndex < str.size());
    assert(endIndex < str.size());

    if (startIndex > endIndex || str.at(startIndex) == separator) {
        return L" ";
    }

    size_t currIndex = startIndex;

    while (currIndex <= endIndex) {
        std::wstring::value_type character = str.at(currIndex);

        if (character == separator) {
            --currIndex;
            break;
        }

        ++currIndex;
    }

    size_t tokenSize = base::Indexes::Size(startIndex, currIndex);
    return str.substr(startIndex, tokenSize);
}

/**
 * Tries to optimizes content.
 */
bool TLogRecordParser::TryOptimizeContent(
    const std::wstring& str, 
    std::wstring& result)
{
    assert(result.empty());
    result = L"";

    bool status = false;

    std::wstring inputStr = str;
    std::wstring outputStr;

    if (base::StringUtils::StartWith(str, COMPOSITOR_CREATED)) {
        status = StripRecordPrefixes(inputStr, COMPOSITOR_CREATED, outputStr);
    } 
    else if (base::StringUtils::StartWith(str, COMPOSITOR_DESTROYED)) {
        status = StripRecordPrefixes(inputStr, COMPOSITOR_DESTROYED, outputStr);
    } 
    else if (base::StringUtils::StartWith(str, ADD_VIEW)) {
        status = StripRecordPrefixes(inputStr, ADD_VIEW, outputStr);
    } 
    else if (base::StringUtils::StartWith(str, REMOVE_VIEW)) {
        status = StripRecordPrefixes(inputStr, REMOVE_VIEW, outputStr);
    }
    else if (base::StringUtils::StartWith(str, SET_CONFIGURATION)) {
        
        bool status1 = StripRecordPrefixes(inputStr, SET_CONFIGURATION, outputStr);
        status |= status1;

        inputStr = outputStr;
        outputStr = L"";

        bool status2 = base::StringUtils::StripSpacesBetweenParentheses(inputStr, outputStr);
        status |= status2;
    } 
    else if (base::StringUtils::StartWith(str, SET_VIEW_PROPERTIES)) {
        bool status1 = StripRecordPrefixes(inputStr, SET_VIEW_PROPERTIES, outputStr);
        status |= status1;

        inputStr = outputStr;
        outputStr = L"";

        bool status2 = base::StringUtils::EraseAll(inputStr, L',', outputStr);
        status |= status2;
    } 
    else {
        outputStr = inputStr;
    }

    result = outputStr;
    return status;
}

/**
 * Strips prefixes from the content of record.
 * Returns false if no prefix is found.
 */
bool TLogRecordParser::StripRecordPrefixes(
    const std::wstring& content, 
    const std::wstring& header, 
    std::wstring& result,
    const std::vector<std::wstring>& prefixes)
{
    assert(result.empty());
    result = L"";

    size_t currIndex = header.size();
    const std::wstring* matchingPrefix = nullptr;

    for (const std::wstring& prefix : prefixes) {
        
        if (base::StringUtils::StartWith(
                content, 
                prefix, 
                currIndex)) {
            
            matchingPrefix = &prefix;
            break;
        }
    }

    if (matchingPrefix == nullptr) {
        result = content;
        return false;
    }

    std::vector<std::wstring::value_type> buffer;
    buffer.reserve(content.size() - matchingPrefix->size());

    buffer.insert(
        buffer.end(), 
        header.begin(), 
        header.end());

    currIndex += matchingPrefix->size();

    buffer.insert(buffer.end(), content.begin() + currIndex, content.end());
    result.assign(buffer.begin(), buffer.end());

    return true;
}
