#include "driver.h"
#include <math.h>
#include <stdio.h>

float norm(float a, float b){
  return (a*a + b*b);
}

float squareDist(struct Particle *a, struct Particle *b){
  return (a->pos.x - b->pos.x) * (a->pos.x - b->pos.x) + (a->pos.y - b->pos.y) * (a->pos.y - b->pos.y);
}

// Calculating distance bewteen 2 particles
float dist(struct Particle *a, struct Particle *b){
  return sqrt(squareDist(a, b));
}

// Calculating force between 2 particles and adjusting acceleration according to its value
void force(struct Particle *a, struct Particle *b){
  float Norm = norm(a->pos.x - b->pos.x,a->pos.y - b->pos.y);
  float tmp = -(CONSTANT_G * b->mass) / Norm;
  
  struct Vector unitv = {(a->pos.x - b->pos.x)/Norm, (a->pos.y - b->pos.y)/Norm};
    
  a->acc.x += unitv.x*tmp;
  a->acc.y += unitv.y*tmp;
}

// Update position and speed of particle
void updateParticule(struct Particle *p, float dt){

  p->pos.x = p->pos.x + p->vit.x * dt + p->acc.x * ((dt * dt) / 2);
  p->pos.y = p->pos.y + p->vit.y * dt + p->acc.y * ((dt * dt) / 2);
  
  p->vit.x = p->vit.x + p->acc.x * dt;
  p->vit.y = p->vit.y + p->acc.y * dt;
}

// Computation of dt for a particle and its nearest neighbour
float dt_computation(struct Particle *p, float distMin){
  float a = norm(p->acc.x,p->acc.y);
  float b = norm(p->vit.x,p->vit.y);
  float c = -0.8*sqrt(distMin);
	
  float delta = b*b-4*a*c;
  return 0.5*(-b+sqrt(delta))/a;
}
