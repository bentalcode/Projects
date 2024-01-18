#ifndef CONSOLE_HELPER_MANIFEST_H_c634b3b9_27c1_41ba_bc8c_656f093d7a31
#define CONSOLE_HELPER_MANIFEST_H_c634b3b9_27c1_41ba_bc8c_656f093d7a31

#include "ICommandManifest.h"

namespace console_helper {

/**
 * The ConsoleHelperManifest class implements a console helper manifest.
 */
class ConsoleHelperManifest final : public command::ICommandManifest
    {
    public:
        /**
         * Creates a manifest.
         */
        static command::ICommandManifestSharedPtr Make();

        /**
         * The ConsoleHelperManifest constructor.
         */
        ConsoleHelperManifest();

        /**
         * The ConsoleHelperManifest destructor.
         */
        virtual ~ConsoleHelperManifest();

        /**
         * Gets name of a command.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets description of a command.
         */
        virtual const std::wstring& GetDescription() const override;

        /**
         * Gets help metadata of a command.
         */
        virtual const command::ICommandHelpMetadata& GetHelpMetadata() const override;

    /**
     * Gets parameter-sets metadata of a command.
     */
    virtual void GetParameterSetsMetadata(
        std::vector<command::IParameterSetMetadataSharedPtr>& parameterSetsMetadata) const override;

    private:
        /**
         * Initializes manifest.
         */
        void Initialize();

        /**
         * Creates a help metadata.
         */
        static command::ICommandHelpMetadataSharedPtr CreateHelpMetadata();

        /**
         * Creates usage message.
         */
        static std::wstring CreateUsageMessage();

        /**
         * Creates parameter sets.
         */
        static void CreateParameterSets(std::vector<command::IParameterSetMetadataSharedPtr>& parameterSets);

        /**
         * Creates a parameter set1.
         */
        static command::IParameterSetMetadataSharedPtr CreateParameterSet1();

        /**
         * Creates a parameter set2.
         */
        static command::IParameterSetMetadataSharedPtr CreateParameterSet2();

        std::wstring m_name;
        std::wstring m_description;
        command::ICommandHelpMetadataSharedPtr m_helpMetadata;
        std::vector<command::IParameterSetMetadataSharedPtr> m_parameterSets;
    };

} // namespace console_helper

#endif // CONSOLE_HELPER_MANIFEST_H_c634b3b9_27c1_41ba_bc8c_656f093d7a31
