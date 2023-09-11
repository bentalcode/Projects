#ifndef I_INPUT_PARAMETERS_H_a7aa3483_3e17_4c82_8883_fda8cdfa930b
#define I_INPUT_PARAMETERS_H_a7aa3483_3e17_4c82_8883_fda8cdfa930b

namespace command {

    /**
     * The IInputParameters interface defines input parameters of a command.
     */
    class IInputParameters
    {
    public:
        /**
         * The constructor.
         */
        IInputParameters() = default;

        /**
         * The destructor.
         */
        virtual ~IInputParameters() = default;

        /**
         * The copy/move constructors.
         */
        IInputParameters(const IInputParameters&) = delete;
        IInputParameters(IInputParameters&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IInputParameters& operator=(const IInputParameters&) = delete;
        IInputParameters& operator=(IInputParameters&&) = delete;

        /**
         * Gets indexed parameters.
         */
        using IndexedParameters = std::vector<std::string>;
        virtual const IndexedParameters& getIndexedParameters() const = 0;

        /**
         * Gets named parameters.
         */
        using NamedParameters = std::map<std::string, std::string>;
        virtual const NamedParameters& getNamedParameters() const = 0;
    };

    using IInputParametersPtr = std::shared_ptr<IInputParameters>;
}

#endif // I_INPUT_PARAMETERS_H_a7aa3483_3e17_4c82_8883_fda8cdfa930b
