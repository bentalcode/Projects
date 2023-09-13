#ifndef PARAMETER_SET_H_cba42bfc_3623_49b6_84da_19383ce899ba
#define PARAMETER_SET_H_cba42bfc_3623_49b6_84da_19383ce899ba

#include "IParameterSet.h"

namespace command {

    /**
     * The ParameterSet class implements a parameter-set.
     */
    class ParameterSet final : public IParameterSet
    {
    public:
        /**
         * Creates a new parameter set.
         */
        static IParameterSetSharedPtr make(
            int index,
            const std::vector<IParameterSharedPtr>& parameters);

        /**
         * The ParameterSet constructor.
         */
        ParameterSet(
            int index,
            const std::vector<IParameterSharedPtr>& parameters);

        /**
         * The ParameterSet destructor.
         */
        virtual ~ParameterSet();

        /**
         * The copy/move constructors.
         */
        ParameterSet(const ParameterSet&) = delete;
        ParameterSet(ParameterSet&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ParameterSet& operator=(const ParameterSet&) = delete;
        ParameterSet& operator=(ParameterSet&&) = delete;

        /**
         * Gets index of a parameter-set.
         */
        virtual int getIndex() const override;

        /**
         * Gets parameters map of a parameter-set.
         */
        using ParameterMap = std::map<std::string, IParameterSharedPtr>;
        virtual const ParameterMap& getParameters() const override;

        /**
         * Gets a parameter by a manifest name.
         * The parameter can be null.
         */
        virtual IParameterSharedPtr getParameter(const std::string& name) const override;

        /**
         * Checks whether a parameter exists by a manifest name.
         */
        virtual bool hasParameter(const std::string& name) const override;

    private:
        /**
         * Creates the parameter map.
         */
        void createParameterMap(const std::vector<IParameterSharedPtr>& parameters);

        int m_index;
        ParameterMap m_parameters;
    };

    //
    // Defines the SharedPtr of Parameter Set...
    //
    using IParameterSetSharedPtr = std::shared_ptr<IParameterSet>;
}

#endif // PARAMETER_SET_H_cba42bfc_3623_49b6_84da_19383ce899ba
