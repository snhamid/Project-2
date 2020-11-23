#include "ToDoList.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

ToDoList::ToDoList()
{
    head = new linkedList;
    head->next = nullptr;
}

ToDoList::ToDoList(const ToDoList &original)
{
    this->head = new linkedList;

    linkedList *oldHead = original.head;
    linkedList *newHead = this->head;
    linkedList *temp = new linkedList;

    while (oldHead != nullptr)
    {
        newHead->item = oldHead->item;
        newHead->next = new linkedList;

        temp = newHead;
        oldHead = oldHead->next;
        newHead = newHead->next;
    }
    temp->next = nullptr;
}

void ToDoList::addItem()
{
    linkedList *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    if (head->item.getPriority() == 0)
    {
        head->item.fillInfo();
    }
    else
    {
        temp->next = new linkedList();
        temp->next->next = nullptr;
        temp->next->item.fillInfo();
    }
}

void ToDoList::editItem(int itemID)
{
    int selection;
    std::string newString;
    int newPriority;
    int day;
    int month;
    int year;
    linkedList *ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->item.getID() == itemID)
        {
            std::cout << "What would you like to edit? Enter a number: \n";
            std::cout << "1. Title\n";
            std::cout << "2. Description\n";
            std::cout << "3. Type\n";
            std::cout << "4. Priority\n";
            std::cout << "5. Status\n";
            std::cout << "6. Due date\n";
            std::cout << "Enter 0 to exit\n";
            std::cin >> selection;

            switch (selection)
            {
            case 1:
                std::cout << "Enter a new title: ";
                std::cin >> newString;
                ptr->item.setTitle(newString);
                break;

            case 2:

                std::cout << "Enter a new description: ";
                std::getline(std::cin, newString);
                ptr->item.setDescription(newString);
                break;

            case 3:
                std::cout << "Enter a new type: ";
                std::cin >> newString;
                ptr->item.setType(newString);
                break;

            case 4:
                std::cout << "Enter a new priority: ";
                std::cin >> newPriority;
                ptr->item.setPriority(newPriority);
                break;

            case 5:
                std::cout << "Enter a new status: ";
                std::cin >> newPriority;
                ptr->item.setStatus(newString);

            case 6:
                std::cout << "Enter a new due date: \n";
                std::cout << "Day: ";
                std::cin >> day;
                std::cout << "\n";
                std::cout << "Enter a month: ";
                std::cin >> month;
                std::cout << "\n";
                std::cout << "Enter a year: ";
                std::cin >> year;
                ptr->item.setDueDate(day, month, year);

            default:
                break;
            }

            ptr->item.setLastModified();
            break;
        }
        ptr = ptr->next;
    }
}

void ToDoList::deleteItem(int itemID)
{
    linkedList *ptr = head;
    linkedList *previous = head;
    while (ptr != nullptr)
    {
        if (ptr->item.getID() == itemID)
        {
            if (head->next == nullptr)
            {
                head->item.setPriority(0);
            }
            else if (ptr == head)
            {
                linkedList *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                previous->next = ptr->next;
                delete ptr;
            }
            break;
        }
        previous = ptr;
        ptr = ptr->next;
    }
}

void ToDoList::deleteByType()
{

    linkedList *ptr = head;
    linkedList *previous = head;
    bool condition = true;

    while (ptr != nullptr)
    {
        int selection;
        std::cout << "Select the type to delete: \n";
        std::cout << "1. Shopping \n";
        std::cout << "2. Housing \n";
        std::cout << "3. Work \n";
        std::cin >> selection;

        switch (selection)
        {
        case 1:
            if (ptr->item.getType() == "shopping")
            {
                if (head->next == nullptr)
                {
                    head->item.setPriority(0);
                }
                else if (ptr == head)
                {
                    linkedList *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    previous->next = ptr->next;
                    delete ptr;
                }
            }
            break;

        case 2:
            if (ptr->item.getType() == "housing")
            {
                if (head->next == nullptr)
                {
                    head->item.setPriority(0);
                }
                else if (ptr == head)
                {
                    linkedList *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    previous->next = ptr->next;
                    delete ptr;
                }
            }
            break;

        case 3:
            if (ptr->item.getType() == "work")
            {
                if (head->next == nullptr)
                {
                    head->item.setPriority(0);
                }
                else if (ptr == head)
                {
                    linkedList *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    previous->next = ptr->next;
                    delete ptr;
                }
            }
            break;

        default:
            break;
        }

        ptr = ptr->next;
        if (ptr == nullptr)
        {
            break;
        }
    }
}

