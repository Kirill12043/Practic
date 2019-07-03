#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <string>
#include <cstring>
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;
using namespace cv;
using namespace std;

void my_mouse_callback(int event, int x, int y, int flags, void* param);
int reading(char* Filename, char* imagename, double wl, double hl, double wr, double hr);

int main(int argc, char** argv) {
	// устанвливаем русскую локаль для консоли
	setlocale(LC_ALL, "Russian");
	
	// read a JSON file
	std::ifstream i("config.json");
	json j;
	i >> j;

	string image_name = j.at("imageName").get<string>();
	cout << "imageName = " << image_name << '\n';
	string file_name = j.at("fileName").get<string>();
	cout << "fileName = " << file_name << '\n';
	double cordwidthL = j.at("cord_widthL").get<double>();
	cout << "cord_widthL = " << cordwidthL << '\n';

	double cordheightL = j.at("cord_heightL").get<double>();
	cout << "cord_heightL = " << cordheightL << '\n';

	double cordwidthR = j.at("cord_widthR").get<double>();
	cout << "cord_widthR = " << cordwidthR << '\n';

	double cordheightR = j.at("cord_heightR").get<double>();
	cout << "cord_heightR = " << cordheightR << '\n';

	CommandLineParser parser(argc, argv,
		"{ @image | Dzerzhinsky.png | изображение карты}"
		"{ @text  | coordinat.txt   | файл, в который записывать координаты }"
		"{ cord_widthL  | 55.639799 | широта левой точки}"
		"{ cord_heightL | 37.828428 | долгота левой точки}"
		"{ cord_widthR  | 55.622020 | широта правой точки}"
		"{ cord_heightR | 37.873735 | долгота правой точки}"
	);
	string filename = samples::findFile(parser.get<string>("@image"));
	char* imagename = new char[filename.length() + 1];
	strcpy_s(imagename, filename.length() + 1, filename.c_str());

	string textname = samples::findFile(parser.get<string>("@text"));
	char* traectory_file = new char[textname.length() + 1];
	strcpy_s(traectory_file, textname.length() + 1, textname.c_str());

	double wl = parser.get<double>("cord_widthL");
	double hl = parser.get<double>("cord_heightL");
	double wr = parser.get<double>("cord_widthR");
	double hr = parser.get<double>("cord_heightR");
	
	reading(traectory_file, imagename, wl, hl, wr, hr);
		
	/*Mat image = imread(filename);
	
	namedWindow("modernGoogle");
	setMouseCallback("modernGoogle", my_mouse_callback, &image);

	while(true){
		imshow("modernGoogle",image);
		waitKey(30);}*/
	return(0);
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
 if (event == EVENT_LBUTTONDOWN) 
  {
	Mat* pImage = (Mat*)param;
	Mat image = *pImage;
	circle(image, Point(x, y), 5, Scalar(255, 0, 0), FILLED, 8, 0);
	ofstream file;
	file.open("coordinat.txt", ios_base::app);
	unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	file << milliseconds_since_epoch << " " << x << " " << y << endl;
	file.close();
  }
}

/*char filename[100]; // Dzerzhinsky.png
cout << "Введите имя файла, в который хотите внести изменения, и нажмите Enter" << endl;
cin.getline(filename, 100);
cout << "Открыт файл ";
cout << filename << endl;*/


