#include "the_final_report.h"

int main(){
    int people;
    MOUSE st;
    MAP map_array[32];
    PLAYER *player_array = NULL;
    ALLEGRO_BITMAP *map = NULL;
    ALLEGRO_SAMPLE* boing = NULL;       /* pointer to sound file */
    ALLEGRO_SAMPLE* background = NULL;  /* pointer to sound file */
    ALLEGRO_SAMPLE_ID backgroundId;

    al_init();             /* initialize Allegro */
    al_init_image_addon();
    al_install_audio();  // install sound driver
    al_init_acodec_addon();
    al_reserve_samples(9);

    boing = al_load_sample("click.wav");    /* load the sound file */
    background = al_load_sample("background.wav"); /* load the background sound file */
    map = al_load_bitmap("./map.jpg");

    al_play_sample(background, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &backgroundId);
    Menu(&st,boing);             /*menu1*/
    Choose_number(&st,boing);    /*draw_number*/
    people = st.character_num;
    player_array = calloc(people,sizeof(PLAYER));   /*create array for players*/
    Chartr(&st,boing);
        /*character*/

    Start(player_array,&st,people);

    Round(player_array,map_array,people,map);

    al_destroy_bitmap(map);
    al_stop_sample(&backgroundId);   /* stop bgm */
    al_destroy_sample(background);  /* destroy the background sound file */
    al_destroy_sample(boing);       /* destroy the boing sound file */
    free(player_array);
    return 0;
}
