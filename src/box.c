#include "box.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Box* createBox(){
  struct Box *this=(struct Box*)malloc(sizeof(struct Box));
  //this->p=(struct Particle*)malloc(nb_init_particles*sizeof(struct Particle));
  //this->nb_particles=nb_init_particles;
  return this;
}

void setBodParticles(struct Box* box, struct Particle* parts, int nb_particles){
  assert(box!=NULL && "box parameter is NULL");
  assert(parts!=NULL && "particles array parameter is NULL");
  box->p=(struct Particle*)malloc(nb_particles*sizeof(struct Particle));
  box->nb_particles=nb_particles;
  for(;;);
  return;
}
