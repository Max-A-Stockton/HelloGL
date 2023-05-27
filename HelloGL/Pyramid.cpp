#include "Pyramid.h"



Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_rotation = 0.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

static int numVertices, numColors, numIndices;

int Pyramid::numVertices = 0;
int Pyramid::numColors = 0;
int Pyramid::numIndices = 0;

void Pyramid::Update()
{
	_rotation += 0.5f;
	if (_rotation >= 360.0f)
		_rotation = 0.0f;
}

void Pyramid::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
	glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
	glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

Pyramid::~Pyramid()
{
}
