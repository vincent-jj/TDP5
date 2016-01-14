#include "interactions.hxx"
#include <vector>
#include <ctime>
#include <cmath>
#include <sys/time.h>
#define G 0.16
#define SIMULATION_W 500000.
#define SIMULATION_H 500000.
#define __NODE_TOLERANCY__ 0.5

void calcForce(particle *p_i, particle *p_j){
    coords vect;
    vect.x = p_i->pos.x - p_j->pos.x;
    vect.y = p_i->pos.y - p_j->pos.y;
    float dist = (vect.x*vect.x)+(vect.y*vect.y);
    float powa = (p_i->wei * p_j->wei * G)/dist;
    p_j->acc.x += vect.x * powa;
    p_j->acc.y += vect.y * powa;
    return;
}

void calcForceBary(node *n_i, particle *p_j){
    coords vect;
    vect.x = n_i->barycenter.x - p_j->pos.x;
    vect.y = n_i->barycenter.y - p_j->pos.y;
    float dist = (vect.x * vect.x) + (vect.y * vect.y);
    float powa = ((n_i->wei)*(p_j->wei)*G)/dist;
    p_j->acc.x += vect.x * powa;
    p_j->acc.y += vect.y * powa;
    return;
}

void deleteParticles(std::vector<particle*>particles){
    unsigned i;
    for(i = 0; i < particles.size(); ++i)
        delete particles[i];
    particles.clear();
    return;
}

particle *createParticle(coords pos, float weigh){
    particle *np = new particle;
    np->pos.x = pos.x;
    np->pos.y = pos.y;
    np->wei = weigh;
    np->spe.x = 0.;
    np->spe.y = 0.;
    np->acc.x = 0.;
    np->acc.y = 0.;
    return np;
}

void generateParticlesSet(std::vector<particle*> *particles, unsigned particlesNumber, float width, float height, float mass_min, float mass_max){
    unsigned i;
    srand(time(NULL));
    for(i = 0; i < particlesNumber; ++i){
        coords pos;
        pos.x = (float)rand()/(float)RAND_MAX * width + (float)(SIMULATION_W/2. - width/2.);
        pos.y = (float)rand()/(float)RAND_MAX * height + (float)(SIMULATION_H/2. - height/2.);
        float wei = mass_min + (float)(rand()%(int)(mass_max-mass_min));
        particles->push_back(createParticle(pos,wei));
    }
    return;
}

void updateParticles(std::vector<particle*>particles){
    unsigned i;
    for(i = 0; i < particles.size(); ++i){
      if(((particles[i]->pos.x > SIMULATION_W) && (particles[i]->spe.x > 0.))
	 || ((particles[i]->pos.x < 0.) && (particles[i]->spe.x < 0.)))
	particles[i]->spe.x *= -1.0;

      if(((particles[i]->pos.y > SIMULATION_H) && (particles[i]->spe.y > 0.))
	 || ((particles[i]->pos.y < 0.) && (particles[i]->spe.y < 0.)))
	particles[i]->spe.y *= -1.0;

        particles[i]->spe.x += particles[i]->acc.x / particles[i]->wei;
        particles[i]->spe.y += particles[i]->acc.y / particles[i]->wei;
        particles[i]->pos.x += particles[i]->spe.x;
        particles[i]->pos.y += particles[i]->spe.y;
    }
    return;
}

void checkNodeDistance(node *nodes, particle *particle_u){
    if(nodes->Particles.size()){
        coords diff;
        diff.x = (nodes->barycenter.x - particle_u->pos.x);
        diff.y = (nodes->barycenter.y - particle_u->pos.y);
        float dist = sqrt((diff.x*diff.x)+(diff.y*diff.y));
        // NODE TOLERANCY correspond à notre pas de 1/2 pour dispatcher les différentes particules //
        if((!nodes->hasChild) || ((nodes->widthSize / dist) < (__NODE_TOLERANCY__))){
            calcForceBary(nodes, particle_u);
            nodes->completed = true;
        }
        else{
            checkNodeDistance(nodes->Child[0],particle_u);
            checkNodeDistance(nodes->Child[1],particle_u);
            checkNodeDistance(nodes->Child[2],particle_u);
            checkNodeDistance(nodes->Child[3],particle_u);
        }
    }
    return;
}

void particleAttraction(node *nodes){
    unsigned i;
    for(i = 0; i < nodes->Particles.size(); ++i)
        checkNodeDistance(nodes, nodes->Particles[i]);
    return;
}

void resetAttraction(std::vector<particle*>particles){
    unsigned i;
    for(i = 0; i < particles.size(); ++i){
        particles[i]->acc.x = 0.;
        particles[i]->acc.y = 0.;
    }
    return;
}
