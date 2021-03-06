/*
	Linked list implementation based on pointer.
*/

#ifndef POINTER_BASED_LINEAR_LIST
#define POINTER_BASED_LINEAR_LIST

#include "../../Base/Base.h"
#include "PllNode.h"

// Linked linear list implemented by pointer
typedef struct {
	PllNode* head;	// First node of list.
	PllNode* cur;	// Cursor that can be used for an amounts of ways.
	int size;
} Ptr_LinearList;

// Search the value x with function compare
static PllNode* Search(const Ptr_LinearList &list, Data x);

// Insert x in the foremost point of list
static void InsertFront(Ptr_LinearList* list, Data x);

// Insert x in rearest point of list
static void InsertRear(Ptr_LinearList* list, Data x);

// Delete the node at foremost point of list
static void RemoveFront(Ptr_LinearList* list);

// Delete the node at rearest point of list
static void RemoveRear(Ptr_LinearList* list);

// Delete the node that pointed by cursor
static void RemoveCursor(Ptr_LinearList* list);

// Get the size of list
static int Length(Ptr_LinearList* list);

// Delete all nodes of list
static void Clear(Ptr_LinearList* list);

// Move Cursor of list
static PllNode* MoveCur(Ptr_LinearList* list, Data x);

// Print the value that pointed by cursor of list
static void PrintCur(const Ptr_LinearList &list);

// Print the all value of list
static void PrintAll(const Ptr_LinearList &list);

// Remove list
static void Terminate(Ptr_LinearList* list);

// Make an initialized linear list based on pointer
static Ptr_LinearList MakePtrLinearList(); 


// Main function of linear list implemented by pointer.
void Pointer_Based_Linear_List_Main();


Ptr_LinearList MakePtrLinearList_p();
void InsertRear_p(Ptr_LinearList* list, Data x);
void RemoveCursor_p(Ptr_LinearList* list);
PllNode* MoveCur_p(Ptr_LinearList* list, Data x);
int Length_p(Ptr_LinearList* list);
void PrintAll_p(const Ptr_LinearList &list);
void Terminate_p(Ptr_LinearList* list);

#endif