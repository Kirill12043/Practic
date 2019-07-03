// g++ image_thread.cpp -std=c++14 -o test
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Image
 {
  int *img;
  int mx, my;

public:

/*Image () // конструктор без параметров, создается автоматически
 {
  mx = 0;
  my = 0;
  img = (int*) malloc(sizeof(int) * mx * my);
 }*/

Image (int tmx, int tmy) // конструктор с параметрами
 {
  mx = tmx; // передали в наш класс длину изображения
  my = tmy; // передали в наш класс ширину изображения
  img = (int*) malloc(sizeof(int) * mx * my); // выделили память под размер изображения
    //for (int i = 0; i < mx*my; i++)	img[i] = 0; // мы можем проиницилизировать все 0 сразу в конструкторе
 }

~Image () // деструктор
 {
  free (img); // освободили память, выделенную малоком
 }

// так как размер изображения private, нам нужны специальные ф-ии чтобы обращаться к нему за пределами класса
int getX () {return mx;} // узнали длину
int getY () {return my;} // узнали ширину

int get (int x, int y) // узнать какой цвет в одной точке
 {
  if (x < mx && y < my && x >= 0 && y >= 0) // проверяем, не выходим ли за границы изображения
  return img[x + y*mx]; // возвращаем значение в нужной точке
 }

void set (int x, int y, int colour) // устанавливаем цыет в одну точку
 {
  if (x < mx && y < my && x >= 0 && y >= 0) // проверяем, не выходим ли за границы изображения
 	img[x + y*mx] = colour; // устанавливаем цвет в нужной точке
 }

void show () // вывод изображения на экран
 {
  for (int j = 0; j < my; j++)
  	{
   	 for (int i = 0; i < mx; i++)
       {
    	cout << img[i + j*mx] << " ";
       }
     cout << endl;
    }
  cout << endl;
 }

};

int main ()
 {
  Image a(13, 7);
  cout << "Image a" << endl;
  // цикл нужен, чтобы 0 закрасить все изображение
  for (int j = 0; j < a.getY(); j++)
    {
     for (int i = 0; i < a.getX(); i++)
       {
        a.set(i, j, 0);
       }
    }
  
  a.show();
   
  return 0;
}