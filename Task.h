#include <utility>

//
// Created by ryanz on 4/24/2022.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H
#include "Time.h"


class Task {
public:
    std::string task;
    Time start;
    Time end;
    int profit;

    Task(int h1, int m1, int h2, int m2, int p, std::string task = "None")
            : start(h1, m1), end(h2, m2), profit(p), task(std::move(task)) {
        // validate
        if (p < 0) {
            throw std::invalid_argument("invalid profit");
        }
    }

    Task(Time start, Time end, int profit, std::string name = "None")
            : start(start), end(end), profit(profit), task(std::move(name)) {
        // validate
        if (profit < 0) {
            throw std::invalid_argument("invalid profit");
        }
    }

    Task(const std::string& startStr, const std::string& endStr, int p, std::string task = "None")
            : profit(p), task(std::move(task)) {
        // Now parse the times:
        try {
            start = Time::parse(startStr);
            end = Time::parse(endStr);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error parsing time: " << e.what() << std::endl;
            throw;  // Re-throw the exception.
        }

        // validate
        if (p < 0) {
            throw std::invalid_argument("invalid profit");
        }
    }


    std::string toString() const {
        std::stringstream ss;
        if  (task == "None") {
            ss << "Task: " << start.toString() << " - " << end.toString() << " Profit: " << profit;
        } else {
            ss << "Task: " << task << " " << start.toString() << " - " << end.toString() << " Profit: " << profit;
        }
        return ss.str();
    }

    bool operator>(const Task& rhs) const {
        if (profit == rhs.profit) {
            return start.getHour() > rhs.start.getHour()
                   || (start.getHour() == rhs.start.getHour() && start.getMinute() > rhs.start.getMinute());
        }
        return profit > rhs.profit;
    }
    bool operator<(const Task& rhs) const {
        if (profit == rhs.profit) {
            return start < rhs.start;
        }
        return profit < rhs.profit;
    }
    bool operator>=(const Task& rhs) const {
        return !(*this < rhs);
    }

    bool operator<=(const Task& rhs) const {
        return !(*this > rhs);
    }

    // overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Task& t) {
        os << t.toString();
        return os;
    }
};
// to sort tasks in increasing order by starting time
bool taskComparator(const Task& lhs, const Task& rhs) {
    return lhs.end < rhs.end;
}


#endif //SCHEDULER_TASK_H
