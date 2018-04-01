/**
 * @brief It defines the links between the spaces
 *
 * @file link.c
 * @author Pablo Rosales
 * @version 1.0
 * @date 18-03-2018
 * @copyright GNU Public License
 */


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

STATUS link_set_name(Link* link, char* name) {
    if (!link || !name) {
        return ERROR;
    }

    if (!strcpy(link->name, name)) {
        return ERROR;
    }

    return OK;
}

const char* link_get_name(Link* link) {
    if (!link) {
        return NULL;
    }
  return link->name;
} 

STATUS link_set_id(Link* link, Id id) {
    if (!link || id == NO_ID) {
        return ERROR;
    }
    link->idL = id;
    return OK;
}
    
Id link_get_id(Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->id;
}

STATUS link_set_spaceL1(Link* link, Id space) {
    if (!link || id == NO_ID) {
        return ERROR;
    }
    link->spaceL1 = id;
    return OK;
}
    
Id link_get_spaceL1(Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->spaceL1;
}

STATUS link_set_spaceL2(Link* link, Id space) {
    if (!link || id == NO_ID) {
        return ERROR;
    }
    link->spaceL2 = id;
     return OK;
}
    
Id link_get_spaceL2(Link* link) {
    if (!link) {
        return NO_ID;
    }
    return link->spaceL2;
}

STATUS link_set_statusL(Link* link, int status) {
    if (!link || id < 0 || id > 1) {
        return ERROR;
    }
    link->statusL = status;
    return OK;
}
    
Id link_get_statusL(Link* link) {
    if (!link) {
        return -1;
    }
    return link->statusL;
}

Link* link_copy(const Link* link) {
    Link* lCopy = link_create(link->id);
    link_set_spaceL1(lCopy, link->spaceL1);
    link_set_spaceL2(lCopy, link->spaceL2);
    link_set_statusL(lCopy, link->statusL);
    link_set_name(lCopy, link->name);
    return lCopy;
}

STATUS link_print(Link* link) {
    if (!link) {
        return ERROR;
    }
    
    fprintf(stdout, "--> Link (Id: %ld; Name: %s; spaceL1: %ld; spaceL2: %ld; statusL: %d)\n",
            link->id, link->name, link->spaceL1, link->spaceL2, link->statusL);
    
