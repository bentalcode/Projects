#ifndef CONSOLE_HELPER_PARAMETERS_H_4d6facc8_ebe5_49a8_90b9_5f1c07a9cd2d
#define CONSOLE_HELPER_PARAMETERS_H_4d6facc8_ebe5_49a8_90b9_5f1c07a9cd2d

#include "IConsoleHelperParameters.h"
#include "ICommandParameters.h"

namespace console_helper {

    /**
     * The ConsoleHelperParameters class implements console helper parameters.
     */
    class ConsoleHelperParameters final : public IConsoleHelperParameters
    {
    public:
        /**
         * Creates a console helper parameters.
         */
         static IConsoleHelperParametersSharedPtr Make(const command::ICommandParameters& parameters);

        /**
         * The ConsoleHelperParameters constructor.
         */
        explicit ConsoleHelperParameters(const command::ICommandParameters& parameters);

        /**
         * The ConsoleHelperParameters destructor.
         */
        virtual ~ConsoleHelperParameters();

        /**
         * Gets title of console.
         */
        virtual const std::wstring& GetConsoleTile() const override;

        /**
         * Gets name of pipe.
         */
        virtual const std::wstring& GetPipeName() const override;

    private:
        std::wstring m_consoleTitle;
        std::wstring m_pipeName;
    };

} // namespace console_helper

#endif // CONSOLE_HELPER_PARAMETERS_H_4d6facc8_ebe5_49a8_90b9_5f1c07a9cd2d
