/*
 * @brief It defines the links between the spaces
 *
 * @file link.h
 * @author Pablo Rosales
 * @version 1.0
 * @date 18-03-2018
 * @copyright GNU Public License
 */

#include "../include/link.h"

/**ADT that links 2 spaces, can be closed or open*/
struct _Link {
    Id idL;
    Id spaceL1;
    Id spaceL2;
    char nameL[WORD_SIZE + 1];
    LINK_STATUS statusL;
};

Link* link_create(Id id) {
    Link* newLink = NULL;

    if (id == NO_ID) return NULL;

    newLink = (Link *) malloc(sizeof (Link));

    if (newLink == NULL) return NULL;

    newLink->idL = id;
    newLink->nameL[0] = '\0';
    newLink->spaceL1 = NO_ID;
    newLink->spaceL2 = NO_ID;
    newLink->statusL = OPEN;
    return newLink;
}

STATUS link_destroy(Link* link) {
    if (!link) {
        return ERROR;
    }
    free(link);
    return OK;
}

STATUS link_set_name(Link* link, char* name) {
    if (!link || !name) {
        return ERROR;
    }

    if (!strcpy(link->nameL, name)) {
        return ERROR;
    }
    return OK;
}

STATUS link_set_spaceL1(Link* link, Id space) {
    if (!link || space == NO_ID) {
        return ERROR;
    }
    link->spaceL1 = space;
    return OK;
}

STATUS link_set_spaceL2(Link* link, Id space) {
    if (!link || space == NO_ID) {
        return ERROR;
    }
    link->spaceL2 = space;
     return OK;
}

STATUS link_set_statusL(Link* link, LINK_STATUS status) {
    if (!link || status < 0 || status > 1) {
        return ERROR;
    }
    link->statusL = status;
    return OK;
}

const char* link_get_name(const Link* link) {
    if (!link) {
        return NULL;
    }
    return link->nameL;
}

Id link_get_id(const Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->idL;
}

Id link_get_spaceL1(const Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->spaceL1;
}

Id link_get_spaceL2(const Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->spaceL2;
}

LINK_STATUS link_get_statusL(const Link* link) {
    if (!link) {
        return NO_STATUS;
    }
    return link->statusL;
}

STATUS link_print(FILE* output, const Link* link) {
    if (!link || !output) {
        return ERROR;
    }
    if(link_get_statusL(link)==OPEN){
      fprintf(output, "--> Link (Id: %ld; Name: %s; spaceL1: %ld; spaceL2: %ld; statusL: Open)\n", link->idL, link->nameL, link->spaceL1, link->spaceL2);
    }
    else{
      fprintf(output, "--> Link (Id: %ld; Name: %s; spaceL1: %ld; spaceL2: %ld; statusL: Closed)\n", link->idL, link->nameL, link->spaceL1, link->spaceL2);
    }
    return OK;
}
