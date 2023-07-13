
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* Singly linked list implementation in C */
/*
SinlyLinkedList Implementation in C
File: Main.c
Author: Malkoot Khan
Date: 13/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Node {
	int item;
	struct Node* next;
};
void showNullMSG() {
	printf("The list is empty!\n");
}
struct Node* createNode(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->item = data;
	temp->next = NULL;
	return temp;
}
void insertAtStart(struct Node** start, int data) {
	struct Node* temp = createNode(data);
	struct Node* s = *start;
	if (s == NULL) {
		*start = temp;
		return;
	}
	temp->next = *start;
	*start = temp;
}
void insertAtEnd(struct Node** start, int data) {
	struct Node* newNode = createNode(data);
	struct Node* s = *start;
	if (s == NULL) {
		*start = newNode;
		return;
	}
	while (s->next != NULL)
		s = s->next;
	s->next = newNode;
}inline bool isValid(int n) {
	if (n >= 0)
		return true;
	return false;
}
void insertAtPos(struct Node** start, int data, int pos) {
	struct Node* newNode = createNode(data);
	struct Node* s = *start;
	if (isValid(pos)) {
		if (pos == 0) {
			newNode->next = *start;
			*start = newNode;
			return;
		}
		int count = 1;
		while (s != NULL) {
			if (pos == count) {
				struct Node* t = s->next;
				s->next = newNode;
				newNode->next = t;
				return;
			}
			s = s->next;
			count++;
		}
		printf("position not found!\n");
		return;
	}
	printf("Invalid Position!\n");
}
void deleteFirst(struct Node** start) {
	struct Node* s = *start;
	if (s == NULL) {
		showNullMSG();
		return;
	}
	*start = (*start)->next;
	free(s);
}
void deleteLast(struct Node** start) {
	struct Node* s = *start;
	if (s == NULL) {
		showNullMSG();
		return;
	}
	while (s->next->next != NULL) 
		s = s->next;
	free(s->next);
	s->next = NULL;
}
void deleteAtPos(struct Node** start, int pos) {
	struct Node* s = *start;
	if (s == NULL) {
		showNullMSG();
		return;
	}
	if (pos == 0) {
		struct Node* t = s;
		*start = t->next;
		free(s);
		return;
	}
	int count = 1;
	while (s->next != NULL) {
		if (count == pos) {
			struct Node* t = s->next;
			s->next = t->next;
			free(t);
			return;
		}
		s = s->next;
		count++;
	}
	printf("The specific node not found!\n");
}
void display(struct Node* start) {
	struct Node* s = start;
	if (s == NULL) {
		showNullMSG();
		return;
	}
	while (s != NULL) {
		printf("%d ", s->item);
		s = s->next;
	}
	printf("\n");
}
void search(struct Node** start, int data) {
	struct Node* s = *start;
	if (s == NULL) {
		showNullMSG();
		return;
	}
	while (s != NULL) {
		if (s->item == data) {
			printf("Element found!\n");
			return;
		}
		s = s->next;
	}
	printf("Element not found!\n");
}

int main() {
	
	struct Node* head = NULL;
	insertAtStart(&head, 10);
	insertAtStart(&head, 20);
	insertAtStart(&head, 30);
	insertAtStart(&head, 1900);
	display(head);
	insertAtEnd(&head, 55);
	insertAtEnd(&head, 66);
	display(head);
	insertAtStart(&head, 88);
	insertAtStart(&head, 77);
	display(head);
	search(&head, 22);
	search(&head, 30);
	insertAtPos(&head, 100, 2);
	display(head);
	insertAtPos(&head, 123, 4);
	display(head);
	insertAtPos(&head, 321, 1);
	display(head);
	insertAtPos(&head, 111, 0);
	display(head);
	deleteFirst(&head);
	display(head);
	deleteFirst(&head);
	display(head);
	deleteLast(&head);
	display(head);
	deleteLast(&head);
	display(head);
	deleteAtPos(&head,2);
	display(head);
	deleteAtPos(&head, 6);
	display(head);
	deleteAtPos(&head, 1);
	display(head);
	deleteAtPos(&head, 0);
	deleteAtPos(&head, 0);
	deleteAtPos(&head, 0);
	display(head);
	return 0;
}

