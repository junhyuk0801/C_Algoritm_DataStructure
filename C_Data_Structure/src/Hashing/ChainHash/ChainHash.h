/*
	Chain Hashing. Store the data that has same hash value in linked list.
*/

#include "../../Base/Base.h"

#ifndef CHAIN_HASHING_H
#define CHAIN_HASHING_H

// Node that represents individual bukkit.
typedef struct __node {
	Data data;
	struct __node* next;
} ChainNode;

// Allocate new CHNode
static ChainNode* MakeCHNode();

// Set values of CHNode
static void SetCHNode(ChainNode* node, Data data, ChainNode* next);

// Hash Table implemented in Chain Hashing.
typedef struct {
	int size;
	ChainNode** Table;
} ChainHash;

// Hash function
static int Hash(Data data, int size);

// Search the value from hash table. If there is node that has same value with parameter, return the address of node. Otherwise return NULL.
static ChainNode* Search(const ChainHash* h, Data data);

// Add the new node that has same data with parameter. If there already is, do not execte it.
static int Add(ChainHash* h, Data data);

// Remove node that has same data with parameter. 
static int Remove(ChainHash* h, Data data);

// Print all contents of Hash Table.
static void Dump(const ChainHash* h);

// Clear all elements of Hash Table.
static void Clear(ChainHash* h);

// Make new Chain hash table and return it.
static ChainHash MakeChainHash(int size);

// Main function of Hashing implemented Chain Hashing.
void ChainHashMain();

#endif