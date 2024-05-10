#ifndef WX_OBJECT_ID_aed76adf_b752_4fde_a80e_f984215c6be1
#define WX_OBJECT_ID_aed76adf_b752_4fde_a80e_f984215c6be1

#include <atomic>

namespace wxwidgets {

    /**
     * The WXObjectId class implements a WX Object Id.
     */
    class WXObjectId final {
    public:
        WXObjectId();
        ~WXObjectId();

        static int NextId();

        /**
         * Gets the next identifier.
         */
        inline int Next();

    private:
        std::atomic<int> m_id;
    };

} // namespace wxwidgets

#endif // WX_OBJECT_ID_aed76adf_b752_4fde_a80e_f984215c6be1
