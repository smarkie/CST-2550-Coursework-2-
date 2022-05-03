#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "list.h"

list::list()
{
    head=NULL;
    tail=NULL;
}

list::list(std::string Filepath)
{
    std::ofstream myfile;
    myfile.open("file.csv");
    head=NULL;
    tail=NULL;
}

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

void list::search()
{
    node* temp;
    temp = head;
    std::string input;
    std::cout<<"Enter Car ID: \n"<<std::endl;
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