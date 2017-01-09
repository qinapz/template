#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string.h>

using namespace std;

#ifndef book_base_hpp
#define book_base_hpp

class Book{
	public:
		string author;
		string type;
		unsigned int pages;
		int available;
		
		Book(string a, string t, int p, int av): author(a), type(t), pages(p), available(av){}
		Book(): author("Not known"), type("Not known"), pages(0), available(1){}
		friend std::ostream & operator <<( std::ostream & s, const Book& m){
				s << "Author: " << setw(20) << m.author << setw(15) << "category: " << setw(15) << m.type
					<< setw(12) << "pages: " << setw(5) << m.pages
					<< setw(20) << "available: ";
				if (m.available)
					s << "available";
				else
					s << "not available";
				return s;
			}
};
# endif
