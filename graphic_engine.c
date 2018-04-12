/*
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 18-01-2017
 * @copyright GNU Public License
 */

#include "../include/graphic_engine.h"


/**Graphic_engine contains the data structures necessary to display the game*/
struct _Graphic_engine{
  Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine* graphic_engine_create(){
  static Graphic_engine *ge = NULL;
  int y_plus = 8;
  int x_plus = 15;

  if (ge) return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  ge->map      = screen_area_init( 1, 1, 25, 13+y_plus);
  ge->descript = screen_area_init(27, 1, 52+x_plus, 13+y_plus);
  ge->banner   = screen_area_init(28,15+y_plus, 23,  1);
  ge->help     = screen_area_init( 1,16+y_plus, 78+x_plus,  2);
  ge->feedback = screen_area_init( 1,19+y_plus, 78+x_plus,  5);

  return ge;
}

void graphic_engine_destroy(Graphic_engine* ge){
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/*graphic_engine_paint_space paints a space on the board.
 *The graphic representation differs in a few details depending on if the
 *space to be printed is the top, middle or bottom space on the current screen.*/
STATUS graphic_engine_paint_space (Graphic_engine* ge, Game* game, Id space_id, POS pos){
  int i = 0, n_obj = 1;
  char obj[12] = "Ob:        ";
  char str[255];
  char player[4] = "   ";

  if (pos == MIDDLE){
    strcpy(player, ">8D");
  }
  if (space_id == NO_ID) {
    return ERROR;
  }

  for (i=0; i < MAX_OBJECTS; i++){
    if (n_obj > MAX_OBJ_PER_SP){
      printf("Maximum number of objects in one field: %i", MAX_OBJ_PER_SP);
      break;
    }
    if (object_get_space_id(game_get_objects(game)[i]) == space_id){
      obj[n_obj*2+1] = '0' + object_get_id(game_get_objects(game)[i]);
      obj[n_obj*2+2] = ',';
      n_obj++;
    }
  }
  while(n_obj <= MAX_OBJ_PER_SP){
    obj[n_obj*2+1] = ' ';
    n_obj++;
  }

  /*The arrow up is only to be printed, if it's the current space and you can go up from there
   *(that is, if it's not the first space.)*/
  if (pos == MIDDLE && space_get_north(game_get_space(game, space_id)) != NO_ID){
    sprintf(str, "          ^      ");
    screen_area_puts(ge->map, str);
  }
  /*The upper border (1st line) is not printed for the top space*/
  if (pos != TOP){
    sprintf(str, "    +-----------+");
    screen_area_puts(ge->map, str);
  }

  /*2nd line of a space contains the player (if it's the current space(MIDDLE)) and the space Id.*/
  if(space_get_east(game_get_space(game, space_id)) != NO_ID){
    sprintf(str, "    |    %3s  %2d| >%2d", player, (int) space_id,
    (int) space_get_east(game_get_space(game, space_id)));
    screen_area_puts(ge->map, str);
  }
  if (space_get_west(game_get_space(game, space_id)) != NO_ID){
    sprintf(str, "%2d< |    %3s  %2d|", (int) space_get_west(game_get_space(game, space_id)),
    player, (int) space_id);
    screen_area_puts(ge->map, str);
  }
  if (space_get_east(game_get_space(game, space_id)) == NO_ID
      && space_get_west(game_get_space(game, space_id)) == NO_ID){
    sprintf(str, "    |    %3s  %2d|", player, (int) space_id);
    screen_area_puts(ge->map, str);
  }

  /*line 3-5 contain the gdesc ASCII representation.*/
  sprintf(str, "    |%s|",space_get_gdesc(game_get_space(game, space_id))[0]);
  screen_area_puts(ge->map, str);
  sprintf(str, "    |%s|",space_get_gdesc(game_get_space(game, space_id))[1]);
  screen_area_puts(ge->map, str);
  sprintf(str, "    |%s|",space_get_gdesc(game_get_space(game, space_id))[2]);
  screen_area_puts(ge->map, str);

  /*line 6 contains the objects, line can hold up to 4 objects.*/
  sprintf(str, "    |%11s|",obj);
  screen_area_puts(ge->map, str);

  /*The lower border (6th line) is not printed for the top space*/
  if (pos != BOTTOM){
    sprintf(str, "    +-----------+");
    screen_area_puts(ge->map, str);
  }

  /*The arrow down is only to be printed, if it's the current space and you can go down from there
   *(that is, if it's not the last space.)*/
  if (pos == MIDDLE && space_get_south(game_get_space(game, space_id)) != NO_ID){
    sprintf(str, "          v      ");
    screen_area_puts(ge->map, str);
  }

  return OK;
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  int i = 0;
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID;
  Space* space_act = NULL;
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[];
  char str[255];
  Object* object = NULL;


  /* Paint the spaces, player(s) and object(s) in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);
    id_back = link_get_spaceL1(game_get_link_with_id(game,space_get_north(space_act)));
    id_next = link_get_spaceL2(game_get_link_with_id(game,space_get_south(space_act)));

    if (graphic_engine_paint_space(ge, game, id_back, TOP) == ERROR){
      fprintf(stderr, "Error while printing space with Id %ld\n", id_back);
    }
    if (graphic_engine_paint_space(ge, game, id_act, MIDDLE) == ERROR){
      fprintf(stderr, "Error while printing space with Id %ld\n", id_act);
    }
    if (graphic_engine_paint_space(ge, game, id_next, BOTTOM) == ERROR){
      fprintf(stderr, "Error while printing space with Id %ld\n", id_next);
    }
  }

  /* Paint the location of the objects in the description area */
  screen_area_clear(ge->descript);
  for (i=0; i < MAX_OBJECTS; i++){
    if ((object = game_get_objects(game)[i]) != NULL){
      if (object_get_space_id(object) != NO_ID){
        sprintf(str, "  %s (Id %d) at location: %d", object_get_name(object),
               (int) object_get_id(object), (int)object_get_space_id(object));
        screen_area_puts(ge->descript, str);
      }
      else{
        sprintf(str, "  %s (Id %d) is carried",
                object_get_name(object), (int) object_get_id(object));
        screen_area_puts(ge->descript, str);
        sprintf(str, "  by the player");
        screen_area_puts(ge->descript, str);
      }
    }
  }

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Position of the Player: %ld", game_get_player_location(game));
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Last value of the dice: %d", dice_get_result(game_get_dice(game)));
  screen_area_puts(ge->descript, str);


  /* Paint the name of the game in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the valid commands in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     following or f, previous or p, or exit or e, grab or g, drop or d,");
  screen_area_puts(ge->help, str);
  sprintf(str, "     throw (the dice) or t, left or l, right or r, move or m.");
  screen_area_puts(ge->help, str);

  /* Paint the last command in the feedback area */
  last_cmd = command_get_command(game_get_last_command(game));

  if (last_cmd > 1){    /*NO_CMD, Unknown and Exit don't require status messages*/
    if (game_get_last_status(game) == OK){
      sprintf(str, " %s: OK", cmd_to_str[last_cmd - NO_CMD]);
      screen_area_puts(ge->feedback, str);
    }
    else{
      sprintf(str, " %s: ERROR", cmd_to_str[last_cmd - NO_CMD]);
      screen_area_puts(ge->feedback, str);
    }
  }
  else{
    sprintf(str, " %s", cmd_to_str[last_cmd - NO_CMD]);
    screen_area_puts(ge->feedback, str);
  }


  if (last_cmd == ROLLDICE){  /*if the last command was rolling the dice, print the result*/
    sprintf(str, " Dice was rolled, result: %d", dice_get_result(game_get_dice(game)));
    screen_area_puts(ge->feedback, str);
    /*If the dice roll leads to an exceedance of the play ground, an error message should
     *be displayed in the feedback area. This is told to the graphic engine by the variable dice_failed.*/
    if (game_get_dice_failed(game) == FALSE){
      sprintf(str, " Player moved forward by %d steps.", dice_get_result(game_get_dice(game)));
      screen_area_puts(ge->feedback, str);
    }
    else{
      sprintf(str, " The game doesn't have enough spaces to go forward %d steps.",
              dice_get_result(game_get_dice(game)));
      screen_area_puts(ge->feedback, str);
    }
  }

  if (game_get_last_message(game)[0]!='\0'){
    sprintf(str, " %s", game_get_last_message(game));
    screen_area_puts(ge->feedback, str);
    game_set_last_message(game, "");
  }

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
