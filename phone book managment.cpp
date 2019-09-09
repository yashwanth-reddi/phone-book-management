#include<iostream>                                              //input,output
#include<sstream>                                               //tokenization
#include<map>                                                   //storing information temporary               
#include<algorithm>                                             //soring,binary search...etc
#include<string>                                                //string operations
#include<fstream>                                               //file input,output
#include<windows.h>                                             //gotoxy,console colour
#include<conio.h>                                               //getch,gets,getline...etc
#include<time.h>                                                //time 
#include<vector>
using namespace std;
void gotoxy(int x,int y)                                        // going to x,y coordinates
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void border(int xLenS = 3, int yLenS = 3,int xLenE = 150, int yLenE = 30 )    //border
{
	system("cls");
	gotoxy(xLenS,yLenS);printf("%c",201);
	
	gotoxy(xLenS,yLenE);printf("%c",200);
	
    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        gotoxy(i,yLenS);
        printf("%c",205);
        gotoxy(i,yLenE);
        printf("%c",205);
    }
    gotoxy(xLenE,yLenS);printf("%c",187);
    gotoxy(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {   
        gotoxy(xLenS, i);
        printf("%c",186);
        gotoxy(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}

string login()
{
	char ch;
	string UserName;
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
	border(18,8,130,15);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
	gotoxy(45,6);
	cout<<"UserName either admin or user.user can only view.password is password";
	do{
	gotoxy(20,10);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    printf("Enter UserName : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
    getline(cin,UserName);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    }while(UserName.length()==0);
    
    if(UserName=="user")
    {
    	system("cls");
    	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
    	border(18,8,130,15);
    	gotoxy(60,10);
    	cout<<"Login Success!!!";
    	gotoxy(51,12);
    	cout<<"recovering data from file 3 Seconds...";
    	gotoxy(78,12);
    	Sleep(1000);
    	cout<<"\b \b2";
    	gotoxy(78,12);
    	Sleep(1000);
    	cout<<"\b \b1";
    	Sleep(1000);
    	
    	return UserName;
	}
    
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    gotoxy(20,12);
    cout<<"Enter Password : ";
    string Password;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
    while(1)
    {
    	ch = getch();
    	if(ch==13)  //ascii enter
    		break;
    	if(ch==8)   //ascii space
    	    {
    	    	if(Password.length()>0)
    	    	{
    	    	Password.erase(Password.size()-1,1);
    	    	gotoxy(38+Password.size()-1,12);cout<<" ";
    	    	gotoxy(38+Password.size()-1,12);
    	        }
			}
    	else
    	{
			cout<<"*";
			Password.push_back(ch);
    	}
	}
	
    if(UserName=="admin" && Password=="password")
    {
    	system("cls");
    	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
    	border(18,8,130,15);
    	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
    	gotoxy(60,10);
    	cout<<"Login Success!!!";
    	gotoxy(51,12);
    	cout<<"recovering data from file 3 Seconds...";
    	gotoxy(78,12);
    	Sleep(1000);
    	cout<<"\b \b2";
    	gotoxy(78,12);
    	Sleep(1000);
    	cout<<"\b \b1";
    	Sleep(1000);
    	return UserName;
	}
	else
	{
		system("cls");
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
    	border(18,8,130,15);
    	gotoxy(63,10);
    	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
		printf("Access Denied!!!\a");
		gotoxy(55,12);
    	cout<<"Will be redirected in 3 Seconds...";
    	gotoxy(78,12);
    	Sleep(1000);
    	cout<<"\b \b2";
    	gotoxy(78,12);
    	Sleep(1000);
    	cout<<"\b \b1";
    	Sleep(1000);
    	system("cls");
    	return(login());
	}
}

void hline( int x1,int y,int x2)                                //for horizontel line
{
	for(int i=x1;i<=x2;i++)         //Left and Right Border Line
    {   
        gotoxy(i, y);
        printf("%c",205);
    }
}

class Person                                                    //class 
{   string phoneno,fname,lname,email;
public:
	void recoverformfile();                                     //recover data from file and add to maps
	void disp(Person *);                                        //for dispaly
	void add();                                                 //for adding a new contact (name,phoneno,email)
	bool check(multimap<string,Person*>::iterator ,string );    //tokenizing given string,contact name returns whether given string tokens are present in name
    void supersearch();                                         //display all names with given name or phone number even by phrase
	multimap<string,Person*> ::iterator search1();              //for searching and returing iterator pointing to it,if not returns map1.end() iterator{null} 
	multimap<string,Person*> ::iterator searchbyname();         //searching by name
	multimap<string,Person*> ::iterator searchbyphoneno();      //searcing by phone number
	void draw_fill(multimap<string,Person*> &);                 //prints border and fill them with given map
	void changedetails();                                       //changing details
	void get_name(Person *);                                    //get's name
	bool get_phonenumber(Person * );                            //get's phone number returns 0 if you exit
	void get_email(Person * );                                  //get's email
	void deletephoneno();                                       //delete phone number (calls delete in maps)
	void deleteinmaps(Person *);                                //deleting in maps
	string nameset( string );                                   //changing the printed string by set of opreations
	void writeinfile();                                         //writing in file
	void multidelete();                                         //for deleting more numbers at a time
	void menu();                                                //for menu
};
multimap<string,Person*> map1;multimap<string,Person*> map4;    //map1 for storing by first name.map4 is for supersearch
multimap<string,Person*> map2;                                  //map2 for storing by last name  
multimap<string,Person*> map3;multimap<string,Person*> map6;    //map3 for storing by phone number.map6 is for super search
multimap<string,Person*> map5;                                  //for super search

// SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF ); for console colour

void Person::multidelete( )
{
	map <Person*,int> m; 
	multimap<string,Person*>::iterator p=map1.begin();
	int y=6;     
	char c;        
	draw_fill(map1);
	
	for(int i=1;i<=map1.size();i++)		{gotoxy(5,y);cout<<"   ";y+=2;}
	
		gotoxy(0,0);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
		cout<<"enter button for select  backspace button for deselect  press @  for complete \necs to exit ";
		y=6;
		
	do{ gotoxy(5,y);c=getch();
	    switch(c)
		{
			case 72:{y-=2;p--;gotoxy(5,y);break;}
			case 80:{y+=2;gotoxy(5,y);p++;break;}
	        case 13:{SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );cout<<"del";m[p->second]=1;break;}
			case 8:{cout<<"   ";m.erase(p->second);break;}
			case 27:m.clear();return ;
	    }
	}while(c!='@');
	
	for(multimap<Person*,int>::iterator l=m.begin();l!=m.end();)
	{
		multimap<Person*,int>::iterator o=l;
		l++;
		deleteinmaps(o->first);
	}
}

bool Person::get_phonenumber(Person *person)                    // for phone number
{
	string phonenumber;
	int check=1;
	while(check==1)
	{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(7,8);
	cout<<"enter the phone number   :                                                                                        ";
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(35,8);
	getline(cin,phonenumber);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
	for (int i = 0; i < phonenumber.length(); i++)              //checking the number or not , if any alphabet ask again
		if (isdigit(phonenumber[i]) == 0) check=0;
		
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );gotoxy(85,7);
	if(phonenumber.length()==0) {cout<<"please enter name                            ";check=1;}
    else if(check==0){cout<<"number contains  letter or space try again\n";check=1;}
    else if(check==1) {cout<<"                                                   ";check=0;}
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    }
	if(map3.find(phonenumber)==map3.end())                      //if number not present in list it adds the number
	{
	   person->phoneno=phonenumber;
	   map3.insert(pair<string,Person*> (phonenumber,person) );
    }
    else                                                        //present ask's whether to exit or try again
    {
    	gotoxy(7,10);	char y;
    	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
    	cout<<"THIS NUMBER ALREADY EXIXTING IN THE LIST\n";
    	do{
		    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(7,12);
            cout<<"do you want to [1].try another number  [2].want to exit    :                 ";
    	    gotoxy(70,12);y=getch();
        	switch(y)
        	{
    	      case '1' : {
    	      	gotoxy(7,10);cout<<"                                                     ";
    	      	gotoxy(7,12);cout<<"                                                                "; 
    	      	return(get_phonenumber(person));
				break;
			  }
    	      case '2' :  return 0;
    	      default  :  { gotoxy(85,7);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
	                        cout<<"INVALID PRESS 1 OR 2";
                            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );break;}
            }
        }while(y!=1 && y!=2);
	}
}

