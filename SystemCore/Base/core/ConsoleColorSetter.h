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
         * The ConsoleColorSetter constructor.
         */
        ConsoleColorSetter(
            IConsoleColorHandlerSharedPtr consoleColorHandler,
            StandardFileDescriptor fileDescriptor,
            ColorType colorType);

        /**
         * The ConsoleColorSetter constructor.
         */
        ConsoleColorSetter(
            IConsoleColorHandlerSharedPtr consoleColorHandler,
            StandardFileDescriptor fileDescriptor,
            unsigned short attributes);

        /**
         * The ConsoleColorSetter destructor.
         */
        ~ConsoleColorSetter();

        /**
         * The Copy/move constructors.
         */
        ConsoleColorSetter(const ConsoleColorSetter&) = delete;
        ConsoleColorSetter(ConsoleColorSetter&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        ConsoleColorSetter& operator=(const ConsoleColorSetter&) = delete;
        ConsoleColorSetter& operator=(ConsoleColorSetter&&) = delete;

    private:
        /**
         * Initializes the console color setter.
         */
        bool Initialize();

        IConsoleColorHandlerSharedPtr m_consoleColorHandler;
        StandardFileDescriptor m_fileDescriptor;
        unsigned short m_newAttributes;
        unsigned short m_currAttributes;
        bool m_active;
    };
}

#endif // CONSOLE_COLOR_SETTER_H_33638183_f87c_4ce1_a3c9_9aa9e684e7e1
