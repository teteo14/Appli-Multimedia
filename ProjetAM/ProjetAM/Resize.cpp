#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int resize(){

	Mat src; Mat dst;
	char nomFichier [50];
	int methode = 0;
	cout<<"Entrez le nom du fichierss : "<<endl;
	cin >> nomFichier;
	while (methode !=1 && methode != 2){
		cout<<"Choisissez votre méthode de redimensionnement : \n 1 ==> facteur \n 2 ==> deux dimensions "<<endl;
		cin >> methode;
	}

	src = imread( nomFichier );

	if (src.empty()){
        printf("no data");
        return -1;
    }

	if (methode == 1){
		double facteur = 0;
		cout<<"Entrez le facteur de redimensionnage : "<<endl;
		cin >> facteur;
		resize(src, dst, dst.size(), facteur, facteur, INTER_LINEAR);
	}

	else if (methode == 2){
		double facteurx = 0;
		double facteury = 0;
		cout<<"Entrez le facteur de redimensionnage x : "<<endl;
		cin >> facteurx;
		cout<<"Entrez le facteur de redimensionnage y : "<<endl;
		cin >> facteury;
		resize(src, dst, dst.size(), facteurx, facteury, INTER_LINEAR);
	}

	
	namedWindow( "Original", WINDOW_AUTOSIZE );
    namedWindow( "resized image", WINDOW_AUTOSIZE );

    imshow( "Original", src); 
    imshow( "resized image", dst ); 

	// Wait for any keystroke in the window
	char c;
	while (c != 27)
	c  = (char) waitKey(25);
   
    return 0;

}