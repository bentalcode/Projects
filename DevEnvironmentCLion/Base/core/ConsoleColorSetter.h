#ifndef CONSOLE_COLOR_SETTER_H_33638183_f87c_4ce1_a3c9_9aa9e684e7e1
#define CONSOLE_COLOR_SETTER_H_33638183_f87c_4ce1_a3c9_9aa9e684e7e1

#include "IConsoleColorHandler.h"

namespace base
{
    /**
     * The ConsoleColorSetter class implements a setter of a console color.
     */
    class ConsoleColorSetter final
    {
    public:
        /**
         * The WindowsConsoleColorHandler constructor.
         */
        ConsoleColorSetter(
            IConsoleColorHandlerPtr consoleColorHandler,
            StandardFileDescriptor fileDescriptor,
            unsigned short attributes);

        /**
         * The WindowsConsoleColorHandler destructor.
         */
        ~ConsoleColorSetter();

        /**
         * The copy/move constructors.
         */
        ConsoleColorSetter(const ConsoleColorSetter&) = delete;
        ConsoleColorSetter(ConsoleColorSetter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ConsoleColorSetter& operator=(const ConsoleColorSetter&) = delete;
        ConsoleColorSetter& operator=(ConsoleColorSetter&&) = delete;

    private:
        IConsoleColorHandlerPtr m_consoleColorHandler;
        StandardFileDescriptor m_fileDescriptor;
        unsigned short m_newAttributes;
        unsigned short m_currAttributes;
        bool m_status;
    };
}

#endif // CONSOLE_COLOR_SETTER_H_33638183_f87c_4ce1_a3c9_9aa9e684e7e1
