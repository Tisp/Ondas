#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "util.h"
#include "input_file.h"
#include "simulation.h"

typedef unsigned char pixel_t[3]; // colors [R, G ,B]


int main(int argc, char const *argv[]) {

    if(argc != 3) {
        printf("Numero de argumentos invalidos\n");
        printf("Ex: %s <input file> <num processadores>\n", argv[0]);
        exit(1);
    }


    /* Numero de processadores */
    int num_proc = atoi(argv[2]);

    /* Le o arquivo de entrada */
    InputFile input_file = read_input_file(argv[1]);

    int image_height = input_file.lake_size.height;
    int image_width = input_file.lake_size.width;

    pixel_t *pixels = malloc(sizeof(pixel_t) * image_height * image_width);

    int L = input_file.matrix_size.L;
    int H = input_file.matrix_size.H;

    double matrix[L][H];
    memset(matrix, 0, L * H * sizeof(double));


    int i, j, N;

    double ts = (double)input_file.T / (double)input_file.n_iter;
    double timestep = ts;
    
    /* Semente para numero aleatorios */
    srand(input_file.seed);

    for(N = 0; N < input_file.n_iter; N++) {

      int r = rand() % 100;
      /* Verifica se cai uma gota */
      if(r < input_file.P) {

      printf("%d\n", r);
          /* Sortea a posicao da gota */
          int x = rand() % L;
          int y = rand() % H;

          for(i = 0; i < L; i++) {

              for (j = 0; j < H; j++) {
                    double dist = distance(i, x, j, y);
                   double wp = wave_propagation(dist, timestep , input_file.v);
                    if(wp > input_file.e){
                        matrix[i][j] = wp;
                    }
              }
          }
      }

      timestep += ts;
   }

   for (i = 0; i < image_height; i++) {
       for (j = 0; j < image_width; j++) {
            if(matrix[i][j] > 0) {
	  	pixels[i * image_width + j][0] = 255;
           	pixels[i * image_width + j][1] = 0;
            	pixels[i * image_width + j][2] = 0;
	   
	    } else {
            	pixels[i * image_width + j][0] = 0;
           	pixels[i * image_width + j][1] = 0;
            	pixels[i * image_width + j][2] = 0;
	   }
       }
   }


   FILE *fp = fopen("ondas_irreais.ppm", "wb");
   fprintf(fp,"P6\n %s\n %d\n %d\n %d\n","# no comment",
           image_width,image_height,255);

   fwrite(pixels,sizeof(pixel_t),image_height * image_width,fp);
   fclose(fp);
   free(pixels);




    return 0;
}
