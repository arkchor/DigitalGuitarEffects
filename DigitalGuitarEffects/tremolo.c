#include "tremolo.h"

//static double dep;
static long dep;
static short counter_limit;
static short control;
static short mod;
//static double offset;
//static long offset;

void Tremolo_init(short effect_rate,long depth) {
    dep     = depth; 
    control = 1;
    mod     = 0;
    counter_limit = effect_rate;
    //offset  = 1 - dep;
}
void Tremolo_init2() { 
    control = 1;
    mod     = 0;
}
/*
double Tremolo_process(double xin) {
    double yout;
    double m;

    m = (double)mod*dep/counter_limit;
    yout = (m + offset)*xin;
    return yout;
}

void Tremolo_sweep(void) {

            mod += control;
  
            if (mod > counter_limit) {
                control = -1;
            } 
            else if(!mod) {
                control = 1;
            }
}
*/

signed long int Tremolo_process(signed long int xin) {
    signed long int yout;
    signed long int m;

    m = mod*dep/counter_limit;
    //yout = (m + offset)*xin;
    yout = m * xin;
    return yout;
}

void Tremolo_sweep(void) {

            mod += control;
  /*
            if (mod > counter_limit) {
                control = -1;
            } 
            else if(!mod) {
                control = 1;
            }
            */
            if (mod > counter_limit && control == 1) {
                control = -1;
            } 
            else if(mod == 0 && control == -1) {
                control = 1;
            }
}

signed long int Tremolo_process2(signed long int xin,short counter_limit,long dep) {
    signed long int yout;
    signed long int m;

    m = mod*dep/counter_limit;
    //yout = (m + offset)*xin;
    yout = m * xin;
    return yout;
}

void Tremolo_sweep2(short counter_limit) {

            mod += control;
  /*
            if (mod > counter_limit) {
                control = -1;
            } 
            else if(!mod) {
                control = 1;
            }
            */
            if (mod > counter_limit && control == 1) {
                control = -1;
            } 
            else if(mod == 0 && control == -1) {
                control = 1;
            }
}
