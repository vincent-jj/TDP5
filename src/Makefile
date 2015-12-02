MPI = mpicc -O2
WFLAGS = -Wall -Wextra
OMP = -fopenmp
EXE = 
TEST = test

.PHONY: all

all : $(EXE) 

$(EXE) : 

%.o : %.c
	$(MPI) -c $^ $(WFLAGS)

clean : 
	rm *.o
	rm $(EXE)
