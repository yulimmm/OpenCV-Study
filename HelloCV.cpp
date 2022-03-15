#include "opencv2/opencv.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Hello OpenCV" << CV_VERSION << std::endl; //opencv 버전 정보 알려줌

	cv::Mat img; //Mat 클래스 타입의 변수 img를 선언
	img = cv::imread("Lenna.png"); //img= 레나 사진

	if (img.empty()) { //만약 img가 비어있다면
		std::cerr << "Image load failed!" << std::endl;  //이미지 로드 실패라고 말하기.
		return -1; //-1로 변환
	}

	cv::namedWindow("image"); //창 이름이 image
	cv::imshow("image", img); //image 창에 img사진 보여주기

	cv::waitKey(); //키보드 입력 기다림. 

	return 0;
}
