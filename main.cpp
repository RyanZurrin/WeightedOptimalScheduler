#include <iostream>
#include "OptimalScheduler.h"

int main() {
//    // 8 tasks
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

    return EXIT_SUCCESS;
}
