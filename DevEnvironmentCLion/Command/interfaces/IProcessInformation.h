#ifndef I_PROCESS_INFORMATION_H_66b6d8af_1a81_44b0_b484_da9e147f0f2d
#define I_PROCESS_INFORMATION_H_66b6d8af_1a81_44b0_b484_da9e147f0f2d

#include "DateTime.h"
#include "Duration.h"

namespace command {

    /**
     * The IProcessInformation interface defines an information of a process.
     */
    class IProcessInformation
    {
    public:
        /**
         * The constructor.
         */
        IProcessInformation() = default;

        /**
         * The destructor.
         */
        virtual ~IProcessInformation() = default;

        /**
         * The copy/move constructors.
         */
        IProcessInformation(const IProcessInformation&) = delete;
        IProcessInformation(IProcessInformation&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IProcessInformation& operator=(const IProcessInformation&) = delete;
        IProcessInformation& operator=(IProcessInformation&&) = delete;

        /**
         * Gets the processId.
         */
        virtual unsigned int processId() const = 0;

        /**
         * Gets the user of the process.
         */
        virtual const std::string& user() const = 0;

        /**
         * Gets the arguments of the process.
         */
        virtual void arguments(std::vector<std::string>& arguments) const = 0;

        /**
         * Gets the executable pathname of the process.
         */
        virtual const std::string& command() const = 0;

        /**
         * Gets the command line of the process.
         */
        virtual const std::string& commandLine() const = 0;

        /**
         * Gets the start time of the process.
         */
        virtual const base::DateTime& startTime() const = 0;

        /**
         * Gets the total cpu time of the process.
         */
        virtual const base::Duration& totalCpuTime() const = 0;
    };

    using IProcessInformationPtr = std::shared_ptr<IProcessInformation>;
}

#endif // I_PROCESS_INFORMATION_H_66b6d8af_1a81_44b0_b484_da9e147f0f2d
