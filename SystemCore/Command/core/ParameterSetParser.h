#ifndef PARAMETER_SET_PARSER_H_965a7fed_a43f_4426_9787_456324f9bc68
#define PARAMETER_SET_PARSER_H_965a7fed_a43f_4426_9787_456324f9bc68

#include "IParameterSetParser.h"
#include "IParameterSetMetadata.h"
#include <vector>

namespace command {

    /**
     * The ParameterSetParser class implements a parameter-set parser.
     */
    class ParameterSetParser final : public IParameterSetParser
    {
    public:
        /**
         * Creates a new parameter set parser.
         */
        static IParameterSetParserSharedPtr Make(
            const std::wstring& commandName,
            int parameterSetIndex,
            IParameterSetMetadataSharedPtr metadata);

        /**
         * The ParameterSetParser constructor.
         */
        ParameterSetParser(
            const std::wstring& commandName,
            int parameterSetIndex,
            IParameterSetMetadataSharedPtr metadata);

        /**
         * The ParameterSet destructor.
         */
        virtual ~ParameterSetParser();

        /**
         * The copy/move constructors.
         */
        ParameterSetParser(const ParameterSetParser&) = delete;
        ParameterSetParser(ParameterSetParser&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ParameterSetParser& operator=(const ParameterSetParser&) = delete;
        ParameterSetParser& operator=(ParameterSetParser&&) = delete;

        /**
         * Parses a parameter-set.
         */
        virtual IParsingResultSharedPtr<IParameterSetSharedPtr> Parse(const IInputParameters& inputParameters) override;

    private:
        /**
         * Parses indexed parameters of a parameter-set.
         */
        using ParameterVector = std::vector<IParameterSharedPtr>;
        using ParameterVectorSharedPtr = std::shared_ptr<ParameterVector>;

        IParsingResultSharedPtr<ParameterVectorSharedPtr> ParseIndexedParameters(
            const std::vector<IParameterMetadataSharedPtr>& parametersMetadata,
            const std::vector<std::wstring>& indexedParameters);

        /**
         * Parses named parameters of a parameter-set.
         */
        IParsingResultSharedPtr<ParameterVectorSharedPtr> ParseNamedParameters(
            const std::vector<IParameterMetadataSharedPtr>& parametersMetadata,
            const std::map<std::wstring, std::wstring>& namedParameters);

        std::wstring m_commandName;
        int m_parameterSetIndex;
        IParameterSetMetadataSharedPtr m_metadata;
    };

    //
    // Defines the SharedPtr of Parameter Set Parser...
    //
    using IParameterSetParserSharedPtr = std::shared_ptr<IParameterSetParser>;

} // namespace command

#endif // PARAMETER_SET_PARSER_H_965a7fed_a43f_4426_9787_456324f9bc68
