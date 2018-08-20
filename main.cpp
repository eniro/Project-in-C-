#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "BibElement.h"

string type, id, author, title, journal, volume, booktitle, publisher, pages, year;
string text, temp;
int i, n=0;
fstream FileRead, FileRead1, FileRead2, FileRead3, FileRead4, FileRead5, FileWrite;

BibElement input();
BibElement input1();
BibElement input2();
BibElement input3();
BibElement input4();
BibElement input5();
void print(BibElement bib);
void print1(BibElement bib1);
void print2(BibElement bib2);
void print3(BibElement bib3);
void print4(BibElement bib4);
void print5(BibElement bib5);
void sortById(BibElement array[], int y);
void sortByAuthor(BibElement array[], int y);
void sortByYear(BibElement array[], int y);
void sortByType(BibElement array[], int y);




int main()
{
	string choice, choice2;
	int number=0, number1=0, count=1, x;
	BibElement *array = new BibElement[6];
	array[0] = input();
	array[1] = input1();
	array[2] = input2();
	array[3] = input3();
	array[4] = input4();
	array[5] = input5();
	
	system("CHCP 1253");
	system("CLS");
	cout<<"******************************************************************************************************"<<endl;
	cout<<"Καλωσόρισες στη βάση δεδομένων βιβλιογραφίας!\n";
	while(1){
	
	do{
		cout<<"\nΠληκτρολόγησε τον αριθμό που αντιστοιχεί στην ενέργεια που θες να πραγματοποιήσεις: \n\n 1. Εμφάνιση των περιεχομένων όλων των αρχείων με στοιχεία βιβλιογραφίας που διαθέτει η βάση μας(input.txt, input1.txt, input2.txt, input3.txt, input4.txt, input5.txt)\n\n 2. Ταξινόμηση των στοιχείων βιβλιογραφίας \n\n";
		cin>> x;
	}while(x!=1 && x!=2);
	if(x==1)
	{
		system("CLS");
		print(input());
		cout<<endl;
		print1(input1());
		cout<<endl;
		print2(input2());
		cout<<endl;
		print3(input3());
		cout<<endl;
		print4(input4());
		cout<<endl;
		print5(input5());
		cout<<endl;
	}
	if(x==2)
	{
		system("CLS");
		cout<<"\n***Δώσε πρωτεύον και δευτερεύον κριτήριο ταξινόμησης της βάσης (type, id, author, year). Κατόπιν, η ταξινόμηση θα εκτυπωθεί στην οθόνη σου και θα αποθηκευτεί στο αρχείο output.txt "<<endl;
		cout<<"\n\n"<<"Πρωτεύον κριτήριο(type, id, author, year): "<<endl;
		cin>>choice;
		if(choice != "type" && choice != "TYPE" && choice != "id" && choice != "ID" && choice != "author" && choice != "AUTHOR" && choice != "year" && choice != "YEAR")
			do{
			
				cout<<"Lathos epilogi! Prospathise pali!"<<endl;
				cout<<"\n\n"<<"Prwteuon kritirio: "<<endl;
				cin>>choice;
			}while(choice != "type" && choice != "TYPE" && choice != "id" && choice != "ID" && choice != "author" && choice != "AUTHOR" && choice != "year" && choice != "YEAR");
		
		cout<<"\n\n"<<"Δευτερεύον κριτήριο(type, id, author, year): "<<endl;
		cin>>choice2;
		if(choice2 != "type" && choice2 != "TYPE" && choice2 != "id" && choice2 != "ID" && choice2 != "author" && choice2 != "AUTHOR" && choice2 != "year" && choice2 != "YEAR")
			do{
			
				cout<<"Lathos epilogi! Prospathise pali!"<<endl;
				cout<<"\n\n"<<"Deytereuon kritirio: "<<endl;
				cin>>choice2;
			}while(choice2 != "type" && choice2 != "TYPE" && choice2 != "id" && choice2 != "ID" && choice2 != "author" && choice2 != "AUTHOR" && choice2 != "year" && choice2 != "YEAR");
			
			
		
		//Metatropi epilogis xristi se akeraio arithmo gia xrisi se SWITCH
		if(choice == "id" || choice == "ID")
			number = 1;
		else if(choice == "author" || choice == "AUTHOR")
			number = 2;
		else if(choice == "year" || choice == "YEAR")
			number = 3;
		else if(choice == "type" || choice == "TYPE")
			number = 4;
			
		if(choice2 == "id" || choice2 == "ID")
			number1 = 1;
		else if(choice2 == "author" || choice2 == "AUTHOR")
			number1 = 2;
		else if(choice2 == "year" || choice2 == "YEAR")
			number1 = 3;
		else if(choice2 == "type" || choice2 == "TYPE")
			number1 = 4;
	 
		system("CLS");
		
		switch(number)
		{
			case 1: {
				for(int i = 0; i<6; i++)
					sortById(array, 6);
					if(number1 ==2 || number1 ==3 || number1==4)
						cout<<"Το id είναι μοναδικό!"<<endl;
					
		
				FileWrite.open("output.txt", ios::out);
				if(!FileWrite)
				{
					cerr<<"File is busy...\n"<<endl;
					exit(1);
				}
				for(int i = 0; i<6; i++)
				FileWrite<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
				cout<<"\nΗ ταξινόμηση ολοκληρώθηκε με επιτυχία! Έλεγξε το αρχείο output.txt\n" << endl;
				for(int i = 0; i<6; i++)
				cout<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
				FileWrite.close();
					break;
			}
			case 2: {
				for(int i = 0; i<6; i++)
					sortByAuthor(array, 6);
				/*if(number1==1)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getAuthor() == array[i+1].getAuthor())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortById(array1, count);
				}
				else if(number1==3)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getAuthor() == array[i+1].getAuthor())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortByYear(array1, count);
				}
				else if(number1==4)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getAuthor() == array[i+1].getAuthor())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortByType(array1, count);
				}*/
				FileWrite.open("output.txt", ios::out);
				if(!FileWrite)
				{
					cerr<<"File is busy...\n"<<endl;
					exit(1);
				}
				for(int i = 0; i<6; i++)
				FileWrite<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
				cout<<"\nΗ ταξινόμηση ολοκληρώθηκε με επιτυχία! Έλεγξε το αρχείο output.txt\n" << endl;
				for(int i = 0; i<6; i++)
				cout<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
				FileWrite.close();
					break;
			}
			case 3: {
				for(int i = 0; i<6; i++)
					sortByYear(array, 6);
				/*if(number1==1)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getYear() == array[i+1].getYear())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortById(array1, count);
				}
				else if(number1==2)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getYear() == array[i+1].getYear())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortByAuthor(array1, count);
				}
				else if(number1==4)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getYear() == array[i+1].getYear())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortByType(array1, count);
				}
				*/FileWrite.open("output.txt", ios::out);
				if(!FileWrite)
				{
					cerr<<"File is busy...\n"<<endl;
					exit(1);
				}
				for(int i = 0; i<6; i++)
				FileWrite<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
				cout<<"\nΗ ταξινόμηση ολοκληρώθηκε με επιτυχία! Έλεγξε το αρχείο output.txt\n" << endl;
				for(int i = 0; i<6; i++)
				cout<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
				FileWrite.close();
					break;
			}
			case 4: {
				for(int i = 0; i<6; i++)
					sortByType(array, 6);
				/*if(number1==1)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getType() == array[i+1].getType())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortById(array1, count);
				}
				else if(number1==2)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getType() == array[i+1].getType())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortByAuthor(array1, count);
				}
				else if(number1==3)
				{
					for(int i = 0; i<6; i++)
					{
						if(array[i].getType() == array[i+1].getType())
							count++;
					}
					BibElement *array1 = new BibElement[count];
					for(int i = 0; i<count; i++)
						sortByYear(array1, count);
				}
				*/FileWrite.open("output.txt", ios::out);
				if(!FileWrite)
				{
					cerr<<"File is busy...\n"<<endl;
					exit(1);
				}
				for(int i = 0; i<6; i++)
				FileWrite<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
	
				cout<<"\nΗ ταξινόμηση ολοκληρώθηκε με επιτυχία! Έλεγξε το αρχείο output.txt\n" << endl;
				for(int i = 0; i<6; i++)
				cout<<"\n"<<array[i].getType()<<"\n"<<array[i].getId()<<"\n"<<array[i].getAuthor()<<"\n"<<array[i].getTitle()<<"\n"<<array[i].getPages()<<"\n"<<array[i].getYear()<<endl;
				FileWrite.close();
					break;
			}
		}
	}
}
	
	
	delete []array;
	system("PAUSE");
	return 0;
}



