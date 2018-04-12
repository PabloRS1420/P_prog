/*
 * @brief It defines the game interface
 * for each command
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include "../include/game.h"
#include "../include/game_reader.h"


#define N_CALLBACK 11

/*ADT that represents a game instance.*/
struct _Game{
  Player *player;
  Object *objects[MAX_OBJECTS];
  Space* spaces[MAX_SPACES + 1];
  Dice* dice;
  Command* last_cmd;
  Link *links[MAX_LINKS];
  STATUS last_status;
  /**dice_failed is TRUE if rolling the dice would lead to a space that is out of bounds.
   *In that case, the player should stay at its position and graphic_engine
   *should print a message informing the user (variable is needed for
   *communication between the callback function and the graphic engine)*/
  BOOL dice_failed;
  char last_message[WORD_SIZE+1];
};

char *parse_cmd[N_CMD] = {"No command", "Unknown", "Exit", "Following", "Previous",
 														"Grab", "Drop", "Throw", "Left", "Right", "Check", "Move"};

/** Define the function type for the callbacks*/
typedef STATUS (*callback_fn)(Game* game);

/** List of callbacks for each command in the game*/
STATUS game_callback_unknown(Game* game);
STATUS game_callback_exit(Game* game);

/**
 * @brief Moves the player to the next space.
 * @author Frederik Mayer
 */
STATUS game_callback_following(Game* game);

/**
 * @brief Moves the player to the previous space.
 * @author Frederik Mayer
 */
STATUS game_callback_previous(Game* game);

/**
 * @brief Moves the player to the space to the left.
 * @author Frederik Mayer
 */
STATUS game_callback_left(Game *game);

/**
 * @brief Moves the player to the space to the right.
 * @author Frederik Mayer
 */
STATUS game_callback_right(Game *game);

/**
 * @brief Grabs the Object indicated by the id variable of the Game's
 * member variable last_cmd.
 * @author Frederik Mayer
 */
STATUS game_callback_grab(Game *game);
/**
 * @brief Leaves the object with the given id in the current space
 * @author Oriana Nicole Pastor Sánchez
 */
STATUS game_callback_leave(Game *game);

 /**
  * @brief Rolls the dice and precedes the amount of steps given by the dice.
  * @author Frederik Mayer
  */
STATUS game_callback_roll_dice(Game *game);

/**
 * @brief Displays the description of an object in the description area.
 * @author Frederik Mayer
 */
STATUS game_callback_check(Game *game);

/**
 * @brief Moves the player in the corresponding direction.
 * @author Frederik Mayer
 */
 STATUS game_callback_move(Game *game);


static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_following,
  game_callback_previous,
  game_callback_grab,
  game_callback_leave,
  game_callback_roll_dice,
  game_callback_left,
  game_callback_right,
  game_callback_check,
  game_callback_move
  };

/**
   Private functions
*/

/* finds the Id of the space with (intern array) number "position" */
Id     game_get_space_id_at(Game* game, int position);
/*'reverse function' to game_get_space_id_at, receives an Id and return the array number*/
int    game_find_space_nr (Game* game, Id space_id);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_objects(Game* game, Set* object_ids, Set* space_ids);

/**
   Game interface implementation
*/

Game *game_ini(){
  Game *game = NULL;
  game = (Game*)malloc(sizeof(Game));
  if(!game) return NULL;
  return game;
}


STATUS game_create(Game* game) {

  int i;

/* initialize all the variables */

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->player = player_create(1);

  game->dice = dice_create(1);

  for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }

  for (i = 0; i < MAX_LINKS; i++) {
    game->links[i] = NULL;
  }

  game->last_cmd = NULL;

  game->last_status = ERROR;

  game->dice_failed = FALSE;

  game->last_message[0]='\0';

  return OK;
}

STATUS game_create_from_file(Game* game, char* filename) {


  if(!game || !filename){
    return ERROR;
  }

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_links(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));

  space_set_description(game_get_space(game, 1), "This is Space 1");

  object_set_description(game_get_object_with_id(game, 4), "Don't panic!");

  printf("Space description:%s", space_get_description(game_get_space(game, 1)));

  return OK;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  if(!game){
    return OK;
  }

/* destroy all the board positions */
  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

