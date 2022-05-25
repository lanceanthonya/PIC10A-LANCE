////
////  main.cpp
////  sir
////
////  Created by Lance Aquino on 2/26/22.
////
//
//#include <iostream>
//#include "sir.h"
//
//using namespace std;
//
//int main() {
//    const double cm = 14; // normal, without distancing
//    const double cn = 9; // after distancing
//
//    const int P = 1000000; // 1 million people, say
//
//    const double istar = 0.005; // 0.5% are initially infected
//    const double beta = 0.02; // /day
//    const double gamma = 1./14; // /day
//    const double mu = 0.34; // if wearing mask
//
//    const double f1 = 0.001; // 1 in 1000 are morons
//    const double f2 = 0.05; // 1 in 20 are morons
//
//    const double Tend = 300; // run till 300 days, say
//    const double dT = 1.; // time steps of 1 day
//
//    SIR p1(cm, cn, P, f1, istar, beta, gamma, mu);
//
//    while (p1.get_time() < Tend) { // until simulation end time
//        p1.step(dT);
//    }
//
//    return 0;
//}
