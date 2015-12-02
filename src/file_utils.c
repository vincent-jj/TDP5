#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "utils.h"
#include <sys/time.h>
#define DIST_MAX 3000
#define SIZE_MAX 5

void write_file(char* filename, struct Particle* p, int n){
	FILE* f = fopen(filename, "w");
	if(f==NULL){
		fprintf(stderr, "File open failed\n");
		exit(EXIT_FAILURE);
	}
	
	int i;

	fwrite(&n, sizeof(n), 1, f);
	for(i=0; i<n; ++i){
		//fwrite(&(p[i].id), sizeof(p[i].id), 1, f);
		fwrite(&(p[i].mass), sizeof(p[i].mass), 1, f);
		fwrite(&(p[i].pos.x), sizeof(p[i].pos.x), 1, f);
		fwrite(&(p[i].pos.y), sizeof(p[i].pos.y), 1, f);
		fwrite(&(p[i].vit.x), sizeof(p[i].vit.x), 1, f);
		fwrite(&(p[i].vit.y), sizeof(p[i].vit.y), 1, f);
		fwrite(&(p[i].acc.x), sizeof(p[i].acc.x), 1, f);
		fwrite(&(p[i].acc.y), sizeof(p[i].acc.y), 1, f);
	}
	fclose(f);
}


int read_file(char* filename, struct Particle** p){
	int n=-1;
	FILE* f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File open failed\n");
		exit(EXIT_FAILURE);
	}

	fread(&n, sizeof(n), 1, f);

	*p = malloc(n*sizeof(struct Particle));
	
	int i;
	
	for(i=0; i<n; ++i){
		//fread(&((*p)[i].id), sizeof((*p)[i].id), 1, f);
		//(*p)[i].id=i;
		fread(&((*p)[i].mass), sizeof((*p)[i].mass), 1, f);
		fread( &((*p)[i].pos.x), sizeof( (*p)[i].pos.x ), 1, f);
		fread( &((*p)[i].pos.y), sizeof( (*p)[i].pos.y ), 1, f);
		fread( &((*p)[i].vit.x), sizeof( (*p)[i].vit.x ), 1, f);
		fread( &((*p)[i].vit.y), sizeof( (*p)[i].vit.y ), 1, f);
		fread( &((*p)[i].acc.x), sizeof( (*p)[i].acc.x ), 1, f);
		fread( &((*p)[i].acc.y), sizeof( (*p)[i].acc.y ), 1, f);
	}

	fclose(f);
	return n;
}

struct Particle * gen_2_far_clusters(){
  int i;
  srand(time(NULL));
  
  struct Particle *particles = (struct Particle *) malloc(sizeof(struct Particle)*2*SIZE_MAX);
  if(particles == NULL){
    perror("Pointer allocation failed in gen_2_far_clusters\n");
    exit(-1);
  }

  for(i = 0; i < SIZE_MAX; ++i){
    particles[i].mass = 1 + (i * (rand() % 3)) % 10;
    particles[i].pos.x = (float)rand() / RAND_MAX;
    particles[i].pos.y = (float)rand() / RAND_MAX;
    particles[i].vit.x = (i - 10 + (rand() % 20)) ;
    particles[i].vit.y = (i - 10 + (rand() % 20));
    particles[i].acc.x = 0;
    particles[i].acc.y = 0;
  }
  
  for(i = SIZE_MAX; i < 2*SIZE_MAX; ++i){
    particles[i].mass = 1 + (i * (rand() % 3)) % 10;
    particles[i].pos.x = (float)rand() / RAND_MAX;
    particles[i].pos.x +=DIST_MAX;
    particles[i].pos.y = (float)rand() / RAND_MAX;
    particles[i].vit.x = (i - 10 + (rand() % 20)) ;
    particles[i].vit.y = (i - 10 + (rand() % 20));
    particles[i].acc.x = 0;
    particles[i].acc.y = 0;
  }
  return particles;
}

void gen_file_2_box(){
  struct Particle *p = gen_2_far_clusters();
  write_file("data.dat", p, SIZE_MAX*2);
}

struct Particle *gen_box(){
  struct Particle *box = NULL;
  return box;
}


int main(void){
  gen_file_2_box();
  FILE *fd = fopen("data_pow.dat", "a+");
  if(fd == NULL){
    perror("Error generating file descriptor in main\n");
    exit(-1);
  }
  struct Particle* p;
  int n = read_file("data.dat", &p);
  int i,j;
  float delta = 0.01;
  int turn;
  for(turn = 0; turn < 10 ; ++turn){
    for(i=0; i<n; ++i){
      for(j=0; j<n; ++j){
	if(i != j){
	  force(&p[i], &p[j]);
	  updateParticule(&p[i], delta);
	}
      }
      fprintf(fd, "%d %f %f \n", 
	      i,p[i].pos.x, p[i].pos.y);
    }
  }
  fclose(fd);
  return EXIT_SUCCESS;
}



