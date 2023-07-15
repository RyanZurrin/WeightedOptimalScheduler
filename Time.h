//
// Created by ryanz on 4/24/2022.
//

#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>

using namespace std;

class Time {
    int hour;
    int minute;
public:
    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }


    // convert from 24 hour time to 12 hour time
    std::string to12Hour() const {
        std::stringstream ss;
        if (hour == 0) {
            ss << "12";
        } else if (hour > 12) {
            ss << hour - 12;
        } else {
            ss << hour;
        }
        ss << ":" << setfill('0') << setw(2) << minute << " " << (hour < 12 ? "AM" : "PM");
        return ss.str();
    }

    // time comparator ==
    bool operator==(const Time& t) const {
        return hour == t.hour && minute == t.minute;
    }
    // time comparator !=
    bool operator!=(const Time& t) const {
        return !(*this == t);
    }

    Time() : hour(0), minute(0) {}

    Time(int h, int m) : hour(h), minute(m){
        // validate
        if (h < 0 || h > 23 || m < 0 || m > 59) {
            throw std::invalid_argument("invalid time");
        }
    }

    std::string toString() const {
        std::stringstream ss;
        // convert to 12 hour time
        ss << to12Hour();
        return ss.str();
    }

    static Time parse(const std::string &timeStr) {
        std::smatch match;
        std::regex timePattern("(\\d{1,2}):(\\d{2})(am|pm|AM|PM)");

        if (std::regex_search(timeStr, match, timePattern)) {
            int hour = std::stoi(match.str(1));
            int minute = std::stoi(match.str(2));
            std::string meridiem = match.str(3);

            // Convert to 24-hour time
            if (meridiem == "pm" || meridiem == "PM") {
                hour = (hour % 12) + 12;
            } else { // AM case
                hour %= 12;
            }

            return Time(hour, minute);
        } else {
            throw std::invalid_argument("Failed to parse time string");
        }
    }

// time comparator >
    bool operator>(const Time& t) const {
        if (hour > t.hour) {
            return true;
        } else if (hour == t.hour) {
            return minute > t.minute;
        } else {
            return false;
        }
    }

// time comparator <
    bool operator<(const Time& t) const {
        if (hour < t.hour) {
            return true;
        } else if (hour == t.hour) {
            return minute < t.minute;
        } else {
            return false;
        }
    }

// time comparator >=
    bool operator>=(const Time& t) const {
        if (hour == t.hour && minute == t.minute) {
            return true;
        } else if (hour > t.hour) {
            return true;
        } else if (hour == t.hour) {
            return minute >= t.minute;
        } else {
            return false;
        }
    }

// time comparator <=
    bool operator<=(const Time& t) const {
        if (hour == t.hour && minute == t.minute) {
            return true;
        } else if (hour < t.hour) {
            return true;
        } else if (hour == t.hour) {
            return minute < t.minute;
        } else {
            return false;
        }
    }

    // overload the << operator
    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.toString();
        return os;
    }
};

// sort time by ending time
bool timeComparator(const Time& lhs, const Time& rhs)  {
    if (lhs.getHour() == rhs.getHour()) {
        return lhs.getMinute() < rhs.getMinute();
    } else {
        return lhs.getHour() < rhs.getHour();
    }
}

#endif //SCHEDULER_TIME_H
