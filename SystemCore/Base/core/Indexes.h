#ifndef INDEXES_H_3e52ab95_6bc4_4242_8937_122765bf07c7
#define INDEXES_H_3e52ab95_6bc4_4242_8937_122765bf07c7

#include "BaseException.h"

namespace base {

    /**
     * The Indexes class implements complementary APIs for indexes.
     */
    class Indexes final {
    public:
        Indexes() = delete;
        ~Indexes() = delete;

        /**
         * Validates an index.
         */
        template <typename T>
        static void ValidateIndex(T index, T startIndex, T endIndex);

        /**
         * Gets number of indexes in a dimension.
         */
        template <typename T>
        static size_t Size(T startIndex, T endIndex);
    };

    /**
     * Validates an index.
     */
    template <typename T>
    void Indexes::ValidateIndex(T index, T startIndex, T endIndex)
    {
        if (index < startIndex || index > endIndex) {
            long errorCode = ErrorCodes::INVALID_ARG;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"Index: " << std::to_string(index) << L" is out of range."
                << L" Specified range: [" << std::to_string(startIndex) << L"-" << std::to_string(endIndex) << L"]"
                << L"; ErrorCode: " << ErrorCodes::GetErrorCodeString(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw BaseException(errorCode, errorMessage);
        }
    }

    /**
     * Gets number of indexes in a dimension.
     */
    template <typename T>
    size_t Indexes::Size(T startIndex, T endIndex)
    {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex) {
            return 0;
        }

        return endIndex - startIndex + 1;
    }

}  // namespace base

#endif // INDEXES_H_3e52ab95_6bc4_4242_8937_122765bf07c7
