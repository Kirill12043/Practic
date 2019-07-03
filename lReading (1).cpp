#include <iostream>
#include <fstream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

int reading(char* Filename, char* imagename, double wl, double hl, double wr, double hr)
{
	const char* File = Filename;
	int x, y, xm, ym;
	unsigned long t, tt;
	long double shirota, dolgota;

	ifstream f(File);
	if (!(f.is_open()))  cout << "Ошибка открытия файла" << File;
	else
	{
	 Mat img = imread(imagename);
	 cout << "Размер изображения: " << endl;
	 cout << "Ширина: " << img.size().width << endl;
	 cout << "Высота: " << img.size().height << endl;
	 //вычисляем коэффициент масштабирования
	 long double koef_mashtabW, koef_mashtabH;
	 koef_mashtabW = (wl - wr) / img.size().width;
	 koef_mashtabH = (hr - hl) / img.size().height;
	 //cout << koef_mashtabW << koef_mashtabH << endl;

	 f >> t >> x >> y;

	 cout << "Ваш путь пролегает по следующему  маршруту: " << endl;
		while (!f.eof()) 
		{
			f >> tt >> xm >> ym;
			
			//cout << "Метка времени: " << t << " x: " << x << " y: " << y << endl;
			shirota = koef_mashtabW * (img.size().width - x) + wr;
			dolgota = koef_mashtabH * (img.size().height - y) + hl;
			cout << "Метка времени: " << t << " широта: " << shirota << " долгота: " << dolgota << endl;
			
			circle(img, Point(x, y), 5, Scalar(0, 0, 255), FILLED, 8, 0);
			x = xm;
			y = ym;
			imshow("route", img);
			waitKey(tt - t);
			t = tt;
		}
	}

	f.close();
	cout << endl;
	return 0;
}