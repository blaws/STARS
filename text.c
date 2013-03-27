// Benjamin Laws, CSE 21211-04
// Lab 10: Final Project

#include <math.h>
#include <ctype.h>
#include <string.h>
#include "gfx.h"
#include "text.h"

void draw_arc(int cx,int cy,int rx,int ry,double s,double t){
  double i;
  for(i=s;i<=t;i+=.01)
    gfx_line(cx+rx*cos(i),cy-ry*sin(i),cx+rx*cos(i+.01),cy-ry*sin(i+.01));
}

void draw_0(int a,int b,int h){
  draw_arc(a+h/4,b+h/2,h/4,h/2,0,2*M_PI);
}
void draw_1(int a,int b,int h){
  gfx_line(a,b+h/4,a+h/4,b);
  gfx_line(a+h/4,b,a+h/4,b+h);
  gfx_line(a,b+h,a+h/2,b+h);
}
void draw_2(int a,int b,int h){
  draw_arc(a+h/4,b+h/4,h/4,h/4,0,M_PI);
  gfx_line(a+h/2,b+h/4,a,b+h);
  gfx_line(a,b+h,a+h/2,b+h);
}
void draw_3(int a,int b,int h){
  draw_arc(a,b+h/4,h/3,h/4,-M_PI/2,M_PI/2);
  draw_arc(a,b+3*h/4,h/3,h/4,-M_PI/2,M_PI/2);
}
void draw_4(int a,int b,int h){
  gfx_line(a+3*h/8,b+h,a+3*h/8,b);
  gfx_line(a+3*h/8,b,a,b+h/2);
  gfx_line(a,b+h/2,a+h/2,b+h/2);
}
void draw_5(int a,int b,int h){
  gfx_line(a+h/2,b,a,b);
  gfx_line(a,b,a,b+2*h/5);
  draw_arc(a,b+7*h/10,h/2,3*h/10,-M_PI/2,M_PI/2);
}
void draw_6(int a,int b,int h){
  draw_arc(a+h/4,b+h/2,h/4,h/2,M_PI/3,3*M_PI/2);
  draw_arc(a+h/4,b+3*h/4,h/5,h/4,0,2*M_PI);
}
void draw_7(int a,int b,int h){
  gfx_line(a,b,a+h/2,b);
  gfx_line(a+h/2,b,a,b+h);
}
void draw_8(int a,int b,int h){
  draw_arc(a+h/4,b+h/4,h/4,h/4,0,2*M_PI);
  draw_arc(a+h/4,b+3*h/4,h/4,h/4,0,2*M_PI);
}
void draw_9(int a,int b,int h){
  draw_arc(a+h/4,b+h/4,h/5,h/4,0,2*M_PI);
  draw_arc(a+h/4,b+h/2,h/4,h/2,-2*M_PI/3,M_PI/2);
}
void draw_a(int a,int b,int h){
  gfx_line(a,b+h,a+h/4,b);
  gfx_line(a+h/4,b,a+h/2,b+h);
  gfx_line(a+h/8,b+h/2,a+3*h/8,b+h/2);
}
void draw_b(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  draw_arc(a,b+h/4,h/3,h/4,-M_PI/2,M_PI/2);
  draw_arc(a,b+3*h/4,h/3,h/4,-M_PI/2,M_PI/2);
}
void draw_c(int a,int b,int h){
  draw_arc(a+h/4,b+h/2,h/4,h/2,M_PI/3,5*M_PI/3);
}
void draw_d(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  draw_arc(a,b+h/2,h/3,h/2,-M_PI/2,M_PI/2);
}
void draw_e(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  gfx_line(a,b,a+h/2,b);
  gfx_line(a,b+h/2,a+h/4,b+h/2);
  gfx_line(a,b+h,a+h/2,b+h);
}
void draw_f(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  gfx_line(a,b,a+h/2,b);
  gfx_line(a,b+h/2,a+h/4,b+h/2);
}
void draw_g(int a,int b,int h){
  draw_arc(a+h/4,b+h/2,h/4,h/2,M_PI/3,2*M_PI);
  gfx_line(a+h/4,b+h/2,a+h/2,b+h/2);
}
void draw_h(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  gfx_line(a+h/2,b,a+h/2,b+h);
  gfx_line(a,b+h/2,a+h/2,b+h/2);
}
void draw_i(int a,int b,int h){
  gfx_line(a,b,a+h/2,b);
  gfx_line(a+h/4,b,a+h/4,b+h);
  gfx_line(a,b+h,a+h/2,b+h);
}
void draw_j(int a,int b,int h){
  gfx_line(a+h/2,b,a+h/2,b+3*h/4);
  draw_arc(a+h/4,b+3*h/4,h/4,h/4,M_PI,2*M_PI);
}
void draw_k(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  gfx_line(a+h/2,b,a,b+h/2);
  gfx_line(a,b+h/2,a+h/2,b+h);
}
void draw_l(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  gfx_line(a,b+h,a+h/2,b+h);
}
void draw_m(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  gfx_line(a,b,a+h/4,b+h/2);
  gfx_line(a+h/4,b+h/2,a+h/2,b);
  gfx_line(a+h/2,b,a+h/2,b+h);
}
void draw_n(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  gfx_line(a,b,a+h/2,b+h);
  gfx_line(a+h/2,b,a+h/2,b+h);
}
void draw_o(int a,int b,int h){
  draw_arc(a+h/4,b+h/2,h/4,h/2,0,2*M_PI);
}
void draw_p(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  draw_arc(a,b+h/4,h/2,h/4,-M_PI/2,M_PI/2);
}
void draw_q(int a,int b,int h){
  draw_arc(a+h/4,b+h/2,h/4,h/2,0,2*M_PI);
  gfx_line(a+h/4,b+3*h/4,a+h/2,b+h);
}
void draw_r(int a,int b,int h){
  gfx_line(a,b,a,b+h);
  draw_arc(a,b+h/4,h/2,h/4,-M_PI/2,M_PI/2);
  gfx_line(a,b+h/2,a+h/2,b+h);
}
void draw_s(int a,int b,int h){
  draw_arc(a+h/4,b+h/4+1,h/4,h/4,0,3*M_PI/2);
  draw_arc(a+h/4,b+3*h/4,h/4,h/4,-M_PI,M_PI/2);
}
void draw_t(int a,int b,int h){
  gfx_line(a,b,a+h/2,b);
  gfx_line(a+h/4,b,a+h/4,b+h);
}
void draw_u(int a,int b,int h){
  gfx_line(a,b,a,b+3*h/4);
  draw_arc(a+h/4,b+3*h/4,h/4,h/4,M_PI,2*M_PI);
  gfx_line(a+h/2,b,a+h/2,b+3*h/4);
}
void draw_v(int a,int b,int h){
  gfx_line(a,b,a+h/4,b+h);
  gfx_line(a+h/4,b+h,a+h/2,b);
}
void draw_w(int a,int b,int h){
  gfx_line(a,b,a+h/8,b+h);
  gfx_line(a+h/8,b+h,a+h/4,b);
  gfx_line(a+h/4,b,a+3*h/8,b+h);
  gfx_line(a+3*h/8,b+h,a+h/2,b);
}
void draw_x(int a,int b,int h){
  gfx_line(a,b,a+h/2,b+h);
  gfx_line(a+h/2,b,a,b+h);
}
void draw_y(int a,int b,int h){
  gfx_line(a,b,a+h/4,b+h/2);
  gfx_line(a+h/4,b+h/2,a+h/2,b);
  gfx_line(a+h/4,b+h/2,a+h/4,b+h);
}
void draw_z(int a,int b,int h){
  gfx_line(a,b,a+h/2,b);
  gfx_line(a+h/2,b,a,b+h);
  gfx_line(a,b+h,a+h/2,b+h);
}
void draw_period(int a,int b,int h){
  draw_arc(a+h/4,b+15*h/16,h/16,h/16,0,2*M_PI);
}
void draw_colon(int a,int b,int h){
  draw_arc(a+h/4,b+h/4,h/16,h/16,0,2*M_PI);
  draw_arc(a+h/4,b+3*h/4,h/16,h/16,0,2*M_PI);
}
void draw_exclamation(int a,int b,int h){
  gfx_line(a+h/4,b,a+h/4,b+3*h/4);
  draw_arc(a+h/4,b+15*h/16,h/16,h/16,0,2*M_PI);
}


