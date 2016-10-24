#include "imageProc.h"


//bool detectCircle(Mat img, uint16_t *centerX, uint16_t *centerY, uint16_t *radius)
//{
//	Mat grayImg(img.rows, img.cols, CV_8UC1);
//	cvtColor(img, grayImg, CV_BGR2GRAY);
//	//GaussianBlur(grayImg, grayImg, Size(9, 9), 2, 2);
//
//	vector<Vec3f> circles;
//	HoughCircles(grayImg, circles, CV_HOUGH_GRADIENT, 2, 300, 200, 100);
//	
//
//	for (size_t i = 0; i < circles.size(); i++)
//	{
//		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//		int radius = cvRound(circles[i][2]);
//		// circle center
//		circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);
//		// circle outline
//		circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);
//	}
//
//	return true;
//}


Mat expandImg(Mat img, uint16_t centerX, uint16_t centerY, uint16_t radiusIn, uint16_t radiusOut, double_t angle)
{
	if (img.empty())
		return img;

	uint16_t rows = img.rows;
	uint16_t cols = img.cols;
	uint16_t R = radiusOut;
	uint16_t r = radiusIn;
	uint16_t newRows = R - r;
	uint16_t newCols = 2 * r * CV_PI;

	Mat dstImg = Mat::zeros(newRows, newCols, CV_8UC3);

	double alpha = angle;
	const double interval = 2 * CV_PI / newCols;

	for (uint16_t i = 0; i < newCols; i++)
	{
		for (uint16_t j = 0; j < newRows; j++)
		{
			uint16_t x = centerX + (r + newRows - 1 - j) * cos(alpha);
			uint16_t y = centerY + (r + newRows - 1 - j) * sin(alpha);
			dstImg.at<Vec3b>(j, i) = img.at<Vec3b>(y, x);
		}
		alpha += interval;
	}

	return dstImg;
}

Mat stithImg(Mat img1, Mat img2, Stitcher::Status *status)
{
	vector<Mat> imgs;
	Mat pano;
	imgs.push_back(img1);
	imgs.push_back(img2);

	Stitcher stitcher = Stitcher::createDefault(true);
	*status = stitcher.stitch(imgs, pano);

	return pano;
}