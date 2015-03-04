//
//  Swarm.cpp
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Swarm.h"

/**
 *Constructor initializing a swarm of particles.
 */

Swarm::Swarm(int numParticles, int dimensions, string function){
    this->numParticles = numParticles;
    for (int i = 0; i < numParticles; i++){
        Particle *newParticle = new Particle(dimensions, function);
        particles.push_back(newParticle);
    }
}

/**
 *Random topology function.
 */

void Swarm::randomTop(int k, int dimensions, string function){
    
    //each particle has its own neighborhood
    vector<Particle*> neighborhood;
    
    for(int i = 0; i < particles.size(); i++){
        neighborhood = initializeNeighborhood(i, k);
        
        double randNum = (double) rand() / (double) RAND_MAX;
        double persRand = randNum*phi1;
        double neighRand = randNum*phi2;
        for (int d = 0; d < dimensions; d++){
            //Compute acceleration due to personal best
            double accelPersBest = (particles[i]->getPBest(d) - particles[i]
                                    ->getPosition(d)) * persRand;
            
            //Compute acceleration due to neighborhood best
            double accelNeighBest = (findBestPositionInNeighborhood(neighborhood, particles[i], d)
                                     - particles[i]->getPosition(d)) * neighRand;
            
            //constrict the new velocity
            double newVel = constrictionFactor * (particles[i]->getVelocity(d) +
                                                  accelPersBest + accelNeighBest);
            
            //reset the current velocity
            particles[i]->setVelocity(d, newVel);
            
            //find new position
            double newPos = particles[i]->getPosition(d) + particles[i]->getVelocity(d);
            
            //reset the current position
            particles[i]->setPosition(d, newPos);
        }
        //find the value of the new position
        double newValue = particles[i]->eval(function, particles[i]->getAllPositions());
        
        //update the personal best
        if (newValue < particles[i]->getPBestValue()){
            particles[i]->setPBestValue(newValue);
            particles[i]->setAllBestPositions(particles[i]->getAllPositions());
        }
        
        //update the global best
        if (particles[i]->getPBestValue() < gBestValue){
            gBestValue = particles[i]->getPBestValue();
            setAllGBestPos(particles[i]->getAllBestPos());
            setAllGBestAccel(particles[i]->getAllBestAccel());
        }
    
    }
}

vector<Particle*> Swarm::initializeNeighborhood(int index, int k){
    
    vector<Particle*> neighborhood;
    int count = k-1;
    
    bool usedParticles[particles.size()];
    //initialize the usedParticles vector to all false.
    for(int i = 0; i < particles.size(); i++){
        usedParticles[i] = false;
    }
    
    //let the particle itself be in its own neighborhood
    neighborhood.push_back(particles.at(index));
    usedParticles[index] = true;
    
    //while loop to choose k-1 individuals as a neighborhood
    while(count != 0){
        //a random number from 0 to (Number of Particles)
        int randParticle = rand() % numParticles;
        if(usedParticles[randParticle] == false){
            neighborhood.push_back(particles.at(randParticle));
            count--;
        }
    }
    return neighborhood;
}

//node for the doubly linked list in ringTop function.
struct node{
    node* next;
    node* prev;
};

/*
 *Ring topology function.
 */

void Swarm::ringTop(){
    node* head;
    node* tail;
    node* conductor;
    
    conductor = new node;
    conductor->prev = NULL;
    head = conductor;
    tail = conductor;
    
    conductor = new node;
    conductor->prev = tail;
    tail->next = conductor;
    tail = conductor;
    
}

/**
 *Von Neumann topology function
 */

