#ifndef I_COMMAND_MANIFEST_H_27391c05_d0d0_4424_b93b_d03a73606520
#define I_COMMAND_MANIFEST_H_27391c05_d0d0_4424_b93b_d03a73606520

#include "ICommandHelpMetadata.h"
#include "IParameterSetMetadata.h"

namespace command {

    /**
     * The ICommandManifest interface defines a manifest of a command.
     */
    class ICommandManifest
    {
    public:
        /**
         * The constructor.
         */
        ICommandManifest() = default;

        /**
         * The destructor.
         */
        virtual ~ICommandManifest() = default;

        /**
         * The copy/move constructors.
         */
        ICommandManifest(const ICommandManifest&) = delete;
        ICommandManifest(ICommandManifest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICommandManifest& operator=(const ICommandManifest&) = delete;
        ICommandManifest& operator=(ICommandManifest&&) = delete;

        /**
         * Gets name of a command.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Gets description of a command.
         */
        virtual const std::string& getDescription() const = 0;

        /**
         * Gets help metadata of a command.
         */
        virtual const ICommandHelpMetadata& getHelpMetadata() const = 0;

        /**
         * Gets parameter-sets metadata of a command.
         */
        virtual void getParameterSets(std::vector<IParameterSetMetadataPtr>& parameterSets) const = 0;
    };

    using ICommandManifestPtr = std::shared_ptr<ICommandManifest>;
}

#endif // I_COMMAND_MANIFEST_H_27391c05_d0d0_4424_b93b_d03a73606520
