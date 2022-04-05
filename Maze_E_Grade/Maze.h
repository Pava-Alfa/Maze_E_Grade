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
		std::vector<std::vector<char>>mazefield;
};

#endif