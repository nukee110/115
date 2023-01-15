#include "the_final_report.h"
void How_to_use(void){
    ALLEGRO_FONT* pongFont1 = NULL;      /* pointer to Font file */
    ALLEGRO_FONT* pongFont2 = NULL;      /* pointer to Font file */
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();
    pongFont1 = al_load_ttf_font("IMPRISHA.ttf", 48, 0); /* load the FONT file */
    pongFont2 = al_load_ttf_font("palabi.ttf", 60, 0); /* load the FONT file */
    al_draw_textf(pongFont2, al_map_rgb(300, 180, 700), 500, 100, 0,"Rule!!");
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 100, 200, 0,"1. Choose how many players in the following game.");
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 100, 275, 0,"2. Choose the characters you like.");
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 100, 350, 0,"3. Start the game ~~ ");
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 100, 425, 0,"4. When there is only one player on the map ,");
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 150, 500, 0,"the game is over.");
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 100, 575, 0,"5. Now you are ready for the game~~ ");
    al_destroy_font(pongFont1);      /* destroy the font */
    al_destroy_font(pongFont2);      /* destroy the font */
}
