// OpenCV Stitcher includes
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

// Stitcher
bool try_use_gpu = false;
std::vector<cv::Mat> panoImgs;
cv::Mat pano; // Output panorama array
//cv::Stitcher::Mode mode = cv::Stitcher::PANORAMA;

int main(int argc, char **argv) {

	int numImages = argc - 1;

	for (int i = 0; i < numImages; i++) {
		panoImgs.push_back(cv::imread(argv[i + 1], CV_LOAD_IMAGE_COLOR));
	}

	// Create Stitcher object for panorama
	cv::Stitcher stitcher = cv::Stitcher::createDefault();

	cv::Stitcher::Status status = stitcher.stitch(panoImgs, pano);

	std::cout << "Creating panorama... ";

	if (status != cv::Stitcher::OK) {
		std::cout << "can't stitch images, error code = " << int(status) << "\n";
	}
	else {
		std::cout << "success!\n";
		cv::imshow("Panoramic Image", pano);
		cv::imwrite("Panorama.png", pano);
	}

    return 0;
}