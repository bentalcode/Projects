#ifndef WINDOWS_CONSOLE_COLOR_HANDLER_H_532400e6_e026_425b_a848_7dd938587c3d
#define WINDOWS_CONSOLE_COLOR_HANDLER_H_532400e6_e026_425b_a848_7dd938587c3d

#include "IConsoleColorHandler.h"
#include <map>
#include <windows.h>

namespace base
{
    /**
     * The WindowsConsoleColorHandler class implements a Console Color Handler for Windows.
     */
    class WindowsConsoleColorHandler final : public IConsoleColorHandler
    {
    public:
        /**
         * The WindowsConsoleColorHandler constructor.
         */
        WindowsConsoleColorHandler();

        /**
         * The WindowsConsoleColorHandler destructor.
         */
        virtual ~WindowsConsoleColorHandler();

        /**
         * The copy/move constructors.
         */
        WindowsConsoleColorHandler(const WindowsConsoleColorHandler&) = delete;
        WindowsConsoleColorHandler(WindowsConsoleColorHandler&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        WindowsConsoleColorHandler& operator=(const WindowsConsoleColorHandler&) = delete;
        WindowsConsoleColorHandler& operator=(WindowsConsoleColorHandler&&) = delete;

        /**
         * Gets the current color attributes.
         * Returns true if the functions succeeds, otherwise false.
         */
        virtual bool GetColorAttributes(
            StandardFileDescriptor fileDescriptor,
            unsigned short& result) const override;

        /**
         * Sets the current color attributes.
         * Returns true if the functions succeeds, otherwise false.
         */
        virtual bool SetColorAttributes(
            StandardFileDescriptor fileDescriptor,
            unsigned short attributes) override;

        /**
         * Gets the attributes of a foreground color.
         */
        virtual unsigned short GetForegroundColorAttributes(ColorType colorType) const override;

    private:
        /**
         * Gets the handle of the file descriptor.
         */
        static HANDLE getFileDescriptorHandle(StandardFileDescriptor fileDescriptor);

        /**
         * Creates the foreground color map.
         */
        using ForegroundColorMap = std::map<ColorType, unsigned short>;
        static ForegroundColorMap* createForegroundColorMap();
    };
}

#endif // WINDOWS_CONSOLE_COLOR_HANDLER_H_532400e6_e026_425b_a848_7dd938587c3d