void Person::get_name(Person *person)                           // for name 
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(7,10);
	cout<<"enter the person's name  :                                                                                           ";
	gotoxy(35,10);  char ch[35],ch2[23];  memset(ch, 0, sizeof(ch));  memset(ch2, 0, sizeof(ch2));  string line,line1,line2;
    do{
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );getline(cin,line);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
       if(line.length()==0)                                     //if number not entered alerts user
       {
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
       	gotoxy(92,7);cout<<" name was not entered ";
		gotoxy(35,10);cout<<"                                  ";gotoxy(35,10);
	   }
    }while(line.length()==0); 
	gotoxy(92,7);cout<<"                       ";
    int k=line.find(' ',0);                                     //find is there any gap 
    if(k==-1)                                                   //if no gap store only first name 
	{ line1=line;              person->fname=line1;           person->lname="-";
	  map1.insert(pair<string,Person*> (line1,person));}
    else                                                        //if gap store in both maps
	{ line.copy(ch,k,0);                                  line.copy(ch2,line.length()-k,k+1);   
	  person->fname=ch;                                   person->lname=ch2;
	  line1=ch;                                           line2=ch2;
	  map1.insert(pair<string,Person*> (line1,person));   map2.insert(pair<string,Person*> (line2,person));}	
}

void Person::get_email(Person *person)                          //for email
{
	string line;  int flage;     char c;
	do{
		flage=1;
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(7,12);
	   cout<<"enter email              :                                                                                          ";
	   SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(35,12);
	   getline(cin,line);gotoxy(92,7);
	   if(line.length()==0)                                     //if length is 0 ask again
	   { 
		   SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
		   cout<<"continue with out email Y/N";c=getch();if(c!='y') flage=0;
		   SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );  
	   }
	   else               
	   {   size_t f= line.find(' ');
		   if( f<line.length() )
		   { SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
		     cout<<"mail ID don't contain space try again"; flage=0;
		   }
		   else{ cout<<"                                          ";  } 
	   }
    }while(flage==0);
	person->email=line;
}

