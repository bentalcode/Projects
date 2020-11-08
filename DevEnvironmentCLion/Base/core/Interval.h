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

    template <typename T>
    using IntervalPtr = std::shared_ptr<Interval<T>>;

    template <typename T>
    Interval<T> Interval<T>::make(const T& start, const T& end)
    {
        return Interval<T>(start, end);
    }

    template <typename T>
    Interval<T>::Interval(const T& start, const T& end) :
        m_start(start),
        m_end(end)
    {
        validate(start, end);
    }

    template <typename T>
    Interval<T>::~Interval()
    {
    }

    template <typename T>
    const T& Interval<T>::getStart() const
    {
        return m_start;
    }

    template <typename T>
    const T& Interval<T>::getEnd() const
    {
        return m_end;
    }

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

    template <typename T>
    bool Interval<T>::overlap(const base::Interval<T>& left, const base::Interval<T>& right)
    {
        assert(left <= right);

        return (right.getStart() <= left.getEnd());
    }

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
