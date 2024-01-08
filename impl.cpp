//This is where I implement all the functions for my derived classes
//Gusaue S Abdullatef Elmusraty - CS202

#include "classes.h"

node::node() //Constructor for the node class to set all data memebrs and pointers
{
	
	name = NULL;
	type = NULL;
	condition =NULL; 
	price = 0;
	next = NULL;
	previous = NULL;

}
node::~node() //delete all dynamic memory and set pointers to null
{
	
	delete name;
	delete type;
	delete condition;
	price = 0;
	
	next = NULL;
	previous = NULL;

}
node::node( char * item , char * itype, char * icond, int amount) //constructor with arguments to copy data sent by user to the data members in node class
{
	
		name = new char [strlen(item) + 1];
		strcpy(name,item);
		type = new char [strlen(itype) + 1];
		strcpy(type,itype);
		condition = new char [strlen(icond) + 1];
		strcpy(condition,icond);
		price = amount;
		set_next(NULL);
		set_previous(NULL);


}
node*& node::go_next() //return the next pointer 
{
	return next;
}
node *& node::go_previous() //return the previous pointer
{
	return previous;
}
int node::set_next( node * tmp) //set next to whatever argument sent by the program
{
	next = tmp;

	return 0;
}
int node::set_previous( node * tmp) //set previous to whatever argument sent by the program 
{
	previous = tmp;
	
	return 0;
}
void node::show_data() //display nodes data whenever requested 
{
	cout << "item name:  " << name << endl;
	cout << "the type :  " << type << endl;
	cout << "the condition of the item is:  "<< condition << endl;
	cout << "the cost:  "<<  price << "$" << endl;
	cout << " ____________________________" << endl;
	return;
}
bool node::compare_data(char match) //compare type of the item in the node for display 
{
	if(match == type[0])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool node::find_match( char * match) //compare data by name for deleting 
{
	if(strcmp(match,name) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

shop::shop() //abstract base class constructor
{

	head = NULL; 


}
shop::~shop() //destructor for base class
{
	


}
//**********************************************************************************************
new_item::new_item() 
{
}
new_item::~new_item()
{


}
used_item::used_item()  			//derived classes constructors and distructoros 
{

}
used_item::~used_item()
{

}
electronic::electronic()
{

}
electronic::~electronic()
{

}
//********************************************************************************************
bool new_item::add_product( char * item, char * itype, char * icond , int amount) //add new product to DLL 
{

		char array[4] = "new"; 
		itype = new char [strlen(array)+1]; //set type to new 
		strcpy(itype,array); 

		node * curr = new node(item,itype,icond,amount); //set data by calling the node constructor with argument 
		bool done = add_product(head,curr); //call the add function for new 
		if(done)
		{
		        delete itype;
			return true;
		}
		else
		{
			return false;
		}
	

}
bool new_item::add_product( node *& head, node * curr) //add product to DLL
{
	if(!head) //IF NO LIST ADD AT THE BIGGENING 
	{
		head = curr;
		head->set_next(NULL);
		head->set_previous(NULL);
		return true;
	}
	else // ADD AND EXTEND THE LIST 
	{
		curr->set_next(head);
		head->set_previous(curr);
		head = curr;
		return true;
	}
}
bool new_item::display_products() //DISPLAY NEW ITEMS 
{
	if(!head) //NO LIST 
	{
		return false;
	}
	else
	{
		display_products(head); //CALL DISPLAY 
		return true;
		
	}
}
bool new_item::display_products( node * head) //DISPLAY ONLY NEW ITEMS BASED ON TYPE 
{
	if(head->go_next()  == NULL) //LAST ITEM
	{
		if(head->compare_data('n')) //COMPARE BASED ON TYPE
		{
			head->show_data(); //SHOW NODES DATA 
			return true;
		}
		else
		{
			return true;
		}
	}
	else //ALL ITEMS BEFORE LAST 
	{
		if(head->compare_data('n')) //CHECK TYPE
		{
			head->show_data(); //DISPLAY NODES DATA 
			display_products(head->go_next()); //CALL FUNCTION WITH NEXT
		}
		else
		{
			
			display_products(head->go_next()); //NO MATCH CALL NEXT 
		}
			
	}
}
bool new_item::delete_product( char * match ) //DETLETE PRODUCT BASED ON WHAT USER ASK
{
	if(!head) //NO HEAD
	{
		return false;
	}
	else
	{
		node * curr = head; //CURRENT POINTER SET TO HEAD
		bool done  = delete_product(head,match,curr); //CALL FUNCTION
		if(done)
		{
		
			return true; //RETURN TRUE IF MATCH FOUND AND DELETING DONE
		}
		else
		{
			return false;
		}
	}
}
bool new_item::delete_product( node *&head, char * match, node * curr) //DELETE MATCH
{
	if(curr->find_match(match)) //CHECK MATCH
	{
		if(!curr->go_previous()) //ONLY ONE ITEM IN LIST 
		{
			delete curr;
			head = NULL;
			return true;
		}
		else if( !curr->go_next() && curr->go_previous()) //MID OF THE LIST DELETING 
		{
			curr->go_previous()->go_next() = NULL;
			curr->go_previous() = NULL;
			delete curr;
			return true;
		}
		else //LAST ITEMS 
		{
		
			curr->go_next()->go_previous() = curr->go_previous(); 
			curr->go_previous()->go_next() = curr->go_next();
		

			delete curr;
		
			return true;
		}

	}
	else
	{
		delete_product(head,match,curr->go_next()); //CALL FUNCTION WITH NEXT 
		return true;
	}


}

bool new_item::delete_all() //DELETE ALL ITEMS 
{

	if(!head) //NO LIST
	{
		return false;
	}
	else
	{
		node * curr = head;
		bool done = delete_all(head,curr); //CALL FUNCTION 
		if(done)
		{
			return true;
		}
		else
		{
			return false;
		}

	}



}
bool new_item::delete_all( node *& head, node * curr) //DELETE ALL ITEMS 
{
	if(!curr->go_next()) 
	{
		return true;
	}
	else
	{
		node * tmp; //SET TMP
		delete_all(head,curr->go_next()); //CALL FUNCTION WITH NEXT 
		tmp = curr->go_next();
		curr->set_next(NULL);
		delete tmp; //DELETE TMP
	}
	

}

bool used_item::add_product( char * item, char * itype, char * icond , int amount) //ADD USED ITEM 
{

		char array[5] = "used"; //SET TYPE TO USED 
		itype = new char [strlen(array)+1];
		strcpy(itype,array); 

		node * curr = new node(item,itype,icond,amount); //CALL CONSTRUCTOR WITH ARGUMENTS TO SET DATA AND COPY IT 
		bool done = add_product(head,curr); //CALL ADD
		if(done)
		{
		        delete itype;
			return true;
		}
		else
		{
			return false;
		}

}
bool used_item::add_product( node *& head, node * curr) //ADD USED PRODUCT TO THE DLL
{
	if(!head)
	{
		head = curr;
		head->set_next(NULL);
		head->set_previous(NULL);
		return true;
	}
	else
	{
		curr->set_next(head);
		head->set_previous(curr);
		head = curr;
		return true;
	}
}
bool used_item::display_products() //DISPLAY USED ITEMS 
{
	if(!head)
	{
		return false;
	}
	else
	{
		display_products(head);
		return true;
		
	}
}
bool used_item::display_products( node * head) //DISPLAY ONLY USED ITEMS 
{
	if(head->go_next()  == NULL)
	{
		if(head->compare_data('u')) //CHECK TYPE
		{
			head->show_data();
			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if(head->compare_data('u')) //CHECK TYPE
		{
			head->show_data();
			display_products(head->go_next());
		}
		else
		{
			
			display_products(head->go_next());
		}
			
	}
}

bool used_item::delete_product( char * match ) //DELETE ITEM
{
	if(!head)
	{
		return false;
	}
	else
	{
		node * curr = head;
		bool done  = delete_product(head,match,curr);
		if(done)
		{
		
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool used_item::delete_product( node *&head, char * match, node * curr) //DELETE REQUISTED ITEM NAME 
{
	if(curr->find_match(match)) //CHECK NAME 
	{
		if(!curr->go_previous())
		{
			delete curr;
			head = NULL;
			return true;
		}
		else if( !curr->go_next() && curr->go_previous())
		{
			curr->go_previous()->go_next() = NULL;
			curr->go_previous() = NULL;
			delete curr;
			return true;
		}
		else
		{
		
			curr->go_next()->go_previous() = curr->go_previous();
			curr->go_previous()->go_next() = curr->go_next();
		

			delete curr;
		
			return true;
		}
		

		

	}
	else
	{
		delete_product(head,match,curr->go_next());
		return false;
	}


}
bool used_item::delete_all() //DELETE ALL ITEMS IN THE STOCK
{

	if(!head)
	{
		return false;
	}
	else
	{
		node * curr = head;
		bool done = delete_all(head,curr);
		if(done)
		{
			return true;
		}
		else
		{
			return false;
		}

	}



}
bool used_item::delete_all( node *& head, node * curr) //CLEAR THE STOCK REGARDLESS OF TYPE
{
	if(!curr->go_next())
	{
		return true;
	}
	else
	{
		node * tmp;
		delete_all(head,curr->go_next());
		tmp = curr->go_next();
		curr->set_next(NULL);
		delete tmp;
	}
	

}
	
bool electronic::add_product( char * item, char * itype, char * icond , int amount) //ADD ELECTRONIC ITEM TO DLL
{

		char array[11] = "electronic"; //SET TYPE
		itype = new char [strlen(array)+1];
		strcpy(itype,array); 

		node * curr = new node(item,itype,icond,amount);
		bool done = add_product(head,curr);
		if(done)
		{
		       delete itype;	
                       return true;
		}
		else
		{
			return false;
		}
	

}
bool electronic::add_product( node *& head, node * curr) //ADD TO THE PERFECT PLACE ON THE LIST 
{
	if(!head)
	{
		head = curr;
		head->set_next(NULL);
		head->set_previous(NULL);
		return true;
	}
	else
	{
		curr->set_next(head);
		head->set_previous(curr);
		head = curr;
		return true;
	}
}
bool electronic::display_products() //DISPLAY E PRODUCTS ONLY WRAPPER 
{
	if(!head)
	{
		return false;
	}
	else
	{
		display_products(head);
		return true;
		
	}
}
bool electronic::display_products( node * head) //DISPALY ONLY E-ITEMS 
{
	if(head->go_next()  == NULL)
	{
		if(head->compare_data('e')) //CHECK TYPE 
		{
			head->show_data();
			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if(head->compare_data('e')) //CHECK TYPE
		{
			head->show_data();
			display_products(head->go_next());
		}
		else
		{
			
			display_products(head->go_next());
		}
			
	}
}

bool electronic::delete_product( char * match ) //DELETE REQUISTED ITEM 
{
	if(!head)
	{
		return false;
	}
	else
	{
		node * curr = head;
		bool done  = delete_product(head,match,curr);
		if(done)
		{
		
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool electronic::delete_product( node *&head, char * match, node * curr) //SEARCH FOR NAME MATCH AND DELETE IT IN THE DLL OF STOCK 
{
	if(curr->find_match(match))
	{
		if(!curr->go_previous())
		{
			delete curr;
			head = NULL;
			return true;
		}
		else if( !curr->go_next() && curr->go_previous())
		{
			curr->go_previous()->go_next() = NULL;
			curr->go_previous() = NULL;
			delete curr;
			return true;
		}
		else
		{
		
			curr->go_next()->go_previous() = curr->go_previous();
			curr->go_previous()->go_next() = curr->go_next();
		

			delete curr;
		
			return true;
		}

	}
	else
	{
		delete_product(head,match,curr->go_next());
		return true;
	}


}
bool electronic::search_product( char * match) //DOWNCASTED FUNCTION TO SEARCH FOR ITEM 
{

	if(!head)
	{
		return false;
	}
	else
	{
		bool done = search_product(head,match);
		if(done)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool electronic::search_product( node * head, char * match) //FIND MATCH IN THE STOCK 
{
	if(head->find_match(match))
	{

		return true;
	}
	else
	{
		search_product(head->go_next(),match);
		return false;
	}
}

bool electronic::delete_all() //DELETE ALL ITEMS IN THE STOCK OR BUY THEM IN OTHER WORDS 
{

	if(!head)
	{
		return false;
	}
	else
	{
		node * curr = head;
		bool done = delete_all(head,curr);
		if(done)
		{
			return true;
		}
		else
		{
			return false;
		}

	}



}
bool electronic::delete_all( node *& head, node * curr) //DELETE ALL ITEMS IN THE LIST 
{
	if(!curr->go_next())
	{
		return true;
	}
	else
	{
		node * tmp;
		delete_all(head,curr->go_next());
		tmp = curr->go_next();
		curr->set_next(NULL);
		delete tmp;
	}
	

}

	
