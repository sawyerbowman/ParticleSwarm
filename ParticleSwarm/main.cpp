//
//  main.cpp
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "ParticleSwarmAlgorithm.h"

using namespace std;

/**
 *Parse the command line arguments, initialize the algorithm object, and run.
 */

int main(int argc, const char * argv[]) {
    srand( time( NULL ) );
    
    if (argc != 6) {
        cout << "Please enter the correct number of parameters for particle swarm "
                "algorithm!" << endl;
        cout << "Topology:       which neighborhood topology to test ex. gl, ri, "
                "vn, ra (string)" << endl;
        cout << "Swarm Size:    the size of the swarm ex. 100 (int)" << endl;
        cout << "Iterations:    the number of iterations ex. 1000 (int)" << endl;
        cout << "Function:      which function to optimize ex. rok, ack, ras "
                "(string)" << endl;
        cout << "Dimensions:    the dimensionality of the function ex. 30 (int)"
                << endl;
    }
    else {
        //Parse the parameters
        string topology = argv[1];
        int size = stoi(argv[2]);
        int iterations = stoi(argv[3]);
        string function = argv[4];
        int dimensions = stoi(argv[5]);
        
        //Initialize algorithm object and run
        ParticleSwarmAlgorithm *alg = new ParticleSwarmAlgorithm(topology, size,
                                                                iterations, function,
                                                                dimensions);
        alg->run();
        
        cout << "DONE!" << endl;
    }
}
