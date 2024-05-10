#ifndef I_SPLITTER_WINDOW_CONFIGURATION_e112b05c_4456_4a5b_9565_cd8b8a14ee37
#define I_SPLITTER_WINDOW_CONFIGURATION_e112b05c_4456_4a5b_9565_cd8b8a14ee37

#include "ISplitterSubWindowConfiguration.h"

namespace WXWidgets {

    /**
     * The ISplitterWindowConfiguration interface defines a configuration of a splitter window.
     */
    class ISplitterWindowConfiguration {
    public:
        ISplitterWindowConfiguration() = default;
        virtual ~ISplitterWindowConfiguration() = default;

        /**
         * Get a sash gravity.
         */
        virtual double GetGravity() const = 0;

        /**
         * Initializes in a box sizer.
         */
        virtual bool InitializeInBoxSizer() const = 0;

        /**
         * Gets a configuration of first window.
         */
        virtual const ISplitterSubWindowConfigurationSharedPtr GetFirstWindowConfiguration() const = 0;

        /**
         * Gets a configuration of second window.
         */
        virtual const ISplitterSubWindowConfigurationSharedPtr GetSecondWindowConfiguration() const = 0;
    };

    /**
     * Defines the Shared Ptr of Splitter Window Configuration.
     */
    using ISplitterWindowConfigurationSharedPtr = std::shared_ptr<ISplitterWindowConfiguration>;

} // namespace WXWidgets

#endif // I_SPLITTER_WINDOW_CONFIGURATION_e112b05c_4456_4a5b_9565_cd8b8a14ee37
