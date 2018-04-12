/*
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Oriana Pastor
 * @version 1.0
 * @date 20-03-18
 * @copyright GNU Public License
 */

#include "../include/command.h"

/** ADT that contains a command and an id*/
struct _Command{
  Id id;
  T_Command c;
};

/*strings to be compared with the input typed by the player*/

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Following", "Previous",
 														"Grab", "Drop", "Throw", "Left", "Right", "Check", "Move"};
char *short_cmd_to_str[N_CMD] =  {"","","e","f","p","g","d","t","l","r","c", "m"};


/* --------------------------------------------------------------------
Function: command_get_user_input
Date: Dec. 19th., 2014
Author: Profesores PPROG
Description: Returns the command typed by the player
Input: void
Output: T_Command (enumeration)
------------------------------------------------------------------- */

Command* command_get_user_input(){

	T_Command cmd = NO_CMD;/*declares cmd as type T_Command (enumeration) and initializes it as NO_CMD (-1)*/
  char input1[CMD_LENGHT] = "";
  char input2[CMD_LENGHT] = "";
  char buff[WORD_SIZE] = "";
  Id idinput = NO_ID;
	int i = UNKNOWN - NO_CMD + 1, argnr = 0;/* i initialized to 2 (0-(-1)+1)*/
  Command *c = NULL;

  fgets(buff, WORD_SIZE, stdin);
  argnr = sscanf(buff, "%s %s", input1, input2);

  printf("Commmand1:%s\n", input1);
  printf("Commmand2:%s\n", input2);

	if (argnr > 0){
		cmd = UNKNOWN;
    c = command_create();

    if(!c){
      return NULL;
    }

		while(cmd == UNKNOWN && i < N_CMD){/* 2<11 whenever reached for the first time*/
      /*without the strlen condition, the command would be also valid if it starts with a shortcut letter:
       *for example "tldasf" would be read as "t"->"throw"*/
  		if (   (!strcasecmp(input1, short_cmd_to_str[i]) && strlen(input1) == strlen(short_cmd_to_str[i]))
          || (!strcasecmp(input1, cmd_to_str[i]) && strlen(input1) == strlen(cmd_to_str[i]))){
  			cmd = i + NO_CMD;
  		}
  		else{
				i++;
        printf("Not command %d\n", i);
			}
		}

    if(cmd == UNKNOWN) {
      printf("Command unknown\n");
      if(command_set_command(c, UNKNOWN) == ERROR){
        command_destroy(c);
        return NULL;
      }
      printf("Command unknown2\n");
      return c;
    }
    else if(argnr == 2){
      printf("Argnr=2\n");
      if(command_set_command(c, cmd) == ERROR){
        command_destroy(c);
        return NULL;
      }

      if (cmd==MOVE){
        printf("Move to the %s\n", input2);
        if(!strcmp(input2, "south")||!strcmp(input2, "s")){
          idinput=1;
          printf("South move.\n");
        }
        else if(!strcmp(input2, "north")||!strcmp(input2, "n")){
          idinput=2;
        }
        else if(!strcmp(input2, "west")||!strcmp(input2, "w")){
          idinput=3;
        }
        else if(!strcmp(input2, "east")||!strcmp(input2, "e")){
          idinput=4;
        }
        else{
          printf("Not a valid command structure.\n");
          if(command_set_id(c, idinput) == ERROR){
            command_destroy(c);
            return NULL;
          }
          return c;
        }
        if(command_set_id(c, idinput) == ERROR){
          command_destroy(c);
          return NULL;
        }
      }
      else{
        if(!strncmp(input2, "O", 1)){
          sscanf(input2, "O%ld", &idinput);
          printf("Id=%ld", idinput);
          if (idinput==NO_ID){
            printf("Not a valid command structure.\n");
            command_set_id(c, NO_ID);
            return c;
          }
        }
        else if(!strcmp(input2, "space")){
          idinput=SPACE_CHECK;
        }
        else {
          printf("Not a valid command structure.\n");
          command_set_id(c, NO_ID);
          return c;
        }
      }
      if(command_set_id(c, idinput) == ERROR){
        command_destroy(c);
        return NULL;
      }
	  }
    else if (argnr == 1){
      if(command_set_command(c, cmd) == ERROR){
        command_destroy(c);
        return NULL;
      }
    }
    return c;
  }

  return NULL;/*when input remains "" NULL is returned */
}


Command* command_create(){
  Command *c = NULL;

  c = (Command*) malloc(sizeof(Command));

  if(!c){
    return NULL;
  }

  c->id = NO_ID;
  c->c = NO_CMD;

  return c;
}

STATUS command_destroy(Command* c){
  if(!c){
    return ERROR;
  }
  free(c);
  return OK;
}

STATUS command_set_command(Command* c, T_Command tc){
  if(!c || tc == NO_CMD){
    return ERROR;
  }
  c->c = tc;
  return OK;
}

STATUS command_set_id(Command* c, Id id){
  if(!c || id == NO_ID){
    return ERROR;
  }
  c->id = id;
  return OK;
}

T_Command command_get_command(Command* c){
  if(!c) return NO_CMD;
  return c->c;
}

Id command_get_id(Command* c){
  if(!c) return NO_ID;
  return c->id;
}

char* command_get_text(Command* c){
  char* text="";
  if (command_get_command(c)==GRAB){
    sprintf(text, "Grab Object %ld:", command_get_id(c));
  }
  else{
    sprintf(text, "%s:", cmd_to_str[command_get_command(c)]);
  }
  return text;
}
