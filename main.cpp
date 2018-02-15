#include <iostream>                 //cin,cout
#include <string>                   //string
#include <sstream>                  //istringstream
#include <fstream>                  //ifstream

#include "ShoppingCart.h"
using namespace std;

ifstream inFile;
ShoppingCart SCart;            //new shopping cart

//open input file
bool openInput(){
    //open input file
    cout << "Enter input file name: " << endl;
    char* inFilename;                          //filename holder
    cin >> inFilename;
    inFile.open(inFilename);
    if (!inFile.is_open()){                    //input file cannot be opened
        return 0;
    }
    return 1;
}

//read file and perform operations
void readfile(){
	string line;
	while (getline(inFile, line))           //get the line
	{
	    istringstream iss(line);
	    string s;                           //take the first string
	    iss >> s;
	    if (s=="A"){                        //add
	    	string description;
	    	int cost=0, quantity=0, pos=0;
	    	iss >> description >> cost >> quantity;
	    	ItemToPurchase item(description,cost,quantity); //item to be added
	    	if (!(iss >> pos)){
                SCart.addItemToEnd(item);                   //Add item to the end of cart
                cout << "Add successful!" << endl;
			}else{
				if (SCart.addItem(item,pos-1)){                   //Add item to the position pos-1
                    cout << "Add successful!" << endl;
				}else{
				    cout << "Add unsuccessful!" << endl;
				}
			}
		}else if (s=="R"){                  //remove item at position pos-1
		    int pos = 0;                    //position
		    iss >> pos;
            if (SCart.removeItem(pos-1)){
                cout << "Remove successful!" << endl;
            }else{
                cout << "Remove unsuccessful!" << endl;
            }
		}else if (s=="D"){                  //Display item at position pos-1
		    int pos = 0;                    //position
		    iss >> pos;
		    if (!SCart.displayItem(pos-1)){
                cout << "Display unsuccessful!" << endl;
		    }
		}else if (s=="DA"){                 //Display all items
		    SCart.displayItems();
		}else if (s=="DC"){                 //Display total cost
		    int pos = 0;                    //position
		    if (iss >> pos){                //DC pos
                if (!SCart.displayTotalCost(pos)){
                    cout << "Display unsuccessful!" << endl;
                }
		    }else{                          //DC
		        SCart.displayTotalCostAllItems();
		    }
		}else if (s=="DN"){                 //Number of items
		    SCart.displayNumberOfItems();
		}
	}
}

int main()
{
    //open input file
    if (!openInput()){
        cout << "Unable to open file" << endl;
        return 1;
    }

    //read file and perform operations
    readfile();
    inFile.close();                 //close input;
    return 0;
}