BibElement input()
{
	BibElement bib;
	FileRead.open("input.txt",ios::in);
	if(!FileRead)
	{
		cerr<<"File not found...\n";
		exit(1);
	}
	
	do
	{
		getline(FileRead,text, '}');
		n++;			
	}
	while (!FileRead.eof());
	FileRead.close();
	
	FileRead.open("input.txt",ios::in);
	for (int i = 5; i < 6; i++)
	{
		/*getline(FileRead, temp);
		int x=temp.length();
		type="";
		for(i=0; i<x; i++)
			if(temp[i]=='@')
			{
				temp="";
				temp[i+1]++;
				temp = type;
			}*/
		
		getline(FileRead, type);
		getline(FileRead, id);
		getline(FileRead, author);
		getline(FileRead, title);
		getline(FileRead, booktitle);
		getline(FileRead, pages);
		getline(FileRead, year, '}');
		
	}
	
	bib.setType(type);
	bib.setId(id);
	bib.setAuthor(author);
	bib.setTitle(title);
	bib.setBooktitle(booktitle);
	bib.setPages(pages);
	bib.setYear(year);
	
	FileRead.close();
	return bib;
	
}

void print(BibElement bib)
{
	cout <<"\n"<<bib.getType()<<"\n"<<bib.getId()<<"\n"<<bib.getAuthor()<<"\n"<<bib.getTitle()<<"\n"<<bib.getBooktitle()<<"\n"<<bib.getPages()<<"\n"<< bib.getYear();
}

