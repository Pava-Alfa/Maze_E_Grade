#include "Maze.h"
#include <stack>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <iostream>

Maze::Maze() {
	mazearea = 121; //11x11
	width = 11;
	lenght = 11;
	start_Mazefield_xaxis = 0;
	start_Mazefield_yaxis = 5;
	end_Mazefield_xaxis = 9;
	end_Mazefield_yaxis = 0;
	nodewith = calculatenodefield(width);
	nodelenght = calculatenodefield(lenght);
	node_push_back(nodewith, nodelenght);
}

Maze::~Maze() {
	
}

void Maze::node_push_back(int nodewidth, int nodelenght) { // @params: the width of the nodefield, the lenght of the nodefield
	for (int indexes = 0; indexes < nodelenght; indexes++) { // for all nodes in the field: crate, index and finaly set the possible path for each node
		std::vector<node>temp;
		for (int indexes2 = 0; indexes2 < nodewidth; indexes2++) {
			node nod(indexes2, indexes);
			if (indexes2 == 0) {
				nod.path.left = false;
			}
			else {
				nod.path.left = true;
			}
			if (indexes != 0) {
				nod.path.up = true;
			}
			else {
				nod.path.up = false;
			}
			if (indexes == (nodelenght - 1)) {
				nod.path.down = false;
			}
			else {
				nod.path.down = true;
			}
			if (indexes2 == (nodewidth - 1)) {
				nod.path.right = false;
			}
			else {
				nod.path.right = true;
			}
			temp.push_back(nod); // to a vector
		}
		nodes.push_back(temp);
	}
}

int Maze::calculatenodefield(int mazedimension) { //@param: regular mazedimension, ant return the corresponding nodefielddimension
	int nodedimension = (mazedimension / 2);
	return nodedimension;
}

Maze::node::node(int xaxis, int yaxis) { //@params: an given indexes in the x-axis and y-axis to construct a node for
	this->xaxis = xaxis;
	this->yaxis = yaxis;
	visited = false;

	path.down = false;
	path.up = false;
	path.left = false;
	path.right = false;

	choosedPath.down = false;
	choosedPath.up = false;
	choosedPath.left = false;
	choosedPath.right = false;

}

void Maze::maze_generator() {
	srand(time(NULL));
	std::stack<node>temp;
	int tempxaxis = 0;
	int tempyaxis = 2;
	//int tempxaxisprev = NULL;
	//int tempyaxisprev = NULL;
	nodes[tempyaxis][tempxaxis].visited = true; // set startnode
	temp.push(nodes[tempyaxis][tempxaxis]);
	while (temp.size() != 0) {

		nodes[tempyaxis][tempxaxis] = temp.top(); //when backtracking the node get the choosedpath value, if dead end choosedpath is false, aka saving data to the object
		if (nodes[tempyaxis][tempxaxis].path.up || nodes[tempyaxis][tempxaxis].path.down || nodes[tempyaxis][tempxaxis].path.left || nodes[tempyaxis][tempxaxis].path.right) { // if any unused path exist
			std::vector<int>temp2;
			if (nodes[tempyaxis][tempxaxis].path.up) { temp2.push_back(1); };
			if (nodes[tempyaxis][tempxaxis].path.down) { temp2.push_back(2); };
			if (nodes[tempyaxis][tempxaxis].path.left) { temp2.push_back(3); };
			if (nodes[tempyaxis][tempxaxis].path.right) { temp2.push_back(4); };
			int randomNumber = NULL;
			int length2 = (temp2.size() - 1); // can be beater done
			if (length2 == 0) { randomNumber = temp2[length2]; }
			else {
				int i = rand() % length2 + 1;
				randomNumber = temp2[i];
			}
			if (randomNumber == 1) {
				//nodes[tempyaxis][tempxaxis].path.up = false; 
				temp.top().path.up = false;
				//tempyaxisprev = tempyaxis;
				tempyaxis--;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					//nodes[tempyaxisprev][tempxaxis].choosedPath.up = true;
					temp.top().choosedPath.up = true;
					nodes[tempyaxis][tempxaxis].visited = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
				}
				else {
					tempyaxis++;
				}
			}
			if (randomNumber == 2) {
				//nodes[tempyaxis][tempxaxis].path.down = false;
				temp.top().path.down = false;
				//tempyaxisprev = tempyaxis;
				tempyaxis++;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					//nodes[tempyaxisprev][tempxaxis].choosedPath.down = true;
					temp.top().choosedPath.down = true;
					nodes[tempyaxis][tempxaxis].visited = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
				}
				else {
					tempyaxis--;
				}
			}
			if (randomNumber == 3) {
				//nodes[tempyaxis][tempxaxis].path.left = false;
				temp.top().path.left = false;
				//tempxaxisprev = tempxaxis;
				tempxaxis--;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					//nodes[tempyaxis][tempxaxisprev].choosedPath.left = true;
					temp.top().choosedPath.left = true;
					nodes[tempyaxis][tempxaxis].visited = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
				}
				else {
					tempxaxis++;
				}
			}
			if (randomNumber == 4) {
				//nodes[tempyaxis][tempxaxis].path.right = false;
				temp.top().path.right = false;
				//tempxaxisprev = tempxaxis;
				tempxaxis++;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					//nodes[tempyaxis][tempxaxisprev].choosedPath.right = true;
					temp.top().choosedPath.right = true;
					nodes[tempyaxis][tempxaxis].visited = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
				}
				else {
					tempxaxis--;
				}
			}
		}
		else {
			temp.pop(); //backtracking
			if (temp.size() != 0) { // cant get data from an empty stack
				tempyaxis = temp.top().yaxis;
				tempxaxis = temp.top().xaxis;
			}
			else { // might not be used
				;
			}
		}

	}

}

void Maze::maze_map_generator() {
	for (int indexes = 0; indexes < lenght; indexes++) {
		std::vector<char>temp;
		for (int indexes2 = 0; indexes2 < width; indexes2++) {
			if (indexes == start_Mazefield_yaxis && indexes2 == start_Mazefield_xaxis) {
				temp.push_back('S');
			}
			else if (indexes == end_Mazefield_yaxis && indexes2 == end_Mazefield_xaxis) {
				temp.push_back('E');
			}
			else if ((indexes % 2) != 0 && (indexes2 % 2) != 0) { temp.push_back(' '); }
			else { temp.push_back('#'); }

		}
		mazefield.push_back(temp);
	}
	for (int indexes = 0; indexes < nodelenght; indexes++) {
		for (int indexes2 = 0; indexes2 < nodewith; indexes2++) {
			if (nodes[indexes][indexes2].choosedPath.up) { mazefield[(2 * indexes)][(2 * indexes2) + 1] = { ' ' }; }
			if (nodes[indexes][indexes2].choosedPath.down) { mazefield[(2 * (indexes + 1))][(2 * indexes2) + 1] = { ' ' }; }
			if (nodes[indexes][indexes2].choosedPath.left) { mazefield[(2 * indexes) + 1][(2 * indexes2)] = { ' ' }; }
			if (nodes[indexes][indexes2].choosedPath.right) { mazefield[(2 * indexes) + 1][(2 * (indexes2 + 1))] = { ' ' }; }
		}
	}
}

void Maze::maze_map_printer() const {
	for (int indexes = 0; indexes < mazefield.size(); indexes++) { //amount of rows
		for (int indexes2 = 0; indexes2 < mazefield[indexes].size(); indexes2++) { //amount of elements in a row
			std::cout << mazefield[indexes][indexes2];
		}
		std::cout << std::endl;
	}
}
