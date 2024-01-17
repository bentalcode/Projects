#ifndef I_LOGIC_H_29c06ab1_e068_4fb9_b5fe_b39c608a0ac6
#define I_LOGIC_H_29c06ab1_e068_4fb9_b5fe_b39c608a0ac6

#include <memory>
#include <string>

namespace client_server {

    /**
     * The ILogic interface defines a generic logic.
     */
    class ILogic {
    public:
        ILogic() = default;
        virtual ~ILogic() = default;

        /**
         * The copy/move constructors.
         */
        ILogic(const ILogic&) = delete;
        ILogic(ILogic&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ILogic& operator=(const ILogic&) = delete;
        ILogic& operator=(ILogic&&) = delete;

        /**
         * Gets the name of the logic.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Runs the logic.
         */
        virtual void Run() = 0;
    };

    /**
     * Defines the Shared Ptr of Logic.
     */
    using ILogicSharedPtr = std::shared_ptr<ILogic>;

} // namespace client_server

#endif // I_LOGIC_H_29c06ab1_e068_4fb9_b5fe_b39c608a0ac6
