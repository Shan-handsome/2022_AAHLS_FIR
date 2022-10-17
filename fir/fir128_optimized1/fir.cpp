/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.
		Match filter
	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"
#include "ap_int.h"
typedef ap_int<5> coef_t_5;
typedef ap_int<8> data_t_8;
typedef ap_int<16>	acc_t16;
void fir (
  data_t *y,
  data_t x
  )
{

	coef_t_5 c[N] = {10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	// Write your code here
	static
	 data_t_8 shift_reg[N];
	acc_t16 acc;
	int i;

	acc = 0;
	Shift_Accum_Loop:
	for (i=N-1;i>=0;i--){
		if(i==0){
			acc += x*c[0];
			shift_reg[0] = x;
		}
		else{
			shift_reg[i]=shift_reg[i-1];
			acc += shift_reg[i]*c[i];
		}
	}
	*y = acc;

}


