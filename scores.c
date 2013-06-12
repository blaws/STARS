// Blaws, CSE 21211-04
// Lab 10: Final Project

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include "gfx.h"
#include "scores.h"

void disp_score(int score,int xsize){
  char score_str[11];
  sprintf(score_str,"%d",score);
  gfx_color(255,255,255);
  typewriter(score_str,xsize-15*strlen(score_str)-10,10,25,xsize);
}

void disp_highscores(struct highscore records[],int nscores,int nplayer,int xsize,int ysize){
  int k,x=xsize/2,y=225;
  char str[22];
  gfx_color(255,255,100);
  typewriter("R: RESTART",xsize/2-300,225,25,xsize);
  typewriter("Q: QUIT",xsize/2-300,265,25,xsize);
  gfx_color(250,100,250);
  typewriter("HIGHSCORES:",xsize/2,150,50,xsize);
  gfx_line(xsize/2-10,210,xsize/2+320,210);
  for(k=0;k<nscores;k++){
    gfx_color(250,100,250);
    if(k==nplayer) gfx_color(255,255,255);
    sprintf(str,"%10d  %s",records[k].score,records[k].name);
    typewriter(str,x,y,25,xsize);
    y+=40;
  }
}

void save_highscores(struct highscore records[],int nscores){
  int k;
  FILE *fp = fopen("stars_scores.txt","w");
  if(fp==NULL){
    fprintf(stderr,"Error: %s",strerror(errno));
    return;
  }
  for(k=0;k<nscores;k++) fprintf(fp,"%d %s\n",records[k].score,records[k].name);
  fclose(fp);
  return;
}

int get_name(int score,struct highscore records[],int nscores,int xsize,struct star player,struct star bluestar[],int nblue,struct star redstar[],int nred,struct star orangestar[],int norange){
  int k=0,j;
  char name[11]={0};
  while(gfx_event_waiting()) gfx_wait();
  while(k<10){      // get name from player
    gfx_clear();    // clear and redraw to allow underscores to disappear
    drawStars(&player,bluestar,nblue,redstar,nred,orangestar,norange);
    gfx_color(255,255,255);
    typewriter(name,350,100,25,xsize);

    gfx_color(100,150,255);
    typewriter("ENTER YOUR NAME:",100,100,25,xsize);
    gfx_color(255,255,255);
    for(j=k;j<10;j++) gfx_line(350+15*j,125,362+15*j,125);  // underline empty spaces
    name[k] = gfx_wait();  // get character input
    if(name[k]=='\n' || name[k]=='\r') break;  // end if 'return'
    if(!isalnum(name[k])) continue;        // ignore spaces, punctuation, etc.
    k++;
  }
  name[k] = 0;

  for(k=0;k<nscores;k++){    // put new score into correct place in list
    if(score>(records[k].score)) break;
  }
  for(j=nscores;j>k;j--){
    if(j<10){
      records[j].score = records[j-1].score;
      strcpy(records[j].name,records[j-1].name);
    }
  }
  records[k].score = score;
  strcpy(records[k].name,name);
  return k;
}

void highscores(int score,int xsize,int ysize,struct star player,struct star bluestar[],int nblue,struct star redstar[],int nred,struct star orangestar[],int norange){
  struct highscore records[10];
  char str[25];
  int k=0,nplayer=-1;
  FILE *fp = fopen("stars_scores.txt","r");
  if(fp==NULL){
    nplayer = get_name(score,records,k,xsize,player,bluestar,nblue,redstar,nred,orangestar,norange);
    k++;
    save_highscores(records,k);
    disp_highscores(records,k,0,xsize,ysize);
    return;
  }
  while(fgets(str,25,fp)){
    sscanf(str,"%d %s",&records[k].score,records[k].name);
    k++;
  }
  fclose(fp);
  if(score>records[k-1].score || k<10){
    nplayer = get_name(score,records,k,xsize,player,bluestar,nblue,redstar,nred,orangestar,norange);
    if(k<10) k++;
    save_highscores(records,k);
  }
  gfx_clear();
  drawStars(&player,bluestar,nblue,redstar,nred,orangestar,norange);
  disp_score(score,xsize);
  disp_highscores(records,k,nplayer,xsize,ysize);
}
