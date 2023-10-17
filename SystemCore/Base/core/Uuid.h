#ifndef UUID_H_dad4a35d_0ceb_42a1_ab7a_72e4fce5404e
#define UUID_H_dad4a35d_0ceb_42a1_ab7a_72e4fce5404e

#include "IUuid.h"
#include "guiddef.h"

namespace base {

    /**
     * The Uuid class implements a uuid.
     */
    class Uuid final : public IUuid {
    public:
        /**
         * Creates a new instance of a uuid.
         */
        static IUuidSharedPtr New();

        /**
         * Creates a new instance of a uuid.
         */
        static IUuidSharedPtr Make(const _GUID& guid);

        /**
         * The Uuid constructor.
         */
        explicit Uuid(const _GUID& guid);

        /**
         * The Uuid destructor.
         */
        virtual ~Uuid();

        /**
         * Gets a string representation Of this instance.
         */
        virtual std::wstring ToString() const override;

        /**
         * Parses a uuid from a string.
         */
        static IUuidSharedPtr Parse(const std::wstring& str);

        /**
         * Tries to parse a uuid from string.
         */
        static IUuidSharedPtr TryParse(const std::wstring& str);

        /**
         * Checks whether a string is a valid uuid.
         */
        static bool IsUuid(const std::wstring& str);

    private:
        /**
         * Tries to parse a guid from string.
         */
        static long TryParseUuid(const std::wstring& str, _GUID& guid);

        /**
         * Creates a uuid from string.
         */
        static void CreateUuid(_GUID& guid);

        _GUID m_guid;
    };

} // namespace base

#endif // namespace UUID_H_dad4a35d_0ceb_42a1_ab7a_72e4fce5404e
