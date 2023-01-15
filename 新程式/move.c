#include "the_final_report.h"
void Move(PLAYER *player_array,int i){
    switch (player_array[i].direction){
        case YPOSATIVE:
            player_array[i].location_y -= 1;
            if(player_array[i].location_y <= 101)
                player_array[i].direction = XPOSATIVE;
            break;
        case XPOSATIVE:
            player_array[i].location_x += 1;
            if(player_array[i].location_x >= WIDTH-SIZE-151)
                player_array[i].direction = YNEGATIVE;
            break;
        case YNEGATIVE:
            player_array[i].location_y += 1;
            if(player_array[i].location_y >= HEIGHT-101)
                player_array[i].direction = XNEGATIVE;
            break;
        case XNEGATIVE:
            player_array[i].location_x -= 1;
            if(player_array[i].location_x <= 201)
                player_array[i].direction = YPOSATIVE;
            break;
    }
}
