// Test driver for the priority queue.

#include <iostream>
using namespace std;
#include <fstream>
#include <string>

#include "PriorityQueue.cpp"

void help()
{
	std::cout << "enqueue value: Enqueue a value at the end of the Queue\n" <<
        "dequeue: Remove the most urgent item \npeek: Peeks at the first item without " <<
        "removing it\npeekPriority: Peeks the priority of the first item without removing it" <<
        "\nclear: Clears the queue.\nisempty: Reports whether the queue is empty\n" <<
        "isfull: Reports whether the queue is full\nlist: Reports the items in the queue, " <<
        "in the order they will be processed\nhelp: Prints this message\n";
}
int main()
{

	ofstream outFile;
	ifstream inFile;
	string command;

	outFile.open("outFile.txt");
	inFile.open("inFile.txt");
	if(!outFile)
	{
		std::cout << "error openning output file" << endl;
		return 1;
	}
	string item;
	int priority;
	PriorityQueue<string> queue;
	int numCommands=0;

	help();
	while (true)
	{
		inFile >> command;
		try
		{
			if (command == "enqueue")
			{
				inFile >> item;
				inFile >> priority;
				queue.enqueue(item, priority);
				outFile << item << " " << priority << " is enqueued." << endl;
			}
			else if (command == "dequeue")
			{
				item = queue.dequeue();
				outFile << item << " is dequeued. " << endl;
			}
			else if (command == "isempty")
			{
				if (queue.isEmpty())
				outFile << "Queue is Empty\n";
			else
				outFile << "Queue is Not Empty\n";
			}
			else if (command == "isfull")
				if (queue.isFull())
					outFile << "Queue is full." << endl;
				else outFile << "Queue is not full." << endl;
			else if (command == "length")
				outFile << "Number of items in the Queue is: " << queue.getLength() << endl;
			else if (command == "clear")
				queue.makeEmpty();
			else if (command == "list")
                queue.printQueue(outFile);
			else if (command == "peek")
			{
                string x = queue.peek();
                outFile << "Item at the front of the queue is " << x << endl;
			}
			else if (command == "peekPriority")
			{
                int pri = queue.peekPriority();
                outFile << "Priority at the front of the queue is " << pri << endl;
			}
			else if (command == "help")
		     	help();
			else if (command == "quit")
				break;
			else
                outFile << " Invalid Command" << endl;
		}
		catch (QueueOverflow)
		{
			outFile << "Queue Overflow, exception thrown!" << endl;
		}

		catch (QueueUnderflow)
		{
            outFile << "Queue Underflow, exception thrown!" << endl;
		}

        numCommands++;
		cout <<  " Command number " << numCommands << " completed."
         << endl;
	}

	cout << "Testing completed."  << endl;
	outFile.close();
	return 0;
}
