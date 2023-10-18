#ifndef CONCURRENT_QUEUE_H_bc494888_f01b_40ca_aab2_b23271283ee4
#define CONCURRENT_QUEUE_H_bc494888_f01b_40ca_aab2_b23271283ee4

#include <mutex>
#include <queue>
#include <condition_variable>

namespace concurrency
{
    /**
     * The ConcurrentQueue class implements a concurrent queue.
     */
    template <typename T>
    class ConcurrentQueue final
    {
    public:
        /**
         * The constructor.
         */
        ConcurrentQueue();

        /**
         * The destructor.
         */
        virtual ~ConcurrentQueue();

        /**
         * The copy/move constructors.
         */
        ConcurrentQueue(const ConcurrentQueue&) = delete;
        ConcurrentQueue(ConcurrentQueue&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ConcurrentQueue& operator=(const ConcurrentQueue&) = delete;
        ConcurrentQueue& operator=(ConcurrentQueue&&) = delete;

        /**
         * Pushes an item to queue.
         */
        void Push(const T& item);
        void Push(T&& item);

        /**
         * Gets the Front item from the queue.
         */
        T Front() const;

        /**
         * Gets the Back item from the queue.
         */
        T Back() const;

        /**
         * Removes the top item from the queue.
         */
        void Pop();

        /**
        * Gets the Size of the queue.
        */
        size_t Size() const;

        /**
         * Checks whether the queue is Empty.
         */
        bool Empty() const;

    private:
        std::queue<T> m_queue;
        std::mutex m_mutex;
        mutable std::condition_variable m_queueHasItemsCondition;
    };

    template <typename T>
    ConcurrentQueue<T>::ConcurrentQueue()
    {
    }

    template <typename T>
    ConcurrentQueue<T>::~ConcurrentQueue()
    {
    }

    template <typename T>
    void ConcurrentQueue<T>::Push(const T& item)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.Push(item);
        lock.unlock();

        m_queueHasItemsCondition.notify_one();
    }

    template <typename T>
    void ConcurrentQueue<T>::Push(T&& item)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.Push(std::move(item));
        lock.unlock();

        m_queueHasItemsCondition.notify_one();
    }

    template <typename T>
    T ConcurrentQueue<T>::Front() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        while (m_queue.Empty())
        {
            m_queueHasItemsCondition.wait(lock);
        }

        T item = m_queue.Front();

        return item;
    }

    template <typename T>
    T ConcurrentQueue<T>::Back() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        while (m_queue.Empty())
        {
            m_queueHasItemsCondition.wait(lock);
        }

        T item = m_queue.Back();

        return item;
    }

    template <typename T>
    void ConcurrentQueue<T>::Pop()
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        while (!m_queue.Empty()) {
            m_queueHasItemsCondition.wait(lock);
        }

        m_queue.Pop();
    }

    template <typename T>
    size_t ConcurrentQueue<T>::Size() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.Size();
    }

    template <typename T>
    bool ConcurrentQueue<T>::Empty() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.Empty();
    }
}

#endif // CONCURRENT_QUEUE_H_bc494888_f01b_40ca_aab2_b23271283ee4
