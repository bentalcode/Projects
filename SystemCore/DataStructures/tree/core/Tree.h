#ifndef TREE_H_ac6e19cf_3a83_4773_ba0c_30f1d5e579ea
#define TREE_H_ac6e19cf_3a83_4773_ba0c_30f1d5e579ea

#include "ITree.h"
#include "SmartPointers.h"

namespace datastructures {

    namespace tree {

        /**
         * The Tree class implements a tree.
         */
        template <typename TKey, typename TValue>
        class Tree final : public ITree<TKey, TValue> {
        public:
            /**
             * Creates a new instance of a tree.
             */
            static ITreeSharedPtr<TKey, TValue> Make();

            /**
             * The Tree constructor.
             */
            Tree();

            /**
             * The Tree destructor.
             */
            virtual ~Tree();

            /**
             * Gets a root of a tree.
             */
            virtual ITreeNodeSharedPtr<TKey, TValue> GetRoot() override;

            /**
             * Gets a root of a tree.
             */
            virtual const ITreeNodeSharedPtr<TKey, TValue> GetRoot() const override;

            /**
             * Sets a root of a tree.
             */
            virtual void SetRoot(ITreeNodeSharedPtr<TKey, TValue> root) override;

            /**
             * Finds a node by path.
             */
            virtual const ITreeNodeSharedPtr<TKey, TValue> FindNode(const std::vector<TKey>& path) const override;

            /**
             * Deletes a node by path.
             * Returns true in case a node has been deleted.
             */
            virtual bool DeleteNode(const std::vector<TKey>& path) const override;

        private:
            ITreeNodeSharedPtr<TKey, TValue> m_root;
        };

        /**
         * Creates a new instance of a tree.
         */
        template <typename TKey, typename TValue>
        ITreeSharedPtr<TKey, TValue> Tree<TKey, TValue>::Make()
        {
            return std::make_shared<Tree<TKey, TValue>>();
        }

        /**
         * The Tree constructor.
         */
        template <typename TKey, typename TValue>
        Tree<TKey, TValue>::Tree()
        {
        }

        /**
         * The Tree destructor.
         */
        template <typename TKey, typename TValue>
        Tree<TKey, TValue>::~Tree()
        {
        }

        /**
         * Gets a root of a tree.
         */
        template <typename TKey, typename TValue>
        ITreeNodeSharedPtr<TKey, TValue> Tree<TKey, TValue>::GetRoot()
        {
            return m_root;
        }

        /**
         * Gets a root of a tree.
         */
        template <typename TKey, typename TValue>
        const ITreeNodeSharedPtr<TKey, TValue> Tree<TKey, TValue>::GetRoot() const
        {
            return m_root;
        }

        /**
         * Sets a root of a tree.
         */
        template <typename TKey, typename TValue>
        void Tree<TKey, TValue>::SetRoot(ITreeNodeSharedPtr<TKey, TValue> root)
        {
            base::SmartPointers::Validate<ITreeNode<TKey, TValue>>(root);
            m_root = root;
        }

        /**
         * Finds a node by path.
         */
        template <typename TKey, typename TValue>
        const ITreeNodeSharedPtr<TKey, TValue> Tree<TKey, TValue>::FindNode(const std::vector<TKey>& path) const
        {
            if (m_root == nullptr) {
                return nullptr;
            }

            ITreeNodeSharedPtr<TKey, TValue> currNode = m_root;
            size_t index = 0;

            while (currNode != nullptr) {
                const std::wstring& currKey = path.at(index);

                if (!currNode->HasChild(currKey)) {
                    return nullptr;
                }

                currNode = currNode->GetChild(currKey);

                if (index == path.size() - 1) {
                    return currNode;
                }

                ++index;
            }

            return nullptr;
        }

        /**
         * Deletes a node by path.
         * Returns true in case a node has been deleted.
         */
        template <typename TKey, typename TValue>
        bool Tree<TKey, TValue>::DeleteNode(const std::vector<TKey>& path) const {
            if (path.empty()) {
                return false;
            }

            ITreeNodeSharedPtr<TKey, TValue> currNode = m_root;
            size_t index = 0;

            while (currNode != nullptr) {
                const std::wstring& currKey = path.at(index);

                if (!currNode->HasChild(currKey)) {
                    return false;
                }

                if (index == path.size() - 1) {
                    currNode->DeleteChild(currKey);
                    return true;
                }

                currNode = currNode->GetChild(currKey);
                ++index;
            }

            return true;
        }

    } // namespace tree

} // namespace datastructures

#endif // TREE_H_ac6e19cf_3a83_4773_ba0c_30f1d5e579ea
