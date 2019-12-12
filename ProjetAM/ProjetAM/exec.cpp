#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include "Resize.cpp"
#include "dilatation_erosion.cpp"
#include "lighten_darken.cpp"
#include "canny_edge_detection.cpp"
#include "panorama_stitching.cpp"
#include "face_recognition.cpp"

int main(int argc, char** argv)
{
	int action = 0;

	while (action != 7){
		cout<< "Que souhaitez-vous faire ? "<<  "\n 1 == > Dilatation/Erosion" << "\n 2 == > Resizing" 
			<< "\n 3 == > Lighten/Darken" << "\n 4 ==> Panorama Stiching" << "\n 5 ==> Canny edge detection" 
			<< "\n 6 ==> Face Recognition "<< " \n 7 ==> Quitter" <<endl;
		cin >> action;
		while (action < 1 || action > 6){
			cout<< "Action inconnu, rentrez une nouvelle action : "<<endl;
			cin >> action;
		}
		if (action == 1)EroDila();
		if (action == 2)resize();
		if (action == 3)lightDarken();
		if (action == 4)panoramaStiching();
		if (action == 5)cannyEdgeDetection();
		if (action == 6)FaceRecognition();
		
	}




}
