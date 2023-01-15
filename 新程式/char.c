#include "the_final_report.h"

void Chartr(MOUSE* st,ALLEGRO_SAMPLE* boing)
{
    int pos_x = 0;
    int pos_y = 0;
    int done = 1;
    int buttons[CHARACTER] = {0,0,0,0,0,0,0,0,0} ;
    st->click_num = 0;

    ALLEGRO_DISPLAY* display = NULL ;
    ALLEGRO_BITMAP* menu_char = NULL;
    ALLEGRO_BITMAP* pic1 = NULL;
    ALLEGRO_BITMAP* pic2 = NULL;
    ALLEGRO_BITMAP* pic3 = NULL;
    ALLEGRO_BITMAP* pic4 = NULL;
    ALLEGRO_BITMAP* pic5 = NULL;
    ALLEGRO_BITMAP* pic6 = NULL;
    ALLEGRO_BITMAP* pic7 = NULL;
    ALLEGRO_BITMAP* pic8 = NULL;
    ALLEGRO_EVENT_QUEUE* ev_que = NULL;

    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    ev_que = al_create_event_queue();

    display = al_create_display(SCREEN_W, SCREEN_H);
    menu_char = al_load_bitmap("main_char.jpg");
    pic1 = al_load_bitmap("pic1.jpg");
    pic2 = al_load_bitmap("pic2.jpg");
    pic3 = al_load_bitmap("pic3.jpg");
    pic4 = al_load_bitmap("pic4.jpg");
    pic5 = al_load_bitmap("pic5.jpg");
    pic6 = al_load_bitmap("pic6.jpg");
    pic7 = al_load_bitmap("pic7.jpg");
    pic8 = al_load_bitmap("pic8.jpg");

    al_register_event_source(ev_que,al_get_display_event_source(display));
    al_register_event_source(ev_que, al_get_mouse_event_source());
    al_draw_bitmap(menu_char,0,0,0);

    while(done == 1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(ev_que, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
        {
            done = 0;
        }

        if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
         {
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;

                 if((pos_x>=138)&&(pos_x<=351)&&(pos_y>=215)&&(pos_y<=437) && ev.mouse.button & 1 && st->click_num < st->character_num) //1
                    {
                       if(buttons[1]==0)
                       {
                         al_draw_bitmap(pic1,80,180,0);
                         st->character[st->click_num] = 1;
                         st->click_num++;
                         st->num_x = 290;
                         st->num_y = 185;
                         Draw_number(st);
                         buttons[1] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=427)&&(pos_x<=542)&&(pos_y>=208)&&(pos_y<=436)&&ev.mouse.button & 1 && st->click_num < st->character_num) //2
                    {
                       if(buttons[2]==0)
                       {
                         al_draw_bitmap(pic2,340,168,0);
                         st->character[st->click_num] = 2;
                         st->click_num++;
                         st->num_x = 574;
                         st->num_y = 185;
                         Draw_number(st);
                         buttons[2] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=675)&&(pos_x<=808)&&(pos_y>=267)&&(pos_y<=418)&&ev.mouse.button & 1 && st->click_num < st->character_num) //3
                    {
                       if(buttons[3]==0)
                       {
                         al_draw_bitmap(pic3,650,180,0);
                         st->character[st->click_num] = 3;
                         st->click_num++;
                         st->num_x = 855;
                         st->num_y = 185;
                         Draw_number(st);
                         buttons[3] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=932)&&(pos_x<=1101)&&(pos_y>=198)&&(pos_y<=430)&&ev.mouse.button & 1 && st->click_num < st->character_num) //4
                    {
                       if(buttons[4]==0)
                       {
                         al_draw_bitmap(pic4,910,160,0);
                         st->character[st->click_num] = 4;
                         st->click_num++;
                         st->num_x = 1120;
                         st->num_y = 185;
                         Draw_number(st);
                         buttons[4] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=137)&&(pos_x<=288)&&(pos_y>=578)&&(pos_y<=785)&&ev.mouse.button & 1 && st->click_num < st->character_num) //5
                    {
                       if(buttons[5]==0)
                       {
                         al_draw_bitmap(pic5,80,550,0);
                         st->character[st->click_num] = 5;
                         st->click_num++;
                         st->num_x = 290;
                         st->num_y = 560;
                         Draw_number(st);
                         buttons[5] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=403)&&(pos_x<=544)&&(pos_y>=594)&&(pos_y<=785)&&ev.mouse.button & 1 && st->click_num < st->character_num) //6
                    {
                       if(buttons[6]==0)
                       {
                         al_draw_bitmap(pic6,340,550,0);
                         st->character[st->click_num] = 6;
                         st->click_num++;
                         st->num_x = 570;
                         st->num_y = 560;
                         Draw_number(st);
                         buttons[6] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=686)&&(pos_x<=820)&&(pos_y>=546)&&(pos_y<=785)&&ev.mouse.button & 1 && st->click_num < st->character_num) //7
                    {
                       if(buttons[7]==0)
                       {
                         al_draw_bitmap(pic7,650,530,0);
                         st->character[st->click_num] = 7;
                         st->click_num++;
                         st->num_x = 830;
                         st->num_y = 560;
                         Draw_number(st);
                         buttons[7] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=936)&&(pos_x<=1106)&&(pos_y>=592)&&(pos_y<=788)&&ev.mouse.button & 1 && st->click_num < st->character_num) //8
                    {
                       if(buttons[8]==0)
                       {
                         al_draw_bitmap(pic8,880,560,0);
                         st->character[st->click_num] = 8;
                         st->click_num++;
                         st->num_x = 1100;
                         st->num_y = 560;
                         Draw_number(st);
                         buttons[8] = 1;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                       }
                    }
                 else if((pos_x>=1028)&&(pos_x<=1188)&&(pos_y>=934)&&(pos_y<=990)&&ev.mouse.button & 1 && st->character_num == st->click_num) //done
                    {
                         done = 0;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                    }

              }

        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_event_queue(ev_que);

    return 0;

}




