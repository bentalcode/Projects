#ifndef COLLECTIONS_H_bd7b6910_701e_4e8e_98a7_dfb1aeb6eab1
#define COLLECTIONS_H_bd7b6910_701e_4e8e_98a7_dfb1aeb6eab1

#include "IIterator.h"
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <functional>
#include <sstream>

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
        static std::wstring ToString(
            const std::vector<T>& collection,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a vector to a string with a functor.
         */
        template <typename T>
        static std::wstring ToString(
            const std::vector<T>& collection,
            const std::function<void(const T &, std::wostream &)>& functor,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a list to a string.
         */
        template <typename T>
        static std::wstring ToString(
            const std::list<T>& collection,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a list to a string with a functor.
         */
        template <typename T>
        static std::wstring ToString(
            const std::list<T>& collection,
            const std::function<void(const T &, std::wostream &)>& functor,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a set to a string.
         */
        template <typename T>
        static std::wstring ToString(
            const std::set<T>& collection,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a set to a string with a functor.
         */
        template <typename T>
        static std::wstring ToString(
            const std::set<T>& collection,
            const std::function<void(const T &, std::wostream &)>& functor,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a queue to a string.
         */
        template <typename T>
        static std::wstring ToString(
            const std::queue<T>& collection,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a queue to a string with a functor.
         */
        template <typename T>
        static std::wstring ToString(
            const std::queue<T>& collection,
            const std::function<void(const T &, std::wostream &)>& functor,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a deque to a string.
         */
        template <typename T>
        static std::wstring ToString(
            const std::deque<T>& collection,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a deque to a string with a functor..
         */
        template <typename T>
        static std::wstring ToString(
            const std::deque<T>& collection,
            const std::function<void(const T &, std::wostream &)>& functor,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a map to a string.
         */
        template <typename TKey, typename TValue, typename TCompare = std::less<TKey>>
        static std::wstring ToString(
            const std::map<TKey, TValue>& collection,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a map to a string with a functor.
         */
        template <typename TKey, typename TValue, typename TCompare = std::less<TKey>>
        static std::wstring toString(
            const std::map<TKey, TValue, TCompare>& collection,
            const std::function<void(const typename std::map<TKey, TValue, TCompare>::value_type& value, std::wostream& stream)>& functor,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts an iterator to a string.
         */
        template <typename T>
        static std::wstring IteratorToString(IIterator<T>& iterator);

        /**
         * Converts an iterator to a string.
         */
        template <typename T>
        static std::wstring IteratorToString(
            IIterator<T>& iterator,
            const std::wstring& delimiter);

        /**
         * Converts an iterator to a string.
         */
        template <typename T>
        static std::wstring IteratorToString(
            IIterator<T>& iterator,
            const std::wstring& prefix,
            const std::wstring& postfix,
            const std::wstring& delimiter);

        /**
         * Converts an iterator to a string by dereferencing it's Element.
         */
        template <typename T>
        static std::wstring DereferenceIteratorToString(IIterator<T>& iterator);

        /**
         * Converts an iterator to a string by dereferencing it's Element.
         */
        template <typename T>
        static std::wstring DereferenceIteratorToString(
            IIterator<T>& iterator,
            const std::wstring& delimiter);

        /**
         * Converts an iterator to a string by dereferencing it's Element.
         */
        template <typename T>
        static std::wstring DereferenceIteratorToString(
            IIterator<T>& iterator,
            const std::wstring& prefix,
            const std::wstring& postfix,
            const std::wstring& delimiter);

    private:
        static const std::wstring DEFAULT_PREFIX;
        static const std::wstring DEFAULT_POSTFIX;
        static const std::wstring DEFAULT_DELIMITER;

        /**
         * Converts a collection to a string.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static std::wstring CollectionToString(
            const CollectionType& collection,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * Converts a collection to a string with a functor.
         */
        template <typename CollectionType, typename ValueType = typename CollectionType::value_type>
        static std::wstring CollectionToString(
            const CollectionType& collection,
            const std::function<void(const ValueType& value, std::wostream& stream)>& functor,
            const std::wstring& prefix = DEFAULT_PREFIX,
            const std::wstring& postfix = DEFAULT_POSTFIX,
            const std::wstring& delimiter = DEFAULT_DELIMITER);

        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Collections() = delete;
        ~Collections() = delete;
    };

    /**
     * Converts a vector to a string with a functor.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::vector<T>& collection,
        const std::function<void(const T& value, std::wostream& stream)>& functor,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a vector to a string.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::vector<T>& collection,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        using CollectionType = std::vector<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::wostream& stream)> functor = [](const ValueType& value, std::wostream& stream)
        {
            stream << value;
        };

        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a vector to a string with a functor.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::list<T>& collection,
        const std::function<void(const T& value, std::wostream& stream)>& functor,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a list to a string.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::list<T>& collection,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        using CollectionType = std::list<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::wostream& stream)> functor = [](const ValueType& value, std::wostream& stream)
        {
            stream << value;
        };

        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a set to a string with a functor.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::set<T>& collection,
        const std::function<void(const T& value, std::wostream& stream)>& functor,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a set to a string.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::set<T>& collection,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        using CollectionType = std::set<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::wostream& stream)> functor = [](const ValueType& value, std::wostream& stream)
        {
            stream << value;
        };

        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a queue to a string with a functor.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::queue<T>& collection,
        const std::function<void(const T& value, std::wostream& stream)>& functor,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a queue to a string.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::queue<T>& collection,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        using CollectionType = std::queue<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::wostream& stream)> functor = [](const ValueType& value, std::wostream& stream)
        {
            stream << value;
        };

        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a queue to a string with a functor.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::deque<T>& collection,
        const std::function<void(const T& value, std::wostream& stream)>& functor,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a deque to a string.
     */
    template <typename T>
    std::wstring Collections::ToString(
        const std::deque<T>& collection,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        using CollectionType = std::deque<T>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::wostream& stream)> functor = [](const ValueType& value, std::wostream& stream)
        {
            stream << value;
        };

        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a map to a string.
     */
    template <typename TKey, typename TValue, typename TCompare>
    std::wstring Collections::ToString(
        const std::map<TKey, TValue>& collection,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        using CollectionType = std::map<TKey, TValue, TCompare>;
        using ValueType = typename CollectionType::value_type;

        std::function<void(const ValueType& value, std::wostream& stream)> functor = [](const ValueType& keyValue, std::wostream& stream)
        {
            const TKey& key = keyValue.first;
            const TValue& value = keyValue.second;

            stream << L"Key = " << key << L", Value = " << value;
        };

        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts a map to a string with a functor.
     */
    template <typename TKey, typename TValue, typename TCompare>
    std::wstring Collections::toString(
        const std::map<TKey, TValue, TCompare>& collection,
        const std::function<void(const typename std::map<TKey, TValue, TCompare>::value_type& value, std::wostream& stream)>& functor,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        return CollectionToString(collection, functor, prefix, postfix, delimiter);
    }

    /**
     * Converts an iterator to a string.
     */
    template <typename T>
    std::wstring Collections::IteratorToString(IIterator<T>& iterator)
    {
        return Collections::IteratorToString(
            iterator,
            DEFAULT_PREFIX,
            DEFAULT_POSTFIX,
            DEFAULT_DELIMITER);
    }

    /**
     * Converts an iterator to a string.
     */
    template <typename T>
    std::wstring Collections::IteratorToString(
        IIterator<T>& iterator,
        const std::wstring& delimiter)
    {
        return Collections::IteratorToString(
            iterator,
            DEFAULT_PREFIX,
            DEFAULT_POSTFIX,
            delimiter);
    }

    /**
     * Converts an iterator to a string.
     */
    template <typename T>
    std::wstring Collections::IteratorToString(
        IIterator<T>& iterator,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        std::wstringstream result;

        result << prefix;

        bool firstElement = true;
        while (iterator.HasNext())
        {
            T element = iterator.Next();

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
     * Converts an iterator to a string by dereferencing it's Element.
     */
    template <typename T>
    std::wstring Collections::DereferenceIteratorToString(IIterator<T>& iterator)
    {
        return Collections::DereferenceIteratorToString(
            iterator,
            DEFAULT_PREFIX,
            DEFAULT_POSTFIX,
            DEFAULT_DELIMITER);
    }

    /**
     * Converts an iterator to a string by dereferencing it's Element.
     */
    template <typename T>
    std::wstring Collections::DereferenceIteratorToString(
        IIterator<T>& iterator,
        const std::wstring& delimiter)
    {
        return Collections::DereferenceIteratorToString(
            iterator,
            DEFAULT_PREFIX,
            DEFAULT_POSTFIX,
            delimiter);
    }

    /**
     * Converts an iterator to a string by dereferencing it's Element.
     */
    template <typename T>
    std::wstring Collections::DereferenceIteratorToString(
        IIterator<T>& iterator,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        std::wstringstream result;

        result << prefix;

        bool firstElement = true;
        while (iterator.HasNext())
        {
            T element = iterator.Next();

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
    std::wstring Collections::CollectionToString(
        const CollectionType& collection,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        std::function<void(const ValueType& value, std::wostream& stream)> functor = [](const ValueType& value, std::wostream& stream)
        {
            stream << value;
        };

        return ToString(
            collection,
            functor,
            prefix,
            postfix,
            delimiter);
    }

    /**
     * Converts a collection to a string with a functor.
     */
    template <typename CollectionType, typename ValueType>
    std::wstring Collections::CollectionToString(
        const CollectionType& collection,
        const std::function<void(const ValueType& value, std::wostream& stream)>& functor,
        const std::wstring& prefix,
        const std::wstring& postfix,
        const std::wstring& delimiter)
    {
        std::wstringstream result;

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
