#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("电路图.jpg");
	Mat grayMat, image, labels, stats, centroids, image_erode, image_dilate, image_open;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(30, 30));
	Mat element1 = getStructuringElement(MORPH_ELLIPSE, Size(20, 20));
	cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);
	
	threshold(grayMat, image, 80, 255, THRESH_OTSU);
	Mat image1 = 255 - image;
//	adaptiveThreshold(grayMat, image, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 10);
	imshow("image", image1);
	erode(image1, image_erode, element);
	dilate(image_erode, image_dilate, element1);
//	imshow("image_erode", image_erode);
	imshow("image_dilate", image_dilate);
	int num = connectedComponentsWithStats(image_erode, labels, stats, centroids, 8, CV_16U);
	cout << "共有" << num-1 << "个圆" << endl;
	waitKey(0);
}