//
//  sir.cpp
//
//  Created by Lance Aquino on 2/26/22.
//

#include "sir.h"
#include <cmath>

// SIR Constructor: Sets the initial values of the SIR Class simulation 
SIR::SIR (double _cm, double _cn, int _P, double _f, double _istar, double _beta, double _gamma, double _mu) : cm (_cm), cn (_cn), P(_P), f (_f), istar (_istar), beta (_beta),  gamma (_gamma), mu (_mu) {}


// getter functions that return certain private values of a SIR class at its current time
const double SIR::get_time(){
    return t;
}

const double SIR::get_sn(){
    return sn_t;
}

const double SIR::get_rn(){
    return rn_t;
}

const double SIR::get_sm(){
    return sm_t;
}

const double SIR::get_im(){
    return im_t;
}

const double SIR::get_rm(){
    return rm_t;
}

// function that alters some of the values of the SIR class for a current change in time, or "step"
void SIR::step(double step_size) {
    
    // Formulas for the constants R, Hn, and Hm, as provided in the hw8 pdf. They are each used for calculating the changes of sn_t, sm_t, in_t, im_t, rn_t, and rm_t. These constants are calculated each time step() is executed based on the in_t and im_t at the current time, since the values of in_t and im_t change after each step
    
    const double R = 1 - exp(-gamma * step_size);
    const double Hn = 1 - exp((-beta * step_size * cn) * ( (((mu* (1-psim))*in_t )/(1-f)) + ((psim*im_t )/f)) );
    const double Hm = 1 - exp((-beta * step_size * cm) * ( (((mu* (1-psim))*in_t )/(1-f)) + ((psim*im_t )/f)) );
    
    // the changes in sn_t, sm_t, in_t, im_t, rn_t, and rm_t, at a given time. These are based off of the current time, before it is overwritten to be "t + ∆t".
    double delta_sn_t = - (Hn * sn_t);
    double delta_sm_t = - (Hm * sm_t);;
    double delta_in_t = (Hn * sn_t) - (R * in_t);
    double delta_im_t = (Hm * sm_t) - (R * im_t);
    double delta_rn_t = (R * in_t);
    double delta_rm_t = (R * im_t);
    
    // each of the SIR class values get overwritten based on their corresponding delta values in the lines above.
    sn_t += delta_sn_t;
    sm_t += delta_sm_t;
    in_t += delta_in_t;
    im_t += delta_im_t;
    rn_t += delta_rn_t;
    rm_t += delta_rm_t;
    
    // increases the time value of the SIR class (in days) based on the inputted step_size
    SIR::t += step_size;
    
}