void ToDoList::deleteByStatus()
{

    linkedList *ptr = head;
    linkedList *previous = head;

    int selection;
    std::cout << "Select the status to delete: \n";
    std::cout << "1. Done\n";
    std::cout << "2. In progress\n";
    std::cout << "3. Hold\n";
    std::cin >> selection;

    while (ptr != nullptr)
    {
        switch (selection)
        {
        case 1:
            if (ptr->item.getType() == "done")
            {
                if (head->next == nullptr)
                {
                    head->item.setPriority(0);
                }
                else if (ptr == head)
                {
                    linkedList *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    previous->next = ptr->next;
                    delete ptr;
                }
            }
            break;

        case 2:
            if (ptr->item.getType() == "inprogress")
            {
                if (head->next == nullptr)
                {
                    head->item.setPriority(0);
                }
                else if (ptr == head)
                {
                    linkedList *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    previous->next = ptr->next;
                    delete ptr;
                }
            }
            break;

        case 3:
            if (ptr->item.getType() == "hold")
            {
                if (head->next == nullptr)
                {
                    head->item.setPriority(0);
                }
                else if (ptr == head)
                {
                    linkedList *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    previous->next = ptr->next;
                    delete ptr;
                }
            }
            break;

        default:
            break;
        }
        ptr = ptr->next;
        if (ptr == nullptr)
        {
            break;
        }
    }
}

void ToDoList::writeList()
{
    std::ofstream listFileOut;
    listFileOut.open("list.txt");
    int i = 0;
    linkedList *ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->item.getPriority() == 0)
        {
        }
        else
        {
            listFileOut << printObject(ptr->item) << std::endl;
        }
        ptr = ptr->next;
    }
}

void ToDoList::readList()
{
    std::ifstream readFile;
    readFile.open("list.txt");
    std::string line;
    std::string s;
    int month;
    int day;
    int year;
    std::string getDate;
    int infoNum = 1;
    int numLines = 0;
    int i = 0;

    std::string typeIn;
    std::string priorityIn;
    std::string titleIn;
    std::string desIn;
    std::string statusIn;
    std::string createIn;
    std::string dueIn;
    std::string lastIn;

    linkedList *ptr = head;

    while (ptr != nullptr)
    {

        while (!readFile.eof())
        {

            getline(readFile, priorityIn, ',');
            getline(readFile, titleIn, ',');
            getline(readFile, desIn, ',');
            getline(readFile, typeIn, ',');
            getline(readFile, statusIn, ',');
            getline(readFile, createIn, ',');
            getline(readFile, dueIn, ',');
            getline(readFile, lastIn, ',');

            ptr->item.setPriority(stoi(priorityIn));
            ptr->item.setTitle(titleIn);
            ptr->item.setDescription(desIn);
            ptr->item.setType(typeIn);
            ptr->item.setStatus(statusIn);

            day = stoi(createIn.substr(0, 2));
            month = stoi(createIn.substr(3, 2));
            year = stoi(createIn.substr(6, 10));
            ptr->item.setCreateDateNum(day, month, year);

            day = stoi(dueIn.substr(0, 2));
            month = stoi(dueIn.substr(3, 2));
            year = stoi(dueIn.substr(6, 10));
            ptr->item.setDueDate(day, month, year);
            ptr->item.setLastModified();
        }
        ptr = ptr->next;
    }
}

void ToDoList::sortByPriority()
{

    linkedList *j = head;
    linkedList *i = nullptr;
    linkedList *minor = nullptr;
    Todo temp;

    while (j != nullptr)
    {
        minor = j;
        i = j->next;
        while (i != nullptr)
        {
            if (i->item.getPriority() < minor->item.getPriority())
            {
                minor = i;
            }
            i = i->next;
        }
        temp = j->item;
        j->item = minor->item;
        minor->item = temp;
        j = j->next;
    }
}

