//
//  main.cpp
//  ParticleSwarm
//
//  Created by Sawyer Bowman on 3/1/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include <stdio.h>
#include "ParticleSwarmAlgorithm.h"
#include <iostream>
#include <fstream>


using namespace std;

//constants used in testing
const int particles[3] = {12, 20, 50};
const int iterations = 50000;
const int dimensions = 30;
const string tops[4] = {"gl", "ri", "vn", "ra"};
const string funcs[3] = {"ack", "ras", "rok"};
const int reps = 50;

/**
 *Saves output into csv file
 */

void saveResults(string top, string func, int particles, double result, double time){
    ofstream csvFile;
    csvFile.open("/Users/sawyerbowman/Desktop/pso_results.csv", std::ios_base::app);
    
    csvFile << top << "," << func << "," << particles << "," << result << "," <<
                time << endl;
    
    csvFile.close();
}

/**
 *Testing loop (12, 20, 50 particles) 30 dimensions, 50,000 iterations, 50 runs
 *per permutation
 */

void testing(){
    for (int numParticles = 0; numParticles < 3; numParticles++){
        for (int topo = 0; topo < 4; topo++){
            for (int func = 0; func < 3; func++){
                for (int r = 0; r < reps; r++){
                    ParticleSwarmAlgorithm *alg = new ParticleSwarmAlgorithm(tops[topo],
                                                                             particles[numParticles],
                                                                             iterations,
                                                                             funcs[func],
                                                                             dimensions);
                    //start the clock
                    clock_t start = clock();
                    double result = alg->run();
                    double time = (clock() - start)/(double)CLOCKS_PER_SEC;
                    
                    saveResults(tops[topo], funcs[func], particles[numParticles],
                                result, time);
                }
            }
        }
    }
}

/**
 *Parse the command line arguments, initialize the algorithm object, and run.
 */

int main(int argc, const char * argv[]) {
    srand( time( NULL ) );
    
    testing();
    
//    if (argc != 6) {
//        cout << "Please enter the correct number of parameters for particle swarm "
//                "algorithm!" << endl;
//        cout << "Topology:       which neighborhood topology to test ex. gl, ri, "
//                "vn, ra (string)" << endl;
//        cout << "Swarm Size:    the size of the swarm ex. 100 (int)" << endl;
//        cout << "Iterations:    the number of iterations ex. 1000 (int)" << endl;
//        cout << "Function:      which function to optimize ex. rok, ack, ras "
//                "(string)" << endl;
//        cout << "Dimensions:    the dimensionality of the function ex. 30 (int)"
//                << endl;
//    }
//    else {
//        //Parse the parameters
//        string topology = argv[1];
//        int size = stoi(argv[2]);
//        int iterations = stoi(argv[3]);
//        string function = argv[4];
//        int dimensions = stoi(argv[5]);
//        
//        //Initialize algorithm object and run
//        ParticleSwarmAlgorithm *alg = new ParticleSwarmAlgorithm(topology, size,
//                                                                iterations, function,
//                                                                dimensions);
//        alg->run();
//        
        cout << "DONE!" << endl;
//    }
}
