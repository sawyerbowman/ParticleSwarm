//
//  ParticleSwarmAlgorithm.cpp
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "ParticleSwarmAlgorithm.h"

/**
 *Constructor initializing the algorithm object.
 */

ParticleSwarmAlgorithm::ParticleSwarmAlgorithm(string topology, int swarmSize,
                                               int iterations, string
                                               function, int dimensions){
    this->topology = topology;
    this->swarmSize = swarmSize;
    this->iterations = iterations;
    this->function = function;
    this->dimensions = dimensions;
    
    swarm = new Swarm(swarmSize, dimensions, function);
}

/**
 *The main algorithm: calls the designated toplogy
 */

void ParticleSwarmAlgorithm::run(){
    //go through the maximum number of iterations
    for (int gen = 0; gen < iterations; gen++){
        swarm->update(dimensions, function, topology);
        cout << "iteration " << gen << " gbest value = " << swarm->getBestValue() << endl;
    }
}
