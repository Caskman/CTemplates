
#ifndef $^^$LIST
#define $^^$LIST

#include <stdio.h>
#include <stdlib.h>
#include "$v$list_imp.h"

typedef struct $v$_node {
	struct $v$_node *next;
	struct $v$_node *prev;
	$$ *data;
} $$Node;

typedef struct $v$_list {
	$$Node *head;
	$$Node *tail;
	int size;
} $$List;

$$List* new$$List();
void append$$($$List *list,$$ *data);
void append$$Node($$List *list,$$Node *node);
void print$$List($$List *list);
void free$$List($$List *list);
void free$$Node($$Node *node);
void free$$NodeOnly($$Node *node);
void insert$$NodeBefore($$List *list,$$Node *cur,$$Node *node);
$$Node* removeIndex$$($$List* list,int index);
void remove$$($$List *list,$$Node *node);
$$Node* new$$Node();


#endif

