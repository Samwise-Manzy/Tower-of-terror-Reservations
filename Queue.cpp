// File Name: Queue.cpp
//
// Auther Samuel Manzanares
// Date: 06/17/2021
// Assignment Number: 4
// CS 2308.501 Summer 2021
// Instructor: Dr. J. Marcos Palacios

// class member functions 

//****************This is the line of 80 characters in length*******************

#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

//*******************************************
// constructor; creates empty queue
//*******************************************
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

//*******************************************
// destructor
//*******************************************
Queue::~Queue() {
    clear();
}

//*******************************************
// enqueue: inserts the value in num at the rear of the queue

// num: value to be inserted into queue
// party: name of party in queue node
// void return type  
//*******************************************
void Queue::enqueue(int num, string party) {
    QueueNode *newNode = nullptr;       // creates new queue node 

    newNode = new QueueNode;
    newNode->value = num;
    newNode->name = party;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    numItems++;
}

//*******************************************
// denqueue: inserts the value in num at the rear of the queue

// num: value to be released from queue
// party: name of party released from queue
// void return type  
//*******************************************
void Queue::dequeue(int &num, string &party) {
    QueueNode *temp = nullptr;      // creates temp node for deletion 

    if (isEmpty()) {
        cout << "The queue is empty.\n";
    } else {
        num = front->value;
        party = front->name;

        temp = front;
        front = front->next;
        delete temp;

        numItems--;
    }
}

//*******************************************
// isEmpty: determines if queue is empty

// bool return type if empty 
//*******************************************
bool Queue::isEmpty() const {
    bool status; // status of queue; empty or not

    if(numItems > 0) {
        status = false;
    } else {
        status = true;
    }

    return status;
}

//*******************************************
// clear: clears queue

// void return type  
//*******************************************
void Queue::clear() {
    int value;          // dummy variable for clear value 
    string name;        // dummy variables for clear name

    while(!isEmpty()) {
        dequeue(value, name);
    }
}

//*******************************************
// getSizeAtFront: gets size value of front of queue

// int return type of value in front of queue 
//*******************************************
int Queue::getSizeAtFront() {
    return front->value;
}






