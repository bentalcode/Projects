#ifndef ABSTRACT_PRIORITY_QUEUE_H_fc0c00e2_b9e1_48fc_bce0_4377930da6a4
#define ABSTRACT_PRIORITY_QUEUE_H_fc0c00e2_b9e1_48fc_bce0_4377930da6a4

#include "IPriorityQueue.h"
#include "IBinaryComparator.h"
#include "PriorityQueueException.h"
#include "VectorIterator.h"
#include "VectorReverseIterator.h"
#include "Indexes.h"
#include "SmartPointers.h"
#include "PriorityQueueException.h"
#include <algorithm>

namespace datastructures {
    namespace priority_queue {

        /**
         * The AbstractPriorityQueue class implements an abstract base class for a priority queue.
         *
         * The priority queue is implemented as a heap with a dynamic array.
         *
         * A complete binary tree can be uniquely represented by storing it's level order traversal in an array.
         * The left child of an element is located at index: 2 * index + 1.
         * The right child of an element is located at index: 2 * index + 2.
         * The parent of an element is located at index: (index - 1) / 2.
         */
        template <typename T>
        class AbstractPriorityQueue : public IPriorityQueue<T>
        {
        protected:
            /**
             * The AbstractPriorityQueue constructor with an element comparator.
             */
            explicit AbstractPriorityQueue(base::IBinaryComparatorSharedPtr<T> elementComparator);

            /**
             * The AbstractPriorityQueue constructor with an element comparator and initial data.
             */
            AbstractPriorityQueue(
                const std::vector<T>& data,
                base::IBinaryComparatorSharedPtr<T> elementComparator);

        public:
            /**
             * The AbstractPriorityQueue destructor.
             */
            virtual ~AbstractPriorityQueue();

            /**
             * The Copy/move constructors.
             */
            AbstractPriorityQueue(const AbstractPriorityQueue<T>&) = delete;
            AbstractPriorityQueue(AbstractPriorityQueue<T>&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            AbstractPriorityQueue& operator=(const AbstractPriorityQueue<T>&) = delete;
            AbstractPriorityQueue& operator=(AbstractPriorityQueue<T>&&) = delete;

            /**
             * Offers an element to the priority queue.
            */
            virtual void Offer(const T& element) override;

            /**
             * Polls the Peek element from the priority queue.
             */
            virtual T Poll() override;

            /**
             * Gets the Peek element of the priority queue.
             */
            virtual const T& Peek() const override;

            /**
             * Gets the Size of the list.
             */
            size_t Size() const override;

            /**
             * Checks whether the list is Empty.
             */
            bool Empty() const override;

            /**
             * Clears the priority queue.
             */
            virtual void Clear() override;

            /**
             * Checks whether the priority queue Contains an element.
             */
            virtual bool Contains(const T& element) const override;

            /**
             * Finds an element in a priority queue.
             * Returns whether an element exist and its result index.
             */
            virtual bool Find(T element, size_t& resultIndex) override;

            /**
             * Finds an element in a priority queue by a match predicate.
             * Returns whether an element exist and its result index.
             */
            virtual bool Find(const base::IMatch<T>& match, size_t& resultIndex) override;

            /**
             * Updates a value of a specific element and heapify it up.
             */
            virtual void UpdateAndHypifyUp(size_t index, const T& element) override;

            /**
             * Updates a value of a specific element and heapify it down.
             */
            virtual void UpdateAndHypifyDown(size_t index, const T& element) override;

            /**
            * Gets an iterator.
            */
            virtual base::IIteratorSharedPtr<T> GetIterator() const override;

            /**
             * Gets a reverse iterator.
             */
            virtual base::IReverseIteratorSharedPtr<T> GetReverseIterator() const override;

        protected:
            /**
             * Gets the data of the heap.
             */
            const std::vector<T>& GetData() const;

            /**
             * Gets the comparator of an element.
             */
            base::IBinaryComparatorSharedPtr<T> GetElementComparator() const;

        private:
            /**
             * Heapify an element up.
             */
            void HeapifyUp(size_t index);

            /**
             * Heapify an element down.
             */
            void HeapifyDown(size_t index);

            /**
             * Swaps the values of the specifies indexes of an array.
             */
            void SwapValues(size_t leftIndex, size_t rightIndex);

            /**
             * Gets the index of a parent.
             * Returns whether the parent exist and it's index.
             */
            bool ParentIndex(size_t index, size_t& resultIndex) const;

            /**
             * Gets the index of a left child.
             * Returns whether the left child exist and it's index.
             */
            bool LeftChildIndex(size_t index, size_t& resultIndex) const;

            /**
             * Gets the index of a right child.
             * Returns whether the right child exist and it's index.
             */
            bool RightChildIndex(size_t index, size_t& resultIndex) const;

            /**
             * Checks whether an element is a leaf.
             */
            bool IsLeaf(size_t index) const;

            typedef std::vector<T> DataType;
            DataType m_data;
            base::IBinaryComparatorSharedPtr<T> m_elementComparator;
        };

