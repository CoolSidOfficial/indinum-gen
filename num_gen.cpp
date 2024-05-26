#include<iostream>
#include<vector>
#include<string>
//#include<windows.h>    //for windows delay
#include<unistd.h>        // for linux delay
#include "clscolor.h"    //Custom library made by  myself 
#include<fstream>
#include<sstream>
#include<iomanip>
std::vector<std::string> indianStates = {

	    "Andhra Pradesh",
	        "Arunachal Pradesh",
		    "Assam",
		        "Bihar",
			    "Chhattisgarh",
			        "Goa",
				    "Gujarat",
				        "Haryana",
					    "Himachal Pradesh",
					        "Jharkhand",
						    "Karnataka",
						        "Kerala",
							    "Madhya Pradesh",
							        "Maharashtra",
								    "Manipur",
								        "Meghalaya",
									    "Mizoram",
									        "Nagaland",
										    "Odisha",
										        "Punjab",
											    "Rajasthan",
											        "Sikkim",
												    "Tamil Nadu",
												        "Telangana",
													    "Tripura",
													        "Uttar Pradesh",
														    "Uttarakhand",
														        "West Bengal"
};

void  generator(int  four=9200){
	int count=0;
   std::ofstream output_file;
   output_file.open("9200.txt");
  while (count<=999999){
   std::ostringstream final_string;
    final_string<< four <<std::setw(6)<<std::setfill('0')<<count;
    output_file<<final_string.str()<<"\n";
     count++;
  }
  output_file.close();
}

int choose_isp(){
   int ispc2;	
  clear();
  std::cout<<"Choose a ISP from given below\n";
  color("[1]>>Reliance Jio","cyan");

  std::cout<<"\n";
  color("[2]>>Airtel","red");
  std::cout<<"\n";
  color("[3]>>Voadafone Idea","white");
  std::cout<<"\n";
  color("[4]>>Bsnl","blue");
	
  std::cout<<"\n"<<"Choose a number [>>]";
  std::cin>>ispc2;
  return ispc2;
} 
int  intro_func()
{


    int count=1;
    int c1;
	for ( auto state:indianStates){
		std::cout<<count<<">>]"<<state<<"\n";
	count=count+1;}
	 std::cout<<"Please choose your state number]>";
	 std::cin>> c1;
	 if  (  c1>=29 || c1<0){
		 std::cout<<"You enter wrong input";
		 clear();
		 sleep(3);
                  intro_func();
	 
	 }
else{

     std::string choosen_state=indianStates[c1-1];
	 std::cout<<"So you choosed :"<<choosen_state<<std::endl;
         sleep(1);
	 clear();
	 return choosen_state;
	 

  }

                   }  

int main(){
int final_state=intro_func();	
int final_isp=choose_isp();
clear();
std::color("PLEASE WAIT GENERATING NUMBERS FOR ","blue")<< final_state<<color("AND FINAL OPERATOR","blue")<<final_isp<<color("IN THE FILE ","blue"<<"numgenout.txt";<<std::endl;
generator();

return 0;
}
