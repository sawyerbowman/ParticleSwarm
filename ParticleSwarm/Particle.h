//
//  Particle.h
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __ParticleSwarm__Particle__
#define __ParticleSwarm__Particle__

#include <stdio.h>
#include <vector>

using namespace std;

//constant used to calculate new particle velocities
const double phi1 = 2.05;

class Particle {
    
public:
    //constructor function
    Particle();
    
    //getter functions
    double getPosition(int dimNumber);
    double getVelocity(int dimNumber);
    double getAccel(int dimNumber);
    double getPBest(int dimNumber);
    double getPBestValue(){ return pBestValue; };
    
    //setter functions
    void setPosition(int dimNumber, double posValue);
    void setVelocity(int dimNumber, double velValue);
    void setAccel(int dimNumber, double accelValue);
    void setPBest(int dimNumber, double posValue);
    void setPBestValue(double newPBestValue);
    
private:
    //information about the particle's position as a vector
    vector<double> position;
    
    //information about the particle's velocity as a vector
    vector<double> velocity;
    
    //information about the particle's acceleration as a vector
    vector<double> acceleration;
    
    //information about the personal best positions, accelerations, and values
    vector<double> pBestPos;
    vector<double> pBestAccel;
    double pBestValue;
    
};

#endif /* defined(__ParticleSwarm__Particle__) */
