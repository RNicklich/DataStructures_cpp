/* Karatsuba multiplication */
#include <iostream>


using namespace std;

int karatsuba(int x, int y);
int numDigits(int n);
int pow10(int n);

int main() {
    cout << "7*6 = " << karatsuba(7, 6) << endl;
    cout << "15*15 = " << karatsuba(15, 15) << endl;
    cout << "6*13 = " << karatsuba(6, 13) << endl;
    cout << "51*49 = " << karatsuba(51, 49) << endl;
    cout << "111*111 = " << karatsuba(111, 111) << endl;
    cout << "5678*1234 = " << karatsuba(5678, 1234) << endl;
    cout << "12345678*1 = " << karatsuba(12345678, 1) << endl;
    cout << "12345678*0 = " << karatsuba(12345678, 0) << endl;
    return 0;
}

int numDigits(int num){
	int count = 0;
    if (num < 0){
  		num = num *(-1);
    }else if (num = 0){
    	count = 1;
    	return count;
    }
    do{
    	num=num/10;
    	//cout <<  << endl;
    	++count;
    }while(num > 0);
    
    return count;
}

int pow10(int n){
	int result = 10;
	for (int i = 0 ; i < n ; i++){
		result *= 10;
	}
	//return pow(10, n);
	return result;
}

int karatsuba(int x, int y){

	int n, round, result, multiplier;
	int a, b, c, d;

	int sizeOf_x = numDigits(x);
	//cout << "sizeOf_x = " << sizeOf_x << endl;
	int sizeOf_y = numDigits(y);
	//cout << "sizeOf_y = " << sizeOf_y << endl;

	n = max(sizeOf_x, sizeOf_y);
	//cout << "n = " << n << endl;

	round = (n/2) + (n%2);
	//cout << "round = " << round << endl;

	if(n < 2){
		return x*y;
	}

	multiplier = pow10(round);

	a = x / multiplier;
	b = x - (a * multiplier);
	c = y / multiplier;
	d = y - (b * multiplier);

	result = (karatsuba(a, c) * pow10(n)) + (pow10(round) * (karatsuba(a , d) + karatsuba(b , c))) + karatsuba(b , d);
	return result;
}