#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void my_mouse_callback(int event, int x, int y, int flags, void* param);
int reading();

int main() {
	/*Mat image = imread("map.jpg");

	namedWindow("maps");
	setMouseCallback("maps", my_mouse_callback, &image );

	while(true){
		imshow("maps",image);
		waitKey(1);}*/

	reading();

	return(0);
}

void my_mouse_callback(int event, int x, int y, int flags, void* param) 
{
	if (event == EVENT_LBUTTONDOWN) 
	 {
		Mat* pImage = (Mat*)param;
		Mat image = *pImage;
		circle(image, Point(x, y), 20, Scalar(0xff, 0xff, 0xff));
		ofstream file;
		file.open("coordinat.txt", ios_base::app);
		unsigned long milliseconds_since_epoch = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
		file << milliseconds_since_epoch << " " << x << " " << y << endl;
		file.close();

	}

}