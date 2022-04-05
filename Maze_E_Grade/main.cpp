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
			if (UserInput == "s") { break; }
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
					Maze A;
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