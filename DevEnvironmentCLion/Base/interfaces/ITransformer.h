#ifndef I_TO_STRING_H_ac198e47_e151_4fe5_b8b6_01a6f212725f
#define I_TO_STRING_H_14d08249_40ab_449a_ac4f_aab15cea5793

namespace base
{
    /**
     * The ITransformer interface defines a generic transformer.
     */
    template <typename TFromObject, typename TToObject>
    class ITransformer
    {
    public:
        /**
         * The constructor.
         */
        ITransformer() = default;

        /**
         * The destructor.
         */
        virtual ~ITransformer() = default;

        /**
         * The copy/move constructors.
         */
        ITransformer(const ITransformer&) = delete;
        ITransformer(ITransformer&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ITransformer& operator=(const ITransformer&) = delete;
        ITransformer& operator=(ITransformer&&) = delete;

        /**
         * Transforms an object.
         */
        virtual TToObject transform(const TFromObject& obj) const = 0;
    };

    //
    // Defines the SharedPtr of Transformer...
    //
    template <typename T>
    using ITransformerSharedPtr = std::shared_ptr<ITransformer<T>>;
}

#endif // I_TO_STRING_H_14d08249_40ab_449a_ac4f_aab15cea5793
