#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename)
{
    FILE *fp = fopen(filename, "r");
    //open the file
    if (fp==NULL) { //if it cant be opened return 0
        return 0;
    }
    ImagePPM *ppm = (ImagePPM*)malloc(sizeof(ImagePPM)); //malloc a PPM

    fscanf(fp, "%s", ppm->magic);
    fscanf(fp, "%d", &ppm->numCols);
    fscanf(fp, "%d", &ppm->numRows);
    
    fscanf(fp, "%d", &ppm->maxVal);

    ppm->pixels = (Pixel **)malloc(sizeof(Pixel*) * ppm->numRows);

    for(int r = 0; r < ppm->numRows; r++){
        ppm->pixels[r] = (Pixel*)malloc(sizeof(Pixel) * ppm->numCols);
    }
    //malloc the pixel array inside the struct

    for(int r = 0; r < ppm->numRows; r++){
       for(int c = 0; c < ppm->numCols; c++){
           fscanf(fp, "%d", &ppm->pixels[r][c].red);
           fscanf(fp, "%d", &ppm->pixels[r][c].blue); 
           fscanf(fp, "%d", &ppm->pixels[r][c].green);  
       }
   }
   
   fclose(fp);

    return ppm;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename)
{
    FILE *fp = fopen(filename, "w");
    //open the file
    if (fp==NULL) { //if it cant be opened return 0
        return 0;
    }
    fprintf(fp,"%s\n",pImagePPM->magic);
    fprintf(fp,"%d\n",pImagePPM->numCols);
    fprintf(fp,"%d\n",pImagePPM->numRows);
    
    fprintf(fp,"%d\n",pImagePPM->maxVal);

    for(int r = 0; r < pImagePPM->numRows; r++){
       for(int c = 0; c < pImagePPM->numCols; c++){
           fprintf(fp, "%d ", pImagePPM->pixels[r][c].red);
           fprintf(fp, "%d ", pImagePPM->pixels[r][c].blue); 
           fprintf(fp, "%d\t", pImagePPM->pixels[r][c].green); 
       }
       fprintf(fp,"\n");
   }

    fclose(fp);
    return 1;
}

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM)
{
    for(int i = 0; i < pImagePPM->numRows; i++){
        free(pImagePPM->pixels[i]); //free each row
    }
    free(pImagePPM->pixels);
    free(pImagePPM);
}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename)
{
    FILE *fp = fopen(filename, "r");
    //open the file
    if (fp==NULL) { //if it cant be opened return 0
        return 0;
    }
    ImagePGM *pgm = (ImagePGM*)malloc(sizeof(ImagePGM)); //malloc a PGM

    fscanf(fp, "%s", pgm->magic);
    fscanf(fp, "%d", &pgm->numCols);
    fscanf(fp, "%d", &pgm->numRows);
    
    fscanf(fp, "%d", &pgm->maxVal);

    pgm->pixels = (int **)malloc(sizeof(int*) * pgm->numRows);
    for(int r = 0; r < pgm->numRows; r++){
        pgm->pixels[r] = (int*)malloc(sizeof(int) * pgm->numCols);
    }

    for(int r = 0; r < pgm->numRows; r++){
       for(int c = 0; c < pgm->numCols; c++){
           fscanf(fp, "%d", &pgm->pixels[r][c]); 
       }
   }

   fclose(fp);
   return pgm;

}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename)
{
    FILE *fp = fopen(filename, "w");
    //open the file
    if (fp==NULL) { //if it cant be opened return 0
        return 0;
    }
    fprintf(fp,"%s\n",pImagePGM->magic);
    fprintf(fp,"%d",pImagePGM->numCols);
    fprintf(fp,"%d",pImagePGM->numRows);
    
    fprintf(fp,"%d\n",pImagePGM->maxVal);

    for(int r = 0; r < pImagePGM->numRows; r++){
       for(int c = 0; c < pImagePGM->numCols; c++){
           fprintf(fp, "%d ", pImagePGM->pixels[r][c]); 
       }
       fprintf(fp,"\n");
   }
   
    fclose(fp);
    return 1;

}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM)
{
    for(int i = 0; i < pImagePGM->numRows; i++){
        free(pImagePGM->pixels[i]); //free each row
    }
    free(pImagePGM->pixels);
    free(pImagePGM);
}

ImagePGM *convertToPGM(ImagePPM *pImagePPM)
{
    ImagePGM *pgm = (ImagePGM*)malloc(sizeof(ImagePGM)); //malloc a PGM
    strcpy(pgm->magic, "P2");
    pgm->numRows = pImagePPM->numRows;
    pgm->numCols = pImagePPM->numCols;
    pgm->maxVal = pImagePPM->maxVal;

    pgm->pixels = (int **)malloc(sizeof(int*) * pgm->numRows);
    for(int r = 0; r < pgm->numRows; r++){
        pgm->pixels[r] = (int*)malloc(sizeof(int) * pgm->numCols);
    }

    for(int r = 0; r < pgm->numRows; r++){
       for(int c = 0; c < pgm->numCols; c++){
           int val = (pImagePPM->pixels[r][c].red + pImagePPM->pixels[r][c].green + pImagePPM->pixels[r][c].blue)/3;
           pgm->pixels[r][c] = val;
       }
   }

   return pgm;

}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{
    ImagePGM *pgm = (ImagePGM*)malloc(sizeof(ImagePGM)); //malloc a PGM
    strcpy(pgm->magic, "P2");
    pgm->numRows = pImagePGM->numRows/2;
    pgm->numCols = pImagePGM->numCols/2;
    pgm->maxVal = pImagePGM->maxVal;

    pgm->pixels = (int **)malloc(sizeof(int*) * pgm->numRows);
    for(int r = 0; r < pgm->numRows; r++){
        pgm->pixels[r] = (int*)malloc(sizeof(int) * pgm->numCols);
    }

    int row = 0; 
    int col = 0;

    for(int r = 0; r < pImagePGM->numRows - 1; r+=2){
        for(int c = 0; c < pImagePGM->numCols - 1; c+=2){

            int total = 0; 
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    total += pImagePGM->pixels[r + i][c + j];
                }
            }
            total = total / 4;
            pgm->pixels[row][col] = total;
            col++;
        }
        row++;
        col = 0;
    }
    return pgm;
}
