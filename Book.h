#pragma once

#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <memory> 


class Book
{
private:
	
	int id;
	std::string title;
	std::string author;
	std::string genre;
	int year;
	bool borrowed=0;

	

public:
	Book();
	Book(int i ,std::string t, std::string a, std::string g, int y, bool b);
	
	Book(const Book& a);
	~Book();
	
	
	std::string get_title() const;
	std::string get_author() const;
    int get_id() const; 
    std::string get_genre() const; 
	int get_year() const;
	bool get_borrowed() const;

	void set_borrowed(bool b);
	void print() const;
	

	Book operator=(const Book &a);
	friend std::ostream& operator<<(std::ostream& os, const Book& book);

	static Book fromBinary(std::ifstream& stream);
};
