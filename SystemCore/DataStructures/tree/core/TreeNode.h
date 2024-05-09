#ifndef TREE_NODE_H_394a2d87_5461_4eef_92a2_24d199868dad
#define TREE_NODE_H_394a2d87_5461_4eef_92a2_24d199868dad

#include "ITreeNode.h"
#include "SmartPointers.h"
#include <map>
#include <assert.h>
#include "TreeException.h"

namespace datastructures {

    namespace tree {

        /**
         * The TreeNode class implements a tree node.
         */
        template <typename TKey, typename TValue>
        class TreeNode final : ITreeNode<TKey, TValue> {
        public:
            /**
             * Creates a new instance of a node.
             */
            static ITreeNodeSharedPtr<TKey, TValue> Make(
                const TKey& key,
                TValue& value);

            /**
             * The TreeNode constructor.
             */
            TreeNode(
                const TKey& key,
                TValue& value);

            /**
             * The TreeNode destructor.
             */
            virtual ~TreeNode();

            /**
             * Gets a key of a node.
             */
            virtual const TKey& GetKey() const override;

            /**
             * Gets a value of a node.
             */
            virtual const TValue& GetValue() const override;

            /**
             * Sets a value of a node.
             */
            virtual void SetValue(const TValue& value) override;

            /**
             * Adds a child to the node.
             */
            virtual void AddChild(ITreeNodeSharedPtr<TKey, TValue> child) override;

            /**
             * Deletes a child from the node.
             * Returns true if child has been deleted.
             */
            virtual bool DeleteChild(const TKey& key) override;

            /**
             * Gets a child.
             */
            virtual ITreeNodeSharedPtr<TKey, TValue> GetChild(const TKey& key) override;

            /**
             * Gets a child.
             */
            virtual const ITreeNodeSharedPtr<TKey, TValue> GetChild(const TKey& key) const override;

            /**
             * Checks whether a child exists.
             */
            virtual bool HasChild(const TKey& key) const override;

            /**
             * Gets list of children.
             */
            virtual void GetChildren(typename ITreeNode<TKey, TValue>::Children& children) const override;

        private:
            TKey m_key;
            TValue m_value;

            using ChildrenMap = std::map<TKey, ITreeNodeSharedPtr<TKey, TValue>>;
            ChildrenMap m_children;
        };

        /**
         * Creates a new instance of a tree node.
         */
        template <typename TKey, typename TValue>
        ITreeNodeSharedPtr<TKey, TValue> TreeNode<TKey, TValue>::Make(
            const TKey& key,
            TValue& value)
        {
            return ITreeNodeSharedPtr<TKey, TValue>(static_cast<ITreeNode<TKey, TValue>*>(new TreeNode<TKey, TValue>(key, value)));
        }

        /**
         * The TreeNode constructor.
         */
        template <typename TKey, typename TValue>
        TreeNode<TKey, TValue>::TreeNode(const TKey& key, TValue& value) :
            m_key(key),
            m_value(value)
        {
        }

        /**
         * The TreeNode destructor.
         */
        template <typename TKey, typename TValue>
        TreeNode<TKey, TValue>::~TreeNode()
        {
        }

        /**
         * Gets a key of a node.
         */
        template <typename TKey, typename TValue>
        const TKey& TreeNode<TKey, TValue>::GetKey() const
        {
            return m_key;
        }

        /**
         * Gets a value of a node.
         */
        template <typename TKey, typename TValue>
        const TValue& TreeNode<TKey, TValue>::GetValue() const
        {
            return m_value;
        }

        /**
         * Sets a value of a node.
         */
        template <typename TKey, typename TValue>
        void TreeNode<TKey, TValue>::SetValue(const TValue& value)
        {
            m_value = value;
        }

        /**
         * Adds a child to the node.
         */
        template <typename TKey, typename TValue>
        void TreeNode<TKey, TValue>::AddChild(ITreeNodeSharedPtr<TKey, TValue> child)
        {
            base::SmartPointers::Validate<ITreeNode<TKey, TValue>>(child);

            const TKey& key = child->GetKey();

            if (HasChild(key)) {
                long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;
                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"The child: " << key << L" already exists in the current node"
                    << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();
                throw TreeException(errorCode, errorMessage);
            }

            m_children.insert(std::make_pair(key, child));
        }

        /**
         * Deletes a child from the node.
         * Returns true if child has been deleted.
         */
        template <typename TKey, typename TValue>
        bool TreeNode<TKey, TValue>::DeleteChild(const TKey& key)
        {
            if (!HasChild(key)) {
                return false;
            }

            m_children.erase(key);

            return true;
        }

        /**
         * Gets a child.
         */
        template <typename TKey, typename TValue>
        ITreeNodeSharedPtr<TKey, TValue> TreeNode<TKey, TValue>::GetChild(const TKey& key)
        {
            if (!HasChild(key)) {
                long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"The child: " << key << L" does not exist in the current node"
                    << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();
                throw TreeException(errorCode, errorMessage);
            }

            typename ChildrenMap::const_iterator childIterator = m_children.find(key);

            return childIterator->second;
        }

        /**
         * Gets a child.
         */
        template <typename TKey, typename TValue>
        const ITreeNodeSharedPtr<TKey, TValue> TreeNode<TKey, TValue>::GetChild(const TKey& key) const
        {
            TreeNode<TKey, TValue>& thisInstance = const_cast<TreeNode<TKey, TValue>&>(*this);
            return thisInstance.GetChild(key);
        }

        /**
         * Checks whether a child exists.
         */
        template <typename TKey, typename TValue>
        bool TreeNode<TKey, TValue>::HasChild(const TKey& key) const
        {
            return m_children.find(key) != m_children.end();
        }

        /**
         * Gets list of childrens.
         */
        template <typename TKey, typename TValue>
        void TreeNode<TKey, TValue>::GetChildren(typename ITreeNode<TKey, TValue>::Children& children) const
        {
            assert(children.empty());
            children.reserve(m_children.size());

            for (typename ChildrenMap::const_iterator childIterator = m_children.begin();
                 childIterator != m_children.end();
                 ++childIterator) {

                const ITreeNodeSharedPtr<TKey, TValue>& child = childIterator->second;
                children.push_back(child);
            }
        }

    } // namespace tree

} // namespace datastructures

#endif // TREE_NODE_H_394a2d87_5461_4eef_92a2_24d199868dad
