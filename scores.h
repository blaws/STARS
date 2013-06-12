// Blaws, CSE 21221-04
// Lab 10: Final Project

struct highscore{
  int score;
  char name[11];
};

struct star{
  double x;
  double y;
  int r;
  double vx;
  double vy;
  int vr;
  double offset;
};

void disp_score(int score,int xsize);

void disp_highscores(struct highscore records[],int nscores,int nplayer,int xsize,int ysize);

int get_name(int score,struct highscore records[],int nscores,int xsize,struct star player,struct star bluestar[],int nblue,struct star redstar[],int nred,struct star orangestar[],int norange);

void highscores(int score,int xsize,int ysize,struct star player,struct star bluestar[],int nblue,struct star redstar[],int nred,struct star orangestar[],int norange);
