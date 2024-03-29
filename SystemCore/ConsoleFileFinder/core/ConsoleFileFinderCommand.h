#ifndef CONSOLE_FILE_FINDER_COMMAND_H_be48e810_bde0_4b2c_8249_1e8af3614103
#define CONSOLE_FILE_FINDER_COMMAND_H_be48e810_bde0_4b2c_8249_1e8af3614103

#include "AbstractCommand.h"
#include "IConsoleFileFinderCommand.h"
#include "IConsoleFileFinderCommandParameters.h"
#include "IConsoleWindowManager.h"

namespace consolefilefinder {

    /**
     * The ConsoleFileFinderCommand class implements a console file finder command.
     */
    class ConsoleFileFinderCommand final : public command::AbstractCommand, public IConsoleFileFinderCommand
    {
    public:
        /**
         * Creates a console file finder command.
         */
         static IConsoleFileFinderCommandSharedPtr Make();

        /**
         * The ConsoleFileFinderCommand constructor.
         */
        ConsoleFileFinderCommand();

        /**
         * The ConsoleFileFinderCommand destructor.
         */
        virtual ~ConsoleFileFinderCommand();

        /**
         * Runs the command.
         */
        virtual void Run() override;

        /**
         * Gets the command.
         */
        virtual command::ICommand& GetCommand() override;

    private:
        /**
         * Initializes the command.
         */
        void Initialize();

        /**
         * Processes file.
         */
        static void ProcessFile(const std::wstring& path);

        /**
         * Creates console windows.
         */
        void CreateConsoleWindows();

        //
        // The parameters of command...
        //
        IConsoleFileFinderCommandParametersSharedPtr m_parameters;

        //
        // The Console Window Manager...
        //
        IConsoleWindowManagerSharedPtr m_consoleWindowManager;
    };

} // namespace consolefilefinder

#endif // CONSOLE_FILE_FINDER_COMMAND_H_be48e810_bde0_4b2c_8249_1e8af3614103
