#ifndef I_TEST_RUNNING_RESULT_H_9621735a_bf67_40ac_8d24_ff90b1240e9f
#define I_TEST_RUNNING_RESULT_H_9621735a_bf67_40ac_8d24_ff90b1240e9f

#include "DateTime.h"
#include "Duration.h"

namespace unit_testing
{
    class ITestRunningResult;
    using ITestRunningResultPtr = std::shared_ptr<ITestRunningResult>;

    /**
     * The ITestRunningResult interface defines result of a single test.
     */
    class ITestRunningResult
    {
    public :
        /**
         * The constructor.
         */
        ITestRunningResult() = default;

        /**
         * The destructor.
         */
        virtual ~ITestRunningResult() = default;

        /**
         * The copy/move constructors.
         */
        ITestRunningResult(const ITestRunningResult&) = delete;
        ITestRunningResult(ITestRunningResult&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ITestRunningResult& operator=(const ITestRunningResult&) = delete;
        ITestRunningResult& operator=(ITestRunningResult&&) = delete;

        /**
         * Gets the name of a test.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Gets the start time of a test.
         */
        virtual const base::DateTime& getStartTime() const = 0;

        /**
         * Gets the end time of a test.
         */
        virtual const base::DateTime& getEndTime() const = 0;

        /**
         * Gets the duration of a test.
         */
        virtual const base::Duration& getDuration() const = 0;

        /**
         * Gets the result status of running a test.
         */
        virtual bool getResultStatus() const = 0;

        /**
         * Gets the error message of running a test.
         */
        virtual const std::string& getErrorMessage() const = 0;

        /**
         * Gets the string representation of this instance.
         */
        virtual std::string toString() const = 0;
    };

    /**
     * Gets the information of the running result.
     */
    inline std::ostream& operator<<(std::ostream& stream, const ITestRunningResult& runningResult)
    {
        std::string string = runningResult.toString();
        stream << string;
        return stream;
    }
}

#endif // I_TEST_RUNNING_RESULT_H_9621735a_bf67_40ac_8d24_ff90b1240e9f
