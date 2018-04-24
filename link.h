/**
 * @brief It defines the links between the spaces
 *
 * @file link.h
 * @author Pablo Rosales
 * @version 1.0
 * @date 18-03-2018
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/**maximum number of links*/
#define MAX_LINKS 100

/**default value for variables of type LINK_STATUS*/
#define NO_STATUS -1

/**ADT that links 2 spaces, can be closed or open*/
typedef struct _Link Link;

/**
  * @brief Reserves memory for a Link* initialising the struct.
  * @param id
  * @return Link*
  * @author Pablo Rosales
  */
Link* link_create(Id id);

/**
  * @brief Frees all the memory reserved.
  * @param Link*
  * @return OK if everything went well or ERROR if not.
  * @author Pablo Rosales
  */
STATUS link_destroy(Link* link);

/**
  * @brief Sets the name of the link entered.
  * @param Link*, char*
  * @return OK if everything went well or ERROR if not.
  * @author Pablo Rosales
  */
STATUS link_set_name(Link* link, char* name);

/**
  * @brief Sets the id of the first space of the link entered.
  * @param Link*, Id
  * @return OK if everything went well or ERROR if not.
  * @author Pablo Rosales
  */
STATUS link_set_spaceL1(Link* link, Id id);

/**
  * @brief Sets the id of the second space of the link entered.
  * @param Link*, Id
  * @return OK if everything went well or ERROR if not.
  * @author Pablo Rosales
  */
STATUS link_set_spaceL2(Link* link, Id space);

/**
  * @brief Sets the id of the status of the link entered.
  * @param Link*, Id
  * @return OK if everything went well or ERROR if not.
  * @author Pablo Rosales
  */
STATUS link_set_statusL(Link* link, LINK_STATUS status);

/**
  * @brief Gets the name of the link entered.
  * @param Link*
  * @return char*
  * @author Pablo Rosales
  */

const char* link_get_name(const Link* link);

/**
  * @brief Gets the id of the id of the link entered.
  * @param Link*
  * @return Id
  * @author Pablo Rosales
  */
Id link_get_id(const Link* link);

/**
  * @brief Gets the id of the first space of the link entered.
  * @param Link*
  * @return Id
  * @author Pablo Rosales
  */
Id link_get_spaceL1(const Link* link);

/**
  * @brief Gets the id of the second space of the link entered.
  * @param Link*
  * @return Id
  * @author Pablo Rosales
  */
Id link_get_spaceL2(const Link* link);

/**
  * @brief Gets the id of the status of the link entered.
  * @param Link*
  * @return Id
  * @author Pablo Rosales
  */
LINK_STATUS link_get_statusL(const Link* link);

/**
  * @brief Prints the relevant data of the link.
  * @param Link*
  * @return OPEN or CLOSED
  * @author Pablo Rosales
  */
STATUS link_print(FILE* output, const Link* link);

#endif
