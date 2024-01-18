#ifndef I_CONSOLE_HELPER_PARAMETERS_H_4900a21f_de92_4f90_b15b_ce7e77c7f479
#define I_CONSOLE_HELPER_PARAMETERS_H_4900a21f_de92_4f90_b15b_ce7e77c7f479

#include <string>
#include <memory>

namespace console_helper
{
    /**
     * The IConsoleHelperParameters interface defines a Console Helper command parameters.
     */
    class IConsoleHelperParameters
    {
    public:
        /**
         * The constructor.
         */
        IConsoleHelperParameters() = default;

        /**
         * The destructor.
         */
        virtual ~IConsoleHelperParameters() = default;

        /**
         * The copy/move constructors.
         */
        IConsoleHelperParameters(const IConsoleHelperParameters&) = delete;
        IConsoleHelperParameters(IConsoleHelperParameters&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsoleHelperParameters& operator=(const IConsoleHelperParameters&) = delete;
        IConsoleHelperParameters& operator=(IConsoleHelperParameters&&) = delete;

        /**
         * Gets title of console.
         */
        virtual const std::wstring& GetConsoleTile() const = 0;

        /**
         * Gets name of pipe.
         */
        virtual const std::wstring& GetPipeName() const = 0;
    };

    //
    // Defines the SharedPtr of Console Helper Parameters...
    //
    using IConsoleHelperParametersSharedPtr = std::shared_ptr<IConsoleHelperParameters>;

} // namespace console_helper

#endif // I_CONSOLE_HELPER_PARAMETERS_H_4900a21f_de92_4f90_b15b_ce7e77c7f479
