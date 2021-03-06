#include "Pointer_Based_Linear_List.h"

static PllNode* Search(const Ptr_LinearList &list, Data x) {
	PllNode* ptr = list.head;
	while (ptr != NULL) {
		if (ptr->data == x) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

static void InsertFront(Ptr_LinearList* list, Data x) {
	PllNode* newNode = AllocPllNode();
	SetPllNode(newNode, x, list->head);
	list->head = newNode;
	list->size++;
}

static void InsertRear(Ptr_LinearList* list, Data x) {
	if (list->head == NULL) {
		InsertFront(list, x);
	} else {
		PllNode* ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = AllocPllNode();
		SetPllNode(ptr->next, x, NULL);
		list->size++;
	}
}

static void RemoveFront(Ptr_LinearList* list) {
	if (list->head != NULL) {
		PllNode* ptr = list->head;
		list->head = list->head->next;
		free(ptr);
		list->size--;
	}
}

static void RemoveRear(Ptr_LinearList* list) {
	if (list->head != NULL) {
		if (list->head->next == NULL) {
			RemoveFront(list);
		} else {
			PllNode* ptr = list->head;
			while (ptr->next->next != NULL) ptr = ptr->next;
			PllNode* del = ptr->next;
			ptr->next = NULL;
			free(del);
			list->size--;
		}
	} 
}

static void RemoveCursor(Ptr_LinearList* list) {
	if (list->cur == NULL)
		return;
	else if (list->head == list->cur) {
		RemoveFront(list);
		list->cur = NULL;
	} else {
		PllNode* ptr = list->head;
		while (ptr->next != list->cur)
			ptr = ptr->next;
		ptr->next = list->cur->next;
		free(list->cur);
		list->cur = NULL;
		list->size--;
	}
}

static int Length(Ptr_LinearList* list) {
	return list->size;
}

static void Clear(Ptr_LinearList* list) {
	while (list->head != NULL) {
		RemoveFront(list);
	}
	list->cur = NULL;
	list->size = 0;
}

static PllNode* MoveCur(Ptr_LinearList* list, Data x) {
	return list->cur = Search(*list, x);
}

static void PrintCur(const Ptr_LinearList& list) {
	if (list.cur != NULL)
		printf("%d", list.cur->data);
	else
		printf("NULL");
}

static void PrintAll(const Ptr_LinearList& list) {
	for(PllNode* ptr = list.head; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
}

static void Terminate(Ptr_LinearList* list) {
	Clear(list);
}

static Ptr_LinearList MakePtrLinearList() {
	Ptr_LinearList list;
	list.cur = list.head = NULL;
	list.size = 0;
	return list;
}


void Pointer_Based_Linear_List_Main() {

	Ptr_LinearList list = MakePtrLinearList();
	printf("List created.\n");
	int input;
	while (1) {
		system(CLEAR);
		printf("list : "); PrintAll(list); printf("\n");
		printf("cursor is on "); PrintCur(list); printf("\n");
		printf("\n");
		printf("Menu\n");
		printf("1. Insert on front\n");
		printf("2. Insert on rear\n");
		printf("3. Remove on front\n");
		printf("4. Remove on rear\n");
		printf("5. Remove on cursor\n");
		printf("6. Clear\n");
		printf("7. Move Cursor\n");
		printf("0. End\n");
		printf(">> "); scanf("%d", &input); putchar('\n');

		switch (input) {
		case 1:
			printf("Enter the value that you want to insert into list\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			InsertFront(&list, input);
			break;
		case 2:
			printf("Enter the value that you want to insert into list\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			InsertRear(&list, input);
			break;
		case 3:
			RemoveFront(&list);
			break;
		case 4:
			RemoveRear(&list);
			break;
		case 5:
			RemoveCursor(&list);
			break;
		case 6:
			Clear(&list);
			break;
		case 7:
			printf("Enter the value that you want to search\n");
			printf(">> "); scanf("%d", &input); printf("\n");
			MoveCur(&list, input);
			break;
		case 0:
			Terminate(&list);
			goto ENDLOOP;
			break;
		default:
			break;
		}
	} ENDLOOP: ;
}	

Ptr_LinearList MakePtrLinearList_p() {
	return MakePtrLinearList();
}

void InsertRear_p(Ptr_LinearList* list, Data x) {
	InsertRear(list, x);
}

void RemoveCursor_p(Ptr_LinearList* list) {
	RemoveCursor(list);
}

PllNode* MoveCur_p(Ptr_LinearList* list, Data x) {
	return MoveCur(list, x);
}

int Length_p(Ptr_LinearList* list) {
	return Length(list);
}

void PrintAll_p(const Ptr_LinearList& list) {
	for (PllNode* ptr = list.head; ptr != NULL; ptr = ptr->next)
		printf("%c ", 'A' + ptr->data);
}

void Terminate_p(Ptr_LinearList* list) {
	Terminate(list);
}