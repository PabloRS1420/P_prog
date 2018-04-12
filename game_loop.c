/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/graphic_engine.h"
#include "../include/game.h"

int main(int argc, char *argv[]){
  BOOL make_log_file = FALSE;
  FILE* logfile = NULL;
  Game* game = NULL;
  Command* command_struct = NULL;
  T_Command command = NO_CMD;
  Graphic_engine* gengine;

  /*prints error if program is started without arguments*/
  if (argc < 2){
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (argc > 2){
    if (strcmp(argv[2],"-l") == 0){
      make_log_file = TRUE;
      if (argc < 4){
        fprintf(stderr, "Enter a log file path.\n");
        return 1;
      }
      printf("%s\n", argv[3]);
      logfile = fopen(argv[3], "w");
    }
  }

  game = game_ini();

  if(!game){
    if(make_log_file==TRUE){
      fclose(logfile);
    }
    return -1;
  }

/*following 2 statements print error statements if game/graphic_engine are initialized badly.*/

	if (game_create_from_file(game, argv[1]) == ERROR){
		fprintf(stderr, "Error while initializing game.\n");
    game_destroy(game);
    if(make_log_file==TRUE){
      fclose(logfile);
    }
		return 1;
	}
  printf("Test\n");

  game_print_data(game);

	if ((gengine = graphic_engine_create()) == NULL){
		fprintf(stderr, "Error while initializing graphic engine.\n");
		game_destroy(game);
    if(make_log_file==TRUE){
      fclose(logfile);
    }
		return 1;
	}

  /*reads user input and updates game until player ends game or game is over.*/
	while ( (command != EXIT) && !game_is_over(game) ){
		graphic_engine_paint_game(gengine, game);
		command_struct = command_get_user_input();
    printf("Got user input.\n");

    if(!command_struct){
      game_destroy(game);
      if(make_log_file==TRUE){
        fclose(logfile);
      }
      printf("No command found.\n");
      return 1;
    }

    command = command_get_command(command_struct);
    printf("Command: %d\n", command);
		game_update(game, command_struct, make_log_file, logfile);
    printf("Game updated.\n");
	}

	command_destroy(command_struct);
	graphic_engine_destroy(gengine);
  game_destroy(game);

  if (make_log_file==TRUE){
    fclose(logfile);
  }

	return 0;
}
