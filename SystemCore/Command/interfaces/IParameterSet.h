#ifndef I_PARAMETERS_SET_H_6e941b19_9b59_4ec6_a11f_02edc3e944d1
#define I_PARAMETERS_SET_H_6e941b19_9b59_4ec6_a11f_02edc3e944d1

#include "IParameter.h"
#include <map>

namespace command {

    /**
     * The IParameterSet interface defines a parameter-set.
     */
    class IParameterSet
    {
    public:
        /**
         * The constructor.
         */
        IParameterSet() = default;

        /**
         * The destructor.
         */
        virtual ~IParameterSet() = default;

        /**
         * The copy/move constructors.
         */
        IParameterSet(const IParameterSet&) = delete;
        IParameterSet(IParameterSet&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParameterSet& operator=(const IParameterSet&) = delete;
        IParameterSet& operator=(IParameterSet&&) = delete;

        /**
         * Gets index of a parameter-set.
         */
        virtual int GetIndex() const = 0;

        /**
         * Gets parameters map of a parameter-set.
         */
        virtual const std::map<std::wstring, IParameterSharedPtr>& GetParameters() const = 0;

        /**
         * Gets a parameter by a manifest name.
         * The parameter can be null.
         */
        virtual IParameterSharedPtr GetParameter(const std::wstring& name) const = 0;

        /**
         * Checks whether a parameter exists by a manifest name.
         */
        virtual bool HasParameter(const std::wstring& name) const = 0;
    };

    //
    // Defines the SharedPtr of Parameter Set...
    //
    using IParameterSetSharedPtr = std::shared_ptr<IParameterSet>;

} // namespace command

#endif // I_PARAMETERS_SET_H_6e941b19_9b59_4ec6_a11f_02edc3e944d1
