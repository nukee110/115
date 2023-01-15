#ifndef THE_FINAL_REPORT_H_INCLUDED
#define THE_FINAL_REPORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


#define WIDTH 1200
#define HEIGHT 1000
#define SCREEN_W 1200
#define SCREEN_H 1000
#define CHARACTER 9
#define SQUARE 100
#define STARTMONEY 1000
#define SIZE 50
#define REST 0.005
#define STOP 50
#define DICESIZE 6
#define YPOSATIVE 1
#define XPOSATIVE 2
#define YNEGATIVE 3
#define XNEGATIVE 4
#define RANK_X 1050
#define RANK_Y 350


typedef struct player{
    int id;
    int location_x;
    int location_y;
    int direction;
    int money;
    int dice;
    int position;
    int tool_free;
    int tool_stay;
    int tool_dice;
    int picture_number;
    int jail_period;
    int personal_rank;
    char life;    //'T' or 'F'
    ALLEGRO_BITMAP* picture;
    ALLEGRO_BITMAP* picture_head;
}PLAYER;

typedef struct the_map{
    int x_house;
    int y_house;
    int type;
    int owner;
    int level;
}MAP;

typedef struct mouse{
  int character_num;
  int click_num;
  int num_x ;
  int num_y ;
  int character[4];
}MOUSE;

void Menu(MOUSE*,ALLEGRO_SAMPLE*);
void How_to_use(void);
void Chartr(MOUSE*,ALLEGRO_SAMPLE*);
void Draw_number(MOUSE*);
void Choose_number(MOUSE*,ALLEGRO_SAMPLE*);
void Start(PLAYER *,MOUSE *,int);
void Show_Dice(int);
void Round(PLAYER *,MAP [],int,ALLEGRO_BITMAP *);
void Map_button(PLAYER *,int *,int *,ALLEGRO_BITMAP *);
void Game(PLAYER *,MAP [],int);
void Rank(PLAYER *,int*);
void Choose_propnumber(PLAYER *,int *);
void Draw(PLAYER *,int*,ALLEGRO_BITMAP *);
void Dice(PLAYER *,int);
void Move(PLAYER *,int);
void IF_BUY_LAND (PLAYER *,MAP [],int*,int*);
void IF_BUILD_HOUSE_ONE (PLAYER *, MAP [],int*,int*);
void IF_BUILD_HOUSE_TWO (PLAYER *, MAP [],int*,int*);
void OTHER_LAND (PLAYER *, MAP[],int*,int*);
void OTHER_HOUSE_ONE (PLAYER *, MAP[],int*,int*);
void OTHER_HOUSE_TWO (PLAYER *, MAP[],int*,int*);
void GET_CHANCE (PLAYER *,int*);
void GET_PROPS (PLAYER *,int*);
void Map_Start(PLAYER *,MAP []);


#endif
