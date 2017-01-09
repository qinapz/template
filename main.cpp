#include "map_template.hpp"
#include "employee.hpp"
#include "book_base.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	typedef unsigned int ID; 											//Identification number of Employee
	Map<ID,Employee> database;											//Database of employees

	database.insert(761028073,Employee("Jan Kowalski","salesman",28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.insert(510212881,Employee("Adam Nowak","storekeeper",54)); //Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	database.insert(730505129,Employee("Anna Zaradna","secretary",32)); //Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << database << endl;											//Print database

	Map<ID,Employee> newDatabase = database;							//Make a copy of database
	
	Employee* pE;
	pE = &newDatabase[510212881];										//Find employee using its ID
	pE->position = "salesman";											//Modify the position of employee
	pE = &newDatabase[761028073];										//Find employee using its ID
	pE->age = 29;														//Modify the age of employee

	database = newDatabase;												//Update original database
	
	cout << database << endl;
	
	
	// LIBRARY EXAMPLE
	typedef string TITLE; 											
	Map<TITLE,Book> bookDatabase;											

	bookDatabase.insert("Kod Da Vinci",Book("Dan Brown", "thriller", 555, 0));
	bookDatabase.insert("Metro 2035",Book("Dmitriy Nukhovsky", "science fiction", 1110, 1));
	bookDatabase.insert("Cyfrowa Twierdza",Book("Dan Brown", "science fiction", 666, 1));

	cout << bookDatabase << endl;											

	Map<TITLE,Book> newBookDatabase = bookDatabase;							
	
	Book* pB;
	pB = &newBookDatabase["Metro 2035"];										
	pB->author = "Dmitriy Glukhovsky";											
	pB = &newBookDatabase["Cyfrowa Twierdza"];										
	pB->pages = 333;								

	bookDatabase = newBookDatabase;												
	
	cout << bookDatabase << endl;
	
    return 0;
}
