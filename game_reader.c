/**
 * @brief Module reads the data necessary to initialize a game from a given
 *        date file
 *
 * @file game_reader.c
 * @author Ignacio Castillo
 * @version 1.0: Module outsourced from module game
 * @date 15-02-2018
 * @copyright GNU Public License
 */


#include "game_reader.h"

STATUS game_load_spaces(Game* game, char* filename) {
  /*initializing all variables to default values*/
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char space_name[WORD_SIZE] = "";
  char obj_name[WORD_SIZE] = "";
  char* toks = NULL;
  char link_nameN[WORD_SIZE] = "";
  Id statusLN = 0;
  Id link_idN = NO_ID, spaceL1N = NO_ID, spaceL2N = NO_ID;
  char link_nameS[WORD_SIZE] = "";
  Id statusLS = 0;
  Id link_idS = NO_ID, spaceL1S = NO_ID, spaceL2S = NO_ID;
  char link_nameE[WORD_SIZE] = "";
  Id statusLE = 0;
  Id link_idE = NO_ID, spaceL1E = NO_ID, spaceL2E = NO_ID;
  char link_nameW[WORD_SIZE] = "";
  Id statusLW = 0;
  Id link_idW = NO_ID, spaceL1W = NO_ID, spaceL2W = NO_ID;
  Id space_id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, obj_id = NO_ID;
  Space* space = NULL;
  Object* new_obj = NULL;
  char* gdesc[3];
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
      obj_id = atol(toks);
      toks = strtok(NULL, "|");
      /*until now, only one object per space can be
        placed at the beginnning, can be changed if necessary*/
      strcpy(obj_name, toks);
      printf("Before gdesc reading.");
      toks = strtok(NULL, "|");
      strcpy(gdesc[0], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[1], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[2], toks);
      
      toks = strtok(NULL, "|");
      link_idN = atol(toks);
      toks = strtok(NULL, "|");
      spaceL1N = atol(toks);
      toks = strtok(NULL, "|");
      spaceL2N = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(link_nameN, toks);
      toks = strtok(NULL, "|");
      statusLN = atol(toks);
      
      toks = strtok(NULL, "|");
      link_idE = atol(toks);
      toks = strtok(NULL, "|");
      spaceL1E = atol(toks);
      toks = strtok(NULL, "|");
      spaceL2E = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(link_nameE, toks);
      toks = strtok(NULL, "|");
      statusLE = atol(toks);
      
      toks = strtok(NULL, "|");
      link_idS = atol(toks);
      toks = strtok(NULL, "|");
      spaceL1S = atol(toks);
      toks = strtok(NULL, "|");
      spaceL2S = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(link_nameS, toks);
      toks = strtok(NULL, "|");
      statusLS = atol(toks);
      
      toks = strtok(NULL, "|");
      link_idW = atol(toks);
      toks = strtok(NULL, "|");
      spaceL1W = atol(toks);
      toks = strtok(NULL, "|");
      spaceL2W = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(link_nameW, toks);
      toks = strtok(NULL, "|");
      statusLW = atol(toks);


#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%s|%ld|%ld|%ld|%s|%ld|%ld|%ld|%ld|%s|%ld|%ld|%ld|%ld|%s|%ld|%ld|%ld|%ld|%s|%ld\n", space_id, space_name, north, east, south, west, obj_id, obj_name, link_idN, spaceL1N, spaceL2N, link_nameN, statusLE, link_idE, spaceL1E, spaceL2E, link_nameE, statusLE, link_idS, spaceL1S, spaceL2S, link_nameS, statusLS, link_idW, spaceL1W, spaceL2W, link_nameW, statusLW);
#endif
      printf("Test3");
      space = space_create(space_id);
      if (space != NULL) {
      	space_set_name(space, space_name);
      	space_set_north(space, north);
      	space_set_east(space, east);
      	space_set_south(space, south);
      	space_set_west(space, west);
        space_set_gdesc(space, gdesc);
        printf("Before object adding.");
        if (obj_id != NO_ID){
          new_obj = object_create(obj_id);
          object_set_name(new_obj, obj_name);
          object_set_space_id(new_obj, space_id);
          space_add_object(space, obj_id);
          game_add_object(game, new_obj);
          new_obj=NULL;
        }
        if (link_idN != NO_ID){
          LinkN = link_create(link_idN);
          link_set_name(LinkN, link_nameN);
          link_set_spaceL1(LinkN, spaceL1N);
          link_set_spaceL2(LinkN, spaceL2N);
          link_set_statusL(LinkN, statusLN);
        }
        if (link_idE != NO_ID){
          LinkE = link_create(link_idE);
          link_set_name(LinkE, link_nameE);
          link_set_spaceL1(LinkE, spaceL1E);
          link_set_spaceL2(LinkE, spaceL2E);
          link_set_statusL(LinkE, statusLE);
        }
        if (link_idS != NO_ID){
          LinkS = link_create(link_idS);
          link_set_name(LinkS, link_nameS);
          link_set_spaceL1(LinkS, spaceL1S);
          link_set_spaceL2(LinkS, spaceL2S);
          link_set_statusL(LinkS, statusLS);
        }
        if (link_idW != NO_ID){
          LinkW = link_create(link_idW);
          link_set_name(LinkW, link_nameW);
          link_set_spaceL1(LinkW, spaceL1W);
          link_set_spaceL2(LinkW, spaceL2W);
          link_set_statusL(LinkW, statusLW);
        }
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

