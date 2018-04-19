/*
 * @brief It defines an object and gives the functions necessary to handle it
 *
 * @file object.h
 * @author Frederik Mayer
 * @version 1.0
 * @date 10-02-2018
 * @copyright GNU Public License
 *
 */

#include "../include/object.h"

/** ADT representing objects on the game board*/
struct _Object {
  Id id;
  char name[WORD_SIZE + 1];
  Id space_id;
  char description[WORD_SIZE + 1];
  BOOL movable;
  BOOL moved;
  BOOL hidden;
  Id open;
};

/****************************/
/* Functions implementation */
/****************************/

Object* object_create(Id id){
  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }

  newObject->id = id;
  newObject->movable = FALSE;
  newObject->moved = FALSE;
  newObject->hidden = FALSE;
  newObject->open = NO_ID;

  return newObject;
}

STATUS object_destroy(Object* object){
	if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

Id object_get_id(Object* object){
	if (!object) {
    return NO_ID;
  }
  return object->id;
}

STATUS object_set_name(Object* object, char* name){
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS object_set_space_id(Object* object, Id space_id){
  if (!object) {
    return ERROR;
  }

  object->space_id = space_id;
  return OK;
}

STATUS object_set_description(Object* object, char* des){
  if (!object || !des) {
    return ERROR;
  }

  if (!strcpy(object->description, des)) {
    return ERROR;
  }

  return OK;
}

STATUS object_set_movable(Object* object, BOOL movable){
  if (!object || !movable) {
    return ERROR;
  }
  
  object->movable = movable;
  return OK;
}

STATUS object_set_moved(Object* object, BOOL moved){
  if (!object || !moved) {
    return ERROR;
  }
  
  object->moved = moved;
  return OK;
}
STATUS object_set_hidden(Object* object, BOOL hidden){
  if (!object || !hidden) {
    return ERROR;
  }
  
  object->hidden = hidden;
  return OK;
}
STATUS object_set_open(Object* object, Id open){
  if (!object || open == NO_ID) {
    return ERROR;
  }
  
  object->open = open;
  return OK;
}

const char* object_get_name(Object* object){
  if (!object){
    return NULL;
  }
  return object->name;
}

Id object_get_space_id(Object *object) {
  if (!object) {
    return NO_ID;
  }
  return object->space_id;
}

const char* object_get_description(Object* object){
  if (!object){
    return NULL;
  }
  return object->description;
}

BOOL object_set_movable(Object* object){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->movable;
}

BOOL object_set_moved(Object* object){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->moved;
}

BOOL object_set_hidden(Object* object, BOOL hidden){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->hidden;
}

Id object_set_open(Object* object){
  if (!object) {
    return NO_ID;
  }
  
  return object->open;
}

STATUS object_print(Object* object){
  if (!object) {
    return ERROR;
  }
  
  if (object->movable == FALSE){
    if (object->hidden == FALSE){
      fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Not movable; Not hidden; Open: %ld)\n", object->id, object->name, object->space_id, object->open);
    }
    else {
      fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Not movable; Hidden; Open: %ld)\n", object->id, object->name, object->space_id, object->open);
    }
  }
  else {
    if (object->moved == FALSE){
      if (object->hidden == FALSE){
        fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Movable; Not moved; Not hidden; Open: %ld)\n", object->id, object->name, object->space_id, object->open);
      }
      else {
        fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Movable; Not moved; Hidden; Open: %ld)\n", object->id, object->name, object->space_id, object->open);
      }
    }
    else {
      if (object->hidden == FALSE){
        fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Movable; Moved; Not hidden; Open: %ld)\n", object->id, object->name, object->space_id, object->open);
      }
      else {
        fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Movable; Moved; Hidden; Open: %ld)\n", object->id, object->name, object->space_id, object->open);
      }
    }
  }
    

	return OK;
}
