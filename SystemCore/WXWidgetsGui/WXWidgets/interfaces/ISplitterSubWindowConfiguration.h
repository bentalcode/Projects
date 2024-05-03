#ifndef I_SPLITTER_SUB_WINDOW_CONFIGURATION_9f4a770a_1a8e_4d7a_b52b_43c405b15684
#define I_SPLITTER_SUB_WINDOW_CONFIGURATION_9f4a770a_1a8e_4d7a_b52b_43c405b15684

#include "IBorderWindowConfiguration.h"

namespace WXWidgets {

    /**
     * The ISplitterSubWindowConfiguration interface defines a configuration of a splitter sub window (left/right, top/bottom).
     */
    class ISplitterSubWindowConfiguration {
    public:
        ISplitterSubWindowConfiguration() = default;
        virtual ~ISplitterSubWindowConfiguration() = default;

        /**
         * Gets a proportion of window.
         */
        virtual int GetProportion() const = 0;

        /**
         * Gets a flag of window.
         */
        virtual int GetFlag() const = 0;

        /**
         * Gets optional configuration of a border window.
         */
        virtual const IBorderWindowConfigurationSharedPtr GetBorderWindowConfiguration() const = 0;

        /**
         * Gets show mode of window.
         */
        virtual bool GetShowMode() const = 0;

        /**
         * Sets show mode of window.
         */
        virtual void SetShowMode(bool mode) = 0;
    };

    /**
     * Defines the Shared Ptr of Splitter Sub Window Configuration.
     */
    using ISplitterSubWindowConfigurationSharedPtr = std::shared_ptr<ISplitterSubWindowConfiguration>;

}  // namespace WXWidgets

#endif // I_SPLITTER_SUB_WINDOW_CONFIGURATION_9f4a770a_1a8e_4d7a_b52b_43c405b15684
