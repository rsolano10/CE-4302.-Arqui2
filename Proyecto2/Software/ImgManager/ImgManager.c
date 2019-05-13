#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>   // for uint32_t
#include <limits.h>   // for CHAR_BIT
// #define NDEBUG
#include <assert.h>

#define TRUE 1
#define FALSE 0

#define INPUT 1  // argument pos for input
#define OUTPUT 2 // argument pos for output

int numberOfBands, numberOfColumns, numberOfRows, highVal, totalPixels;

// Functions
void readImage(char **argv, unsigned char **image);
void writeImage(char *output,unsigned char **image);
void printImage(unsigned char **image);
void StoreImage(unsigned char **image);

// Read image
void readImage(char **argv, unsigned char **image)
{

    // Define needs of implementation
    FILE *fpIn;
    char *string;
    int doneReading = FALSE;
    char c;
    int header;
    unsigned char *image1;

    // Open file
    fpIn = fopen(argv[INPUT], "rb");

    //Verify if file could be oppened
    if (fpIn == NULL)
    {
        perror("Such a file does not exist...");
        return;
    }

    // Allocate neccesary memmory
    string = (char *)calloc(256, 3);

    // Verify if is a color image.
    while (!doneReading && (c = (char)fgetc(fpIn)) != '\0')
        switch (c)
        {
        case 'P':
            c = (char)fgetc(fpIn);
            switch (c)
            {
            case '2': // pgm plain
                header = 2;
                numberOfBands = 1;
                break;
            case '5': // pgm Normal
                header = 5;
                numberOfBands = 1;
                break;
            case '3': // ppm plain
                header = 3;
                numberOfBands = 3;
                break;
            case '6': // ppm Normal
                header = 6;
                numberOfBands = 3;
                break;
            }
            c = (char)fgetc(fpIn);
            if (c != 0x0A)
            {
                ungetc(c, fpIn);
            }
            else
            {
                ungetc(c, fpIn);
                fgets(string, 256, fpIn);
            }
            break;
        case '#':
            fgets(string, 256, fpIn);
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            ungetc(c, fpIn);
            fscanf(fpIn, "%d %d %d", &(numberOfColumns), &(numberOfRows), &(highVal));
            doneReading = TRUE;
            fgetc(fpIn);
            break;
        }

    totalPixels = numberOfRows * numberOfColumns; // get the total of pixels

    (*image) = (unsigned char *)malloc(totalPixels); // reserve memory for image

    if (numberOfBands != 1) // verify if the image is not in gray colors
    {
        image1 = (unsigned char *)malloc(totalPixels * 3);
        fread(image1, 1, totalPixels * 3, fpIn);
        int count = 0;

        for (int a = 0; a < totalPixels * 3; a += 3)
        {
            int gray = (image1[a] + image1[a + 1] + image1[a + 2]) / 3; // get gray of color
            (*image)[count] = gray;
            count++;
        }

        free(image1);
    }
    else
    {
        fread((*image), 1, totalPixels, fpIn);
    }
}

// Write a image
void writeImage(char *output, unsigned char **image)
{
    FILE *fpOut;
    fpOut = fopen(output, "wb");

    //verify if file could be oppened
    if (fpOut == NULL)
    {
        perror("Error couldn't write the image ");
        return;
    }

    // Write File
    fprintf(fpOut, "P%d\n%d %d\n%d\n", 5, numberOfColumns, numberOfRows, highVal);
    fwrite((*image), 1, totalPixels, fpOut);
    //free((*image));
    printf("Image Wrote\n");
}

void printMatrix(unsigned char **image)
{

    int pixels[numberOfRows][numberOfColumns]; // create a matrix of image rows and columns
    int cont = 0;
    // store pixels inside matrix
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            pixels[i][j] = (int)(*image)[cont];
            cont++;
        }
    }

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            printf("|%i|", pixels[i][j]);
        }
        printf("\n");
    }
}

// Write a image
void writeMatrix(char *output, unsigned char **image)
{

    FILE *f = fopen(output, "wb");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int cont = 0;
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            int temp = (*image)[cont];
            if(temp < 10){
                fprintf(f, "|%d  |", temp);
            }
            else if(temp < 100){
                fprintf(f, "|%d |", temp);
            }
            if(temp < 1000){
                fprintf(f, "|%d|", temp);
            }
            
            cont++;
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

void xorimg(unsigned char **image){

    for (int j = 0; j < totalPixels; j++)
        {
            (*image)[j] = (int) ((*image)[j] ^ 134);
        }
}

void sumimg(unsigned char **image){

    for (int j = 0; j < totalPixels; j++)
        {
            (*image)[j] = (int) ((*image)[j] + 100);
        }
}

void restimg(unsigned char **image){

    for (int j = 0; j < totalPixels; j++)
        {
            (*image)[j] = (int) ((*image)[j] - 100);
        }
}

static inline uint32_t rotl32 (uint32_t n, unsigned int c)
{
  const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);  // assumes width is a power of 2.

  // assert ( (c<=mask) &&"rotate by type width or more");
  c &= mask;
  return (n<<c) | (n>>( (-c)&mask ));
}

static inline uint32_t rotr32 (uint32_t n, unsigned int c)
{
  const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);

  // assert ( (c<=mask) &&"rotate by type width or more");
  c &= mask;
  return (n>>c) | (n<<( (-c)&mask ));
}

void shiftleft(unsigned char **image){

    for (int j = 0; j < totalPixels; j++)
        {
            
            (*image)[j] = ( (*image)[j] << 1 ) + ( (*image)[j] >> 7 );
        }
}

void shiftright(unsigned char **image){

    for (int j = 0; j < totalPixels; j++)
        {
            (*image)[j] = ( (*image)[j] >> 1 ) + ( (*image)[j] << 7 );
        }
}

//Funcion principal
int main(int argc, char **argv)
{
    if (argc < 1)
        return -1;

    unsigned char *image2;

    readImage(argv, &image2);

    writeImage("original.pgm",&image2);

    writeMatrix("original.txt",&image2);

    xorimg(&image2);

    writeImage("xor.pgm",&image2);

    writeMatrix("xor.txt",&image2);

    xorimg(&image2);

    writeImage("xor_return.pgm",&image2);

    writeMatrix("xor_return.txt",&image2);

    sumimg(&image2);

    writeImage("sum.pgm",&image2);

    writeMatrix("sum_return.txt",&image2);

    restimg(&image2);

    writeImage("rest.pgm",&image2);

    writeMatrix("rest_return.txt",&image2);

    shiftleft(&image2);

    writeImage("left.pgm",&image2);

    writeMatrix("left_return.txt",&image2);

    shiftright(&image2);

    writeImage("right.pgm",&image2);

    writeMatrix("right_return.txt",&image2);

        //initDataMem();

        //StoreImage(&image2);

        //printf("%i\n",readDataMem(639999));

        //printMatrix(&image2);

        //printf("rows: %i, columns: %i\n",numberOfRows,numberOfColumns);

        return 0;
}