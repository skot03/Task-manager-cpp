/**
 * @file Task.cpp
 * @brief Implementation file for the Task class and its derived class Derived_Task.
 */
#include "Task.h"
#include "TaskException.h"
using namespace std;
 /**
  * @brief Constructor for the Task class.
  * @param task_name The name of the task.
  * @param task_description The description of the task.
  * @param is_task_done The status of the task (true if done, false otherwise).
  */
Task::Task(string task_name, string task_description, bool is_task_done) {
    this->task_name = task_name;
    this->task_description = task_description;
    this->is_task_done = is_task_done;
}

/**
 * @brief Setter method to mark the task as done or not done.
 * @param is_task_done The status to set for the task.
 */
void Derived_Task::set_task_done(bool is_task_done) {
    this->is_task_done = is_task_done;
}

/**
 * @brief Setter method to mark the task as done.
 */
void Derived_Task::set_task_done() {
    is_task_done = true;
}

/**
 * @brief Getter method to retrieve the status of the task.
 * @return True if the task is done, false otherwise.
 */
bool Derived_Task::get_task_done() const {
    return is_task_done;
}

/**
 * @brief Setter method to update the task description.
 * @param task_description The new description for the task.
 */
void Derived_Task::set_task_description(const string& task_description) {
    this->task_description = task_description;
}

/**
 * @brief Getter method to retrieve the task description.
 * @return The description of the task.
 */
string Derived_Task::get_task_description() const {
    return task_description;
}

/**
 * @brief Getter method to retrieve the task name.
 * @return The name of the task.
 */
string Derived_Task::get_task_name() const {
    return task_name;
}

/**
 * @brief Overloaded output stream operator for easy printing of task details.
 * @param os The output stream.
 * @param task The task to be printed.
 * @return The modified output stream.
 */
ostream& operator<<(ostream& os, const Task& task) {
    os << "Name: " << task.get_task_name() << endl;
    os << "Description: " << task.get_task_description() << endl;
    os << "Status: " << (task.get_task_done() ? "Done" : "To do") << endl;
    return os;
}

/**
 * @brief Constructor for the Derived_Task class.
 * @param task_name The name of the task.
 * @param task_description The description of the task.
 * @param is_task_done The status of the task (true if done, false otherwise).
 */
Derived_Task::Derived_Task(string task_name, string task_description, bool is_task_done)
    : Task(task_name, task_description, is_task_done) {
    // Additional initialization, if needed.
}
