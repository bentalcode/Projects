#ifndef SPLITTER_WINDOW_CONFIGURATION_4d41ce89_ff7f_4f5a_a5f0_5cb88c1426ff
#define SPLITTER_WINDOW_CONFIGURATION_4d41ce89_ff7f_4f5a_a5f0_5cb88c1426ff

#include "ISplitterWindowConfiguration.h"

namespace WXWidgets {

    /**
     * The SplitterWindowConfiguration class implements a configuration of a splitter window.
     */
    class SplitterWindowConfiguration final : public ISplitterWindowConfiguration {
    public:
        /**
         * Creates a configuration of a splitter window.
         */
        static ISplitterWindowConfigurationSharedPtr Make(
            double gravity,
            bool initializeInBoxSizer,
            const ISplitterSubWindowConfigurationSharedPtr firstWindowConfiguration,
            const ISplitterSubWindowConfigurationSharedPtr secondWindowConfiguration);

        /**
         * Copies a configuration of a splitter window.
         */
        static ISplitterWindowConfigurationSharedPtr Copy(ISplitterWindowConfiguration& configuration);

        /**
         * The SplitterWindowConfiguration constructor.
         */
        SplitterWindowConfiguration(
            double gravity,
            bool initializeInBoxSizer,
            const ISplitterSubWindowConfigurationSharedPtr firstWindowConfiguration,
            const ISplitterSubWindowConfigurationSharedPtr secondWindowConfiguration);

        /**
         * The SplitterWindowConfiguration destructor.
         */
        virtual ~SplitterWindowConfiguration();

        /**
         * Get a sash gravity.
         */
        virtual double GetGravity() const override;

        /**
         * Initializes in a box sizer.
         */
        virtual bool InitializeInBoxSizer() const override;

        /**
         * Gets a configuration of first window.
         */
        virtual const ISplitterSubWindowConfigurationSharedPtr GetFirstWindowConfiguration() const override;

        /**
         * Gets a configuration of second window.
         */
        virtual const ISplitterSubWindowConfigurationSharedPtr GetSecondWindowConfiguration() const override;

    private:
        double m_gravity;
        bool m_initializeInBoxSizer;
        ISplitterSubWindowConfigurationSharedPtr m_firstWindowConfiguration;
        ISplitterSubWindowConfigurationSharedPtr m_secondWindowConfiguration;
    };

} // namespace WXWidgets

#endif // SPLITTER_WINDOW_CONFIGURATION_4d41ce89_ff7f_4f5a_a5f0_5cb88c1426ff
