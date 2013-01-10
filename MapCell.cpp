#include "MapCell.h"
#include <stdlib.h>

Map_Cell::Map_Cell()
{
	data = NULL;
}

Map_Cell::~Map_Cell()
{
	delete data;
}


Cell::Cell(Map_Cell *parent, int id)
{
	this->id = id;
	this->parent = parent;

	if (id < CELL_AIR) {
		for (int i = 0; i < 8; i++) {
			cells[i] = new Cell(this, id + 1);
		}
	}
	else {
		data = new Cell_Data();
	}
}

Cell::~Cell()
{
	delete[] cells;
}

void Cell::gen(int x, int z, int y)
{
	if (id < (CELL_AIR - 1)) {
		for (int i = 0; i < 8; i++) {
			cells[i]->gen(x + (i >> 3), z + (i >> 2), y + (i >> 1));
		}
	}
	else if (id == (CELL_AIR - 1)) {
		for (int i = 0; i < 8; i++) {
			cells[i]->id = generateCell(x + (i >> 3), z + (i >> 2), y + (i >> 1));
		}
	}
	else {
		id = generateCell(x, z, y);
	}
}

int Cell::generateCell(int x, int z, int y)
{
	srand(x*z*y);
	return (rand() % CELL_TOTAL);
}


Grid::Grid(int depth)
{
	this->depth = depth;
	if (depth <= 0)
		return;

	abs_x = 0;
	abs_z = 0;
	abs_y = 0;

	int x = 0, y = 0, z = 0;
	while (z < LOAD_DIAMETER) {
		x++;
		if (x >= LOAD_DIAMETER) {
			x = 0;
			y++;
		}
		if (y >= LOAD_DIAMETER) {
			y = 0;
			z++;
		}

		space[x][z][y] = new Cell(this, - depth);
		gen(x, z, y);
	}
}

Grid::~Grid()
{
	delete[] space;
}

int Grid::align(int n)
{
	return ((n - LOAD_RADIUS) << depth);
}

void Grid::gen(int x, int z, int y)
{
	space[x][z][y]->gen(align(x + abs_x), align(z + abs_z), align(y + abs_y));
}

void Grid::shift(int x, int z, int y)
{
	if ((x == 0) & (z == 0) & (y == 0)) {
		return;
	}

	int ix = 0, iz = 0, iy = 0;
	abs_x += x;
	abs_z += z;
	abs_y += y;

	while (iz < LOAD_DIAMETER) {
		ix++;
		if (ix >= LOAD_DIAMETER) {
			ix = 0;
			iy++;
		}
		if (iy >= LOAD_DIAMETER) {
			iy = 0;
			iz++;
		}

		if  (
			 (
			  ((ix + x) > LOAD_DIAMETER) ||
			  ((iz + z) > LOAD_DIAMETER) ||
			  ((iy + y) > LOAD_DIAMETER)
			 ) || (
			  ((ix + x) < 0) ||
			  ((iz + z) < 0) ||
			  ((iy + y) < 0)
			 )
			)
			gen(ix, iz, iy);
		else
			space[ix][iz][iy] = space[ix - x][iz - z][iy - y];
	}
}