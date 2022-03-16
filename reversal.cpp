#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void main(void)
{
	Mat img; //Mat 클래스 타입의 변수 img를 선언
	img = imread("sphygmomanometer.jpg"); //img = 혈압계 사진

	if (img.empty()) { //만약 img가 비어있다면
		std::cerr << "Image load failed!" << std::endl;  //이미지 로드 실패라고 말하기.
		//return;
	}

	Mat img2 = img(Rect(200, 120, 340, 240));  //혈압계 사진의 특정 크기 자르기
	Mat img3 = img(Rect(200, 120, 340, 240)).clone(); //그 이미지 추출

	img2 = ~img2; //이미지 반전

	imshow("img1", img);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey(); //키보드 입력 기다림. 
	destroyAllWindows(); //창 끄기

}
