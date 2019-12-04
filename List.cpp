// Ethan Massey
// ejm4aa
// 1/31/19
// List.cpp

#include <iostream>
#include "List.h"
using namespace std;

// Default constructor
List::List(){
	head = new ListNode;
    tail = new ListNode;
    head->next = tail;
    tail->previous = head;
    count=0;
}

// Copy Constructor
List::List(const List& source) {      
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    // deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Destructor
List::~List(){
    makeEmpty();
    delete head;
    delete tail;
}

// Equals operator
List& List::operator=(const List& source) { 
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// Returns true if list contains no nodes (other than head and tail)
bool List::isEmpty() const{
    if(count == 0){
        return true;
    }else{
        return false;
    }
}

// Deletes all nodes between head and tail, reclaiming memory
void List::makeEmpty(){
    ListItr dummy = first();

    while(! dummy.isPastEnd()){
        dummy.moveForward();
        int value = dummy.current->previous->value;
        remove(value);
    }

    // re-point pointers
    head->next = tail;
    tail->previous = head;
    count = 0;
}

// Returns ListItr at position of first real node in list
ListItr List::first(){
    ListItr itr = ListItr();
    itr.current = head->next;
    return itr;
}

// Returns ListItr at position of last real node in list
ListItr List::last(){
    ListItr itr = ListItr();
    itr.current = tail->previous;
    return itr;
}

// Inserts x after the current iterator positon position
void List::insertAfter(int x, ListItr position){
    ListNode *n = new ListNode();
    n->value = x;

    n->previous = position.current;
    n->next = position.current->next;

    n->next->previous = n;
    n->previous->next = n;

    count++;
}

// Inserts x before the current iterator position position
void List::insertBefore(int x, ListItr position){

    ListNode *n = new ListNode();
    n->value = x;

    n->next = position.current;
    n->previous = position.current->previous;

    n->next->previous = n;
    n->previous->next = n;

    count++;
}

// Inserts x at tail of list
void List::insertAtTail(int x){

    ListNode *n = new ListNode();
    ListItr iter = last();

    tail->previous->next = n;
    tail->previous = n;

    n->previous = iter.current;
    n->next = tail;

    n->value = x;
    
    count++;

}

// Removes first node with value x, reclaiming memory
void List::remove(int x){
    ListItr position = find(x);

    position.current->previous->next = position.current->next;
    position.current->next->previous = position.current->previous;

    delete position.current;

    count--;
}

// Returns an iterator that points to first occurrence of x
ListItr List::find(int x){
    ListItr iter = first();
    while(iter.current != NULL){
        if(iter.current->value == x){
            return iter;
        }else{
            iter.current = iter.current->next;
        }
    }
    // Value not found, returns ListItr with current = NULL
    cout << "Value not found in list" << endl;
    ListItr notFound = ListItr();
    return notFound;
}

// Returns number of elements in list
int List::size() const{
    return count;
}

// Prints visual representation of list
// Format: element -> element -> element, etc.
void printList(List& source, bool direction){

    ListItr iter;
    // forward
    if(direction){
        iter = source.first();
        while(! iter.isPastEnd()){
            cout << iter.retrieve();
            iter.moveForward();
            if(! iter.isPastEnd()){
                cout << " -> ";
            }
        }
        cout << endl;
    // backward    
    }else{
        iter = source.last();
        while(! iter.isPastBeginning()){
            cout << iter.retrieve();
            iter.moveBackward();
            if(! iter.isPastBeginning()){
                cout << " -> ";
            }
        } 
        cout << endl;
    }
}
