#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void main()
{
	Mat resized_src;
	Mat src = imread("test.png", IMREAD_GRAYSCALE);
	resize(src, resized_src, Size(700, 700));

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);

	Mat dst;
	cvtColor(resized_src, dst, COLOR_GRAY2BGR);

	for (int i = 1; i < cnt; i++) {
		int* p = stats.ptr<int>(i);

		if (p[4] < 20) continue;

		rectangle(dst, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 255, 255), 2);
	}

	imshow("src", resized_src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
	
}
