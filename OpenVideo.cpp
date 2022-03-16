
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void main(void) 
{
	VideoCapture cap(0); //videocapture 객체를 생성하고 컴퓨터에 연결된 기본 카메라를 사용하도록 설정

	if (!cap.isOpened())  //카메라 장치가 열리지 않으면 
	{
		cerr << "Camera open failed!" << endl;  //실패 메시지 보내기
		return; //함수 종료
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl; //프레임 가로 크기를 콘솔창에 출력
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl; //프레임 세로 크기를 콘솔창에 출력

	Mat frame, inversed; //Mat 타입의 변수 frame,과 inversed를 선언
	while (true) {
		cap >> frame;  //카메라 장치로부터 한 프레임을 받아 와서 frame 변수에 저장
		if (frame.empty())  // 만약 프레임이 비어있다면
			break;         //while루프 빠져나오기

		inversed = ~frame; //현재 프레임을 반전하여 inversed 변수에 저장

		imshow("frame", frame);   //frame에 저장된 정지 영상을 화면에 출력
		imshow("inversed", inversed);  //inversed에 저장된 정지 영상을 화면에 출력

		if (waitKey(10) == 27)  //10ms 시간 동안 키보드 입력 대기. 만약 키보드 입력이 있고, 해당 키 값이 27(esc)이면 
			break; //while루프 나오기
	}

	destroyAllWindows(); //모든 창 닫기.

}