void Person::add()                                              //for adding new contact 
{
	Person *person=new Person;                     
	border();                         
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(68,5);
	cout<<"NEW RECORD";
	bool t=get_phonenumber(person);if(t==0) return ;            //if want to exit add returns 0 then t==0 go's back to menu
	get_name(person);
	get_email(person);

    gotoxy(59,28);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
	cout<<"ENTRED THE NUMBER SUCCESSFULLY";
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
}

void Person::disp(Person *pointer)                              // for dispay contact
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
	if(pointer)
	{
	cout<<"name    :"<<pointer->fname<<" ";if(pointer->lname!="-")cout<<pointer->lname<<endl;else cout<<endl;
    cout<<"phone no:"<<pointer->phoneno<<endl;
	cout<<"email   :"<<pointer->email<<endl<<endl;   
    }
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    return ;
}

void Person::draw_fill(multimap <string,Person*> &map7)         // for drawing and filling in table
{
	system("cls");
	if(map7.size()!=0)
	{
	int count=map7.size();
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(66,6);
	cout<<"LIST WITH GIVEN NAME \n"; 
	border(3,3,150,count*2+6);
	hline(4,5,149);
	gotoxy(4,4);
	cout<<"S.NO ";
	gotoxy(10,4);
	cout<<"NAME ";
    gotoxy(65,4);
	cout<<"PHONE NUMBER";
	gotoxy(120,4);
	cout<<"EMAIL";
	cout<<endl;
	int y=6;
	int i=1;
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
	for(multimap<string,Person*>::iterator it=map7.begin();it!=map7.end();it++)
		{
			gotoxy(5,y);
			cout<<i;
			gotoxy(10,y);
			cout<<it->second->fname<<" "; 
			if(it->second->lname!="-")cout<<it->second->lname;
			gotoxy(65,y);
			cout<<it->second->phoneno;
			gotoxy(120,y);
			cout<<it->second->email;
			y+=2;
			i++;
	   	 }	   	 
    }
    else
    {
	  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );gotoxy(0,4);
	  cout<<endl<<"     zero records ";
	}
}

