#ifndef TREMOLO_
#define TREMOLO_

/*
extern void Tremolo_init(short effect_rate,double depth);
extern double Tremolo_process(double xin);
extern void Tremolo_sweep(void);
*/
extern void Tremolo_init(short effect_rate,long depth);
extern signed long int Tremolo_process(signed long int xin);
extern void Tremolo_sweep(void);
extern void Tremolo_init2();
extern signed long int Tremolo_process2(signed long int xin,short,long);
extern void Tremolo_sweep2(short);

#endif
