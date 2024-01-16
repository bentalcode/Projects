#ifndef I_CONSOLE_H_a4ab6899_1fa4_48e9_b22c_0988f8560ddb
#define I_CONSOLE_H_a4ab6899_1fa4_48e9_b22c_0988f8560ddb

#include <memory>

namespace consolefilefinder
{
    /**
     * The IConsole interface defines a console.
     */
    class IConsole
    {
    public:
        /**
         * The constructor.
         */
        IConsole() = default;

        /**
         * The destructor.
         */
        virtual ~IConsole() = default;

        /**
         * The copy/move constructors.
         */
        IConsole(const IConsole&) = delete;
        IConsole(IConsole&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsole& operator=(const IConsole&) = delete;
        IConsole& operator=(IConsole&&) = delete;

        /**
         * Writes a line to console.
         */
        virtual void WriteLine(const std::wstring& content) = 0;
    };

    //
    // Defines the SharedPtr of Console...
    //
    using IConsoleSharedPtr = std::shared_ptr<IConsole>;

} // namespace consolefilefinder

#endif // I_CONSOLE_H_a4ab6899_1fa4_48e9_b22c_0988f8560ddb
