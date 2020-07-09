#ifndef I_TEST_RUNNING_RESULT_H_1ddd4663_6014_4b1c_abca_2b77ecbac123
#define I_TEST_RUNNING_RESULT_H_1ddd4663_6014_4b1c_abca_2b77ecbac123

#include "DateTime.h"

namespace unit_testing
{
    class ITestRunningResult;
    using ITestRunningResultPtr = std::shared_ptr<ITestRunningResult>;

    using Duration = base::Duration<double>;
    using DurationPtr = std::shared_ptr<Duration>;

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
        virtual const Duration& getDuration() const = 0;

        /**
         * Gets the result status of running a test.
         */
        virtual bool getResultStatus() const = 0;

        /**
         * Gets the error message of running a test.
         */
        virtual const std::string& getErrorMessage() const = 0;

        /**
         * Gets the information of the running result.
         */
        virtual void getRunningResultInformation(std::ostream& stream) const = 0;
    };

    /**
     * Gets the information of the running result.
     */
    inline std::ostream& operator<<(std::ostream& stream, const ITestRunningResult& runningResult)
    {
        runningResult.getRunningResultInformation(stream);
        return stream;
    }
}

#endif // I_TEST_RUNNING_RESULT_H_1ddd4663_6014_4b1c_abca_2b77ecbac123
