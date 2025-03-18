#include<iostream>
using namespace std;
float add(float a,float b)
 {
 	return a+b;
 }
 
 float sub(float a,float b)
 {
 	return a-b;
 }
 
 float mul(float a,float b)
 {
 	return a*b;
 }
 
 float div(float a,float b)
 {
 	 if (b == 0)
	{
        cout << "Error! Division by zero is not allowed." << endl;
        return 0;
    }
    return a / b;
}
 	
 void displayMenu()
 {
 	cout<<"\n===========MENU DEIVEN CALCULATOR==============\n";
 	cout<<"1.ADDITION"<<endl;
 	cout<<"2.SUBTRACTION"<<endl;
 	cout<<"3.MULTIPLICATION"<<endl;
 	cout<<"4.DIVISION"<<endl;
 	cout<<"5.EXIT"<<endl;
 	cout<<"================================================"<<endl;
 }
int main()
{
	int choice;
	float num1,num2,result;
	
	
	while(true)
	{
		displayMenu();
		cout<<"Enter Your Choice(1-5): ";
		cin>>choice;
		
		if(choice < 1 || choice > 5)
		{
			cout<<"	Invalid Choice!Please Select a valid option(1-5)"<<endl;
			continue;
		}
		
		
		if(choice == 5)
		{
			cout<<"Exiting the calculator.Thank You!"<<endl;
			break;
		}
		
		cout<<"Enter a First Number:";
		cin>>num1;	
		cout<<"Enter Second Number:";
		cin>>num2;
		
		
		switch(choice)
		{
			case 1:
				result = add(num1,num2);
				cout<<"Result: "<<num1 <<" + "<<num2<<" = "<<result<<endl;
				break;
			case 2:
				result = sub(num1,num2);
				cout<<"Result: "<<num1<<" - "<<num2<<" = "<<result<<endl;
				break;
			case 3:
				result = mul(num1,num2);
				cout<<"Result:"<<num1<<" * "<<num2<<" = "<<result<<endl;
				break;
			case 4:
				result = div(num1,num2);
				cout<<"Result:"<<num1<<" / "<<num2<<" = "<<result<<endl;
				break;
		}
	}
	
return 0;
}
