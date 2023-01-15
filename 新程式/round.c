#include "the_final_report.h"
void Round(PLAYER *player_array,MAP map_array[],int people,ALLEGRO_BITMAP *map){
    int temp = people+5;
    int i,step,stop;
    ALLEGRO_DISPLAY* display = NULL ;

    for(i = 0;i < people;i++){
        player_array[i].position = 1;
    }
    display = al_create_display(SCREEN_W, SCREEN_H);
    while(temp > 0){    //big round
        temp--;
        Dice(player_array,people);
        for(i = 0;i < people;i++){      //personal round
            if(player_array[i].jail_period != 0){  //whether in jail
                player_array[i].jail_period --;
                /*window function*/
                continue;
            }
            Draw(player_array,&people,map);
            Map_button(player_array,&people,&i,map);
            step = 0;
            stop = 0;

            while(step < player_array[i].dice * SQUARE){     //move one step
                if(step%SQUARE == 0 && stop < STOP){
                    stop++;
                    Draw(player_array,&people,map);
                }else{
                    stop = 0;
                    step ++;
                    Move(player_array,i);
                    Draw(player_array,&people,map);
                }
                /*start the specific function for each spuare*/
            }
            Game(player_array,map_array,i);
            Rank(player_array,&people);
        }
    }
    al_destroy_display(display);
    for(i = 0;i < people;i++){
        al_destroy_bitmap(player_array[i].picture);
    }
}
void Draw(PLAYER *player_array,int* people,ALLEGRO_BITMAP *map){
    int i,j;
    al_draw_bitmap(map,0,0,0);
    for(i = 0;i < *people;i++){
        al_draw_bitmap(player_array[i].picture,player_array[i].location_x,player_array[i].location_y,0);
        for(j = 0;j < *people ;j++){
            if(player_array[j].personal_rank == i)
                al_draw_bitmap(player_array[j].picture_head,RANK_X,RANK_Y+i*75,0);
        }
    }
    al_rest(REST);
    al_flip_display();
}
