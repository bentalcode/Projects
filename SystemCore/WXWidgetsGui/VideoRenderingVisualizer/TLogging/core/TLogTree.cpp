#include "TLogTree.h"
#include "ErrorCodes.h"
#include "Loggers.h"
#include "TLoggingException.h"

using namespace tlogging;

/**
 * Creates a TLogTree.
 */
ITLogTreeSharedPtr TLogTree::Make() 
{
    return std::make_shared<TLogTree>();
}

/**
 * The TLogTree constructor.
 */
TLogTree::TLogTree() : 
    m_loggers(logging::Loggers::Make(typeid(TLogTree)))
{
}

/**
 * The TLogTree destructor.
 */
TLogTree::~TLogTree() 
{
}

/**
 * Gets a TLog Record Tree.
 */
const ITLogTree::ITLogRecordTreeSharedPtr TLogTree::GetTLogRecordTree(TLogRecordType type) const
{ 
    TLogRecordTypeToTreeMap::const_iterator logRecordIterator = m_logRecordTreeLookup.find(type);
    
    if (logRecordIterator == m_logRecordTreeLookup.end()) {
        long errorCode = base::ErrorCodes::RESOURCE_TEMPLATE_NOT_FOUND;
        
        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The TLogRecordTree of type: " << TLogRecordTypeToString(type) 
            << L" does not exist in the TLogTree" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw TLoggingException(errorCode, errorMessage);
    }
    
    return logRecordIterator->second;
}

/**
 * Creates a TLog Record Tree.
 */
ITLogTree::ITLogRecordTreeSharedPtr TLogTree::CreateTLogRecordTree(TLogRecordType type)
{
    ITLogRecordTreeSharedPtr tree = TLogRecordTree::Make();
    std::wstring name = TLogRecordTypeToString(type);
    const ITLogRecord* record = nullptr;
    ITLogRecordTreeNodeSharedPtr root = TLogRecordTreeNode::Make(name, record);
    tree->SetRoot(root);

    m_logRecordTreeLookup.insert(std::make_pair(type, tree));
    return tree;
}

/**
 * Checks whether a TLog Record Tree exists.
 */
bool TLogTree::HasTLogRecordTree(TLogRecordType type) const 
{
    return m_logRecordTreeLookup.find(type) != m_logRecordTreeLookup.end();
}
