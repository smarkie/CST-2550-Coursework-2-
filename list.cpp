/* 
    list.cpp
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
#include <vector>
#include "node.h"
#include "list.h"

list::list()
{
    head=NULL;
    tail=NULL;
}

list::list(std::string Filepath)
{
    head=NULL;
    tail=NULL;
}

// created a constructor to add different items to a file
void list::insert(std::string date,std::string vrn,std::string timein,std::string timeout)
{
    node* newnode = new node(date, vrn, timein, timeout);
    if (head==NULL)
    {
        head= newnode;
        tail= newnode;
    }
    else
    {
    tail->next = newnode;
    tail = newnode;
    }
}

// created a constructor to display all the items in a file
void list::display()
{
    if (!head)
    {
        std::cout<<"File was not found."<< std::endl;
    }
    else
    {
        node* temp = head;
        while(temp != NULL)
        {
            std::cout<<temp->Date;
            std::cout<<temp->VRN;
            std::cout<<temp->TimeIn;
            std::cout<<temp->TimeOut;

            temp = temp->next;
        }
    }
}

// created a constructor to search items from a file
void list::search()
{
    node *temp;
    temp = head;
    std::string input;

    std::getline(std::cin, input);
    bool bl = false;

    while (temp != NULL)
    {
        if (temp->VRN == input)
        {
            std::cout<<temp->Date;
            std::cout<<temp->VRN;
            std::cout<<temp->TimeIn;
            std::cout<<temp->TimeOut;
            bl = true;
            system("pause");
        }
        temp = temp->next;       
    }
    if (bl == false)
    {
        std::cout<<"NOT FOUND."<< std::endl;
    }
}
