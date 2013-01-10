#pragma once
#include "defenitions.h"

struct Cell_Data {
	char *d;
};

struct Map_Cell {
	Cell_Data *data;

	Map_Cell();
	~Map_Cell();


};

struct Cell : Map_Cell {
	Cell *cells[8];
	int id;
	Map_Cell *parent;

	Cell(Map_Cell *parent, int id);
	~Cell();

	void gen(int x, int z, int y);
	int generateCell(int x, int z, int y);
};

struct Grid : Map_Cell {
	Cell *space[LOAD_DIAMETER][LOAD_DIAMETER][LOAD_DIAMETER];
	int depth;
	int abs_x;
	int abs_z;
	int abs_y;

	Grid(int depth);
	~Grid();
	
	int align(int n);
	void gen(int x, int z, int y);
	void shift(int x, int z, int y);
};