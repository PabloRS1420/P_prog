/**
 * @brief It defines a space
 *
 * @file space.h
 * @author Oriana Nicole Pastor Sánchez
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

typedef struct _Space Space;  /*ADT representing spaces on the game board*/

#define MAX_SPACES 100
#define FIRST_SPACE 1


/**
  * @description It reserves memory for a Space* initialising the struct.
  * @input Id
  * @output Space*
  * @author Frederik Mayer
  */
Space* space_create(Id id);

/**
  * @description It frees all the memory reserved.
  * @input Space*
  * @output OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_destroy(Space* space);

/**
  * @description Returns the Id of the space entered.
  * @input Space*
  * @output Id
  * @author Frederik Mayer
  */
Id space_get_id(Space* space);

/**
  * @description Sets the name of the space entered.
  * @input Space*, Char*
  * @output OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @description Returns the name of the space entered.
  * @input Space*
  * @output const Char*
  * @author Frederik Mayer
  */
const char* space_get_name(Space* space);

/**
  * @description Sets the north link of the space.
  * @input Space*
  * @output OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_north(Space* space, Id id);

/**
  * @description Returns the Link of the space which is in the north.
  * @input Space*
  * @output Link*
  * @author Frederik Mayer
  */
Link* space_get_north(Space* space);

/**
  * @description Sets the south link of the space.
  * @input Space*
  * @output OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_south(Space* space, Id id);

/**
  * @description Returns the Link of the space which is in the south.
  * @input Space*
  * @output Link*
  * @author Frederik Mayer
  */
Link* space_get_south(Space* space);

/**
  * @description Sets the east link of the space.
  * @input Space*
  * @output OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_east(Space* space, Id id);

/**
  * @description Returns the Link of the space which is in the east.
  * @input Space*
  * @output Link*
  * @author Frederik Mayer
  */
Link* space_get_east(Space* space);

/**
  * @description Sets the west link of the space.
  * @input Space*, Id
  * @output  OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_west(Space* space, Id id);

/**
  * @description Returns the Link of the space which is in the west.
  * @input Space*
  * @output Link*
  * @author Frederik Mayer
  */
Link* space_get_west(Space* space);

/**
  * @description Adds the Id to the object array of the space
  * @input Space*, Id
  * @output OK if everything worked correctly or ERROR if not.
  * @author Frederik Mayer
  */
STATUS space_add_object(Space* space, Id id);

/**
  * @description Returns a set with the id of all the objects in the space.
  * @input Space*
  * @output Set*
  * @author Frederik Mayer
  */
Set* space_get_object_set(Space* space);

/**
  * @description Sets the picture of the space entered.
  * @input Space*, Char*
  * @output OK if everything works correctly or ERROR if not.
  * @author Frederik Mayer
  */
STATUS space_set_gdesc (Space* space, char* gdesc[]);

/**
  * @description Returns the picture of the space entered.
  * @input Space*
  * @output Char**
  * @author Frederik Mayer
  */
char** space_get_gdesc(Space* space);

/**
  * @description Prints the information of the space.
  * @input Space*
  * @output OK if everything works correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_print(Space* space);

#endif
