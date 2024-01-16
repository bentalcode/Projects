#ifndef FILE_CONSOLE_H_d409aaf6_4670_40c5_8d55_13d519e8419e
#define FILE_CONSOLE_H_d409aaf6_4670_40c5_8d55_13d519e8419e

#include "IFileConsole.h"
#include "IFile.h"
#include "IConsole.h"

namespace consolefilefinder {

    /**
     * The FileConsole class implements a file console.
     */
    class FileConsole final : public IFileConsole
    {
    public:
        /**
         * Creates a file console.
         */
        static IFileConsoleSharedPtr Make(const std::wstring& path);

        /**
         * The FileConsole constructor.
         */
        FileConsole(const std::wstring& path);

        /**
         * The FileConsole destructor.
         */
        virtual ~FileConsole();

        /**
         * Displays content of a file.
         */
        virtual void Display() override;

    private:
        TabularData::IFileSharedPtr m_file;
        IConsoleSharedPtr m_console;
    };

} // namespace consolefilefinder

#endif // FILE_CONSOLE_H_d409aaf6_4670_40c5_8d55_13d519e8419e
