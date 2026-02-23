#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void load_image(const char* filepath, unsigned char** image_data, size_t* width, size_t* height);
void save_image(const char* filepath, unsigned char* image, size_t width, size_t height);
size_t getIndiceRed(size_t x, size_t y, size_t width);
void blur(size_t x, size_t y, size_t width, int *valueRed, int *valueGreen, int *valueBlue);

int main(void)
{
	unsigned char* image = NULL;
	unsigned char* out_image = NULL;
    const char* filename = "image.ppm";
    const char* output_filename = "output.ppm";
	size_t width = 0;
	size_t height = 0;
	
    load_image(filename, &image, &width, &height);
	printf("x:%ld y:%ld\n", width, height);
	out_image = malloc((width*height*3) * sizeof(unsigned char));


    //votre code ici
	size_t x = 0;
	size_t y = 0;

	while ( x < width && y < height ){
		int valueRed;
		int valueGreen;
		int valueBlue;
		size_t indice;
		if ( x == width - 1){
			if(x != 0 && x != width && y != height && y != 0){
				blur(x, y, width, &valueRed, &valueGreen, &valueBlue, image);
				out_image[indice] = valueRed;
				out_image[indice+1] = valueGreen;
				out_image[indice+2] = valueBlue;
			}
			y += 1;
			x = 0;
		}else{
			if(x != 0 && x != width && y != height && y != 0){
				blur(x, y, width, &valueRed, &valueGreen, &valueBlue, image);
				out_image[indice] = valueRed;
				out_image[indice+1] = valueGreen;
				out_image[indice+2] = valueBlue;
			}
			x+=1;
		}
	}

	// size_t a = getIndiceRed(x-1, y-1, width);
	// size_t b = getIndiceRed(x, y-1, width);
	// size_t c = getIndiceRed(x+1, y-1, width);
	// size_t d = getIndiceRed(x-1, y, width);
	// size_t e = getIndiceRed(x, y, width);
	// size_t f = getIndiceRed(x+1, y, width);
	// size_t g = getIndiceRed(x-1, y+1, width);
	// size_t h = getIndiceRed(x, y+1, width);
	// size_t i = getIndiceRed(x+1, y+1, width);

    // int valueRed = (image[a] + image[b] + image[c] + image[d] + image[e] + image[f] + image[g] + image[h] + image[i]) / 9;
	// int valueGreen = (image[a+1] + image[b+1] + image[c+1] + image[d+1] + image[e+1] + image[f+1] + image[g+1] + image[h+1] + image[i+1]) / 9;
	// int valueBlue = (image[a+2] + image[b+2] + image[c+2] + image[d+2] + image[e+2] + image[f+2] + image[g+2] + image[h+2] + image[i+2]) / 9;


	// out_image[e] = valueRed;
	// out_image[e+1] = valueGreen;
	// out_image[e+2] = valueBlue;


	save_image(output_filename, out_image, width, height);
	free(image);
    free(out_image);
	return 0;
}

size_t getIndiceRed(size_t x, size_t y, size_t width){
	return ((y - 1) * width + (x - 1)) * 3;
}

void blur(size_t x, size_t y, size_t width, int *valueRed, int *valueGreen, int *valueBlue){
	size_t a = getIndiceRed(x-1, y-1, width);
	size_t b = getIndiceRed(x, y-1, width);
	size_t c = getIndiceRed(x+1, y-1, width);
	size_t d = getIndiceRed(x-1, y, width);
	size_t e = getIndiceRed(x, y, width);
	size_t f = getIndiceRed(x+1, y, width);
	size_t g = getIndiceRed(x-1, y+1, width);
	size_t h = getIndiceRed(x, y+1, width);
	size_t i = getIndiceRed(x+1, y+1, width);

	*valueRed = (image[a] + image[b] + image[c] + image[d] + image[e] + image[f] + image[g] + image[h] + image[i]) / 9;
	*valueGreen = (image[a+1] + image[b+1] + image[c+1] + image[d+1] + image[e+1] + image[f+1] + image[g+1] + image[h+1] + image[i+1]) / 9;
	*valueBlue = (image[a+2] + image[b+2] + image[c+2] + image[d+2] + image[e+2] + image[f+2] + image[g+2] + image[h+2] + image[i+2]) / 9;
}

//Vous n'avez pas besoin de comprendre les lignes qui suivent

char* readline(int fd)
{
	int offset = 0;
	size_t size;
	char dummy;
	do {
		size = read(fd,&dummy,1);
		offset += size;
	} while(size != 0 && dummy != '\n' && dummy != EOF);

	char* line = malloc(offset * sizeof(char)+1);
	lseek(fd,-offset,SEEK_CUR);
	read(fd,line,offset);
	line[offset]='\0';
	return line;
}

void load_image(const char* filepath, unsigned char** image_data, size_t* width, size_t* height)
{
	int fd = open(filepath,O_RDONLY);
	if (fd == -1)
	{
		perror("Can't open input file");
		exit(-1);
	}
	char* line = readline(fd);
	if ( strncmp("P6", line, 2) != 0)
	{
		fputs("Input File is not a ppm file\n", stderr);
		free(line);
		exit(-1);
	}
	free(line);
	do {
		line = readline(fd);
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		int success = sscanf(line,"%lu %lu",width,height);
		if (success != 2)
		{
			fputs("Input File is not a valid ppm file\n", stderr);
			free(line);
			exit(-1);
		}
		free(line);
	} while(*width == 0);
	int dummy = 0;
	do {
		line = readline(fd);
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		int success = sscanf(line,"%d",&dummy);
		if (success != 1)
		{
			fputs("Input File is not a valid ppm file\n", stderr);
			free(line);
			exit(-1);
		}
		free(line);
	} while(dummy == 0);

	unsigned data_size = 3 * (*width) * (*height);
	*image_data = malloc(data_size * sizeof(unsigned char));

    read(fd,*image_data,3*(*width)*(*height));
}

void save_image(const char* filepath, unsigned char* image, size_t width, size_t height)
{
	int fd = open(filepath,O_CREAT|O_WRONLY,0644);
	if (fd == -1)
	{
		perror("Can't open output file");
		exit(-1);
	}
	write(fd,"P6\n",3);
	char* size = NULL;
	asprintf(&size,"%lu %lu\n",width, height);
	write(fd,size,strlen(size));
	free(size);
	write(fd,"255\n",4);
    usleep(500000);
    write(fd,image,3*width*height);
	write(fd,"\n",1);
	close(fd);

}

