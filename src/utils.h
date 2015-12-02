#ifndef __UTILS_H__
#define __UTILS_H__

void write_file(char* , struct Particle* , int );

int read_file(char* filename, struct Particle** p);

struct Particle * gen_2_far_clusters();

void gen_file_2_box();

struct Particle *gen_box();

#endif
