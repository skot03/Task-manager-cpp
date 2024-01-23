#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include "Task.h"

class Task_container {
private:
    vector<Task*> tasks_to_do;
    int done_counter=0;
public:
    Task_container();
    virtual ~Task_container();

    void save_counter();
    void set_task(int task_index);
    void add_task(const string& name, const string& description);
    void remove_task(int task_index);
    void show_tasks();
    void load_counter();
    void set_task_done();
    void clear_screen();
    void add_description(int task_index);
    void tasks_conter();

};