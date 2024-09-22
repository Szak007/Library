#include "Function.h"
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

bool get_params(int num, char* params[], std::string& file_one, std::string& file_output)
{
	std::cout << params[0] << "\n";
	if (num < 5) {
		std::cout << "Nie poprawna ilosc parametrow\n";
		return 0;
	}
	for (int i = 1; i < num; i += 2) {
		if ((std::string)params[i] == "-f") {
			std::ifstream f_one(params[i + 1]);
			file_one = params[i + 1];
			if (!f_one) {
				std::cout << "File one dont work\n";
				return 0;
			}

		}
		else if ((std::string)params[i] == "-o") {
			std::ifstream f_out(params[i + 1]);
			file_one = params[i + 1];
			if (!f_out) {
				std::cout << "Output file dont work\n";
				return 0;
			}

		}
		else {
			std::cout << "Wrong parameters\n";
		}
		
	}
	return 1;
}





void sort_books(list_of_books<Book>& books_list) {
	int choice;
	std::cout << "Choose sorting criterion:\n";
	std::cout << "1. Title\n";
	std::cout << "2. Author\n";
	std::cout << "3. Genre\n";
	std::cout << "4. Year\n";
	std::cout << "5. Borrowed\n";
	std::cin >> choice;

	switch (choice) {
	case 1:
		books_list.sort_books_by(&Book::get_title);
		break;
	case 2:
		books_list.sort_books_by(&Book::get_author);
		break;
	case 3:
		books_list.sort_books_by(&Book::get_genre);
		break;
	case 4:
		books_list.sort_books_by_year();
		break;
	case 5:
		books_list.sort_books_by_borrowed();
		break;
	default:
		std::cout << "Invalid choice\n";
		break;
	}

	std::cout << "Books sorted successfully.\n";
	books_list.display_books();
}


void find_title(list_of_books<Book>& books_list) {
	std::string title_to_find;
	std::cout << "\nName the title: \t";
	std::cin >> title_to_find;

	std::list<Book> found_books = books_list.find_books_by_title(title_to_find);

	if (found_books.empty()) {
		std::cout << "No books found with title '" << title_to_find << "'.\n";
	}
	else {
		std::cout << "Found books with title '" << title_to_find << "':\n";
		for (const auto& book : found_books) {
			book.print(); 
			std::cout << std::endl;
		}
	}
}





void display_found_books(const std::list<Book>& found_books) {
	if (found_books.empty()) {
		std::cout << "No books found.\n";
	}
	else {
		std::cout << "Found books:\n";
		for (const auto& book : found_books) {
			book.print();
			std::cout << std::endl;
		}
	}
}



void find_books(list_of_books<Book>& books_list) {
	int choice;
	std::cout << "Choose search criterion:\n";
	std::cout << "1. ID\n";
	std::cout << "2. Title\n";
	std::cout << "3. Author\n";
	std::cout << "4. Genre\n";
	std::cout << "5. Year\n";
	std::cout << "6. Borrowed\n";
	std::cin >> choice;

	switch (choice) {
	case 1: {
		int id;
		std::cout << "Enter ID: ";
		std::cin >> id;
		auto found_books = books_list.find_books_by_id(id);
		display_found_books(found_books);
		break;
	}
	case 2: {
		std::string title;
		std::cout << "Enter title: ";
		std::cin >> title;
		auto found_books = books_list.find_books_by(&Book::get_title, title);
		display_found_books(found_books);
		break;
	}
	case 3: {
		std::string author;
		std::cout << "Enter author: ";
		std::cin >> author;
		auto found_books = books_list.find_books_by(&Book::get_author, author);
		display_found_books(found_books);
		break;
	}
	case 4: {
		std::string genre;
		std::cout << "Enter genre: ";
		std::cin >> genre;
		auto found_books = books_list.find_books_by(&Book::get_genre, genre);
		display_found_books(found_books);
		break;
	}
	case 5: {
		int year;
		std::cout << "Enter year: ";
		std::cin >> year;
		auto found_books = books_list.find_books_by_year(year);
		display_found_books(found_books);
		break;
	}
	case 6: {
		auto found_books = books_list.find_borrowed_books();
		display_found_books(found_books);
		break;
	}
	default:
		std::cout << "Invalid choice\n";
		break;
	}
}



int execution(std::string file_one, std::string file_output)
{
	
	list_of_books<Book> books_list;
	
	books_list.load_books_file(file_one);
	
	books_list.save_to_file();
	books_list.display_books();
	std::cout << "\n\n\n";

	find_title(books_list);

	

	
	Book first(1, "cos", "cos", "cos", 1777, 0);
	Book second(2, "soc", "soc", "fsd", 1997, 0);

	books_list.add_book(first);

	

	find_title(books_list);



	books_list.display_books();


	
	sort_books(books_list);

	
	find_books(books_list);
	

	

	books_list.save_List_To_Bin_File();
	books_list.load_books_file_from_bin();
	books_list.display_books();

	return 0;

}


