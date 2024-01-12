#ifndef CONSOLE_FILE_FINDER_COMMAND_PARAMETERS_H_9b04c516_fac6_44f3_a012_13b0a0ccd2aa
#define CONSOLE_FILE_FINDER_COMMAND_PARAMETERS_H_9b04c516_fac6_44f3_a012_13b0a0ccd2aa

#include "IConsoleFileFinderCommandParameters.h"
#include "ICommandParameters.h"

namespace consolefilefinder {

    /**
     * The ConsoleFileFinderCommandParameters class implements a console file finder command parameters.
     */
    class ConsoleFileFinderCommandParameters final : public IConsoleFileFinderCommandParameters
    {
    public:
        /**
         * Creates a console file finder command parameters.
         */
         static IConsoleFileFinderCommandParametersSharedPtr Make(const command::ICommandParameters& parameters);

        /**
         * The ConsoleFileFinderCommandParameters constructor.
         */
        explicit ConsoleFileFinderCommandParameters(const command::ICommandParameters& parameters);

        /**
         * The ConsoleFileFinderCommandParameters destructor.
         */
        virtual ~ConsoleFileFinderCommandParameters();

        /**
         * Gets path of the directory to search.
         */
        virtual const std::wstring& GetPath() const override;

        /**
         * Gets file patterns.
         */
        virtual const std::vector<std::wstring>& GetFilePatterns() const override;

    private:
        std::wstring m_path;
        std::vector<std::wstring> m_filePatterns;
    };

} // namespace consolefilefinder

#endif // CONSOLE_FILE_FINDER_COMMAND_PARAMETERS_H_9b04c516_fac6_44f3_a012_13b0a0ccd2aa
