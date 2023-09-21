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
            const std::wstring& user,
            const std::vector<std::wstring>& arguments,
            const std::wstring& command,
            const std::wstring& commandLine,
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
         * Gets the ProcessId.
         */
        virtual unsigned int ProcessId() const override;

        /**
         * Gets the User of the process.
         */
        virtual const std::wstring& User() const override;

        /**
         * Gets the Arguments of the process.
         */
        virtual void Arguments(std::vector<std::wstring>& arguments) const override;

        /**
         * Gets the executable pathname of the process.
         */
        virtual const std::wstring& Command() const override;

        /**
         * Gets the Command line of the process.
         */
        virtual const std::wstring& CommandLine() const override;

        /**
         * Gets the start time of the process.
         */
        virtual const base::DateTime& StartTime() const override;

        /**
         * Gets the total cpu time of the process.
         */
        virtual const base::Duration& TotalCpuTime() const override;

    private:
        unsigned int m_processId;
        std::wstring m_user;
        std::vector<std::wstring> m_arguments;
        std::wstring m_command;
        std::wstring m_commandLine;
        base::DateTime m_startTime;
        base::Duration m_totalCpuTime;
    };

    //
    // Defines the SharedPtr of Process Information...
    //
    using IProcessInformationSharedPtr = std::shared_ptr<IProcessInformation>;

} // namespace command

#endif // PROCESS_INFORMATION_H_d168b642_eb11_4dc5_b62a_55ab2522610b
