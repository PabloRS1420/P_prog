/**
 * @brief It defines an object and gives the functions necessary to handle it
 *
 * @file object.h
 * @author Frederik Mayer
 * @version 1.0
 * @date 10-02-2018
 * @copyright GNU Public License
 *
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** ADT representing objects on the game board*/
typedef struct _Object Object;


/**maximum number of spaces on the board*/
#define MAX_SPACES 100

/**number of the first space*/
#define FIRST_SPACE 1

/**maximum number of objects*/
#define MAX_OBJECTS 9

/**
  * @brief It reserves memory for an Object* initialising the struct.
  * @param Id
  * @return Object*
  * @author Frederik Mayer
  */
Object* object_create(Id id);

/**
  * @brief It frees all the memory reserved.
  * @param Object*
  * @return OK if everything went well or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS object_destroy(Object* object);

/**
  * @brief Returns the id of the given object.
  * @param Object*
  * @return Id
  * @author Frederik Mayer
  */
Id object_get_id(Object* object);

/**
  * @brief Sets the name of the given object.
  * @param Object*, Char*
  * @return OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS object_set_name(Object *object, char* name);

/**
  * @brief Sets the location of the given object.
  * @param Object*, Id
  * @return OK if everything worked correctly or ERROR if not.
  * @author Frederik Mayer
  */
STATUS object_set_space_id(Object *object, Id space_id);

/**
  * @brief Sets the description of the given object.
  * @param Object*, Id
  * @return OK if everything worked correctly or ERROR if not.
  * @author Frederik Mayer
  */
STATUS object_set_description(Object* object, char* des);

/**
  * @brief Returns the name of the given object.
  * @param Object*
  * @return const Char*
  * @author Oriana Nicole Pastor Sánchez
  */
const char* object_get_name(Object *object);

/**
  * @brief Returns the location of the given object.
  * @param Object*
  * @return Id
  * @author Frederik Mayer
  */
Id object_get_space_id(Object *object);

/**
  * @brief Prints the relevant data of the object.
  * @param Object*
  * @return OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS object_print(Object* object);

/**
  * @brief Returns the description of the given object.
  * @param Object*
  * @return String
  * @author Frederik Mayer
  */
const char* object_get_description(Object* object);

#endif
