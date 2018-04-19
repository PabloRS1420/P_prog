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
  char description2[WORD_SIZE + 1];
  BOOL movable;
  BOOL moved;
  BOOL hidden;
  Id open;
  BOOL illuminate;
  BOOL switchedOn;
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
  newObject->illuminate = FALSE;
  newObject->switchedOn = FALSE;

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

STATUS object_set_description2(Object* object, char* des){
  if (!object || !des) {
    return ERROR;
  }

  if (!strcpy(object->description2, des)) {
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

STATUS object_set_illuminate(Object* object, BOOL illuminate){
  if (!object || !illuminate) {
    return ERROR;
  }
  
  object->illuminate = illuminate;
  return OK;
}

STATUS object_set_switchedOn(Object* object, BOOL switchedOn){
  if (!object || !switchedOn) {
    return ERROR;
  }
  
  object->switchedOn = switchedOn;
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

const char* object_get_description2(Object* object){
  if (!object){
    return NULL;
  }
  return object->description2;
}

BOOL object_get_movable(Object* object){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->movable;
}

BOOL object_get_moved(Object* object){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->moved;
}

BOOL object_get_hidden(Object* object, BOOL hidden){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->hidden;
}

Id object_get_open(Object* object){
  if (!object) {
    return NO_ID;
  }
  
  return object->open;
}

BOOL object_get_illuminate(Object* object){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->illuminate;
}

BOOL object_get_switchedOn(Object* object){
  if (!object) {
    return NULL_BOOLEAN;
  }
  
  return object->switchedOn;
}

STATUS object_print(Object* object){
  if (!object) {
    return ERROR;
  }
  
  char a[WORD_SIZE + 1], b[WORD_SIZE + 1], x[WORD_SIZE + 1], y[WORD_SIZE + 1], z[WORD_SIZE + 1], description[WORD_SIZE + 1];
  if (object->moved == FALSE) a = "Not movable";
  else a = "Movable";
  if (object->moved == FALSE){
    b = "Not moved";
    strcpy(description, object->description);
  }
  else {
    b = "Moved";
    strcpy(description, object->description2);
  }
  if (object->hidden == FALSE) x = "Not hidden";
  else x = "Hidden";
  if (object->illuminate == FALSE) y = "Cant illuminate";
  else y = "Can illuminate";
  if (object->switchedOn == FALSE) z = "SwitchedOff";
  else z = "SwitchedOn";
  
  if (object->movable == FALSE){
    if (object->illuminate == FALSE){
      fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Description: %s; %s; %s; Open: %ld; %s)\n", object->id, object->name, object->space_id, description, a, x, object->open, y);
    }
    else {
      fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Description: %s; %s; %s; Open: %ld; %s; %s)\n", object->id, object->name, object->space_id, description, a, x, object->open, y, z);
    }
  }
  else {
    if (object->illuminate == FALSE){
      fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Description: %s; %s; %s; %s; Open: %ld; %s)\n", object->id, object->name, object->space_id, description, a, b, x, object->open, y);
    }
    else {
      fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld; Description: %s; %s; %s; %s; Open: %ld; %s; %s)\n", object->id, object->name, object->space_id, description, a, b, x, object->open, y, z);
    }
  }
    
	return OK;
}
