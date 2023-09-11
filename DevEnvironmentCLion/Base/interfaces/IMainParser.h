#ifndef I_MAIN_PARSER_H_564707ff_e4b7_49e8_b403_9fbb5a18a50d
#define I_MAIN_PARSER_H_564707ff_e4b7_49e8_b403_9fbb5a18a50d

#include "IParsingResult.h"

namespace base
{
    /**
     * The IMainParser interface defines a parser of main parameters.
     */
    template <typename T>
    class IMainParser
    {
    public:
        /**
         * The constructor.
         */
        IMainParser() = default;

        /**
         * The destructor.
         */
        virtual ~IMainParser() = default;

        /**
         * The copy/move constructors.
         */
        IMainParser(const IMainParser&) = delete;
        IMainParser(IMainParser&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMainParser& operator=(const IMainParser&) = delete;
        IMainParser& operator=(IMainParser&&) = delete;

        /**
         * Parses the parameters of main.
         */
        virtual IParsingResultPtr<T> parse(int argc, char *argv[]) = 0;
    };

    template <typename T>
    using IMainParserPtr = std::shared_ptr<IMainParser<T>>;
}

#endif // I_MAIN_PARSER_H_564707ff_e4b7_49e8_b403_9fbb5a18a50d
