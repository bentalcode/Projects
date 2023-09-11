#ifndef COLLECTIONS_H_bd7b6910_701e_4e8e_98a7_dfb1aeb6eab1
#define COLLECTIONS_H_bd7b6910_701e_4e8e_98a7_dfb1aeb6eab1

#include "IIterator.h"

namespace base
{
    /**
     * The Collections class implements complementary APIs for collections.
     */
    class Collections final
    {
    public:
        /**
         * Converts a vector to a string.
         */
        template <typename T>
        static std::string toString(
            const std::vector<T>& collection,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a vector to a string.
         */
        template <typename T>
        static std::string toString(
            const std::vector<T>& collection,
            const std::function<void(const T& value, std::ostream& stream)>& functor,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a list to a string.
         */
        template <typename T>
        static std::string toString(
            const std::list<T>& collection,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a list to a string.
         */
        template <typename T>
        static std::string toString(
            const std::list<T>& collection,
            const std::function<void(const T& value, std::ostream& stream)>& functor,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a deque to a string.
         */
        template <typename T>
        static std::string toString(
            const std::deque<T>& collection,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a deque to a string.
         */
        template <typename T>
        static std::string toString(
            const std::deque<T>& collection,
            const std::function<void(const T& value, std::ostream& stream)>& functor,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a set to a string.
         */
        template <typename T, typename TCompare = std::less<T>>
        static std::string toString(
            const std::set<T, TCompare>& collection,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a set to a string.
         */
        template <typename T, typename TCompare = std::less<T>>
        static std::string toString(
            const std::set<T, TCompare>& collection,
            const std::function<void(const typename std::set<T, TCompare>::value_type& value, std::ostream& stream)>& functor,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a map to a string.
         */
        template <typename TKey, typename TValue, typename TCompare = std::less<TKey>>
        static std::string toString(
            const std::map<TKey, TValue, TCompare>& collection,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a map to a string.
         */
        template <typename TKey, typename TValue, typename TCompare = std::less<TKey>>
        static std::string toString(
            const std::map<TKey, TValue, TCompare>& collection,
            const std::function<void(const typename std::map<TKey, TValue, TCompare>::value_type& value, std::ostream& stream)>& functor,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts an iterator to a string.
         */
        template <typename T>
        static std::string iteratorToString(
            IIterator<T>& iterator);

        /**
         * Converts an iterator to a string.
         */
        template <typename T>
        static std::string iteratorToString(
            IIterator<T>& iterator,
            const std::string& delimiter);

        /**
         * Converts an iterator to a string.
         */
        template <typename T>
        static std::string iteratorToString(
            IIterator<T>& iterator,
            const std::string& prefix,
            const std::string& postfix,
            const std::string& delimiter);

        /**
         * Converts an iterator to a string by dereferencing it's element.
         */
        template <typename T>
        static std::string dereferenceIteratorToString(
            IIterator<T>& iterator);

        /**
         * Converts an iterator to a string by dereferencing it's element.
         */
        template <typename T>
        static std::string dereferenceIteratorToString(
            IIterator<T>& iterator,
            const std::string& delimiter);

        /**
         * Converts an iterator to a string by dereferencing it's element.
         */
        template <typename T>
        static std::string dereferenceIteratorToString(
            IIterator<T>& iterator,
            const std::string& prefix,
            const std::string& postfix,
            const std::string& delimiter);

    private:
        static const std::string defaultPrefix;
        static const std::string defaultPostfix;
        static const std::string defaultDelimiter;

        /**
         * Converts a collection to a string.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static std::string collectionToString(
            const CollectionType& collection,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * Converts a collection to a string.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static std::string collectionToString(
            const CollectionType& collection,
            const std::function<void(const ValueType& value, std::ostream& stream)>& functor,
            const std::string& prefix = defaultPrefix,
            const std::string& postfix = defaultPostfix,
            const std::string& delimiter = defaultDelimiter);

        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Collections() = delete;
        ~Collections() = delete;
    };

    /**
     * Converts a vector to a string.
     */
    template <typename T>
    std::string Collections::toString(
        const std::vector<T>& collection,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        using CollectionType = std::vector<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::ostream& stream)> functor = [](const ValueType& value, std::ostream& stream)
        {
            stream << value;
        };

        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a vector to a string.
     */
    template <typename T>
    std::string Collections::toString(
        const std::vector<T>& collection,
        const std::function<void(const T& value, std::ostream& stream)>& functor,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a list to a string.
     */
    template <typename T>
    std::string Collections::toString(
        const std::list<T>& collection,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        using CollectionType = std::list<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::ostream& stream)> functor = [](const ValueType& value, std::ostream& stream)
        {
            stream << value;
        };

        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a list to a string.
     */
    template <typename T>
    std::string Collections::toString(
        const std::list<T>& collection,
        const std::function<void(const T& value, std::ostream& stream)>& functor,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a deque to a string.
     */
    template <typename T>
    std::string Collections::toString(
        const std::deque<T>& collection,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        using CollectionType = std::deque<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::ostream& stream)> functor = [](const ValueType& value, std::ostream& stream)
        {
            stream << value;
        };

        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a deque to a string.
     */
    template <typename T>
    std::string Collections::toString(
        const std::deque<T>& collection,
        const std::function<void(const T& value, std::ostream& stream)>& functor,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a set to a string.
     */
    template <typename T, typename TCompare>
    std::string Collections::toString(
        const std::set<T, TCompare>& collection,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        using CollectionType = std::set<T, TCompare>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::ostream& stream)> functor = [](const ValueType& value, std::ostream& stream)
        {
            stream << value;
        };

        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a set to a string.
     */
    template <typename T, typename TCompare>
    std::string Collections::toString(
        const std::set<T, TCompare>& collection,
        const std::function<void(const typename std::set<T, TCompare>::value_type& value, std::ostream& stream)>& functor,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a map to a string.
     */
    template <typename TKey, typename TValue, typename TCompare>
    std::string Collections::toString(
        const std::map<TKey, TValue, TCompare>& collection,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        using CollectionType = std::map<TKey, TValue, TCompare>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::ostream& stream)> functor = [](const ValueType& keyValue, std::ostream& stream)
        {
            const TKey& key = keyValue.first;
            const TValue& value = keyValue.second;

            stream << "Key = " << key << ", Value = " << value;
        };

        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a map to a string.
     */
    template <typename TKey, typename TValue, typename TCompare>
    std::string Collections::toString(
        const std::map<TKey, TValue, TCompare>& collection,
        const std::function<void(const typename std::map<TKey, TValue, TCompare>::value_type& value, std::ostream& stream)>& functor,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        return collectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts an iterator to a string.
     */
    template <typename T>
    std::string Collections::iteratorToString(IIterator<T>& iterator)
    {
        return Collections::iteratorToString(
            iterator,
            defaultPrefix,
            defaultPostfix,
            defaultDelimiter);
    }

    /**
     * Converts an iterator to a string.
     */
    template <typename T>
    std::string Collections::iteratorToString(
        IIterator<T>& iterator,
        const std::string& delimiter)
    {
        return Collections::iteratorToString(
            iterator,
            defaultPrefix,
            defaultPostfix,
            delimiter);
    }

    /**
     * Converts an iterator to a string.
     */
    template <typename T>
    std::string Collections::iteratorToString(
        IIterator<T>& iterator,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        std::stringstream result;

        result << prefix;

        bool firstElement = true;
        while (iterator.hasNext())
        {
            T element = iterator.next();

            if (!firstElement)
            {
                result << delimiter;
            }

            result << element;

            firstElement = false;
        }

        result << postfix;

        return result.str();
    }

    /**
     * Converts an iterator to a string by dereferencing it's element.
     */
    template <typename T>
    std::string Collections::dereferenceIteratorToString(IIterator<T>& iterator)
    {
        return Collections::dereferenceIteratorToString(
            iterator,
            defaultPrefix,
            defaultPostfix,
            defaultDelimiter);
    }

    /**
     * Converts an iterator to a string by dereferencing it's element.
     */
    template <typename T>
    std::string Collections::dereferenceIteratorToString(
        IIterator<T>& iterator,
        const std::string& delimiter)
    {
        return Collections::dereferenceIteratorToString(
            iterator,
            defaultPrefix,
            defaultPostfix,
            delimiter);
    }

    /**
     * Converts an iterator to a string by dereferencing it's element.
     */
    template <typename T>
    std::string Collections::dereferenceIteratorToString(
        IIterator<T>& iterator,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        std::stringstream result;

        result << prefix;

        bool firstElement = true;
        while (iterator.hasNext())
        {
            T element = iterator.next();

            if (!firstElement)
            {
                result << delimiter;
            }

            result << *element;

            firstElement = false;
        }

        result << postfix;

        return result.str();
    }

    /**
     * Converts a collection to a string.
     */
    template <typename CollectionType, typename ValueType>
    std::string Collections::collectionToString(
        const CollectionType& collection,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        std::function<void(const ValueType& value, std::ostream& stream)> functor = [](const ValueType& value, std::ostream& stream)
        {
            stream << value;
        };

        return toString(
            collection,
            functor,
            prefix,
            postfix,
            delimiter);
    }

    /**
     * Converts a collection to a string.
     */
    template <typename CollectionType, typename ValueType>
    std::string Collections::collectionToString(
        const CollectionType& collection,
        const std::function<void(const ValueType& value, std::ostream& stream)>& functor,
        const std::string& prefix,
        const std::string& postfix,
        const std::string& delimiter)
    {
        std::stringstream result;

        result << prefix;

        size_t index = 0;
        for (const ValueType& value : collection)
        {
            if (index > 0)
            {
                result << delimiter;
            }

            functor(value, result);
            ++index;
        }

        result << postfix;

        return result.str();
    }

}

#endif // COLLECTIONS_H_bd7b6910_701e_4e8e_98a7_dfb1aeb6eab1
