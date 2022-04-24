//
// Created by ryanz on 4/24/2022.
//

#ifndef SCHEDULER_OPTIMALSCHEDULER_H
#define SCHEDULER_OPTIMALSCHEDULER_H

#include <vector>
#import "Task.h"
// find optimal scheduling of tasks making sure the times do not overlap, and
// find the sequence of takes that produce the largest priority value, using
// dynamic programming, bottom-up approach
class OptimalScheduler {
public:
    vector<Task> tasks;
    vector<int> *schedule;
    int maxProfit;
    int idx = 0;


    OptimalScheduler(vector<Task> t) : tasks(t) {
        // validate
        if (tasks.size() == 0) {
            throw invalid_argument("invalid task");
        }
        schedule = new vector<int>[tasks.size()];
        maxProfit = findMaxProfit();
        findMaxProfitJobs();
    }

    // sort jobs in increasing order of start time
    void  taskSorter(vector<Task>& t) {
        sort(t.begin(), t.end(), taskComparator);
    }

    int findMaxProfit() {
        // sort the jobs in  increasing order according to start time
        taskSorter(tasks);
        // get the number of jobs
        int n = tasks.size();

        // base case
        if (n == 0) {
            return 0;
        }

        // 'max_profit' stores the maximum profit of non-conflicting jobs ending
        // at the i'th job
        int max_profit[n];
        // consider every job
        for (int i = 0; i < n; i++) {
            // initialize the profit of the i'th job as 0
            max_profit[i] = 0;
            // consider every job before the i'th job
            for (int j = 0; j < i; j++) {
                // if the i'th job does not overlap with the j'th job
                if (tasks[j].end <= tasks[i].start && max_profit[j] > max_profit[i]) {
                    // update the profit of the i'th job
                    max_profit[i] = max_profit[j];
                }
            }
            // update the profit of the i'th job
            max_profit[i] += tasks[i].profit;
        }
        // return the maximum profit
        return *max_element(max_profit, max_profit + n);
    }

    void findMaxProfitJobs() {
        // sort the jobs in  increasing order according to start time
        taskSorter(tasks);
        // get the number of jobs
        int n = tasks.size();

        // base case
        if (n == 0) {
            return;
        }

        // 'max_profit' stores the maximum profit of non-conflicting jobs ending
        // at the i'th job
        int max_profit[n];
        // consider every job
        for (int i = 0; i < n; i++) {
            // initialize the profit of the i'th job as 0
            max_profit[i] = 0;
            // consider every job before the i'th job
            for (int j = 0; j < i; j++) {
                // if the i'th job does not overlap with the j'th job
                if (tasks[j].end <= tasks[i].start && max_profit[j] > max_profit[i]) {
                    // update the profit of the i'th job
                    max_profit[i] = max_profit[j];
                    schedule[i] = schedule[j];
                }
            }
            // update the profit of the i'th job
            schedule[i].push_back(i);
            max_profit[i] += tasks[i].profit;
        }
        // find an index with the maximum profit
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (max_profit[i] > max_profit[index]) {
                index = i;
                idx = i;
            }
        }
    }

    void addTask(Task t) {
        tasks.push_back(t);
        schedule = new vector<int>[tasks.size()];
        maxProfit = findMaxProfit();
        findMaxProfitJobs();
    }

    string toString() {
        stringstream ss;
        ss << "Optimal Scheduler: " << endl;
        ss << "Max Profit: " << maxProfit << endl;
        ss << "Schedule:\n";
        int index = 1;
        for (int i: schedule[idx])
        {
            // add formatting so it looks nice
            if (tasks[i].task == "None") {
                ss << setw(19) << left << "Job " << index << ": ";
            } else {
                ss << setw(20) << left << tasks[i].task << ": ";
            }
            ss << setw(8) << right << tasks[i].start.to12Hour() <<
               setw(3) << left << " to " <<
               setw(8) << right << tasks[i].end.to12Hour() <<
               setw(12) << left << ", earning: $" << tasks[i].profit;
            ss << endl;
            index++;
        }
        ss << endl;
        return ss.str();
    }
};

#endif //SCHEDULER_OPTIMALSCHEDULER_H