/* destroy the data of player and object if they are not empty */
  if(game_get_player(game)){
    player_destroy(game_get_player(game));
  }

  if(game_get_dice(game)){
    dice_destroy(game_get_dice(game));
  }

  for(i=0; i<MAX_OBJECTS; i++){
    if (game_get_objects(game)[i]){
      if(object_destroy(game_get_objects(game)[i]) == ERROR){
        return ERROR;
      }
    }
  }

  for(i=0; i<MAX_LINKS; i++){
    if (game_get_links(game)[i]){
      if(link_destroy(game_get_links(game)[i]) == ERROR){
        return ERROR;
      }
    }
  }

  free(game);

  return OK;
}

/* add a space, if it is empty, to the game */
STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (!space || !game) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }
  space_destroy(game->spaces[i]);
  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game* game, Object* object){
  int i = 0;

  if (!object || !game) {
    return ERROR;
  }

  while ( (i < MAX_OBJECTS) && (game->objects[i] != NULL)){
    i++;
  }

  if (i >= MAX_OBJECTS) {
    return ERROR;
  }
  object_destroy(game->objects[i]);
  game->objects[i] = object;

  return OK;
}

STATUS game_add_link(Game* game, Link* link){
  int i = 0;

  if (!link || !game) {
    return ERROR;
  }

  while ( (i < MAX_LINKS) && (game->links[i] != NULL)){
    i++;
  }

  if (i == MAX_LINKS) {
    return ERROR;
  }
  link_destroy(game->links[i]);
  game->links[i] = link;

  return OK;
}

/* finds the Id of the space with (intern array) number "position" */
Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES || !game || !(game->spaces[position])) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/*'reverse function' to game_get_space_id_at, receives an Id and return the array number*/
int game_find_space_nr (Game* game, Id space_id){
  int i=0;
  for (i=0; i<MAX_SPACES; i++){
    if(game_get_space_id_at(game, i) == space_id){
      return i;
    }
  }
  printf("Space ID not found.");
  return -1;
}


/* take the space given its identifier */
Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID || !game) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}


/* locate the player in a certain space */
STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID || !game) {
    return ERROR;
  }

  if(player_set_space_id(game_get_player(game), id) == ERROR){
    return ERROR;
  }

  if(!game_get_player(game)){
    return ERROR;
  }

  return OK;

}

/* locate the objects in a certain space */
STATUS game_set_objects(Game* game, Set* object_ids, Set* space_ids) {
  int i=0;

  if (!object_ids || !space_ids || !game) {
    return ERROR;
  }

  if (set_get_size(space_ids) != set_get_size(object_ids)){
    return ERROR;
  }

  for (i=0; i < set_get_size(object_ids); i++){
    Id current_object = set_get_ids(object_ids)[i];
    Id current_space = set_get_ids(space_ids)[i];
    /*create object*/
    if (!((game->objects)[i] = object_create(current_object)))
    {
      return ERROR;
    }
    /*set its member variable space_id to the initial value*/
    if(object_set_space_id(game_get_object_with_id(game,current_object),
       set_get_ids(space_ids)[i]) == ERROR){
      return ERROR;
    }
    /*and add the object to the corresponding space*/
    if(set_add_element(space_get_object_set(game_get_space(game, current_space)),
      current_object) == ERROR){
      return ERROR;
    }
  }
  return OK;
}

Id game_get_player_location(Game *game) {

  if(!game) {
    return NO_ID;
  }

  return player_get_space_id(game_get_player(game));
}

Set* game_get_object_location_set(Game *game) {
  /*is not a member variable -> new object that has to be freed!*/
  int i = 0;
  Set* obj_locs = NULL;
  obj_locs = set_create();

  if(!game || !obj_locs) {
    return NULL;
  }
  for (i=0; i < MAX_OBJECTS; i++){
    if (game->objects[i]){
      set_add_element(obj_locs, object_get_space_id(game->objects[i]));
    }
  }
  return obj_locs;
}

Player* game_get_player(Game *game){
  if (!game){
    return NULL;
  }
  return game->player;
}

Object** game_get_objects(Game *game){
  if (!game){
    return NULL;
  }
  return game->objects;
}

