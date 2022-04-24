# WeightedOptimalScheduler #
Finds a optimal schedule when given a list of task times and the  associated profit or priority of each task.

## Example Useage ## 

``` c++
    Task t1(10, 0, 12, 0, 7);
    Task t2(13, 0, 15, 0, 3);
    Task t3(16, 0, 18, 0, 2);
    Task t4(11, 0, 16, 0, 15);
    Task t5(15, 0, 17, 0, 5);
    Task t6(17, 0, 20, 0, 10, "netflix and chill");
    Task t7(11, 30, 14, 0, 11, "Basketball");
    Task t8(14, 0, 20, 0, 10);
    vector<Task> tasks = {t1, t2, t3, t4, t5, t6, t7, t8};



    OptimalScheduler scheduler(tasks);
    cout << scheduler.toString() << endl;

    scheduler.addTask(Task(5, 45, 9, 0, 7, "tutoring"));
    cout << scheduler.toString() << endl;
```
### will Output the Following ###
> Optimal Scheduler:
Max Profit: 26
Schedule:
Basketball          : 11:30 AM to  2:00 PM, earning: $11
Job                2:  3:00 PM to  5:00 PM, earning: $5
netflix and chill   :  5:00 PM to  8:00 PM, earning: $10


Optimal Scheduler:
Max Profit: 33
Schedule:
tutoring            :  5:45 AM to  9:00 AM, earning: $7
Basketball          : 11:30 AM to  2:00 PM, earning: $11
Job                3:  3:00 PM to  5:00 PM, earning: $5
netflix and chill   :  5:00 PM to  8:00 PM, earning: $10
