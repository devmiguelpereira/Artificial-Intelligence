//
//  AI.hpp
//  Tetris AI
//
//  Created by Roberto Ariosa Hernández on 09/01/2018.
//

#ifndef AI_hpp
#define AI_hpp

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

#define CLOCKWISE true
#define COUNTERCLOCKWISE false

// Data Structures
enum Blocks {I=0,J=4,L=8,O=12,S=16,T=20,Z=24};
struct Shape {
	int x;
	int y;
	Blocks shape;
};

class AI {
	float aggregate_height = -3.78;
	float complete_lines = 1.6;
	float holes = -2.31;
	float bumpiness = -0.59;
	
	vector< vector<unsigned char> > grid;
	map<int,vector< vector<unsigned char> > > shapes;
	
	void rotateCustom(Shape &s, bool clockwise);
	
	bool in (Shape &s, int offset_x, int offset_y);
	
	bool moveLeft(Shape &s);
	
	void moveRight(Shape &s);
	
	bool moveDown(Shape &s);
	
public:
	AI();
	
	AI(map<int,vector< vector<unsigned char> > > &shapes);
	
	void setGrid(vector< vector<unsigned char> > &grid);
	
	void setDNA(float aggregate_height, float complete_lines, float holes, float bumpiness);
	
	void place_piece(Shape &s);
	
	void remove_piece(Shape &s);
	
	int columnHeight(int col);
	
	float calculate_height(Shape &s);
	
	float calculate_lines(Shape &s);
	
	float calculate_holes(Shape &s);
	
	float calculate_bumpiness(Shape &s);
	
	float score(Shape &s);
	
	Shape getBest(Shape s_inicial);
};

#endif /* AI_hpp */
