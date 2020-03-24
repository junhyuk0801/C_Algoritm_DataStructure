/*
	Deque and a series of associated functions.
*/

#ifndef DEQUE_H
#define DEQUE_H

#include "../../Base/Base.h"
#include "./DequeNode.h"

// Deque and a series of associated functions. Deque is able to add data in both of front and rear.
typedef struct {
	DequeNode* front;	// Pointer of the foremost node of deque.
	DequeNode* rear;	// Pointer of the rearest node of deque.
	int size;
} Deque;

// Add the value into front of deque.
static int AddFront(Deque* que, Data value);

// Add the value into rear of deque.
static int AddRear(Deque* que, Data value);

// Remove the value from front of queue.
static int RemoveFront(Deque* que);

// Remove the value from rear of queue.
static int RemoveRear(Deque* que);

// Clear the all value from deque.
static void Clear(Deque* que);

// See the current size of deque.
static int Size(const Deque* que);

// See if the deque is empty.
static int isEmpty(const Deque* que);

// Search the given value from deque. 
static int Search(const Deque* que, Data value);

// Print out all the value of deque.
static void Print(const Deque* que);

// Delete the deque and all of its contents.
static void Terminate(Deque* que);

// Make an initialized deque.
static Deque MakeDeque(int size);

#endif