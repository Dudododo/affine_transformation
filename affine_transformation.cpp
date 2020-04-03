#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("1.jpg", 1);
	cv::Mat dstMat;

	//变换前的三点坐标
	const cv::Point2f src_pt[] = {
		cv::Point2f(200,200),
		cv::Point2f(250,200),
		cv::Point2f(200,150)
	};
	//变换后的三点坐标
	const cv::Point2f dst_pt[] = {
		cv::Point2f(350,150),
		cv::Point2f(300,50),
		cv::Point2f(200,100)
	};
	//计算仿射矩阵
	const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);

	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
	cv::imshow("srcMat", srcMat);
	cv::imshow("dstMat", dstMat);
	waitKey(0);
}