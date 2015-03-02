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
#include <vector>

using namespace std;

//constants that will be used to calculate new best particle velocities
const double phi2 = 2.05;
const double constrictionFactor = .7298;

class Swarm {
    
public:
    //constructor function
    Swarm(int numParticles);
    
    //getter functions
    double getGBestPos(int dimNumber);
    double getGBestAccel(int dimNumber);
    double getBestValue(){ return gBestValue; };
    double getNumParticles(){ return numParticles; };
    
    //setter functions
    void setGBestPos(int dimNumber);
    void setGBestAccel(int dimNumber);
    void setGBestValue();
    
    //test functions
    double eval(int functionNumber, vector<double> pos);
    double evalRosenbrock(vector<double> pos);
    double evalAckley(vector<double> pos);
    double evalRastrigin(vector<double> pos);
    
private:
    //global best information
    vector<double> gBestPos;
    vector<double> gBestAccel;
    double gBestValue;
    
    //number of particles in swarm
    int numParticles;
    
};

#endif /* defined(__ParticleSwarm__Swarm__) */