Object* game_get_object_with_id(Game *game, Id obj_id){
  int i = 0;
  if (!game || obj_id == NO_ID){
    return NULL;
  }
  for (i=0; i < MAX_OBJECTS; i++){
    if (object_get_id(game_get_objects(game)[i]) == obj_id){
      return game_get_objects(game)[i];
    }
  }
  printf("Searched object ID doesn't exist.\n");
  return NULL;
}

Link** game_get_links(Game *game){
  if (!game){
    return NULL;
  }
  return game->links;
}

Link* game_get_link_with_id(Game* game, Id link_id){
  int i = 0;
  if (!game || link_id == NO_ID){
    return NULL;
  }
  for (i=0; i < MAX_LINKS; i++){
    if (link_get_id(game_get_links(game)[i]) == link_id){
      return game_get_links(game)[i];
    }
  }
  printf("Searched link ID doesn't exist.\n");
  return NULL;
}


Dice* game_get_dice(Game* game){
  if (!game){
    return NULL;
  }
  return game->dice;
}

STATUS game_update(Game* game, Command* cmd, BOOL make_log_file, FILE* logfile) {
  STATUS status=ERROR;
  T_Command last_cmd=NO_CMD;
  if(!cmd || !game) return ERROR;
  printf("game update.\n");
  if(game_get_last_command(game)){
    command_destroy(game->last_cmd);
  }

  game_set_dice_failed(game, FALSE);

  game->last_cmd = cmd;

  last_cmd = command_get_command(cmd);

  printf("Last command:%d\n", last_cmd);

  status = (*game_callback_fn_list[last_cmd])(game);

  if (make_log_file == TRUE && last_cmd != NO_CMD){
     if (last_cmd == GRAB){
       fprintf(logfile, "Grab O%ld:", command_get_id(cmd));
       if (status == ERROR){
         fprintf(logfile, "ERROR\n");
       }
       if (status == OK){
       fprintf(logfile, "OK\n");
       }
     }
     else if (last_cmd == ROLLDICE){  /*if the last command was rolling the dice, print the result*/
       fprintf(logfile, "Dice was rolled, result: %d\n", dice_get_result(game_get_dice(game)));
       /*If the dice roll leads to an exceedance of the play ground, an error message should
        *be displayed in the feedback area. This is told to the graphic engine by the variable dice_failed.*/
       if (game_get_dice_failed(game) == FALSE){
         fprintf(logfile, "Player moved forward by %d steps: OK\n", dice_get_result(game_get_dice(game)));
       }
       else{
         fprintf(logfile, "The game doesn't have enough spaces to go forward %d steps.\n",
                 dice_get_result(game_get_dice(game)));
       }
     }
     else{
       fprintf(logfile, "%s:", parse_cmd[last_cmd+1]);
       if (status == ERROR){
         fprintf(logfile, "ERROR\n");
       }
       if (status == OK){
       fprintf(logfile, "OK\n");
       }
     }
  }

  game_set_last_status(game, status);
  return OK;
}

Command * game_get_last_command(Game* game){
  if(!game) return NULL;
  return game->last_cmd;
}

BOOL game_get_dice_failed (Game* game){
  if (!game){
    return FALSE;
  }
  return game->dice_failed;
}
STATUS game_set_dice_failed (Game* game, BOOL dice_failed){
  if(!game){
    return ERROR;
  }
  game->dice_failed = dice_failed;
  return OK;
}

STATUS game_set_last_status (Game* game, STATUS status){
   if(!game){
     return ERROR;
   }
   game->last_status = status;
   return OK;
 }

 STATUS game_get_last_status (Game* game){
  if(!game){
    return ERROR;
  }
  return game->last_status;
}

STATUS game_set_last_message(Game* game, const char* des){
  if(!game){
    return ERROR;
  }
  strcpy(game->last_message, des);
  return OK;
}

char* game_get_last_message(Game* game){
  if(!game){
    return ERROR;
  }
  return game->last_message;
}

void game_print_data(Game *game) {
  int i = 0;
  Set* obj_locs = NULL;

  obj_locs=game_get_object_location_set(game);

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object locations: \n");
  set_print(obj_locs);
  set_destroy(obj_locs);
  printf("=> Player location: %d\n",(int) game_get_player_location(game));
  printf("=> Dice: ");
  dice_print(stdout, game_get_dice(game));
  printf("prompt:> ");
}


BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action
*/

