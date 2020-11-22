#ifndef PROCESS_INFORMATION_H_d168b642_eb11_4dc5_b62a_55ab2522610b
#define PROCESS_INFORMATION_H_d168b642_eb11_4dc5_b62a_55ab2522610b

#include "IProcessInformation.h"

namespace command {

    /**
     * The ProcessInformation class implements an information of a process.
     */
    class ProcessInformation final : public IProcessInformation
    {
    public:
        /**
         * The ProcessInformation constructor.
         */
        ProcessInformation(
            unsigned int processId,
            const std::string& user,
            const std::vector<std::string>& arguments,
            const std::string& command,
            const std::string& commandLine,
            const base::DateTime& startTime,
            const base::Duration& totalCpuTime);

        /**
         * The destructor.
         */
        virtual ~ProcessInformation();

        /**
         * The copy/move constructors.
         */
        ProcessInformation(const ProcessInformation&) = delete;
        ProcessInformation(ProcessInformation&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ProcessInformation& operator=(const ProcessInformation&) = delete;
        ProcessInformation& operator=(ProcessInformation&&) = delete;

        /**
         * Gets the processId.
         */
        virtual unsigned int processId() const override;

        /**
         * Gets the user of the process.
         */
        virtual const std::string& user() const override;

        /**
         * Gets the arguments of the process.
         */
        virtual void arguments(std::vector<std::string>& arguments) const override;

        /**
         * Gets the executable pathname of the process.
         */
        virtual const std::string& command() const override;

        /**
         * Gets the command line of the process.
         */
        virtual const std::string& commandLine() const override;

        /**
         * Gets the start time of the process.
         */
        virtual const base::DateTime& startTime() const override;

        /**
         * Gets the total cpu time of the process.
         */
        virtual const base::Duration& totalCpuTime() const override;

    private:
        unsigned int m_processId;
        std::string m_user;
        std::vector<std::string> m_arguments;
        std::string m_command;
        std::string m_commandLine;
        base::DateTime m_startTime;
        base::Duration m_totalCpuTime;
    };

    using IProcessInformationPtr = std::shared_ptr<IProcessInformation>;
}

#endif // PROCESS_INFORMATION_H_d168b642_eb11_4dc5_b62a_55ab2522610b
