#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

//double alpha = 1.0;
int alpha = 0;
int beta = 0;
double double_alpha;
double const max_alpha = 200;
int const max_beta = 400;
Mat src1,  dst1;


/**
 * @function on_trackbar
 * @brief Callback for trackbar
 */
void on_trackbar( int, void* )
{
    double_alpha = (double) (100+alpha)/100 ;
    double double_beta = beta - 200;

    src1.convertTo(dst1, dst1.type(), double_alpha, double_beta);
    imshow( "Lighten / Brighten", dst1 );
}


int lightDarken()
{


    // Read image from file
    string imageName = "";
    cout<<"Entrez le nom du fichier : "<<endl;
    cin>>imageName;
    src1 = imread(imageName, IMREAD_COLOR);

    //if fail to read the image
   if(!src1.data )
    {
        printf( " No image data \n " );
        return -1;
    }
    dst1 = Mat::zeros(src1.size(), src1.type());
    src1.copyTo(dst1);


    /// Create Windows
    namedWindow("Lighten / Brighten", CV_WINDOW_AUTOSIZE);


    createTrackbar( "Contrast", "Lighten / Brighten",
                    &alpha, max_alpha,
                    on_trackbar );

    createTrackbar( "Brightness", "Lighten / Brighten",
                    &beta, max_beta,
                    on_trackbar );

    /// Apply the convert operation
    imshow( "Lighten / Brighten", dst1 );

    /// Wait until user press some key
    waitKey(0);

    size_t lastindex = imageName.find_last_of(".");
    string rawname = imageName.substr(0, lastindex);

    imwrite(rawname+"_adjusted.jpg", dst1);
    return 0;
}