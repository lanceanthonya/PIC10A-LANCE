//
//  sir.h
//
//  Created by Lance Aquino on 2/26/22.
//

#ifndef _SIR_
#define _SIR_

/**
 @class SIR  is a class that represents  a mathematical model  simulating the spread of COVID-19 in a population before the availability of vaccines. However, the spread of COVID-19 under this model is contingent on the presence of two subgroups - a "normal" (denoted by "n") and a "moron" (denoted by "m") subpopulation within the total city population.  Each subgroup has their own potentially unique values representing their daily number of contacts, or how well each groups socially distance themselves (with normal people generally interacting with less people and therefore having a relatively lower number of daily contacts or "cn" than the number of daily contacts or "cm" of morons ). These values affect how often these subgroups may get infected or cause infections. The values of the simulation changes based on the number of days since the start of the simulated pandemic (t=0), and is increased using the step() function, which also recalculates certain values of the SIR class simulation.
 */
class SIR {
public:

    
    /**
    Constructor: Takes 8 inputs in order to create a SIR object. The inputs are described below
     
     @param _cm represents cm, or the daily number of contacts for morons people, which is assumed constant
     @param _cn represents cn, or the daily number of contacts for normal people, which is assumed constant
     @param _P represents P, or the total number of people in the city
     @param _f represents f, fraction of morons in the city
     @param _istar represents i*, or the the fraction of people who are infected at time t = 0
     @param _beta represents β, or the probability of getting COVID-19 when interacting with a sick person on a given day
     @param _gamma represents γ (gamma), daily rate people recover/die from the "ill state" and become part of the removed group
     @param _mu represents µ, or the risk reduction factor experienced by those wearing a mask
     */
    SIR (double _cm, double _cn, int _P, double _f, double _istar, double _beta, double _gamma, double _mu);
    
    /**
      increments the time value of a given SIR class, based on the inputted step size. Also overwrites several variables of the SIR class based on this input, including sn_t, sm_t, in_t, im_t, rn_t, and rm_t.
     
     @param step_size the number of days by which to increase the time member value of a SIR class's simulation
     */
    void step(const double step_size);
    
    /**
     returns the current time of a given SIR class
     
     @return the current time (in days) of the simulation as a double
     */
    const double get_time();
    
    /**
     returns the current value of sn_t of a given SIR class
     
     @return a double value representing sn_t
     */
    const double get_sn();
   
    /**
     returns the current value of rn_t of a given SIR class
     
     @return a double value representing rn_t
     */
    const double get_rn();
    
    /**
     returns the current value of sm_t of a given SIR class
     
     @return a double value representing sm_t
     */
    const double get_sm();
    
    /**
     returns the current value of im_t of a given SIR class
     
     @return a double value representing im_t
     */
    const double get_im();
    
    /**
     returns the current value of rm_t of a given SIR class
     
     @return a double value representing rm_t
     */
    const double get_rm();
    
private:
        
    // Initializes variables that will store a SIR class' cm, cn, P, f, i∗, β, γ, and μ when it is constructed
    
    double cm = 0;
    double cn = 0;
    int P = 0;
    double f = 0;
    double istar =0;
    double beta = 0;
    double gamma =0;
    double mu =0;
    
    // All of these values (except day_zero) of the class are editted each time the step() function is executed. They are initialized here with their values at t=0 days, based on the equations provided in the HW8 pdf. I set them to private since they should not be editted by the user and should only change when step() is executed
    
    const double day_zero = 0; // represents 0 days after the start of the pandemic
    double t = day_zero; // elapsed time since the start of the pandemic
    double sn_t = (1 - istar) * (1 - f); // fraction of the population who are susceptible normal people at a given time
    double in_t = (istar) * (1 - f); // the fraction of the population who are infected normal people at a given time
    double rn_t = 0; // the fraction of the population who are removed normal people at a given time
    double sm_t = (1-istar) * f; // the fraction of the population who are susceptible morons at a given time
    double im_t = istar * f; // he fraction of the population who are infected morons at a given time
    double rm_t = 0;// the fraction of the population who are removed morons at a given time
    
    // These values of the class should remain constant throughout the simulation and some are used in some of the equations within the definition for step()
    
    const double N = (1-f) * P; // number of normal people in the given population
    const double M = f * P; // number of morons in the given population
    const double psi = (N*cn) + (M*cm);
    const double psim = (M*cm)/psi;
    
};

#endif
