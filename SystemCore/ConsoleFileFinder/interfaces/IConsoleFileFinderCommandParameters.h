#ifndef I_CONSOLE_FILE_FINDER_COMMAND_PARAMETERS_H_9cc5a9f3_4b28_4d8c_8dc0_c019fd7ba531
#define I_CONSOLE_FILE_FINDER_COMMAND_PARAMETERS_H_9cc5a9f3_4b28_4d8c_8dc0_c019fd7ba531

#include <string>
#include <vector>
#include <memory>

namespace consolefilefinder
{
    /**
     * The IConsoleFileFinderCommandParameters interface defines a console file finder command parameters.
     */
    class IConsoleFileFinderCommandParameters
    {
    public:
        /**
         * The constructor.
         */
        IConsoleFileFinderCommandParameters() = default;

        /**
         * The destructor.
         */
        virtual ~IConsoleFileFinderCommandParameters() = default;

        /**
         * The copy/move constructors.
         */
        IConsoleFileFinderCommandParameters(const IConsoleFileFinderCommandParameters&) = delete;
        IConsoleFileFinderCommandParameters(IConsoleFileFinderCommandParameters&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsoleFileFinderCommandParameters& operator=(const IConsoleFileFinderCommandParameters&) = delete;
        IConsoleFileFinderCommandParameters& operator=(IConsoleFileFinderCommandParameters&&) = delete;

        /**
         * Gets path of the directory to search.
         */
        virtual const std::wstring& GetPath() const = 0;

        /**
         * Gets file patterns.
         */
        virtual const std::vector<std::wstring>& GetFilePatterns() const = 0;
    };

    //
    // Defines the SharedPtr of Console File Finder Command Parameters...
    //
    using IConsoleFileFinderCommandParametersSharedPtr = std::shared_ptr<IConsoleFileFinderCommandParameters>;

} // namespace consolefilefinder

#endif // I_CONSOLE_FILE_FINDER_COMMAND_PARAMETERS_H_9cc5a9f3_4b28_4d8c_8dc0_c019fd7ba531
