//
// Created by ryanz on 4/24/2022.
//

#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Time {
public:
    int hour;
    int minute;
    // convert from 24 hour time to 12 hour time
    [[nodiscard]] string to12Hour() const {
        stringstream ss;
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


    Time(int h, int m) : hour(h), minute(m){
        // validate
        if (h < 0 || h > 23 || m < 0 || m > 59) {
            throw invalid_argument("invalid time");
        }
    }

    [[nodiscard]] string toString() const {
        stringstream ss;
        // convert to 12 hour time
        ss << to12Hour();
        return ss.str();
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
    if (lhs.hour == rhs.hour) {
        return lhs.minute < rhs.minute;
    } else {
        return lhs.hour < rhs.hour;
    }
}

#endif //SCHEDULER_TIME_H
