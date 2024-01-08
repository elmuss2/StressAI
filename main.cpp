//client program to interact with the user. it takes all data sent by the user and implement them in other file 
//Gusaue S Abdullatef Elmusraty - CS202

#include "classes.h"


int main()
{
	new_item my_new;    //derived class object 
	used_item my_used;
	electronic my_e;
	//***********************************************************************
	char ans; //do while variable
	//***********************************************************************
	char * item = NULL;
	char * itype = NULL; //temporary variables to send them to implemntaion 
	char * icond = NULL;
	int amount =0;
	//**********************************************************************
	int choice = 0; 
	char tmp[200]; //temporary VARIABLES
	char * match = NULL;
	//************************************************************************
	//Dynmaic binding
	shop * ptr[3];
	ptr[0] = &my_new;	//array of base pointer points to derived objects
	ptr[1] = &my_used;
	ptr[2] = &my_e;
	
	//**********************************************************************

	cout << "Welcome to iShop store where you can buy and sell products, Please choose one of the options:" << endl;
	

	do
	{
		
		cout << "What type of products you are intersted in: 1- New product 2- Used product 3- Electronic product " << endl;
		cin >> choice;
		cin.ignore(100,'\n');

		if( choice == 1) // options for new product
		{       cout<<"That is a great choise!"<<endl;
			cout<<"Please choose one of the options:"<<endl;
			cout<<"1-Sell new product"<<endl;
			cout<<"2-Display all new products in invetory"<<endl;
			cout<<"3-Buy new product"<<endl;
			cout<<"4-Buy all items" <<endl;
			cin >> choice;
			cin.ignore(100,'\n');
			if ( choice == 1) //add product to the stock
			{
				cout << "Please enter the product name:";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');

				item = new char [strlen(tmp) + 1];
				strcpy(item,tmp);
				
					
				
				cout << "Please enter the product condition (excellent/good/damged/bad):";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');

				icond = new char [strlen(tmp) + 1];
				strcpy(icond,tmp);

				
				cout << "Please enter the product price:";
				cin >> amount;
				cin.ignore(100,'\n');
				
	
				bool done = ptr[0]->add_product(item,itype,icond,amount); //call function with base class pointer on index 0 which
											  //has refrence to the new item object - dynamic binding
				if(done)
				{
					cout <<"The insertion is done." << endl;
				}
				
			

			}
			else if(choice == 2)
			{
	
				bool done = ptr[0]->display_products(); //call the display function with base class pointer

				if(done)
				{
					cout << "Here is your list:" << endl;
				}
				else
				{
					cout << "Nothing to show here!" << endl;
				}

			}
			else if(choice == 3)
			{
				cout << "Please enter the name of the product you want to buy:" << endl;
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');
				
				match = new char [strlen(tmp)+1];
				strcpy(match,tmp);
				bool done = ptr[0]->delete_product(match);// call the display function with base pointer
				if(done)
				{
					cout << "Phe purchase is done!" << endl;
				}
				else
				{
					cout << "Sorry, the product is out of stock" << endl;
				}
                                //delete match;
			}
			else if(choice == 4)
			{
				
				bool done = ptr[0]->delete_all(); //same here for delete it uses the reference for the object and call it
								  // with base pointer
				if(done)
				{
					cout << "Wow!!! you bought everything!" << endl;
				}
				else
				{
					cout << "The stock is empty" << endl;
				}


				


			}


		}
		else if( choice == 2) //used item managment
		{
			
			cout << " choose one of the options: 1- Sell used  product 2- Display all used products in invetory 3- Buy used  product 4 - buy all items" <<endl;
			cin >> choice;
			cin.ignore(100,'\n');
			if ( choice == 1)
			{
				cout << "Please enter the product name:";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');

				item = new char [strlen(tmp) + 1];
				strcpy(item,tmp);
				
					
				
				cout << "Please enter the product condition (excellent/good/damged/bad):";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');

				icond = new char [strlen(tmp) + 1];
				strcpy(icond,tmp);

				
				cout << "Please enter the product price:";
				cin >> amount;
				cin.ignore(100,'\n');
				
	
				bool done = ptr[1]->add_product(item,itype,icond,amount);//call add used product with the base pointer  
				if(done)
				{
					cout <<"The insertion is done" << endl;
				}
				
			



			}
			else if(choice == 2)
			{
	
				bool done = ptr[1]->display_products();

				if(done)
				{
					cout << "Here is your list!" << endl;
				}
				else
				{
					cout << "Nothing to show here." << endl;
				}

			}
			else if(choice == 3)
			{
				
				cout << "Please enter the name of the product you want to buy";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');
				
				match = new char [strlen(tmp)+1];
				strcpy(match,tmp);

				bool done = ptr[1]->delete_product(match);//call the delete product with a pointer to a derived refrence for used object
				if(done)
				{
					cout << "The purchase was done!";
				}
				else
				{
					cout << "Product is out of stock" << endl;
				}


                                
			}
			else if(choice == 4)
			{
				bool done = ptr[1]->delete_all(); //clear stock using the same pointer 
				if(done)
				{
					cout << "wow!!! you bought everything" << endl;
				}
				else
				{
					cout << "Stock is empty " << endl;
				}


			}
		


		}
		else if ( choice == 3)
		{


			cout << "Choose one of the options: 1- Sell electronic product 2- Display all electronic products in invetory 3- Buy electronic product 4 - buy all items 5- search for elctronic item" <<endl;
			cin >> choice;
			cin.ignore(100,'\n');
			if ( choice == 1)
			{
				cout << "Please enter the product name:";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');

				item = new char [strlen(tmp) + 1];
				strcpy(item,tmp);
				
					
				
				cout << "Please enter the product condition (excellent/good/damged/bad):";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');

				icond = new char [strlen(tmp) + 1];
				strcpy(icond,tmp);

				
				cout << "Please enter the product price ";
				cin >> amount;
				cin.ignore(100,'\n');
				
	
				bool done = ptr[2]->add_product(item,itype,icond,amount); //add e-item to the DLL using base pointer to an Electronic
											  //object
				if(done)
				{
					cout <<"The insertion is done" << endl;
				}
				


			}
			else if(choice == 2)
			{
	
				bool done = ptr[2]->display_products(); //display e-items only with the base pointer 

				if(done)
				{
					cout << "Here is your list" << endl;
				}
				else
				{
					cout << "Nothing to show here" << endl;
				}

			}
			else if(choice == 3)
			{
				
				cout << "Please enter the name of the product you want to buy:";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');
				
				match = new char [strlen(tmp)+1];
				strcpy(match,tmp);

				bool done = ptr[2]->delete_product(match); //delete e-item sent by the user using same method
				if(done)
				{
					cout << "The purchase was done!" << endl;
				}
				else
				{
					cout << "Product is out of stock" << endl;
				}



			}
			else if(choice == 4)
			{
				
				bool done = ptr[2]->delete_all(); //clear stock 
				if(done)
				{
					cout << "wow!!! you bought everything" << endl;
				}
				else
				{
					cout << "Stock is empty" << endl;
				}


				


			}
			//This choice for RTTI method where we convert base pointer to derived pointer
			else if(choice == 5)
			{

				electronic * pt; //derived class pointer
				pt = dynamic_cast<electronic*>(ptr[2]); //downcast using RTTI using dynamic binding to convert base pointer 
									//to derived pointer 

				cout << "Please enter the name of the electronic product you want to search for:";
				cin.get(tmp,200,'\n');
				cin.ignore(100,'\n');
				match = new char [strlen(tmp) + 1];
				strcpy(match,tmp);


				bool done = pt->search_product(match); //call search product with derived pointer after conversion
				if(done)
				{
					cout << "match found for:" << match << endl;
				}
				else
				{
					cout << "sorry, no match!!" << endl;
				}
		

			}
		
			

			


		}
		cout << "Do you want to do another command before you exit (y/n)" << endl;
	 	cin >> ans;
	 	cin.ignore(100,'\n');

	}while( ans == 'y' || ans == 'Y');
	




	return 0;
}
