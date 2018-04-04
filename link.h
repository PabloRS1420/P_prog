/**
 * @brief It defines the links between the spaces
 *
 * @file link.h
 * @author Pablo Rosales
 * @version 1.0
 * @date 18-03-2018
 * @copyright GNU Public License
 */
 
#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

struct _Link Link;

/**
  * @description Reserves memory for a Link* initialising the struct.
  * @input id
  * @output Link*
  * @author Pablo Rosales Sánchez
  */
Link* link_create(Id id);

/**
  * @description Frees all the memory reserved.
  * @input Link*
  * @output OK if everything went well or ERROR if not.
  * @author Pablo Rosales Sánchez
  */
STATUS link_destroy(Link* link);

/**
  * @description Sets the name of the link entered.
  * @input Link*, char*
  * @output OK if everything went well or ERROR if not.
  * @author Pablo Rosales Sánchez
  */
STATUS link_set_name(Link* link, char* name);

/**
  * @description Gets the name of the link entered.
  * @input Link*
  * @output char*
  * @author Pablo Rosales Sánchez
  */
const char* link_get_name(Link* link);

/**
  * @description Sets the id of the id of the link entered.
  * @input Link*, Id
  * @output OK if everything went well or ERROR if not.
  * @author Pablo Rosales Sánchez
  */
STATUS link_set_id(Link* link, Id id);

/**
  * @description Gets the id of the id of the link entered.
  * @input Link*
  * @output Id
  * @author Pablo Rosales Sánchez
  */
Id link_get_id(Link* link);

/**
  * @description Sets the id of the first space of the link entered.
  * @input Link*, Id
  * @output OK if everything went well or ERROR if not.
  * @author Pablo Rosales Sánchez
  */
STATUS link_set_spaceL1(Link* link, Id id);

/**
  * @description Gets the id of the first space of the link entered.
  * @input Link*
  * @output Id
  * @author Pablo Rosales Sánchez
  */
Id link_get_spaceL1(Link* link);

/**
  * @description Sets the id of the second space of the link entered.
  * @input Link*, Id
  * @output OK if everything went well or ERROR if not.
  * @author Pablo Rosales Sánchez
  */
STATUS link_set_spaceL2(Link* link, Id id);

/**
  * @description Gets the id of the second space of the link entered.
  * @input Link*
  * @output Id
  * @author Pablo Rosales Sánchez
  */
Id link_get_spaceL2(Link* link);

/**
  * @description Sets the id of the status of the link entered.
  * @input Link*, Id
  * @output OK if everything went well or ERROR if not.
  * @author Pablo Rosales Sánchez
  */
STATUS link_set_statusL(Link* link, Id id);

/**
  * @description Gets the id of the status of the link entered.
  * @input Link*
  * @output Id
  * @author Pablo Rosales Sánchez
  */
Id link_get_statusL(Link* link);

/**
  * @description Copies all the information of a the link entered into another one.
  * @input Link*
  * @output Link*
  * @author Pablo Rosales Sánchez
  */
Link* link_copy(const Link* link);

/**
  * @description Prints the relevant data of the link.
  * @input Link*
  * @output OK if everything went well or ERROR if not.
  * @author Pablo Rosales Sánchez
  */
STATUS link_print(Link* link);

#endif
