#include <cstdlib>
#include <time.h>
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
struct index {
	int index1[12] ;
	int index2[12] ;
	int index3[12];
	int index4[12];
	int index5[12];
	int index6[12];
	int index7[12];
	int index8[12];
	int indexf123_1[12];
	int indexf123_2[12];
	int indexf123_3[12];
	int indexf1234_1[12];
	int indexf1234_2[12];
	int indexf1234_3[12];
	int indexf1234_4[12];
}in;

struct Fvalues
{
	double F12_x[12];
	double F123_x[12];
	double F1234_x[12];
}val;
struct random_value_array
{
	float f1_r[12];
	float f2_r[12];

}ran_arr;
  void F12(int A) {
	  
	double f1[2][11] = { {0, 0.28, 0.45, 0.65, 0.78, 0.90, 1.02, 1.13, 1.23, 1.32, 1.38} ,
						{ 0, 0.25, 0.41, 0.55, 0.65, 0.75, 0.80, 0.85, 0.88, 0.90, 0.90 } };
	double max_value = 0;
	
	for (int i = 0; i < A  ; ++i) {
		for (int j = 0; j < A ; ++j) {
			if (  (i + j)< A) {							 //f1(x) + f2(A-x) 
				if (f1[0][j] + f1[1][i] > max_value) { //max[f1(x) + f2(A-x)]
					
						in.index1[A] = j;
						in.index2[A] = i;
					
					
					max_value = f1[0][j] + f1[1][i];
					
				}
			}		
		}	
	}
	
	val.F12_x[A] = max_value; //save the calculated value to input into the new array
	cout <<"the optimal point :  " << "( " << in.index1[A] << "," << in.index2[A] << " )   <-   ";
	cout <<"F(1,2)x :  " << max_value << endl;
	/*
	* The result of F12()x :
	the optimal point :  ( 0,0 )   <-   F(1,2)x :  0
	the optimal point :  ( 1,0 )   <-   F(1,2)x :  0.28
	the optimal point :  ( 1,1 )   <-   F(1,2)x :  0.53
	the optimal point :  ( 2,1 )   <-   F(1,2)x :  0.7
	the optimal point :  ( 3,1 )   <-   F(1,2)x :  0.9
	the optimal point :  ( 3,2 )   <-   F(1,2)x :  1.06
	the optimal point :  ( 3,3 )   <-   F(1,2)x :  1.2
	the optimal point :  ( 4,3 )   <-   F(1,2)x :  1.33
	the optimal point :  ( 5,3 )   <-   F(1,2)x :  1.45
	the optimal point :  ( 6,3 )   <-   F(1,2)x :  1.57
	the optimal point :  ( 7,3 )   <-   F(1,2)x :  1.68
	*/
}

void F123(int A) {
	
	
	double max_value = 0;
	
	cout << endl;

	//double f1[2][11] = { {0, 0.28, 0.53, 0.7, 0.9, 1.06, 1.2, 1.33, 1.45, 1.57, 1.68} ,
						//{ 0, 0.15, 0.25, 0.40, 0.50, 0.62, 0.53, 0.82, 0.90, 0.96, 1.00 } };
	double f1[2][11] = { {} ,
		{ 0, 0.15, 0.25, 0.40, 0.50, 0.62, 0.53, 0.82, 0.90, 0.96, 1.00 } };
	for (int i = 0; i <= 10; i++) {
		f1[0][i] = val.F12_x[i+1];
	}

	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < A; ++j) {
			if ((i + j) < A) {							 //F(1,2)x + f3(A-x) 
				if (f1[0][j] + f1[1][i] > max_value) { //max[F(1,2)x + f3(A-x)]
					in.index3[A] = j;
					in.index4[A] = i;
					max_value = f1[0][j] + f1[1][i];

				}
			}
		}
	}
	val.F123_x[A] = max_value; //save the calculated value to input into the new array
	cout << "the optimal point :  " << "( " << in.index1[A-in.index4[A]] << "," << in.index2[A - in.index4[A]] <<","<<in.index4[A] << " )   <-   ";
	in.indexf123_1[A] = in.index1[A - in.index4[A]];
	in.indexf123_2[A] = in.index2[A - in.index4[A]];
	in.indexf123_3[A] = in.index4[A];
	cout << "F(1,2,3)x :  " << max_value << endl;

	/*
	* The result of F123()x :
	the optimal point :  ( 0,0, 0 )   <-   F(1,2,3)x :  0

	the optimal point :  ( 1,0, 0 )   <-   F(1,2,3)x :  0.28

	the optimal point :  ( 1,1, 0 )   <-   F(1,2,3)x :  0.53

	the optimal point :  ( 2,1, 0 )   <-   F(1,2,3)x :  0.7

	the optimal point :  ( 3,1, 0 )   <-   F(1,2,3)x :  0.9

	the optimal point :  ( 3,2, 0 )   <-   F(1,2,3)x :  1.06

	the optimal point :  ( 3,2, 1 )   <-   F(1,2,3)x :  1.21

	the optimal point :  ( 3,3, 1 )   <-   F(1,2,3)x :  1.35

	the optimal point :  ( 4,3, 1 )   <-   F(1,2,3)x :  1.48

	the optimal point :  ( 3,3, 3 )   <-   F(1,2,3)x :  1.6

	the optimal point :  ( 4,3, 3 )   <-   F(1,2,3)x :  1.73
	*/
}

