/*
 * @brief Allows the player to carry and manage several objects in his backpack.
 *
 * @file inventory.h
 * @author Oriana Pastor
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */

#include "../include/inventory.h"

/**lets the player carry and handle more than one object*/
struct _Inventory{
  Set *objects;
  int nmax;
};

Inventory* inventory_create() {
  Inventory* new_inventory = NULL;

  new_inventory = (Inventory*) malloc(sizeof(Inventory));

  if (new_inventory == NULL) {
    return NULL;
  }

  new_inventory->objects = set_create();
  new_inventory->nmax = DIM;
  return new_inventory;
}

STATUS inventory_destroy(Inventory* inventory) {
  if (!inventory) {
    return ERROR;
  }
  set_destroy(inventory->objects);
  free(inventory);
  inventory = NULL;

  return OK;
}

STATUS inventory_add_object(Inventory* inventory, Id id) {
  if (!inventory || id == NO_ID) {
    return ERROR;
  }
  return set_add_element(inventory_get_object_set(inventory), id);
}

STATUS inventory_set_nmax(Inventory* inventory, int n) {
  if (!inventory || n <= 0) {
    return ERROR;
  }
  inventory->nmax = n;
  return OK;
}

Set* inventory_get_object_set(Inventory* inventory) {
  if (!inventory) {
    return NULL;
  }
  return inventory->objects;
}

int inventory_get_nmax(Inventory* inventory){
  if (!inventory) {
    return -1;
  }
  return inventory->nmax;
}

BOOL inventory_is_full(Inventory* inventory) {
  if (!inventory) {
    return TRUE;
  }
  if(inventory_get_nmax(inventory) == set_get_size(inventory->objects)){
    return TRUE;
  }
  return FALSE;
}

STATUS inventory_print(FILE* output, Inventory* inventory) {
  if (!inventory || !output) {
    return ERROR;
  }

  fprintf(output, "--> Inventory (MaxObjects: %d)\n", inventory->nmax);
  fprintf(output, "---> Objects located in the Inventory:\n");
  if(set_print(inventory_get_object_set(inventory)) == -1){
    return ERROR;
  }

  return OK;
}
