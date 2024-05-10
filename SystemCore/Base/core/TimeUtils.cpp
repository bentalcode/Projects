#include "TimeUtils.h"
#include <ctime>
#include <vector>
#include "TimeUnit.h"
#include "Indexes.h"
#include "BaseException.h"
#include <stack>

using namespace base;

const size_t TimeUtils::BUFFER_SIZE = 1024;
const std::wstring::value_type TimeUtils::TIME_SEPARATOR = L':';

/**
 * Parses a string with format.
 */
std::wstring TimeUtils::ParseString(
    const std::wstring& str, 
    const std::wstring& format)
{
    //
    // Parse a struct tm...
    //
    std::tm time = {};
    ParseTm(str, format, time);

    //
    // Convert a struct tm to a string...
    //
    std::wstring result = TmToString(time, format);

    return result;
}

/**
 * Parses string with format to a time point.
 */
std::chrono::system_clock::time_point TimeUtils::ParseStringToTimePoint(
    const std::wstring str, 
    const std::wstring& format)
{
    //
    // Parse a struct tm from string...
    //
    std::tm time = {};
    ParseTm(str, format, time);
    
    //
    // Convert a struct tm to time_t...
    //
    std::time_t timeT = TmToTimeT(time);

    //
    // Create a time point...
    //
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(timeT);

    return timePoint;
}

/**
 * Converts a time point to a string.
 */
std::wstring TimeUtils::TimePointToString(
    const std::chrono::system_clock::time_point& timePoint,
    const std::wstring& format)
{
    std::time_t timeT = std::chrono::system_clock::to_time_t(timePoint);
    std::tm tm = *std::gmtime(&timeT);
    return TmToString(tm, format);
}

/**
 * Converts a struct TM time to a string.
 */
std::wstring TimeUtils::TmToString(
    const std::tm& time, 
    const std::wstring& format)
{
    //
    // Convert a struct TM to a string with std::wcsftime...
    //
    size_t bufferSize = BUFFER_SIZE;
    std::vector<std::wstring::value_type> buffer(bufferSize);

    size_t numberOfCharactersWritten = std::wcsftime(
        &buffer[0], 
        buffer.size(), 
        format.c_str(), 
        &time);

    if (numberOfCharactersWritten == 0) {
        long errorCode = ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The TimeUtils Has failed converting a struct tm to a string"
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    buffer.resize(numberOfCharactersWritten);
    std::wstring result(buffer.begin(), buffer.end());

    return result;
}

/**
 * Gets a string representation of a duration.
 */
std::wstring TimeUtils::DurationToString(size_t milliseconds)
{
    double currMilliseconds = static_cast<double>(milliseconds);
    TimeUnitSharedPtr timeUnit = TimeUnit::MakeMilliseconds();

    size_t numberOfHours = static_cast<size_t>(timeUnit->InHours(currMilliseconds));
    currMilliseconds -= numberOfHours * (60 * 60 * 1000);

    unsigned short numberOfMinutes = 0;

    if (currMilliseconds > 0) {
        numberOfMinutes = static_cast<unsigned short>(timeUnit->InMinutes(currMilliseconds));
        currMilliseconds -= numberOfMinutes * (60 * 1000);
    }

    unsigned short numberOfSeconds = 0;

    if (currMilliseconds > 0) {
        numberOfSeconds = static_cast<unsigned short>(timeUnit->InSeconds(currMilliseconds));
        currMilliseconds -= numberOfSeconds * 1000;
    }

    unsigned short numberOfMilliseconds = static_cast<unsigned short>(currMilliseconds);

    std::wstring::value_type ch = '0';
    std::wstringstream stream;
    stream 
        << numberOfHours 
        << TIME_SEPARATOR << std::setfill(ch) << std::setw(2) << numberOfMinutes 
        << TIME_SEPARATOR << std::setfill(ch) << std::setw(2) << numberOfSeconds 
        << TIME_SEPARATOR << std::setfill(ch) << std::setw(3) << numberOfMilliseconds;

    return stream.str();
}

/**
 * Parses a duration from string.
 */
size_t TimeUtils::ParseDuration(const std::wstring& str)
{
    if (str.empty()) {
        return 0;
    }

    size_t hours = 0;
    size_t minutes = 0;
    size_t seconds = 0;
    size_t milliseconds = 0;
    
    std::stack<size_t*> stack;
    stack.push(&milliseconds);
    stack.push(&seconds);
    stack.push(&minutes);
    stack.push(&hours);

    size_t startTokenIndex = 0;

    while (!stack.empty()) {
        size_t nextSeparatorIndex = str.find_first_of(TIME_SEPARATOR, startTokenIndex);

        size_t endTokenIndex = nextSeparatorIndex != std::wstring::npos ? nextSeparatorIndex - 1 : str.length() - 1;

        size_t tokenLength = Indexes::Size(startTokenIndex, endTokenIndex);

        size_t elementValue = 0;

        if (tokenLength > 0) {
            std::wstring token = str.substr(startTokenIndex, tokenLength);
            elementValue = std::stol(token);
        }

        size_t* pElement = stack.top();
        stack.pop();
        *pElement = elementValue;

        if (nextSeparatorIndex == std::wstring::npos) {
            break;
        }

        startTokenIndex = nextSeparatorIndex + 1;
    }

    size_t totalMilliseconds = hours * 60 * 60 * 1000 + minutes * 60 * 1000 + seconds * 1000 + milliseconds;

    return totalMilliseconds;
}

/**
 * Parses a struct tm from a string.
 */
void TimeUtils::ParseTm(
    const std::wstring& str, 
    const std::wstring& format, 
    std::tm& time)
{
    //
    // Parse a struct tm...
    //
    std::wstringstream stream(str);
    std::tm structTm{};

    stream >> std::get_time(&structTm, format.c_str());

    if (stream.fail()) {
        long errorCode = ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The TimeUtils Has failed parsing a struct tm from a string"
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    //
    // Copy a struct tm...
    //
    CopyStructTm(structTm, time);
}

/**
 * Converts a struct tm to time_t.
 */
time_t TimeUtils::TmToTimeT(std::tm& time)
{
    //
    // Convert local calendar time to a time since epoch as a time_t object.
    // If the conversion is successful, the time object is modified. 
    // All fields of time are updated to fit their proper ranges. 
    // time->tm_wday and time->tm_yday are recalculated using information available in other fields.
    //
    std::time_t timeT = std::mktime(&time);
    return timeT;
}

/**
 * Converts a time_t to a struct tm.
 */
void TimeUtils::TimeTToTm(time_t timeT, std::tm& time)
{
    //
    // Convert a time_t to struct tm with std::gmtime...
    //
    struct tm* localTime = std::localtime(&timeT);

    if (localTime == nullptr) {
        long errorCode = ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The TimeUtils Has failed converting a time_t to a struct tm"
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    CopyStructTm(*localTime, time);
}

/**
 * Copies a struct tm.
 */
void TimeUtils::CopyStructTm(const std::tm& src, std::tm& dst)
{
    dst.tm_sec = src.tm_sec;
    dst.tm_min = src.tm_min;
    dst.tm_hour = src.tm_hour;
    dst.tm_mday = src.tm_mday;
    dst.tm_mon = src.tm_mon;
    dst.tm_year = src.tm_year;
    dst.tm_wday = src.tm_wday;
    dst.tm_yday = src.tm_yday;
    dst.tm_isdst = src.tm_isdst;
}
