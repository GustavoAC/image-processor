typedef struct{
	int red;
	int green;
	int blue;
} Pixel;


void header(){
	system("clear");
	printf("Bem vindo ao programa!\n");
	printf("Dígite o nome do seu arquivo (sem extensão)");
	printf("\t(Exemplo: lena)\n");
}

void read_image(int height, int width, char filetype[], Pixel image[height][width], FILE *imagepath){
	int i, j;

	if(filetype[0] == 'P' && filetype[1] == '3')
        for(i = 0; i < height; i++)
        	for(j = 0; j < width; j++)
        		fscanf(imagepath, "%i %i %i", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
    else {
    	system("clear");
    	printf("O tipo de arquivo PPM não é P3!\n");
    	exit(1);
    }

    fclose(imagepath);

}

void effect_black_white(char nome[50], int height, int width, Pixel image[height][width]){
	int i, j, gray;
	strcat(nome, "_bw.ppm");

	for(i = 0; i < height; i++)
		for(j = 0; j < height; j++){
			gray = (image[i][j].blue + image[i][j].green + image[i][j].red)/3;
			image[i][j].blue = gray;
			image[i][j].red = gray;
			image[i][j].green = gray;
		}
}

void ef_thresholding(char nome[50], int height, int width, int *clrRange, Pixel image[height][width]){
	int i, j, gray;
	strcat(nome, "_thr.ppm");
	for(i = 0; i < height; i++)
		for(j = 0; j < height; j++){
			gray = (image[i][j].blue + image[i][j].green + image[i][j].red)/3;
			if(gray > *clrRange/2){
                image[i][j].blue = 1;
                image[i][j].green = 1;
                image[i][j].red = 1;
			}else{
                image[i][j].blue = 0;
                image[i][j].green = 0;
                image[i][j].red = 0;
			}
		}

    *clrRange = 1;
}
void create_new_file(char nome[50], char filetype[3], int height, int width, int clrRange, Pixel image[height][width]){
	int i, j;
	FILE *newfile;
	newfile = fopen(nome, "w");
	fprintf(newfile, "%s\n%i %i\n%i\n", filetype, height, width, clrRange);
	for(i = 0; i < height; i++)
		for(j = 0; j < height; j++)
        	fprintf(newfile, "%i %i %i ", image[i][j].red, image[i][j].green, image[i][j].blue);

    system("clear");
    printf("O arquivo %s foi criado com sucesso na pasta raíz do programa.\n", nome);
}


/*

void print_options(){
	printf("thr // Thresholding");
}

void controller(){

}

*/
