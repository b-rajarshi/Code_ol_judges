// Basic link list operations

#include <iostream>
using namespace std;
 

typedef struct node {
	int data;
	struct node *next;
} node;

/*
 * head - the root node;
 * d	- data to append.
*/
void appendEnd (node *head, int d) {
	while (head->next != NULL) {
		head = head->next;
	}

	node *temp = new node;
	head->next = temp;
	temp->data = d;
	temp->next = NULL;
}

void printList (node *head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	cout << "\n";
}

int main () {
	node *head = new node;
	head->data = 1;
	head->next = NULL;
	appendEnd(head, 1);
	appendEnd(head, 2);
	appendEnd(head, 3);
	printList(head);

	return 0;
}
