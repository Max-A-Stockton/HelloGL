#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Pyramid.h"
#define REFRESHRATE 16


class HelloGL
{
private:
	float rotation;
	Camera* camera;
	SceneObject* objects[1000];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
public:
	HelloGL(int argc, char* argv[]);
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	void Display();
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	~HelloGL(void);
};

