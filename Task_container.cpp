/**
 * @file Task_container.cpp
 * @brief Implementation file for the Task_container class managing tasks.
 */
#include "Task_container.h"
#include <iostream>
#include <fstream>
#include "TaskException.h"

 /**
  * @brief Constructor for the Task_container class.
  * Initializes the counter by loading its value from a binary file.
  */
Task_container::Task_container() {
    Task_container::load_counter();
}
Task_container::~Task_container() {
    for(int i=0;i<tasks_to_do.size();i++)
        if (tasks_to_do[i])
        {
            delete tasks_to_do[i];
            tasks_to_do[i] = nullptr;

        }
}

/**
 * @brief Saves the value of the counter to a binary file.
 */
void Task_container::save_counter() {
    std::ofstream ofs("counter.bin", std::ios::binary);
    if (ofs.is_open()) {
        ofs.write(reinterpret_cast<char*>(&done_counter), sizeof(int));
        ofs.close();
    }
    else
        cout << "blad otwarcia pliku";
}

/**
 * @brief Loads the value of the counter from a binary file.
 * If the file does not exist, initializes the counter to zero.
 */
void Task_container::load_counter() {
    std::ifstream ifs("counter.bin", std::ios::binary);
    if (ifs.is_open()) {
        ifs.read(reinterpret_cast<char*>(&done_counter), sizeof(int));
        ifs.close();
    }
    else {
        cout << "Blad otwarcia pliku";
    }
}

/**
 * @brief Marks a specific task as done by its index in the vector.
 * Increases the counter and saves it to the file.
 * @param task_index The index of the task to mark as done.
 */
void Task_container::set_task(int task_index) {
    if (task_index >= 0 && task_index < tasks_to_do.size()) {
        if (tasks_to_do[task_index]->get_task_done() == false) {
            tasks_to_do[task_index]->set_task_done(true);
            std::cout << "Task zaznaczony jako zrobiony" << std::endl;
            done_counter++;
            save_counter();
        }
        else {
            cout << "task byl juz zrobiony" << std::endl;
        }
    }
    else {
        std::cout << "Z³y index taska " << std::endl;
    }
}

/**
 * @brief Marks all tasks as done.
 * Increases the counter and saves it to the file.
 */
void Task_container::set_task_done() {
    for (auto& task : tasks_to_do) {
        if (task->get_task_done() == false) {
            task->set_task_done();
            done_counter++;
        }
    }
    std::cout << "Wszystkie zadania zaznaczone jako zrobione." << std::endl;
    save_counter();
}
/**
 * @brief Adds a new task to the container.
 * @param name The name of the task.
 * @param description The description of the task.
 */
void Task_container::add_task(const std::string& name, const std::string& description) {
    Task* temp = new Derived_Task(name, description, 0);
    tasks_to_do.push_back(temp);
    std::cout << "Task dodany prawidowo." << std::endl;
}

/**
 * @brief Removes a task from the container by its index.
 * @param task_index The index of the task to be removed.
 * @throw VectorIndexException if the index is out of bounds.
 */
void Task_container::remove_task(int task_index) {
    if (task_index >= 0 && task_index < tasks_to_do.size()) {
        delete tasks_to_do[task_index];
        tasks_to_do.erase(tasks_to_do.begin() + task_index);
        std::cout << "Task usuniety prawidlowo." << std::endl;
    }
    else {
        throw VectorIndexException("Z³y index taska.", task_index);
    }
}

/**
 * @brief Overloaded output stream operator for printing the tasks in the container.
 * @param os The output stream.
 * @param vec The vector of tasks to be printed.
 * @return The modified output stream.
 */
std::ostream& operator<<(std::ostream& os, std::vector<Task*> vec) {
    if (!vec.empty()) {
        for (int i = 0; i < vec.size(); i++) {
            os << "Numer Taska:" << i  << std::endl;
            os << "Nazwa Taska: " << vec[i]->get_task_name() << std::endl;
            os << "Opis Taska: " << vec[i]->get_task_description() << std::endl;
            os << "Czy jest zrobiony:? " << vec[i]->get_task_done()<< std::endl;
        }
    }
    else {
        os << "Brak zadan do wykonania." << std::endl;
    }
    return os;
}

/**
 * @brief Displays all tasks in the container.
 */
void Task_container::show_tasks() {
    std::cout << tasks_to_do;
}

/**
 * @brief Clears the screen of this console.
 */
void Task_container::clear_screen() {
    system("cls");
}

/**
 * @brief Adds a description to a task by its index.
 * @param task_index The index of the task to add a description to.
 */
void Task_container::add_description(int task_index) {
    if (task_index >= 0 && task_index < tasks_to_do.size()) {
        std::string new_description;
        std::cout << "Podaj nowy opis taska: ";
        std::getline(std::cin, new_description);
        tasks_to_do[task_index]->set_task_description(new_description);
        std::cout << "Udalo sie dodaæ nowy opis." << std::endl;
    }
    else {
        std::cout << "Z³y index taska." << std::endl;
    }
}

/**
 * @brief Displays the number of tasks marked as done  ..
 */
void Task_container::tasks_conter() {
    std::cout << done_counter << " tasks done \n";
}
