#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{
	// ������������ ������� ������ ��� �������
	setlocale(LC_ALL, "Russian");

	char filename[100]; // dragon.jpg
	cout << "������� ��� �����, � ������� ������ ������ ���������, � ������� Enter" << endl;
	cin.getline(filename, 80);
	cout << "������ ���� ";
	cout << filename << endl;

    Mat image = imread(filename);
    Rect drecte = Rect(275,10,400,500);
    rectangle(image, drecte, Scalar(255,0,0), 20, 8, 0);
	
	Rect hrecte = Rect(950, 330, 250, 290);
	rectangle(image, hrecte, Scalar(0, 0, 255), 20, 8, 0);

	char newfilename[100]; // dragon_new.jpg
	cout << "������� ��� �����, � ������� ������ ��������� ���������, � ������� Enter" << endl;
	cin.getline(newfilename, 80);
	cout << "������ ���� ";
	cout << newfilename << endl;

    imwrite(newfilename, image);
    imshow("result", image);
    while (1)
	{
     if (waitKey(30)==27)
      break;
    }
    
    return 0;
}