multimap<string,Person*>::iterator Person::search1()            // for searching
{
	char ch,r;
	do
	{
		system("cls");
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(0,2);
	    cout<<"SEARCH by   [1].name    [2].phone number   [3].exit  :           ";
	    gotoxy(56,2);
	    ch=getch();cout<<ch;
	    switch(ch)
	    {
	    	case '1':return(searchbyname());break;
	    	case '2':return(searchbyphoneno());break;
	    	case '3':return(map1.end());break;
	    	default :SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );gotoxy(82,0);
			         cout<<"invalid \n";
			         gotoxy(75,1);
			         cout<<"want to exit press 1  : ";
			         SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x7 );
					 r=getch();
					 if(r=='1') return map1.end();
		}

    }while(ch!='1' && ch!='2');
}

multimap<string,Person*>::iterator Person::searchbyname()       // for search by name
{
	int f=1,i,j;
	string line,line1,line2;
	do{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(0,5);
	cout<<"enter name     :";
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
	getline(cin,line);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
	}while(line.length()==0);
	if(line.length()==0) return map1.end();
	int k=line.find(" ",0);                                     //dividing into first name,last name
	if(k==-1)
	{
		line1=line;line2="  ";
	}
	else
	{
	  char ch[35],ch2[35];
	  line.copy(ch,k,0);
	  line.copy(ch2,line.length()-k,k+1);
	  line1=ch;line2=ch2;
		f=0;
	}
	//example:yashwanth reddy line1=yashwanth line2=reddy
	//example:yashwanth       line1=yashwanth line2=" "
	//example:reddy           line1=reddy line2=" "
	multimap<string,Person*>::iterator  itr=map1.find(line1); multimap<string,Person*>::iterator  itr2=map2.find(line2);
	if(f)                                                       // if only one word is entered
	{
    	itr2=map2.find(line1);
    	if(itr==map1.end() && itr2==map2.end() )  return map1.end(); //not present in both maps return map.end (null)
	    if(itr!=map1.end() && itr2==map2.end())                      //if present in map1 and not in map2
	    { int count=0; map4.clear();                                         //counting
          for(multimap<string,Person*>::iterator  itrt=itr ; itrt!=map1.end() &&itrt->second->fname==line1 ;itrt++ )
	      { count++; map4.insert(pair<string,Person*>( itrt->first,itrt->second)); }
	      if(count==1) return itr;                              //if only one return itr=map1.find
	      else                                                  //more than one draw and ask
	      {   draw_fill(map4);
	          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(4,count*2+11);
		      cout<<"press the number which one do you want   :        "; int n;
	          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(47,count*2+11);cin>>n;
		      while(n>count)  
		      { 
		    	gotoxy(70,count*2+8);  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
			    cout<<"enter between range  1 to  "<<count;          gotoxy(67,count*2+9);
		        cout<<" if you want to exit enter press 0         "; gotoxy(47,count*2+11);
			    cout<<"               ";                             gotoxy(47,count*2+11);
		        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );cin>>n;
			    if(n==0) return map1.end();
		      }
		      multimap<string,Person*>::iterator  itrn=itr;for(i=1;i<n;itrn++) i++;	map4.clear();   return itrn; 
            }
	     }
	     
		if(itr==map1.end() && itr2!=map2.end())                 //if present in map2 and not in map1
		{
			  int count=0;
			  for(multimap<string,Person*>::iterator  itrt=itr2 ; itrt!=map2.end() &&itrt->second->lname==line1 ;itrt++ )
			  { count++;map4.insert(pair<string,Person*>( itrt->first,itrt->second));  }
			  if(count==1) return itr;                          //if only one return itr=map1.find
		      else                                              //if more draw and ask
		      {
		          draw_fill(map4);
		          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(4,count*2+11);
			      cout<<"press the number which one do you want   :        ";int n;
		          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(47,count*2+11);cin>>n;
			      while(n>count)  
			      { 
			    	gotoxy(70,count*2+8);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
				    cout<<"enter between range  1 to  "<<count;          gotoxy(67,count*2+9);
			        cout<<"  if you want to exit enter press 0         ";gotoxy(47,count*2+11);
				    cout<<"               ";                             gotoxy(47,count*2+11);
			        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA ); cin>>n;
				    if(n==0) return map1.end();
			      }
			      multimap<string,Person*>::iterator  itrn=itr;for(i=1;i<n;itrn++) i++;map4.clear();return itrn; 
	            }
		           
          }
        
        if(itr!=map1.end() && itr2!=map2.end())   //if present i n both maps   ex:a b,b a; search for 'a' should search in both maps
        {
	          int count=0;map4.clear();                                     //counting
	          for(multimap<string,Person*>::iterator  itrt=itr ; itrt!=map1.end() &&itrt->second->fname==line1 ;itrt++ )
		      { count++; map4.insert(pair<string,Person*>( itrt->first,itrt->second)); }
		      for(multimap<string,Person*>::iterator  itrt=itr2 ; itrt!=map2.end() &&itrt->second->lname==line1 ;itrt++ )
			  { count++;map4.insert(pair<string,Person*>( itrt->first,itrt->second));  }	  
              if(count==1) return itr;                          //if only one return itr=map1.find
		      else                                              //if more draw and ask
		      {
		          draw_fill(map4);
		          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(4,count*2+11);
			      cout<<"press the number which one do you want   :        ";int n;
		          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(47,count*2+11);cin>>n;
			      while(n>count)  
			      { 
			    	gotoxy(70,count*2+8);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
				    cout<<"enter between range  1 to  "<<count;        gotoxy(67,count*2+9);
			        cout<<"if you want to exit enter press 0         ";gotoxy(47,count*2+11);
				    cout<<"               ";                           gotoxy(47,count*2+11);
			        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );cin>>n;
				    if(n==0) return map1.end();
			      }
			    multimap<string,Person*>::iterator  itrn=map4.begin();for(i=1;i<n;itrn++) i++;map4.clear();return itrn; 
	            }  
		 }
    }
    else                                       // if two or more word are entered line1=first string lin2=next all strings
    { 
       if(itr==map1.end() && itr2==map2.end()) return map1.end();  //ex:a b search for a b then both first name and second name should be there
       int count=0;
	   for(multimap<string,Person*>::iterator  itrt=itr; itrt!=map1.end() && itrt->first==line1 ;itrt++)   
	   	 if(itrt->second->lname==line2) { count++; map4.insert(pair<string,Person*>( itrt->first,itrt->second));}    
       if(count==0) return map1.end();                          //if count=0 retun map1.end()
	   if(count==1)
	      for(multimap<string,Person*>::iterator  itrt=itr;itrt->second->fname==line1 && itrt->second->lname==line2;itrt++)    
		                     return itrt;
	   else
	    {     draw_fill(map4);
	          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );gotoxy(4,count*2+11);
		      cout<<"press the number which one do you want   :        ";int n;
	          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );gotoxy(47,count*2+11);cin>>n;
		      while(n>count)  
		      { 
		    	gotoxy(70,count*2+8);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
			    cout<<"enter between range  1 to  "<<count;        gotoxy(67,count*2+9);
		        cout<<"if you want to exit enter press 0         ";gotoxy(47,count*2+11);
			    cout<<"               ";                           gotoxy(47,count*2+11);
		        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );cin>>n;
			    if(n==0) return map1.end();
		      }
	          multimap<string,Person*>::iterator  itrn=map4.begin();for(i=1;i<n;itrn++) i++;map4.clear();return itrn; 
        }
	  }
}

