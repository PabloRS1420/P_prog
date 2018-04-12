/**
 * @brief Allows the player to carry and manage several objects in his backpack.
 *
 * @file inventory.h
 * @author Oriana Pastor
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */

#include "set.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#define DIM 4

/**lets the player carry and handle more than one object*/
typedef struct _Inventory Inventory;

/**
 * @brief Creates an Inventory*.
 * @param None
 * @return Inventory*
 * @author Oriana Pastor
 */
Inventory* inventory_create();

/**
 * @brief Destroys an Inventory*.
 * @param Inventory*
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Pastor
 */
STATUS inventory_destroy(Inventory* inventory);

/**
 * @brief Adds an object to the inventory.
 * @param Inventory*, object_id
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Pastor
 */
STATUS inventory_add_object(Inventory* inventory, Id id);

/**
 * @brief Sets the maximum size of an inventory.
 * @param Inventory*, maximum size
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Pastor
 */
STATUS inventory_set_nmax(Inventory* inventory, int n);

/**
 * @brief Returns the maximum size of an inventory.
 * @param Inventory*
 * @return maximum size
 * @author Oriana Pastor
 */
int inventory_get_nmax(Inventory* inventory);

/**
 * @brief Returns the object set of an inventory.
 * @param Inventory*
 * @return Set* of object ids
 * @author Oriana Pastor
 */
Set* inventory_get_object_set(Inventory* inventory);

/**
 * @brief Check if the maximum number of objects is reached
 * @param Inventory*
 * @return TRUE if full, FALSE if not
 * @author Oriana Pastor
 */
BOOL inventory_is_full(Inventory* inventory);

/**
 * @brief Prints the relevant data of an inventory.
 * @param Inventory*
 * @return OK if everything went well or ERROR if not.
 * @author Oriana Pastor
 */
STATUS inventory_print(FILE* output, Inventory* inventory);
