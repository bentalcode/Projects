#ifndef RECORD_H_71090bf8_9a7f_497b_bcf7_10a54c14e6e1
#define RECORD_H_71090bf8_9a7f_497b_bcf7_10a54c14e6e1

#include "IRecord.h"

namespace tabular_data {

/**
 * The Record class implements a Record.
 */
class Record final : public IRecord {
public:
    /**
     * Creates a Record.
     */
    static IRecordSharedPtr Make(
        size_t index, 
        const std::wstring& content);

    /**
     * The Record constructor.
     */
    Record(
        size_t index, 
        const std::wstring& content);

    /**
     * The Record destructor.
     */
    virtual ~Record();

    /**
     * Gets an index of a record.
     */
    virtual size_t GetIndex() const override;

    /**
     * Gets a content of record.
     */
    virtual const std::wstring& GetContent() const override;

private:
    size_t m_index;
    std::wstring m_content;
};

} // namespace tabular_data

#endif // RECORD_H_71090bf8_9a7f_497b_bcf7_10a54c14e6e1
