
#include "$kk$k$vv$vhashtable.h"

void print$Kk$K$Vv$VEntry($Kk$K$Vv$VEntry *data) {
    printf("%s -> %d\n",(char*)data->key,*data->value);
}

void free$Kk$K$Vv$VEntry($Kk$K$Vv$VEntry *data) {
    free$Kk$(data->key);
    free$Vv$(data->value);
    free(data);
}

$Kk$K$Vv$VHashTable *new$Kk$K$Vv$VHashTable(int min_capacity) {
    int i;
    for (i = 1; min_capacity / i > 0; i <<= 1);
    int table_size = i;

    $Kk$K$Vv$VHashTable *newtable = ($Kk$K$Vv$VHashTable*)malloc(sizeof($Kk$K$Vv$VHashTable));

    newtable->table_size = table_size;
    newtable->num_elements = 0;
    newtable->table = ($Kk$K$Vv$VEntryList**)malloc(sizeof($Kk$K$Vv$VEntryList*)*table_size);

    for (i = 0; i < table_size; i++) newtable->table[i] = NULL;

    return newtable;
}

void free$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table) {
    if (table->table != NULL) {
        $Kk$K$Vv$VEntryList *listptr;
        int i;
        for (i = 0; i < table->table_size; i++) {
            listptr = table->table[i];
            if (listptr != NULL) free$Kk$K$Vv$VEntryList(listptr);
        }
        free(table->table);
    }
    free(table);
}

int shouldExpandTable($Kk$K$Vv$VHashTable *table) {
    float loadfactor = ((float)table->num_elements) / ((float)table->table_size);
    if (loadfactor > MAX_LOAD_FACTOR) return 1;
    else return 0;
}

void expandTable($Kk$K$Vv$VHashTable *table) {
    int newtablesize = table->table_size << 1;
    int i;
    $Kk$K$Vv$VEntryList *bucket,*temp;
    $Kk$K$Vv$VEntryNode *entry;
    // Create a whole new table object that holds the larger table to make it easy to rehash all the current values
    $Kk$K$Vv$VHashTable *newtable = new$Kk$K$Vv$VHashTable(newtablesize - 1); // subtract 1 to get that exact power of two
    // Use the new table to rehash all the entries in the old table into the new one
    for (i = 0; i < table->table_size; i++) {
        bucket = table->table[i];
        if (bucket != NULL) {
            for (entry = bucket->head->next; entry != NULL; entry = entry->next) {
                putEntry$Kk$K$Vv$VHashTable(newtable,entry->data);
            }
        }
    }

    // go through the old table and free each bucket that's not null with the free-list-only function, as opposed to freeing the list and its data elements.
    for (i = 0; i < table->table_size; i++) {
        temp = table->table[i];
        if (temp != NULL) free$Kk$K$Vv$VEntryListOnly(temp);
    }
    // finally, free the old table
    free(table->table);
    // swap the tables and copy the attributes between the objects 
    table->table = newtable->table;
    table->table_size = newtable->table_size;
    table->num_elements = newtable->num_elements;
    // set the placeholder's table to null so we don't get memory errors
    newtable->table = NULL;
    // free the placeholder object
    free$Kk$K$Vv$VHashTable(newtable);



}

void putEntry$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table,$Kk$K$Vv$VEntry *entry) {
    unsigned int hashvalue = hash$Kk$(entry->key);
    hashvalue = hashvalue%table->table_size;
    $Kk$K$Vv$VEntryList *list = table->table[hashvalue];
    if (list == NULL) {
        list = new$Kk$K$Vv$VEntryList();
        table->table[hashvalue] = list;
    }

    append$Kk$K$Vv$VEntry(list,entry);
    table->num_elements++;
    if (shouldExpandTable(table)) expandTable(table);
}

$Kk$K$Vv$VEntry *new$Kk$K$Vv$VEntry($Kk$ *key,$Vv$ *value) {
    $Kk$K$Vv$VEntry *entry = ($Kk$K$Vv$VEntry*)malloc(sizeof($Kk$K$Vv$VEntry));
    entry->key = key;
    entry->value = value;
    return entry;
}

void put$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table,$Kk$ *key,$Vv$ *value) {
    $Kk$K$Vv$VEntry *entry = new$Kk$K$Vv$VEntry(key,value);
    putEntry$Kk$K$Vv$VHashTable(table,entry);
}

$Vv$ *getValue$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table,$Kk$ *key) {
    unsigned int hashvalue = hash$Kk$(key);
    hashvalue = hashvalue%table->table_size;
    $Kk$K$Vv$VEntryList *bucket = table->table[hashvalue];
    if (bucket != NULL) {
        $Kk$K$Vv$VEntryNode *node;
        for (node = bucket->head->next; node != NULL; node = node->next) {
            if (compare$Kk$(key,node->data->key) == 0) {
                return node->data->value;
            }
        }
        return NULL;
    } else return NULL;
}



