#ifndef BIBELEMENT_H
#define BIBELEMENT_H

class BibElement
{
	private:
		string type, id, author, title, journal, volume, booktitle, publisher, pages, year;
	public:
		void setType(string x){type = x;}
		void setId(string x){id = x;}
		void setAuthor(string x){author = x;}
		void setTitle(string x){title = x;}
		void setJournal(string x){journal = x;}
		void setVolume(string x){volume = x;}
		void setBooktitle(string x){booktitle = x;}
		void setPublisher(string x){publisher = x;}
		void setPages(string x){pages = x;}
		void setYear(string x){year = x;}
		string getType(){return type;}
		string getId(){return id;}
		string getAuthor(){return author;}
		string getTitle(){return title;}
		string getJournal(){return journal;}
		string getVolume(){return volume;}
		string getBooktitle(){return booktitle;}
		string getPublisher(){return publisher;}
		string getPages(){return pages;}
		string getYear(){return year;}
	
	
};
#endif
