#include <stdlib.h>
#include "Transform.hpp"
#include <stdio.h>
#include <math.h>
#include <iostream>

/**
 * \file	Main.cpp
 * \brief 	This is an approach to calculate the translation,
 * 		rotation and scaling between two images which show
		the same object. The main goal is to verify how
 *		good this method is when trying to match textures in
 *		3d reconstructions.
 *
 * \author	Kim Oliver Rinnewitz, krinnewitz@uos.de
 */

using namespace std;


int main (int argc, char** argv)
{

	if (argc != 3)
	{
		cout<<"Usage: "<<argv[0]<<" <filename1> <filename2>"<<endl;
		return EXIT_FAILURE;	
	}
	else
	{
		cv::Mat src1 = cv::imread(argv[1], 0);
		cv::Mat src2 = cv::imread(argv[2], 0);

		lssr::Transform* t = new lssr::Transform(src1, src2);
		cv::Mat transformed = t->apply();
		

		cv::startWindowThread();
		
		//show the reference image
		cv::namedWindow("RefImage", CV_WINDOW_AUTOSIZE);
		cv::imshow("RefImage", src1);
		
		//show the transformed second image
		cv::namedWindow("TransImage", CV_WINDOW_AUTOSIZE);
		cv::imshow("TransImage", transformed);
		cv::waitKey();

		cv::destroyAllWindows();

		return EXIT_SUCCESS;
	}

}
