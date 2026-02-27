#ifndef IMAGE_H
#define IMAGE_H
#include"Array_T.h";
#include"/Users/User/source/repos/string oop/String.cpp"
#include<fstream>

void rotateNavie(Array<Array<int>>& mat)
{
	int rows = mat.getSize();
	int columns = mat[0].getSize();

	int rotRows = columns;
	int rotColumns = rows;

	Array<Array<int>> rotated(rotRows);
	for (int i = 0;i < rotRows;i++)
	{
		rotated[i].reSize(rotColumns);
	}
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < columns;j++)
		{
			rotated[j][rows - i - 1] = mat[i][j];
		}
	}
	mat = rotated;
}

bool readPGM(const String& filename, Array<Array<int>>& matrix, int& width, int& height, int& maxVal)
{
	ifstream file(&filename[0]);
	if (!file.is_open())
	{
		cerr << "Error:cannot open file " << filename << endl;
		return false;

	}
	String format;
	file >> format;
	if ((format == "P2") != 0)
	{
		cerr << "Error:only Ascii PGm(p2) format supported " << "\n";
		return false;
	}

	char cmnt = file.peek();
	if (cmnt == '#')
	{
		String comment;
		file >> comment;
	}
	file >> width >> height >> maxVal;
	cout << "maxval" << maxVal << "\n";
	matrix.reSize(height);
	for (int i = 0;i < matrix.getSize();i++)
	{
		matrix[i].reSize(width);

	}
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			file >> matrix[i][j];
		}
	}
	file.close();
	return true;

}
void rotate2PGM(String  inputFileName, String outputFileName)
{
	Array<Array<int>> mat;
	int h, w, max;
	if (readPGM(inputFileName, mat, w, h, max))
	{
		
		rotateNavie(mat);
		fstream file(&inputFileName[0]);

		if (!file.is_open())
		{
			cout << "Error:cannot open file " << endl;


		}
		String format{"P2"};
		file << format<<"\n";
		char cmnt = file.peek();
		if (cmnt == '#')
		{
			file << outputFileName<<"\n";
		}
		file << h <<" " << w << "\n";
		file<<max << "\n";
		mat.getSize();
		for (int i = 0;i < w;i++)
		{
			for (int j = 0;j < h;j++)
			{
				file << mat[i][j];
				if (mat[i][j] < 100)
				{
					file << "  ";
				}
				else
				{
					file << " ";
				}
			}
			file << "\n";
		}

		file.close();
		//remove(&inputFileName[0]);
	    rename( &inputFileName[0], &outputFileName[0]);
	}


}

#endif // !IMAGE_H