STATUS game_callback_unknown(Game* game) {
  return ERROR;
}

STATUS game_callback_exit(Game* game) {
  return OK;
}

STATUS game_callback_following(Game* game) {
  Id space_id = NO_ID;
  Link* south_link=NULL;
  Id next_id = NO_ID;
  STATUS status=ERROR;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  printf("South link: %ld\n", space_get_south(game_get_space(game, space_id)));
  south_link=game_get_link_with_id(game,space_get_south(game_get_space(game, space_id)));
  if (link_get_statusL(south_link)==CLOSED){
    game_set_last_message(game, "The way is shut. It was made by those who are dead, and the dead keep it. The way is shut.");
    return ERROR;
  }
  next_id = link_get_spaceL2(south_link);
  printf("Next ID: %ld\n", next_id);
  if (next_id != NO_ID) {
    status = game_set_player_location(game, next_id);
  }
  else{
    status = ERROR;
  }
  return status;
}

STATUS game_callback_previous(Game* game) {
  Id next_id = NO_ID;
  Id space_id = NO_ID;
  Link* north_link=NULL;
  STATUS status = ERROR;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  printf("north link: %ld\n", space_get_north(game_get_space(game, space_id)));
  north_link=game_get_link_with_id(game,space_get_north(game_get_space(game, space_id)));
  if (link_get_statusL(north_link)==CLOSED){
    game_set_last_message(game, "The way is shut. It was made by those who are dead, and the dead keep it. The way is shut.");
    return ERROR;
  }
  next_id = link_get_spaceL1(north_link);
  printf("Next ID: %ld\n", next_id);

  if (next_id != NO_ID) {
    status = game_set_player_location(game, next_id);
  }
  else{
    status = ERROR;
  }

  return status;
}

/*grabs the object*/

STATUS game_callback_grab(Game* game) {
   Space* current_player_pos = NULL;
   STATUS status = ERROR;

   if(!game){
     return ERROR;
   }

   printf("Callback Grab with Id: %ld\n", command_get_id(game_get_last_command(game)));

   if(inventory_is_full(player_get_inventory(game_get_player(game))) == TRUE){
    fprintf(stderr, "Inventory is full");
    return ERROR;
  }

  if(player_is_carrying_object(game_get_player(game), command_get_id(game_get_last_command(game))) == TRUE){
   fprintf(stderr, "Player is already carrying the object with ID:%ld.", command_get_id(game_get_last_command(game)));
   return ERROR;
 }

   current_player_pos = game_get_space(game, player_get_space_id(game_get_player(game)));
   /*current_player_pos is a pointer to a Space in game, not a copy -> not to be freed!
     (used just for better understandibility, not necessary)*/

  /*if the number of objects in the current space of the player is greater than zero*/
  if(set_get_size(space_get_object_set(current_player_pos))>0){
    /*delete the grabbed object from the space's object IDs array*/
    if(set_delete_element(space_get_object_set(current_player_pos),
        command_get_id(game_get_last_command(game))) == ERROR){
      return ERROR;
    }
    /* pick up object with id passed from the command struct argument,*/
    /*assign the ID of the object to the player*/
    if(player_add_newobject(game_get_player(game), command_get_id(game_get_last_command(game))) == ERROR){
      return ERROR;
    }
    /*and set the object's space ID to NO_ID*/
    if(object_set_space_id(game_get_object_with_id(game,
        command_get_id(game_get_last_command(game))), NO_ID) == ERROR){
      return ERROR;
    }
    status = OK;
  }
  else{
    printf("No objects in the current space.\n");
    status = ERROR;
  }

  game_set_last_status(game, status);
  return status;
}

