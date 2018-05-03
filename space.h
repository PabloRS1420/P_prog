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

/**ADT representing spaces on the game board*/
typedef struct _Space Space;

/**maximum number of spaces on the board*/
#define MAX_SPACES 100

/**number of the first space*/
#define FIRST_SPACE 1


/**
  * @brief It reserves memory for a Space* initialising the struct.
  * @param Id
  * @return Space*
  * @author Frederik Mayer
  */
Space* space_create(Id id);

/**
  * @brief It reserves memory for a Description* initialising the struct.
  * @param Space*
  * @return Description*
  * @author Pablo Rosales
  */
Description *description_create(Space *space);

/**
  * @brief It frees all the memory reserved.
  * @param Space*
  * @return OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_destroy(Space* space);

/**
  * @brief It frees all the memory reserved.
  * @param Description*
  * @return OK if everything worked correctly or ERROR if not.
  * @author Pablo Rosales
  */
STATUS description_destroy(Description *d);

/**
  * @brief Returns the Id of the space entered.
  * @param Sapce*
  * @return Id
  * @author Frederik Mayer
  */
Id space_get_id(Space* space);

/**
  * @brief Sets the name of the space entered.
  * @param Space*, Char*
  * @return OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief Returns the name of the space entered.
  * @param Space*
  * @return const Char*
  * @author Frederik Mayer
  */
const char* space_get_name(Space* space);

/**
  * @brief Sets the north link of the space.
  * @param Space*, Id, Id, Id, char, LINK_STATUS
  * @return OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_north(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL);

/**
  * @brief Returns the Link of the space which is in the north.
  * @param Space*
  * @return Link*
  * @author Frederik Mayer
  */
Link* space_get_north(Space* space);

/**
  * @brief Sets the south link of the space.
  * @param Space*, Id, Id, Id, char, LINK_STATUS
  * @return OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_south(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL);

/**
  * @brief Returns the Link of the space which is in the south.
  * @param Space*
  * @return Link*
  * @author Frederik Mayer
  */
Link* space_get_south(Space* space);

/**
  * @brief Sets the east link of the space.
  * @param Space*, Id, Id, Id, char, LINK_STATUS
  * @return OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_east(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL);

/**
  * @brief Returns the Link of the space which is in the east.
  * @param Space*
  * @return Link*
  * @author Frederik Mayer
  */
Link* space_get_east(Space* space);

/**
  * @brief Sets the west link of the space.
  * @param Space*, Id, Id, Id, char, LINK_STATUS
  * @return  OK if everything worked correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_set_west(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL);

/**
  * @brief Returns the Link of the space which is in the west.
  * @param Space*
  * @return Link*
  * @author Frederik Mayer
  */
Link* space_get_west(Space* space);

/**
  * @brief Sets the up link of the space.
  * @param Space*, Id, Id, Id, char, LINK_STATUS
  * @return  OK if everything worked correctly or ERROR if not.
  * @author Pablo Rosales
  */
STATUS space_set_up(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL);

/**
  * @brief Returns the Link of the space which is up.
  * @param Space*
  * @return Link*
  * @author Pablo Rosales
  */
Link* space_get_up(Space* space);

/**
  * @brief Sets the down link of the space.
  * @param Space*, Id, Id, Id, char, LINK_STATUS
  * @return  OK if everything worked correctly or ERROR if not.
  * @author Pablo Rosales
  */
STATUS space_set_down(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL);

/**
  * @brief Returns the Link of the space which is down.
  * @param Space*
  * @return Link*
  * @author Pablo Rosales
  */
Link* space_get_down(Space* space);

/**
  * @brief Adds the Id to the object array of the space.
  * @param Space*, Id, Id, Id, char, LINK_STATUS
  * @return OK if everything worked correctly or ERROR if not.
  * @author Frederik Mayer
  */
STATUS space_add_object(Space* space, Id id);

/**
  * @brief Returns a set with the id of all the objects in the space.
  * @param Space*
  * @return Set*
  * @author Frederik Mayer
  */
Set* space_get_object_set(Space* space);

/**
  * @brief Sets the picture of the space entered.
  * @param Space*, Char*
  * @return OK if everything works correctly or ERROR if not.
  * @author Frederik Mayer
  */
STATUS space_set_gdesc (Space* space, char* gdesc[]);

/**
  * @brief Returns the picture of the space entered.
  * @param Space*
  * @return Char**
  * @author Frederik Mayer
  */
char** space_get_gdesc(Space* space);

/**
* @brief Sets the description of the given space.
* @param Space*, Description
* @return OK if everything worked correctly or ERROR if not.
* @author Frederik Mayer
*/
STATUS space_set_description(Space* space, Description* des);

/**
  * @brief Returns the description of the given space.
  * @param Space*
  * @return Description
  * @author Frederik Mayer
  */
Description* space_get_description(Space* space);

/**
  * @brief Sets the illumination of the space.
  * @param Space* space, ILLUMINATION_SPACE illumination
  * @return  OK if everything worked correctly or ERROR if not.
  * @author Pablo Rosales
  */
STATUS space_set_illumination(Space* space, ILLUMINATION_SPACE illumination);

/**
  * @brief Returns the Link of the space which is up.
  * @param Space*
  * @return ILLUMINATION_SPACE
  * @author Pablo Rosales
  */
ILLUMINATION_SPACE space_get_illumination(Space* space);

/**
  * @brief Prints the information of the space.
  * @param Space*
  * @return OK if everything works correctly or ERROR if not.
  * @author Oriana Nicole Pastor Sánchez
  */
STATUS space_print(Space* space);

#endif
