#include <iostream>
#include <fstream>
#include <string>

// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

// Define mode for stitching as panoroma
// (One out of many functions of Stitcher)
Stitcher::Mode mode = Stitcher::PANORAMA;

// Array for pictures
vector<Mat> imgs;

int panoramaStiching()
{
    int again_loop = -1;
    string image_choice;
    while (again_loop != 0) {
        cout<<"Entrez le nom du fichier : "<<endl;
        cin >> image_choice;
        Mat img = imread(image_choice);
        if (img.empty())
        {
            // Exit if image is not present
            cout << "Can't read image '" << image_choice << "'\n";
        } else {
            imgs.push_back(img);
        }
        cout << "Do you want to pick another image (1 for yes, 0 for no)" << endl;
        cin >> again_loop;
    }


    // Define object to store the stitched image
    Mat pano;

    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode, false);

    // Command to stitch all the images present in the image array
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    if (status != Stitcher::OK)
    {
        // Check if images could not be stiched
        // status is OK if images are stiched successfully
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return -1;
    }

    // Store a new image stiched from the given
    //set of images as "result.jpg"
    imwrite("result.jpg", pano);

    // Show the result
    imshow("Result", pano);

    cout << "Stitching completed successfully!";
    waitKey(0);
    return 0;
}