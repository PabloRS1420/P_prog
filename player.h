/**
  * @brief It defines a player and gives the functions necessary to handle it
  *
  * @file player.h
  * @author Oriana Pastor
  * @version 1.0
  * @date 10-02-2018
  * @copyright GNU Public License
  *
  */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "space.h"
#include "object.h"
#include "inventory.h"

/**ADT representing players in the game*/
typedef struct _Player Player;

/**maximum number of spaces*/
#define MAX_SPACES 100
/*number of the first space*/
#define FIRST_SPACE 1

/**
 * @brief It reserves memory for a Player* initialising the struct.
 * @param Id
 * @return Player*
 * @author Oriana Nicole Pastor Sánchez
 */
Player* player_create(Id id);

/**
 * @brief It frees all the memory reserved.
 * @param Player*
 * @return None
 * @author Frederik Mayer
 */
STATUS player_destroy(Player* player);

/**
 * @brief Returns the id of the player entered.
 * @param Player*
 * @return Id
 * @author Oriana Nicole Pastor Sánchez
 */
Id player_get_id(Player* player);

/**
 * @brief Sets the name of the player entered.
 * @param Player*, Char*
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS player_set_name(Player* player, char* name);

/**
 * @brief Returns the name of the player entered.
 * @param Player*
 * @return const Char*
 * @author Oriana Nicole Pastor Sánchez
 */
const char* player_get_name(Player* player);

/**
 * @brief Sets the location of the player.
 * @param Player*, Id
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS player_set_space_id(Player* player, Id space_id);

/**
 * @brief Sets the object carried by the player.
 * @param Player*, Id
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Nicole Pastor Sánchez
 */
STATUS player_add_newobject(Player* player, Id object_id);

/**
 * @brief Returns the location of the player.
 * @param Player*
 * @return Id
 * @author Frederik Mayer
 */
Id player_get_space_id(Player* player);

/**
 * @brief Returns the set of objects carried by the player.
 * @param Player*
 * @return Set*
 * @author Oriana Nicole Pastor Sánchez
 */
Id* player_get_objects_ids(Player *player);

/**
 * @brief Returns the inventory of the player.
 * @param Player*
 * @return Inventory*
 * @author Oriana Nicole Pastor Sánchez
 */
Inventory* player_get_inventory(Player *player);

/**
 * @brief Check is the player is carrying the object with the given id.
 * @param Player*, object_id
 * @return TRUE if object is carried by player, FALSE if not.
 * @author Oriana Nicole Pastor Sánchez
 */
BOOL player_is_carrying_object(Player *player, Id object_id);

/**
 * @brief Prints the relevant data of the player.
 * @param Player*
 * @return OK if everything went well or ERROR if not.
 * @author Frederik Mayer
 */
STATUS player_print(Player* player);

#endif
