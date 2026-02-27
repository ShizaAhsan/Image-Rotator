#include <iostream>
#include "Array_T.h"
#include"image.h"
#include"/Users/User/source/repos/string oop/String.h"
using namespace std;
int main() 
{
   Array<Array<int>> mat;
   /*for (int i = 0;i < 2;i++)
   {
	   mat[i].reSize(3);

   }
   for (int i = 0;i < 2;i++)
   {
	   for (int j = 0;j < 3;j++)
	   {
		   cin>>mat[i][j];
	   }
   }*/
   int h, w, m;
   String s{ "inputX.pgm" };
   readPGM(s, mat, h,w, m);
   rotate2PGM(s, "i.pgm");
   /*for (int i = 0;i < w;i++)
   {
	   for (int j = 0;j < h;j++)
	   {
		   cout << mat[i][j]<<" ";
	   }
	   cout << " \n";
   }
	*/
}
