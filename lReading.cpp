#include <iostream>
#include <fstream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

int reading()
{
	const char* File = "coordinat.txt";
	int x, y, xm, ym;
	unsigned long t, tt;
	
	ifstream f(File);
	if (!(f.is_open()))  cout << "Ошибка открытия файла" << File;
	else
	{
	 Mat img = imread("map.jpg");
	 f >> t >> x >> y;

		while (!f.eof()) 
		{
			f >> tt >> xm >> ym;
			cout << "time: " << t << " x: " << x << " y: " << y << endl;
			circle(img, Point(x, y), 5, Scalar(255, 255, 255), FILLED, 8, 0);
			x = xm;
			y = ym;
			imshow("window", img);
			waitKey(tt - t);
			t = tt;
		}
	}

	f.close();
	cout << endl;
	return 0;
}