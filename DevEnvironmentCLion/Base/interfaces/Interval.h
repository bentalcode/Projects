#ifndef INTERVAL_H_33423945_ab47_4afe_adad_c4f5cb0557f9
#define INTERVAL_H_33423945_ab47_4afe_adad_c4f5cb0557f9

namespace base
{

    /**
     * The Interval class template implements an interval.
     */
    template <typename Type>
    class Interval final
    {
    public:
        /**
         * The constructor.
         */
        Interval(const Type& first, const Type& second);

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
        const Type& getStart() const;

        /**
         * Gets the end point of an interval.
         */
        const Type& getEnd() const;

        /**
         * Determines whether the sorted intervals overlap.
         */
        static bool overlap(const base::Interval<Type>& left, const base::Interval<Type>& right);

    private:
        /**
         * Validates the interval start and end points.
         */
        static void validate(Type start, Type end);

        Type m_start;
        Type m_end;
    };

    template <typename T>
    using IntervalPtr = std::shared_ptr<Interval<T>>;

    template <typename Type>
    Interval<Type>::Interval(const Type& start, const Type& end) :
        m_start(start),
        m_end(end)
    {
        validate(start, end);
    }

    template <typename Type>
    Interval<Type>::~Interval()
    {
    }

    template <typename Type>
    const Type& Interval<Type>::getStart() const
    {
        return m_start;
    }

    template <typename Type>
    const Type& Interval<Type>::getEnd() const
    {
        return m_end;
    }

    template <typename Type>
    bool operator<(const Interval<Type>& left, const Interval<Type>& right)
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

    template <typename Type>
    bool Interval<Type>::overlap(const base::Interval<Type>& left, const base::Interval<Type>& right)
    {
        assert(left <= right);

        return (right.getStart() <= left.getEnd());
    }

    template <typename Type>
    void Interval<Type>::validate(Type start, Type end)
    {
        if (start > end)
        {
            std::string errorMessage = "Invalid interval start and end points.";
            throw BaseException(errorMessage);
        }
    }
}

#endif // INTERVAL_H_33423945_ab47_4afe_adad_c4f5cb0557f9
