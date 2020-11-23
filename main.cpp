#include <iostream>
#include <cstdlib>
#include "ToDoList.cpp"
#include <stdio.h>
#include <ctime>
using namespace std;
int main()
{
    int selection;
    ToDoList newList;
    int itemID;
    ToDoList listToMerge;

    do
    {
        cout << "Select an option: \n";
        cout << "1. Add an item \n";
        cout << "2. Edit an item \n";
        cout << "3. Delete an item \n";
        cout << "4. Delete items by type \n";
        cout << "5. Delete items by status \n";
        cout << "6. Read list from text file \n";
        cout << "Enter 0 to stop \n";
        cin >> selection;

        switch (selection)
        {
        case 1:
            newList.addItem();
            break;

        case 2:
            cout << "Enter the ID of the item you would like to edit: \n";
            cin >> itemID;
            newList.editItem(itemID);
            break;

        case 3:
            cout << "Enter the ID of the item you would like to delete: \n";
            cin >> itemID;
            newList.deleteItem(itemID);
            break;

        case 4:
            newList.deleteByType();
            break;

        case 5:
            newList.deleteByStatus();
            break;

        case 6:
            newList.readList();
            break;

        default:
            break;
        }

    } while (selection != 0);

    do
    {
        cout << "Select an option to sort: \n";
        cout << "1. Sort by priority \n";
        cout << "2. Sort by due date \n";
        cout << "3. Sort by date created \n";
        cout << "4. Print all items \n";
        cout << "5. Print items by type \n";
        cout << "6. Print items by priority \n";
        cout << "7. Print an item by ID \n";
        cout << "8. Write to do list to text file \n";
        cout << "9. Merge from read file \n";
        cout << "Enter 0 to stop \n";
        cin >> selection;

        switch (selection)
        {
        case 1:
            newList.sortByPriority();
            newList.printAllItems();
            break;

        case 2:
            newList.sortByDueDate();
            newList.printAllItems();
            break;

        case 3:
            newList.sortByCreateDate();
            newList.printAllItems();
            break;

        case 4:
            newList.printAllItems();
            break;

        case 5:
            newList.printByType();
            break;

        case 6:
            newList.printByPriority();

        case 7:
            newList.printByID();
            break;

        case 8:
            newList.writeList();
            break;

        case 9:
            listToMerge.readList();
            newList.mergeLists(listToMerge);
            newList.printAllItems();

        default:
            break;
        }
    } while (selection != 0);
}
