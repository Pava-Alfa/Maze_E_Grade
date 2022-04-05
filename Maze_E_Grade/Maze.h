/*
Description: A automatic maze-generator console-application that trough a simple CLI-type user-interface creates and presents mazes with dimension 11x11 on demand.

Attempted grade: E.

Created by: Jesper Eriksson(jeer1902) @ Mid Sweden Uneversity.

Course: DT026G(Mid Sweden Uneversity).

Last Modified: 2022-04-05.

Used references in project:
Cplusplus.com, rand-function: https://www.cplusplus.com/reference/cstdlib/rand/

Additional notes: This program was created on and primarly is recomanded to be executed om Microsoft Visual Studio.

*/

#ifndef MAZE_H //header guard
#define MAZE_H
#include <vector>

class Maze
{
	public:
		Maze(); //defaultconstructor, 11x11.
		int calculatenodefield(int mazedimension);
		void node_push_back(int nodewidth, int nodelenght);
		void maze_generator();
		void maze_map_generator();
		void maze_map_printer() const;

	private:
		struct avalibleDirections {
			bool up;
			bool down;
			bool left;
			bool right;
		};

		struct mazePath {
			bool up;
			bool down;
			bool left;
			bool right;
		};

		struct node {
			node(int xaxis, int yaxis); //node parametirised constructor
			int xaxis; //node index
			int yaxis;
			bool visited;// the value of the individuelnode
			avalibleDirections path; // all posible paths for each node
			mazePath choosedPath; // the maze-path in the end
		};

		int mazearea; //the maze-dimensions
		int lenght;
		int width;
		int start_Mazefield_xaxis;
		int start_Mazefield_yaxis;
		int end_Mazefield_xaxis;
		int end_Mazefield_yaxis;
		int nodewith;
		int nodelenght;

		std::vector<std::vector<node>>nodes;//node-container
		std::vector<std::vector<char>>mazefield;//maze-map-char-container
};

#endif