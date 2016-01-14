#pragma once
#include<vector>
#include"node.hxx"

void calcForce(particle *p_i, particle *p_j);
void calcForceBary(node *n_i, particle *p_j);
void deleteParticles(std::vector<particle*>particles);
particle* createParticle(coords pos, float weigh);
void generateParticlesSet(std::vector<particle*> *particles, unsigned particlesNumber, float width, float height, float mass_min, float mass_max);
void updateParticles(std::vector<particle*>particles);
void checkNodeDistance(node *nodes, particle *particle_u);
void particleAttraction(node *nodes);
void resetAttraction(std::vector<particle*>particle);

