#include<iostream>
#include<vector>
#include<string>
//#include<windows.h>    //for windows delay
#include<unistd.h>        // for linux delay
#include "clscolor.h"    //Custom library made by  myself 
#include<fstream>
#include<sstream>
#include<iomanip>
#include<unordered_map>
std::vector<std::string> indianStates = {

    "Andhra Pradesh",
        "Assam",
        "Bihar & Jharkhand",
        "DELHI",
        "Gujarat",
        "Tamil Nadu",
        "UTTAR PRADESH EAST",
        "UTTAR PRADESH West",
        "West Bengal"
        };




//////////////////////////////////////////////////////////////////////////////////////
std::unordered_map <std::string,std::unordered_map <std::string,std::vector<int> >> statecodes= {
        {"Andhra Pradesh", {
            {"AIRTEL", {9000, 9030, 9032, 9059, 9100, 9103, 9121, 9154, 9177, 9502, 9515, 9550, 9573, 9618, 9652, 9676, 9701, 9704, 9849, 9866, 9908, 9949, 9959, 9963, 9989}},
            {"BSNL", {9180, 9440, 9441, 9490, 9491, 9492, 9493, 9494}},
            {"Reliance Jio", {9014, 9182, 9281, 9346, 9347, 9381, 9390, 9391, 9392, 9398}},
            {"Vodafone Idea", {9010, 9052, 9063, 9160, 9505, 9542, 9553, 9581, 9603, 9640, 9642, 9666, 9703, 9705, 9848, 9885, 9912, 9948, 9966, 9985}}
        }},
        {"Assam", {
            {"AIRTEL", {9678, 9707, 9954, 9957}},
            {"BSNL", {9181, 9401, 9435}},
            {"Reliance Jio", {9101, 9287, 9864}},
            {"Vodafone Idea", {9064, 9085, 9706}}
        }},
        {"Bihar & Jharkhand", {
            {"AIRTEL", {9006, 9031, 9060, 9102, 9122, 9155, 9162, 9199, 9262, 9546, 9572, 9631, 9661, 9771, 9801, 9931, 9934, 9939, 9955, 9973}},
            {"BSNL", {9430, 9431, 9470, 9471, 9472}},
            {"Reliance Jio", {9142, 9229, 9234, 9241, 9263, 9279, 9304, 9334, 9341, 9508, 9608, 9693, 9798, 9835, 9905}},
            {"Vodafone Idea", {9117, 9128, 9135, 9507, 9525, 9534, 9570, 9576, 9708, 9709}}
        }},
        {"DELHI", {
            {"AIRTEL", {9205, 9311, 9319, 9560, 9599, 9650, 9667, 9717, 9773, 9810, 9818, 9821, 9870, 9871, 9910, 9958, 9971}},
            {"BSNL", {9013}},
            {"Reliance Jio", {9310, 9315, 9318, 9354, 9625}},
            {"Vodafone Idea", {9355, 9540, 9582, 9643, 9654, 9711, 9718, 9811, 9873, 9891, 9899, 9911, 9953, 9990, 9999}}
        }},
        {"Gujarat", {
            {"AIRTEL", {9033, 9104, 9157, 9173, 9558, 9601, 9662, 9724, 9725, 9898, 9974, 9998}},
            {"BSNL", {9184, 9408, 9409, 9426, 9427, 9428, 9429}},
            {"Reliance Jio", {9016, 9023, 9227, 9265, 9274, 9313, 9316, 9327, 9328, 9510, 9664}}
        }},
        {"Tamil Nadu", {
            {"AIRTEL", {9003, 9042, 9043, 9094, 9150, 9171, 9240, 9384, 9500, 9566, 9597, 9600, 9629, 9677, 9784, 9789, 9790, 9791, 9840, 9842, 9894, 9940, 9941, 9944, 9952, 9994}},
            {"BSNL", {9183, 9195, 9385, 9442, 9443, 9444, 9445, 9486, 9487, 9488, 9489, 9498, 9499}},
            {"Reliance Jio", {9025, 9080, 9280, 9342, 9344, 9345, 9360}},
            {"Vodafone Idea", {9047, 9087, 9092, 9159, 9176, 9585, 9626, 9655, 9751, 9786, 9787, 9843, 9884, 9943, 9962}}
        }},
    
        {"UTTAR PRADESH EAST", {
            {"AIRTEL", {9005,9267, 9044, 9125, 9129, 9151, 9170, 9198, 9559, 9621, 9651, 9695, 9793, 9794, 9935, 9936, 9956}},
            {"BSNL", {9196, 9415, 9450, 9451, 9452, 9453, 9454, 9455, 9473, 9532}},
            {"Reliance Jio", {9026, 9140, 9219, 9235, 9236, 9250, 9305, 9335, 9336, 9369, 9555, 9569, 9580, 9653, 9696}},
            {"Vodafone Idea", {9161, 9506, 9554, 9565, 9598, 9616, 9628, 9648, 9670, 9721, 9792, 9795, 9838, 9839, 9889, 9918, 9919, 9984}}
        }},
        {"UTTAR PRADESH West", {
            {"AIRTEL", {9045, 9058, 9068, 9084, 9557, 9634, 9760, 9897, 9997}},
            {"BSNL", {9410, 9411, 9412, 9456, 9457, 9458}},
            {"Reliance Jio", {9027, 9259, 9368, 9389, 9528, 9548}},
            {"Vodafone Idea", {9012, 9536, 9568, 9627, 9639, 9675, 9690, 9719, 9720, 9756, 9758, 9759, 9761, 9837, 9917, 9927}}
        }},
        {"West Bengal", {
            {"AIRTEL", {9002, 9046, 9126, 9547, 9635, 9679, 9800, 9932, 9933}},
            {"BSNL", {9197, 9434, 9474, 9475, 9476, 9531}},
            {"Reliance Jio", {9239, 9242, 9382, 9641, 9749, 9832, 9883, 9907}},
            {"Vodafone Idea", {9091, 9093, 9564, 9593, 9609, 9647, 9732, 9733, 9734, 9735, 9775}}
        }}
    };





