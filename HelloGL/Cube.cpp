#include "Cube.h"
#include <fstream>
#include <iostream>

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_rotation = 0.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}


static int numVertices, numColors, numIndices;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndices = 0;


void Cube::Update()
{
	_rotation += 0.5f;
	if (_rotation >= 360.0f)
		_rotation = 0.0f;
}

void Cube::Draw()
{
	glBindTexture(GL_TEXTURE_2D, _texture->GetID());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
	glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
	glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texcoords);

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
	glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
	
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

Cube::~Cube()
{
}
