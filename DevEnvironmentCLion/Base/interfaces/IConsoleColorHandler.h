#ifndef I_CONSOLE_COLOR_HANDLER_H_2f5c7933_f285_43de_a789_00f4c4e91797
#define I_CONSOLE_COLOR_HANDLER_H_2f5c7933_f285_43de_a789_00f4c4e91797

#include "StandardFileDescriptor.h"
#include "ColorType.h"

namespace base
{
    /**
     * The IConsoleColorHandler interface defines a Console Color Handler.
     */
    class IConsoleColorHandler
    {
    public:
        /**
         * The constructor.
         */
        IConsoleColorHandler() = default;

        /**
         * The destructor.
         */
        virtual ~IConsoleColorHandler() = default;

        /**
         * The copy/move constructors.
         */
        IConsoleColorHandler(const IConsoleColorHandler&) = delete;
        IConsoleColorHandler(IConsoleColorHandler&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsoleColorHandler& operator=(const IConsoleColorHandler&) = delete;
        IConsoleColorHandler& operator=(IConsoleColorHandler&&) = delete;

        /**
         * Gets the current color attributes of the standard output.
         * Returns true if the functions succeeds, otherwise false.
         */
        virtual bool getColorAttributes(
            StandardFileDescriptor fileDescriptor,
            unsigned short& result) const = 0;

        /**
         * Sets the current color attributes.
         * Returns true if the functions succeeds, otherwise false.
         */
        virtual bool setColorAttributes(
            StandardFileDescriptor fileDescriptor,
            unsigned short attributes) = 0;

        /**
         * Gets the attributes of the foreground color.
         */
        virtual unsigned short getForegroundColorAttributes(ColorType colorType) const = 0;
    };

    //
    // Defines the SharedPtr of Console Color Handler...
    //
    using IConsoleColorHandlerSharedPtr = std::shared_ptr<IConsoleColorHandler>;
}

#endif // I_CONSOLE_COLOR_HANDLER_H_2f5c7933_f285_43de_a789_00f4c4e91797
