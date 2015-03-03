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

void Swarm::randomTop(int k, int particleNumber){
    
    int count = k-1;
    bool usedParticles[particles.size()];
    //initialize the usedParticles vector to all false.
    for(int i = 0; i < particles.size(); i++){
        usedParticles[i] = false;
    }
    
    //while loop to choose k-1 individuals with no repetition
    while(count != 0){
        int randParticle = rand() % numParticles;
        if(usedParticles[randParticle] == false && randParticle != particleNumber){
            
        }
    }
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

/*
 * Get global best position function
 */
double Swarm::getGBestPos(int dimNumber) {
    return gBestPos.at(dimNumber);
}

/* 
 * Get global best acceleration function
 */
double Swarm::getGBestAccel(int dimNumber) {
    return gBestAccel.at(dimNumber);
}

/*
 * Set global best position function
 */
void Swarm::setGBestPos(int dimNumber, double newGBestPos) {
    gBestPos.at(dimNumber) = newGBestPos;
}

/*
 * Set global best acceleration
 */

void Swarm::setGBestAccel(int dimNumber, double newGBestAccel){
    gBestAccel.at(dimNumber) = newGBestAccel;
}

/*
 * Set global best value
 */

void Swarm::setGBestValue(double newGBestValue){
    gBestValue = newGBestValue;
}

// Global neighborhood topology function
void globalTop(){
    
}