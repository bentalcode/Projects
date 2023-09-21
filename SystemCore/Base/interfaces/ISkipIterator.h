#ifndef I_SKIP_ITERATOR_H_01927b89_1f9e_49f2_a5fd_a765f58bfdf0
#define I_SKIP_ITERATOR_H_01927b89_1f9e_49f2_a5fd_a765f58bfdf0

#include <typeindex>
#include <memory>

namespace base
{
    /**
     * The ISkipIterator interface defines a skip iterator of elements.
     */
    class ISkipIterator
    {
    protected:
        /**
         * The constructor.
         */
        ISkipIterator() = default;

    public:
        /**
         * The destructor.
         */
        virtual ~ISkipIterator() = default;

        /**
         * The copy/move constructors.
         */
        ISkipIterator(const ISkipIterator&) = delete;
        ISkipIterator(ISkipIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ISkipIterator& operator=(const ISkipIterator&) = delete;
        ISkipIterator& operator=(ISkipIterator&&) = delete;

        /*
         * Registers the class type of a generic skip element.
         */
        virtual void RegisterGenericSkipElement(const std::type_index& classTypeToSkip) = 0;

        /*
         * Configures the iterator for skipping over the registered elements.
         * Returns the previous configured status.
         */
        virtual bool EnableSkipElements() = 0;

        /*
         * Configures the iterator for including the registered skip elements.
         * Returns the previous configured status.
         */
        virtual bool DisableSkipElements() = 0;

        /*
         * Configures the status of skip elements.
         * Returns the previous configured status.
         */
        virtual bool SetSkipElementsStatus(bool status) = 0;

        /*
         * Gets the current status of skip elements.
         */
        virtual bool GetSkipElementsStatus() = 0;

        /*
         * Checks whether this is a skip element.
         */
        virtual bool IsSkipElement(const std::type_index& classType) = 0;
    };

    //
    // Defines the Shared Ptr of Skip Iterator...
    //
    using ISkipIteratorSharedPtr = std::shared_ptr<ISkipIterator>;

} // namespace base

#endif // I_SKIP_ITERATOR_H_01927b89_1f9e_49f2_a5fd_a765f58bfdf0