void Swarm::vonNeumannTop(int dimensions, string function){
    //initialize the number of rows and cols for the grid representation
    int rows = findFactor();
    int cols = numParticles/rows;
    
    //each particle has its own neighborhood, intialized in this loop
    vector<Particle*> neighborhood;
    for (int i = 0; i < particles.size(); i++){
        neighborhood = initializeNeighborhood(i, rows, cols);
        
        double randNum = (double) rand() / (double) RAND_MAX;
        double persRand = randNum*phi1;
        double neighRand = randNum*phi2;
        for (int d = 0; d < dimensions; d++){
            //Compute acceleration due to personal best
            double accelPersBest = (particles[i]->getPBest(d) - particles[i]
                                    ->getPosition(d)) * persRand;
            
            //Compute acceleration due to neighborhood best
            double accelNeighBest = (findBestPositionInNeighborhood(neighborhood, particles[i], d)
                                    - particles[i]->getPosition(d)) * neighRand;
            
            //constrict the new velocity
            double newVel = constrictionFactor * (particles[i]->getVelocity(d) +
                                                  accelPersBest + accelNeighBest);
            
            //reset the current velocity
            particles[i]->setVelocity(d, newVel);
            
            //find new position
            double newPos = particles[i]->getPosition(d) + particles[i]->getVelocity(d);
            
            //reset the current position
            particles[i]->setPosition(d, newPos);
        }
        //find the value of the new position
        double newValue = particles[i]->eval(function, particles[i]->getAllPositions());
        
        //update the personal best
        if (newValue < particles[i]->getPBestValue()){
            particles[i]->setPBestValue(newValue);
            particles[i]->setAllBestPositions(particles[i]->getAllPositions());
        }
        
        //update the global best
        if (particles[i]->getPBestValue() < gBestValue){
            gBestValue = particles[i]->getPBestValue();
            setAllGBestPos(particles[i]->getAllBestPos());
            setAllGBestAccel(particles[i]->getAllBestAccel());
        }
    }
}

/**
 *Compare the best position in a particular dimension for each particle in a given
 *neighborhood. Return the highest one. (optimal is small)
 */

double Swarm::findBestPositionInNeighborhood(vector<Particle*> neighborhood,
                                             Particle* curParticle, int dim){
    double bestInDim = curParticle->getPBest(dim);
    for (Particle* neighbor : neighborhood){
        if (neighbor->getPBest(dim) < bestInDim){
            bestInDim = neighbor->getPBest(dim);
        }
    }
    return bestInDim;
}

/**
 *Given a particle's index in the 1d array and the number of rows and cols for
 *the 2d array, initialize a neighborhood created by going in 4 cardinal directions
 *with wraparound.
 */

vector<Particle*> Swarm::initializeNeighborhood(int index, int rows, int cols){
    vector<Particle*> neighborhood;
    
    //up particle
    //if index is on top row
    if (index >= 0 && index < cols){
        neighborhood.push_back(particles[(rows-1)*cols+index]);
    }
    else{
        neighborhood.push_back(particles[index-cols]);
    }
    
    //down particle
    //if index is on bottom row
    if (index >= (cols*rows)-cols && index < (cols*rows)){
        neighborhood.push_back(particles[index-(rows-1)*cols]);
    }
    else{
        neighborhood.push_back(particles[index+cols]);
    }
    
    //left particle
    //if index is on left edge
    if (index % cols == 0){
        neighborhood.push_back(particles[index+cols-1]);
    }
    else{
        neighborhood.push_back(particles[index-1]);
    }
    
    //right particle
    //if index is on right edge
    if ((index+1) % cols == 0){
        neighborhood.push_back(particles[index-cols-1]);
    }
    else{
        neighborhood.push_back(particles[index+1]);
    }
    
    return neighborhood;
}

/**
 *Given the number of particles, this method finds one factor closest to the square
 *root. This will give us a 2d grid closest to a square shape (use the factors
 *for row and column)
 */

int Swarm::findFactor(){
    int possibleFactor = sqrt(numParticles);
    while (!(numParticles % possibleFactor == 0)){
        possibleFactor--;
    }
    return possibleFactor;
}

/**
>>>>>>> Von Neumann Implemented
 * Get global best position function
 */

double Swarm::getGBestPos(int dimNumber) {
    return gBestPos.at(dimNumber);
}

/**
 * Get global best acceleration function
 */

double Swarm::getGBestAccel(int dimNumber) {
    return gBestAccel.at(dimNumber);
}

/**
 * Set global best position function
 */

void Swarm::setGBestPos(int dimNumber, double newGBestPos) {
    gBestPos.at(dimNumber) = newGBestPos;
}

/**
 * Set global best acceleration
 */

void Swarm::setGBestAccel(int dimNumber, double newGBestAccel){
    gBestAccel.at(dimNumber) = newGBestAccel;
}

/**
 * Set global best value
 */

void Swarm::setGBestValue(double newGBestValue){
    gBestValue = newGBestValue;
}

/**
 *Global neighborhood topology function
 */

void globalTop(){
    
}