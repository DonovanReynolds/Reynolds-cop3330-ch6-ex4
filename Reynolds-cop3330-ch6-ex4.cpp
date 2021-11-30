/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Donovan Reynolds
 */

#include "std_lib_facilities.h"

/*

Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors

*/

class Name_value
{
    private:
        string name;
        double value;
    public:
        Name_value(string name, double value)
        {
            this->name = name;
            this->value = value;
        }
        void setName(string name)
        {
            this->name = name;
        }
        void setValue(double value)
        {
            this->value = value;
        }
        string getName()
        {
            return name;
        }
        double getValue()
        {
            return value;
        }
        bool compareTo(Name_value test)
        {
            if (test.name == this->name)
                throw invalid_argument("");
            return false;
        }
};

int main()
{
    vector <Name_value> allPeople;
    string input;
    double value;
    cin >> input >> value;
        while (input != "NoName" && value != 0)
        {
            Name_value temp(input,value);
            bool exists = false;
            for (Name_value test: allPeople)
            {
                try
                {
                    test.compareTo(temp);
                }catch (invalid_argument &e)
                {
                    cerr << "That name already exists please enter a new name\n";
                    exists = true;
                }
            }

            if (!exists)
                allPeople.push_back(temp);
            cin >> input >> value;
        }
    
    for (Name_value print: allPeople)
    {
        cout << print.getName() << "  " << print.getValue() << "\n";
    }
    

    


}