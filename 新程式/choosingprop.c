#include "the_final_report.h"
void Choose_propnumber(PLAYER *player_array,int *player){
    int done = 1;
    int button = 0;
    int buttonfree = 0;
    int pos_x = 0;
    int pos_y = 0;
    int origin_free = player_array[*player].tool_free;
    int origin_dice = player_array[*player].tool_dice;
    int origin_stay = player_array[*player].tool_stay;
    //ALLEGRO_DISPLAY* display = NULL ;
    ALLEGRO_BITMAP* chooseprops = NULL;
    ALLEGRO_BITMAP* choosedice = NULL;
    ALLEGRO_BITMAP* choosestay = NULL;
    ALLEGRO_EVENT_QUEUE* ev_que = NULL;
    ALLEGRO_FONT* pongFont1 = NULL;      /* pointer to Font file */


    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();

    ev_que = al_create_event_queue();
    //display = al_create_display(SCREEN_W, SCREEN_H);
    pongFont1 = al_load_ttf_font("IMPRISHA.ttf", 48, 0); /* load the FONT file */
    chooseprops = al_load_bitmap("chooseprop.png");
    choosedice = al_load_bitmap("choosedice.png");
    choosestay = al_load_bitmap("choosestay.png");
    //al_register_event_source(ev_que,al_get_display_event_source(display));
    al_register_event_source(ev_que, al_get_mouse_event_source());
    al_draw_bitmap(chooseprops,0,0,0);
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 270, 850, 0,"%d",origin_free);
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 600, 850, 0,"%d",origin_dice);
    al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 900, 850, 0,"%d",origin_stay);
     while(done == 1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(ev_que, &ev);

        if(button == 0)
            al_draw_bitmap(chooseprops,0,0,0);
        if(button == 1)
            al_draw_bitmap(choosedice,0,0,0);
        if(button == 2)
            al_draw_bitmap(choosestay,0,0,0);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
        {
            done = 0;
        }
        al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 270, 850, 0,"%d",origin_free);
        al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 600, 850, 0,"%d",origin_dice);
        al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 900, 850, 0,"%d",origin_stay);
        if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
         {
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;

                 if((pos_x>=146)&&(pos_x<=418)&&(pos_y>=323)&&(pos_y<=576) && button != 4 && buttonfree == 0)
                    {
                      if(ev.mouse.button & 1)//choose free
                      {
                         buttonfree = 1;
                      }
                    }
                 else if((pos_x>=484)&&(pos_x<=726)&&(pos_y>=335)&&(pos_y<=559) && button != 4)
                    {
                      button = 1;
                      if(ev.mouse.button & 1)//choose dice
                      {
                         button = 4;
                         player_array[*player].tool_dice -= 1;
                         al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 645, 850, 0,"-1");
                      }
                    }
                 else if((pos_x>=787)&&(pos_x<=1042)&&(pos_y>=328)&&(pos_y<=581) && button != 4)
                    {
                      button = 2;
                      if(ev.mouse.button & 1)//choose stay
                      {
                         button = 4;
                         player_array[*player].tool_stay -= 1;
                         al_draw_textf(pongFont1, al_map_rgb(300, 180, 700), 945, 850, 0,"-1");
                      }
                    }
                 else if((pos_x>=22)&&(pos_x<=219)&&(pos_y>=912)&&(pos_y<=992) && button != 4 && ev.mouse.button & 1)
                    {
                      done = 0;//choose back
                    }
                 else if((pos_x>=980)&&(pos_x<=1183)&&(pos_y>=914)&&(pos_y<=990) && button == 4 && ev.mouse.button & 1)
                    {
                      done = 0;//choose ok
                    }

                 else if(button != 4)
                    {
                      button = 0;
                    }
         }
       al_flip_display();
    }

    al_destroy_bitmap(chooseprops);
    al_destroy_bitmap(choosedice);
    al_destroy_bitmap(choosestay);
    al_destroy_event_queue(ev_que);
    //al_destroy_display(display);
    al_destroy_font(pongFont1);      /* destroy the font */
    return 0;

}
