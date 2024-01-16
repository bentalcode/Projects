#ifndef I_FILE_CONSOLE_H_45e9f164_b006_459a_b10e_c67bb8624f74
#define I_FILE_CONSOLE_H_45e9f164_b006_459a_b10e_c67bb8624f74

#include <memory>

namespace consolefilefinder
{
    /**
     * The IFileConsole interface defines a file console.
     */
    class IFileConsole
    {
    public:
        /**
         * The constructor.
         */
        IFileConsole() = default;

        /**
         * The destructor.
         */
        virtual ~IFileConsole() = default;

        /**
         * The copy/move constructors.
         */
        IFileConsole(const IFileConsole&) = delete;
        IFileConsole(IFileConsole&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IFileConsole& operator=(const IFileConsole&) = delete;
        IFileConsole& operator=(IFileConsole&&) = delete;

        /**
         * Displays content of a file.
         */
        virtual void Display() = 0;
    };

    //
    // Defines the SharedPtr of File Console...
    //
    using IFileConsoleSharedPtr = std::shared_ptr<IFileConsole>;

} // namespace consolefilefinder

#endif // I_FILE_CONSOLE_H_45e9f164_b006_459a_b10e_c67bb8624f74
