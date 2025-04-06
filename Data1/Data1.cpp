// Data1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

typedef struct {
	unsigned short int type; /* BMP type identifier */
	unsigned int size; /* size of the file in bytes*/
	unsigned short int reserved1, reserved2;
	unsigned int offset; /* starting address of the byte */
} HEADER;

typedef struct {
	unsigned int size; /* Header size in bytes */
	int width, height; /* Width and height in pixels */
	unsigned short int planes; /* Number of color planes */
	unsigned short int bits; /* Bits per pixel */
	unsigned int compression; /* Compression type */
	unsigned int imagesize; /* Image size in bytes */
	int xresolution, yresolution; /* Pixels per meter */
	unsigned int ncolors; /* Number of colors */
	unsigned int importantcolors; /* Important colors */
} INFO;

struct node {
	unsigned int var1;
	char* var2;
} ;

typedef struct {
	unsigned char R, G, B; // stores a value between 0-255 representing the color depth
	int x, y;
} _2Dpoint;

int foo( INFO* const ptr) {

	int tmp = ptr->width;
	return 0;
}
int main()
{	
	INFO info;
	node mynode;
	node* ptr = &mynode;
	ptr -> var1 = 100;
	ptr -> var2 = (char*) malloc(20); 
	_2Dpoint A[100];

	foo(&info);
	void* bmp_ptr = malloc(54);
	FILE* file = fopen("image.bmp", "r");
	if (file == NULL) {
		printf("Error opening file!\n");
		return 2;
	}

	void* bmp_ptr = malloc(54);//allocate memory for 54 bytes
	fread(ptr, 54, 1, file); //read 54 bytes of memory
	fclose(file); //close file

	int width = *(int*)(ptr + 18);
	int height = *(int*) (ptr + 22);

}

 //Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
