#pragma once
#include <string>
#include <iostream>

using namespace std;

#pragma once
class Task
{
protected:
	string task_name;
	string task_description;
	bool is_task_done;
public:
	virtual ~Task() {}
	 Task(string task_name, string task_description, bool is_task_done);
	 virtual void set_task_done(bool is_task_done) = 0;
	 virtual void set_task_done() = 0;
	 virtual bool get_task_done() const = 0;
	 virtual void set_task_description(const string& task_description) = 0;
	 virtual string get_task_description() const = 0;
	 virtual string get_task_name() const = 0;


};
ostream& operator<<(ostream& os, const Task& task);

class Derived_Task:public Task
{  public:
	Derived_Task(string task_name, string task_description, bool is_task_done);
	 void set_task_done(bool is_task_done);
	 void set_task_done();
	 bool get_task_done() const;
	 void set_task_description(const string& task_description);
	 string get_task_description() const;
	 string get_task_name() const;
	 ~Derived_Task() {}
	 

};
