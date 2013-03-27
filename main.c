// Benjamin Laws, CSE 21211-04
// Lab 10: Final Project

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "gfx.h"
#include "text.h"
#include "scores.h"

void show_title(int xsize,int ysize){
  int c1,c2,c3;
  c1 = 100+rand()%156;
  c2 = 100+rand()%156;
  c3 = 100+rand()%156;
  while(1){
    usleep(30000);
    gfx_color(c1,c2,c3);
    gfx_clear();
    typewriter("STARS",xsize/2-150,ysize/2-50,100,xsize);
    if(c1<255 && rand()%2) c1++;
    else if(c1>255) c1-=150;
    if(c2<255 && rand()%2) c2++;
    else if(c2>255) c2-=150;
    if(c3<255 && rand()%2) c2++;
    else if(c3>255) c3-=150;
    if(gfx_event_waiting()){
      if(gfx_wait()=='q') exit(0);
      break;
    }
    gfx_flush();
  }

  gfx_clear();
  gfx_color(255,255,255);
  typewriter("YOU ARE THE YELLOW STAR.\nCOLLECT BLUE STARS FOR EXTRA POINTS.\nAVOID OTHER STARS.\n\nCONTROLS:\nWASD: MOVE\nP: PAUSE\nQ: QUIT",150,130,40,xsize-175);
  gfx_line(140,425,365,425);
  if(gfx_wait()=='q') exit(0);
}

void addBlueStar(struct star bluestar[],int nblue,int xsize,int ysize){
  bluestar[nblue].x = rand()%xsize;
  bluestar[nblue].y = rand()%ysize;
  bluestar[nblue].r = 4;
  bluestar[nblue].vr = -rand()%4 - 5;
  bluestar[nblue].offset = (rand()%100)/50 * M_PI;
}

void addRedStar(struct star redstar[],int nred,int xsize,int ysize){
  if(rand()%2){
    redstar[nred].x = rand()%xsize;
    redstar[nred].y = rand()%40 - 20;
    if(redstar[nred].y > 0) redstar[nred].y+=ysize;
  } else{
    redstar[nred].x = rand()%40 - 20;
    redstar[nred].y = rand()%ysize;
    if(redstar[nred].x > 0) redstar[nred].x+=xsize;
  }
  redstar[nred].r = 10;
  redstar[nred].vx = redstar[nred].vy = 30 + rand()%71;
  redstar[nred].vr = redstar[nred].vx / 10;
  redstar[nred].offset = (rand()%100)/50 * M_PI;
}

void addOrangeStar(struct star orangestar[],int norange,int xsize,int ysize){
  if(rand()%2){
    orangestar[norange].x = rand()%xsize;
    orangestar[norange].y = rand()%40 - 20;
    if(orangestar[norange].y > 0) orangestar[norange].y+=ysize;
  } else{
    orangestar[norange].x = rand()%40 - 20;
    orangestar[norange].y = rand()%ysize;
    if(orangestar[norange].x > 0) orangestar[norange].x+=xsize;
  }
  orangestar[norange].r = 10;
  orangestar[norange].vr = 10+rand()%6;
  orangestar[norange].offset = (rand()%100)/50 * M_PI;
}

void drawFullStar(int x,int y,int r,double offset){
  double i,dtheta=4*M_PI/5;
  for(i=0;i<=4*M_PI;i+=dtheta) gfx_line(x+r*cos(i+offset),y+r*sin(i+offset),x+r*cos(i+offset+dtheta),y+r*sin(i+offset+dtheta));
}

void drawStickStar(int x,int y,int r,double offset){
  double i,dtheta=2*M_PI/5;
  for(i=0;i<2*M_PI;i+=dtheta) gfx_line(x,y,x+r*cos(i-offset),y+r*sin(i-offset));
}

