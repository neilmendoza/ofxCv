#pragma once

#include "ofxCv.h"

/*
 the contour finder is with automatically threshold your image for you. it will
 also convert non-grayscale images to grayscale before thresholding. if you
 want to disable this, setAutoThreshold(false). by default the threshold is
 128. to change this, use setThreshold().
 */

namespace ofxCv {
	
	class ContourFinder {
	public:
		ContourFinder();
		
		template <class T> 
		void findContours(T& img) {
			findContours(toCv(img));
		}
		void findContours(cv::Mat img);
		void setAutoThreshold(bool autoThreshold);
		void setThreshold(float thresholdValue);
		void setSimplify(bool simplify);
		void draw();
	protected:
		cv::Mat thresh;
		bool autoThreshold, simplify;
		float thresholdValue;
		vector<vector<cv::Point> > contours;
	};	
}