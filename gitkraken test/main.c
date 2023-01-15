#include "the_final_report.h"

int main(){
    int people;
    MOUSE st;
    MAP map_array[32];
    PLAYER *player_array = NULL;
    ALLEGRO_BITMAP *map = NULL;
    ALLEGRO_DISPLAY *display = NULL;        /* pointer to display */
    ALLEGRO_KEYBOARD_STATE KBstate;
    ALLEGRO_SAMPLE* boing = NULL;       /* pointer to sound file */
    ALLEGRO_SAMPLE* background = NULL;  /* pointer to sound file */
    ALLEGRO_SAMPLE_ID backgroundId;
    ALLEGRO_FONT* pongFont1 = NULL;      /* pointer to Font file */
    ALLEGRO_FONT* pongFont2 = NULL;      /* pointer to Font file */

    al_init();             /* initialize Allegro */
    al_install_keyboard(); /* install the keyboard for Allegro to use */
    al_init_image_addon();
    al_install_audio();  // install sound driver
    al_init_acodec_addon();
    al_reserve_samples(9);
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();

    boing = al_load_sample("click.wav");    /* load the sound file */
    background = al_load_sample("background.wav"); /* load the background sound file */
    pongFont1 = al_load_ttf_font("IMPRISHA.ttf", 48, 0); /* load the FONT file */
    pongFont2 = al_load_ttf_font("palabi.ttf", 60, 0); /* load the FONT file */
    map = al_load_bitmap("./map.jpg");

    al_play_sample(background, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &backgroundId);
    Menu(&st,pongFont1,pongFont2,boing);             /*menu1*/
    Choose_number(&st,boing);    /*draw_number*/
    people = st.character_num;
    player_array = calloc(people,sizeof(PLAYER));   /*create array for players*/
    Chartr(&st,boing);           /*character*/

    Start(player_array,&st,people);
    Map_Start(player_array,map_array);
    display = al_create_display(WIDTH,HEIGHT);

    Round(player_array,map_array,people,&KBstate,map);

    al_destroy_bitmap(map);
    al_destroy_display(display);
    al_stop_sample(&backgroundId);   /* stop bgm */
    al_destroy_sample(background);  /* destroy the background sound file */
    al_destroy_sample(boing);       /* destroy the boing sound file */
    al_destroy_font(pongFont1);      /* destroy the font */
    al_destroy_font(pongFont2);      /* destroy the font */
    free(player_array);
    return 0;
}
