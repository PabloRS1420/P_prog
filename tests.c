/*
 * @brief Implements all the tests of previous iterations,
      those are executed by execute_tests.c
 *
 * @file tests.h
 * @author Frederik Mayer
 * @version 1.0
 * @date 03-04-18
 * @copyright GNU Public License
 */

 #include "../include/tests.h"

 STATUS test1_set_test(){
   Set* set;
   set = set_create();
   set_add_element(set,12345678);
   set_add_element(set,12346678);
   set_add_element(set,12336978);
   set_add_element(set,12342628);
   set_add_element(set,12345678);
   printf("Set test:\n");

   set_print(set);
   if(set_delete_element(set,12336978) == ERROR){
     printf("Error in set_delete_element.");
     return ERROR;
   }
   if(set_delete_element(set,12345678) == ERROR){
     printf("Error in set_delete_element.");
     return ERROR;
   }
   set_print(set);
   set_destroy(set);
   return OK;
 }

 STATUS test2_dice_test(){
   int veces, i;
   Dice *d = NULL;

   srand((unsigned)time(NULL));

   d = dice_create(0);

   if(!d){
       return ERROR;
   }
   printf("Dice test:\n");
   printf("Enter the amount of times you want to roll the dice: ");
   scanf("%d", &veces);

   for(i=0; i < veces; i++){
       if(dice_roll(d) == ERROR){
           return ERROR;
       }
       if(dice_print(stdout, d) == ERROR){
           return ERROR;
       }
   }

   return OK;
 }