        /**
         * The AbstractPriorityQueue constructor.
         */
        template <typename T>
        AbstractPriorityQueue<T>::AbstractPriorityQueue(base::IBinaryComparatorSharedPtr<T> elementComparator) :
            m_elementComparator(elementComparator)
        {
        }

        /**
         * The AbstractPriorityQueue constructor with initial data.
         */
        template <typename T>
        AbstractPriorityQueue<T>::AbstractPriorityQueue(
            const std::vector<T>& data,
            base::IBinaryComparatorSharedPtr<T> elementComparator) :
            m_data(data),
            m_elementComparator(elementComparator)
        {
            base::SmartPointers::Validate<base::IBinaryComparator<T>>(elementComparator);
        }

        /**
         * The AbstractPriorityQueue destructor.
         */
        template <typename T>
        AbstractPriorityQueue<T>::~AbstractPriorityQueue()
        {
        }

        /**
         * Offers an element to the priority queue.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::Offer(const T& element)
        {
            m_data.push_back(element);

            size_t newSize = Size();

            if (newSize == 1) {
                return;
            }

            HeapifyUp(newSize - 1);
        }

        /**
         * Polls the Peek element from the priority queue.
         */
        template <typename T>
        T AbstractPriorityQueue<T>::Poll()
        {
            if (Empty())
            {
                long statusCode = base::ErrorCodes::OUT_OF_RANGE;
                std::wstring errorMessage = L"The priority queue is empty.";
                throw PriorityQueueException(statusCode, errorMessage);
            }

            const T& currentElement = m_data[0];

            SwapValues(0, Size() - 1);
            m_data.pop_back();

            if (!Empty())
            {
                HeapifyDown(0);
            }

            return currentElement;
        }

        /**
         * Gets the Peek element of the priority queue.
         */
        template <typename T>
        const T& AbstractPriorityQueue<T>::Peek() const
        {
            if (Empty())
            {
                long statusCode = base::ErrorCodes::OUT_OF_RANGE;
                std::wstring errorMessage = L"The priority queue is empty.";
                throw PriorityQueueException(statusCode, errorMessage);
            }

            return m_data[0];
        }

        /**
         * Gets the Size of the list.
         */
        template <typename T>
        size_t AbstractPriorityQueue<T>::Size() const
        {
            return m_data.size();
        }

        /**
         * Checks whether the list is Empty.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::Empty() const
        {
            return Size() == 0;
        }

        /**
         * Clears the priority queue.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::Clear()
        {
            m_data.clear();
        }

        /**
         * Checks whether the priority queue Contains an element.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::Contains(const T& element) const
        {
            return std::find(m_data.begin(), m_data.end(), element) != m_data.end();
        }

        /**
         * Finds an element in a priority queue.
         * Returns whether an element exist and its result index.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::Find(T element, size_t& resultIndex)
        {
            typename DataType::const_iterator i = std::find(m_data.begin(), m_data.end(), element);

            if (i == m_data.end())
            {
                resultIndex = 0;
                return false;
            }

            resultIndex = i - m_data.begin();
            return true;
        }

        /**
         * Finds an element in a priority queue by a match predicate.
         * Returns whether an element exist and its result index.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::Find(const base::IMatch<T>& match, size_t& resultIndex)
        {
            for (size_t index = 0; index < m_data.size(); ++index)
            {
                const T& currElement = m_data[index];

                if (match.match(currElement))
                {
                    resultIndex = index;
                    return true;
                }

                ++index;
            }

            resultIndex = 0;
            return false;
        }

        /**
         * Updates a value of a specific element and heapify it up.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::UpdateAndHypifyUp(size_t index, const T& element)
        {
            base::Indexes::ValidateIndex<size_t>(index, 0, m_data.size() - 1);
            m_data[index] = element;
            HeapifyUp(index);
        }

        /**
         * Updates a value of a specific element and heapify it down.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::UpdateAndHypifyDown(size_t index, const T& element)
        {
            base::Indexes::ValidateIndex<size_t>(index, 0, m_data.size() - 1);
            m_data[index] = element;
            HeapifyDown(index);
        }

        /**
        * Gets an iterator.
        */
        template <typename T>
        base::IIteratorSharedPtr<T> AbstractPriorityQueue<T>::GetIterator() const
        {
            return base::VectorIterator<T>::Make(m_data);
        }

        /**
         * Gets a reverse iterator.
         */
        template <typename T>
        base::IReverseIteratorSharedPtr<T> AbstractPriorityQueue<T>::GetReverseIterator() const
        {
            return base::VectorReverseIterator<T>::Make(m_data);
        }

