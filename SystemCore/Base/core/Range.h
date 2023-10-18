#ifndef RANGE_H_f6ee6a76_61f8_4e69_ade4_e0a665c6c98e
#define RANGE_H_f6ee6a76_61f8_4e69_ade4_e0a665c6c98e

namespace base
{
    /**
     * The Range class implements a range.
     */
    template <typename T>
    class Range final
    {
    public:
        /**
         * Creates a range.
         */
        static Range<T> Make(const T& start, const T& from);

        /**
         * The constructor.
         */
        Range(const T& from, const T& to);

        /**
         * The destructor.
         */
        ~Range();

        /**
         * The Copy/move constructors.
         */
        Range(const Range&) = default;
        Range(Range&&) = default;

        /**
         * The Copy/move assignment operators.
         */
        Range& operator=(const Range&) = default;
        Range& operator=(Range&&) = default;

        /**
         * Gets the start point of a range.
         */
        const T& GetStart() const;

        /**
         * Gets the End point of a range.
         */
        const T& GetEnd() const;

        /**
         * Gets the string representation ofthis instance.
         */
        std::wstring ToString() const;

        /**
         * Validates the the range start and End points.
         */
        static void Validate(const T& start, const T& end);

    private:
        T m_start;
        T m_end;
    };

    //
    // Defines the SharedPtr of Range...
    //
    template <typename T>
    using RangeSharedPtr = std::shared_ptr<Range<T>>;

    /**
     * Creates a range.
     */
    template <typename T>
    Range<T> Range<T>::Make(const T& start, const T& end)
    {
        return Range<T>(start, end);
    }

    /**
     * The constructor.
     */
    template <typename T>
    Range<T>::Range(const T& start, const T& end) :
        m_start(start),
        m_end(end)
    {
        Validate(start, end);
    }

    /**
     * The destructor.
     */
    template <typename T>
    Range<T>::~Range()
    {
    }

    /**
     * Gets the start point of a range.
     */
    template <typename T>
    const T& Range<T>::GetStart() const
    {
        return m_start;
    }

    /**
     * Gets the End point of a range.
     */
    template <typename T>
    const T& Range<T>::GetEnd() const
    {
        return m_end;
    }

    /**
     * Gets the string representation ofthis instance.
     */
    template <typename T>
    std::wstring Range<T>::ToString() const
    {
        std::wstringstream stream;
        stream << L"[" << m_start << L"-" << m_end << L"]";
        return stream.str();
    }

    /**
     * Validates the the range start and End points.
     */
    template <typename T>
    void Range<T>::Validate(const T& start, const T& end)
    {
        if (start > end)
        {
            long statusCode = base::ErrorCodes::OUT_OF_RANGE;
            std::wstring errorMessage = L"Invalid range start and End points.";
            throw BaseException(statusCode, errorMessage);
        }
    }

    /**
     * The operator< for implementing equivalence relation.
     */
    template <typename T>
    bool operator<(const Range<T>& left, const Range<T>& right)
    {
        if (left.GetStart() < right.GetStart())
        {
            return true;
        }

        if (left.GetStart() > right.GetStart())
        {
            return false;
        }

        return left.GetEnd() < right.GetEnd();
    }
}

#endif // RANGE_H_f6ee6a76_61f8_4e69_ade4_e0a665c6c98e
