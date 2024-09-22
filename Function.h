#pragma once
#include "Book.h"
#include "List_of_books.h"
#include <iostream>
#include <algorithm>
#include <list>

bool get_params(int num, char* params[], std::string& file_one, std::string& file_output);
void sort_books(list_of_books<Book>& books_list);

void find_title(list_of_books<Book>& books_list);

void display_found_books(const std::list<Book>& found_books);
void find_books(list_of_books<Book>& books_list);
int execution(std::string file_one, std::string file_output);
