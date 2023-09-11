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
            static base::IIteratorPtr<TKey> make(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator);

            /**
             * The KeyIterator constructor.
             */
            explicit KeyIterator(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator);

            /**
             * The KeyIterator destructor.
             */
            virtual ~KeyIterator();

            /**
             * The copy/move constructors.
             */
            KeyIterator(const KeyIterator&) = delete;
            KeyIterator(KeyIterator&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            KeyIterator& operator=(const KeyIterator&) = delete;
            KeyIterator& operator=(KeyIterator&&) = delete;

            /**
             * Checks whether there is a next node.
             */
            virtual bool hasNext() const override;

            /**
             * Gets the next node.
             */
            virtual TKey next() override;

            /**
             * Resets the iterator.
             */
            virtual void reset() override;

        private:
            base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> m_iterator;
        };

        /**
         * Creates a new iterator of keys from key value nodes.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<TKey> KeyIterator<TKey, TValue>::make(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator)
        {
            return std::make_shared<KeyIterator<TKey, TValue>>(iterator);
        }

        /**
         * The KeyIterator constructor.
         */
        template <typename TKey, typename TValue>
        KeyIterator<TKey, TValue>::KeyIterator(base::IIteratorPtr<IKeyValueNodePtr<TKey, TValue>> iterator) :
            m_iterator(iterator)
        {
            base::SmartPointers::validate(iterator);
            reset();
        }

        /**
         * The KeyIterator destructor.
         */
        template <typename TKey, typename TValue>
        KeyIterator<TKey, TValue>::~KeyIterator()
        {
        }

        /**
         * Checks whether there is a next node.
         */
        template <typename TKey, typename TValue>
        bool KeyIterator<TKey, TValue>::hasNext() const
        {
            return m_iterator->hasNext();
        }

        /**
         * Gets the next node.
         */
        template <typename TKey, typename TValue>
        TKey KeyIterator<TKey, TValue>::next()
        {
            assert(hasNext());

            return m_iterator->next()->getKey();
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void KeyIterator<TKey, TValue>::reset()
        {
            m_iterator->reset();
        }
    }
}

#endif // KEY_ITERATOR_H_b93f1ed7_f3fd_46a5_93e5_c56ffb31a223
