#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("回形针.jpg");
	Mat grayMat, image, labels, stats, centroids, image_erode, image_dilate, image_open;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(8, 8));
	Mat element1 = getStructuringElement(MORPH_ELLIPSE, Size(10, 10));
	cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);

	threshold(grayMat, image, 80, 255, THRESH_OTSU);
	Mat image1 = 255 - image;
	imshow("image1", image1);

//	erode(image1, image_erode, element);
//	dilate(image_erode, image_dilate, element1);
//	imshow("image_erode", image_erode);
//	imshow("image_dilate", image_dilate);
	int number = 0;
	int num = connectedComponentsWithStats(image1, labels, stats, centroids, 8, CV_16U);
	for (int i = 1; i < num; i++)
	{
		if (stats.at<int>(i, 4) >= 6000 & stats.at<int>(i, 4) <= 9000)
			number++;
	}
	//cout << stats.at<int>(2, 4) << endl;
	//cout << stats.at<int>(3, 4) << endl;
	//cout << stats.at<int>(4, 4) << endl;
	//cout << stats.at<int>(5, 4) << endl;
	
	cout << "共有" << number << "个回形针" << endl;
	waitKey(0);
}