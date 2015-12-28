#ifndef INPUT_FILE
#define INPUT_FILE

/* Estrutura para o tamanho do lago */
typedef struct {
	unsigned int width;	/* Largura do lago */
	unsigned int height; /* Altura do lado */
} LakeSize;

/* Estrutura do tamanho da matriz */
typedef struct {
	unsigned int L;
	unsigned int H;
} MatrixSize;

/* Estrutura do arquivo de entrada */
typedef struct {
	LakeSize lake_size;
	MatrixSize matrix_size;
	unsigned int T;
	unsigned int v;
	double e;
	unsigned int n_iter;
	double P;
	unsigned int seed;
} InputFile;


InputFile read_input_file(const char *filename);


#endif
