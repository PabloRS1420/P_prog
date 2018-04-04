/**
 * @brief It defines a space
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include "space.h"
#include "link.h"

struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  Link* north;
  Link* south;
  Link* east;
  Link* west;
  Set* objects;
  char* gdesc[3];
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

  new_space->north = link_create(id-1);
  link_set_spaceL1(new_space->north, id);
  link_set_spaceL2(new_space->north, id-1);
    
  new_space->south = link_create(id);
  link_set_spaceL1(new_space->south, id);
  link_set_spaceL2(new_space->south, id+1);
    
  if (id == 5 || id == 9 || id == 13 || id == 17 || id == 21 || id == 25) {
      if (id == 5) x = 25;
      else if (id == 9) x = 26;
      else if (id == 13) x = 27;
      else if (id == 17) x = 28;
      else if (id == 21) x = 29;
      else if (id == 25) x = 30;
      new_space->east = link_create(x);
      link_set_spaceL1(new_space->east, id);
      link_set_spaceL2(new_space->east, id+4);
  }
  else if(id == 8) {
      new_space->east = link_create(30);
      link_set_spaceL1(new_space->east, id);
      link_set_spaceL2(new_space->east, id+8);
  }
  else if(id == 22) {
      new_space->east = link_create(31);
      link_set_spaceL1(new_space->east, id);
      link_set_spaceL2(new_space->east, id-21);
  }
  else {
      new_space->east = link_create(-1);
      link_set_spaceL1(new_space->east, -1);
      link_set_spaceL2(new_space->east, -1);
  }
    
  if (id == 16) {
     new_space->west = link_create(30);
     link_set_spaceL1(new_space->west, id);
     link_set_spaceL2(new_space->west, id-8);
  }
  else if(id == 22) {
      new_space->west = link_create(31);
      link_set_spaceL1(new_space->west, id);
      link_set_spaceL2(new_space->west, id-21);
  }
  else {
     new_space->west = link_create(-1);
     link_set_spaceL1(new_space->west, -1);
     link_set_spaceL2(new_space->west, -1);
  }

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
  link_destroy(space->north);
  link_destroy(space->south);
  link_destroy(space->east);
  link_destroy(space->west);

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
  link_set_spaceL2(space->north, id);
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
 link_set_spaceL2(space->south, id);
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
 link_set_spaceL2(space->east, id);
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  link_set_spaceL2(space->west, id);
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

STATUS space_print(Space* space) {
  Link* idaux = NULL;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = Link* link_copy(space->north);
  if (NULL != idaux) {
    link_print(idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = Link* link_copy(space->south);
  if (NULL != idaux) {
    link_print(idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = Link* link_copy(space->east);
  if (NULL != idaux) {
    link_print(idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = Link* link_copy(space->west);
  if (NULL != idaux) {
    link_print(idaux);
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
