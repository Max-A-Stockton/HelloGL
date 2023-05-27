#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct Texcoords
{
	GLfloat u, v;
};

struct Mesh
{
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indices;
	int VertexCount, ColorCount, IndexCount, texcoordsCount;
	Texcoords* texcoords;
};