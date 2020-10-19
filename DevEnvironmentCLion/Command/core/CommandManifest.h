#ifndef COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122
#define COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122

#include "ICommandManifest.h"

namespace command {

    /**
     * The CommandManifest class implements a command handler for running commands.
     */
    class CommandManifest : public ICommandManifest
    {
    public:
        /**
         * Creates a new manifest.
         */
        static ICommandManifestPtr make(
            const std::string& name,
            const std::string& description,
            const std::string& usageMessage);


        /**
         * The CommandManifest constructor.
         */
        CommandManifest(
            const std::string& name,
            const std::string& description,
            const std::string& usageMessage);

        /**
         * The CommandManifest destructor.
         */
        virtual ~CommandManifest();

        /**
         * The copy/move constructors.
         */
        CommandManifest(const CommandManifest&) = delete;
        CommandManifest(CommandManifest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CommandManifest& operator=(const CommandManifest&) = delete;
        CommandManifest& operator=(CommandManifest&&) = delete;

        /**
         * Gets name of a command.
         */
        virtual const std::string& getName() const override;

        /**
         * Gets description of a command.
         */
        virtual const std::string& getDescription() const override;

        /**
         * Gets usage message of a command.
         */
        virtual const std::string& getUsageMessage() const override;

    private:
        std::string m_name;
        std::string m_description;
        std::string m_usageMessage;
    };

    using ICommandManifestPtr = std::shared_ptr<ICommandManifest>;
}

#endif // COMMAND_MANIFEST_H_63cfd33a_1faf_4890_a86b_008a5188f122
