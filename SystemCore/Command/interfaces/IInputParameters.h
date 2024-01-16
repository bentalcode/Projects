#ifndef I_INPUT_PARAMETERS_H_a7aa3483_3e17_4c82_8883_fda8cdfa930b
#define I_INPUT_PARAMETERS_H_a7aa3483_3e17_4c82_8883_fda8cdfa930b

#include <string>
#include <vector>
#include <map>
#include <memory>

namespace command {

    class IndexedParameters;
    class NamedParameters;

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
        using IndexedParameters = std::vector<std::wstring>;
        virtual const IndexedParameters& GetIndexedParameters() const = 0;

        /**
         * Gets named parameters.
         */
        using NamedParameters = std::map<std::wstring, std::wstring>;
        virtual const NamedParameters& GetNamedParameters() const = 0;
    };

    //
    // Defines the SharedPtr of Input Parameters...
    //
    using IInputParametersSharedPtr = std::shared_ptr<IInputParameters>;

} // namespace command

#endif // I_INPUT_PARAMETERS_H_a7aa3483_3e17_4c82_8883_fda8cdfa930b
