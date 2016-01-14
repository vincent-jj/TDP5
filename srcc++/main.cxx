#include <iostream>
#include <vector>
#include "interactions.hxx"
#include "node.hxx"
#include <fstream>
#define DEFAULT_NUM_STEP 10
#define DEFAULT_PART_NUM 5
#define DEFAULT_WIDTH 100e8
#define DEFAULT_HEIGHT 100e8
#define MAX_DEPTH 10
#define MASS_MIN 1.
#define MASS_MAX 10.

int main(int argc, char *argv[]){
    unsigned i, j;
    std::ofstream fd;
    fd.open("nbody.dat");
    std::vector<particle*>particles;
    node main_node = new node(MAX_DEPTH);

    particle *part;
    unsigned k;
    for(k = 0; k < 5; ++k){
      if(!k){
        part = new particle;
        part->pos.x = part->pos.y = 0;
        part->wei = 1.9891e30;
        part->spe.x = part->spe.y = 0;
        part->acc.x = part->acc.y = 0;
        particles.push_back(part);
      }
      if(k == 1){
        part = new particle;
        part->pos.x = 57909176;
        part->pos.y = 0.;
        part->spe.x = 0.;
        part->spe.y = 47.35e3;
        part->acc.x = part->acc.y = 0;
        part->wei = 3.0e23;
        particles.push_back(part);
      }
      if(k == 2){
        part = new particle;
        part->pos.x = 108208930;
        part->pos.y = 0.0;
        part->spe.x = 0.0;
        part->spe.y = -35.02e3;
        part->acc.x = 0.0;
        part->acc.y = 0.0;
        part->wei = 5.97237e24;
        particles.push_back(part);
      }
      if(k == 3){
        part = new particle;
        part->pos.x = 149597887.5;
        part->pos.y = 0.0;
        part->spe.x = 0.0;
        part->spe.y = 29.783e3;
        part->acc.x = 0.0;
        part->acc.y = 0.0;
        part->wei = 5.97237e24;
        particles.push_back(part);
      }
      if(k == 4){
        part = new particle;
        part->wei = 641.85e21;
        part->pos.x = 227936637;
        part->pos.y = 0;
        part->spe.x = 0.0;
        part->spe.y = 24.077e3;
        part->acc.x = 0.0;
        part->acc.y = 0.0;
        particles.push_back(part);
      }
    }
    main_node.Particles = particles;
    // if(argc < 1)
    // generateParticlesSet(&particles, DEFAULT_PART_NUM, DEFAULT_WIDTH, DEFAULT_HEIGHT, MASS_MIN, MASS_MAX);
    for(i = 0; i < DEFAULT_NUM_STEP; ++i){
        // updateParticles(particles);
        // resetAttraction(main_node.Particles);
        // particles = main_node.Particles;
        // main_node.reset();
        // main_node.setParameters(main_node.Particles, DEFAULT_WIDTH, DEFAULT_HEIGHT);
        // particleAttraction(&main_node);
        // updateParticles(main_node.Particles);
        fd << i << std::endl;
        for(j = 0; j < particles.size() ; ++j)
           fd << j << " " << particles[j]->pos.x << " " << particles[j]->pos.y << std::endl;
        main_node.setParameters(particles, DEFAULT_WIDTH, DEFAULT_HEIGHT);
        particleAttraction(&main_node);
        updateParticles(main_node.Particles);
        particles = main_node.Particles;
        main_node.reset();
    }
    fd.close();
    deleteParticles(particles);
}
