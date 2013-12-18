

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

$$List* insert$$NodeBefore($$List *list,$$Node *cur,$$Node *node) {
	//set links for above
	node->prev = cur->prev;
	cur->prev->next = node;
	//set links for below
	node->next = cur;
	cur->prev = node;
	list->size++;
	return list;
}

$$List* append$$($$List *list,$$ *data) {
	return append$$Node(list,new$$Node(data));
}

$$List* append$$WoP($$List *list,$$ data) {
	$$* pdata = ($$*)malloc(sizeof($$));
	*pdata = data;
	return append$$(list,pdata);
}

$$List* append$$Node($$List* list,$$Node* node) {
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;
	list->size++;
	return list;
}

void print$$List($$List* list) {
	$$Node *temp;
	for (temp = list->head->next; temp != NULL; temp = temp->next) {
		print$$(temp->data);
		// printf("\n");
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
		if (node->data != NULL) free$$(node->data);
		free(node);
	}
}

void free$$List($$List *list) {
	if (list == NULL) return;
	free$$NodeRec(list->head);
	free(list);
}


void free$$ListOnly($$List *list) {
	if (list == NULL) return;
	free$$NodeOnlyRec(list->head);
	free(list);
}

$$Node* removeIndex$$($$List* list,int index) {
	$$Node *temp;
	int i;
	if (index >= list->size) return NULL;

	for (temp = list->head->next, i = 0; temp != NULL && i < index; temp = temp->next, i++);

	if (temp == NULL) return NULL;

	remove$$Node(list,temp);
	return temp;
}

void remove$$Node($$List *list,$$Node *node) {
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

$$List* dup$$List($$List *list) {
	if (list == NULL) return NULL;
	$$List *newlist = new$$List();
	$$Node *node;
	for (node = list->head->next; node != NULL; node = node->next) {
		append$$Node(newlist,new$$Node(dup$$(node->data)));
	}
	return newlist;
}

$$List* dup$$ListShallow($$List *list) {
	if (list == NULL) return NULL;
	$$List *newlist = new$$List();
	$$Node *node;
	for (node = list->head->next; node != NULL; node = node->next) {
		append$$Node(newlist,new$$Node(node->data));
	}
	return newlist;
}


$$List* makeSE$$List($$ *data) {
	$$List *list = new$$List();
	append$$(list,data);
	return list;
}

$$List* makeSE$$ListWoP($$ data) {
	$$* pdata = ($$*)malloc(sizeof($$));
	*pdata = data;
	return makeSE$$List(pdata);
}

$$* remove$$($$List *list,$$ *data) {
	$$Node *node;
	for (node = list->head->next; node != NULL; node = node->next) {
		if (compare$$(data,node->data) == 0) {
			remove$$Node(list,node);
			data = node->data;
			free$$NodeOnly(node);
			return data;
		}
	}
	return NULL;
}

int compare$$List($$List *a_list,$$List *b_list) {
	$$Node *a_node,*b_node;
	for (a_node = a_list->head->next,b_node = b_list->head->next; a_node != NULL && b_node != NULL; a_node = a_node->next, b_node = b_node->next) {
		int comparison = compare$$(a_node->data,b_node->data);
		if (comparison < 0) return -1;
		else if (comparison > 0) return 1;
	}
	if (a_node == b_node) return 0;
	else if (a_node == NULL) return -1;
	else return 1;
}

$$List *append$$ListToList($$List *list,$$List *second_list) {
	$$Node *node;
	for (node = second_list->head->next; node != NULL; node = node->next) {
		append$$(list,dup$$(node->data));
	}
	return list;
}

$$List *append$$ListToListShallow($$List *list,$$List *second_list) {
	$$Node *node;
	for (node = second_list->head->next; node != NULL; node = node->next) {
		append$$(list,node->data);
	}
	return list;
}

$$List* prepend$$Node($$List *list,$$Node *node) {
	if (list->size == 0) return append$$Node(list,node);
	else {
		$$Node *head = list->head;
		node->next = head->next;
		node->prev = head;
		head->next->prev = node;
		head->next = node;
		list->size++;
		return list;
	}
}

$$List* prepend$$($$List *list,$$ *data) {
	return prepend$$Node(list,new$$Node(data));
}

$$List* prepend$$WoP($$List *list,$$ data) {
	$$* pdata = ($$*)malloc(sizeof($$));
	*pdata = data;
	return prepend$$(list,pdata);
}


