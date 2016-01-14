#include <iostream>
#include <vector>
#include "interactions.hxx"
#include "node.hxx"
#define DEFAULT_NUM_STEP 100
#define DEFAULT_PART_NUM 100000
#define DEFAULT_WIDTH 500000.
#define DEFAULT_HEIGHT 500000.
#define MASS_MIN 1.
#define MASS_MAX 10.

int main(int argc, char *argv[]){
    unsigned i;
    std::vector<particle*>particles;
    node main_node;
    if(argc < 1)
        generateParticlesSet(&particles, DEFAULT_PART_NUM, DEFAULT_WIDTH, DEFAULT_HEIGHT, MASS_MIN, MASS_MAX);
    for(i = 0; i < DEFAULT_NUM_STEP; ++i){
        updateParticles(particles);
        resetAttraction(particles);
        main_node.reset();
        main_node.setParameters(particles, DEFAULT_WIDTH, DEFAULT_HEIGHT);
        particleAttraction(&main_node);
    }
    deleteParticles(particles);
}
