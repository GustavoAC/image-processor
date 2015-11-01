#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

int main(){
    FILE *imagepath;
	int height, width, clrRange;
	char filetype[3], nome[50], nomeArq[55];
	header();

	scanf("%s", nome);
	strcpy(nomeArq, nome);
	strcat(nomeArq, ".ppm");
	imagepath = fopen(nomeArq, "r");

	if(imagepath == NULL){
		system("clear");
		printf("Esse arquivo não foi encontrado.\n");
		exit(1);
	}

	fgets(filetype, 3, imagepath);
	fscanf(imagepath, "%i %i %i", &height, &width, &clrRange);
    Pixel image[height][width];
    read_image(height, width, filetype, image, imagepath);

    ef_thresholding(nome, height, width, &clrRange, image);
    create_new_file(nome, filetype, height, width, clrRange, image);

	return 0;
}
