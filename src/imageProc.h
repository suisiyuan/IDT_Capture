#pragma once

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;


// 获得给定图片的圆心坐标和半径
//bool detectCircle(Mat img, uint16_t *centerX, uint16_t *centerY, uint16_t *radius);

// 根据给定圆心和半径来展开图片
Mat expandImg(Mat img, uint16_t centerX, uint16_t centerY, uint16_t radiusIn, uint16_t radiusOut, double_t angle);

// 根据给定的两张图片以及方向进行拼接
Mat stithImg(Mat img1, Mat img2, Stitcher::Status *status);