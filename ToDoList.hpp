#ifndef TodoList_hpp
#define TodoList_hpp

#include <stdio.h>
#include "Todo.cpp"

struct linkedList
{
	Todo item;
	linkedList *next;
};

class ToDoList
{
private:
	linkedList *head;

public:
	ToDoList();
	ToDoList(const ToDoList &original);

	//Editing list
	void addItem();
	void editItem(int itemID);
	void deleteItem(int itemID);
	void deleteByType();
	void deleteByStatus();

	void writeList();
	void readList();

	//Sorting
	void sortByPriority();
	void sortByDueDate();
	void sortByCreateDate();

	//Printing
	void printAllItems();
	void printByType();
	void printByPriority();
	void printByID();
	std::string printObject(Todo todoObject);

	void mergeLists(ToDoList &merger);
	void clone(const ToDoList &cloner);
};

#endif