void drawStars(struct star *player,struct star bluestar[],int nblue,struct star redstar[],int nred,struct star orangestar[],int norange){
  int k;
  for(k=0;k<nblue;k++){     // Draw blue stars
    if(rand()%10>8) gfx_color(255,255,255);  // make twinkle white
    else gfx_color(0,225,255);
    drawStickStar(bluestar[k].x,bluestar[k].y,bluestar[k].r,bluestar[k].offset);
  }

  gfx_color(255,255,0);  // Draw yellow star
  drawFullStar(player->x,player->y,player->r,player->offset);

  gfx_color(255,50,50);  // Draw red stars
  for(k=0;k<nred;k++) drawFullStar(redstar[k].x,redstar[k].y,redstar[k].r,redstar[k].offset);

  gfx_color(255,165,0);  // Draw orange stars
  for(k=0;k<norange;k++) drawFullStar(orangestar[k].x,orangestar[k].y,orangestar[k].r,orangestar[k].offset);
}

void moveStars(struct star *player,struct star bluestar[],int nblue,struct star redstar[],int nred,struct star orangestar[],int norange,int xsize,int ysize,int dv,double dt){
  int k;
  // Move player star
  player->offset += player->vr*dt;
  player->x += player->vx;
  player->y += player->vy;
  if((player->x)<5) (player->x)=5;  // keep player within screen
  if((player->x)>xsize-5) (player->x)=xsize-5;
  if((player->y)<5) (player->y)=5;
  if((player->y)>ysize-5) (player->y)=ysize-5;
  // Slow down player star
  if(player->vx > 0) (player->vx)-=.1;
  else if(player->vx < 0) (player->vx)+=.1;
  if(player->vy > 0) (player->vy)-=.1;
  else if(player->vy < 0) (player->vy)+=.1;
  if(fabs(player->vx)<.1) player->vx=0;
  if(fabs(player->vy)<.1) player->vy=0;

  // Spin blue stars
  for(k=0;k<nblue;k++) bluestar[k].offset+=bluestar[k].vr*dt;

  for(k=0;k<nred;k++){    // Move red stars
    if(redstar[k].x<(player->x)) redstar[k].x+=redstar[k].vx*dt;
    else redstar[k].x-=redstar[k].vx*dt;
    if(redstar[k].y<(player->y)) redstar[k].y+=redstar[k].vy*dt;
    else redstar[k].y-=redstar[k].vy*dt;
    redstar[k].offset+=redstar[k].vr*dt;
  }

  for(k=0;k<norange;k++){    // Move orange stars
    orangestar[k].offset += orangestar[k].vr*dt;
    orangestar[k].x += orangestar[k].vx;
    orangestar[k].y += orangestar[k].vy;
    // Slow down star
    if(orangestar[k].vx > 0) orangestar[k].vx-=.1;
    if(orangestar[k].vx < 0) orangestar[k].vx+=.1;
    if(orangestar[k].vy > 0) orangestar[k].vy-=.1;
    if(orangestar[k].vy < 0) orangestar[k].vy+=.1;
    // Speed up star
    if(fabs(orangestar[k].vx)<.2 && fabs(orangestar[k].vy)<.2 && rand()%50<1){
      if(orangestar[k].x < player->x-15) orangestar[k].vx=orangestar[k].vr/3;
      else if(orangestar[k].x > player->x+15) orangestar[k].vx=-orangestar[k].vr/3;
      if(orangestar[k].y < player->y-15) orangestar[k].vy=orangestar[k].vr/3;
      else if(orangestar[k].y > player->y+15) orangestar[k].vy=-orangestar[k].vr/3;
    }
  }
}

int checkCollisions(struct star *player,struct star bluestar[],int *nblue,struct star redstar[],int nred,struct star orangestar[],int norange,double *score){
  int k,j;
  for(k=0;k<*nblue;k++){  // Blue stars
    if(abs((player->x)-bluestar[k].x)<=10 && abs((player->y)-bluestar[k].y)<=10){
      for(j=k;j<*nblue;j++){   // remove blue star collided with; shift bluestar array
	bluestar[j].x=bluestar[j+1].x;
	bluestar[j].y=bluestar[j+1].y;
	bluestar[j].vr=bluestar[j+1].vr;
	bluestar[j].offset=bluestar[j+1].offset;
      }
      (*nblue)--;
      *score+=5000;
      if(player->vr < 30) (player->vr)++;
    }
  }

  for(k=0;k<nred;k++){   // Red stars
    if(abs((player->y)-redstar[k].y)<15 && abs((player->x)-redstar[k].x)<15) return 1;
  }
  for(k=0;k<norange;k++){   // Orange stars
    if(abs((player->y)-orangestar[k].y)<15 && abs((player->x)-orangestar[k].x)<15) return 1;
  }
  return 0;
}

