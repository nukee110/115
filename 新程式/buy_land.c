#include "the_final_report.h"
void IF_BUY_LAND (PLAYER *player_array, MAP map_array[],int* i,int* map_num)
{
    int j;
    printf("Do you want to buy the empty land? (1)Yes (2)No\n");
    scanf( "%d" , &j );
    if(j==1)
    {
        map_array[*map_num].owner=player_array[*i].id;
        map_array[*map_num].level += 1;
        player_array[*i].money -= 100;
    }
}

void IF_BUILD_HOUSE_ONE (PLAYER *player_array, MAP map_array[],int *i,int *map_num)
{
    int j;
    printf("Do you want to build the first house? (1)Yes (2)No\n");
    scanf( "%d" , &j );
    if(j==1)
    {
        map_array[*map_num].level=2;
        player_array[*i].money -= 200;
    }
}

void IF_BUILD_HOUSE_TWO (PLAYER *player_array, MAP map_array[],int* i,int* map_num)
{
    int j;
    printf("Do you want to build the second house? (1)Yes (2)No\n");
    scanf( "%d" , &j );
    if(j==1)
    {
        map_array[*map_num].level=3;
        player_array[*i].money -= 300;
    }
}
