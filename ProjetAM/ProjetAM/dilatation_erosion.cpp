#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/// Global variables
Mat src2, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const maxi_kernel_size = 21;

/** Function Headers */
void Erosion( int, void* );
void Dilation( int, void* );


int EroDila()
{

    // Read image from file
    string imageName = "";
    cout<<"Entrez le nom du fichier : "<<endl;
    cin>>imageName;
   
    src2 = imread(imageName, IMREAD_COLOR);

    //if fail to read the image
    if(!src2.data )
    {
        printf( " No image data \n " );
        return -1;
    }
    //if fail to read the image
    if (src2.empty()){
        printf("no data");
        return -1;
    }

    int erosion_choice = -1;
    while (erosion_choice != 0 && erosion_choice != 1) {
        cout << " 1 for Erosion or 0 for Dilation" << endl;
        cin >> erosion_choice;
    }

    if (erosion_choice == 1) {
        Erosion( 0, 0 );
    } else if (erosion_choice == 0) {
        Dilation( 0, 0 );
    }

    waitKey(0);
    size_t lastindex = imageName.find_last_of(".");
    string rawname = imageName.substr(0, lastindex);
    if (erosion_choice == 1) {
        String newImage_name = rawname + "_eroded.jpg";
        imwrite(newImage_name, erosion_dst);
    } else if (erosion_choice == 0) {
        String newImage_name = rawname + "_dilatated.jpg";
        imwrite(newImage_name, dilation_dst);
    }
    return 0;
}

/**  @function Erosion  */
void Erosion( int, void* )
{
    int erosion_type;
    if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
    else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
    else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

    Mat element = getStructuringElement( erosion_type,
                                         Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                         Point( erosion_size, erosion_size ) );

    /// Create windows
    namedWindow( "Erosion", CV_WINDOW_AUTOSIZE );

    /// Create Erosion Trackbar
    createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion",
                    &erosion_elem, max_elem,
                    Erosion );

    createTrackbar( "Erosion size:\n 2n +1", "Erosion",
                    &erosion_size, maxi_kernel_size,
                    Erosion );

    /// Apply the erosion operation
    erode( src2, erosion_dst, element );
    imshow( "Erosion", erosion_dst );
}

/** @function Dilation */
void Dilation( int, void* )
{
    int dilation_type;
    if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
    else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
    else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

    Mat element = getStructuringElement( dilation_type,
                                         Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                         Point( dilation_size, dilation_size ) );

    /// Create windows
    namedWindow( "Dilation", CV_WINDOW_AUTOSIZE );
    cvMoveWindow( "Dilation", src2.cols, 0 );

    /// Create Dilation Trackbar
    createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation",
                    &dilation_elem, max_elem,
                    Dilation );

    createTrackbar( "Dilation size:\n 2n +1", "Dilation",
                    &dilation_size, maxi_kernel_size,
                    Dilation );

    /// Apply the dilation operation
    dilate( src2, dilation_dst, element );
    imshow( "Dilation", dilation_dst );
}