/* Copyright (C) 2011 Uni Osnabrück
 * This file is part of the LAS VEGAS Reconstruction Toolkit,
 *
 * LAS VEGAS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * LAS VEGAS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 */


/*
 * Transform.cpp
 *
 *  @date 15.07.2012
 *  @author Kim Rinnewitz (krinnewitz@uos.de)
 */

#include "Transform.hpp"

namespace lssr {
Transform::Transform(Texture *t1, Texture* t2)
{
	//convert textures to cv::Mat
	cv::Mat img1(cv::Size(t1->m_width, t1->m_height), CV_MAKETYPE(t1->m_numBytesPerChan * 8, t1->m_numChannels), t1->m_data);
	cv::Mat img2(cv::Size(t2->m_width, t2->m_height), CV_MAKETYPE(t2->m_numBytesPerChan * 8, t2->m_numChannels), t2->m_data);
	m_img1 = img1;
	m_img2 = img2;

	//make input gray scale 
	cv::Mat img1g;	
	cv::cvtColor(img1, img1g, CV_RGB2GRAY);
	cv::Mat img2g;	
	cv::cvtColor(img2, img2g, CV_RGB2GRAY);

	//TODO	
	//calculate rotation, translation and scaling
}

Transform::Transform(const cv::Mat &t1, const cv::Mat &t2)
{
	m_img1 = t1;
	m_img2 = t2;

	//TODO
	//calculate rotation, translation and scaling
}

cv::Mat Transform::apply()
{
	//TODO
	//apply the transformation to the second image/texture
}

Transform::~Transform()
{
	//TODO?!
}
}
