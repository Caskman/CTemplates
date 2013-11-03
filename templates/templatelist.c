

#include "$v$list.h"


$$List* new$$List() {
	$$List *newlist = ($$List*)malloc(sizeof($$List));
	$$Node *dummy = new$$Node(NULL);
	newlist->head = dummy;
	newlist->tail = dummy;
	newlist->size = 0;
	return newlist;
}

$$Node* new$$Node($$* data) {
	$$Node* newnode = ($$Node*) malloc(sizeof($$Node));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void insert$$NodeBefore($$List *list,$$Node *cur,$$Node *node) {
	//set links for above
	node->prev = cur->prev;
	cur->prev->next = node;
	//set links for below
	node->next = cur;
	cur->prev = node;
	list->size++;
}

void append$$($$List *list,$$ *data) {
	append$$Node(list,new$$Node(data));
}

void append$$Node($$List* list,$$Node* node) {
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;
	list->size++;
}

void print$$List($$List* list) {
	$$Node *temp;
	for (temp = list->head->next; temp != NULL; temp = temp->next) {
		print$$(temp->data);
	}
}

void free$$NodeRec($$Node *node) {
	if (node != NULL) {
		free$$NodeRec(node->next);
		free$$Node(node);
	}
}

void free$$NodeOnlyRec($$Node *node) {
	if (node != NULL) {
		free$$NodeOnlyRec(node->next);
		free$$NodeOnly(node);
	}
}

void free$$NodeOnly($$Node *node) {
	if (node != NULL) free(node);
}

void free$$Node($$Node *node) {
	if (node != NULL) {
		free$$(node->data);
		free(node);
	}
}

void free$$List($$List *list) {
	free$$NodeRec(list->head);
	free(list);
}


void free$$ListOnly($$List *list) {
	free$$NodeOnlyRec(list->head);
	free(list);
}

$$Node* removeIndex$$($$List* list,int index) {
	$$Node *temp;
	int i;
	if (index >= list->size) return NULL;

	for (temp = list->head->next, i = 0; temp != NULL && i < index; temp = temp->next, i++);

	if (temp == NULL) return NULL;

	remove$$(list,temp);
	return temp;
}

void remove$$($$List *list,$$Node *node) {
	$$Node *before = node->prev;
	$$Node *after = node->next;
		
	// Common case
	before->next = after;

	node->next = NULL; // kill these references just in case
	node->prev = NULL;

	if (list->tail == node) // if node is the tail
		list->tail = before; 
	else
		after->prev = before; // if not the tail, must fix the previous of node's next
	list->size--;
}








