/*
  * @brief It defines a player and gives the functions necessary to handle it
  *
  * @file player.h
  * @author Oriana Pastor
  * @version 1.0
  * @date 10-02-2018
  * @copyright GNU Public License
  *
  */

#include "../include/player.h"

/**ADT representing players in the game*/
struct _Player {
  Id id;
  char name[WORD_SIZE + 1];
  Id space_id;
  Inventory *objects;
};

/****************************/
/* Functions implementation */
/****************************/

Player* player_create(Id id){
  Player *newPlayer = NULL;

  if (id == NO_ID){
    return NULL;
  }
  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) {
    return NULL;
  }

  newPlayer->id = id;

  newPlayer->name[0]= '\0';
  newPlayer->space_id = NO_ID;
  newPlayer->objects = inventory_create();

	return newPlayer;
}

STATUS player_destroy(Player *player){
  if(!player){
    return ERROR;
  }
  inventory_destroy(player->objects);
  free(player);
  player = NULL;
  return OK;
}

STATUS player_set_name(Player *player, char *name){
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS player_set_space_id(Player* player, Id space_id){
  if (!player) {
    return ERROR;
  }

  player->space_id = space_id;
  return OK;
}

STATUS player_add_newobject(Player* player, Id object_id){
  if (!player) {
    return ERROR;
  }
  if(inventory_add_object(player->objects, object_id) == ERROR){
    return ERROR;
  }
  return OK;
}

Id player_get_id(Player *player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

const char* player_get_name(Player *player){
  if (!player){
    return NULL;
  }
  return player->name;
}

Id player_get_space_id(Player *player) {
  if (!player) {
    return NO_ID;
  }
  return player->space_id;
}

Id* player_get_objects_ids(Player *player) {
  if (!player) {
    return NULL;
  }
  return set_get_ids(inventory_get_object_set(player->objects));
}

Inventory* player_get_inventory(Player *player) {
  if (!player) {
    return NULL;
  }
  return player->objects;
}

BOOL player_is_carrying_object(Player *player, Id object_id) {
  Id *objects = NULL;
  int i, found = 0;

  if(!player){
    return FALSE;
  }

  objects = player_get_objects_ids(player);

  for(i=0; i < set_get_size(inventory_get_object_set(player->objects)) && !found ;i++){
    if(objects[i] == object_id){
      found = 1;
    }
  }
  if(found == 0) return FALSE;
  return TRUE;
}

STATUS player_print(Player *player) {
  if (!player) {
    return ERROR;
  }
  fprintf(stdout, "--> Player (Id: %ld; Name: %s; SpaceId: %ld)\n", player_get_id(player), player_get_name(player), player_get_space_id(player));
  inventory_print(stdout, player->objects);
  return OK;
}
