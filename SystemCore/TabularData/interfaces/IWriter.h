#ifndef I_WRITER_H_0a18796e_672d_478f_8dc8_1894e4ff1cbe
#define I_WRITER_H_0a18796e_672d_478f_8dc8_1894e4ff1cbe

#include <string>
#include <memory>

namespace tabular_data {

/**
 * The IWriter interface defines a writer.
 */
class IWriter {
public:
    IWriter() = default;
    virtual ~IWriter() = default;

    /**
     * Writes a line.
     */
    virtual void WriteLine(const std::wstring& line) = 0;

    /**
     * Writes a new line.
     */
    virtual void NewLine() = 0;
};

/**
 * Defines the Shared Ptr of IWriter.
 */
using IWriterSharedPtr = std::shared_ptr<IWriter>;

} // namespace tabular_data

#endif // I_WRITER_H_0a18796e_672d_478f_8dc8_1894e4ff1cbe
