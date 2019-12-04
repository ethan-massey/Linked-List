// Ethan Massey
// 1/31/19
// List.h

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

class ListItr;

class List {
public:
    List();				//Constructor
    List(const List& source);	//Copy Constructor
    ~List();			//Destructor
    List& operator=(const List& source);	//Equals Operator
    bool isEmpty() const;		//Returns true if empty; else false
    void makeEmpty();	//Removes all items except blank head and tail
    ListItr first(); 		//Returns an iterator that points to
    //the ListNode in the first position
    ListItr last();			//Returns an iterator that points to
    //the ListNode in the last position
    void insertAfter(int x, ListItr position);
    //Inserts x after current iterator position p
    void insertBefore(int x, ListItr position);
    //Inserts x before current iterator position p
    void insertAtTail(int x);	//Insert x at tail of list
    void remove(int x);		//Removes the first occurrence of x
    ListItr find(int x);		//Returns an iterator that points to
    // the first occurrence of x, else return a iterator to the dummy tail node

    int size() const; //Returns the number of elements in the list



private:
    ListNode *head, *tail;	//indicates beginning and end of the list
    int count;			//#of elements in list
    friend class ListItr;
};

// printList: non-member function prototype
void printList(List& source, bool direction);
//prints list forwards when direction is true
//or backwards when direction is false
#endif
/* end of List.h */
