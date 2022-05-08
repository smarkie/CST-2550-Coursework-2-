/* 
    main.cpp
    Author: Smith Rajesh Dbritto
    Created: 04/2022
    Updated: 05/2022
    
    References: 
	cjamesm (2012) ‘Answer to “How to loop back to the beginning of a switch statement after a case”’, Stack Overflow. Available at: 			https://stackoverflow.com/a/13089413 (Accessed: 6 May 2022).

	How to read CSV file in C++? - Java2Blog (2021). Available at: https://java2blog.com/read-csv-filein-cpp/ (Accessed: 6 May 2022).

	Input/output with files - C++ Tutorials (no date). Available at:
	https://www.cplusplus.com/doc/tutorial/files/ (Accessed: 20 April 2022).

	Read data from csv file and store it to linked list || Search data from linked list || in C++ - YouTube
	(no date). Available at: https://www.youtube.com/ (Accessed: 6 May 2022).

*/

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
#include <sstream>
#include "node.h"
#include "list.h"

// Allowing user to specify the input file name as command line argument
void load()
{
    std::string filename;
 	std::cout<<"Enter the name of the file ( with extensions eg. File.txt): ";
 	std::cin>>filename;
 	std::vector<std::vector<std::string>> content;
 	std::vector<std::string> row;
 	std::string line, word;

 	std::fstream file (filename, std::ios::in);
 	if(file.is_open())
 	{
 		while(getline(file, line))
 		{
 			row.clear();
 			std::stringstream str(line);
 			while(std::getline(str, word, ','))
 			row.push_back(word);
 			content.push_back(row);
 		}
 	}
 	else
            std::cout<<"Error: Could not find the file\n";
 	        for(int i=0;i<content.size();i++)
 	        {
 		        for(int j=0;j<content[i].size();j++)
 		            {
 			            std::cout<<content[i][j]<<" ";
 		            }
 		        std::cout<<"\n";
 	    }
}

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
    
    // Loads the file
    std::string Datafilepath= "FILE.txt";
    std::ifstream File(Datafilepath);
    list *l1= new list(Datafilepath);

    // Added label for iterating within the case
    label:

    // User interface visible from the terminal
    std::cout<<"---------Automated Car Parking System---------\n";
    std::cout<<"----------------------------------------------\n";
    std::cout<<" 1.Enter Car Info to ENTER/EXIT to Car Park System \n";
    std::cout<<" 2.Display Current Records\n";
    std::cout<<" 3.Calculate the parking charge.\n";
    std::cout<<" 4.Exit\n";

    std::cout<<"Enter your choice:\n";
    std::cin>>option;

    // Switch case for the user input
    switch (option){
    
    case 1:{

    std::cout<<"Enter your car information: \n";
    std::cin>>VRN;
    std::cout<<"Enter current date: \n";
    std::cin>>Date;
    std::cout<<"Enter current time: \n";
    std::cin>>TimeIn;
    std::cout<<"Enter exit time: \n";
    std::cin>>TimeOut;
    
    std::cout<<"Details are as follows: \n";
    std::cout<<VRN<<", \t"<<Date<<" ,"<<TimeIn<<","<<TimeOut<<"\n";

    // User input validation #1
    std::cout<<"Do you wish to save it to the file? \n";
    std::string ans;
    std::cin>>ans;
    if(ans=="y")
    {
        std::cout<<"Exiting program. \n";
        std::fstream file;
        file.open("FILE.txt", std::ios::app);
        
            if(file.is_open());
            {
            file<<"\n"<<VRN<<", \t"<<Date<<","<<TimeIn<<","<<TimeOut<<"\n";
            file.close();
    }
    }
    
    // goes to label to restart the loop
    else 
        {
        return 0;
        }
    }
    break;
    
    case 2: 
    {
        // Displaying all the vehicles in the parking system
        load();
    }
    break;
    
    case 3:
    {
        std::cout<<"4.Calculate the parking charge.\n";
        l1->search();
        std::cout<<"Enter time to entrance:\n [HOURS : MINUTES] (Do not include"<<':'<<") \n";
        std::cin>>x;
        std::cout<<"Enter time of exit:\n [HOURS : MINUTES] (Do not include"<<':'<<") \n";
        std::cin>>y;
        duration = y-x;
        std::cout<<"Calculating....\n";

    if (duration<1)
    {
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
    }
    break;
       
    case 4:
    {
        std::cout<<"Do you want to save changes? (y/n) : \n";
        std::string answer;
        std::cin>> answer;
    if(answer=="y")
    {
        std::cout<<"Exiting program. \n";
    }
    
    // goes to label to restart the loop
    else {
        goto label;
    }
    
    // Exit
    return 0;
    }
    break;
    }
}
