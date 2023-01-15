#include "the_final_report.h"
void Draw_number(MOUSE* st)
{
    ALLEGRO_BITMAP* num1 = NULL;
    ALLEGRO_BITMAP* num2 = NULL;
    ALLEGRO_BITMAP* num3 = NULL;
    ALLEGRO_BITMAP* num4 = NULL;

    num1 = al_load_bitmap("1.jpg");
    num2 = al_load_bitmap("2.jpg");
    num3 = al_load_bitmap("3.jpg");
    num4 = al_load_bitmap("4.jpg");

    switch(st->click_num)
    {
       case 1 :
       al_draw_bitmap(num1,st->num_x,st->num_y,0);
       break;
       case 2 :
       al_draw_bitmap(num2,st->num_x,st->num_y,0);
       break;
       case 3 :
       al_draw_bitmap(num3,st->num_x,st->num_y,0);
       break;
       case 4 :
       al_draw_bitmap(num4,st->num_x,st->num_y,0);
       break;
    }

}


void Choose_number(MOUSE* st,ALLEGRO_SAMPLE* boing)
{
    int done = 1;
    int button = 0;
    int pos_x = 0;
    int pos_y = 0;

    ALLEGRO_DISPLAY* display = NULL ;
    ALLEGRO_BITMAP* choosenumber = NULL;
    ALLEGRO_BITMAP* choosenumber1 = NULL;
    ALLEGRO_BITMAP* choosenumber2 = NULL;
    ALLEGRO_BITMAP* choosenumber3 = NULL;
    ALLEGRO_EVENT_QUEUE* ev_que = NULL;
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    ev_que = al_create_event_queue();
    display = al_create_display(SCREEN_W, SCREEN_H);
    choosenumber = al_load_bitmap("choosenumber.jpg");
    choosenumber1 = al_load_bitmap("choosenumber1.jpg");
    choosenumber2 = al_load_bitmap("choosenumber2.jpg");
    choosenumber3 = al_load_bitmap("choosenumber3.jpg");
    al_register_event_source(ev_que,al_get_display_event_source(display));
    al_register_event_source(ev_que, al_get_mouse_event_source());
    al_draw_bitmap(choosenumber,0,0,0);

     while(done == 1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(ev_que, &ev);

        if(button == 0)
            al_draw_bitmap(choosenumber,0,0,0);
        if(button == 1)
            al_draw_bitmap(choosenumber1,0,0,0);
        if(button == 2)
            al_draw_bitmap(choosenumber2,0,0,0);
        if(button == 3)
            al_draw_bitmap(choosenumber3,0,0,0);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
        {
            done = 0;
        }

        if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
         {
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;

                 if((pos_x>=105)&&(pos_x<=398)&&(pos_y>=363)&&(pos_y<=644) && button != 4) //2
                    {
                      button = 1;
                      if(ev.mouse.button & 1)
                      {
                         st->character_num = 2;
                         button = 4;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                      }
                    }
                 else if((pos_x>=446)&&(pos_x<=737)&&(pos_y>=363)&&(pos_y<=644) && button != 4)  //3
                    {
                      button = 2;
                      if(ev.mouse.button & 1)
                      {
                         st->character_num = 3;
                         button = 4;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                      }
                    }
                 else if((pos_x>=782)&&(pos_x<=1067)&&(pos_y>=363)&&(pos_y<=644) && button != 4) //4
                    {
                      button = 3;
                      if(ev.mouse.button & 1)
                      {
                         st->character_num = 4;
                         button = 4;
                         al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                      }
                    }
                 else if((pos_x>=1028)&&(pos_x<=1128)&&(pos_y>=934)&&(pos_y<=990) && ev.mouse.button & 1) //done
                    {
                        done = 0;
                        al_play_sample(boing, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE,NULL); /* play "boing" sound once */
                    }
                 else if(button != 4)
                    {
                      button = 0;
                    }
         }
        al_flip_display();
    }
    al_destroy_bitmap(choosenumber);
    al_destroy_bitmap(choosenumber1);
    al_destroy_bitmap(choosenumber2);
    al_destroy_bitmap(choosenumber3);
    al_destroy_event_queue(ev_que);
    al_destroy_display(display);
    return 0;
}
