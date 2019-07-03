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
	// устанвливаем русскую локаль для консоли
	setlocale(LC_ALL, "Russian");

	char filename[100]; // dragon.jpg
	cout << "Введите имя файла, в который хотите внести изменения, и нажмите Enter" << endl;
	cin.getline(filename, 80);
	cout << "Открыт файл ";
	cout << filename << endl;

    Mat image = imread(filename);
    Rect drecte = Rect(275,10,400,500);
    rectangle(image, drecte, Scalar(255,0,0), 20, 8, 0);
	
	Rect hrecte = Rect(950, 330, 250, 290);
	rectangle(image, hrecte, Scalar(0, 0, 255), 20, 8, 0);

	char newfilename[100]; // dragon_new.jpg
	cout << "Введите имя файла, в который хотите сохранить изменения, и нажмите Enter" << endl;
	cin.getline(newfilename, 80);
	cout << "Создан файл ";
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