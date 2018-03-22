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

struct _Link Link;

Link* link_create(Id id);
STATUS link_destroy(Link* link);

STATUS link_set_name(Link* link, char* name);
const char* link_get_name(Link* link);

STATUS link_set_id(Link* link, Id id);
Id link_get_id(Link* link);

STATUS link_set_spaceL1(Link* link, Id id);
Id link_get_spaceL1(Link* link);

STATUS link_set_spaceL2(Link* link, Id id);
Id link_get_spaceL2(Link* link);

STATUS link_set_statusL(Link* link, Id id);
Id link_get_statusL(Link* link);

STATUS link_print(FILE* f, Link* link);

#endif
