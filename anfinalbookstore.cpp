#include<iostream>
#include<fstream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int index[100];int count=0; /// used to index the searched data...

//To create template class que
template<typename T>
class node
{
	T val;
	node* link;
	public: node()
		{
			link=NULL;
		}
		template <typename u> friend class que;
};
template <typename T>
class que
{
	node<T> *front;
	node<T> *rear;
	public: que()
		{
			front=rear=NULL;
		}
		void push(T x)
		{ 
			node<T> *temp=new node<T>;
			temp->val=x;
			temp->link=NULL;
			if(front==NULL)
				front=rear=temp;
			else
			{
				rear->link=temp;
				rear=temp;
			}
		}
		bool pop(T &x)
		{
			if(front==NULL)
				return false;
			node<T> *temp=front;
			x=temp->val;
			if(front==rear)
				front=rear=NULL;
			else
				front=front->link;
			delete(temp);
			return true;
		}
};

/// ## function for check substr found in str or not
bool ifound(string s1,string s2)
{
	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	if (s1.find(s2) != std::string::npos)
    	return true;
	else
		return false;
}

/// class book...
class book
{
	protected:
	string bname;   /// book name
	string aname;   /// author name
	string pub;     /// publisher name
	string type;    /// type of book
	float price;    /// price of book
	int quantity;   /// stock of book

	public:
		/// Default constructor...
		book()
        {   /// initializing all to null values
			bname   = "";
			aname   = "";
			pub     = "";
			type    = "";
			price   = (float)0.0;
			quantity= 0;
		}

        /// constructor with all argument ...
		book(string x,string y,string z, float p,string w,int q)
		{
			bname=x;
			aname=y;
			pub=z;
			price=p;
			type=w;
			quantity=q;
		}

        /// display data of book of back end purpose ...
		void display()
		{
			cout    << bname   <<"  "
                    << aname   <<"  "
                    << pub     <<"  "
                    << type    <<"  "
                    << price   <<"  "
                    << quantity<<"\n";
		}

        /// functions for data fetching from class book ....
		string retname()    { return bname;   }
		string retauthor()  { return aname;   }
		string retpub()     { return pub;     }
		string rettype()    { return type;    }
		float retprice()    { return price;   }
		int retquantity()   { return quantity;}

		/// functions for setting data publicly  ...
		void setprice(float a){price=a;}
		void setquantity(int x){quantity=x;}

        /// for display a book as form of block ...
		void display_box(int id)
		{
			cout << "\n\t_______________________________________\n";
			cout <<"\t|  Book      ID   : " << id   	<< endl
				 <<"\t|  Book      Name : " << bname	<< endl
				 <<"\t|  Author    Name : " << aname	<< endl
				 <<"\t|  Publisher Name : " << pub		<< endl
				 <<"\t|  Catagory       : " << type	<< endl
				 <<"\t|  Price          : " << price << endl
				 <<"\t|  Quantity       : " << quantity	;
				 cout << "\n\t________________________________________\n";
		}

		/// overloading input output operator for book class ...
		friend istream& operator >> (istream& in,book &b);
		friend ostream& operator << (ostream& out,book b);

};

/// class inherit from class book ..
class fiction:public book
{
	public:
	    /// Default constructor for subclass fiction ...
		fiction():book() /// calling constructor of class book
		{
		    type = "fiction" ;   ///  setting book type as fiction remains entity null
		}

		/// constructor with all argument ...
		fiction(string x,string y,string z,float p,int q)
		{
			bname=x;
			aname=y;
			pub=z;
			price=p;
			type="fiction";
			quantity=q;
		}

        /// overloading in/out operator ...
		friend istream& operator >> (istream& in,book &b);
		friend ostream& operator << (ostream& out,book b);
};

/// class inherit from class book ..
class nonfiction:public book
{
	public:
		nonfiction():book()
		{
			type="non-fiction";
		}

		nonfiction(string x,string y,string z,float p,int q)
		{
			bname=x;
			aname=y;
			pub=z;
			price=p;
			type="non-fiction";
			quantity=q;
		}

		friend istream& operator>>(istream& in,book &b);
		friend ostream& operator<<(ostream& out,book b);
};

/// class inherit from class book ..
class scient:public book
{
	public:
		scient():book()
		{
            type="scientific";
		}

