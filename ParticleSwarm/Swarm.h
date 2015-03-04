//
//  Swarm.h
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __ParticleSwarm__Swarm__
#define __ParticleSwarm__Swarm__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Particle.h"

using namespace std;

//constants that will be used to calculate new best particle velocities
const double phi2 = 2.05;
const double constrictionFactor = .7298;
const int k = 5;

class Swarm {
    
public:
    //constructor function
    Swarm(int numParticles, int dimensions, string function);
    
    //getter functions
    double getGBestPos(int dimNumber) { return gBestPos.at(dimNumber); }
    double getBestValue() { return gBestValue; }
    double getNumParticles() { return numParticles; }
    
    //setter functions
    void setAllGBestPos(vector<double> newBestPos) { gBestPos = newBestPos; }
    void setGBestPos(int dimNumber, double newGBestPos) { gBestPos.at(dimNumber) = newGBestPos; }
    void setGBestValue(double newGBestValue) { gBestValue = newGBestValue; }
    
    //update function that takes topology into account
    void update(int dimensions, string function, string topology);
    
private:
    //functions for Von Neumann Topology
    int findFactor();
    vector<Particle*> initializeNeighborhood(int index, int rows, int cols);

    //function for Random Topology
    vector<Particle*> initializeNeighborhood(int index, int k);
    
    //function for Ring Topology
    vector<Particle*> initializeNeighborhood(int index);
    
    double findBestPositionInNeighborhood(vector<Particle*> neighborhood,
                                          Particle* curParticle, int dim,
                                          string toplogy);
    
    //global best information
    vector<double> gBestPos;
    double gBestValue;
    
    //number of particles in swarm
    int numParticles;
    
    //vector containing each particle
    vector<Particle*> particles;
    
};

#endif /* defined(__ParticleSwarm__Swarm__) */
