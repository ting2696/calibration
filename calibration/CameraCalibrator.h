/*------------------------------------------------------------------------------------------*\
This file contains material supporting chapter 9 of the cookbook:
Computer Vision Programming using the OpenCV Library.
by Robert Laganiere, Packt Publishing, 2011.

This program is free software; permission is hereby granted to use, copy, modify,
and distribute this source code, or portions thereof, for any purpose, without fee,
subject to the restriction that the copyright notice may not be removed
or altered from any source or altered source distribution.
The software is released on an as-is basis and without any warranties of any kind.
In particular, the software is not guaranteed to be fault-tolerant or free from failure.
The author disclaims all warranties with regard to this software, any use,
and any consequent failure, is purely the responsibility of the user.

Copyright (C) 2010-2011 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#ifndef CAMERACALIBRATOR_H
#define CAMERACALIBRATOR_H


#include <vector>
#include <iostream>

#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

class CameraCalibrator {
	//input points
	vector<vector<Point3f>> objectPoints;
	vector<vector<Point2f>> imagePoints;
	//output Matrices
	Mat cameraMatrix;
	Mat distCoeffs;
	int flag;
	Mat map1, map2;
	bool mustInitUndistort;
public:
	CameraCalibrator() : flag(0), mustInitUndistort(true) {};
	int addChessboardPoints(const vector<string>& filelist, Size & boardSize);
	void addPoints(const vector<Point2f>& imageCorners, const vector<cv::Point3f>& objectCorners);
	// Calibrate the camera
	double calibrate(Size imageSize);
	// Set the calibration flag
	void setCalibrationFlag(bool radial8CoeffEnabled = false, bool tangentialParamEnabled = false);
	// Remove distortion in an image (after calibration)
	Mat remap(const Mat &image);
	Mat getCameraMatrix() { return cameraMatrix; }
	Mat getDistCoeffs() { return distCoeffs; }
};

#endif // CAMERACALIBRATOR_H






