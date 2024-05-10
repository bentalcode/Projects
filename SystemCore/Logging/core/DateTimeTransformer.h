#ifndef DATE_TIME_TRANSFORMER_H_fd93eec9_0ad4_4bba_90af_f8cbb7844091
#define DATE_TIME_TRANSFORMER_H_fd93eec9_0ad4_4bba_90af_f8cbb7844091

#include "IValueTransformer.h"
#include "DateTime.h"

namespace logging {

    /**
     * The DateTimeTransformer class implements a date time transformer.
     */
    class DateTimeTransformer final : public tabular_data::IValueTransformer<base::DateTimeSharedPtr> {
    public:
        /**
         * Creates a Date Time Transformer.
         */
        static tabular_data::IValueTransformerSharedPtr<base::DateTimeSharedPtr> Make(
            const std::wstring& format = L"%Y-%m-%d %H:%M:%S");

        /**
         * The DateTimeTransformer constructor.
         */
        explicit DateTimeTransformer(const std::wstring& format);

        /**
         * The DateTimeTransformer destructor.
         */
        virtual ~DateTimeTransformer();

        /**
         * Transforms a value to a date time.
         */
        virtual base::DateTimeSharedPtr Transform(const std::wstring& value) const override;

    private:
        std::wstring m_format;
    };

} // namespace logging

#endif // DATE_TIME_TRANSFORMER_H_fd93eec9_0ad4_4bba_90af_f8cbb7844091
