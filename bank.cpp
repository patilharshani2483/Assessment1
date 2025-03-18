#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	
	cout<<"==============Welcome to ATM=================="<<endl;
	cout<<"            -------------------               "<<endl;
	
	std::time_t now = std::time(0);  
    std::cout << std::ctime(&now);
    
    cout<<"            -------------------               "<<endl;
    
    
    cout<<"=========================================================================="<<endl;
    cout<<"\tPress 1 and Then Press Enter to Access Your Account via Pin Number"<<endl;
    cout<<"                             or                                    "<<endl;
    cout<<"\tPress 0 and Press Enter to get Help"<<endl<<endl;
    
    
    
    cout<<"==============ATM ACCOUNT ACCESS=================="<<endl<<endl;
    cout<<"Enter Your Account Pin Access Number![Only one attempt is allowed]"<<endl<<endl<<endl;
    
    cout<<"==========================================================================="<<endl<<endl;
    
    cout<<"12345";


    return 0;
	
	

	
}
