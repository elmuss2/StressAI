//THIS IS THE FILE THAT MANAGES ALL OF MY CLASSES IT CONTAIN NODE CLASS - ABSTRACT BASE CLASS AND THREE DERIVED CLASSES
//Gusaue S Abdullatef Elmusraty - CS202 - PROGRAM 2 ON DYNAMIC BINDING
#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;


class node //the class the manages node in the list of DLL
{
	public:
		node(); //defult constructor
		node( char * item, char * itype, char * icond, int amount); //constructor that copies data sent by the user to the node  object data
		~node(); //distructor
		node *& go_next(); //go to the next address
		node *& go_previous(); //go to the previous address
		int set_next( node * tmp); //set the next node
		int set_previous(node * tmp); //set the previous node
		void show_data(); //display data in the node
		bool compare_data( char match); //compare data in the node for display
		bool find_match(char * match);//sent char * to be compared with data for delete
	private:
		
		char * name; //item name
		char * type;// automatic type set in the implemntaion
		char * condition; //product condition
		int price; //price of the product
		node * next; //next pointer
		node * previous;// previous pointer
};

class shop //ABSTRACT BASE CLASS THAT HAVE ALL FUNCTIONS DYNAMICLLY BOUND
{
	public:
		shop();//CONSTRUCTOR 
		virtual ~shop();//DISTRUCTOR
		virtual bool add_product( char * item, char * itype , char * icond , int amount ) = 0;	//PURE VIRTUAL ADD PRODUCT FUNCTION
		virtual bool display_products() = 0;//PURE VIRTUAL DISPLAY FUNCTION THAT DELETES PRODUCT
		virtual bool delete_product( char * match) = 0;//PURE DELETE FUCNTION THAT DELETES PRODUCT
		virtual bool delete_all() = 0; //DELETE ALL PRODUCTS IN THE STOCK



	protected:
		node * head;
};
class new_item:public shop //DERIVED CLASS THAT MANAGES ALL NEW ITEMS SENT BY THE USER AND IMPLEMENT THEM
{
	public:
	new_item(); //CONSTRUCTOR
	~new_item();//DISTRUCTOR
	bool add_product( char * item, char * itype , char * icond , int amount ); //ADD NEW PRODUCT - WRAPPER
	bool display_products();//DISPLAY ONLY THE NEW PRODUCTS - WRAPPER
	bool delete_product( char * match);//DELETE NEW PRODUCT SENT BY USER AFTER COMPARING - WRAPPER
	bool delete_all(); //DELETE ALL ITEMS IN THE LIST - WRAPPER


	private://FUNCTIONS THAT ARE CALLED FROM THE WRAPPERS TO DO THE JOB
	bool add_product( node *& head, node * curr ); 
	bool display_products( node * head);
	bool delete_product(node *& head, char * match, node * curr);
	bool delete_all( node *&head, node * curr);

};
class used_item:public shop //DERIVED CLASS THAT MANAGES ALL USED ITEMS SENT BY THE USER AND IMPLEMENT THEM FOR THE ABSTRACT BASE CLASS
{
	public:
	used_item(); //CONSTRUCTOR
	~used_item();//DISTRUCTOR
	bool add_product( char * item, char * itype , char * icond , int amount ); //ADD USER PRODUCT TO DLL -WRAPPER
	bool display_products(); //DISPLAY ONLY USED PRODUCTS - WRAPPER
	bool delete_product( char * match); //DELETE ONLY THE ONE PRODUCT SENT BY THE USER 
	bool delete_all();//DELETE ALL PRODUCTS IN THE STOCK
	
	private: //FUNCTIONS THAT ARE CALLED FROM THE WRAPPER TO DO THE IMPLEMNTAION
	
	bool add_product( node *& head, node * curr );
	bool display_products( node * head);
	bool delete_product(node *& head, char * match, node * curr);
	bool delete_all( node *&head , node * curr);

};
class electronic:public shop //CLASS THAT MANGES ALL ELECTRONIC PRODUCTS 
{
	public:
	electronic();//CONSTRUCTOR
	~electronic();//DISTRUCTOR 
	bool add_product( char * item, char * itype , char * icond , int amount ); //ADD ELECTRONIC PRODUCT TO THE DLL - WRAPPER
	bool display_products(); //DISPLAY ONLY E-PRODUCTS- WRAPPER
	bool delete_product( char * match); //DELETE REQUISTED ITEM NAME SENT BY THE USER - WRAPPER
	bool search_product( char * match); //DIFFERENT FUNCTION THAN THE BASE CLASS ( DOWNCASTING ) SEARCH FOR E-PRODUCT IN THE LIST
	bool delete_all(); //DELETE ALL PRODUCTS IN THE STOCK

	private: //FUNCTIONS THAT ARE CALLED FROM WRAPPERS TO DO THE IMPLEMENTAION
	bool add_product( node *& head, node * curr );
	bool display_products( node * head);
	bool delete_product(node *& head, char * match, node * curr);
	bool search_product( node * head, char * match); //DOWNCASTED FUNCTION
	bool delete_all( node *& head, node * curr);

};

