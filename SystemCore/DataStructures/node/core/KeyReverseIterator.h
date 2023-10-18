#ifndef KEY_REVERSE_ITERATOR_H_499d0208_fc40_4746_ae72_69b73b57d80b
#define KEY_REVERSE_ITERATOR_H_499d0208_fc40_4746_ae72_69b73b57d80b

#include "IReverseIterator.h"
#include "IKeyValueNode.h"
#include "SmartPointers.h"

namespace datastructures {
    namespace node {

        /**
         * The KeyReverseIterator class implements a reverse iterator of keys from key-value nodes.
         */
        template <typename TKey, typename TValue>
        class KeyReverseIterator final : public base::IReverseIterator<TKey>
        {
        public:
            /**
             * Creates a new reverse iterator of keys from key value nodes.
             */
            static base::IReverseIteratorSharedPtr<TKey> Make(
                base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator);

            /**
             * The KeyReverseIterator constructor.
             */
            explicit KeyReverseIterator(base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator);

            /**
             * The KeyReverseIterator destructor.
             */
            virtual ~KeyReverseIterator();

            /**
             * The Copy/move constructors.
             */
            KeyReverseIterator(const KeyReverseIterator&) = delete;
            KeyReverseIterator(KeyReverseIterator&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            KeyReverseIterator& operator=(const KeyReverseIterator&) = delete;
            KeyReverseIterator& operator=(KeyReverseIterator&&) = delete;

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
            base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> m_reverseIterator;
        };

        /**
         * Creates a new reverse iterator of keys from key value nodes.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<TKey> KeyReverseIterator<TKey, TValue>::Make(
            base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator)
        {
            return std::make_shared<KeyReverseIterator<TKey, TValue>>(reverseIterator);
        }

        /**
         * The KeyReverseIterator constructor.
         */
        template <typename TKey, typename TValue>
        KeyReverseIterator<TKey, TValue>::KeyReverseIterator(
            base::IReverseIteratorSharedPtr<IKeyValueNodeSharedPtr<TKey, TValue>> reverseIterator) :
            m_reverseIterator(reverseIterator)
        {
            base::SmartPointers::Validate<base::IReverseIterator<IKeyValueNodeSharedPtr<TKey, TValue>>>(reverseIterator);
            Reset();
        }

        /**
         * The KeyReverseIterator destructor.
         */
        template <typename TKey, typename TValue>
        KeyReverseIterator<TKey, TValue>::~KeyReverseIterator()
        {
        }

        /**
         * Checks whether there is a Next node.
         */
        template <typename TKey, typename TValue>
        bool KeyReverseIterator<TKey, TValue>::HasNext() const
        {
            return m_reverseIterator->HasNext();
        }

        /**
         * Gets the Next node.
         */
        template <typename TKey, typename TValue>
        TKey KeyReverseIterator<TKey, TValue>::Next()
        {
            assert(HasNext());

            return m_reverseIterator->Next()->GetKey();
        }

        /**
         * Resets the iterator.
         */
        template <typename TKey, typename TValue>
        void KeyReverseIterator<TKey, TValue>::Reset()
        {
            m_reverseIterator->Reset();
        }
    }
}

#endif // KEY_REVERSE_ITERATOR_H_499d0208_fc40_4746_ae72_69b73b57d80b
