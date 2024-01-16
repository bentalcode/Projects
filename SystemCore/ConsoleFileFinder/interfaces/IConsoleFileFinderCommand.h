#ifndef I_CONSOLE_FILE_FINDER_COMMAND_H_306d891a_af6a_49bc_ba65_3acc2703f067
#define I_CONSOLE_FILE_FINDER_COMMAND_H_306d891a_af6a_49bc_ba65_3acc2703f067

#include <memory>

namespace consolefilefinder
{
    /**
     * The IConsoleFileFinderCommand interface defines a console file finder command.
     */
    class IConsoleFileFinderCommand
    {
    public:
        /**
         * The constructor.
         */
        IConsoleFileFinderCommand() = default;

        /**
         * The destructor.
         */
        virtual ~IConsoleFileFinderCommand() = default;

        /**
         * The copy/move constructors.
         */
        IConsoleFileFinderCommand(const IConsoleFileFinderCommand&) = delete;
        IConsoleFileFinderCommand(IConsoleFileFinderCommand&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsoleFileFinderCommand& operator=(const IConsoleFileFinderCommand&) = delete;
        IConsoleFileFinderCommand& operator=(IConsoleFileFinderCommand&&) = delete;

        /**
         * Gets the command.
         */
        virtual Command::ICommand& GetCommand() = 0;
    };

    //
    // Defines the SharedPtr of Console File Finder Command...
    //
    using IConsoleFileFinderCommandSharedPtr = std::shared_ptr<IConsoleFileFinderCommand>;

} // namespace consolefilefinder

#endif // I_CONSOLE_FILE_FINDER_COMMAND_H_306d891a_af6a_49bc_ba65_3acc2703f067
