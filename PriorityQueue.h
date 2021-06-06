// Header file for priority queue ADT.
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class FullQueue
{};
class EmptyQueue
{};

template <class ItemType>
struct QNode {
    ItemType info;
    int priority;
    QNode<ItemType>* next;
};

class QueueOverflow {
};

class QueueUnderflow {
};

template <class ItemType>
class PriorityQueue {
public:
    PriorityQueue();
    // Class constructor.
    ~PriorityQueue();
    // Class destructor.
    void makeEmpty();
    // Removes all items from the queue.
    bool isEmpty() const;
    // Returns true if the queue has no items.
    bool isFull() const;
    // Returns true if the queue is full.
    int getLength() const;
    // Returns length of queque.
    void enqueue(ItemType newItem, int priority);
    // Adds newItem after any items of higher or equal priority,
    // but before any items of lower priority.
    ItemType dequeue();
    // Removes and returns the item at the front of the queue.
    ItemType peek() const;
    // Returns the item at the front of the queue.
    int peekPriority() const;
    // Returns the priority of the item at the front of the queue.
    void printQueue(ofstream&) const;
    // Prints the items in the queue from front to rear.
private:
    QNode<ItemType>* front;
    QNode<ItemType>* rear;
    int length;
};
