#ifndef I_BUILDER_H_f837d9c4_e7e2_4bb8_acbe_d7eb5429521c
#define I_BUILDER_H_f837d9c4_e7e2_4bb8_acbe_d7eb5429521c

namespace base
{
    /**
     * The IBuilder interface defines a builder.
     */
    template <typename T>
    class IBuilder
    {
    public:
        /**
         * The constructor.
         */
        IBuilder() = default;

        /**
         * The destructor.
         */
        virtual ~IBuilder() = default;

        /**
         * The copy/move constructors.
         */
        IBuilder(const IBuilder&) = delete;
        IBuilder(IBuilder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IBuilder& operator=(const IBuilder&) = delete;
        IBuilder& operator=(IBuilder&&) = delete;

        /**
         * Builds a new object of type T.
         */
        virtual T build() = 0;
    };

    //
    // Defines the SharedPtr of Builder...
    //
    template <typename T>
    using IBuilderSharedPtr = std::shared_ptr<IBuilder<T>>;
}

#endif // I_BUILDER_H_f837d9c4_e7e2_4bb8_acbe_d7eb5429521c
