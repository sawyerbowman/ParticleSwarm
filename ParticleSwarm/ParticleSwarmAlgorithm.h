//
//  ParticleSwarmAlgorithm.h
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __ParticleSwarm__ParticleSwarmAlgorithm__
#define __ParticleSwarm__ParticleSwarmAlgorithm__

#include <stdio.h>
#include <iostream>
#include "Swarm.h"

using namespace std;

class ParticleSwarmAlgorithm{
public:
    ParticleSwarmAlgorithm(string topology, int swarmSize, int iterations, string
                           function, int dimensions);
    
    void run();
    
private:
    string topology;
    int swarmSize;
    int iterations;
    string function;
    int dimensions;
    
    Swarm *swarm;
    
};

#endif /* defined(__ParticleSwarm__ParticleSwarmAlgorithm__) */
