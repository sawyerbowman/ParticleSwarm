//
//  Particle.cpp
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Particle.h"

/**
 *Constructor for a particle, initializes random position and velocity within
 *a given range depending on the function. Also initializes a value based on
 *the function.
 */

Particle::Particle(int dimensions, string function){
    //variables to hold the correct range of positions and velocities
    double pos[2], vel[2];
    
    if (function == "rok"){
        pos[0] = ROK_POS[0];
        pos[1] = ROK_POS[1];
        vel[0] = ROK_VEL[0];
        vel[1] = ROK_VEL[1];
    }
    else if (function == "ack"){
        pos[0] = ACK_POS[0];
        pos[1] = ACK_POS[1];
        vel[0] = ACK_VEL[0];
        vel[1] = ACK_VEL[1];
    }
    else {
        pos[0] = RAS_POS[0];
        pos[1] = RAS_POS[1];
        vel[0] = RAS_VEL[0];
        vel[1] = RAS_VEL[1];
        
    }
    
    //intialize a position and velocity for each particle (randomly within range)
    for (int i = 0; i < dimensions; i++){
        position.push_back(getRandomNumberInRange(pos[0], pos[1]));
        velocity.push_back(getRandomNumberInRange(vel[0], vel[1]));
        
        //best is initially what we initialized
        pBestPos.push_back(position[i]);
    }
    
    pBestValue = eval(function, position);
}

/**
 *Calculate and return a random number in a given range
 */

double Particle::getRandomNumberInRange(double min, double max){
    return min + ((double) rand() / (double) RAND_MAX) * (max-min);
}

/**
 *Evaluate using the selected function and return a value
 */

//TODO: IMPLEMENT THIS!

double Particle::eval(string function, vector<double> position){
    return 0;
}