void ToDoList::sortByDueDate()
{
    linkedList *j = head;
    linkedList *i = nullptr;
    linkedList *minor = nullptr;

    while (j != nullptr)
    {
        minor = j;
        i = j->next;
        while (i != nullptr)
        {
            if (i->item.getDueDateY() < minor->item.getDueDateY())
            {
                minor = i;
            }
            else if (i->item.getDueDateY() == minor->item.getDueDateY() && (i->item.getDueDateM() < minor->item.getDueDateM()))
            {
                minor = i;
            }
            else if (i->item.getDueDateY() == minor->item.getDueDateY() && (i->item.getDueDateM() == minor->item.getDueDateM()) && (i->item.getDueDateD() < minor->item.getDueDateD()))
            {
                minor = i;
            }
            i = i->next;
        }
        Todo temp = j->item;
        j->item = minor->item;
        minor->item = temp;
        j = j->next;
    }
}

void ToDoList::sortByCreateDate()
{
    linkedList *j = head;
    linkedList *i = nullptr;
    linkedList *minor = nullptr;

    while (j != nullptr)
    {
        minor = j;
        i = j->next;
        while (i != nullptr)
        {
            if (i->item.getCreateDateY() < minor->item.getCreateDateY())
            {
                minor = i;
            }
            else if (i->item.getCreateDateY() == minor->item.getCreateDateY() && (i->item.getCreateDateM() < minor->item.getCreateDateM()))
            {
                minor = i;
            }
            else if (i->item.getCreateDateY() == minor->item.getCreateDateY() && (i->item.getCreateDateM() == minor->item.getCreateDateM()) && (i->item.getCreateDateD() < minor->item.getCreateDateD()))
            {
                minor = i;
            }
            i = i->next;
        }
        Todo temp = j->item;
        j->item = minor->item;
        minor->item = temp;
        j = j->next;
    }
}

void ToDoList::printAllItems()
{
    linkedList *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->item.getPriority() == 0)
        {
        }
        else
        {
            std::cout << printObject(ptr->item) + "\n";
            ptr = ptr->next;
        }
    }
}

void ToDoList::printByType()
{
    int selection;
    linkedList *ptr = head;
    std::cout << "Select a type to print: \n";
    std::cout << "1. Shopping \n";
    std::cout << "2. Work \n";
    std::cout << "3. Housing \n";
    std::cin >> selection;

    while (ptr != nullptr)
    {
        switch (selection)
        {
        case 1:

            if (ptr->item.getType() == "shopping")
            {
                std::cout << printObject(ptr->item) + "\n";
            }
            else
            {
            }

            break;

        case 2:
            if (ptr->item.getType() == "work")
            {
                std::cout << printObject(ptr->item) + "\n";
            }
            else
            {
            }

            break;

        case 3:
            if (ptr->item.getType() == "housing")
            {
                std::cout << printObject(ptr->item) + "\n";
            }
            else
            {
            }
            break;

        default:
            break;
        }
        ptr = ptr->next;
    }
}

void ToDoList::printByPriority()
{
    int selection;
    std::cout << "Select priority to print (1-5): \n";
    std::cin >> selection;
    std::cout << "\n";
    linkedList *ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->item.getPriority() == selection)
        {
            std::cout << printObject(ptr->item) + "\n";
        }
        else
        {
        }
        ptr = ptr->next;
    }
}

void ToDoList::printByID()
{
    int selection;
    std::cout << "Enter ID to print: \n";
    std::cin >> selection;
    std::cout << "\n";
    linkedList *ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->item.getID() == selection)
        {
            std::cout << printObject(ptr->item) + "\n";
        }
        else
        {
        }

        ptr = ptr->next;
    }
}

void ToDoList::mergeLists(ToDoList &merger)
{

    linkedList *temp = head;
    linkedList *mergerTemp = merger.head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    if (head->item.getPriority() == 0)
    {
        head->item = merger.head->item;
    }
    else
    {
        while (mergerTemp->next != nullptr)
        {
            temp->next = new linkedList();
            temp->next->next = nullptr;
            temp->next->item = mergerTemp->item;
            mergerTemp = mergerTemp->next;
        }
    }
}

std::string ToDoList::printObject(Todo todoObject)
{
    std::string priority = std::to_string(todoObject.getPriority());
    std::string title = todoObject.getTitle();
    std::string description = todoObject.getDescription();
    std::string type = todoObject.getType();
    std::string status = todoObject.getStatus();
    std::string dateCreated = todoObject.getCreateDate();
    std::string dueDate = todoObject.getDueDate();
    std::string lastMod = todoObject.getLastModified();
    char comma = ',';
    std::string newline = "\n";

    std::string objectLine = priority + comma + title + comma + description + comma + type + comma + status + comma + dateCreated + comma + dueDate + comma + lastMod + newline;
    return objectLine;
}
