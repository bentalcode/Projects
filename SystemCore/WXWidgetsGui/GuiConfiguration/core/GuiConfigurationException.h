#ifndef GUI_CONFIGURATION_EXCEPTION_ca758bf2_081d_41c7_8115_a2cb0ebb4ad7
#define GUI_CONFIGURATION_EXCEPTION_ca758bf2_081d_41c7_8115_a2cb0ebb4ad7

#include "BaseException.h"

namespace GuiConfiguration {

    /**
     * The class GuiConfigurationException class implements
     * an exception in Gui Configuration module.
     */
    class GuiConfigurationException : public base::BaseException {
    public:
        /**
         * The GuiConfigurationException constructor.
         */
        explicit GuiConfigurationException(const std::wstring& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        /**
         * The GuiConfigurationException constructor.
         */
        GuiConfigurationException(
            long errorCode,
            const std::wstring& errorMessage) :
            base::BaseException(errorCode, errorMessage)
        {
        }

        /**
         * The GuiConfigurationException destructor.
         */
        virtual ~GuiConfigurationException() = default;
    };

} // namespace GuiConfiguration

#endif // GUI_CONFIGURATION_EXCEPTION_ca758bf2_081d_41c7_8115_a2cb0ebb4ad7
