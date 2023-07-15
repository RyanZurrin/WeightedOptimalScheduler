//
// Created by ryanz on 4/24/2022.
//

#ifndef SCHEDULER_OPTIMALSCHEDULER_H
#define SCHEDULER_OPTIMALSCHEDULER_H

#include <utility>
#include <vector>
#include "Task.h"
// find optimal scheduling of tasks making sure the times do not overlap, and
// find the sequence of takes that produce the largest priority value, using
// dynamic programming, bottom-up approach
class OptimalScheduler {
public:
    vector<Task> tasks;
    vector<int> *schedule;
    int maxProfit;
    int idx = 0;
    int totalTasks = -1;

    explicit OptimalScheduler(vector<Task> t, int totalTasks = -1) :
            tasks(std::move(t)), totalTasks(totalTasks) {
        // validate
        if (tasks.empty()) {
            throw invalid_argument("invalid task");
        }
        schedule = new vector<int>[tasks.size()];
        maxProfit = findMaxProfitJobs();

    }

    // sort jobs in increasing order of start time
    static void  taskSorter(vector<Task>& t) {
        sort(t.begin(), t.end(), taskComparator);
    }

    int findMaxProfitJobs() {
        // sort the jobs in increasing order according to end time
        taskSorter(tasks);

        for (auto & task : tasks) {
            cout << task.start << ", " << task.end << ", " << task.profit << endl;
        }

        // get the number of jobs
        auto n = tasks.size();

        // base case
        if (n == 0) {
            return 0;
        }

        // 'max_profit' stores the maximum profit of non-conflicting jobs ending at the i'th job
        vector<int> max_profit(n, 0);

        // consider every job
        for (int i = 0; i < n; i++) {
            // initialize the profit of the i'th job as 0
            max_profit[i] = 0;
            schedule[i].push_back(i);

            // consider every job before the i'th job
            for (int j = 0; j < i; j++) {
                // if the i'th job does not overlap with the j'th job and adding it would not exceed the task limit
                if (tasks[j].end <= tasks[i].start && (totalTasks == -1 || schedule[j].size() < totalTasks)) {
                    // if the profit of the jth task plus the ith task is higher than the current profit of the ith task
                    int newProfit = max_profit[j] + tasks[i].profit;
                    bool isTotalTasksLimitReached = (totalTasks != -1 && schedule[j].size() + 1 > totalTasks);
                    if ((newProfit > max_profit[i] || (newProfit == max_profit[i] && schedule[j].size() + 1 > schedule[i].size())) && !isTotalTasksLimitReached) {
                        max_profit[i] = newProfit;
                        schedule[i] = vector<int>(schedule[j]);  // Create a copy of schedule[j]
                        schedule[i].push_back(i);
                    }
                }
            }

            // include the profit of the i'th job if it's still profitable even after including the i'th job.
            if (max_profit[i] < tasks[i].profit) {
                max_profit[i] = tasks[i].profit;
                schedule[i] = {i};
            }
        }

        // find an index with the maximum profit
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (max_profit[i] > max_profit[index]) {
                index = i;
            }
        }

        idx = index;
        return max_profit[index];
    }


    /**
     * Add a task to the scheduler
     * @param t  the task to add
     */
    void addTask(const Task& t) {
        if (schedule != nullptr) {
            delete[] schedule;
        }
        tasks.push_back(t);
        schedule = new vector<int>[tasks.size()];
        maxProfit = findMaxProfitJobs();
    }

    /**
     * Convert the scheduler to a string
     * @return  the string representation of the scheduler
     */
    string toString() {
        stringstream ss;
        ss << "Optimal Scheduler: " << endl;
        ss << "Max Profit: " << maxProfit << endl;
        ss << "Schedule:\n";

        // Find the maximum task name length
        int maxTaskNameLength = 0;
        for (const auto &task : tasks) {
            if (task.task != "None" && task.task.length() > maxTaskNameLength) {
                maxTaskNameLength = task.task.length();
            }
        }

        int index = 1;
        for (int i: schedule[idx]) {
            // add formatting so it looks nice
            string taskName = tasks[i].task == "None" ? "Job" + to_string(index) : tasks[i].task;
            ss << setw(maxTaskNameLength + 1) << left << taskName <<
               setw(3) << right << index << ": " <<
               setw(8) << right << tasks[i].start <<
               setw(3) << left << " to " <<
               setw(8) << right << tasks[i].end <<
               setw(12) << left << ", earning: $" << tasks[i].profit;
            ss << endl;
            index++;
        }
        ss << endl;
        return ss.str();
    }


    // overload the << operator
    friend ostream& operator<<(ostream& os, OptimalScheduler scheduler) {
        os << scheduler.toString();
        return os;
    }

    ~OptimalScheduler() {
        if (schedule != nullptr) {
            delete[] schedule;
        }
    }


};

#endif //SCHEDULER_OPTIMALSCHEDULER_H