multimap<string,Person*>::iterator Person::searchbyphoneno()    // for searcing by number
{
	cout<<"\n \n enter phone number:  ";
	string number; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
	cin>>number;
	map<string,Person*>::iterator  itr=map3.find(number);
	if(itr!=map3.end()) return itr;
	else return map1.end();
}

void Person::deletephoneno()                                    // deleting contact
{
	system("cls");int ch;
	multimap<string,Person*>::iterator  itr=search1();Person *itr2=itr->second;
	if(itr==map1.end()) cout<<"not found"; 
	else deleteinmaps(itr2);
}
void Person::deleteinmaps(Person *person)                       // deleting in maps
{
	string p,f,l;
	p=person->phoneno;f=person->fname;l=person->lname;
	multimap<string,Person*>::iterator  itr1=map3.find(p);      //for deleting in number map
	multimap<string,Person*>::iterator  itr2=map1.find(f);      //for deleting in first name map
	multimap<string,Person*>::iterator  itr3=map2.find(l);      //for deleting in second name map
	 while(1) 
	    if(itr2->first==f && itr2->second->lname==l && itr2->second->phoneno==p)
             break;
        else itr2++;             
     if(itr3!=map2.end())
       while(1)
           if(itr3->first==l && itr3->second->fname==f && itr3->second->phoneno==p )
              break;
           else itr3++;
    free(itr1->second);
	map3.erase(itr1);
	if(itr3!=map2.end())map2.erase(itr3);
	map1.erase(itr2);
}

