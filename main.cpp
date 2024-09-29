/// @file main.cpp
/// @author Adam T Koehler, PhD
/// @date October 2, 2023
/// @brief main to test out program execution outside of framework testing
///		Initial file authored by:
///     Adam T Koehler, PhD - University of Illinois Chicago


/*
 * Instructions for Using the Priority Queue Program
 *
 * This program implements a priority queue allowing users to manage elements with associated priorities.
 * The following commands can be entered to interact with the priority queue:
 *
 * 1. **enqueue <value>**: Add an element to the queue with a specified priority.
 *    - After entering the value, you will be prompted to enter the priority.
 * 2. **dequeue**: Remove the highest priority element from the queue.
 * 3. **peek**: Display the highest priority element without removing it from the queue.
 * 4. **clear**: Clear all elements from the queue.
 * 5. **copy**: Create a copy of the current queue and display its contents.
 * 6. **begin**: Prepare the queue for traversal.
 * 7. **next**: Retrieve the next element in the queue during traversal.
 * 8. **equal**: Compare the current queue with a predefined queue to check for equality.
 * 9. **break**: Exit the program.
 *
 * When prompted to enter a value or priority, simply type the desired input and press Enter.
 *
 * This interactive command-line interface allows you to test and visualize the priority queue's functionality.
 *
 * Note: Ensure that the program is compiled and run properly to avoid any runtime errors.
 */


#include <iostream>
#include "prqueue.h"
using namespace std;



int main()
{
    
    prqueue<string> myQueue;
    int level=0;
    string result="";
    string v="";
    int p=0;
	while (true){
        string val;
        cout<<"enter val: "<<endl;
        cin>>val;
        if (val=="clear"){
            myQueue.clear();
            cout<<"size is "<<myQueue.size();
            continue;
        }
        if (val=="copy"){
            prqueue<string> newQueue;
            newQueue=myQueue;
        cout<<endl<<endl;
        cout<<newQueue.toString();
        break;
        }
        if (val=="begin"){
            myQueue.begin();
            continue;
        }
        if (val=="next"){
            myQueue.next(v,p);
            continue;
        }
        if (val=="dequeue"){
            myQueue.dequeue();
            cout<<"tree is now"<<endl;
            cout<<endl<<endl;
            cout<<myQueue.toString();
            continue;
        }
        if (val=="peek"){
            myQueue.peek();
            continue;
        }
        if (val=="equal"){
            prqueue<string> newQueue;
            newQueue.enqueue("22",22);
            newQueue.enqueue("11",11);
            newQueue.enqueue("3",3);
            newQueue.enqueue("19",19);
            newQueue.enqueue("49",49);
            newQueue.enqueue("35",35);
            newQueue.enqueue("61",61);
            newQueue.enqueue("30",30);
            newQueue.enqueue("41",41);
            bool E=newQueue==myQueue;
            cout<<E;
            continue;
        }
        if (val=="break"){break;}
        int priority;
        cout<<"enter priority: "<<endl;
        cin>>priority;
        myQueue.enqueue(val,priority);
        cout<<"tree is now"<<endl;
        cout<<endl<<endl;
        cout<<myQueue.toString();
        
    }

	return 0;
}
