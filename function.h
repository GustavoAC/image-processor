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

/* void open_image(){
	scanf("%s", nome);
	strcpy(nomeArq, nome);
	strcat(nomeArq, ".ppm");
	imagepath = fopen(nomeArq, "r");
	
	if(imagepath == NULL){
        system("clear");
        printf("Esse arquivo não foi encontrado.\nTente novamente:\n");
        open_image();
	}

	fgets(filetype, 3, imagepath);
	fscanf(imagepath, "%i %i %i", &height, &width, &clrRange);
	Pixel image[height][width];
	
    read_image(height, width, filetype, image);
	
	fclose(imagepath);
}
*/

int read_image(int height, int width, char filetype[3], Pixel image[height][width]){
	int i, j;
	if(filetype[0] == 'P' && filetype[1] == '3')
        for(i = 0; i < height; i++)
        	for(j = 0; j < width; j++)
        		fscanf(imagepath, "%i %i %i", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
    else {
    	system("clear");
    	printf("O tipo de arquivo PPM não é P3!\n");
    }

}

void effect_black_white(char nome[50], int height, int width, Pixel image[height][width]){
	int i, j;
	strcat(nome, "_bw.ppm");

	for(i = 0; i < height; i++)
		for(j = 0; j < height; j++){ 
			image[i][j].blue = image[i][j].green; 
			image[i][j].red = image[i][j].green;
		}	
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
