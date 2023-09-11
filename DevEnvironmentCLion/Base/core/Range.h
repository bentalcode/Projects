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
        static Range<T> make(const T& start, const T& from);

        /**
         * The constructor.
         */
        Range(const T& from, const T& to);

        /**
         * The destructor.
         */
        ~Range();

        /**
         * The copy/move constructors.
         */
        Range(const Range&) = default;
        Range(Range&&) = default;

        /**
         * The copy/move assignment operators.
         */
        Range& operator=(const Range&) = default;
        Range& operator=(Range&&) = default;

        /**
         * Gets the start point of a range.
         */
        const T& getStart() const;

        /**
         * Gets the end point of a range.
         */
        const T& getEnd() const;

        /**
         * Gets the string representation of this instance.
         */
        std::string toString() const;

        /**
         * Validates the the range start and end points.
         */
        static void validate(const T& start, const T& end);

    private:
        T m_start;
        T m_end;
    };

    template <typename T>
    using RangePtr = std::shared_ptr<Range<T>>;

    /**
     * Creates a range.
     */
    template <typename T>
    Range<T> Range<T>::make(const T& start, const T& end)
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
        validate(start, end);
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
    const T& Range<T>::getStart() const
    {
        return m_start;
    }

    /**
     * Gets the end point of a range.
     */
    template <typename T>
    const T& Range<T>::getEnd() const
    {
        return m_end;
    }

    /**
     * Gets the string representation of this instance.
     */
    template <typename T>
    std::string Range<T>::toString() const
    {
        std::stringstream stream;
        stream << "[" << m_start << "-" << m_end << "]";
        return stream.str();
    }

    /**
     * Validates the the range start and end points.
     */
    template <typename T>
    void Range<T>::validate(const T& start, const T& end)
    {
        if (start > end)
        {
            std::string errorMessage = "Invalid range start and end points.";
            throw BaseException(errorMessage);
        }
    }

    /**
     * The operator< for implementing equivalence relation.
     */
    template <typename T>
    bool operator<(const Range<T>& left, const Range<T>& right)
    {
        if (left.getStart() < right.getStart())
        {
            return true;
        }

        if (left.getStart() > right.getStart())
        {
            return false;
        }

        return left.getEnd() < right.getEnd();
    }
}

#endif // RANGE_H_f6ee6a76_61f8_4e69_ade4_e0a665c6c98e
