/*
 * @brief It defines a space
 *
 * @file space.h
 * @author Oriana Nicole Pastor Sánchez
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */


#include "../include/space.h"

/**ADT representing spaces on the game board*/
struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  Link* north;
  Link* south;
  Link* east;
  Link* west;
  Link* up;
  Link* down;
  Set* objects;
  char* gdesc[3];
  Description *description[WORD_SIZE];
  ILLUMINATION_SPACE illumination;
};

struct _Description {
    ILLUMINATION_SPACE illumination;
    Set* objects;
    Id north;
    Id south;
    Id east;
    Id west;
    Id up;
    Id down;
}

/****************************/
/* Functions implementation */
/****************************/

Space* space_create(Id id) {

  Space* new_space = NULL;

  if (id == NO_ID)
    return NULL;

  new_space = (Space *) malloc(sizeof (Space));

  if (new_space == NULL) {
    return NULL;
  }
  new_space->id = id;

  new_space->name[0] = '\0';

  new_space->north = NULL;
  new_space->north = link_create(NO_ID);
  new_space->south = NULL;
  new_space->south = link_create(NO_ID);
  new_space->east = NULL;
  new_space->east = link_create(NO_ID);
  new_space->west = NULL;
  new_space->west = link_create(NO_ID);
  new_space->up = NULL;
  new_space->up = link_create(NO_ID);
  new_space->down = NULL;
  new_space->down = link_create(NO_ID);
  
  new_space->illumination = ILLUMINATED;

  new_space->objects = set_create();

  new_space->gdesc[0]=(char*) malloc((LINE_SIZE+1)*sizeof(char));
  new_space->gdesc[1]=(char*) malloc((LINE_SIZE+1)*sizeof(char));
  new_space->gdesc[2]=(char*) malloc((LINE_SIZE+1)*sizeof(char));

  sprintf(new_space->gdesc[0], "       ");
  sprintf(new_space->gdesc[1], "       ");
  sprintf(new_space->gdesc[2], "       ");
    
  new_space->description = description_create(new_space);

  return new_space;
}

Description *description_create(Space *space) {
    Description *d = NULL;
    
    if(!space) return NULL;
    
    new_space = (Space *) malloc(sizeof (Space));
    if (new_space == NULL) return NULL;
    
    d->illumination = space->illumination;
    space->objects = space->objects;
    d->north = space->north->spaceL1;
    d->south = space->south->spaceL1;
    d->east = space->east->spaceL1;
    d->west = space->west->spaceL1;
    d->up = space->up->spaceL1;
    d->down = space->down->spaceL1;
    
    return d;
}

STATUS space_destroy(Space *space) {
  if (!space) {
    return ERROR;
  }
  set_destroy(space->objects);
  description->destroy(space->dscription)

  free (space->gdesc[0]);
  free (space->gdesc[1]);
  free (space->gdesc[2]);

  free(space);
  space = NULL;

  return OK;
}

STATUS description_destroy(Description *d) {
    if (!d) {
        return ERROR;
    }
    
    set_destroy(d->objects);
    free(d);
    return OK;
}

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_north(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL) {
  if (!space || idL == NO_ID || spaceL1 == NO_ID || spaceL2 == NO_ID || nameL == NULL || statusL < 0 || statusL > 1) {
    return ERROR;
  }
  space->north->idL = idL;
  space->north->spaceL1 = spaceL1;
  space->north->spaceL2 = spaceL2;
  strcpy(space->north->nameL, nameL);
  space->north->statusL = statusL;
  return OK;
}

STATUS space_set_south(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL) {
  if (!space || idL == NO_ID || spaceL1 == NO_ID || spaceL2 == NO_ID || nameL == NULL || statusL < 0 || statusL > 1) {
    return ERROR;
  }
  space->south->idL = idL;
  space->south->spaceL1 = spaceL1;
  space->south->spaceL2 = spaceL2;
  strcpy(space->south->nameL, nameL);
  space->south->statusL = statusL;
  return OK;
}

STATUS space_set_east(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL) {
  if (!space || idL == NO_ID || spaceL1 == NO_ID || spaceL2 == NO_ID || nameL == NULL || statusL < 0 || statusL > 1) {
    return ERROR;
  }
  space->east->idL = idL;
  space->east->spaceL1 = spaceL1;
  space->east->spaceL2 = spaceL2;
  strcpy(space->east->nameL, nameL);
  space->east->statusL = statusL;
  return OK;
}

