#ifndef GL_ERROR_CODES_fc2b5ee9_ff3d_4c12_8cbb_8121df9f687e
#define GL_ERROR_CODES_fc2b5ee9_ff3d_4c12_8cbb_8121df9f687e

#include <string>
#include <map>

namespace WXWidgets {

    /**
     * The GLErrorCodes class defines error codes of Open GL.
     */
    class GLErrorCodes final {
    public:
        GLErrorCodes() = delete;
        ~GLErrorCodes() = delete;

        /**
         * Gets an error message.
         */
        static std::wstring GetErrorMessage(int errorCode);

    private:
        //
        // Defines the mapping between a error code to it's message...
        //
        using CodeToMessageMap = std::map<int, std::wstring>;

        /**
         * Gets the Code -> Message map.
         */
        static const CodeToMessageMap& GetCodeToMessageMap();

        /**
         * Initializes the Code -> Message map.
         */
        static void InitializeCodeToMessageMap(CodeToMessageMap& map);
    };

} // namespace WXWidgets

#endif // GL_ERROR_CODES_fc2b5ee9_ff3d_4c12_8cbb_8121df9f687e
