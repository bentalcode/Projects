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
         * Converts a collection to a string.
         */
        template <typename CollectionType>
        static std::string toString(
            const CollectionType& collection);

        /**
         * Converts a collection to a string.
         */
        template <typename CollectionType>
        static std::string toString(
            const CollectionType& collection,
            const std::string& delimiter);

        /**
         * Converts a collection to a string.
         */
        template <typename CollectionType>
        static std::string toString(
            const CollectionType& collection,
            std::string prefix,
            std::string postfix,
            std::string delimiter);

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
            std::string prefix,
            std::string postfix,
            std::string delimiter);

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
            std::string prefix,
            std::string postfix,
            std::string delimiter);

    private:
        static const std::string defaultPrefix;
        static const std::string defaultPostfix;
        static const std::string defaultDelimiter;

        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Collections() = delete;
        ~Collections() = delete;
    };

    /**
     * Converts a collection to a string.
     */
    template <typename CollectionType>
    std::string Collections::toString(const CollectionType& collection)
    {
        return Collections::toString(
            collection,
            defaultPrefix,
            defaultPostfix,
            defaultDelimiter);
    }

    /**
     * Converts a collection to a string.
     */
    template <typename CollectionType>
    std::string Collections::toString(
        const CollectionType& collection,
        const std::string& delimiter)
    {
        return Collections::toString(
            collection,
            defaultPrefix,
            defaultPostfix,
            delimiter);
    }

    /**
     * Converts a collection to a string.
     */
    template <typename CollectionType>
    std::string Collections::toString(
        const CollectionType& collection,
        std::string prefix,
        std::string postfix,
        std::string delimiter)
    {
        std::stringstream result;

        result << prefix;

        for (typename CollectionType::const_iterator i = collection.begin(); i != collection.end(); ++i)
        {
            if (i != collection.begin())
            {
                result << delimiter;
            }

            result << *i;
        }

        result << postfix;

        return result.str();
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
        std::string prefix,
        std::string postfix,
        std::string delimiter)
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
        std::string prefix,
        std::string postfix,
        std::string delimiter)
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
}

#endif // COLLECTIONS_H_bd7b6910_701e_4e8e_98a7_dfb1aeb6eab1
