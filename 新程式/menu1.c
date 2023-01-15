#include "the_final_report.h"

void Menu(MOUSE* st,ALLEGRO_SAMPLE* boing)
{
    int pos_x = 0;
    int pos_y = 0;
    int done = 1;
    int button = 0;
    int back = 0;

    ALLEGRO_DISPLAY* display = NULL ;
    ALLEGRO_BITMAP* menu = NULL;
    ALLEGRO_BITMAP* menuhelp = NULL;
    ALLEGRO_BITMAP* menusetting = NULL;
    ALLEGRO_BITMAP* menustart = NULL;
    ALLEGRO_EVENT_QUEUE* ev_que = NULL;
    ALLEGRO_BITMAP* howtousebackground = NULL;

    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    ev_que = al_create_event_queue();

    display = al_create_display(SCREEN_W, SCREEN_H);
    menu = al_load_bitmap("menu.jpg");
    menuhelp = al_load_bitmap("help.jpg");
    menusetting = al_load_bitmap("exit.jpg");
    menustart = al_load_bitmap("start.jpg");
    howtousebackground = al_load_bitmap("howtousebackground.jpg");

    al_register_event_source(ev_que,al_get_display_event_source(display));
    al_register_event_source(ev_que, al_get_mouse_event_source());

    al_draw_bitmap(menu,0,0,0);
    while(done == 1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(ev_que, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
            done = 0;
        if(button == 0)
            al_draw_bitmap(menu,0,0,0);
        if(button == 1)
            al_draw_bitmap(menustart,0,0,0);
        if(button == 2)
            al_draw_bitmap(menuhelp,0,0,0);
        if(button == 3)
            al_draw_bitmap(menusetting,0,0,0);

        if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
         {
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;

                 if((pos_x>=436)&&(pos_x<=755)&&(pos_y>=371)&&(pos_y<=486))
                    {
                        button = 1;
                    if(ev.mouse.button & 1)
                      {
                        done = 0;
                        al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                      }
                    }
                 else if((pos_x>=429)&&(pos_x<=764)&&(pos_y>=546)&&(pos_y<=658))
                    {
                        button = 2;
                     if(ev.mouse.button & 1)
                       {
                            al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                            al_draw_bitmap(howtousebackground,0,0,0);
                            How_to_use();
                            while(back == 0){
                                al_wait_for_event(ev_que, &ev);
                                if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ){
                                    pos_x = ev.mouse.x;
                                    pos_y = ev.mouse.y;
                                    if((pos_x>=922)&&(pos_x<=1162)&&(pos_y>=783)&&(pos_y<=875)&&(ev.mouse.button & 1)){
                                        back = 1;
                                        al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                                        done = 0;

                                    }
                                }
                                al_rest(REST);
                                al_flip_display();
                            }
                       }
                    }
                 else if((pos_x>=429)&&(pos_x<=764)&&(pos_y>=706)&&(pos_y<=822))
                    {
                        button = 3;
                      if(ev.mouse.button & 1)
                        {
                            al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                            exit(0);
                        }
                    }
                 else
                    {
                        button = 0;
                    }
              }

        al_flip_display();
    }

    al_destroy_bitmap(menu);
    al_destroy_bitmap(menustart);
    al_destroy_bitmap(menusetting);
    al_destroy_bitmap(menuhelp);
    al_destroy_display(display);
    al_destroy_event_queue(ev_que);
    al_destroy_bitmap(howtousebackground);
    return 0;

}
