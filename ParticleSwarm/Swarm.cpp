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