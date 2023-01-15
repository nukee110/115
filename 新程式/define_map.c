#include "the_final_report.h"

void Game(PLAYER *player_array,MAP map_array[],int player){
    int map_num = player_array[player].position-1;

    if((player_array[player].position == 5)||(player_array[player].position == 21)){  /* type 2:destiny */
        GET_PROPS (player_array,&player);
        //printf("at 5 or 21\n");
    }
    else if((player_array[player].position == 13)||(player_array[player].position == 29)){  /* type 3:chance */
        GET_CHANCE (player_array,&player);
        //printf("at 13 or 29\n");
    }
    else if(player_array[player].position == 9){   /* type 4:jail */
        //printf("at 9\n");
        player_array[player].jail_period = 1;
    }
    else if(player_array[player].position == 17){  /* type 5:return to start */
        //printf("at 17\n");
        player_array[player].position = 1;
        player_array[player].location_x = 200;
        player_array[player].location_y = HEIGHT-100;
        player_array[player].direction = YPOSATIVE;
        player_array[player].money += 2000;
    }
    else if(player_array[player].position == 25){   /* type 6:black hole */
        //printf("at 25\n");
    }
    else{/* type 7:land */
        if(map_array[map_num].owner == 0)
            {
                IF_BUY_LAND (player_array,map_array,&player,&map_num);
            }
        else if(map_array[map_num].owner != 0)
            {
                //self
                if(map_array[map_num].owner == player_array[player].id){
                    if(map_array[map_num].level == 1)
                        IF_BUILD_HOUSE_ONE (player_array,map_array,&player,&map_num);
                    else if(map_array[map_num].level == 2)
                        IF_BUILD_HOUSE_TWO (player_array,map_array,&player,&map_num);
                }
                //other
                else if(map_array[map_num].owner != player_array[player].id){
                    if(map_array[map_num].level == 1){
                        OTHER_LAND (player_array,map_array,&player,&map_num);
                    }
                    else if(map_array[map_num].level ==2){
                        OTHER_HOUSE_ONE (player_array,map_array,&player,&map_num);
                    }
                    else if(map_array[map_num].level == 3)
                        OTHER_HOUSE_TWO (player_array,map_array,&player,&map_num);
                }
            }
        //printf("at land\n");
    }

}
