#ifndef __BOX_H__
#define __BOX_H__
#include "driver.h"
struct Box{
  struct Particle* p;
  struct Particle bary;
  int nb_particles;
};

struct QuadTreeBox{
  struct Box **box;
  int nb_box_son;
  struct TreeBox **subBoxes;
  int nb_treebox_son;
  struct Particle bary;
};

struct Box* createBox();

void setBoxParticles(/*OUT*/struct Box*,/*IN*/struct Particle *,/*IN*/ int);

void processBarycentre(struct Box*);

void freeBox();


#endif // __BOX_H__
