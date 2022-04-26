# WeightedOptimalScheduler #
Finds a optimal schedule when given a list of task times and the  associated profit or priority of each task.<br/>
For simplicity when adding times input using 24 hour standard. This saves from having
to use a extra string flag for each time input. Times are implicity converted to 
12 hour format when displayed.
## Example Useage ## 

``` c++
    Task t1(10, 0, 12, 0, 7, "drop off food");
    Task t2(13, 0, 15, 0, 3);
    Task t3(16, 0, 18, 0, 2);
    Task t4(11, 0, 16, 0, 15);
    Task t5(15, 0, 17, 0, 5);
    Task t6(17, 0, 20, 0, 10, "netflix and chill");
    Task t7(11, 30, 14, 0, 11, "Basketball");
    Task t8(14, 0, 20, 0, 10);
    Task t9(5, 0, 6, 0, 5);
    Task t10(8, 0, 10, 0, 3, "training");
    Task t11(20, 0, 22, 0, 20, "hack cia");
    Task t12(18, 30, 21, 0, 25, "girl friend");
    Task t13(4, 0, 7, 0, 12);
    Task t14(8, 30, 11, 30, 15, "newspapers");
    // add all the tasks to vector
    vector<Task> tasks = {t1,t2,t3,t4,t5,t6,t7,t8,t8,t9,t10,t11,t12,t13,t14};


    OptimalScheduler scheduler(tasks);
    cout << scheduler.toString() << endl;

    scheduler.addTask(Task(5, 45, 9, 0, 7, "tutoring"));
    scheduler.addTask(Task(15, 0, 18, 0, 30, "visit mom"));
    cout << scheduler.toString() << endl;
```
### will Output the Following ###
> Optimal Scheduler:<br/>
Max Profit: 73<br/>
Schedule:<br/>
Job &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 1:  4:00 AM &emsp;to  7:00 AM,  &emsp; earning: $12<br/>
newspapers &emsp;&emsp;&emsp;:  8:30 AM &emsp;to 11:30 AM, &emsp;earning: $15<br/>
Basketball&emsp;&emsp;&emsp;&emsp;: 11:30 AM&emsp;to  2:00 PM, &emsp; earning: $11<br/>
Job&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 4:  3:00 PM &emsp; to  5:00 PM, &emsp; earning: $5<br/>
netflix and chill&emsp;&emsp;:  5:00 PM &emsp;to  8:00 PM,  &emsp; earning: $10<br/>
hack cia&emsp;&emsp;&emsp;&emsp;&emsp;:  8:00 PM &emsp;to 10:00 PM,&emsp;earning: $20<br/><br/>
Optimal Scheduler:<br/>
Max Profit: 93<br/>
Schedule:<br/>
Job &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 1:  4:00 AM &emsp; to  7:00 AM, &emsp;earning: $12<br/>
newspapers &emsp;&emsp;&emsp;:  8:30 AM &emsp; to 11:30 AM, &emsp;earning: $15<br/>
Basketball&emsp;&emsp;&emsp;&emsp;: 11:30 AM &emsp;to  2:00 PM, &emsp;earning: $11<br/>
visit mom&emsp;&emsp;&emsp;&emsp; :  3:00 PM &emsp; to  6:00 PM, &emsp;earning: $30<br/>
girl friend&emsp;&emsp;&emsp;&emsp; :  6:30 PM  &emsp; to  9:00 PM, &emsp;earning: $25<br/>
