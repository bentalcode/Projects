#ifndef I_PARAMETER_SET_PARSER_H_a078e19a_ac9d_4e4a_bfce_06aeeceabf58
#define I_PARAMETER_SET_PARSER_H_a078e19a_ac9d_4e4a_bfce_06aeeceabf58

#include "IParsingResult.h"
#include "IParameterSet.h"

namespace Command {

    class IInputParameters;

    /**
     * The IParameterSetParser interface defines a parameter-set parser.
     */
    class IParameterSetParser
    {
    public:
        /**
         * The constructor.
         */
        IParameterSetParser() = default;

        /**
         * The destructor.
         */
        virtual ~IParameterSetParser() = default;

        /**
         * The copy/move constructors.
         */
        IParameterSetParser(const IParameterSetParser&) = delete;
        IParameterSetParser(IParameterSetParser&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParameterSetParser& operator=(const IParameterSetParser&) = delete;
        IParameterSetParser& operator=(IParameterSetParser&&) = delete;

        /**
         * Parses a parameter-set.
         */
        virtual IParsingResultSharedPtr<IParameterSetSharedPtr> Parse(const IInputParameters& inputParameters) = 0;
    };

    //
    // Defines the SharedPtr of Parameter Set...
    //
    using IParameterSetParserSharedPtr = std::shared_ptr<IParameterSetParser>;

} // namespace Command

#endif // I_PARAMETER_SET_PARSER_H_a078e19a_ac9d_4e4a_bfce_06aeeceabf58
