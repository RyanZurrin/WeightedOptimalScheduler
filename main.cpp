#include <iostream>
#include "OptimalScheduler.h"

int main() {

//    Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
//    Output: 7
//    Task t1("1:00pm", "2:00pm", 4);
//    Task t2("2:00pm", "4:00pm", 3);
//    Task t3("1:00pm", "3:00pm", 1);
//    vector<Task> tasks = {t1,t2,t3};
//    int k = 2;
//
//
//    OptimalScheduler scheduler(tasks, k);
//    cout << scheduler.toString() << endl;


//    Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
//    Output: 10
//    Task t1a("1:00pm", "2:00pm", 4, "event 0");
//    Task t2a("2:00pm", "4:00pm", 3, "event 1");
//    Task t3a("1:00pm", "3:00pm", 10, "event 2");
//    vector<Task> tasks1 = {t1a,t2a,t3a};
//    int k1 = 2;
//
//    OptimalScheduler scheduler1(tasks1, k1);
//    cout << scheduler1.toString() << endl;

//    Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
//    Output: 9
    Task t1b("12:00pm", "1:00pm", 1, "event 0");
    Task t2b("1:00pm", "2:00pm", 2, "event 1");
    Task t3b("2:00pm", "3:00pm", 3, "event 2");
    Task t4b("3:00pm", "4:00pm", 4, "event 3");
    vector<Task> tasks2 = {t1b,t2b,t3b,t4b};
    int k2 = 3;

    OptimalScheduler scheduler2(tasks2, k2);
    cout << scheduler2.toString() << endl;

    return EXIT_SUCCESS;
}


////    // 8 tasks
//    Task t1("10:00am", "12:00pm", 7, "drop off food");
////    Task t2(13, 0, 15, 0, 3);
//    Task t2("1:00pm", "3:00pm", 3);
////    Task t3(16, 0, 18, 0, 2);
//    Task t3("4:00pm", "6:00pm", 2);
////    Task t4(11, 0, 16, 0, 15);
//    Task t4("11:00am", "4:00pm", 15);
////    Task t5(15, 0, 17, 0, 5);
//    Task t5("3:00pm", "5:00pm", 5);
////    Task t6(17, 0, 20, 0, 10, "netflix and chill");
//    Task t6("5:00pm", "8:00pm", 10, "netflix and chill");
////    Task t7(11, 30, 14, 0, 11, "Basketball");
//    Task t7("11:30am", "2:00pm", 11, "Basketball");
////    Task t8(14, 0, 20, 0, 10);
//    Task t8("2:00pm", "8:00pm", 10);
////    Task t9(5, 0, 6, 0, 5);
//    Task t9("5:00am", "6:00am", 5);
////    Task t10(8, 0, 10, 0, 3, "training");
//    Task t10("8:00am", "10:00am", 3, "training");
////    Task t11(20, 0, 22, 0, 20, "hack cia");
//    Task t11("8:00pm", "10:00pm", 20, "hack cia");
////    Task t12(18, 30, 21, 0, 25, "girl friend");
//    Task t12("6:30PM", "9:00PM", 25, "girl friend");
////    Task t13(4, 0, 7, 0, 12);
//    Task t13("4:00am", "7:00am", 12);
////    Task t14(8, 30, 11, 30, 15, "newspapers");
//    Task t14("8:30am", "11:30am", 15, "newspapers");
//    // add all the tasks to vector
//    vector<Task> tasks = {t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14};

//
//    scheduler.addTask(Task(5, 45, 9, 0, 7, "tutoring"));
//    scheduler.addTask(Task(15, 0, 18, 0, 30, "visit mom"));
//    cout << scheduler.toString() << endl;
