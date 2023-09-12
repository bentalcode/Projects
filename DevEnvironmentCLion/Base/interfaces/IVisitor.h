#ifndef I_VISITOR_H_528a874b_d4ba_4d63_b87b_2f7c550a0491
#define I_VISITOR_H_528a874b_d4ba_4d63_b87b_2f7c550a0491

namespace base
{
    /**
     * The IVisitor interface defines a visitor.
     */
    template <typename T>
    class IVisitor
    {
    public:
        /**
         * The constructor.
         */
        IVisitor() = default;

        /**
         * The destructor.
         */
        virtual ~IVisitor() = default;

        /**
         * The copy/move constructors.
         */
        IVisitor(const IVisitor&) = delete;
        IVisitor(IVisitor&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IVisitor& operator=(const IVisitor&) = delete;
        IVisitor& operator=(IVisitor&&) = delete;

        /**
         * Visits an element.
         */
        virtual void visit(T element) = 0;
    };

    //
    // Defines the SharedPtr of Visitor...
    //
    template <typename T>
    using IVisitorSharedPtr = std::shared_ptr<IVisitor<T>>;
}

#endif // I_VISITOR_H_528a874b_d4ba_4d63_b87b_2f7c550a0491
