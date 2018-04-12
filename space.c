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
  Id north;
  Id south;
  Id east;
  Id west;
  Set* objects;
  char* gdesc[3];
  char description[WORD_SIZE];
};

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

  new_space->north = NO_ID;
  new_space->south = NO_ID;
  new_space->east = NO_ID;
  new_space->west = NO_ID;

  new_space->objects = set_create();

  new_space->gdesc[0]=(char*) malloc((LINE_SIZE+1)*sizeof(char));
  new_space->gdesc[1]=(char*) malloc((LINE_SIZE+1)*sizeof(char));
  new_space->gdesc[2]=(char*) malloc((LINE_SIZE+1)*sizeof(char));

  sprintf(new_space->gdesc[0], "       ");
  sprintf(new_space->gdesc[1], "       ");
  sprintf(new_space->gdesc[2], "       ");

  return new_space;
}

STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }
  set_destroy(space->objects);

  free (space->gdesc[0]);
  free (space->gdesc[1]);
  free (space->gdesc[2]);

  free(space);
  space = NULL;

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

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
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

STATUS space_set_description(Space* space, char* des){
  if (!space || !des) {
    return ERROR;
  }

  if (!strcpy(space->description, des)) {
    return ERROR;
  }

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

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
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
  return space->description;
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  fprintf(stdout, "---> Objects located in the Space:\n");
  if(set_print(space_get_object_set(space)) == -1){
    return ERROR;
  }

  fprintf(stdout, "---> Gdesc of the Space:\n");
  fprintf(stdout, "%s\n",space_get_gdesc(space)[0]);
  fprintf(stdout, "%s\n",space_get_gdesc(space)[1]);
  fprintf(stdout, "%s\n",space_get_gdesc(space)[2]);


  return OK;
}
