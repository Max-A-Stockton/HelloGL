#include "HelloGL.h"
#include "MeshLoader.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();

}
void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGl Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(90, 1, 0.9, 1000);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D); //Textures won't load without this
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
}
void HelloGL::InitObjects()
{
	rotation = 0.0f;
	camera = new Camera();
	
	camera->eye.x = 5.0f;
	camera->eye.y = 5.0f;
	camera->eye.z = -5.0f;
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;

	Mesh* cubeMesh = MeshLoader::Load((char*)"Cube.txt");
	Mesh* pyramidMesh = MeshLoader::Load((char*)"Pyramid.txt");
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 512);
	for (int i = 0; i < 500; i++)
	{
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	for (int i = 500; i < 1000; i++)
	{
		objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
}
void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		camera->center.x -= 0.1f;
	if (key == 'a')
		camera->center.x += 0.1f;
}
void HelloGL::Update()
{
	glLoadIdentity();
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	for (int i = 0; i < 200; i++)
	{
		objects[i]->Update();
	}
	glutPostRedisplay();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//DrawCube();
	for (int i = 0; i < 200; i++)
	{
		objects[i]->Draw();
	}
	//glEnd();
	glFlush();
	glutSwapBuffers();
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