int checkControls(struct star *player,int dv){
  char c;
  while(gfx_event_waiting()){
    c = gfx_wait();
    switch(c){
    case 'q': 
      return 1;
    case 'p':
      return 2;
    case 'd':
      if((player->vx)>=0) (player->vx)=dv;
      else (player->vx)=0;
      break;
    case 'a':
      if((player->vx)<=0) (player->vx)=-dv;
      else (player->vx)=0;
      break;
    case 's':
      if((player->vy)>=0) (player->vy)=dv;
      else (player->vy)=0;
      break;
    case 'w':
      if((player->vy)<=0) (player->vy)=-dv;
      else (player->vy)=0;
      break;
    }
  }
  return 0;
}

void pause_game(int xsize,int ysize){
  char c;
  gfx_color(255,255,255);
  typewriter("PAUSE",xsize/2-65,ysize/2-50,50,xsize);
  typewriter("P: RESUME\nQ: QUIT",xsize/2-62,ysize/2+30,25,xsize);
  while(1){
    c = gfx_wait();
    if(c=='p') break;
    if(c=='q') exit(0);
  }
}

void play(int xsize,int ysize){
  int k,dv=5,t=0,nblue=0,nred=0,norange=0;
  double dt=.01,score=0;
  struct star player={xsize/2,ysize/2,10,0,0,3,0};
  struct star bluestar[10],redstar[10],orangestar[10];

  addBlueStar(bluestar,nblue,xsize,ysize);
  nblue++;

  while(1){
    gfx_clear();
    disp_score((int)score,xsize);

    // Change star position and rotations
    moveStars(&player,bluestar,nblue,redstar,nred,orangestar,norange,xsize,ysize,dv,dt);

    drawStars(&player,bluestar,nblue,redstar,nred,orangestar,norange);
    gfx_flush();

    if(checkCollisions(&player,bluestar,&nblue,redstar,nred,orangestar,norange,&score)){
      usleep(1000000);
      highscores((int)score,xsize,ysize,player,bluestar,nblue,redstar,nred,orangestar,norange);
      return;
    }

    k = checkControls(&player,dv);
    if(k==1){
      usleep(1000000);
      highscores((int)score,xsize,ysize,player,bluestar,nblue,redstar,nred,orangestar,norange);
      return;
    } else if(k==2){
      pause_game(xsize,ysize);
      gfx_clear();
      disp_score((int)score,xsize);
      drawStars(&player,bluestar,nblue,redstar,nred,orangestar,norange);
      gfx_flush();
    }

    // Pause, increment score, add stars
    usleep(dt*1000000);
    if(score<999999999) score+=(1+nred+norange)/10.0;
    if(nblue==0 || (nblue<10 && rand()%500<1)){
      addBlueStar(bluestar,nblue,xsize,ysize);
      nblue++;
    }
    if(nred<10 && rand()%2500<1){
      addRedStar(redstar,nred,xsize,ysize);
      nred++;
    }
    if(norange<10 && rand()%3000<1){
      addOrangeStar(orangestar,norange,xsize,ysize);
      norange++;
    }
  }
}

int main(void){
  int xsize=1000,ysize=700;
  char c;
  gfx_open(xsize,ysize,"Stars");
  srand(time(NULL));

  show_title(xsize,ysize);
  play(xsize,ysize);

  while(1){   // Wait on highscore menu for end or replay
    c = gfx_wait();
    if(c=='q') return 0;
    if(c=='r') play(xsize,ysize);
  }
}
