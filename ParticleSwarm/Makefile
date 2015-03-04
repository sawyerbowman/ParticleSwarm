CC=g++

CFLAGS=-c -Wall

all:	pso

pso:	main.o ParticleSwarmAlgorithm.o Swarm.o Particle.o
	$(CC) main.o ParticleSwarmAlgorithm.o Swarm.o Particle.o -o pso

main.o:	main.cpp ParticleSwarmAlgorithm.h
	$(CC) $(CFLAGS) main.cpp

ParticleSwarmAlgorithm.o:	ParticleSwarmAlgorithm.cpp ParticleSwarmAlgorithm.h Swarm.h
	$(CC) $(CFLAGS) ParticleSwarmAlgorithm.cpp

Swarm.o:	Swarm.cpp Swarm.h Particle.h
	$(CC) $(CFLAGS) Swarm.cpp

Particle.o:	Particle.cpp PArticle.h
	$(CC) $(CFLAGS) Particle.cpp

clean:
	rm *o pso