BibElement input1()
{
	BibElement bib1;
	FileRead1.open("input1.txt",ios::in);
	if(!FileRead1)
	{
		cerr<<"File not found...\n";
		exit(1);
	}
	
	do
	{
		getline(FileRead1,text, '}');
		n++;			
	}
	while (!FileRead1.eof());
	FileRead1.close();
	
	FileRead1.open("input1.txt",ios::in);
	for (int i = 5; i < 6; i++)
	{
		getline(FileRead1, type);
		getline(FileRead1, id);
		getline(FileRead1, author);
		getline(FileRead1, title);
		getline(FileRead1, booktitle);
		getline(FileRead1, pages);
		getline(FileRead1, year, '}');
		
	}

	bib1.setType(type);
	bib1.setId(id);
	bib1.setAuthor(author);
	bib1.setTitle(title);
	bib1.setBooktitle(booktitle);
	bib1.setPages(pages);
	bib1.setYear(year);
	
	FileRead1.close();
	return bib1;
	
	
}

void print1(BibElement bib1)
{
	cout <<"\n"<<bib1.getType()<<"\n"<<bib1.getId()<<"\n"<<bib1.getAuthor()<<"\n"<<bib1.getTitle()<<"\n"<<bib1.getBooktitle()<<"\n"<<bib1.getPages()<<"\n"<< bib1.getYear();
}

BibElement input2()
{
	BibElement bib2;
	
	FileRead2.open("input2.txt",ios::in);
	if(!FileRead2)
	{
		cerr<<"File not found...\n";
		exit(1);
	}
	
	do
	{
		getline(FileRead2,text, '}');
		n++;			
	}
	while (!FileRead2.eof());
	FileRead2.close();
	
	FileRead2.open("input2.txt",ios::in);
	for (int i = 5; i < 6; i++)
	{
		getline(FileRead2, type);
		getline(FileRead2, id);
		getline(FileRead2, author);
		getline(FileRead2, title);
		getline(FileRead2, publisher);
		getline(FileRead2, pages);
		getline(FileRead2, year, '}');
		
	}

	bib2.setType(type);
	bib2.setId(id);
	bib2.setAuthor(author);
	bib2.setTitle(title);
	bib2.setPublisher(publisher);
	bib2.setPages(pages);
	bib2.setYear(year);
	FileRead2.close();
	
	return bib2;
	
}

void print2(BibElement bib2)
{
	cout <<"\n"<<bib2.getType()<<"\n"<<bib2.getId()<<"\n"<<bib2.getAuthor()<<"\n"<<bib2.getTitle()<<"\n"<<bib2.getPublisher()<<"\n"<<bib2.getPages()<<"\n"<< bib2.getYear();
}