void Person::changedetails()                                    //modifing data
{   
    string line;    char c;  map<string,Person*>::iterator  itr=search1();
	if(itr==map1.end()) 
	{   system("cls");SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
		cout<<"NOT FOUND"<<endl; 
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );	return ;	}
    int flage;   Person *p=new Person; 	system("cls");
	if(itr!=map1.end())
	{
		do{
	    p->phoneno=itr->second->phoneno;p->fname=itr->second->fname;p->lname=itr->second->lname;p->email=itr->second->email;
          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
		  cout<<"\n[1].change in name  [2].in phonenumber   [3].change in email  [4].exit   : ";c=getch();cout<<c;flage=0;
		  switch(c)
		  { case '1':{  cin.ignore();get_name(p);map3.insert(pair<string,Person*> (p->phoneno,p)); break;  } 
		  	case '2':{  cin.ignore();get_phonenumber(p);map1.insert(pair<string,Person*> (p->fname,p));
				  	    if(p->lname.at(0)!='-' && p->lname.length()!=1) map2.insert(pair<string,Person*> (p->lname,p));
						break;}
			case '3':{  cin.ignore(); get_email(p);
				        map3.insert(pair<string,Person*> (p->phoneno,p));map1.insert(pair<string,Person*> (p->fname,p));
		  		        if(line!="-")map2.insert(pair<string,Person*> (p->lname,p));break;}
			case '4': return ;
		  	default : flage=1;cout<<"invalid ";break;}
		if(c=='1'||c=='2'||c=='3') { deleteinmaps(itr->second);}
       }while(flage);
	 SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF ); gotoxy(0,20);  disp(p);
    }
}






            /////// you can remove nameset,supersearch,check to remove super search feature///// 

bool Person::check(multimap<string,Person*> :: iterator it,string line1) //check whethe given strign tokens are present or not
{
	vector <string> tokens1;  
    stringstream check1(line1); 
    string intermediate; 
    while(getline(check1, intermediate, ' '))                   //tokenization given line
       tokens1.push_back(intermediate); 
	
	string line2;
	line2.append( it->second->fname );
	if(it->second->lname!="-")
	{
	  line2.push_back(' ');
	  line2.append( it->second->lname );
    }
	vector <string> tokens2;  
    stringstream check2(line2); 
    while(getline(check2, intermediate, ' '))                   //tokenization of first name, second name
       tokens2.push_back(intermediate);   
       
	vector <int> s1;
	int s2=0;
	                                               // checking all token present or not if present return 1 not return 0 
	for(int i=0;i<tokens1.size();i++)          
	{
	 for(int j=0;j<tokens2.size();j++)
	  {
	    size_t f=tokens2[j].find(tokens1[i]);
	    if(f==0) s2=1;
	  }
	  if(s2==1) s1.push_back(1);
	  else s1.push_back(0);
	  
	  s2=0;
    }
	
	for(int x=0;x<s1.size();x++ ) if(s1[x]==0) {s1.clear();return 0;}
	s1.clear();
	return 1;
	
}
   	

