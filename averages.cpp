//Norbert Acedański
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;
unsigned short int choice, i, numberOfElements, keepAveraging=1;
float product, power, weightProduct, currentProduct, result, currentWeight, currentNumber, kFactor;

void arithmeticAverage()
{
	cout<<"1 - ARYTHMETIC AVERAGE\n";
	cout<<"Arythmetic average form:\n";
	cout<<"(a1+a2+a3+...+an)\n";
	cout<<"-----------------\n";
	cout<<"        n\n";
	cout<<"It is a sum of the elements divided by their amount.\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	for(i=0; i<numberOfElements; i++)
		{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		product+=currentNumber;
	}
	result=product/numberOfElements;
	cout<<"Arythmetic average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void geometricAverage()
{
	cout<<"2 - GEOMETRIC AVERAGE\n";
	cout<<"Geometric average form:\n";
	cout<<"    ________________\n";
	cout<<"n  /\n";
	cout<<" \\/ a1*a2*a3*...*an\n";
	cout<<"It is an n-th square root of the product of positive numbers\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=1;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		if(currentNumber<=0)
		{
			cout<<"Cannot compute geometric average with non-positive numbers\n";
			i--;
		}
		product*=currentNumber;
	}
	power=1.00/numberOfElements;
	result=pow(product, power);
	cout<<"Geometric mean of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void harmonicAverage()
{
	cout<<"3 - HARMONIC AVERAGE\n";
	cout<<"Harmonic average form:\n";
	cout<<"       n\n";
	cout<<"---------------\n";
	cout<<" 1  1  1      1\n";
	cout<<"--+--+--+...+--\n";
	cout<<"a1 a2 a3     an\n";
	cout<<"It is a number of elements divided by the sum of inverses of the positive numbers\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		if(currentNumber<=0)
		{
			cout<<"Cannot compute harmonic average with non-positive numbers\n";
			i--;
		}
		product+=1.00/currentNumber;
	}
	result=numberOfElements/product;
	cout<<"Harmonic average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void squareAverage()
{
	cout<<"4 - SQUARE AVERAGE\n";
	cout<<"Square average form:\n";
	cout<<"      ____________________\n";
	cout<<"     /  2    2          2\n";
	cout<<"    / a1 + a2 + ... + an\n";
	cout<<"\\  /  -------------------\n";
	cout<<" \\/            n\n";
	cout<<"It is a square root of the arithmetic average of squared numbers\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		product+=currentNumber*currentNumber;
	}
	product=product/numberOfElements;
	result=sqrt(product);
	cout<<"Square average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void powerAverage()
{
	cout<<"5 - POWER AVERAGE\n";
	cout<<"Power average form:\n";
	cout<<"       ____________________\n";
	cout<<"      /  k    k          k\n";
	cout<<"k    / a1 + a2 + ... + an\n";
	cout<<" \\  /  -------------------\n";
	cout<<"  \\/            n\n";
	cout<<"It is a k-th root of the quotient of the sums of the k-th powers of successive numbers and the number of elements\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	cout<<"Enter \"k\" factor: ";
	cin>>kFactor;
	currentProduct=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		currentProduct=pow(currentNumber, kFactor);
		product+=currentProduct;
	}
	product=product/numberOfElements;
	power=1.00/kFactor;
	result=pow(product, power);
	cout<<"Power average of " <<numberOfElements<< " given elements equals: " <<result<<endl;
}

void weightedAverage()
{
	cout<<"6 - WEIGHTED AVERAGE\n";
	cout<<"Weighted average form:\n";
	cout<<"a1*w1+a2*w2+a3*w3+...+an*wn\n";
	cout<<"---------------------------\n";
	cout<<"      w1+w2+w3+...+wn\n";
	cout<<"It is a quotient of the sum of the products of numbers and their weights and the sum of the weights\n";
	cout<<"Enter the number of elements: ";
	cin>>numberOfElements;
	product=0;
	weightProduct=0;
	for(i=0; i<numberOfElements; i++)
	{
		cout<<"Enter " <<i+1<< ". element: ";
		cin>>currentNumber;
		cout<<"Enter element weight: ";
		cin>>currentWeight;
		product+=currentNumber*currentWeight;
		weightProduct+=currentWeight;
	}
	result=product/weightProduct;
	cout<<"Weighted average of " <<numberOfElements<< " given elements equals " <<result<<endl;
}

void printAveragesMenu()
{
	system("cls");
	cout<<"MENU\n";
	cout<<"Choose average to compute:\n";
	cout<<"1 - Arythmetic average\n";
	cout<<"2 - Geometric average\n";
	cout<<"3 - Harmonic average\n";
	cout<<"4 - Square average\n";
	cout<<"5 - Power average\n";
	cout<<"6 - Weighted average\n";
	cout<<"0 - To stop the program\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	system("cls");
}

int main()
{
	cout<<setprecision(100000);
	cout<<"A program that calculates averages\n";
	while(keepAveraging!=0)
	{
		printAveragesMenu();
		switch(choice)
		{
			case 1:
			{
				arithmeticAverage();
				break;
			}
			case 2:
			{
				geometricAverage();
				break;
			}
			case 3:
			{
				harmonicAverage();
				break;
			}
			case 4:
			{
				squareAverage();
				break;
			}
			case 5:
			{
				powerAverage();
				break;
			}
			case 6:
			{
				weightedAverage();
				break;
			}
			case 0:
			{
				system("pause");
				return 0;
				break;
			}
		}
		cout<<"To select menu enter 1, to stop the program, enter 0: ";
		cin>>keepAveraging;
	}
	system("pause");
	return 0;
}
