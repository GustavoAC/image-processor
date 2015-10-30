#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"


int main(){
	int height, width, i, j, clrRange;
	char filetype[3], nome[50], nomeArq[55];
	header();
	
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

	
    effect_black_white(nome, height, width, image);
    create_new_file(nome, filetype, height, width, clrRange, image);
	
	return 0;
}
