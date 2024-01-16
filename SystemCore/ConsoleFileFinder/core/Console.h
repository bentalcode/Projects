#ifndef CONSOLE_H_0f244364_7484_4254_bcb9_1a99aa107d45
#define CONSOLE_H_0f244364_7484_4254_bcb9_1a99aa107d45

#include "IConsole.h"

namespace consolefilefinder {

    /**
     * The Console class implements a console.
     */
    class Console final : public IConsole
    {
    public:
        /**
         * Creates a file console.
         */
        static IConsoleSharedPtr Make(std::wostream& stream);

        /**
         * The Console constructor.
         */
        Console(std::wostream& stream);

        /**
         * The Console destructor.
         */
        virtual ~Console();

        /**
         * Writes a line to console.
         */
        virtual void WriteLine(const std::wstring& content) override;

    private:
        std::wostream& m_stream;
    };

} // namespace consolefilefinder

#endif // CONSOLE_H_0f244364_7484_4254_bcb9_1a99aa107d45
