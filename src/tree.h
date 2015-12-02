#ifndef __TREE_H__
#define __TREE_H__
#include "driver.h"

// Tree structure for Barnes & Hut algorithm
struct Tree{
  struct Particle *particles;
  int size;
};


// Particle to Particle algorithm
P2P(struct Tree *);

// Particle to Molecule algorithm
P2M(struct Tree *);

// Molecule to Molecule algorithm
M2M(struct Tree *);

// Molecule to Local algorithm
M2L(struct Tree *);

// Local to Local algorithm
L2L(struct Tree *);

// Local to Particle algorithm
L2P(struct Tree *);

//



#endif // __TREE_H__
