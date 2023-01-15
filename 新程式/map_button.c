#include "the_final_report.h"
void Map_button(PLAYER *player_array,int* people,int* i,ALLEGRO_BITMAP *map)
{
            int done = 1;
            int button = 1;
            int button2 = 1;
            int pos_x = 0;
            int pos_y = 0;
            ALLEGRO_EVENT_QUEUE* ev_que = NULL;
            //ALLEGRO_DISPLAY* display = NULL ;
            //ALLEGRO_BITMAP* map = NULL ;
            al_init();             /* initialize Allegro */
            al_init_image_addon();
            al_init_acodec_addon();

            al_install_mouse();

            //map = al_load_bitmap("map.jpg");
            //display = al_create_display(SCREEN_W, SCREEN_H);
            ev_que = al_create_event_queue();
            //al_register_event_source(ev_que,al_get_display_event_source(display));
            al_register_event_source(ev_que, al_get_mouse_event_source());
            Draw(player_array,people,map);
            while(done == 1){

                ALLEGRO_EVENT ev;
                al_wait_for_event(ev_que, &ev);
                Draw(player_array,people,map);
                if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
                {
                    done = 0;
                }
                if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
                {
                    pos_x = ev.mouse.x;
                    pos_y = ev.mouse.y;

                    if((pos_x>=390)&&(pos_x<=554)&&(pos_y>=610)&&(pos_y<=708)&& (ev.mouse.button &1) && (button ==1)){
                        Choose_propnumber(player_array,i);
                        Draw(player_array,people,map);
                        button = 0;
                    }
                    if((pos_x>=648)&&(pos_x<=814)&&(pos_y>=610)&&(pos_y<=708)&& (ev.mouse.button &1) && (button2 == 1)){
                        Show_Dice(player_array[*i].dice);
                        Draw(player_array,people,map);
                        button2 = 0;

                    }
                    if(button == 0 && button2 ==0 )
                     {
                       done = 0;
                     }


                }
            }
            al_destroy_event_queue(ev_que);
            //al_destroy_display(display);






}
