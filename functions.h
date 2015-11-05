void header(){
	system("clear");
	printf("Bem vindo ao programa!\n");
	printf("Dígite o nome do seu arquivo (sem extensão)");
	printf("\t(Exemplo: lena)\n");
}

FILE *open_image(char name[]){
    printf("cheguei");
	FILE *file = fopen(name, "r");
	printf("cheguei");
	if(file == NULL){
        printf("cheguei");
		system("clear");
		printf("Esse arquivo não foi encontrado.\nTente novamente:\n");
		exit(1);
	}
	printf("cheguei");
	return file;
}

void read_image(Pixel image[height][width], FILE *imagepath){
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

void effect_black_white(Pixel image[height][width]){
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

void ef_thresholding(Pixel image[height][width]){
	int i, j, gray;
	strcat(nome, "_thr.ppm");
	for(i = 0; i < height; i++)
		for(j = 0; j < height; j++){
			gray = (image[i][j].blue + image[i][j].green + image[i][j].red)/3;
			if(gray > clrRange/2){
                image[i][j].blue = 1;
                image[i][j].green = 1;
                image[i][j].red = 1;
			}else{
                image[i][j].blue = 0;
                image[i][j].green = 0;
                image[i][j].red = 0;
			}
		}

    clrRange = 1;
}
void create_new_file(Pixel image[height][width]){
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


void print_options(){
	system("clear");	
	printf("== Pressione a opção desejada ==");
	printf("1- thr // Thresholding");
	printf("2- bw  // Black & White");
	printf("================================");
}

void controller(int choice){

}


