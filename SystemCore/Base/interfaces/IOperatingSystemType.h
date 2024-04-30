#ifndef I_OPERATING_SYSTEM_TYPE_H_691a7d1a_d3ef_4430_9c8a_4eb8662ee76f
#define I_OPERATING_SYSTEM_TYPE_H_691a7d1a_d3ef_4430_9c8a_4eb8662ee76f

#include <string>
#include <memory>

namespace base {

    /**
     * The IOperatingSystemType interface defines an operating system type.
     */
    class IOperatingSystemType {
    public:
        /**
         * The IOperatingSystemType constructor.
         */
        IOperatingSystemType() = default;

        /**
         * The IOperatingSystemType destructor.
         */
        virtual ~IOperatingSystemType() = default;

        /**
         * Checks whether this is an operating system based on the system value.
         */
        virtual bool IsOperatingSystem(const std::wstring& value) const = 0;

        /**
         * Creates control settings of an operating system.
         */
        //virtual IOperatingSystemControlSettings createControlSettings() const = 0;
    };

    /**
     * Defines the Shared Ptr of Operating System Type.
     */
    using IOperatingSystemTypeSharedPtr = std::shared_ptr<IOperatingSystemType>;

}  // namespace base

#endif // I_OPERATING_SYSTEM_TYPE_H_691a7d1a_d3ef_4430_9c8a_4eb8662ee76f