char ch;
int position=0;
string Person::nameset(string s)                                //changing the printed string by set of opreations
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
gotoxy(0,0);
string d=s;
char temp[30],temp2[30];
int x=position,y=1;cout<<"enter name or phone number             press enter to exit  \n";
cout<<s;              //print string
gotoxy(x,y);          // go's to position
do
{
ch=getch();            // gets charecter
switch(ch)
{
	case 77         : //for right arrow
	                 if( position<s.length() ) {gotoxy(++x,y);position++;}  break; 
	
	case 75         : //for left arrow
	                 if(position>0){gotoxy(--x,y);position--;   }          break;
	
	case 'a' ... 'z': // for letters
	                 {
	                 	if(position<d.size()) 
	                 	{
	                 			d.copy(temp,d.length()-position,position);d.copy(temp2,position,0);
	                 			d.clear();
	                 			d.append(temp2);d.push_back(ch);d.append(temp);	
						 }
						 else d.push_back(ch);
						 					  
	                  position++;gotoxy(++x,y);return d;
					 }
	case '0' ... '9': // for numbers
	                 {
					  if(position<d.size()) d[position]=ch; else d.push_back(ch);
	                  position++;gotoxy(++x,y);return d;
					 }
	case 8          :// for backspace
	                 {
	                    if(position<d.length() && position>0)
		                {
	                    d.copy(temp,d.length()-position,position+1);d.copy(temp2,position,0);
						d.clear();d.append(temp2);d.append(temp);
					    }
						else if(position==d.length() && position>0) {position--;gotoxy(--x,y);cout<<" ";gotoxy(x,y);d.erase(position);
						}     
						return d;                              
					 }
	case ' '        : // for space bar
	                   {
		                if(position<d.length() && position>0)
		                {
		                d.copy(temp,d.length()-position,position);d.copy(temp2,position,0);
						cout<<" "<<temp;
						d.clear();d.append(temp2);d.push_back(' ');d.append(temp);
						gotoxy(++x,y);position++;
					    }
					    if(position==d.length())
					    {
					    	position++;
					    	gotoxy(++x,y);
					    	d.push_back(' ');
						}
						return d;
                     }
}
memset(temp, 0, sizeof(temp));
memset(temp2, 0, sizeof(temp2));

}while(ch!=13);          //if enter loop terminates
} 

void Person::supersearch()                                      //display all names with given name or phone number even for phases
{
	position=0;
	if(map1.empty()) {cout<<"record is Empty";return ; }
	string line,d;
	int count;
	system("cls");
	line=nameset(line);       //get's letter 
	
	while(1)
	{
		int flage=1;
		for (int i = 0; i < line.length(); i++) 
		  if (isdigit(line[i]) == 0) 
		      flage=0;
		      
		 cout<<endl;
		if(flage==1)         //if number 
		{
		  for(multimap<string,Person*>::iterator  itr=map6.begin();itr!=map6.end();itr++)
		  {
		  	string l=itr->first;
		  	auto i=search(l.begin(), l.end(), line.begin(), line.end());
		    if( i!=l.end() ) map5.insert(pair<string,Person*> (itr->first,itr->second) ); 
	      }
	      map6=map5;
	      map5.clear();
	      draw_fill(map6);
	      
	    d=nameset(line);
		for(int i=0;i<line.length();i++)
		  if(d[i]!=line[i])
		  map6=map3;
	      
		}
		else                 //if name
		{
		for(multimap<string,Person*>::iterator  itr=map4.begin();itr!=map4.end();itr++)
		   if(check(itr,line)) map5.insert(pair<string,Person*> (itr->first,itr->second) );
   
		   map4.clear();  map4=map5;  map5.clear();
		    
	     draw_fill(map4); 
	    
		  d=nameset(line);
		  for(int i=0;i<line.length();i++)
		  if(d[i]!=line[i])
		  map4=map1;
		}
		  
		line=d;
	    system("cls");
		if(ch==13)break;
	    
	}
	
}

void Person::writeinfile()                                      // writing in fire
{
	ofstream myfile("phone book.txt");
	if (myfile.is_open())
  {
  	for(multimap<string,Person*>::iterator  itr=map1.begin();itr!=map1.end();itr++)
  	{
  		myfile<<itr->first<<"\n";
  		myfile<<itr->second->lname<<"\n";
  		myfile<<itr->second->phoneno<<"\n";
  		myfile<<itr->second->email<<"\n";
	}
    myfile.close();
  }
  
 	
}