		scient(string x,string y,string z,float p,int q)
		{
			bname=x;
			aname=y;
			pub=z;
			price=p;
			type="scientific";
			quantity=q;
		}

		friend istream& operator>>(istream& in,book &b);
        friend ostream& operator<<(ostream& out,book b);
};

/// Defining in/out operator for book class...
istream& operator >> (istream& in,book &b)
{
	getline(in,b.bname);
	getline(in,b.aname);
	getline(in,b.type);
	getline(in,b.pub);
	in>>b.price;
	in>>b.quantity;
	return in;
}

ostream& operator<<(ostream& out,book b)
{
	out<<b.bname<<"\n"<<b.aname<<"\n"<<b.type<<"\n"<<b.pub<<"\n"<<b.price<<"\n"<<b.quantity<<"\n";
	return out;
}
/// #### BOOK CLASS SECTION ENDED ####################################################################
/// ##################################################################################################

class person
{
	protected:
	string name;
	string email;
	public:
		person()
		{
            		name ="";
			email="";
		}
		person(string x,string y)
		{
			name=x;
			email=y;
		}
};

class emp:public person
{
	int eid;
	string password;
	long long phone;

	public:
		emp()
		{
			eid=0;
			phone=0;
		}

		emp(int eno,string x,string y,string z, long ph):person(x,y)
		{
			eid=eno;
			password=z;
			phone=ph;
		}

		string retname()
		{
			return name;
		}

		string retpass()
		{
			return password;
		}

		long long retphone()
		{
			return phone;
		}

		bool login()
		{
			string name,pass;
			emp e;
			int flag=0;

			cout << "\nEnter your employee name:";
            		getline(cin,name);

			cout << "\nPassword to login:";
			getline(cin,pass);

			ifstream fin;
			fin.open("emp.txt",ios::in);
			fin.seekg(0);

			while(!fin.eof())
			{
				fin >> e;
				//cout<<e.retname();
				//cout<<endl<<e.retpass()<<endl;
				if(name==e.retname()  &&   pass==e.retpass())
				{
					flag=1;
					break;
				}
				else
					flag=0;
			}
			fin.close();

			if(flag==1)
				return 1;
			else
				return 0;
		}

		void addbook()
		{
			string choice;
			book *b;
			int j;
			ifstream fin;
			ofstream fout;
			do
			{
				cout    <<"Enter Type Of Book:-"<<"\n"
                        	<<" 1.For Fiction"<<"\n 2.For Non-Fiction"<<"\n 3.For Scientific";
				cin>>j;
				fflush(stdin);

				if (j == 1)
				{
					b=new fiction();
					fout.open("fict.txt",ios::app);
					cin.ignore();
					cin>>(*b);
					fout<<(*b)<<endl;
					fout.close();
  	 			}

				else if(j == 2)
				{
					b=new nonfiction();
					fout.open("nfict.txt",ios::app);
					cin.ignore();
					cin>>(*b);
					fout<<(*b)<<endl;
					fout.close();
                }
				else if (j ==  3)
				{
					b=new scient();
					fout.open("scint.txt",ios::app);
					cin.ignore();
					cin>>(*b);
					fout<<(*b)<<endl;
					fout.close();
                }
                else
                {
                	try
                	{
                		throw j;
                	}
                	catch(int x)
                	{
                		cout<<"EXCEPTION:\nIllegal choice of book\n";
                	}
                }

				cout<<"\nDo you wish to enter any other book(yes/no)\n";
				cin>>choice;
			}while(choice=="yes" || choice == "YES");
		}
		void changebook()
		{
				/*shouldd be able to change price or current quntity of a book*/
			int ini,fin;
			string categ;
			string decision;
			do
			{
			cout<<"Enter the category  of books in which you wish to make changes\n";

			//Check for exception

			cin.ignore();
			getline(cin,categ);
			cout<<"Enter name of the book and author whose details u want to change"<<endl;
			string s;
			string r;
			//cin.ignore();
			getline(cin,s);
			getline(cin,r);
			cout<<s<<endl<<r<<endl;
			cout<<"Do u want to change the price or the quantity?\nPress 1 to change price and 2 to change the quantity"<<endl;
			int y;
			cin>>y;
			if(y==1)
			{
				cout<<"Enter the new price";
				int a;
				cin>>a;
				fstream f;
				book b;
				if(categ=="fiction")
					f.open("fict.txt",ios::out|ios::in);
				else if(categ=="nonfiction")
					f.open("nfict.txt",ios::out|ios::in);
				else
					f.open("scint.txt",ios::out|ios::in);
				f.seekg(0);
				while(!f.eof())
				{
					ini=f.tellg();
					f.ignore();
					f>>b;
					fin=f.tellg();
					if(s==b.retname()&&r==b.retauthor())
					{
						b.setprice(a);
						f.seekg(ini);
						f<<endl<<b;
						break;
					}
				}
				f.close();
			}
			else if(y==2)
			{
				cout<<"Enter the new quantity"<<endl;
				int u,ini,fin;
				cin>>u;
				fstream f;
				book b;
				if(categ=="fiction")
					f.open("fict.txt",ios::out|ios::in);
				else if(categ=="nonfiction")
					f.open("nfict.txt",ios::out|ios::in);
				else
					f.open("scint.txt",ios::out|ios::in);
				f.seekg(0);
				while(!f.eof())
				{
					ini=f.tellg();
					f.ignore();
					f>>b;
					if(s==b.retname()&&r==b.retauthor())
					{
						cout<<"hello\n";
						b.setquantity(u);
						f.seekg(ini);
						f<<endl<<b;
						break;
					}
				}
				f.close();
			}
			else
			{
				try
				{
					throw y;
				}
				catch(int x)
				{
					cout<<"EXCEPTION:\nIllegal choice\n";
				}
			}
				cout<<"Do you want ta make modifications for some other book\n";
				cin>>decision;
			}while(decision=="yes");
		}	
		void delbook()
		{
			/*deletes a book from the books table*/
		}
		friend istream& operator>>(istream& in,emp &e);
		friend ostream& operator<<(ostream& out,emp e);
};

