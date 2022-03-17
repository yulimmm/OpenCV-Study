#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void on_trackbar(int pos, void* userdata);

int main()
{
	Mat resized_src;
	Mat src = imread("sphygmomanometer.jpg", IMREAD_GRAYSCALE);
	resize(src, resized_src, Size(300, 300));

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	imshow("resized_src", resized_src);

	namedWindow("dst");
	createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&resized_src);
	setTrackbarPos("Block Size", "dst", 11);

	waitKey();
	return 0;
}

void on_trackbar(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;

	int bsize = pos;
	if (bsize % 2 == 0)bsize--;
	if (bsize < 3) bsize = 3;

	Mat dst;
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);

	imshow("dst", dst);
}
