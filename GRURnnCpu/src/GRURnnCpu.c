#include <stdio.h>
#include <stdint.h>

#include "Maxfiles.h"



#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>
#include "common.h"


const int hSize = 52;
const int N = 20;
const float range = 10.0;



int main(void) {
	const int matSize = hSize * hSize;
	const int sizeWz = hSize * N;

	float *Wz = malloc(hSize * N * sizeof(float));
	float *Uz = malloc(hSize * hSize * sizeof(float));
	float *Wr = malloc(hSize * N * sizeof(float));
	float *Ur = malloc(hSize * hSize * sizeof(float));
	float *Wh = malloc(hSize * N * sizeof(float));
	float *Uh = malloc(hSize * hSize * sizeof(float));



	float *xt = malloc(N * sizeof(float));
	float *ht = malloc(hSize * sizeof(float));

	float *vec = malloc(N * sizeof(float));
	float *output = malloc(hSize * sizeof(float));
	float *expected = malloc(hSize * sizeof(float));

	printf("ok");

	// it should have Xavier initialization ->> fix this!!!!
	generate_matrix(hSize, N, Wz, range);
	generate_matrix(hSize, hSize, Uz, range); // Uz
	generate_matrix(hSize, N, Wr, range); // Wxt
	generate_matrix(hSize, hSize, Ur, range); // Wht
	generate_matrix(hSize, N, Wh, range);
	generate_matrix(hSize, hSize, Uh, range);


	generate_vector(N, xt, range);
	generate_vector(hSize, ht, range);


//	generate_vector(N, vec, range);
//	generate_vector(N, vec, range);

	timing_t timer1;
	timer_start(&timer1);
	GRURnn(sizeWz, hSize, matSize, N, Uh, Ur, Uz, Wh, Wr, Wz, ht, xt, output);
	timer_stop(&timer1);

	float sum = sum_vec(hSize, output);

	printf("%d %f %ld %ld\n", hSize, sum, timer1.realtime, timer1.cputime);

	const int trace = 1;

	if (trace == 1) {
		printf("\nInput Uz matrix\n");
		for (int i=0; i<hSize; i++){
			for (int j=0; j<hSize; j++){
				printf("%f " , Uz[i*N+j]);
			}
			printf("\n");
		}
		printf("\n");

		printf("\nInput Wz matrix\n");
		for (int i=0; i<hSize; i++){
			for (int j=0; j<N; j++){
				printf("%f " , Wz[i*N+j]);
			}
			printf("\n");
		}
		printf("\n");

		printf("\nInput bz vector \n");
		for (int i=0; i<hSize; i++){
			printf("%f " , ht[i]);
		}
		printf("\n");

		printf("\nInput xt vector \n");
		for (int i=0; i < N; i++){
			printf("%f " , xt[i]);
		}
		printf("\n");

		printf("\n\nResult\n");
		for (int i=0; i<hSize; i++){
			printf("%f " , output[i]);
		}
		printf("\n");
	}
	else if (trace == 2) {
		multiply_CPU(hSize, Wz, vec, expected); // two dummy hSize, change it !!!!
		int status = check(hSize, output, expected);
		if (status)
			printf("Test failed.\n");
		else
			printf("Test passed OK!\n");
		return status;
	}

	free(Wz);
	free(Uz);
	free(Wr);
	free(Ur);
	free(Wh);
	free(Uh);
	free(ht);
	free(vec);
	free(output);
	free(expected);



    return 0;
}
