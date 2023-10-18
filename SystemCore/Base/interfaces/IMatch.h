#ifndef I_MATCH_H_a0f1a51e_5a7f_4ec4_960a_efcc35becf1e
#define I_MATCH_H_a0f1a51e_5a7f_4ec4_960a_efcc35becf1e

#include <memory>

namespace base
{
    /**
     * The IMatch interface defines a match predicate.
     */
    template <typename T>
    class IMatch
    {
    public:
        /**
         * The constructor.
         */
        IMatch() = default;

        /**
         * The destructor.
         */
        virtual ~IMatch() = default;

        /**
         * The copy/move constructors.
         */
        IMatch(const IMatch&) = delete;
        IMatch(IMatch&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMatch& operator=(const IMatch&) = delete;
        IMatch& operator=(IMatch&&) = delete;

        /**
         * Checks whether an element is matching.
         */
        virtual bool match(const T& element) const = 0;
    };

    //
    // Defines the Shared Ptr of Match...
    //
    template <typename T>
    using IMatchSharedPtr = std::shared_ptr<IMatch<T>>;
}

#endif // I_MATCH_H_a0f1a51e_5a7f_4ec4_960a_efcc35becf1e