void F1234(int A) {


	double max_value = 0;

	cout << endl;
	//double f1[2][11] = { {0, 0.28, 0.53, 0.7, 0.9, 1.06, 1.21, 1.35, 1.48, 1.6, 1.73} ,
		//				{ 0, 0.20, 0.33, 0.42, 0.48, 0.53, 0.56, 0.58, 0.60, 0.60, 0.60 } };
	double f1[2][11] = { {} ,
						{ 0, 0.20, 0.33, 0.42, 0.48, 0.53, 0.56, 0.58, 0.60, 0.60, 0.60 } };
	for (int i = 0; i <= 10; i++) {
		f1[0][i] = val.F123_x[i + 1];
	}
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < A; ++j) {
			if ((i + j) < A) {							//F(1,2)x + f3(A-x) 
				if (f1[0][j] + f1[1][i] > max_value) { //max[F(1,2)x + f3(A-x)]
					in.index5[A] = j;
					in.index6[A] = i;
					max_value = f1[0][j] + f1[1][i];

				}
			}
		}
	}

	
	cout << "the optimal point :  " << "( " << in.indexf123_1[A - in.index6[A]] << "," << in.indexf123_2[A - in.index6[A]] << "," << in.indexf123_3[A - in.index6[A]] << "," << in.index6[A] << " )   <-   ";
	in.indexf1234_1[A] = in.indexf123_1[A - in.index6[A]];
	in.indexf1234_2[A] = in.indexf123_2[A - in.index6[A]];
	in.indexf1234_3[A] = in.indexf123_3[A - in.index6[A]];
	in.indexf1234_4[A] = in.index6[A];
	cout << "F(1,2,3,4)x :  " << max_value << endl;

	
	/*
	* The result of F1234()x :
	the optimal point :  ( 0,0,0,0 )   <-   F(1,2,3)x :  0

	the optimal point :  ( 1,0,0,0 )   <-   F(1,2,3)x :  0.28

	the optimal point :  ( 1,1,0,0 )   <-   F(1,2,3)x :  0.53

	the optimal point :  ( 1,1,0,1 )   <-   F(1,2,3)x :  0.73

	the optimal point :  ( 3,1,0,0 )   <-   F(1,2,3)x :  0.9

	the optimal point :  ( 3,1,0,1 )   <-   F(1,2,3)x :  1.1

	the optimal point :  ( 3,2,0,1 )   <-   F(1,2,3)x :  1.26

	the optimal point :  ( 3,2,1,1 )   <-   F(1,2,3)x :  1.41

	the optimal point :  ( 3,3,1,1 )   <-   F(1,2,3)x :  1.55

	the optimal point :  ( 3,3,1,2 )   <-   F(1,2,3)x :  1.68

	the optimal point :  ( 4,3,1,2 )   <-   F(1,2,3)x :  1.81
	*/
}

void F12345(int A) {
	default_random_engine e(time(0));
	uniform_real_distribution<float> u(0, 3);
	for (int i = 0; i < 11; i++) {
		ran_arr.f1_r[i] = u(e);
		//cout << fixed << setprecision(2) << u(e) << endl;//example: get random value from 0 to 3
	}

	double max_value = 0;

	cout << endl;
	//double f1[2][11] = { {0, 0.28, 0.53, 0.73, 0.9, 1.1, 1.26, 1.41, 1.55, 1.68, 1.81} ,
		//				{ 0, 0.20, 0.33, 0.42, 0.48, 0.53, 0.56, 0.58, 0.60, 0.60, 0.60 } };
	double f1[2][11] = { {} ,{} };
	for (int i = 0; i <= 10; i++) {
		f1[0][i] = val.F1234_x[i + 1];
		f1[1][i] = ran_arr.f1_r[i];
	}
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < A; ++j) {
			if ((i + j) < A) {							 //F(1,2)x + f3(A-x) 
				if (f1[0][j] + f1[1][i] > max_value) { //max[F(1,2)x + f3(A-x)]
					in.index7[A] = j;
					in.index8[A] = i;
					max_value = f1[0][j] + f1[1][i];

				}
			}
		}
	}


	cout << "the optimal point :  " << "( " << in.indexf1234_1[A - in.index8[A]] << "," << in.indexf1234_2[A - in.index8[A]] << "," << in.indexf1234_3[A - in.index8[A]] << "," <<in.indexf1234_4[A-in.index8[A]]<<"," << in.index8[A] << " )   <-   ";

	cout << "F(1,2,3,4,5)x :  " << max_value << endl;
}
int main() {
	

	
	/*default_random_engine e(time(0));
	uniform_real_distribution<float> u(0, 3);
	for (int i = 0; i < 11; i++) {
		cout <<fixed<<setprecision(2)<< u(e) << endl;//example: get random value from 0 to 3
	}
	*/
	cout << "The result of F12()x :" << endl;
	for (int A = 1; A <= 11; A++) {
		F12(A);    //if you want to know F12()x, you must know F1()x, Now we konw the F1()x
	}
	
	cout << endl;
	cout << "The result of F123()x :" << endl;
	for (int A = 1; A <= 11; A++) {
		F123(A);  //if you want to know F123()x, you must know F12()x,So we must firstly calculate the previous function.
	}

	cout << endl;
	//for (int i = 1; i <= 11; i++) {
	//	cout << val.F12_x[i] << endl;
	//}
	
	cout << endl;
	cout << "The result of F1234()x :" << endl;
	for (int A = 1; A <= 11; A++) {
		F1234(A);  //if you want to know F1234()x, you must know F123()x. So we must firstly calculate the previous function.
	}
	cout << endl;
	cout << "The result of F12345()x :" << endl;
	for (int A = 1; A <= 11; A++) {
		F12345(A);  //if you want to know F12345()x, you must know F1234()x. So we must firstly calculate the previous function.
	}
	//If we want to calculate Fn()x,we must know the F(n-1)x, If we want to calculate F(n-1)x,we must know the F(n-2)x,,,,and so on. 
	
	
	return 0;
}