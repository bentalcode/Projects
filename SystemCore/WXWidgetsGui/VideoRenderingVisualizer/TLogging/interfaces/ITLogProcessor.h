#ifndef I_TLOG_PROCESSOR_H_ca75aeb6_e293_4add_8700_5aaf605e8a62
#define I_TLOG_PROCESSOR_H_ca75aeb6_e293_4add_8700_5aaf605e8a62

#include <memory>

namespace tlogging {

    class ICallStartedRecord;
    class ICallEndedRecord;
    class ICompositorCreatedRecord;
    class ICompositorDestroyedRecord;
    class IAddViewRecord;
    class IRemoveViewRecord;
    class ISetConfigurationRecord;
    class ISetViewPropertiesRecord;

    /**
     * The ITLogProcessor interface defines a TLog Processor.
     */
    class ITLogProcessor {
    public:
        ITLogProcessor() = default;
        virtual ~ITLogProcessor() = default;

        /**
         * Processes a Call Started Record.
         */
        virtual void Process(const ICallStartedRecord& record) = 0;

        /**
         * Processes a Call Ended Record.
         */
        virtual void Process(const ICallEndedRecord& record) = 0;

        /**
         * Processes a Compositor Created Record.
         */
        virtual void Process(const ICompositorCreatedRecord& record) = 0;

        /**
         * Processes a Compositor Destroyed Record.
         */
        virtual void Process(const ICompositorDestroyedRecord& record) = 0;

        /**
         * Processes an Add View Record.
         */
        virtual void Process(const IAddViewRecord& record) = 0;

        /**
         * Processes a Remove View Record.
         */
        virtual void Process(const IRemoveViewRecord& record) = 0;

        /**
         * Processes a Set Configuration Record.
         */
        virtual void Process(const ISetConfigurationRecord& record) = 0;

        /**
         * Processes a Set View Properties Record.
         */
        virtual void Process(const ISetViewPropertiesRecord& record) = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Processor.
     */
    using ITLogProcessorSharedPtr = std::shared_ptr<ITLogProcessor>;

} // namespace tlogging

#endif // I_TLOG_PROCESSOR_H_ca75aeb6_e293_4add_8700_5aaf605e8a62

