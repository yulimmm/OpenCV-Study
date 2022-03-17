
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void on_threshold(int pos, void* userdata);

int main(int argc, char* argv[]) 
{
	Mat src;
	Mat resized_src;

	if (argc < 2) {
		src = imread("sphygmomanometer.jpg", IMREAD_GRAYSCALE);
		resize(src, resized_src, Size(300, 300)); //사진 크기 조정
	}

	else {
		src = imread(argv[1], IMREAD_GRAYSCALE);
		resize(src, resized_src, Size(300, 300)); //사진 크기 조정
	}

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return - 1;
	}

	//imshow("src", src);
	imshow("resized_src", resized_src);

	namedWindow("dst");
	moveWindow("dst", 40, 30);  //창 위치
	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&resized_src);
	setTrackbarPos("Threshold", "dst", 70);

	waitKey();
	return 0;
}

void on_threshold(int pos, void* userdata) 
{
	Mat src = *(Mat*)userdata;

	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);

	imshow("dst", dst);
}
