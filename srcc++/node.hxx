#ifndef __NODE_H__
#define __NODE_H__
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define TRUE 1
#define FALSE 0

typedef struct coords{
    float x, y;
}coords;

typedef struct particle{
    coords pos;
    coords spe;
    coords acc;
    float wei;
}particle;

// C++ version

using namespace std;

class node{
  // private:
  // coords pos;
  // float widthSize;
  // float heightSize;
  // float massTree;
  // coords barycenter;
  // int depth;
  // vector<particle*> Particles;
  // vector<node*> Child;
  // bool hasChild;
public:
  coords pos;
  float widthSize;
  float heightSize;
  float massTree;
  int depth;
  vector<particle*> Particles;
  vector<node*> Child;
  coords barycenter;
  float wei;
  bool hasChild;
  bool completed;
  node();
  node(int depths);
  ~node();
  void makeChild();
  void setParameters(vector<particle*>particles, float particlesWidth, float particlesHeight, float pos_x = 0., float pos_y = 0.);
  void reset();
};

// C version
/*
typedef struct node node{
    coords pos; 
    float width_size, height_size;
    float mass_tree;
    coords barycenter;
    int depth;
    particle *particles;
    node *child;
    int has_child;
};

node *init_node();
node *init_node_depth(int depths);
void free_node(node * node_tree);
void make_child();
void set_node_params(particle *particles,
                     float width, 
                     float height, 
                     float pos_x,
                     float pos_y);
void reset(node *node_tree);
*/
#endif // __NODE_H__
