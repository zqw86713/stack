#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//	A structure to represent stack using linked list.
struct StackNode {
	int data;
	struct StackNode *next;
};

//	a method to create a new node.
struct StackNode *createNode(int data) {
	struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/*	the method to see if the stack is empty or not. 
	1 is empty; 0 is non-empty;
*/
int isEmpty(struct StackNode *root) {
	return !root;
}


/*	the method to push a new data to stack.
*/
void push(struct StackNode **root, int data) {
	struct StackNode *newStackNode = createNode(data);
	newStackNode->next = *root;
	*root = newStackNode;
	printf("%d push to stack \n", data);
}

/*	the method to pop a top node.	
*/
int pop(struct StackNode **root) {
	if (isEmpty(*root)) {
		return INT_MIN;
	}
	struct StackNode *temp = *root;
	*root = (*root)->next;
	int data = temp->data;
	free(temp);

	return data;
}

/*	the method to peek.	*/
int peek(struct StackNode *root){
	if (isEmpty(root)) {
		return INT_MIN;
	}
	return root->data;
}

int main() {

	struct StackNode *root = NULL;
	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	printf("%d popped from stack \n", pop(&root));
	printf("The TOP element is %d\n", peek(root));

	return 0;
}