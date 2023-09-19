#pragma once

#include <iosfwd>

namespace Utilities {

namespace Colors {

enum class FG {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CAYAN = 36,
    WHITE = 37,
    BRIGHT_BLACK = 90,
    BRIGHT_RED = 91,
    BRIGHT_GREEN = 92,
    BRIGHT_YELLOW = 93,
    BRIGHT_BLUE = 94,
    BRIGHT_MAGENTA = 95,
    BRIGHT_CAYAN = 96,
    BRIGHT_WHITE = 97
};

enum class BG {
    BLACK = 40,
    RED = 41,
    GREEN = 42,
    YELLOW = 43,
    BLUE = 44,
    MAGENTA = 45,
    CAYAN = 46,
    WHITE = 47,
    BRIGHT_BLACK = 100,
    BRIGHT_RED = 101,
    BRIGHT_GREEN = 102,
    BRIGHT_YELLOW = 103,
    BRIGHT_BLUE = 104,
    BRIGHT_MAGENTA = 105,
    BRIGHT_CAYAN = 106,
    BRIGHT_WHITE = 107
};

class Modifier final {
public:
    Modifier(FG fgColor) : m_fgColor(fgColor) {}

    ~Modifier(){};

    int GetFGCode() const { return static_cast<int>(m_fgColor); }

private:
    FG m_fgColor;
};

inline std::wostream& operator<<(std::wostream& stream, const Modifier& modifier)
{
    std::wstring format1(L"\0" + std::to_wstring(modifier.GetFGCode()) + L"[32m");
    std::wstring format2 = L"\033[32m";
    stream << format2;
    return stream;
}

}  // namespace Colors

}  // namespace Utilities
