/*GARDIENS*/
#ifndef MT_H
#define MT_H

#include <stdio.h>
#include <stdlib.h>


void init_genrand(unsigned long s) ;    /* initializes mt[N] with a seed */

void init_by_array(unsigned long init_key[], int key_length) ; /* initialize by an array with array-length */

double genrand_real1(void);           /* generates a random number on [0,1]-real-interval */

double genrand_real2(void);           /* generates a random number on [0,1)-real-interval */

double genrand_real3(void);           /* generates a random number on (0,1)-real-interval */     

unsigned long genrand_int32(void);    /*generates a random number on [0,0xffffffff]-int-interval*/

double uniform(double a, double b);         /*generates a random number on [a,b]-real-interval*/


#endif
