#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("Ó²±Ò.jpg");
	Mat grayMat, image, labels, stats, centroids, image_erode, image_dilate;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);
	
	threshold(grayMat, image, 80, 255, 0);
	erode(image, image_erode, element);
	dilate(image_erode, image_dilate, element);
	int num = connectedComponentsWithStats(image_erode, labels, stats, centroids, 8, CV_16U);
	cout << "¹²ÓÐ" << num-1 << "¸öÓ²±Ò" << endl;

	for (int i = 1; i < num; i++)
	{
		Rect rect;
		rect.x = stats.at<int>(i,0);
		rect.y = stats.at<int>(i,1);
		rect.width = stats.at<int>(i,2);
		rect.height = stats.at<int>(i,3);
		rectangle(srcMat, rect, CV_RGB(255, 0, 0), 1, 8, 0);
	}
	imshow("image_erode1", srcMat);
	waitKey(0);
}