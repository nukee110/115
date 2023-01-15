#include "the_final_report.h"
void GET_CHANCE (PLAYER *player_array,int *i)
{
    srand(time(NULL));
    int j;
    j=rand()%2;
    if(j==1)
    {
        player_array[*i].money += 200;
    }
    else
    {
        player_array[*i].money -= 200;
    }
}
void GET_PROPS (PLAYER *player_array,int* i)
{
    srand(time(NULL));
    int j = rand() % 4;
    if (j==1)
    {
        player_array[*i].tool_free = player_array[*i].tool_free + 1;
        //printf("You get a free passing card.\n");
    }else if (j==2)
    {
        player_array[*i].tool_free = 0;
        player_array[*i].tool_stay = 0;
        player_array[*i].tool_dice = 0;
        //printf("Your props are all disappeared.\n");
    }else if (j==3)
    {
        player_array[*i].tool_dice = player_array[*i].tool_dice + 1;
        //printf("You get a dice card.\n");
    }else if (j==0)
    {
        player_array[*i].tool_stay = player_array[*i].tool_stay + 1;
        //printf("You get a stay in place card.\n");
    }
}
