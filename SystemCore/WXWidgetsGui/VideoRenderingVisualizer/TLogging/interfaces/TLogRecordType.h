#ifndef TLOG_RECORD_TYPE_7a654031_eb37_4983_ada7_9b60da75ea82
#define TLOG_RECORD_TYPE_7a654031_eb37_4983_ada7_9b60da75ea82

namespace tlogging {

    /**
     * The TLogRecordType class defines various types of TLog records.
     */
    enum class TLogRecordType {
        CALL_STARTED,
        CALL_ENDED,
        COMPOSITOR_CREATED,
        COMPOSITOR_DESTROYED,
        ADD_VIEW,
        REMOVE_VIEW,
        SET_CONFIGURATION,
        SET_VIEW_PROPERTIES
    };

    /**
     * Translates a TLogRecordType to a String.
     */
    inline static std::wstring TLogRecordTypeToString(TLogRecordType recordType) {
        std::wstring result;

        if (recordType == TLogRecordType::COMPOSITOR_CREATED)
        {
            return L"Compositor Created";
        }
        else if (recordType == TLogRecordType::COMPOSITOR_DESTROYED) {
            return L"Compositor Destroyed";
        }
        else if (recordType == TLogRecordType::ADD_VIEW) {
            return L"Add View";
        }
        else if (recordType == TLogRecordType::REMOVE_VIEW) {
            return L"Remove View";
        }
        else if (recordType == TLogRecordType::SET_CONFIGURATION) {
            return L"Set Configuration";
        }

        return result;
    }

} // namespace tlogging

#endif // TLOG_RECORD_TYPE_7a654031_eb37_4983_ada7_9b60da75ea82
