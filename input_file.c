#include <stdio.h>
#include "input_file.h"

InputFile read_input_file(const char *filename) {

	FILE *fp;
	InputFile input_file;

	fp = fopen(filename, "r");

	fscanf(fp, "(%d,%d)\n", &input_file.lake_size.width,
							&input_file.lake_size.height);

	fscanf(fp, "(%d,%d)\n", &input_file.matrix_size.L,
							&input_file.matrix_size.H);

	fscanf(fp, "%d\n", &input_file.T);
	fscanf(fp, "%d\n", &input_file.v);
	fscanf(fp, "%lf\n", &input_file.e);
	fscanf(fp, "%d\n", &input_file.n_iter);
	fscanf(fp, "%lf\n", &input_file.P);
	fscanf(fp, "%d\n", &input_file.seed);

	fclose(fp);
	return input_file;
}
