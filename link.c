/**
 * @brief It defines the links between the spaces
 *
 * @file link.c
 * @author Pablo Rosales
 * @version 1.0
 * @date 18-03-2018
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

struct _Link {
    Id idL, spaceL1, spaceL2;
    char nameL[WORD_SIZE + 1];
    int statusL //statusL = 0 link open, statusL = 1 link closed
}

Link* link_create(Id id) {
    Link* newLink = NULL;
    
    if (id == NO_ID)
        return NULL;
        
    newLink = (Link *) malloc(siceof (Link));
    if (newLink == NULL) {
        return NULL;
    }
    
    newLink->idL = id;
    newLink->nameL[0] = '\0';
    newLink->spaceL1 = NO_ID;
    newLink->spaceL2 = NO_ID;
    return newLink
}

STATUS link_destroy(Link* link) {
    if (!link) {
        return ERROR;
    }
    
    free(link);
}