void  generator(int  four){
	int count=0;
   std::ofstream output_file;
   std::string filename=std::to_string(four);
   output_file.open(filename +".txt");
  while (count<=999999){
   std::ostringstream final_string;
    final_string<< four <<std::setw(6)<<std::setfill('0')<<count;
    output_file<<final_string.str()<<"\n";
     count++;
  }
  output_file.close();
}

std::string choose_isp(){
   std::string  ispc2;	
  clear();
  std::cout<<"Choose a ISP from given below\n";
  color("[1]>>AIRTEL","red");

  std::cout<<"\n";
  color("[2]>>BSNL","blue");
  std::cout<<"\n";
  color("[3]>>Reliance Jio","cyan");
  std::cout<<"\n";
  color("[4]>>Vodafone Idea","white");
	
  std::cout<<"\n"<<"Choose a number [>>]";
  std::cin>>ispc2;
  if (ispc2=="1"){
      return "AIRTEL";
  }
  else if (ispc2=="2"){
      return "BSNL";
  }
  else if (ispc2=="3"){
      return "Reliance Jio";
  }
  else if (ispc2=="4"){
      return "Vodafone Idea";
  }
  else{
      std::cout<<"You enter wrong input";
      clear();
      sleep(3);
      return "E";
  }
} 
std::string  intro_func()
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
                  return "E";
	 
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
	std::string  final_state=intro_func();	
std::string  choosed_isp=choose_isp();
clear();
color("PLEASE WAIT GENERATING NUMBERS FOR ","blue");
std::cout<< final_state;
color("AND FINAL OPERATOR","blue");
std::cout<<choosed_isp;
color("IN THE FILE ","blue");
std::cout<<"\n IN Their series code ."<<std::endl;
  auto indict=statecodes.find(final_state);
    auto indictisp=indict->second.find(choosed_isp);
    for (auto each:indictisp->second){
      generator(each);
        
    }

return 0;
}
