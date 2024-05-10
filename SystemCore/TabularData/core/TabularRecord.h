#ifndef TABULAR_RECORD_H_8ea4d8f7_897c_4480_bdaf_667cbee46e77
#define TABULAR_RECORD_H_8ea4d8f7_897c_4480_bdaf_667cbee46e77

#include "ITabularRecord.h"

namespace tabular_data {

/**
 * The TabularRecord class implements a Tabular Record.
 */
class TabularRecord final : public ITabularRecord {
public:
    /**
     * Creates a Tabular Record.
     */
    static ITabularRecordSharedPtr Make(
        size_t index, 
        const std::wstring& content,
        const std::vector<std::wstring>& values);

    /**
     * The TabularRecord constructor.
     */
    TabularRecord(
        size_t index,
        const std::wstring& content,
        const std::vector<std::wstring>& values);

    /**
     * The TabularRecord destructor.
     */
    virtual ~TabularRecord();

    /**
     * Gets an index of a record.
     */
    virtual size_t GetIndex() const override;

    /**
     * Gets a content of record.
     */
    virtual const std::wstring& GetContent() const override;

    /**
     * Gets a value by index.
     */
    virtual const std::wstring& GetValue(size_t index) const override;

    /**
     * Gets number of values.
     */
    virtual size_t GetSize() const override;

    /**
     * Gets all values.
     */
    virtual void GetValues(std::vector<std::wstring>& values) const override;

private:
    size_t m_index;
    std::wstring m_content; 
    std::vector<std::wstring> m_values;
};

} // namespace tabular_data

#endif // TABULAR_RECORD_H_8ea4d8f7_897c_4480_bdaf_667cbee46e77