void draw_letter(int a,int b,char n,int h){
  switch(n){
  case '0':
    draw_0(a,b,h);
    break;
  case '1':
    draw_1(a,b,h);
    break;
  case '2':
    draw_2(a,b,h);
    break;
  case '3':
    draw_3(a,b,h);
    break;
  case '4':
    draw_4(a,b,h);
    break;
  case '5':
    draw_5(a,b,h);
    break;
  case '6':
    draw_6(a,b,h);
    break;
  case '7':
    draw_7(a,b,h);
    break;
  case '8':
    draw_8(a,b,h);
    break;
  case '9':
    draw_9(a,b,h);
    break;
  case 'a':
    draw_a(a,b,h);
    break;
  case 'b':
    draw_b(a,b,h);
    break;
  case 'c':
    draw_c(a,b,h);
    break;
  case 'd':
    draw_d(a,b,h);
    break;
  case 'e':
    draw_e(a,b,h);
    break;
  case 'f':
    draw_f(a,b,h);
    break;
  case 'g':
    draw_g(a,b,h);
    break;
  case 'h':
    draw_h(a,b,h);
    break;
  case 'i':
    draw_i(a,b,h);
    break;
  case 'j':
    draw_j(a,b,h);
    break;
  case 'k':
    draw_k(a,b,h);
    break;
  case 'l':
    draw_l(a,b,h);
    break;
  case 'm':
    draw_m(a,b,h);
    break;
  case 'n':
    draw_n(a,b,h);
    break;
  case 'o':
    draw_o(a,b,h);
    break;
  case 'p':
    draw_p(a,b,h);
    break;
  case 'q':
    draw_q(a,b,h);
    break;
  case 'r':
    draw_r(a,b,h);
    break;
  case 's':
    draw_s(a,b,h);
    break;
  case 't':
    draw_t(a,b,h);
    break;
  case 'u':
    draw_u(a,b,h);
    break;
  case 'v':
    draw_v(a,b,h);
    break;
  case 'w':
    draw_w(a,b,h);
    break;
  case 'x':
    draw_x(a,b,h);
    break;
  case 'y':
    draw_y(a,b,h);
    break;
  case 'z':
    draw_z(a,b,h);
    break;
  case '.':
    draw_period(a,b,h);
    break;
  case ':':
    draw_colon(a,b,h);
    break;
  case '!':
    draw_exclamation(a,b,h);
    break;
  }
}



int typewriter(char *str,int xi,int y,int height,int xlimit){
  int i,x=xi;
  char c;

  for(i=0;i<strlen(str);i++){
    c = tolower(str[i]);
    switch(c){
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case '.':
    case ':':
    case '!':
      draw_letter(x,y,c,height);
      break;
    case ' ':
      break;
    case '\t':
      x+=12*height/5;
      break;
    case '\r':
    case '\n':
      x=xi-3*height/5;
      y+=1.25*height;
      break;
    default:
      x-=3*height/5;
    }

    x+=3*height/5;
    if(x>=xlimit-9*height/5 && (c==' '||c=='\t'||c=='\n'||c=='\r')){
      x=xi;
      y+=1.25*height;
    }
  }
}
