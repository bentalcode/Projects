#ifndef SKIP_ITERATOR_H_3ecd7885_6757_4a51_8114_915a43fada62
#define SKIP_ITERATOR_H_3ecd7885_6757_4a51_8114_915a43fada62

#include "ISkipIterator.h"
#include <vector>

namespace base
{
    /**
     * The SkipIterator class implements a skip iterator of elements.
     */
    class SkipIterator : public ISkipIterator
    {
    public:
        /**
         * The SkipIterator constructor.
         */
        SkipIterator();

        /**
         * The SkipIterator destructor.
         */
        virtual ~SkipIterator();

        /**
         * The copy/move constructors.
         */
        SkipIterator(const SkipIterator&) = delete;
        SkipIterator(SkipIterator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        SkipIterator& operator=(const SkipIterator&) = delete;
        SkipIterator& operator=(SkipIterator&&) = delete;

        /*
         * Registers the class type of generic skip element.
         */
        virtual void RegisterGenericSkipElement(const std::type_index& classTypeToSkip) override;

        /*
         * Configures the iterator for skipping over the registered elements.
         * Returns the previous configured status.
         */
        virtual bool EnableSkipElements() override;

        /*
         * Configures the iterator for including the registered skip elements.
         * Returns the previous configured status.
         */
        virtual bool DisableSkipElements() override;

        /*
         * Configures the status of skip elements.
         * Returns the previous configured status.
         */
        virtual bool SetSkipElementsStatus(bool status) override;

        /*
         * Gets the current status of skip elements.
         */
        virtual bool GetSkipElementsStatus() override;

        /*
         * Checks whether this is a skip element.
         */
        virtual bool IsSkipElement(const std::type_index& element) override;

    private:
        std::vector<std::type_index> m_elementsToSkip;
        bool m_skipElements;
    };

} // namespace base

#endif // SKIP_ITERATOR_H_3ecd7885_6757_4a51_8114_915a43fada62
