#ifndef SPLITTER_SUB_WINDOW_CONFIGURATION_c0023bc8_bd12_4c8d_aa98_8e5cafce1174
#define SPLITTER_SUB_WINDOW_CONFIGURATION_c0023bc8_bd12_4c8d_aa98_8e5cafce1174

#include "ISplitterSubWindowConfiguration.h"

namespace WXWidgets {

    /**
     * The ISplitterSubWindowConfiguration class implements a configuration of a splitter sub window (left/right, top/bottom).
     */
    class SplitterSubWindowConfiguration final : public ISplitterSubWindowConfiguration {
    public:
        /**
         * Creates a configuration of a splitter sub window.
         */
        static ISplitterSubWindowConfigurationSharedPtr Make(
            int proportion,
            int flag,
            const IBorderWindowConfigurationSharedPtr borderWindowConfiguration = nullptr,
            bool showMode = true);

        /**
         * Copies a configuration of a splitter sub window.
         */
        static ISplitterSubWindowConfigurationSharedPtr Copy(const ISplitterSubWindowConfiguration& configuration);

        /**
         * The SplitterSubWindowConfiguration constructor.
         */
        SplitterSubWindowConfiguration(
            int proportion,
            int flag,
            const IBorderWindowConfigurationSharedPtr borderWindowConfiguration,
            bool showMode);

        /**
         * The SplitterSubWindowConfiguration destructor.
         */
        virtual ~SplitterSubWindowConfiguration();

        /**
         * Gets a proportion of window.
         */
        virtual int GetProportion() const override;

        /**
         * Gets a flag of window.
         */
        virtual int GetFlag() const override;

        /**
         * Gets optional configuration of a border window.
         */
        virtual const IBorderWindowConfigurationSharedPtr GetBorderWindowConfiguration() const override;

        /**
         * Gets show mode of window.
         */
        virtual bool GetShowMode() const override;

        /**
         * Sets show mode of window.
         */
        virtual void SetShowMode(bool mode) override;


    private:
        int m_proportion;
        int m_flag;
        const IBorderWindowConfigurationSharedPtr m_borderWindowConfiguration;
        bool m_showMode;
    };

} // namespace WXWidgets

#endif // SPLITTER_SUB_WINDOW_CONFIGURATION_c0023bc8_bd12_4c8d_aa98_8e5cafce1174
