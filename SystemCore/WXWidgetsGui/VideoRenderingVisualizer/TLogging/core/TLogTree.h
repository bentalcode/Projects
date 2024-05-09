#ifndef TLOG_TREE_H_aa50f478_04ff_457e_909c_fd5dc433dafb
#define TLOG_TREE_H_aa50f478_04ff_457e_909c_fd5dc433dafb

#include "ITLogTree.h"
#include "TLogRecordType.h"
#include "ILoggers.h"
#include <map>

namespace tlogging {

    /**
     * The TLogTree class implements a TLog Tree.
     */
    class TLogTree final : public ITLogTree {
    public:
        /**
         * Creates a TLog Tree.
         */
        static ITLogTreeSharedPtr Make();

        /**
         * The TLogTree constructor.
         */
        TLogTree();

        /**
         * The TLogTree destructor.
         */
        virtual ~TLogTree();

        /**
         * Gets a TLog Record Tree.
         */
        virtual const ITLogTree::ITLogRecordTreeSharedPtr GetTLogRecordTree(TLogRecordType type) const override;

        /**
         * Creates a TLog Record Tree.
         */
        virtual ITLogTree::ITLogRecordTreeSharedPtr CreateTLogRecordTree(TLogRecordType type) override;

        /**
         * Checks whether a TLog Record Tree exists.
         */
        virtual bool HasTLogRecordTree(TLogRecordType type) const override;

    private:
        using TLogRecordTypeToTreeMap = std::map<TLogRecordType, ITLogTree::ITLogRecordTreeSharedPtr>;
        TLogRecordTypeToTreeMap m_logRecordTreeLookup;

        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace tlogging

#endif // TLOG_TREE_H_aa50f478_04ff_457e_909c_fd5dc433dafb
