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

STATUS object_print(Object* object){
  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s; SpaceId: %ld)\n", object->id, object->name, object->space_id);

	return OK;
}
