#ifndef INTERVAL_H_a1a25086_de91_44c6_9219_767e45bae8e0
#define INTERVAL_H_a1a25086_de91_44c6_9219_767e45bae8e0

namespace base
{

    /**
     * The Interval class template implements an interval.
     */
    template <typename T>
    class Interval final
    {
    public:
        /**
         * Creates an interval.
         */
        static Interval<T> make(const T& start, const T& end);

        /**
         * The constructor.
         */
        Interval(const T& start, const T& end);

        /**
         * The destructor.
         */
        ~Interval();

        /**
         * The copy/move constructors.
         */
        Interval(const Interval&) = default;
        Interval(Interval&&) = default;

        /**
         * The copy/move assignment operators.
         */
        Interval& operator=(const Interval&) = default;
        Interval& operator=(Interval&&) = default;

        /**
         * Gets the start point of an interval.
         */
        const T& getStart() const;

        /**
         * Gets the end point of an interval.
         */
        const T& getEnd() const;

        /**
         * Determines whether the sorted intervals overlap.
         */
        static bool overlap(const base::Interval<T>& left, const base::Interval<T>& right);

    private:
        /**
         * Validates the interval start and end points.
         */
        static void validate(const T& start, const T& end);

        T m_start;
        T m_end;
    };

    //
    // Define the SharedPtr of Interval...
    //
    template <typename T>
    using IntervalSharedPtr = std::shared_ptr<Interval<T>>;

    /**
     * Creates an interval.
     */
    template <typename T>
    Interval<T> Interval<T>::make(const T& start, const T& end)
    {
        return Interval<T>(start, end);
    }

    /**
     * The Interval constructor.
     */
    template <typename T>
    Interval<T>::Interval(const T& start, const T& end) :
        m_start(start),
        m_end(end)
    {
        validate(start, end);
    }

    /**
     * The Interval destructor.
     */
    template <typename T>
    Interval<T>::~Interval()
    {
    }

    /**
     * Gets the start point of an interval.
     */
    template <typename T>
    const T& Interval<T>::getStart() const
    {
        return m_start;
    }

    /**
     * Gets the end point of an interval.
     */
    template <typename T>
    const T& Interval<T>::getEnd() const
    {
        return m_end;
    }

    /**
     * Defines operator less of intervals.
     */
    template <typename T>
    bool operator<(const Interval<T>& left, const Interval<T>& right)
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

    /**
     * Determines whether the sorted intervals overlap.
     */
    template <typename T>
    bool Interval<T>::overlap(const base::Interval<T>& left, const base::Interval<T>& right)
    {
        assert(left <= right);

        return (right.getStart() <= left.getEnd());
    }

    /**
     * Validates the interval start and end points.
     */
    template <typename T>
    void Interval<T>::validate(const T& start, const T& end)
    {
        if (start > end)
        {
            std::string errorMessage = "Invalid interval start and end points.";
            throw BaseException(errorMessage);
        }
    }
}

#endif // INTERVAL_H_a1a25086_de91_44c6_9219_767e45bae8e0
