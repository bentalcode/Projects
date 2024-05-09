#ifndef I_TLOG_TREE_H_b63f1126_350b_417a_811c_ac08e3bb1252
#define I_TLOG_TREE_H_b63f1126_350b_417a_811c_ac08e3bb1252

#include "ITLogRecord.h"
#include "TLogRecordType.h"
#include "Tree.h"
#include "TreeNode.h"
#include <memory>

namespace tlogging {

    /**
     * The ITLogTree interface defines a TLog Tree.
     */
    class ITLogTree {
    public:
        ITLogTree() = default;
        virtual ~ITLogTree() = default;

        //
        // Defines the tree of specific TLog Records...
        //
        using ITLogRecordTree = datastructures::tree::ITree<std::wstring, const ITLogRecord*>;
        using TLogRecordTree = datastructures::tree::Tree<std::wstring, const ITLogRecord*>;
        using ITLogRecordTreeSharedPtr = datastructures::tree::ITreeSharedPtr<std::wstring, const ITLogRecord*>;

        using ITLogRecordTreeNode = datastructures::tree::ITreeNode<std::wstring, const ITLogRecord*>;
        using TLogRecordTreeNode = datastructures::tree::TreeNode<std::wstring, const ITLogRecord*>;
        using ITLogRecordTreeNodeSharedPtr = datastructures::tree::ITreeNodeSharedPtr<std::wstring, const ITLogRecord*>;

        /**
         * Gets a TLog Record Tree.
         */
        virtual const ITLogRecordTreeSharedPtr GetTLogRecordTree(TLogRecordType type) const = 0;

        /**
         * Creates a TLog Record Tree.
         */
        virtual ITLogRecordTreeSharedPtr CreateTLogRecordTree(TLogRecordType type) = 0;

        /**
         * Checks whether a TLog Record Tree exists.
         */
        virtual bool HasTLogRecordTree(TLogRecordType type) const = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Tree.
     */
    using ITLogTreeSharedPtr = std::shared_ptr<ITLogTree>;

} // namespace tlogging

#endif // I_TLOG_TREE_H_b63f1126_350b_417a_811c_ac08e3bb1252
