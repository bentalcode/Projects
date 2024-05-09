#ifndef I_TREE_H_16533c18_1527_42cf_9009_fad176082709
#define I_TREE_H_16533c18_1527_42cf_9009_fad176082709

#include "ITreeNode.h"

namespace datastructures {

     namespace tree {

        /**
         * The ITree interface defines a tree.
         */
        template <typename TKey, typename TValue>
        class ITree {
        public:
            ITree() = default;
            virtual ~ITree() = default;

            /**
             * Gets a root of a tree.
             */
            virtual ITreeNodeSharedPtr<TKey, TValue> GetRoot() = 0;

            /**
             * Gets a root of a tree.
             */
            virtual const ITreeNodeSharedPtr<TKey, TValue> GetRoot() const = 0;

            /**
             * Sets a root of a tree.
             */
            virtual void SetRoot(ITreeNodeSharedPtr<TKey, TValue> root) = 0;

            /**
             * Finds a node by path.
             */
            virtual const ITreeNodeSharedPtr<TKey, TValue> FindNode(const std::vector<TKey>& path) const = 0;

            /**
             * Deletes a node by path.
             * Returns true in case a node has been deleted.
             */
            virtual bool DeleteNode(const std::vector<TKey>& path) const = 0;
        };

        /**
         * Defines the Shared Ptr of Tree.
         */
        template <typename TKey, typename TValue>
        using ITreeSharedPtr = std::shared_ptr<ITree<TKey, TValue>>;

    } // namespace tree

} // namespace datastructures

#endif // I_TREE_H_16533c18_1527_42cf_9009_fad176082709

