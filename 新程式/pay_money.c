#include "the_final_report.h"
void OTHER_LAND (PLAYER *player_array, MAP map_array[],int* pay_money_player,int* map_num)
{
    int get_money_player = map_array[*map_num].owner-1;
    player_array[get_money_player].money += 100;
    player_array[*pay_money_player].money -= 100;
}
void OTHER_HOUSE_ONE (PLAYER *player_array, MAP map_array[],int* pay_money_player,int* map_num)
{
    int get_money_player = map_array[*map_num].owner-1;
    player_array[map_array[*map_num].owner].money += 200;
    player_array[*pay_money_player].money -= 200;
}

void OTHER_HOUSE_TWO (PLAYER *player_array, MAP map_array[],int* pay_money_player,int* map_num)
{
    int get_money_player = map_array[*map_num].owner-1;
    player_array[map_array[*map_num].owner].money += 300;
    player_array[*pay_money_player].money -= 300;
}
