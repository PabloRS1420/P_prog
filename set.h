/**
 * @brief Allows to store and manage a set of Ids, referring to TADs of different types.
 *
 * @file set.h
 * @author Frederik Mayer
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/**maximum number of sets*/
#define MAX_SET 9

/**ADT that can store multiple ids of different types.*/
typedef struct _Set Set;

/**
  * @brief It reserves memory for a Set* initialising the struct.
  * @param None
  * @return Set*
  * @author Frederik Mayer
  */
Set* set_create();

/**
  * @brief It frees all the memory reserved.
  * @param Set*
  * @return OK if everything went well or ERROR if not.
  * @author Frederik Mayer
  */
STATUS set_destroy(Set* set);

/**
  * @brief Returns the number of Ids in the set that are not NO_ID.
  * @param Set*
  * @return int, size of the set
  * @author Frederik Mayer
  */
int set_get_size(Set* set);

/**
  * @brief It adds a new element to the given set.
  * @param Set*, Id to be added
  * @return OK if everything went well or ERROR if not.
  * @author Oriana Frederik Mayer
  */
STATUS set_add_element(Set* set, Id elid);

/**
  * @brief It deletes the element with the given id from the set.
  *              The other elements are shifted to avoid gaps in the array.
  * @param Set*, Id to be deleted
  * @return OK if everything went well or ERROR if not.
  * @author Frederik Mayer
  */
STATUS set_delete_element(Set* set, Id elid);

/**
  * @brief Returns all the elements of the set
  * @param Set*
  * @return An array of Ids
  * @author Frederik Mayer
  */
Id* set_get_ids(Set* set);

/**
  * @brief Prints the relevant data of the set
  * @param Set*
  * @return int, number of characters printed.
  * @author Frederik Mayer
  */
int set_print(Set* set);

#endif
