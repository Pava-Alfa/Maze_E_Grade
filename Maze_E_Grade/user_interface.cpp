#include "user_interface.h"
#include <iostream>
#include <string>

void print_startmenu() {
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "|(1) Generate standardsize maze with dimensions 11x11 blocks(new page)|" << std::endl;
	std::cout << "|(2) Exit this consoleapplication(new page)                           |" << std::endl;
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "\t" << std::endl;

}

void print_user_input() {
	std::cout << "Input: ";
	//std::cout << "\t" << std::endl;
}

void print_wrong_input() {
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "|Please enter a valid input                                           |" << std::endl;
	std::cout << "|To startmenu (s)                                                     |" << std::endl;
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "\t" << std::endl;
}
void print_op_one() {
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "|A maze with the dimensions 11x11 will be created                     |" << std::endl;
	std::cout << "|Procced? (Y/n)                                                       |" << std::endl;
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "\t" << std::endl;
}

void print_op_two() {
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "|Are you sure? the selection cant be reversed (Y/n)                   |" << std::endl;
	std::cout << "+---------------------------------------------------------------------+" << std::endl;
	std::cout << "\t" << std::endl;
}