        /**
         * Gets the data of the heap.
         */
        template <typename T>
        const std::vector<T>& AbstractPriorityQueue<T>::GetData() const
        {
            return m_data;
        }

        /**
         * Gets the comparator of an element.
         */
        template <typename T>
        base::IBinaryComparatorSharedPtr<T> AbstractPriorityQueue<T>::GetElementComparator() const
        {
            return m_elementComparator;
        }

        /**
         * Heapify an element up.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::HeapifyUp(size_t index)
        {
             assert(index < m_data.size());

            if (index == 0)
            {
                return;
            }

            size_t currChildIndex = index;
            size_t currParentIndex = 0;
            bool parentExist = ParentIndex(index, currParentIndex);

            while (parentExist)
            {
                const T& currParentValue = m_data[currParentIndex];
                const T& currChildValue = m_data[currChildIndex];

                int compareStatus = m_elementComparator->CompareTo(currParentValue, currChildValue);

                if (compareStatus <= 0)
                {
                    break;
                }

                SwapValues(currParentIndex, currChildIndex);

                //
                // Move one level up...
                //
                currChildIndex = currParentIndex;
                parentExist = ParentIndex(currParentIndex, currParentIndex);
            }
        }

        /**
         * Heapify an element down.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::HeapifyDown(size_t index)
        {
            assert(index < m_data.size());

            size_t currParentIndex = index;

            while (!IsLeaf(currParentIndex))
            {
                size_t currChildIndex = 0;
                const T* currChildValue = nullptr;

                size_t currLeftChildIndex = 0;
                bool leftChildExist = LeftChildIndex(currParentIndex, currLeftChildIndex);
                assert(leftChildExist);

                const T& currLeftChildValue = m_data[currLeftChildIndex];

                size_t currRightChildIndex = 0;
                bool rightChildExist = RightChildIndex(currParentIndex, currRightChildIndex);

                if (rightChildExist)
                {
                    const T& currRightChildValue = m_data[currRightChildIndex];

                    if (m_elementComparator->CompareTo(currLeftChildValue, currRightChildValue) <= 0)
                    {
                        currChildIndex = currLeftChildIndex;
                        currChildValue = &currLeftChildValue;
                    }
                    else
                    {
                        currChildIndex = currRightChildIndex;
                        currChildValue = &currRightChildValue;
                    }
                }
                else
                {
                    currChildIndex = currLeftChildIndex;
                    currChildValue = &currLeftChildValue;
                }

                const T& currParentValue = m_data[currParentIndex];

                int compareStatus = m_elementComparator->CompareTo(currParentValue, *currChildValue);

                if (compareStatus <= 0)
                {
                    break;
                }

                SwapValues(currParentIndex, currChildIndex);

                //
                // Move one level down...
                //
                currParentIndex = currChildIndex;
            }
        }

        /**
         * Swaps the values of the specifies indexes of an array.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::SwapValues(size_t leftIndex, size_t rightIndex)
        {
            assert(leftIndex < m_data.size());
            assert(rightIndex < m_data.size());
            assert(leftIndex <= rightIndex);

            if (leftIndex == rightIndex)
            {
                return;
            }

            T temp = m_data[leftIndex];
            m_data[leftIndex] = m_data[rightIndex];
            m_data[rightIndex] = temp;
        }

        /**
         * Gets the index of a parent.
         * Returns whether the parent exist and it's index.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::ParentIndex(size_t index, size_t& resultIndex) const
        {
            if (index == 0)
            {
                resultIndex = 0;
                return false;
            }
            else
            {
                resultIndex = (index - 1) / 2;
                return true;
            }
        }

        /**
         * Gets the index of a left child.
         * Returns whether the left child exist and it's index.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::LeftChildIndex(size_t index, size_t& resultIndex) const
        {
            size_t childIndex = (index * 2) + 1;

            if (childIndex < Size())
            {
                resultIndex = childIndex;
                return true;
            }
            else
            {
                resultIndex = 0;
                return false;
            }
        }

        /**
         * Gets the index of a right child.
         * Returns whether the right child exist and it's index.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::RightChildIndex(size_t index, size_t& resultIndex) const
        {
            size_t childIndex = (index * 2) + 2;

            if (childIndex < Size())
            {
                resultIndex = childIndex;
                return true;
            }
            else
            {
                resultIndex = 0;
                return false;
            }
        }

        /**
         * Checks whether an element is a leaf.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::IsLeaf(size_t index) const
        {
            return index >= Size() / 2;
        }

    }
}

#endif // ABSTRACT_PRIORITY_QUEUE_H_fc0c00e2_b9e1_48fc_bce0_4377930da6a4
