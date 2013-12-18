
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
$$List* append$$($$List *list,$$ *data);
$$List* append$$WoP($$List *list,$$ data);
$$List* append$$Node($$List *list,$$Node *node);
void print$$List($$List *list);
void free$$List($$List *list);
void free$$ListOnly($$List *list);
void free$$Node($$Node *node);
void free$$NodeOnly($$Node *node);
$$List* insert$$NodeBefore($$List *list,$$Node *cur,$$Node *node);
$$Node* removeIndex$$($$List* list,int index);
void remove$$Node($$List *list,$$Node *node);
$$* remove$$($$List *list,$$ *data);
$$Node* new$$Node();
$$List* dup$$List($$List *list);
$$List* dup$$ListShallow($$List *list);
int compare$$List($$List *a_list,$$List *b_list);
$$List* makeSE$$List($$ *data);
$$List* makeSE$$ListWoP($$ data);
$$List *append$$ListToList($$List *list,$$List *second_list);
$$List *append$$ListToListShallow($$List *list,$$List *second_list);
$$List* prepend$$($$List *list,$$ *data);
$$List* prepend$$WoP($$List *list,$$ data);

#endif