BibElement input3()
{
	BibElement bib3;
	FileRead3.open("input3.txt",ios::in);
	if(!FileRead3)
	{
		cerr<<"File not found...\n";
		exit(1);
	}
	
	do
	{
		getline(FileRead3,text, '}');
		n++;			
	}
	while (!FileRead3.eof());
	FileRead3.close();
	
	FileRead3.open("input3.txt",ios::in);
	for (int i = 5; i < 6; i++)
	{
		getline(FileRead3, type);
		getline(FileRead3, id);
		getline(FileRead3, author);
		getline(FileRead3, title);
		getline(FileRead3, volume);
		getline(FileRead3, pages);
		getline(FileRead3, year, '}');
		
	}

	bib3.setType(type);
	bib3.setId(id);
	bib3.setAuthor(author);
	bib3.setTitle(title);
	bib3.setVolume(volume);
	bib3.setPages(pages);
	bib3.setYear(year);
	FileRead3.close();
	
	return bib3;
}

void print3(BibElement bib3)
{
	cout <<"\n"<<bib3.getType()<<"\n"<<bib3.getId()<<"\n"<<bib3.getAuthor()<<"\n"<<bib3.getTitle()<<"\n"<<bib3.getVolume()<<"\n"<<bib3.getPages()<<"\n"<< bib3.getYear();
}

BibElement input4()
{
	BibElement bib4;
	FileRead4.open("input4.txt",ios::in);
	if(!FileRead4)
	{
		cerr<<"File not found...\n";
		exit(1);
	}
	
	do
	{
		getline(FileRead4,text, '}');
		n++;			
	}
	while (!FileRead4.eof());
	FileRead4.close();
	
	FileRead4.open("input4.txt",ios::in);
	for (int i = 5; i < 6; i++)
	{
		getline(FileRead4, type);
		getline(FileRead4, id);
		getline(FileRead4, author);
		getline(FileRead4, title);
		getline(FileRead4, booktitle);
		getline(FileRead4, pages);
		getline(FileRead4, year, '}');
		
	}

	bib4.setType(type);
	bib4.setId(id);
	bib4.setAuthor(author);
	bib4.setTitle(title);
	bib4.setBooktitle(booktitle);
	bib4.setPages(pages);
	bib4.setYear(year);
	FileRead4.close();
	return bib4;
}

void print4(BibElement bib4)
{
	cout <<"\n"<<bib4.getType()<<"\n"<<bib4.getId()<<"\n"<<bib4.getAuthor()<<"\n"<<bib4.getTitle()<<"\n"<<bib4.getBooktitle()<<"\n"<<bib4.getPages()<<"\n"<<bib4.getYear();
}

BibElement input5()
{
	BibElement bib5;
	FileRead5.open("input5.txt",ios::in);
	if(!FileRead5)
	{
		cerr<<"File not found...\n";
		exit(1);
	}
	
	do
	{
		getline(FileRead5,text, '}');
		n++;			
	}
	while (!FileRead5.eof());
	FileRead5.close();
	
	FileRead5.open("input5.txt",ios::in);
	for (int i = 5; i < 6; i++)
	{
		getline(FileRead5, type);
		getline(FileRead5, id);
		getline(FileRead5, author);
		getline(FileRead5, title);
		getline(FileRead5, pages);
		getline(FileRead5, year, '}');
		
	}

	bib5.setType(type);
	bib5.setId(id);
	bib5.setAuthor(author);
	bib5.setTitle(title);
	bib5.setPages(pages);
	bib5.setYear(year);
	FileRead5.close();
	return bib5;
}

void print5(BibElement bib5)
{
	cout <<bib5.getType()<<"\n"<<bib5.getId()<<"\n"<<bib5.getAuthor()<<"\n"<<bib5.getTitle()<<"\n"<<bib5.getPages()<<"\n"<<bib5.getYear();
}

void sortById(BibElement array[], int y)
{
	int i,j;
    BibElement temp;
    for(i=0; i<y; i++)
        for(j=0; j<y-1; j++)
            if(array[j].getId() > array[j+1].getId())
            {
            	temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
            }
} 

void sortByAuthor(BibElement array[], int y)
{
	int i,j;
    BibElement temp;
    for(i=0; i<y; i++)
        for(j=0; j<y-1; j++)
            if(array[j].getAuthor() > array[j+1].getAuthor())
            {
            	temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
            }
	
}

void sortByYear(BibElement array[], int y)
{
	int i,j;
    BibElement temp;
    for(i=0; i<y; i++)
        for(j=0; j<y-1; j++)
            if(array[j].getYear() < array[j+1].getYear())
            {
            	temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
            }
}

void sortByType(BibElement array[], int y)
{
	int i,j;
    BibElement temp;
    for(i=0; i<y; i++)
        for(j=0; j<y-1; j++)
            if(array[j].getType() < array[j+1].getType())
            {
            	temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
            }
}
