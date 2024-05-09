#ifndef I_TREE_NODE_H_ca8d8f0d_cc8f_4423_8f9e_e05b2248a33e
#define I_TREE_NODE_H_ca8d8f0d_cc8f_4423_8f9e_e05b2248a33e

#include <memory>
#include <vector>

namespace datastructures {

    namespace tree {

         /**
         * The ITreeNode interface defines a tree node.
         */
        template <typename TKey, typename TValue>
        class ITreeNode {
        public:
            //
            // Defines the children of a node...
            //
            using Children = std::vector<std::shared_ptr<ITreeNode<TKey, TValue>>>;

            ITreeNode() = default;
            virtual ~ITreeNode() = default;

            /**
             * Gets a key of a node.
             */
            virtual const TKey& GetKey() const = 0;

            /**
             * Gets a value of a node.
             */
            virtual const TValue& GetValue() const = 0;

            /**
             * Sets a value of a node.
             */
            virtual void SetValue(const TValue& value) = 0;

            /**
             * Adds a child to the node.
             */
            virtual void AddChild(std::shared_ptr<ITreeNode<TKey, TValue>> child) = 0;

            /**
             * Deletes a child from the node.
             * Returns true if child has been deleted.
             */
            virtual bool DeleteChild(const TKey& key) = 0;

            /**
             * Gets a child.
             */
            virtual std::shared_ptr<ITreeNode<TKey, TValue>> GetChild(const TKey& key) = 0;

            /**
             * Gets a child.
             */
            virtual const std::shared_ptr<ITreeNode<TKey, TValue>> GetChild(const TKey& key) const = 0;

            /**
             * Checks whether a child exists.
             */
            virtual bool HasChild(const TKey& key) const = 0;

            /**
             * Gets list of children.
             */
            virtual void GetChildren(typename ITreeNode<TKey, TValue>::Children& children) const = 0;
        };

        /**
         * Defines the Shared Ptr of ITreeNode.
         */
        template <typename TKey, typename TValue>
        using ITreeNodeSharedPtr = std::shared_ptr<ITreeNode<TKey, TValue>>;

    } // namespace tree

} // namespace datastructures

#endif // I_TREE_NODE_H_ca8d8f0d_cc8f_4423_8f9e_e05b2248a33e
