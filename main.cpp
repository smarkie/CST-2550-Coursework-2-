/* 
Name: Smith Rajesh Dbritto
Student ID: M00689896
*/

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "node.h"
#include "list.h"

int main()
{
    
    int option;
    int duration;
    float price;
    int count = 0, x,y; 
    
    std::string Date;
    std::string VRN;
    std::string TimeIn;
    std::string TimeOut;

    std::ifstream File("file.csv");
    std::string Datafilepath= "file.csv";
    list *l1= new list(Datafilepath);

    std::cout<<"---------Automated Car Parking System---------\n";
    std::cout<<"----------------------------------------------\n";
    std::cout<<" 1.Enter Car Info to ENTER to Car Park System \n";
    std::cout<<" 2.Enter Car Info to EXIT to Car Park System  \n";
    std::cout<<" 3.Display Current Records\n";
    std::cout<<" 4.Calculate the parking charge.\n";
    std::cout<<" 5.Exit\n";

    std::cout<<"Enter your choice:\n";
    std::cin>>option;
    
    std::ofstream myfile;
    myfile.open("file.csv");

    switch (option){
    
    case 1:
    std::cout<<"!\n";
    break;
    
    case 2:
    std::cout<<"Your Car has now been exited from the system! \n";
    l1->search();
    break;
    
    case 3: 
    std::cout<<"Displaying all the records: \n";
    l1->display();
    break;
    
    case 4:
    std::cout<<"4.Calculate the parking charge.\n";
    l1->search();
    std::cout<<"Enter time to entrance:\n HOURS_MINUTES \n";
    std::cin>>x;

    std::cout<<"Enter time of exit:\n HOURS_MINUTES \n";
    std::cin>>y;

    duration = y-x;
    std::cout<<"Calculating....\n";

    if (duration<1){
    price=0;
    std::cout<<"\nFree \n";
    }
    else if(duration=1){
    price=1.5;
    std::cout<<"\nCharged for 1 hour. Parking charge is:"<< price <<"£ \n";
    }
    else if(duration<=2){
    price=3;
    std::cout<<"\nCharged for up to 2 hours. Parking charge is:"<< price <<"£ \n";
    }
    else if(duration<=4){
    price=5;
    std::cout<<"\nCharged for up to 4 hours. Parking charge is:"<< price <<"£ \n";
    }
    else if(duration<=8){
    price=15;
    std::cout<<"\nCharged for up to 8 hours. Parking charge is:"<< price <<"£ \n";
    }
    else if(duration>8){
    price=30;
    std::cout<<"\nCharged for over 8 hours. Parking charge is:"<< price <<"£";
    }
    
    break;
       
    case 5:
    // Exit
    return 0;

    break;
    }
    
    if(File.is_open())
    {
        while (!File.eof())
        {
            if(count==0)
            {
                std::string temp;
                std::getline(File, temp);
                count = 1;
            }
            else
            {
                std::getline(File, Date, ',');
                std::getline(File, VRN, ',');
                std::getline(File, TimeIn, ',');
                std::getline(File, TimeOut, '\n');
            
                l1->insert( Date, VRN, TimeIn, TimeOut);
            }
        }
    }
    else 
    {
        std::cout<<"Error!"<<std::endl;       
    }
    return 0;
  
}