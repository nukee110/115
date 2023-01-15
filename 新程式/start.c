#include "the_final_report.h"
void Start(PLAYER *player_array,MOUSE *st,int people){
    int i;
    srand(time(NULL));
    for(i = 0;i < people;i++){
        player_array[i].id = i+1;
        player_array[i].direction = YPOSATIVE;
        player_array[i].location_x = 200;
        player_array[i].location_y = HEIGHT-100;
        player_array[i].money = STARTMONEY;
        player_array[i].life = 'T';
        player_array[i].picture_number =  st->character[i];
        player_array[i].jail_period = 0;
        player_array[i].tool_free = 0;
        player_array[i].tool_stay = 0;
        player_array[i].tool_dice = 0;
        player_array[i].personal_rank = i;
        switch(player_array[i].picture_number){
            case 1:
                player_array[i].picture = al_load_bitmap("littlebin.png");
                player_array[i].picture_head = al_load_bitmap("littlebin_head.png");
                break;
            case 2:
                player_array[i].picture = al_load_bitmap("conan.png");
                player_array[i].picture_head = al_load_bitmap("conan_head.png");
                break;
            case 3:
                player_array[i].picture = al_load_bitmap("pikachu.png");
                player_array[i].picture_head = al_load_bitmap("pikachu_head.png");
                break;
            case 4:
                player_array[i].picture = al_load_bitmap("doraemon.png");
                player_array[i].picture_head = al_load_bitmap("doraemon_head.png");
                break;
            case 5:
                player_array[i].picture = al_load_bitmap("crayonshinchan.png");
                player_array[i].picture_head = al_load_bitmap("crayonshinchan_head.png");
                break;
            case 6:
                player_array[i].picture = al_load_bitmap("spongebob.png");
                player_array[i].picture_head = al_load_bitmap("spongebob_head.png");
                break;
            case 7:
                player_array[i].picture = al_load_bitmap("patrick.png");
                player_array[i].picture_head = al_load_bitmap("patrick_head.png");
                break;
            case 8:
                player_array[i].picture = al_load_bitmap("americancaptain.png");
                player_array[i].picture_head = al_load_bitmap("americancaptain_head.png");
                break;
        }
    }
}
void Map_Start(PLAYER *player_array,MAP map_array[]){
    int i;
    for(i = 0;i <= 31;i++){
        map_array[i].level = 0 ;//0
        map_array[i].owner = 0 ;//0
    }
}
