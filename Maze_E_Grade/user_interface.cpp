/*
Description: A automatic maze-generator console-application that trough a simple CLI-type user-interface creates and presents mazes with dimension 11x11 on demand.

Attempted grade: E.

Created by: Jesper Eriksson(jeer1902) @ Mid Sweden Uneversity.

Course: DT026G(Mid Sweden Uneversity).

Last Modified: 2022-04-05.

Used references in project:
Cplusplus.com: https://www.cplusplus.com/reference/cstdlib/rand/

Additional notes: This program was created on and primarly is recomanded to be executed om Microsoft Visual Studio.

*/

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

