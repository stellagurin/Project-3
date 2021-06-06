#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
// Constructor
{
    front = NULL;
    rear = NULL;
    length = 0;
}

template <class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
// Destructor
{
    makeEmpty();
}

template <class ItemType>
void PriorityQueue<ItemType>::makeEmpty()
// Removes all items from the queue
{
    QNode<ItemType>* temp = new QNode<ItemType>;
    front = temp;
    front->next = temp->next;
    length = 0;
}

template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
// Returns true if the queue is empty
{
    return (length == 0);
}

template <class ItemType>
bool PriorityQueue<ItemType>::isFull() const
// Returns true if the queue is full
{
    bool full = false;
    try {
        QNode<ItemType>* testPtr = new QNode<ItemType>;
        delete testPtr;
    } catch (bad_alloc&) {
        full = true;
    }
    return full;
}


template <class ItemType>
int PriorityQueue<ItemType>::getLength() const
// Returns length
{
    return length;
}

template <class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem, int priority)
// Adds newItem after any items of higher or equal priority,
// but before any items of lower priority.
{
    if (isFull()) {
        throw QueueOverflow();
    } else {
        QNode<ItemType>* newNode = new QNode<ItemType>;
        newNode->info = newItem;
        newNode->priority = priority;
        if (isEmpty()) {
            front = newNode;
        } else {
            QNode<ItemType>* pred = NULL;

            QNode<ItemType>* loc;
            QNode<ItemType>* prevLoc;
            bool moreToSearch;

            loc = front;
            prevLoc = NULL;

            moreToSearch = (loc != NULL);

            while (moreToSearch) {

                if(loc->priority < priority){
                    prevLoc = loc;
                    loc = loc->next;
                    moreToSearch = (loc != NULL);
                } //if

                else {
                    moreToSearch=false;
                }
            } //while

            if (prevLoc == NULL) {
                newNode->next = front;
                front = newNode;
            } //if

            else {
                newNode->next = loc;
                prevLoc->next = newNode;
            }
        }
        length++;
    }
}

template <class ItemType>
ItemType PriorityQueue<ItemType>::dequeue()
// Removes and returns the item at the front of the queue.
{
    if (isEmpty()) {
        throw QueueUnderflow();
    } else {
        QNode<ItemType>* tempPtr = front;
        ItemType dequeued = front->info;
        front = front->next;
        delete tempPtr;
        length--;
        return dequeued;
    }
}

template <class ItemType>
ItemType PriorityQueue<ItemType>::peek() const
// Returns the item at the front of the queue.
{
    if (isEmpty()) {
        throw QueueUnderflow();
    } else {
        return front->info;
    }
}

template <class ItemType>
int PriorityQueue<ItemType>::peekPriority() const
// Returns the priority of the item at the front of the queue.
{
    if (isEmpty()) {
        throw QueueUnderflow();
    } else {
        return front->priority;
    }
}

template <class ItemType>
void PriorityQueue<ItemType>::printQueue(ofstream& outFile) const
// Prints the items in the queue from front to rear.
{
    QNode<ItemType>* loc = front;
    for (int i = 0; i < length; i++) {
        outFile << loc->info << " " << loc->priority << " --> ";
        loc = loc->next;
    }
    outFile << "NULL";
    outFile << endl;
}
