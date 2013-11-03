
#ifndef $KK$K$VV$VHASHTABLE
#define $KK$K$VV$VHASHTABLE




#define MAX_LOAD_FACTOR 0.75F

#include "$kk$k$vv$vhashtable_imp.h"

#include "$kk$k$vv$vhashtabletypes.h"

#include "$kk$k$vv$ventrylist_imp.h"
#include "$kk$k$vv$ventrylist.h"

typedef struct $kk$_k_$vv$_v_hash_table {
    $Kk$K$Vv$VEntryList **table;
    int table_size;
    int num_elements;
} $Kk$K$Vv$VHashTable;





$Kk$K$Vv$VHashTable *new$Kk$K$Vv$VHashTable(int min_capacity);
void free$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table);
void put$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table,$Kk$ *key,$Vv$ *value);
void putEntry$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table,$Kk$K$Vv$VEntry *entry);
$Vv$ *getValue$Kk$K$Vv$VHashTable($Kk$K$Vv$VHashTable *table,$Kk$ *key);

#endif



