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
	srand(time(NULL)); //rand function, based on cplusplus.com
	std::stack<node>temp; //temoparly node stack
	int tempxaxis = 0; //start-node-in xaxis and yaxis
	int tempyaxis = 2;
	nodes[tempyaxis][tempxaxis].visited = true; // set startnode as visited
	temp.push(nodes[tempyaxis][tempxaxis]); //place the startnode in the stack
	while (temp.size() != 0) { //as long as the backtracking stack is not empty(only occurs wnen all nodes are visited and backtract to the startnode)

		nodes[tempyaxis][tempxaxis] = temp.top(); //when backtracking the node get the choosedpath value, if dead end choosedpath is false, aka saving data to the object
		if (temp.top().path.up || temp.top().path.down || temp.top().path.left || temp.top().path.right) { // if any unused path exist
			std::vector<int>temp2;
			if (temp.top().path.up) { temp2.push_back(1); };
			if (temp.top().path.down) { temp2.push_back(2); };
			if (temp.top().path.left) { temp2.push_back(3); };
			if (temp.top().path.right) { temp2.push_back(4); };
			int randomNumber = NULL;
			int length2 = (temp2.size() - 1); // -1 because of 0 based index
			if (length2 == 0) { randomNumber = temp2[length2]; } // if temp2 contains one integer 2, the size-function will return 1 and the integer 2 will be stored at vector index 0
			else {
				length2++;
				int i = rand() % length2; // rand function, based on cplusplus.com. If temp2 contains two integers 1 & 2, the size-function will return 2 (-1, r96) (+1, r99) = 2, rand draws a number 0-1, which are temp2 indexes
				randomNumber = temp2[i];
			}
			if (randomNumber == 1) { //1. set path to false so not checkd again 2. if the node above is unvisited 3. choosedpath true 4. put the visited node in stack and visited true
				temp.top().path.up = false;
				tempyaxis--;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					temp.top().choosedPath.up = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
					temp.top().visited = true;
				}
				else {
					tempyaxis++; //path checkd but this neigbor was arely wisited
				}
			}
			if (randomNumber == 2) {
				temp.top().path.down = false;
				tempyaxis++;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					temp.top().choosedPath.down = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
					temp.top().visited = true;
				}
				else {
					tempyaxis--;
				}
			}
			if (randomNumber == 3) {
				temp.top().path.left = false;
				tempxaxis--;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					temp.top().choosedPath.left = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
					temp.top().visited = true;
				}
				else {
					tempxaxis++;
				}
			}
			if (randomNumber == 4) {
				temp.top().path.right = false;
				tempxaxis++;
				if (nodes[tempyaxis][tempxaxis].visited == false) {
					temp.top().choosedPath.right = true;
					temp.push(nodes[tempyaxis][tempxaxis]);
					temp.top().visited = true;
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
		}
	}
}

void Maze::maze_map_generator() {
	for (int indexes = 0; indexes < lenght; indexes++) { //creates based on maze-dimensions walls, start/end points and empty spaces for nodes
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
	for (int indexes = 0; indexes < nodelenght; indexes++) { // inserts empty spaces for the choosed paths between the nodes
		for (int indexes2 = 0; indexes2 < nodewith; indexes2++) {
			if (nodes[indexes][indexes2].choosedPath.up) { mazefield[(2 * indexes)][(2 * indexes2) + 1] = { ' ' }; }
			if (nodes[indexes][indexes2].choosedPath.down) { mazefield[(2 * (indexes + 1))][(2 * indexes2) + 1] = { ' ' }; }
			if (nodes[indexes][indexes2].choosedPath.left) { mazefield[(2 * indexes) + 1][(2 * indexes2)] = { ' ' }; }
			if (nodes[indexes][indexes2].choosedPath.right) { mazefield[(2 * indexes) + 1][(2 * (indexes2 + 1))] = { ' ' }; }
		}
	}
}

void Maze::maze_map_printer() const { // takes the completed maze from maze_map_generator and print all chars in the mazefield-vector according to the two-dimensional mazefield dimensions
	for (int indexes = 0; indexes < mazefield.size(); indexes++) { //amount of rows
		for (int indexes2 = 0; indexes2 < mazefield[indexes].size(); indexes2++) { //amount of elements in a row
			std::cout << mazefield[indexes][indexes2];
		}
		std::cout << std::endl;
	}
}
