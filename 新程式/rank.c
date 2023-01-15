#include "the_final_report.h"
//void Move_rank(PLAYER *player_array,ALLEGRO_BITMAP *map,int *people){
//    int i,j;
////    int time = 100;
////    while(time>0){
////        time --;
////        al_draw_bitmap(map,0,0,0);
////        for(i = 0;i < *people;i++){
////            al_draw_bitmap(player_array[i].picture,player_array[i].location_x,player_array[i].location_y,0);
////        }
//        for(i = 0;i < *people;i++){
//            for(j = 0;j < *people ;j++){
//                if(player_array[j].personal_rank == i)
//                    al_draw_bitmap(player_array[j].picture_head,RANK_X,RANK_Y+i*75,0);
//            }
//        }
//        al_flip_display();
//    //}
//}
void Rank(PLAYER *player_array,int *people){
    int i,j,tmp,tmp_id;
    int array[*people][2];
    for(i = 0;i < *people;i++){
        array[i][0] = i;
        array[i][1] = player_array[i].money;
    }
    for(i = 0;i < *people;i++){
        for(j = 0;j < i;j++){
            if(array[j][1] < array[i][1]){
                tmp = array[j][1];
                tmp_id = array[j][0];

                array[j][1] = array[i][1];
                array[j][0] = array[i][0];

                array[i][1] = tmp;
                array[i][0] = tmp_id;

            }
        }
    }
    for(i = 0;i < *people;i++){
        for(j = 0;j < *people;j++){
            if(array[j][0] == i)
                player_array[i].personal_rank = j;
        }
    }
}
