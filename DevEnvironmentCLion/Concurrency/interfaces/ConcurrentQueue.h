#ifndef CONCURRENT_QUEUE_H_bc494888_f01b_40ca_aab2_b23271283ee4
#define CONCURRENT_QUEUE_H_bc494888_f01b_40ca_aab2_b23271283ee4

#include <mutex>
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
        void push(const T& item);
        void push(T&& item);

        /**
         * Gets the front item from the queue.
         */
        T front() const;

        /**
         * Gets the back item from the queue.
         */
        T back() const;

        /**
         * Removes the top item from the queue.
         */
        void pop();

        /**
        * Gets the size of the queue.
        */
        size_t size() const;

        /**
         * Checks whether the queue is empty.
         */
        bool empty() const;

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
    void ConcurrentQueue<T>::push(const T& item)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(item);
        lock.unlock();

        m_queueHasItemsCondition.notify_one();
    }

    template <typename T>
    void ConcurrentQueue<T>::push(T&& item)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(std::move(item));
        lock.unlock();

        m_queueHasItemsCondition.notify_one();
    }

    template <typename T>
    T ConcurrentQueue<T>::front() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        while (m_queue.empty())
        {
            m_queueHasItemsCondition.wait(lock);
        }

        T item = m_queue.front();

        return item;
    }

    template <typename T>
    T ConcurrentQueue<T>::back() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        while (m_queue.empty())
        {
            m_queueHasItemsCondition.wait(lock);
        }

        T item = m_queue.back();

        return item;
    }

    template <typename T>
    void ConcurrentQueue<T>::pop()
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        while (!m_queue.empty()) {
            m_queueHasItemsCondition.wait(lock);
        }

        m_queue.pop();
    }

    template <typename T>
    size_t ConcurrentQueue<T>::size() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    template <typename T>
    bool ConcurrentQueue<T>::empty() const
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }
}

#endif // CONCURRENT_QUEUE_H_bc494888_f01b_40ca_aab2_b23271283ee4
