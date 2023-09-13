#ifndef INPUT_PARAMETERS_H_d6e509a4_0789_4690_9505_1de4baa68b2b
#define INPUT_PARAMETERS_H_d6e509a4_0789_4690_9505_1de4baa68b2b

#include "IInputParameters.h"

namespace command {

    /**
     * The InputParameters class implements input parameters of a command.
     */
    class InputParameters final : public IInputParameters
    {
    public:
        /**
         * Makes new input parameters.
         */
        static IInputParametersSharedPtr make(
            const std::vector<std::string>& indexedParameters,
            const std::map<std::string, std::string>& namedParameters);

        /**
         * The constructor.
         */
        InputParameters(
            const std::vector<std::string>& indexedParameters,
            const std::map<std::string, std::string>& namedParameters);

        /**
         * The destructor.
         */
        virtual ~InputParameters();

        /**
         * The copy/move constructors.
         */
        InputParameters(const InputParameters&) = delete;
        InputParameters(InputParameters&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        InputParameters& operator=(const InputParameters&) = delete;
        InputParameters& operator=(InputParameters&&) = delete;

        /**
         * Gets indexed parameters.
         */
        virtual const IndexedParameters& getIndexedParameters() const override;

        /**
         * Gets named parameters.
         */
        virtual const NamedParameters& getNamedParameters() const override;

    private:
        std::vector<std::string> m_indexedParameters;
        std::map<std::string, std::string> m_namedParameters;
    };

    //
    // Defines the SharedPtr of Input Parameter...
    //
    using IInputParametersSharedPtr = std::shared_ptr<IInputParameters>;
}

#endif // INPUT_PARAMETERS_H_d6e509a4_0789_4690_9505_1de4baa68b2b
