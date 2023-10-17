#ifndef KEY_ITERATOR_H_b93f1ed7_f3fd_46a5_93e5_c56ffb31a223
#define KEY_ITERATOR_H_b93f1ed7_f3fd_46a5_93e5_c56ffb31a223

#include "IIterator.h"
#include "IKeyValueNode.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace node {

        /**
         * The KeyIterator class implements an iterator of keys from key-value nodes.
         */
        template <typename TKey, typename TValue>
        class KeyIterator final : public base::IIterator<TKey>
        {
        public:
            /**
             * Creates a new iterator of keys from key value nodes.
             */
            static base::IIteratorSharedPtr<TKey> Make(
                base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator);

            /**
             * The KeyIterator constructor.
             */
            explicit KeyIterator(base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator);

            /**
             * The KeyIterator destructor.
             */
            virtual ~KeyIterator();

            /**
             * The Copy/move constructors.
             */
            KeyIterator(const KeyIterator&) = delete;
            KeyIterator(KeyIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            KeyIterator& operator=(const KeyIterator&) = delete;
            KeyIterator& operator=(KeyIterator&&) = delete;

            /**
             * Checks whether there is a Next node.
             */
            virtual bool HasNext() const override;

            /**
             * Gets the Next node.
             */
            virtual TKey Next() override;

            /**
             * Resets the iterator.
             */
            virtual void Reset() override;

        private:
            base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> m_iterator;
        };

        /**
         * Creates a new iterator of keys from key value nodes.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<TKey> KeyIterator<TKey, TValue>::Make(
            base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator)
        {
            return std::make_shared<KeyIterator<TKey, TValue>>(iterator);
        }

        /**
         * The KeyIterator constructor.
         */
        template <typename TKey, typename TValue>
        KeyIterator<TKey, TValue>::KeyIterator(base::IIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> iterator) :
            m_iterator(iterator)
        {
            base::SmartPointers::Validate<base::IIterator<IKeyValueNodeSharedPtr<TKey, TValue>>>(iterator);
            Reset();
        }

        /**
         * The KeyIterator destructor.
         */
        template <typename TKey, typename TValue>
        KeyIterator<TKey, TValue>::~KeyIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename TKey, typename TValue>
        bool KeyIterator<TKey, TValue>::HasNext() const
        {
            return m_iterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename TKey, typename TValue>
        TKey KeyIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            return m_iterator->Next()->GetKey();
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void KeyIterator<TKey, TValue>::Reset()
        {
            m_iterator->Reset();
        }
    }
}

#endif // KEY_ITERATOR_H_b93f1ed7_f3fd_46a5_93e5_c56ffb31a223
