#include "Book.h"

Book::Book()
{
	std::cout << "\nEnter id: \t";
	std::cin >> id;
	std::cout << "\nName the author: \t";
	std::cin >> author;
	std::cout << "\nName the title: \t";
	std::cin >> title;
	std::cout << "\nEnter the year: \t";
	std::cin >> year;
	std::cout << "\nEnter the genre: \t";
	std::cin >> genre;
	borrowed = false; 
}

Book::Book(int i, std::string t, std::string a, std::string g, int y, bool b) : id(i), title(t), author(a), genre(g), year(y), borrowed(b)
{
}


Book::~Book()
{
}

void Book::set_borrowed(bool b)
{

	
	this->borrowed = b;
}

void Book::print() const
{
	std::cout << "\n Id: \t" << id << std::endl;
	std::cout << "\n Title: \t" << title << std::endl;
	std::cout << "\n Author: \t" << author << std::endl;
	std::cout << "\n Year: \t" << year << std::endl;
	if (borrowed) {
		std::cout << "\n Is Borrowed: \t" << "yes" << std::endl;
	}
	else {
		std::cout << "\n Is Borrowed: \t" << "no" << std::endl;
	}
}

std::string Book::get_title() const
{
	return title;
}

std::string Book::get_author() const
{
	return author;
}

int Book::get_id() const
{
	return id;
}

std::string Book::get_genre() const
{
	return genre;
}

int Book::get_year() const
{
	return year;
}

bool Book::get_borrowed() const
{
	return borrowed;
}

Book::Book(const Book& a)
{
	id = a.id;
	author = a.author;
	title = a.title;
	genre = a.genre;
	year = a.year;
	borrowed = a.borrowed;
}

Book Book::operator=(const Book& a)
{
	if (this != &a){
		id = a.id;
		author = a.author;
		title = a.title;
		genre = a.genre;
		year = a.year;
		borrowed = a.borrowed;


		}
	return *this;
	
}

Book Book::fromBinary(std::ifstream& stream)
{
	int id;
	stream.read(reinterpret_cast<char*>(&id), sizeof(id));

	
	int titleSize;
	stream.read(reinterpret_cast<char*>(&titleSize), sizeof(titleSize));
	std::string title(titleSize, ' ');
	stream.read(&title[0], titleSize);

	
	int authorSize;
	stream.read(reinterpret_cast<char*>(&authorSize), sizeof(authorSize));
	std::string author(authorSize, ' ');
	stream.read(&author[0], authorSize);

	
	int genreSize;
	stream.read(reinterpret_cast<char*>(&genreSize), sizeof(genreSize));
	std::string genre(genreSize, ' ');
	stream.read(&genre[0], genreSize);

	
	int year;
	stream.read(reinterpret_cast<char*>(&year), sizeof(year));

	
	bool borrowed;
	stream.read(reinterpret_cast<char*>(&borrowed), sizeof(borrowed));

	return Book(id, title, author, genre, year, borrowed);
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	
	os.write(reinterpret_cast<const char*>(&book.id), sizeof(book.id));

	
	int titleSize = book.title.size();
	os.write(reinterpret_cast<const char*>(&titleSize), sizeof(titleSize));
	os.write(book.title.c_str(), titleSize);

	
	int authorSize = book.author.size();
	os.write(reinterpret_cast<const char*>(&authorSize), sizeof(authorSize));
	os.write(book.author.c_str(), authorSize);

	
	int genreSize = book.genre.size();
	os.write(reinterpret_cast<const char*>(&genreSize), sizeof(genreSize));
	os.write(book.genre.c_str(), genreSize);

	
	os.write(reinterpret_cast<const char*>(&book.year), sizeof(book.year));

	
	os.write(reinterpret_cast<const char*>(&book.borrowed), sizeof(book.borrowed));

	return os;
}
