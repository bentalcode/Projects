#ifndef I_PARAMETER_METADATA_H_fbec8048_3517_4c85_ab1e_585d55896b41
#define I_PARAMETER_METADATA_H_fbec8048_3517_4c85_ab1e_585d55896b41

#include <string>
#include <memory>
#include <map>

namespace Command {

    /**
     * The IParameterMetadata interface defines metadata of a parameter.
     */
    class IParameterMetadata
    {
    public:
        /**
         * The constructor.
         */
        IParameterMetadata() = default;

        /**
         * The destructor.
         */
        virtual ~IParameterMetadata() = default;

        /**
         * The copy/move constructors.
         */
        IParameterMetadata(const IParameterMetadata&) = delete;
        IParameterMetadata(IParameterMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParameterMetadata& operator=(const IParameterMetadata&) = delete;
        IParameterMetadata& operator=(IParameterMetadata&&) = delete;

        /**
         * Gets name of a parameter.
         */
        virtual const std::wstring& GetName() const = 0;

        /**
         * Gets description of a parameter.
         */
        virtual const std::wstring& GetDescription() const = 0;

        /**
         * Try to parse value.
         */
        virtual bool TryParseValue(
            const std::map<std::wstring, std::wstring>& parameters,
            std::wstring& value) const = 0;
    };

    //
    // Defines the SharedPtr of Parameter Metadata...
    //
    using IParameterMetadataSharedPtr = std::shared_ptr<IParameterMetadata>;

} // namespace Command

#endif // I_PARAMETER_METADATA_H_fbec8048_3517_4c85_ab1e_585d55896b41
