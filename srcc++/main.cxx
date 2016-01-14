#include <iostream>
#include <vector>
#include "interactions.hxx"
#include "node.hxx"
#include <fstream>
#define DEFAULT_NUM_STEP 100
#define DEFAULT_PART_NUM 10
#define DEFAULT_WIDTH 5000000.
#define DEFAULT_HEIGHT 5000000.
#define MAX_DEPTH 10
#define MASS_MIN 1.
#define MASS_MAX 10.

int main(int argc, char *argv[]){
    unsigned i, j;
    std::ofstream fd;
    fd.open("nbody.dat");
    std::vector<particle*>particles;
    node main_node = new node(MAX_DEPTH);
    main_node.Particles = particles;
    // if(argc < 1)
    generateParticlesSet(&particles, DEFAULT_PART_NUM, DEFAULT_WIDTH, DEFAULT_HEIGHT, MASS_MIN, MASS_MAX);
    for(i = 0; i < DEFAULT_NUM_STEP; ++i){
        updateParticles(particles);
        resetAttraction(particles);
        main_node.reset();
        main_node.setParameters(particles, DEFAULT_WIDTH, DEFAULT_HEIGHT);
        particleAttraction(&main_node);
        fd << i << std::endl;
        for(j = 0; j < particles.size() ; ++j)
            fd << j << " " << particles[j]->pos.x << " " << particles[j]->pos.y << std::endl;
    }
    fd.close();
    deleteParticles(particles);
}
