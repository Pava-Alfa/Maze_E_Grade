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

#include "Maze.h"
#include "user_interface.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string UserInput;
	std::string SecurityToken;

	do {

		print_startmenu();
		print_user_input();

		std::cin >> UserInput;
		std::cout << "\t" << std::endl;
		while (UserInput != "1" && UserInput != "2") {
			print_wrong_input();
			print_user_input();
			std::cin >> UserInput;
			std::cout << "\t" << std::endl;
			if (UserInput == "s") { break; } //break skipps ONE while loop
		}
		if (UserInput == "1") {
			print_op_one();
			print_user_input();
			std::cin >> SecurityToken;
			std::cout << "\t" << std::endl;
			while (SecurityToken != "Y" && SecurityToken != "n") {
				print_wrong_input();
				print_user_input();
				std::cin >> SecurityToken;
				std::cout << "\t" << std::endl;
				if (SecurityToken == "s") {
					break;
				}
				if (SecurityToken == "Y") {
					Maze A; // static allocated maze => auto-destructs when exit this if statement => same construct-statement can be used again
					A.maze_generator();
					A.maze_map_generator();
					A.maze_map_printer();
					std::cout << "\t" << std::endl;
					SecurityToken = "";
					break;
				}
			}
			if (SecurityToken == "n") { ; }
			if (SecurityToken == "Y") {
				Maze A;
				A.maze_generator();
				A.maze_map_generator();
				A.maze_map_printer();
 				std::cout << "\t" << std::endl;
				SecurityToken = "";
				
			}
		}
		if (UserInput == "2") {
			print_op_two();
			print_user_input();
			std::cin >> SecurityToken;
			std::cout << "\t" << std::endl;
			while (SecurityToken != "Y" && SecurityToken != "n") {
				print_wrong_input();
				print_user_input();
				std::cin >> SecurityToken;
				std::cout << "\t" << std::endl;
				if (SecurityToken == "s") {
					UserInput = "";
					break;
				}
			}
			if (SecurityToken == "Y") { ; }
			if (SecurityToken == "n") { UserInput = ""; }
		}
	} while (UserInput != "2");

	return 0;
}