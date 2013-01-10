#pragma once

//OpenGL
#define INTERNAL_COLOR_MODE GLUT_RGBA

//Files
#define LOG_FILE "log.txt"

//Map
#define LOAD_RADIUS 8
#define LOAD_DIAMETER LOAD_RADIUS * 2
#define DEFAULT_DEPTH 3
	//Cell types
	enum CELLS {
		CELL_AIR,
		CELL_DIRT,
		CELL_STONE,
		CELL_TOTAL
	};