void Person::recoverformfile()                                  // reading from file and updating maps for operations
{
  string line,line2;
  ifstream myfile ("phone book.txt");
  int count=0;
  cout<<endl;
  Person *p=new Person;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    { 	
      	if(count%4==0)p->fname=line;
      	if(count%4==1){p->lname=line;line2=line;}
      	if(count%4==2)p->phoneno=line;
      	if(count%4==3)p->email=line;
      	if(count%4==3)
		  {
		  	map1.insert(pair<string,Person*> (p->fname,p));
		  	
	    	if(line2.at(0)!='-' && line.length()!=1) map2.insert(pair<string,Person*> (p->lname,p));
		  	
		  	map3.insert(pair<string,Person*> (p->phoneno,p));
		  	Person *temp=new Person;
		  	p=temp;
    	  }	  
      	count++;
    }
    myfile.close();
  }
}

void Person::menu()
{
	system("cls");
    char choise;
    
    while(1)
    {   
	    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA );
    	cout<<"                                                       phonebook   management ";
    	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    	cout<<"\n\n[1].Add a phone number";
    	cout<<"\n[2].Edit a phone number";
    	cout<<"\n[3].search";
    	cout<<"\n[4].Delete a phone number";
    	cout<<"\n[5].multi delete";
    	cout<<"\n[6].list";
    	cout<<"\n[7].Advanced search";
        cout<<"\n[8].exit  for writing into file ";
  		cout<<"\nEnter you choise    :";
        choise=getch();
		cout<<choise;
        cout<<endl;
        switch(choise)
        {
        	case '1':{ border();add(); gotoxy(7,29);            break;}
        	case '2':{ changedetails();gotoxy(7,29);           break;}
        	case '3':{
        		      if(map3.size()==0) cout<<"NO RECORDS"; 
        		      else
        		      {
			          map<string,Person*>::iterator  itr=search1();
			          system("cls");
			          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
			          if(itr!=map1.end()) disp(itr->second);
        	          else
					  {
					    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
					    cout<<"NOT FOUND"<<endl; 
					  }
					  cin.ignore();
					  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
				      }
					                                                       break;
					}
        	case '4':{
			          deletephoneno();
					  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
			          cout<<"    THE NUMBER IS DELETED";  gotoxy(7,29);
					  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
					  cin.ignore();
					  break;
					 }
			case '5':{int co=map1.size()*2+10;
			          if(map1.size()!=0) 
					  {
					    multidelete();
					    gotoxy(7,co);
			            cout<<" SELECTED NUUMBERS ARE DELETED ";  gotoxy(7,29);
			          
				       }
		        	  else
					  {
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
						cout<<"no contact "<<endl;
					  }	  
				      
			          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF ); 
					  	
					  gotoxy(7,co+2);	
					  break;
					 }
        	case '6':{
			          draw_fill(map1);
					  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
		              gotoxy(4,map1.size()*2+11);
			                                                                break;
					 }
        	case '7':{ 
			           map4=map1;map6=map3;supersearch();              break;}
			case '8':{
			          writeinfile();
					  map1.clear();map2.clear();map3.clear();map4.clear();map5.clear();map6.clear();
			          exit(0);                                           
					                                                     break;
					 }
        	default:{
			         SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );gotoxy(0,30);
			         cout<<"invalid ";gotoxy(0,31);                        break;
					}
        
		}
		
        system("pause");
    	system("cls");
    }
}

int main()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1275, 580, TRUE);
    
    
    string Username=login();
    
    Person obj;
    obj.recoverformfile();
    char ch;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    
    if(Username=="admin")obj.menu();
    if(map1.size()==0)
    {
       system("cls");
       cout<<"zero contacts \n";
       SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
       system("pause");
       return 0;
	}
	
    if(Username=="user")
    {
    	do{
    		system("cls");
    		
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
    	     cout<<"[1].search [2].exit \n";
    	     cout<<"enter your choise   :  ";ch=getch();
    	     switch(ch)
    	     {
    	     case '1':{	
					  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF );
					  multimap<string,Person*>::iterator itr=obj.search1();
					  if(itr!=map1.end()) obj.disp(itr->second);
		        	  else
					  {
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC );
						cout<<"NOT FOUND"<<endl; getch();
					  }	  
				      break;
			          }
			  case '2':exit(0);
			  default: cout<<"Invalid";
			           cout<<"\n \n try again in 2 seconds";
			           Sleep(2000);
		     }
		    
		}while(1);
	}
	
}