istream& operator>>(istream& in,emp &e)
{
	in>>e.eid;
	in.ignore();
	getline(in,e.name);
	getline(in,e.email);
	getline(in,e.password);
	in>>e.phone;
	return in;
}

ostream& operator<<(ostream& out,emp e)
{
	out<<e.eid<<"\n"<<e.name<<"\n"<<e.password<<"\n"<<e.email<<"\n"<<e.phone;
	return out;
}

class customer:public person
{
	public:
		customer()
		{
		}
		customer(int no,string x,string y):person(x,y)
		{
		}
		void search(string bkname="NONE")
		{
			if(bkname == "NONE" || bkname == "")
			{
				cout << "\n Please Enter Something to search  OR Type (EXIT) to get out from search:";
				cin >> bkname;
				if(bkname =="EXIT" || bkname == "exit")
				{
					return;
				}
				else
					this->search(bkname);
			}

			book all_book[100]; /// to extract all files data into code in one array of book
			que<book> q;
			book b;
			int n;
			ifstream f_in;
			/// fetching data from fict.txt
			f_in.open("fict.txt",ios::in); /// change file name according to final file name
			f_in.seekg(0);
			while(!f_in.eof())
			{
				f_in.ignore();
				f_in >> b;
				q.push(b);
			}
			f_in.close();
			
			/// fetching data from nfict.txt
			f_in.open("nfict.txt",ios::in); /// change file name according to final file name
			f_in.seekg(0);
			while(!f_in.eof())
			{
				f_in.ignore();
				f_in >> b;
				q.push(b);
			}
			f_in.close();

			/// fetching data from scint.txt
			f_in.open("scint.txt",ios::in); /// change file name according to final file name
			f_in.seekg(0);
			for(;!f_in.eof();n++)
			{
				f_in.ignore();
				f_in >> b;
				q.push(b);
			}
			f_in.close();

			int count=0; ///  for indexing of search found...
			while(q.pop(b))
			{
				if (ifound(b.retname(),bkname) || ifound(b.retauthor(),bkname) || ifound(b.retpub(),bkname) || ifound(b.rettype(),bkname) )
				{
					b.display_box(count);
					all_book[count]=b;
					index[count]=count;
					count++;
				}
				if(count>99)
				{
					try
					{
						throw count;
					}
					catch(int l)
					{
						cout<<"ArrayOutOfBounds Exception\n";
					}
				}
			}

			int id;
			string c ="no";
			string xx ="no";

			do{
			cout << "\nEnter Id of book to buy:";
			cin>>id;
			all_book[index[id]].display_box(id);
			cout << "\n Conform(Yes/no):";
			cin >> xx;
			if(xx=="yes" || xx == "YES" || xx == "Yes" )
                this->buy( all_book[index[id]].retname(),all_book[index[id]].retauthor(),all_book[index[id]].rettype());
            else
            {
                cout << "\n $$ Aboted! $$ \n";
                string search_string;
                cout << "\nEnter string for search:";
                getline(cin,search_string);
                this->search(search_string);
            }

			cout << "\nwant to buy more!(yes / no):";
			cin >> c;
			}
			while(c=="yes" || c == "YES" || c == "Yes");

		}



