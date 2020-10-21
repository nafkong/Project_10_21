#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat image1 = imread("Ó²±Ò.jpg");
	Mat image,image2,image_erode, image_dilate, image_open, image_colse, image_tophat;
	cvtColor(image1, image2, COLOR_BGR2GRAY);

	threshold(image2, image, 100, 255, 0);
	imshow("image", image);
	erode(image, image_erode, element);
	imshow("image_erode1", image_erode);
	dilate(image, image_dilate, element);
	imshow("image_dilate", image_dilate);
	morphologyEx(image, image_erode, MORPH_ERODE, element);
	imshow("image_erode2", image_erode);
	morphologyEx(image, image_open, MORPH_OPEN, element);
	imshow("image_open", image_open);
	morphologyEx(image, image_colse, MORPH_CLOSE, element);
	imshow("image_colse", image_colse);
	morphologyEx(image, image_tophat, MORPH_TOPHAT, element);
	imshow("image_tophat", image_tophat);
	waitKey(0);


}