/*leaves the object in the current space*/
STATUS game_callback_leave(Game *game) {
  Player* player = NULL;
  Id obj_id = NO_ID;
  STATUS status = ERROR;

  if(!game){
    return ERROR;
  }
  player = game_get_player(game);
  obj_id = command_get_id(game_get_last_command(game));

  if(player_is_carrying_object(player, obj_id) == FALSE){
    fprintf(stderr, "Player has not picked up the object with ID:%ld.", obj_id);
    status = ERROR;
    return ERROR;
  }
  /*if the player is carrying an object*/
  if (obj_id != NO_ID){
    /*set this object's location to the current location of the player.*/
    if(object_set_space_id(game_get_object_with_id(game, obj_id), player_get_space_id(player)) == ERROR){
      return ERROR;
    }
    /*add the dropped object to the space's object ID set*/
    if(set_add_element(space_get_object_set(game_get_space(game, player_get_space_id(player))), obj_id) == ERROR){
      return ERROR;
    }
    /*and deassign the object from the player.*/
    if(set_delete_element(inventory_get_object_set(player_get_inventory(player)), obj_id) == ERROR){
      fprintf(stderr, "Couldnt deassign object from player.\n");
      return ERROR;
    }
    status = OK;
  }
  else{
    status = ERROR;
  }

  game_set_last_status(game, status);
  return status;
}

STATUS game_callback_roll_dice(Game *game) {
  int i = 0;
  Dice* dice = NULL;
  STATUS status = ERROR;

  if(!game){
    return ERROR;
  }
  dice = game_get_dice(game);
  if (dice_roll(dice) == ERROR){
    fprintf(stderr, "Error while rolling the dice.");
    return ERROR;
  }

  if(game_get_space_id_at(game, game_find_space_nr(game, game_get_player_location(game))
      + dice_get_result(dice)) != NO_ID){
    for (i=0; i < dice_get_result(dice); i++){
      game_callback_following(game);
    }
    status = OK;
  }
  else{
    game_set_dice_failed(game, TRUE);
    printf("The game doesn't have enough spaces to go forward %d steps.", dice_get_result(dice));
    status = ERROR;
  }

  game_set_last_status(game, status);
  return status;
}

STATUS game_callback_left(Game* game) {
  Id next_id = NO_ID;
  Id space_id = NO_ID;
  Link* west_link=NULL;
  STATUS status = ERROR;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  printf("west link: %ld\n", space_get_west(game_get_space(game, space_id)));
  west_link=game_get_link_with_id(game,space_get_west(game_get_space(game, space_id)));
  if (link_get_statusL(west_link)==CLOSED){
    game_set_last_message(game, "The way is shut. It was made by those who are dead, and the dead keep it. The way is shut.");
    return ERROR;
  }
  next_id = link_get_spaceL1(west_link);
  printf("Next ID: %ld\n", next_id);

  if (next_id != NO_ID) {
    status = game_set_player_location(game, next_id);
  }
  else{
    status = ERROR;
  }

  return status;
}

STATUS game_callback_right(Game* game) {
  Id next_id = NO_ID;
  Id space_id = NO_ID;
  Link* east_link=NULL;
  STATUS status = ERROR;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  printf("east link: %ld\n", space_get_east(game_get_space(game, space_id)));
  east_link=game_get_link_with_id(game,space_get_east(game_get_space(game, space_id)));
  if (link_get_statusL(east_link)==CLOSED){
    game_set_last_message(game, "The way is shut. It was made by those who are dead, and the dead keep it. The way is shut.");
    return ERROR;
  }
  next_id = link_get_spaceL2(east_link);
  printf("Next ID: %ld\n", next_id);

  if (next_id != NO_ID) {
    status = game_set_player_location(game, next_id);
  }
  else{
    status = ERROR;
  }

  return status;
}

STATUS game_callback_check(Game *game){
  Id id = NO_ID;

  printf("Callback check\n");
  if(!game){
    return ERROR;
  }

  id = command_get_id(game_get_last_command(game));
  printf("ID: %ld\n", id);
  if (id==NO_ID){
    return ERROR;
  }


  if(id==SPACE_CHECK){
    printf("Spacecheck\n");
    if(game_set_last_message(game, space_get_description(game_get_space
       (game,game_get_player_location(game))))==ERROR){
      return ERROR;
    }
  }
  else{
    if(game_set_last_message(game,object_get_description(
       game_get_object_with_id(game,id)))==ERROR){
      return ERROR;
    }
  }
  return OK;
}

STATUS game_callback_move(Game *game){
  Id id = NO_ID;

  if(!game){
    return ERROR;
  }

  id=command_get_id(game_get_last_command(game));

  if (id==1){
    return game_callback_following(game);
  }
  if (id==2){
    return game_callback_previous(game);
  }
  if (id==3){
    return game_callback_left(game);
  }
  if (id==4){
    return game_callback_right(game);
  }
  return ERROR;
}
