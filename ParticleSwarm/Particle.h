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
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//constant used to calculate new particle velocities
const double phi1 = 2.05;

//ranges of values for position depending on functions
const double ROK_POS[2] = {15, 30};
const double ACK_POS[2] = {16, 32};
const double RAS_POS[2] = {2.56, 5.12};

//ranges of values for position depending on functions
const double ROK_VEL[2] = {-2, 2};
const double ACK_VEL[2] = {-2, 4};
const double RAS_VEL[2] = {-2, 4};


class Particle {
    
public:
    //constructor function
    Particle(int dimensions, string function);
    
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
    
    //test functions
    double eval(string function, vector<double> pos);
    
private:
    double getRandomNumberInRange(double num1, double num2);
    
    //test functions
    double evalRosenbrock(vector<double> pos);
    double evalAckley(vector<double> pos);
    double evalRastrigin(vector<double> pos);
    
    //information about the particle's position as a vector
    vector<double> position;
    
    //information about the particle's velocity as a vector
    vector<double> velocity;
    
    //information about the particle's acceleration as a vector
    vector<double> acceleration;
    
    //information about the personal best positions, accelerations, and values
    vector<double> pBestPos;
    
    //TODO: do we need this variable? Yes, in order to update the acceleration.
    vector<double> pBestAccel;

    double pBestValue;
    
};

#endif /* defined(__ParticleSwarm__Particle__) */