		void buy(string book_name,string auth_name,string book_type)
		{
		    int quan,ini,fin,n;
		    string choice = "no";
		    cout<<book_name<<" "<<auth_name<<" "<<book_type<<endl;
		    cout << "\nEnter no of copies you want to buy:";
		    cin >> quan;
            	    fstream f;
		    book buk;

            if(book_type =="fiction")
                f.open("fict.txt",ios::in|ios::out);
	else if(book_type=="nonfiction")
		f.open("nfict.txt",ios::in|ios::out);
	else if(book_type=="scientific")
		f.open("scint.txt",ios::in|ios::out);

                f.seekg(0);

		while(!f.eof())                
		{
		    ini=f.tellg();
		    f.ignore();
                    f >> buk;
		    fin=f.tellg();
		    if(buk.retname() == book_name && buk.retauthor() == auth_name)
                    {
                        if(quan <= buk.retquantity())
                        {
                            cout << "\nTotal: Rs." << buk.retprice()*quan ;
                            cout << "\nWant to buy(yes/no):";
                            cin >> choice;
                            if(choice =="yes")
                                {
                                    cout << "\n Successfully purchased!!!! ";
                                    buk.setquantity( buk.retquantity() - quan);
				    f.seekg(ini);
				    f<<endl<<buk;
                                    cout << "\n\n\t\t $$ BILL $$\n";

                                    cout << "\n\t_______________________________________\n"
                                         <<"\t|  Total          : " <<  buk.retprice()*quan << endl
                                         <<"\t|  Quantity       : " << quan	;
                                    cout << "\n\t________________________________________\n";

                                }
                            else
                                cout << "\nAborted!!";
                        }
                        else
                        {
                            cout << "\n Sorry out of stock || try with some less count!!";
                            this->buy(book_name , auth_name,book_type);
                        }
		    }
		}
		f.close();
	}
	friend istream& operator>>(istream&,customer&);
	friend ostream& operator<<(ostream&,customer ); 
};

istream& operator>>(istream& in,customer &c)
{
	in.ignore();
	getline(cin,c.name);
	getline(cin,c.email);
}
ostream& operator<<(ostream& out,customer c)
{
	out<<c.name<<" "<<c.email<<endl;
}	
void begemp()
{
	int a;
	emp e1;
	a=e1.login();
	if(a==1)
	{
		cout<<"U have logged in successfully"<<endl;
		cout<<"What do u want to do? Choose the choices given below"<<endl;
		cout<<"1.Add book\n2.Change book\n3.Delete book"<<endl;
		int c;
		cin>>c;
		switch(c)
		{
			case 1:
			{
				e1.addbook();
				break;

			}
			case 2:
			{
				e1.changebook();
				break;
			}
		}
	}
	else
	{
		
		try
		{
			throw a;
		}
		catch(int x)
		{
			cout<<"EXCEPTION:\nInvalid input. Please begin from the start\n";
			exit(0);
		}
	}
		//	cout<<"incorrect name or password..please try logging in again"<<endl;
}

int main()
{
	int choice;
	customer c;
	string tosearch;//String that will be searched for
	cout<<"1 for customer\n2 for employee\n"; 
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter details\n"; 
			cin>>c;
			cout<<"Details enterd are\n";
			cout<<c;
			cout<<"Enter the book or author for which you wish to search for\n";	
			getline(cin,tosearch);
			//cout<<tosearch<<endl;
			c.search(tosearch);
			break;
		case 2:
			begemp();
	}
	return 0;
}


