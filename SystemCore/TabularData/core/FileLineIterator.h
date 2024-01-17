#ifndef FILE_LINE_ITERATOR_H_c126ac47_2f06_4b94_b56e_da747afcbaff
#define FILE_LINE_ITERATOR_H_c126ac47_2f06_4b94_b56e_da747afcbaff

#include "IIterator.h"
#include "IRecord.h"
#include <fstream>

namespace tabular_data {

/**
 * The FileLineIterator class implements a File Line Iterator.
 */
class FileLineIterator final : public base::IIterator<IRecordSharedPtr> {
public:
    /**
     * Creates a File Line Iterator.
     */
    static base::IIteratorSharedPtr<IRecordSharedPtr> Make(const std::wstring& path);

    /**
     * The FileLineIterator constructor.
     */
    explicit FileLineIterator(const std::wstring& path);

    /**
     * The FileLineIterator destructor.
     */
    virtual ~FileLineIterator();

    /**
     * Checks whether there is a next element.
     */
    virtual bool HasNext() const override;

    /**
     * Gets the next element.
     */
    virtual IRecordSharedPtr Next() override;

    /**
     * Resets the iterator.
     */
    virtual void Reset() override;

private:
    //
    // The path of a file...
    //
    std::wstring m_path;

    //
    // Define the current line...
    //
    size_t m_currLineIndex;
    std::wstring m_currLineContent;

    //
    // Define the file stream...
    //
    using FileStreamUniquePtr = std::unique_ptr<std::wifstream>;
    FileStreamUniquePtr m_fileStream;
};

} // namespace tabular_data

#endif // FILE_LINE_ITERATOR_H_c126ac47_2f06_4b94_b56e_da747afcbaff

