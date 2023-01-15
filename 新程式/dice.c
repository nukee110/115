#include "the_final_report.h"
void Dice(PLAYER *player_array,int people){
    int i;
    srand(time(NULL));
    for(i = 0;i < people;i++){
        player_array[i].dice = (rand()%DICESIZE) +1;
        player_array[i].position += player_array[i].dice;
        if(player_array[i].position > 32){
            player_array[i].position = player_array[i].position%32;
            player_array[i].money += 1000;
        }
    }
}
void Show_Dice(int dice_num){
    int time = 200;
    int i;

    //ALLEGRO_DISPLAY* display = NULL ;
    ALLEGRO_BITMAP *dice = NULL;
    ALLEGRO_BITMAP* dice1 = NULL;
    ALLEGRO_BITMAP* dice2 = NULL;
    ALLEGRO_BITMAP* dice3 = NULL;
    ALLEGRO_BITMAP* dice4 = NULL;

    al_init();
    al_init_image_addon();
    al_init_primitives_addon();

    //display = al_create_display(SCREEN_W, SCREEN_H);

    dice1 = al_load_bitmap("rolling1.png");
    dice2 = al_load_bitmap("rolling2.png");
    dice3 = al_load_bitmap("rolling3.png");
    dice4 = al_load_bitmap("rolling4.png");
    switch(dice_num){
        case 1:
            dice = al_load_bitmap("diceresult1.png");
            break;
        case 2:
            dice = al_load_bitmap("diceresult2.png");
            break;
        case 3:
            dice = al_load_bitmap("diceresult3.png");
            break;
        case 4:
            dice = al_load_bitmap("diceresult4.png");
            break;
        case 5:
            dice = al_load_bitmap("diceresult5.png");
            break;
        case 6:
            dice = al_load_bitmap("diceresult6.png");
            break;
    }
    for(i = 0 ;i < 4 ; i++){
        switch(i){
        case 0:{
            al_draw_bitmap(dice1,0,0,0);
            break;
        }
        case 1:{
            al_draw_bitmap(dice2,0,0,0);
            break;
        }
        case 2:{
            al_draw_bitmap(dice3,0,0,0);
            break;
        }
        case 3:{
            al_draw_bitmap(dice4,0,0,0);
            break;
        }
        }
        al_rest(0.5);
        al_flip_display();
    }
    while(time>0){
        time--;
        al_draw_bitmap(dice,0,0,0);
        al_rest(REST);
        al_flip_display();
    }
    al_destroy_bitmap(dice);
    al_destroy_bitmap(dice1);
    al_destroy_bitmap(dice2);
    al_destroy_bitmap(dice3);
    al_destroy_bitmap(dice4);
    //al_destroy_display(display);
}