STATUS space_set_west(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL) {
  if (!space || idL == NO_ID || spaceL1 == NO_ID || spaceL2 == NO_ID || nameL == NULL || statusL < 0 || statusL > 1) {
    return ERROR;
  }
  space->west->idL = idL;
  space->west->spaceL1 = spaceL1;
  space->west->spaceL2 = spaceL2;
  strcpy(space->west->nameL, nameL);
  space->west->statusL = statusL;
  return OK;
}

STATUS space_set_up(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL) {
  if (!space || idL == NO_ID || spaceL1 == NO_ID || spaceL2 == NO_ID || nameL == NULL || statusL < 0 || statusL > 1) {
    return ERROR;
  }
  space->up->idL = idL;
  space->up->spaceL1 = spaceL1;
  space->up->spaceL2 = spaceL2;
  strcpy(space->up->nameL, nameL);
  space->up->statusL = statusL;
  return OK;
}

STATUS space_set_down(Space* space, Id idL, Id spaceL1, Id spaceL2, char nameL, LINK_STATUS statusL) {
  if (!space || idL == NO_ID || spaceL1 == NO_ID || spaceL2 == NO_ID || nameL == NULL || statusL < 0 || statusL > 1) {
    return ERROR;
  }
  space->down->idL = idL;
  space->down->spaceL1 = spaceL1;
  space->down->spaceL2 = spaceL2;
  strcpy(space->down->nameL, nameL);
  space->down->statusL = statusL;
  return OK;
}

STATUS space_add_object(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  return set_add_element(space_get_object_set(space), id);
}

STATUS space_set_gdesc (Space* space, char* gdesc[]){
  if(!space){
    return ERROR;
  }
  strcpy(space->gdesc[0],gdesc[0]);
  strcpy(space->gdesc[1],gdesc[1]);
  strcpy(space->gdesc[2],gdesc[2]);
  return OK;
}

STATUS space_set_description(Space* space, Description* des){
  if (!space || !des) {
    return ERROR;
  }

  if (!strcpy(space->description, des)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_illumination(Space* space, ILLUMINATION_SPACE illumination){
  if (!space || illumination < 0 || illumination > 1) {
    return ERROR;
  }
  
  space->illumination = illumination;
  return OK;
}

const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

Link* space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Link* space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Link* space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Link* space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

Link* space_get_up(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->up;
}

Link* space_get_down(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->down;
}

Set* space_get_object_set(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->objects;
}

char** space_get_gdesc(Space* space){
  if (!space){
    return NULL;
  }
  return space->gdesc;
}

const char* space_get_description(Space* space){
  if (!space){
    return NULL;
  }
  
  if (space->illumination == DARKENED) {
    char des[WORD_SIZE] = "The space is not illuminated";
    return des;
  }
  
  return space->description;
}

ILLUMINATION_SPACE space_get_illumination(Space* space){
  if (!space){
    return NULL;
  }
  return space->illumination;
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  STATUS status = OK

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
  fprintf(stdout, "--> North: ");
  status = link_print(stdout, space->north);
  if (status != OK) {
    fprintf(stdout, "---> No link.\n");
  }
  fprintf(stdout, "--> South: ");
  status = link_print(stdout, space->south);
  if (status != OK) {
    fprintf(stdout, "---> No link.\n");
  }
  fprintf(stdout, "--> East: ");
  status = link_print(stdout, space->east);
  if (status != OK) {
    fprintf(stdout, "---> No link.\n");
  }
  fprintf(stdout, "--> West: ");
  status = link_print(stdout, space->west);
  if (status != OK) {
    fprintf(stdout, "---> No link.\n");
  }
  fprintf(stdout, "--> Up: ");
  status = link_print(stdout, space->up);
  if (status == OK) {
    fprintf(stdout, "---> No link.\n");
  }
  fprintf(stdout, "--> Down: ");
  status = link_print(stdout, space->down);
  if (status == OK) {
    fprintf(stdout, "---> No link.\n");
  }

  fprintf(stdout, "---> Objects located in the Space:\n");
  if(set_print(space_get_object_set(space)) == -1){
    return ERROR;
  }

  fprintf(stdout, "---> Gdesc of the Space:\n");
  fprintf(stdout, "%s\n",space_get_gdesc(space)[0]);
  fprintf(stdout, "%s\n",space_get_gdesc(space)[1]);
  fprintf(stdout, "%s\n",space_get_gdesc(space)[2]);
  
  if (space_get_illumination(space)==ILLUMINATED) {
     fprintf(stdout, "---> Space illuminated");
  }
  else {
    fprintf(stdout, "---> Space not illuminated");
  }
 
  return OK;
}
