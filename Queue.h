// File Name: Queue.h
//
// Auther Samuel Manzanares
// Date: 06/17/2021
// Assignment Number: 4
// CS 2308.501 Summer 2021
// Instructor: Dr. J. Marcos Palacios

// header file for queue class decleration and objects

//****************This is the line of 80 characters in length*******************

#ifndef QUEUE_H
#define QUEUE_H

using namespace std;
#include <string>

class Queue {
    // structure of the queue nodes
private:
    // structure of the queue nodes
    struct QueueNode {
        int value;          // value in a node; party size
        string name;        // party name 
        QueueNode *next;    // Pointer to the next node
    };

    QueueNode *front;       // front of the queue 
    QueueNode *rear;        // rear of the queue
    int numItems;           // number of parties in queue
public:
    // Constructor  
    Queue();
    // Deconstructor
    ~Queue();

    // Queue operations
    void enqueue(int, string);
    void dequeue(int &, string &);
    bool isEmpty() const;
    bool isFull() const;
    void clear();
    int getSizeAtFront();

};
#endif