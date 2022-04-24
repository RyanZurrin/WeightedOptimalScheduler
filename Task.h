//
// Created by ryanz on 4/24/2022.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H
#import "Time.h"

class Task {
public:
    std::string task;
    Time start;
    Time end;
    int profit;
    Task(int h1, int m1, int h2, int m2, int p, string task = "None") : start(h1, m1), end(h2, m2), profit(p), task(task) {
        // validate
        if (h1 < 0 || h1 > 23 || m1 < 0 || m1 > 59 || h2 < 0 || h2 > 23 || m2 < 0 || m2 > 59 || p < 0) {
            throw invalid_argument("invalid time");
        }
    }
    Task(Time start, Time end, int profit, string name = "None") : start(start), end(end), profit(profit), task(name) {
        if (start.hour < 0 || start.hour > 23 || start.minute < 0 ||
            start.minute > 59 || end.hour < 0 || end.hour > 23 ||
            end.minute < 0 || end.minute > 59 || profit < 0) {
            throw invalid_argument("invalid task");
        }
    }
    string toString() {
        stringstream ss;
        if  (task == "None") {
            ss << "Task: " << start.toString() << " - " << end.toString() << " Profit: " << profit;
        } else {
            ss << "Task: " << task << " " << start.toString() << " - " << end.toString() << " Profit: " << profit;
        }
        return ss.str();
    }
    bool operator>(const Task& rhs) const {
        if (profit == rhs.profit) {
            return start > rhs.start;
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
        return profit >= rhs.profit && start >= rhs.start && end >= rhs.end;
    }
    bool operator<=(const Task& rhs) const {
        return profit <= rhs.profit && start <= rhs.start && end <= rhs.end;
    }
    bool taskComparator(const Task& rhs) const {
        if (profit == rhs.profit) {
            return start > rhs.start;
        }
        return profit > rhs.profit;
    }
};
// to sort tasks in increasing order by starting time
bool taskComparator(const Task& lhs, const Task& rhs) {
    if (lhs.start.hour == rhs.start.hour) {
        return lhs.start.minute < rhs.start.minute;
    } else {
        return lhs.start.hour < rhs.start.hour;
    }
}


#endif //SCHEDULER_TASK_H
