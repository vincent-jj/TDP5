#ifndef __DRIVER_H__
#define __DRIVER_H__

#define CONSTANT_G 6.68f

struct Vector{
    float x, y;
};

struct Particle{
    float mass;
    struct Vector pos; // position
    struct Vector vit; // speed
    struct Vector acc; // acceleration
};

float min(float a,float b);

float norm(float a, float b);

float squareDist(struct Particle *a, struct Particle *b);

float dist(struct Particle *a, struct Particle *b);

void force(struct Particle *a, struct Particle *b);

void updateParticule(struct Particle *p, float dt);

float dt_computation(struct Particle *p, float distMin);

#endif // __DRIVER_H__
