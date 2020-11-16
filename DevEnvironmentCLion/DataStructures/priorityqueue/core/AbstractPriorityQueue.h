#ifndef ABSTRACT_PRIORITY_QUEUE_H_fc0c00e2_b9e1_48fc_bce0_4377930da6a4
#define ABSTRACT_PRIORITY_QUEUE_H_fc0c00e2_b9e1_48fc_bce0_4377930da6a4

#include "IPriorityQueue.h"
#include "IBinaryComparator.h"
#include "PriorityQueueException.h"
#include "VectorIterator.h"
#include "VectorReverseIterator.h"
#include "Indexes.h"
#include "SmartPointers.h"

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
            explicit AbstractPriorityQueue(base::IBinaryComparatorPtr<T> elementComparator);

            /**
             * The AbstractPriorityQueue constructor with an element comparator and initial data.
             */
            AbstractPriorityQueue(
                const std::vector<T>& data,
                base::IBinaryComparatorPtr<T> elementComparator);

        public:
            /**
             * The AbstractPriorityQueue destructor.
             */
            virtual ~AbstractPriorityQueue();

            /**
             * The copy/move constructors.
             */
            AbstractPriorityQueue(const AbstractPriorityQueue<T>&) = delete;
            AbstractPriorityQueue(AbstractPriorityQueue<T>&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            AbstractPriorityQueue& operator=(const AbstractPriorityQueue<T>&) = delete;
            AbstractPriorityQueue& operator=(AbstractPriorityQueue<T>&&) = delete;

            /**
             * Offers an element to the priority queue.
            */
            virtual void offer(const T& element) override;

            /**
             * Polls the peek element from the priority queue.
             */
            virtual T poll() override;

            /**
             * Gets the peek element of the priority queue.
             */
            virtual const T& peek() const override;

            /**
             * Gets the size of the list.
             */
            size_t size() const override;

            /**
             * Checks whether the list is empty.
             */
            bool empty() const override;

            /**
             * Clears the priority queue.
             */
            virtual void clear() override;

            /**
             * Checks whether the priority queue contains an element.
             */
            virtual bool contains(const T& element) const override;

            /**
             * Finds an element in a priority queue.
             * Returns whether an element exist and its result index.
             */
            virtual bool find(T element, size_t& resultIndex) override;

            /**
             * Finds an element in a priority queue by a match predicate.
             * Returns whether an element exist and its result index.
             */
            virtual bool find(const base::IMatch<T>& match, size_t& resultIndex) override;

            /**
             * Updates a value of a specific element and heapify it up.
             */
            virtual void updateAndHypifyUp(size_t index, const T& element) override;

            /**
             * Updates a value of a specific element and heapify it down.
             */
            virtual void updateAndHypifyDown(size_t index, const T& element) override;

            /**
            * Gets an iterator.
            */
            virtual base::IIteratorPtr<T> getIterator() const override;

            /**
             * Gets a reverse iterator.
             */
            virtual base::IReverseIteratorPtr<T> getReverseIterator() const override;

        protected:
            /**
             * Gets the data of the heap.
             */
            const std::vector<T>& getData() const;

            /**
             * Gets the comparator of an element.
             */
            base::IBinaryComparatorPtr<T> getElementComparator() const;

        private:
            /**
             * Heapify an element up.
             */
            void heapifyUp(size_t index);

            /**
             * Heapify an element down.
             */
            void heapifyDown(size_t index);

            /**
             * Swaps the values of the specifies indexes of an array.
             */
            void swapValues(size_t leftIndex, size_t rightIndex);

            /**
             * Gets the index of a parent.
             * Returns whether the parent exist and it's index.
             */
            bool parentIndex(size_t index, size_t& resultIndex) const;

            /**
             * Gets the index of a left child.
             * Returns whether the left child exist and it's index.
             */
            bool leftChildIndex(size_t index, size_t& resultIndex) const;

            /**
             * Gets the index of a right child.
             * Returns whether the right child exist and it's index.
             */
            bool rightChildIndex(size_t index, size_t& resultIndex) const;

            /**
             * Checks whether an element is a leaf.
             */
            bool isLeaf(size_t index) const;

            typedef std::vector<T> DataType;
            DataType m_data;
            base::IBinaryComparatorPtr<T> m_elementComparator;
        };

        /**
         * The AbstractPriorityQueue constructor.
         */
        template <typename T>
        AbstractPriorityQueue<T>::AbstractPriorityQueue(base::IBinaryComparatorPtr<T> elementComparator) :
            m_elementComparator(elementComparator)
        {
        }

        /**
         * The AbstractPriorityQueue constructor with initial data.
         */
        template <typename T>
        AbstractPriorityQueue<T>::AbstractPriorityQueue(
            const std::vector<T>& data,
            base::IBinaryComparatorPtr<T> elementComparator) :
            m_data(data),
            m_elementComparator(elementComparator)
        {
            base::SmartPointers::validate(elementComparator);
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
        void AbstractPriorityQueue<T>::offer(const T& element)
        {
            m_data.push_back(element);

            size_t newSize = size();

            if (newSize == 1) {
                return;
            }

            heapifyUp(newSize - 1);
        }

        /**
         * Polls the peek element from the priority queue.
         */
        template <typename T>
        T AbstractPriorityQueue<T>::poll()
        {
            if (empty())
            {
                std::string errorMessage = "The priority queue is empty.";
                throw PriorityQueueException(errorMessage);
            }

            const T& currentElement = m_data[0];

            swapValues(0, size() - 1);
            m_data.pop_back();

            if (!empty())
            {
                heapifyDown(0);
            }

            return currentElement;
        }

        /**
         * Gets the peek element of the priority queue.
         */
        template <typename T>
        const T& AbstractPriorityQueue<T>::peek() const
        {
            if (empty())
            {
                std::string errorMessage = "The priority queue is empty.";
                throw PriorityQueueException(errorMessage);
            }

            return m_data[0];
        }

        /**
         * Gets the size of the list.
         */
        template <typename T>
        size_t AbstractPriorityQueue<T>::size() const
        {
            return m_data.size();
        }

        /**
         * Checks whether the list is empty.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::empty() const
        {
            return size() == 0;
        }

        /**
         * Clears the priority queue.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::clear()
        {
            m_data.clear();
        }

        /**
         * Checks whether the priority queue contains an element.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::contains(const T& element) const
        {
            return std::find(m_data.begin(), m_data.end(), element) != m_data.end();
        }

        /**
         * Finds an element in a priority queue.
         * Returns whether an element exist and its result index.
         */
        template <typename T>
        bool AbstractPriorityQueue<T>::find(T element, size_t& resultIndex)
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
        bool AbstractPriorityQueue<T>::find(const base::IMatch<T>& match, size_t& resultIndex)
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
        void AbstractPriorityQueue<T>::updateAndHypifyUp(size_t index, const T& element)
        {
            base::Indexes::validateIndex<size_t>(index, 0, m_data.size() - 1);
            m_data[index] = element;
            heapifyUp(index);
        }

        /**
         * Updates a value of a specific element and heapify it down.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::updateAndHypifyDown(size_t index, const T& element)
        {
            base::Indexes::validateIndex<size_t>(index, 0, m_data.size() - 1);
            m_data[index] = element;
            heapifyDown(index);
        }

        /**
        * Gets an iterator.
        */
        template <typename T>
        base::IIteratorPtr<T> AbstractPriorityQueue<T>::getIterator() const
        {
            return base::VectorIterator<T>::make(m_data);
        }

        /**
         * Gets a reverse iterator.
         */
        template <typename T>
        base::IReverseIteratorPtr<T> AbstractPriorityQueue<T>::getReverseIterator() const
        {
            return base::VectorReverseIterator<T>::make(m_data);
        }

        /**
         * Gets the data of the heap.
         */
        template <typename T>
        const std::vector<T>& AbstractPriorityQueue<T>::getData() const
        {
            return m_data;
        }

        /**
         * Gets the comparator of an element.
         */
        template <typename T>
        base::IBinaryComparatorPtr<T> AbstractPriorityQueue<T>::getElementComparator() const
        {
            return m_elementComparator;
        }

        /**
         * Heapify an element up.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::heapifyUp(size_t index)
        {
             assert(index < m_data.size());

            if (index == 0)
            {
                return;
            }

            size_t currChildIndex = index;
            size_t currParentIndex = 0;
            bool parentExist = parentIndex(index, currParentIndex);

            while (parentExist)
            {
                const T& currParentValue = m_data[currParentIndex];
                const T& currChildValue = m_data[currChildIndex];

                int compareStatus = m_elementComparator->compareTo(currParentValue, currChildValue);

                if (compareStatus <= 0)
                {
                    break;
                }

                swapValues(currParentIndex, currChildIndex);

                //
                // Move one level up...
                //
                currChildIndex = currParentIndex;
                parentExist = parentIndex(currParentIndex, currParentIndex);
            }
        }

        /**
         * Heapify an element down.
         */
        template <typename T>
        void AbstractPriorityQueue<T>::heapifyDown(size_t index)
        {
            assert(index < m_data.size());

            size_t currParentIndex = index;

            while (!isLeaf(currParentIndex))
            {
                size_t currChildIndex = 0;
                const T* currChildValue = nullptr;

                size_t currLeftChildIndex = 0;
                bool leftChildExist = leftChildIndex(currParentIndex, currLeftChildIndex);
                assert(leftChildExist);

                const T& currLeftChildValue = m_data[currLeftChildIndex];

                size_t currRightChildIndex = 0;
                bool rightChildExist = rightChildIndex(currParentIndex, currRightChildIndex);

                if (rightChildExist)
                {
                    const T& currRightChildValue = m_data[currRightChildIndex];

                    if (m_elementComparator->compareTo(currLeftChildValue, currRightChildValue) <= 0)
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

                int compareStatus = m_elementComparator->compareTo(currParentValue, *currChildValue);

                if (compareStatus <= 0)
                {
                    break;
                }

                swapValues(currParentIndex, currChildIndex);

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
        void AbstractPriorityQueue<T>::swapValues(size_t leftIndex, size_t rightIndex)
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
        bool AbstractPriorityQueue<T>::parentIndex(size_t index, size_t& resultIndex) const
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
        bool AbstractPriorityQueue<T>::leftChildIndex(size_t index, size_t& resultIndex) const
        {
            size_t childIndex = (index * 2) + 1;

            if (childIndex < size())
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
        bool AbstractPriorityQueue<T>::rightChildIndex(size_t index, size_t& resultIndex) const
        {
            size_t childIndex = (index * 2) + 2;

            if (childIndex < size())
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
        bool AbstractPriorityQueue<T>::isLeaf(size_t index) const
        {
            return index >= size() / 2;
        }

    }
}

#endif // ABSTRACT_PRIORITY_QUEUE_H_fc0c00e2_b9e1_48fc_bce0_4377930da6a4
