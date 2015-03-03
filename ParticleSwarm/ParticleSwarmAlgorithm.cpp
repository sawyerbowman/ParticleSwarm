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
        //Run Global topology
        if(topology == "gl"){
            swarm->globalTop();
        }
        //Run Ring topology
        else if (topology == "ri"){
            swarm->ringTop();
        }
        //Run Von Neumann topology
        else if (topology == "vn"){
            swarm->vonNeumannTop(dimensions, function);
        }
        //Run Random topology
        else {
            swarm->randomTop(5, swarmSize);
        }
        cout << "iteration " << gen << " gbest value = " << swarm->getBestValue();
    }
    
    cout << "Derp!" << endl;
}
