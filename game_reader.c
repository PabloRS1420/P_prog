/*
 * @brief Module reads the data necessary to initialize a game from a given
 *        date file
 *
 * @file game_reader.h
 * @author Frederik Mayer
 * @version 1.0: Module outsourced from module game
 * @date 15-02-2018
 * @copyright GNU Public License
 */

#include "../include/game_reader.h"

STATUS game_reader_load_spaces(Game* game, char* filename) {
  /*initializing all variables to default values*/
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char space_name[WORD_SIZE] = "";
  char* toks = NULL;
  Id space_id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
  Space* space = NULL;
  char* gdesc[3];
  char description[WORD_SIZE];
  STATUS status = OK;

  gdesc[0]=(char*) malloc((LINE_SIZE+1)*sizeof(char));
  gdesc[1]=(char*) malloc((LINE_SIZE+1)*sizeof(char));
  gdesc[2]=(char*) malloc((LINE_SIZE+1)*sizeof(char));

  sprintf(gdesc[0], "       ");
  sprintf(gdesc[1], "       ");
  sprintf(gdesc[2], "       ");

  if (!filename) {
    return ERROR;
  }
  printf("Test2\n");

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  /*reading the game specifications from the file*/
  /*the format of the lines is: #s:$space_id$|$space_name$|$north$|$east$|
   *$south$|$west$|$obj_id$|$obj_name$|$gdesc[0]$|$gdesc[1]$|$gdesc[2]$|*/
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {  /*if the line begins with "#s:"*/
      toks = strtok(line + 3, "|");      /*seperate the sequence from the 3rd position until the first '|'*/
      space_id = atol(toks);                   /*and write its content in 'space_id'*/
      toks = strtok(NULL, "|");
      strcpy(space_name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      up = atol(toks);
      toks = strtok(NULL, "|");
      down = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[0], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[1], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[2], toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);


#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%s|%s|%s|%s\n", space_id, space_name, north, east, south, west, up, down, gdesc[0], gdesc[1], gdesc[2], description);
#endif
      printf("Test3");
      space = space_create(space_id);
      if (space != NULL) {
      	space_set_name(space, space_name);
      	space_set_north(space, north);
      	space_set_east(space, east);
      	space_set_south(space, south);
      	space_set_west(space, west);
        space_set_up(space, up);
      	space_set_down(space, down);
        space_set_gdesc(space, gdesc);
        space_set_description(space, description);
        game_add_space(game, space);
        printf("Space added.");
      }
      space=NULL;
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }
  free (gdesc[0]);
  free (gdesc[1]);
  free (gdesc[2]);
  fclose(file);

  return status;
}


STATUS game_reader_load_objects(Game* game, char* filename) {
  /*initializing all variables to default values*/
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char obj_name[WORD_SIZE] = "";
  char* toks = NULL;
  Id obj_id = NO_ID;
  Id space_id;
  Object* new_obj = NULL;
  STATUS status = OK;
  char description[WORD_SIZE];

  if (!filename) {
    return ERROR;
  }
  printf("Test2\n");

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  /*reading the game specifications from the file*/
  /*the format of the lines is: #o:$object_id$|$object_name$|$initial position$|$description$*/
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {  /*if the line begins with "#o:"*/
      toks = strtok(line + 3, "|");      /*seperate the sequence from the 3rd position until the first '|'*/
      obj_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(obj_name, toks);
      toks = strtok(NULL, "|");
      space_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s\n", obj_id, obj_name, space_id, description);
#endif
      printf("Test3");
      if (obj_id != NO_ID){
        new_obj = object_create(obj_id);
        object_set_name(new_obj, obj_name);
        object_set_space_id(new_obj, space_id);
        object_set_description(new_obj, description);
        game_add_object(game, new_obj);
        set_add_element(space_get_object_set(game_get_space(game, space_id)), obj_id);
        new_obj=NULL;
      }
    }
  }


  if (ferror(file)) {
    status = ERROR;
  }
  fclose(file);

  return status;
}

STATUS game_reader_load_links(Game* game, char* filename) {
  /*initializing all variables to default values*/
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char link_name[WORD_SIZE] = "";
  char* toks = NULL;
  Id link_id = NO_ID;
  Id spaceL1;
  Id spaceL2;
  LINK_STATUS statusL;
  Link *new_link = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }
  printf("Test2\n");

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  /*reading the game specifications from the file*/
  /*the format of the lines is: #l:$link_id$|$link_name$|$linked_space_1$|$linked_space_2$|$status$*/
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#l:", line, 3) == 0) {  /*if the line begins with "#l:"*/
      toks = strtok(line + 3, "|");      /*seperate the sequence from the 3rd position until the first '|'*/
      link_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(link_name, toks);
      toks = strtok(NULL, "|");
      spaceL1 = atol(toks);
      toks = strtok(NULL, "|");
      spaceL2 = atol(toks);
      toks = strtok(NULL, "|");
      statusL = atol(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%d|\n", link_id, link_name, spaceL1, spaceL2, statusL);
#endif
      printf("Test3");
      if (link_id != NO_ID){
        new_link = link_create(link_id);
        link_set_name(new_link, link_name);
        link_set_spaceL1(new_link, spaceL1);
        link_set_spaceL2(new_link, spaceL2);
        link_set_statusL(new_link, statusL);
        game_add_link(game, new_link);
        new_link=NULL;
      }
    }
  }


  if (ferror(file)) {
    status = ERROR;
  }
  fclose(file);

  return status;
}
