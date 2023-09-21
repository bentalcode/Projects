#ifndef I_PROCESS_INFORMATION_H_66b6d8af_1a81_44b0_b484_da9e147f0f2d
#define I_PROCESS_INFORMATION_H_66b6d8af_1a81_44b0_b484_da9e147f0f2d

#include "DateTime.h"
#include "Duration.h"
#include <vector>

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
         * Gets the ProcessId.
         */
        virtual unsigned int ProcessId() const = 0;

        /**
         * Gets the User of the process.
         */
        virtual const std::wstring& User() const = 0;

        /**
         * Gets the Arguments of the process.
         */
        virtual void Arguments(std::vector<std::wstring>& arguments) const = 0;

        /**
         * Gets the executable pathname of the process.
         */
        virtual const std::wstring& Command() const = 0;

        /**
         * Gets the Command line of the process.
         */
        virtual const std::wstring& CommandLine() const = 0;

        /**
         * Gets the start time of the process.
         */
        virtual const base::DateTime& StartTime() const = 0;

        /**
         * Gets the total cpu time of the process.
         */
        virtual const base::Duration& TotalCpuTime() const = 0;
    };

    //
    // Defines the SharedPtr of Process Information...
    //
    using IProcessInformationSharedPtr = std::shared_ptr<IProcessInformation>;

} // namespace command

#endif // I_PROCESS_INFORMATION_H_66b6d8af_1a81_44b0_b484_da9e147f0f2d
