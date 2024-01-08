#include <stdio.h>
#include<stdlib.h>
#define MIN_HEADER_SIZE 54
#define WIDTH 18
#define HEIGHT 22
#define OFFSET 10
#define SIZE 2

void readBMP(char header[54], char **otherData, char **pixelDataPadded,long long int *width,long long int *height,long long int * otherDataSize, long long int* sizeOfPadding);
void rotateBMP(char **rotatedPixelData,char header[MIN_HEADER_SIZE],char*pixelDataPadded,long long int width, long long int height,long long int oldPadding, long long int * newPixelWidthPadded,long long int * newHeight);
void writeBMP(char * header, char * rotatedPixelData, char * otherData, long long int otherDataSize,long long int newPixelWidthPadded,long long int newHeight); 

int main(){
  char header[54];
  char *otherData,*pixelDataPadded, * finalPixelData;

  long long int width, height, otherDataSize, sizeOfPadding, newPixelWidthPadded, newHeight;
  readBMP(header, &otherData, &pixelDataPadded,&width,&height, &otherDataSize,&sizeOfPadding);

  rotateBMP(&finalPixelData,header,pixelDataPadded,width,height,sizeOfPadding, &newPixelWidthPadded, &newHeight);

  writeBMP(header,finalPixelData,otherData,otherDataSize, newPixelWidthPadded, newHeight);
}

void readBMP(char header[54], char **otherData, char **pixelDataPadded,long long int *width,long long int *height, long long int * otherDataSize,long long int* sizeOfPadding){

//Reads header
  int read = fread(header, MIN_HEADER_SIZE, 1, stdin);
  if(read != 1){
    fprintf(stderr, "Could not read headers, they are %d\n", read);
    exit(1);
  }
  if(header[0] != 'B' || header[1] != 'M'){
    fprintf(stderr, "Not a BMP file\n");
    exit(1);
  }


//Reads otherData
  int offset = *(int*)(header + OFFSET);
  *otherDataSize = offset - MIN_HEADER_SIZE;
  *otherData = malloc(*otherDataSize);
  int read2 = fread(*otherData, *otherDataSize, 1,stdin);
  // if(read2!= 1){
  //   exit(1);
  // }

//Reads pixelData
  *width = *(int*)&header[18];
  *height = *(int*)&header[22];

  //Goes to the greater and closest multple of four of width to add the padding;
  int pixelWidth = (*width)*3 /*because of RGB*/;
  int remainder = pixelWidth % 4;
  *sizeOfPadding = 4 - remainder;
  int pixelWidthPadded = pixelWidth + *sizeOfPadding;

  int pixelDataPaddedSize = (*height) * pixelWidthPadded;

  // fprintf(stderr, "pixelDataPaddedSize is : %d \n", pixelDataPaddedSize);
  
  *pixelDataPadded = malloc(pixelDataPaddedSize + 1);
  int read3 = fread(*pixelDataPadded, pixelDataPaddedSize,1, stdin);
  // if(read3!= 1){
  //     exit(1);

  //   }
              // fprintf(stderr, "pdp1 is : %c \n", *pixelDataPadded[1]);

}

void rotateBMP(char **finalPixelData,char header[MIN_HEADER_SIZE],char*pixelDataPadded, long long int width, long long int height, long long int oldPadding, long long int * newPixelWidthPadded, long long int * newHeight){
//changes header width to height
  *(int*)(header + WIDTH) = height;
  *(int*)(header + HEIGHT) = width;
  *newHeight = width;
  long long int newWidth = height;

  //fprintf(stderr,"header is %d", *(int*)&header[WIDTH]);

//Rotates Pixel Data
  //Removes Old Padding
  char * pixelData = malloc(3*width*height + 1);
  long long int index = 0;
    for (long long int i = 0; i < height; i++) {
        for (long long int j = 0; j < width*3; j++) {

            //fprintf(stderr, "pdp1 of %d is : %x \n",index, pixelDataPadded[1]);

            pixelData[index] = pixelDataPadded[i * (3*width + oldPadding) + j];
            index++;
        }
    }

  //rotates pixelData
  char * rotatedPixelData = malloc(3*width*height);

  long long int index2 = 0;
  for(long long int i = 0; i<width; i++){
    for(long long int j = height -1;j >=0; j--){




    rotatedPixelData[index2++] = pixelData[j*3*width + 3*i];
    rotatedPixelData[index2++] = pixelData[j*3*width + 3*i + 1];
    rotatedPixelData[index2++] = pixelData[j*3*width + 3*i + 2];
    }
  }

  //Finds the new padding Size
  long long int newPixelWidth = newWidth*3;
  long long int remainder = newPixelWidth % 4;
  long long int sizeOfPadding;
  if(remainder == 0){
      sizeOfPadding = 0;
  }
  else{
      sizeOfPadding = 4 - remainder;
  } 
  * newPixelWidthPadded = newPixelWidth + sizeOfPadding;

  //Adds padding to rotatedPixelData and creates the finalPixelData
  *finalPixelData = malloc((*newPixelWidthPadded) * (*newHeight));

//long long int testt = 0;

  long long int index3 = 0;
  for(long long int i = 0; i< *newHeight; i++){
    for(long long int j = 0; j<newPixelWidth; j++){
        (*finalPixelData)[index3++] = rotatedPixelData[i*newPixelWidth + j]; 
    }
    for(long long int k = 0; k<sizeOfPadding; k++){
     (*finalPixelData)[index3++] = 0/*it can be any value*/; 

      //testt++;
      //fprintf(stderr, "%lld\n", testt);

    }
  }
}

      //fprintf(stderr, "%lld\n", k);

void writeBMP(char * header, char * rotatedPixelData, char * otherData, long long int otherDataSize, long long int newPixelWidthPadded, long long int newHeight){



  fwrite(header,MIN_HEADER_SIZE,1,stdout);
  fwrite(otherData, otherDataSize, 1, stdout);
  fwrite(rotatedPixelData, newPixelWidthPadded*newHeight, 1, stdout);



  
}



  //Τα πιο όμορφα structs είναι τα ωραίys;
