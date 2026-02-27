//void rotate2PGM(String  inputFileName, String outputFileName)
//{
//	Array<Array<int>> mat;
//	int h, w, max;
//	if (readPGM(inputFileName, mat, w, h, max))
//	{
//		rotateNavie(mat);
//		fstream file(&inputFileName[0]);
//
//		if (!file.is_open())
//		{
//			cout << "Error:cannot open file " << endl;
//
//
//		}
//		String format;
//		file >> format;
//		char cmnt = file.peek();
//		if (cmnt == '#')
//		{
//			file << outputFileName;
//		}
//		mat.getSize();
//		file << mat.getSize() << mat[0].getSize();
//		for (int i = 0;i < mat[0].getSize();i++)
//		{
//			for (int j = 0;j < mat.getSize();j++)
//			{
//				file >> mat[i][j];
//			}
//		}
//		file.close();
//		remove(&inputFileName[0]);
//		rename(&outputFileName[0], &inputFileName[0]);
//	}
//
//
//}
