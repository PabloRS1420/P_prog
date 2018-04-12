/*
 * @brief Allows to store and manage a set of Ids, referring to TADs of different types.
 *
 * @file set.h
 * @author Frederik Mayer
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */


#include "../include/set.h"

/**ADT that can store multiple ids of different types.*/
struct _Set{
  int size;
  Id ids[MAX_SET];
};

/*Private functions*/
Id set_get_id_at(Set* set, int i);
STATUS set_set_id_at(Set* set, Id elid, int i);
STATUS set_fill_gaps(Set* set);

Set* set_create(){
  Set *newSet = NULL;
  int i = 0;

  newSet = (Set *) malloc(sizeof (Set));

  if (newSet == NULL) {
    return NULL;
  }
  newSet->size = 0;
  for (i=0; i < MAX_SET; i++){
    newSet->ids[i] = NO_ID;
  }

  return newSet;
}

STATUS set_destroy(Set* set){
  if (!set) {
    return ERROR;
  }

  free(set);
  set = NULL;

  return OK;
}

int set_get_size(Set* set){
  if(!set) return -1;
  return set->size;
}

Id set_get_id_at(Set* set, int i){  /*private!*/
  if (!set || i >= MAX_SET){
    return NO_ID;
  }
  return set->ids[i];
}

STATUS set_set_id_at(Set* set, Id elid, int i){  /*private!*/
    if (!set || i >= MAX_SET){
      return ERROR;
    }
    set->ids[i] = elid;
    return OK;
}

STATUS set_fill_gaps(Set* set){
  Set* auxset = NULL;
  int i = 0;
  auxset=set_create();
  if (!auxset)  return ERROR;
  for (i=0; i<MAX_SET; i++){
    if (set_get_id_at(set, i) != NO_ID){
      if(set_add_element(auxset,set_get_id_at(set, i)) == ERROR) return ERROR;
      if(set_delete_element(set,set_get_id_at(set, i)) == ERROR) return ERROR;
    }
  }
  for (i=0; i < set_get_size(auxset); i++){
      if (set_add_element(set, set_get_id_at(auxset,i)) == ERROR) return ERROR;
  }
  if(set_destroy(auxset) == ERROR) return ERROR;
  return OK;
}


STATUS set_add_element(Set* set, Id elid){
  int i = 0;
  int insertat = -1;
  if (!set || set_get_size(set) == MAX_SET){
    return ERROR;
  }

  for (i=MAX_SET-1; i >= 0; i--){   /*finds the first empty space in ids*/
    if (set_get_id_at(set, i) == elid){ /*elid is already part of the set*/
      return OK;
    }
    if (set_get_id_at(set, i) == NO_ID){
      insertat = i;
    }
  }
  if (insertat == -1){
    return ERROR;
  }
  set->size++;
  return set_set_id_at(set, elid, insertat);
}

STATUS set_delete_element(Set* set, Id elid){
  int i = 0;
  if(!set || elid == NO_ID) return ERROR;
  for (i=0; i < MAX_SET; i++){
    if (set_get_id_at(set, i) == elid){
      set->size--;
      if(set_set_id_at(set, NO_ID, i) == ERROR) return ERROR;
      return set_fill_gaps(set);
    }
  }
  return ERROR;
}

Id* set_get_ids(Set* set){
  if(!set){
    return NULL;
  }
  return set->ids;
}

int set_print(Set* set){
  int cuenta = 0, i = 0, elnr = 0;
  if(!set) return -1;
  fprintf(stdout, "Printing set of size: %i\n", set_get_size(set));
  for (i=0; i < MAX_SET; i++){
    if (set_get_id_at(set, i) != NO_ID){
      cuenta = cuenta + fprintf(stdout, "%i. Id: %ld at place: %i\n",elnr+1, set_get_id_at(set,i), i);
      elnr++;
    }
  }
  return cuenta;
}
