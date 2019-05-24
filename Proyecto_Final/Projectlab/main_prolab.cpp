//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno: Delgado Romo Ximena******************//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include  "cmodel/CModel.h"

#if(_MSC_VER >= 1900)
#pragma comment (lib, "legacy_stdio_definitions.lib")
#endif

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

float transZ = -5.0f;

GLfloat vertice[8][3] = {
	{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
};

CTexture text1;
CTexture text2;
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CTexture t_ban;
CTexture t_paredr;
CTexture t_cem;
CTexture t_piso;
CTexture t_pared;
CTexture t_puerta;
CTexture t_mesa;
CTexture t_cajon;
CTexture t_c1;
CTexture t_teclado;
CTexture t_pantalla;

CTexture t_sofa;
CTexture t_lib;
CTexture t_plat;
CTexture t_sabana;
CTexture t_cama;
CTexture t_mueble;
CTexture t_libros;
CTexture t_techo;
CTexture t_gold;
CTexture t_escalon;
CTexture t_almohada;
CTexture t_agua;
CTexture t_pecera;
CTexture t_barandal;
CTexture t_metal;
CTexture t_lad;
CTexture t_ven;
CTexture t_rocas;
CTexture t_porton;
CTexture t_porton1;
CTexture t_piz;
CTexture t_poster;
CTexture t_tub;
CTexture t_tub1;
CTexture t_compu;
CTexture t_compu1;
CTexture negro;
CTexture t_silla;
CTexture esc;
CTexture t_med;
CTexture foto1;
CTexture foto2;
CTexture t_techocuarto;
CTexture pisoAndy;
CTexture TapizAndy;
CTexture t_cajonera;
CTexture t_cajonera2;
CTexture t_tapizcama;
CTexture t_tapizcolchon;
CTexture t_colcha;
CTexture t_buzz;
CTexture t_escritorio;
CTexture t_escritorio2;
CTexture t_escritorio3;
CTexture t_tv;
CTexture t_tv2;
CTexture pantalla;
CTexture t_librero1;
CTexture t_librero2;
CTexture t_posterbuzz;
CTexture t_posterabc;
CTexture t_metalr;
CTexture pelota;
CTexture baul;
CTexture lona;

CFiguras cubo;
CFiguras casa;
CFiguras poster1;
CFiguras sky;
CTexture t_lampara;

//END NEW//////////////////////////////////////////

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;

float white[3] = { 1.0,1.0,1.0 };
float	black[3] = { 0.0, 0.0, 0.0 };

void prismas(float color[3])
{
	
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glColor3fv(color);
	glBegin(GL_POLYGON);	//Front		
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

 void plata(GLuint textura1)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glColor3f(0.270, 0.827, 0.458);

	glBegin(GL_POLYGON);  //Top
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front		
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

}


void trapecio(GLuint textura)
{
	
	GLfloat vertice[8][3] = {
		{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0		
		{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
		{0.5 ,0.5, 0.5},    //Coordenadas Vértice 2 V2
		{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 3 V3
		{-1.0 ,-1.0, -0.5},    //Coordenadas Vértice 4 V4
		{1.0 ,-1.0, -0.5},    //Coordenadas Vértice 5 V5
		{1.0 ,1.0, -0.5},    //Coordenadas Vértice 6 V6
		{-1.0 ,1.0, -0.5},    //Coordenadas Vértice 7 V7
	};

	glBindTexture(GL_TEXTURE_2D, textura);
	glBegin(GL_POLYGON);	//Front		
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void ciudad ()
{

		glPushMatrix(); //Camino2
			glTranslatef(0.0,0.0, 48.0);
			glScalef(125,0.1,34);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Banqueta
			glTranslatef(0.0,1.0,24.0);
			glScalef(125,2.0,16);
			glDisable(GL_LIGHTING);
			fig3.prisma2(t_ban.GLindex, t_ban.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
}


GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	t_ban.LoadTGA("ban.tga");
	t_ban.BuildGLTexture();
	t_ban.ReleaseImage();

	t_paredr.LoadTGA("paredr.tga");
	t_paredr.BuildGLTexture();
	t_paredr.ReleaseImage();

	t_cem.LoadTGA("cem.tga");
	t_cem.BuildGLTexture();
	t_cem.ReleaseImage();

	t_piso.LoadTGA("piso.tga");
	t_piso.BuildGLTexture();
	t_piso.ReleaseImage();

	t_pared.LoadTGA("pared.tga");
	t_pared.BuildGLTexture();
	t_pared.ReleaseImage();

	t_puerta.LoadTGA("puerta.tga");
	t_puerta.BuildGLTexture();
	t_puerta.ReleaseImage();

	t_mesa.LoadTGA("t_mesa.tga");
	t_mesa.BuildGLTexture();
	t_mesa.ReleaseImage();

	t_cajon.LoadTGA("cajon.tga");
	t_cajon.BuildGLTexture();
	t_cajon.ReleaseImage();

	t_c1.LoadTGA("c1.tga");
	t_c1.BuildGLTexture();
	t_c1.ReleaseImage();

	t_teclado.LoadTGA("teclado.tga");
	t_teclado.BuildGLTexture();
	t_teclado.ReleaseImage();

	t_pantalla.LoadTGA("pantalla.tga");
	t_pantalla.BuildGLTexture();
	t_pantalla.ReleaseImage();

	t_sofa.LoadTGA("colchon2.tga");
	t_sofa.BuildGLTexture();
	t_sofa.ReleaseImage();


	t_lib.LoadTGA("mor.tga");
	t_lib.BuildGLTexture();
	t_lib.ReleaseImage();

	t_plat.LoadTGA("plat.tga");
	t_plat.BuildGLTexture();
	t_plat.ReleaseImage();

	t_sabana.LoadTGA("sabana.tga");
	t_sabana.BuildGLTexture();
	t_sabana.ReleaseImage();

	t_mueble.LoadTGA("mueble.tga");
	t_mueble.BuildGLTexture();
	t_mueble.ReleaseImage();

	t_libros.LoadTGA("libros.tga");
	t_libros.BuildGLTexture();
	t_libros.ReleaseImage();

	t_techo.LoadTGA("techo.tga");
	t_techo.BuildGLTexture();
	t_techo.ReleaseImage();

	t_gold.LoadTGA("gold.tga");
	t_gold.BuildGLTexture();
	t_gold.ReleaseImage();

	t_escalon.LoadTGA("escalon.tga");
	t_escalon.BuildGLTexture();
	t_escalon.ReleaseImage();

	t_cama.LoadTGA("cama.tga");
	t_cama.BuildGLTexture();
	t_cama.ReleaseImage();

	t_almohada.LoadTGA("almohada.tga");
	t_almohada.BuildGLTexture();
	t_almohada.ReleaseImage();

	t_agua.LoadTGA("agua.tga");
	t_agua.BuildGLTexture();
	t_agua.ReleaseImage();

	t_pecera.LoadTGA("pecera.tga");
	t_pecera.BuildGLTexture();
	t_pecera.ReleaseImage();

	t_barandal.LoadTGA("barandal.tga");
	t_barandal.BuildGLTexture();
	t_barandal.ReleaseImage();

	t_metal.LoadTGA("metal.tga");
	t_metal.BuildGLTexture();
	t_metal.ReleaseImage();

	t_lad.LoadTGA("ladder.tga");
	t_lad.BuildGLTexture();
	t_lad.ReleaseImage();

	t_ven.LoadTGA("ven.tga");
	t_ven.BuildGLTexture();
	t_ven.ReleaseImage();

	t_rocas.LoadTGA("rocas.tga");
	t_rocas.BuildGLTexture();
	t_rocas.ReleaseImage();

	t_porton.LoadTGA("porton.tga");
	t_porton.BuildGLTexture();
	t_porton.ReleaseImage();

	t_porton1.LoadTGA("porton1.tga");
	t_porton1.BuildGLTexture();
	t_porton1.ReleaseImage();

	t_piz.LoadTGA("piz.tga");
	t_piz.BuildGLTexture();
	t_piz.ReleaseImage();

	t_poster.LoadTGA("poster.tga");
	t_poster.BuildGLTexture();
	t_poster.ReleaseImage();

	t_tub.LoadTGA("tub.tga");
	t_tub.BuildGLTexture();
	t_tub.ReleaseImage();

	t_tub1.LoadTGA("tub1.tga");
	t_tub1.BuildGLTexture();
	t_tub1.ReleaseImage();

	t_compu.LoadTGA("compu.tga");
	t_compu.BuildGLTexture();
	t_compu.ReleaseImage();


	t_compu1.LoadTGA("compu1.tga");
	t_compu1.BuildGLTexture();
	t_compu1.ReleaseImage();

	negro.LoadTGA("black.tga");
	negro.BuildGLTexture();
	negro.ReleaseImage();

	t_silla.LoadTGA("silla.tga");
	t_silla.BuildGLTexture();
	t_silla.ReleaseImage();

	esc.LoadTGA("escamas.tga");
	esc.BuildGLTexture();
	esc.ReleaseImage();

	t_med.LoadTGA("med.tga");
	t_med.BuildGLTexture();
	t_med.ReleaseImage();

	foto1.LoadTGA("foto1.tga");
	foto1.BuildGLTexture();
	foto1.ReleaseImage();

	foto2.LoadTGA("foto2.tga");
	foto2.BuildGLTexture();
	foto2.ReleaseImage();

	TapizAndy.LoadTGA("tapizandy3.tga");
	TapizAndy.BuildGLTexture();
	TapizAndy.ReleaseImage();

	t_techocuarto.LoadTGA("techocuarto.tga");
	t_techocuarto.BuildGLTexture();
	t_techocuarto.ReleaseImage();

	pisoAndy.LoadTGA("pisoAndy.tga");
	pisoAndy.BuildGLTexture();
	pisoAndy.ReleaseImage();

	t_cajonera.LoadTGA("cajonera.tga");
	t_cajonera.BuildGLTexture();
	t_cajonera.ReleaseImage();

	t_cajonera2.LoadTGA("cajonera2.tga");
	t_cajonera2.BuildGLTexture();
	t_cajonera2.ReleaseImage();

	t_tapizcama.LoadTGA("tapizcama.tga");
	t_tapizcama.BuildGLTexture();
	t_tapizcama.ReleaseImage();

	t_tapizcolchon.LoadTGA("tapizcolchon.tga");
	t_tapizcolchon.BuildGLTexture();
	t_tapizcolchon.ReleaseImage();

	t_colcha.LoadTGA("colcha.tga");
	t_colcha.BuildGLTexture();
	t_colcha.ReleaseImage();

	t_buzz.LoadTGA("buzz.tga");
	t_buzz.BuildGLTexture();
	t_buzz.ReleaseImage();

	t_escritorio.LoadTGA("escritorio.tga");
	t_escritorio.BuildGLTexture();
	t_escritorio.ReleaseImage();

	t_escritorio2.LoadTGA("escritorio2.tga");
	t_escritorio2.BuildGLTexture();
	t_escritorio2.ReleaseImage();

	t_escritorio3.LoadTGA("escritorio3.tga");
	t_escritorio3.BuildGLTexture();
	t_escritorio3.ReleaseImage();

	t_tv.LoadTGA("tv.tga");
	t_tv.BuildGLTexture();
	t_tv.ReleaseImage();

	t_tv2.LoadTGA("tv2.tga");
	t_tv2.BuildGLTexture();
	t_tv2.ReleaseImage();

	pantalla.LoadTGA("pantallaAndy.tga");
	pantalla.BuildGLTexture();
	pantalla.ReleaseImage();

	t_lampara.LoadTGA("lampara.tga");
	t_lampara.BuildGLTexture();
	t_lampara.ReleaseImage();

	t_librero1.LoadTGA("librero1.tga");
	t_librero1.BuildGLTexture();
	t_librero1.ReleaseImage();

	t_librero2.LoadTGA("librero2.tga");
	t_librero2.BuildGLTexture();
	t_librero2.ReleaseImage();

	t_posterbuzz.LoadTGA("posterbuzz.tga");
	t_posterbuzz.BuildGLTexture();
	t_posterbuzz.ReleaseImage();

	t_posterabc.LoadTGA("posterabc.tga");
	t_posterabc.BuildGLTexture();
	t_posterabc.ReleaseImage();

	t_metalr.LoadTGA("metalr.tga");
	t_metalr.BuildGLTexture();
	t_metalr.ReleaseImage();

	pelota.LoadTGA("pelota.tga");
	pelota.BuildGLTexture();
	pelota.ReleaseImage();

	baul.LoadTGA("baul.tga");
	baul.BuildGLTexture();
	baul.ReleaseImage();

	lona.LoadTGA("lona.tga");
	lona.BuildGLTexture();
	lona.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,53,0,2.5f,30, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}


void prisma(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(2.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(2.0, 2.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 2.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void tri(GLuint textura)  //Funcion creacion prisma
{

	GLfloat vertice[6][3] = {
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{0.0 ,0.5, 0.5},    //Coordenadas Vértice 2 V2
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 4 V4
				{0.0 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
			
	};


	glBindTexture(GL_TEXTURE_2D, textura);   // choose the texture to use.
	glBegin(GL_TRIANGLES);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.5f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_TRIANGLES);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.5f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glEnd();


}

void techo(GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{-1.0 ,-0.5, 1.0},    //Coordenadas Vértice 0 V0
				{1.0 ,-0.5, 1.0},    //Coordenadas Vértice 1 V1
				{0.5 ,1.0, 0.5},    //Coordenadas Vértice 2 V2
				{-0.5 ,1.0, 0.5},    //Coordenadas Vértice 3 V3
				{-1.0 ,-0.5, -1.0},    //Coordenadas Vértice 4 V4
				{1.0 ,-0.5, -1.0},    //Coordenadas Vértice 5 V5
				{0.5 ,1.0, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,1.0, -0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(2.0, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(2.0, 2.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0, 2.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}


void librero(GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(2.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(2.0, 2.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 2.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void pris(GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};
	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.002f);
	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.002f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.002f);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.002f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, textura3);   // choose the texture to use.	
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(5.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(5.0f, 1.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.002f, 0.0f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, textura4);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

}

void prisA(GLuint textura1, GLuint textura2, GLuint textura3)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};
	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();


	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);   // choose the texture to use.	
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.75f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();

}

void prisAR(GLuint textura1, GLuint textura2, GLuint textura3)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};
	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();


}


void prismae(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,-0.25, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,-0.25, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.75f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void prismat(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[6][3] = {
				{-0.5 , 0.5, -0.5},    //Coordenadas Vértice 0 V0
				{0.5 , 0.5, -0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 5 V5
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	//glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	//glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();
}

void esf(GLfloat radio, int meridianos, int paralelos, GLuint text)
{
	GLdouble theta, phi;

	float ctext_s = 1.0 / meridianos;
	float ctext_t = 1.0 / paralelos;

	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.

	float v1[] = { 0.0, 0.0, 0.0 };
	float v2[] = { 0.0, 0.0, 0.0 };
	float v3[] = { 0.0, 0.0, 0.0 };
	float v4[] = { 0.0, 0.0, 0.0 };
	int i, j;
	float angulom, angulop;
	angulom = 2 * 3.141592654 / meridianos;
	angulop = 1.57 / paralelos;
	for (i = 0;i < meridianos;i++)
	{
		for (j = 0;j < paralelos;j++)
		{
			v1[0] = radio * cos(angulom*i)*sin(angulop*j);
			v1[1] = radio * cos(angulop*j);
			v1[2] = radio * sin(angulom*i)*sin(angulop*j);

			v2[0] = radio * cos(angulom*i)*sin(angulop*(j + 1));
			v2[1] = radio * cos(angulop*(j + 1));
			v2[2] = radio * sin(angulom*i)*sin(angulop*(j + 1));

			v3[0] = radio * cos(angulom*(i + 1))*sin(angulop*(j + 1));
			v3[1] = radio * cos(angulop*(j + 1));
			v3[2] = radio * sin(angulom*(i + 1))*sin(angulop*(j + 1));

			v4[0] = radio * cos(angulom*(i + 1))*sin(angulop*j);
			v4[1] = radio * cos(angulop*j);
			v4[2] = radio * sin(angulom*(i + 1))*sin(angulop*j);

			glBegin(GL_POLYGON);
			glNormal3fv(v1);
			glTexCoord2f(ctext_s*i, -ctext_t * j);
			glVertex3fv(v1);
			glNormal3fv(v2);
			glTexCoord2f(ctext_s*i, -ctext_t * (j + 1));
			glVertex3fv(v2);
			glNormal3fv(v3);
			glTexCoord2f(ctext_s*(i + 1), -ctext_t * (j + 1));
			glVertex3fv(v3);
			glNormal3fv(v4);
			glTexCoord2f(ctext_s*(i + 1), -ctext_t * j);
			glVertex3fv(v4);
			glEnd();
		}
	}
}


void cil(float radio, float altura, int resolucion, GLuint text)
{

	float v1[] = { 0.0, 0.0, 0.0 };
	float v2[] = { 0.0, 0.0, 0.0 };
	float v3[] = { 0.0, 0.0, 0.0 };
	float v4[] = { 0.0, 0.0, 0.0 };
	float v5[] = { 0.0, 0.0, 0.0 };

	float angulo = 2 * 1.57 / resolucion;

	//float ctext_s = 1/resolucion-1;
	float ctext_s = 1.0 / resolucion;
	float ctext_t = 0.0;


	for (int i = 0; i < resolucion; i++)
	{

		v2[0] = radio * cos(angulo*i);
		v2[1] = 0;
		v2[2] = radio * sin(angulo*i);

		v3[0] = radio * cos(angulo*(i + 1));
		v3[1] = 0;
		v3[2] = radio * sin(angulo*(i + 1));

		v4[0] = radio * cos(angulo*i);
		v4[1] = altura;
		v4[2] = radio * sin(angulo*i);

		v5[0] = radio * cos(angulo*(i + 1));
		v5[1] = altura;
		v5[2] = radio * sin(angulo*(i + 1));

		glBegin(GL_POLYGON);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0, altura, 0.0);
		glVertex3fv(v4);
		glVertex3fv(v5);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_POLYGON);
		glNormal3f(v2[0], 0.0f, v2[2]);
		glTexCoord2f(ctext_s*i, 0.0f);		glVertex3fv(v2);
		glTexCoord2f(ctext_s*(i + 2), 0.0f);	glVertex3fv(v3);
		glTexCoord2f(ctext_s*(i + 2), 1.0f);	glVertex3fv(v5);
		glTexCoord2f(ctext_s*i, 1.0f);		glVertex3fv(v4);
		glEnd();


	}
}


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	//textura 1 el cielo
	fig1.skybox(150.0, 130.0, 200.0, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	glCallList(ciudad_display_list);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glEnable(GL_COLOR_MATERIAL);

	glPopMatrix();

	//mesa
	glPushMatrix();
	glTranslatef(38.0, 55.625, -30.0);
	glScaled(2.75, 8.25, 2.75);
	prisma(t_mesa.GLindex, t_mesa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(38.0, 55.625, -15.0);
	glScaled(2.75, 8.25, 2.75);
	prisma(t_mesa.GLindex, t_mesa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34.0, 55.625, -15.0);
	glScaled(2.75, 8.25, 2.75);
	prisma(t_mesa.GLindex, t_mesa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34.0, 55.625, -30.0);
	glScaled(2.75, 8.25, 2.75);
	prisma(t_mesa.GLindex, t_mesa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35.375, 61.375, -22.5);
	glScaled(8.25, 3.25, 21.25);
	prisma(t_mesa.GLindex, t_mesa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35.375, 63.875, -22.5);
	glScaled(8.75, 1.75, 21.75);
	prisma(t_mesa.GLindex, t_mesa.GLindex);
	glPopMatrix();

	//cajones
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_c1.GLindex);
	glTranslatef(31.5, 62, -25.5);
	glScaled(1.0, 2.25, 4.5);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_c1.GLindex);
	glTranslatef(31.5, 62, -19.0);
	glScaled(1.0, 2.25, 4.5);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//////////////////////////////////////////////
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.15f);
	glTranslatef(36.525, 85, -24.0);
	glRotatef(90, 0, 0, 1);
	fig3.prisma(0.3, 9.0, 9.0, t_pecera.GLindex);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(37.025, 85, -24.0);
	glRotatef(90, 0, 0, 1);
	fig3.prisma(0.6, 13.0, 13.0, t_escalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor4f(1.0, 1.0, 1.0, 0.1f);
	glTranslatef(37.025, 79.5, -24.0);
	glRotatef(90, 0, 0, 1);
	fig3.prisma(1.0, 2.0, 17.0, t_escalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(37.025, 87, -6.0);
	glRotatef(90, 0, 0, 1);
	fig3.prisma(0.6, 7.0, 7.0, t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(36.825, 87, -6.0);
	glRotatef(90, 0, 0, 1);
	fig3.prisma(0.6, 5.0, 5.0, foto1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(37.025, 81, 4.0);
	glRotatef(90, 0, 0, 1);
	fig3.prisma(0.6, 7.0, 7.0, t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(36.825, 81, 4.0);
	glRotatef(90, 0, 0, 1);
	fig3.prisma(0.6, 5.0, 5.0, foto2.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//compu
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(37.0, 69.7, -16.0);
	glRotatef(60, 0, 1, 0);
	glScaled(2.5, 2.5, 4.0);
	trapecio(t_compu1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(35.2, 69.7, -17.0);
	glRotatef(-121, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glScaled(3.5, 0.01, 3.7);
	glDisable(GL_LIGHTING);
	fig3.prisma_anun(t_pantalla.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(36.475, 67.3, -16.6);
	glRotatef(60, 0, 1, 0);
	glScaled(1.5, 3.75, 1.5);
	prisma(t_compu.GLindex, t_compu.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(36.5, 65.5, -16.4);
	glRotatef(60, 0, 1, 0);
	glScaled(4.75, 1.0, 5.25);
	glColor3f(1.0, 1.0, 1.0);
	prisma(t_compu1.GLindex, t_compu1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(33.9, 65, -23.4);
	glRotatef(-90, 0, 1, 0);
	glScaled(7.0, 0.25, 3.0);
	fig3.prisma2(t_teclado.GLindex, t_compu.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//sofa
	glPushMatrix();
	glTranslatef(32.0, 51.5, 8.0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	cil(7, 22, 50, t_sofa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.0, 60.5, 11.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	cil(5, 22, 50, t_sofa.GLindex);
	glPopMatrix();

	//plataformas
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-27.025, 52, -20.0);
	glScaled(24.75, 1.25, 64.0);
	plata(t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-29.025, 53.25, -20.0);
	glScaled(20.75, 1.25, 64.0);
	plata(t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//cama
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-31.025, 55.75, -20.0);
	glScaled(16.75, 3.75, 64.0);
	prisma(t_cama.GLindex, t_cama.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_sabana.GLindex);
	glTranslatef(-30.75, 57.25, -15.25);
	glScaled(17.0, 1.0, 56);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_sabana.GLindex);
	glTranslatef(-22.775, 55.875, -15.75);
	glScaled(1.0, 3.75, 57);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//almohada
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-25.025, 56, -48.0);
	glRotatef(90, 0, 0, 1);
	fig3.cilindro(4, 13, 40, t_almohada.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//escalones
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-30.625, 59.75, 11.0);
	glRotatef(190, 1, 0, 0);
	glScaled(8.25, 4.75, 0.1);
	librero(t_escalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-30.625, 69.125, 12.0);
	glRotatef(190, 1, 0, 0);
	glScaled(8.25, 4.75, 0.1);
	librero(t_escalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-30.625, 77.5, 14.0);
	glRotatef(190, 1, 0, 0);
	glScaled(8.25, 4.75, 0.1);
	librero(t_escalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-30.625, 85.875, 15.0);
	glRotatef(190, 1, 0, 0);
	glScaled(8.25, 4.75, 0.1);
	librero(t_escalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-30.625, 94.25, 16.7);
	glRotatef(190, 1, 0, 0);
	glScaled(8.25, 4.75, 0.1);
	librero(t_escalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_escalon.GLindex);
	glTranslatef(-13.75, 56.5, 9.75);
	glRotatef(5, 1, 0, 0);
	glScaled(10.5, 10.0, 1);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_escalon.GLindex);
	glTranslatef(-13.75, 56.5, 9.7);
	glRotatef(5, 1, 0, 0);
	glScaled(7.5, 7.0, 1);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//librero

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(28.025, 66.75, -49.0);
	glScaled(19.0, 30.0, 5.0);
	librero(t_mueble.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(28.025, 66.75, -49.0);

	glScaled(19.0, 0.5, 5.0);
	prisma(t_mueble.GLindex, t_mueble.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(28.025, 74.25, -49.0);
	//glRotatef(-90, 0, 1, 0);
	glScaled(19.0, 0.5, 5.0);
	prisma(t_mueble.GLindex, t_mueble.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(28.025, 59.25, -49.0);
	//glRotatef(-90, 0, 1, 0);
	glScaled(19.0, 0.5, 5.0);
	prisma(t_mueble.GLindex, t_mueble.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_libros.GLindex);
	glTranslatef(28.025, 66.75, -49.0);
	glScaled(19.0, 30.0, 1.0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//librero cama
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-29.025, 76.75, -49.0);
	//glRotatef(-90, 0, 1, 0);
	glScaled(15.0, 22.5, 5.0);
	librero(t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-29.025, 80.5, -49.0);
	//glRotatef(-90, 0, 1, 0);
	glScaled(15.0, 0.5, 5.0);
	prisma(t_plat.GLindex, t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-29.025, 73, -49.0);
	//glRotatef(-90, 0, 1, 0);
	glScaled(15.0, 0.5, 5.0);
	prisma(t_plat.GLindex, t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_libros.GLindex);
	glTranslatef(-29.025, 76.75, -49.0);
	glScaled(15.0, 22.5, 1.0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.75f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 0.75f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//pecera
	glPushMatrix();
	glTranslatef(-1.0, 61.5, -7.0);
	glRotatef(-25, 0, 0, 1);

	glPushMatrix();
	glTranslatef(10.0, 10.5, -40.0);
	glRotated(90, 0, 0, 1);
	tri(esc.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(9.25, 10.5, -40.0);
	fig3.esfera(0.5, 30, 30, esc.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(9.0, 10.5, -40.0);
	glRotated(90, 0, 0, 1);
	fig2.cilindro(0.5, 1.5, 50, esc.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7.5, 10.5, -40.0);
	fig3.esfera(0.5, 30, 30, esc.GLindex);
	glPopMatrix();

	glPopMatrix();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(12.0, 77.5, -5.0);
	glRotatef(180, 0, 0, 1);
	glRotatef(25, 0, 0, 1);

	glPushMatrix();
	glTranslatef(10.0, 10.5, -40.0);
	glRotated(90, 0, 0, 1);
	tri(esc.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(9.25, 10.5, -40.0);
	fig3.esfera(0.5, 30, 30, esc.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(9.0, 10.5, -40.0);
	glRotated(90, 0, 0, 1);
	fig2.cilindro(0.5, 1.5, 50, esc.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7.5, 10.5, -40.0);
	fig3.esfera(0.5, 30, 30, esc.GLindex);
	glPopMatrix();

	glPopMatrix();

	//////////////////////////////////////////////////////////////////////////////////////////////////

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(10.025, 57, -47.0);
		//glRotatef(-90, 0, 1, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(4, 4, 40, t_plat.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(10.025, 51.5, -49.0);
		//glRotatef(-90, 0, 1, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.5, 8, 20, t_plat.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(8.025, 51.5, -47.0);
		//glRotatef(-90, 0, 1, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.5, 8, 20, t_plat.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(12.025, 51.5, -47.0);
		//glRotatef(-90, 0, 1, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.5, 8, 20, t_plat.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(12.025, 51.5, -47.0);
		//glRotatef(-90, 0, 1, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.5, 8, 20, t_plat.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		//glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1.0, 1.0, 1.0, 0.2f);
		glTranslatef(10.025, 59.5, -47.0);
		//glRotatef(-90, 0, 1, 0);
		//glScaled(15.0, 0.5, 5.0);
		//glEnable(GL_ALPHA_TEST);
		//glAlphaFunc(GL_GREATER, 0.1f);
		fig3.cilindro(4, 9, 40, t_agua.GLindex);
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		//glDisable(GL_ALPHA_TEST);
//		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		//glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1.0, 1.0, 1.0, 0.1f);
		glTranslatef(10.025, 59.5, -47.0);
		//glRotatef(-90, 0, 1, 0);
		//glScaled(15.0, 0.5, 5.0);
		//glEnable(GL_ALPHA_TEST);
		//glAlphaFunc(GL_GREATER, 0.1f);
		fig3.cilindro(5, 12, 40, t_pecera.GLindex);
		//glDisable(GL_ALPHA_TEST);
		//glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		glPopMatrix();

//radiador

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-2.025, 52.25, -50.0);
		fig3.cilindro(0.75, 10.0, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-2.025, 52.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-2.025, 62.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		//////////////////////
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-4.025, 52.25, -50.0);
		fig3.cilindro(0.75, 10.0, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-4.025, 52.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-4.025, 62.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		////////////////////////////////
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-6.025, 52.25, -50.0);
		fig3.cilindro(0.75, 10.0, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-6.025, 52.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-6.025, 62.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		////////////////////////////
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-8.025, 52.25, -50.0);
		fig3.cilindro(0.75, 10.0, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-8.025, 52.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-8.025, 62.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		///////////////////////////////////////
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-10.025, 52.25, -50.0);
		fig3.cilindro(0.75, 10.0, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-10.025, 52.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-10.025, 62.25, -50.0);
		fig3.esfera(0.75, 30, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-8.525, 60.25, -51.0);
		glScalef(12.75, 1.5, 0.5);
		prismas(white);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-14.025, 63.75, -51.0);
		glScalef(1.5, 3.0, 0.5);
		prismas(white);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-14.025, 63.75, -51.0);
		glRotatef(90, 1, 0, 0);
		fig3.cilindro(1.5, 0.5, 30, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, t_med.GLindex);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1f);
		glDisable(GL_LIGHTING);
		glTranslatef(-14.025, 63.75, -50.5);
		glScalef(3.0, 3.0, 0.2);
		glBegin(GL_POLYGON);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-7.025, 55.25, -51.0);
		glScalef(11.75, 1.5, 0.5);
		prismas(white);
		glEnable(GL_LIGHTING);
		glPopMatrix();

////////////////////////ventana pecera
		glPushMatrix();
		//glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1.0, 1.0, 1.0, 0.15f);
		glTranslatef(0.525, 83.25, -50.25);
		glRotatef(-90, 0, 1, 0);
		glRotatef(90, 0, 0, 1);
		fig3.prisma(0.3, 9.0, 9.0, t_pecera.GLindex);
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		glPopMatrix();

		glPushMatrix();
		//glDisable(GL_LIGHTING);
		glDisable(GL_LIGHTING);
		glTranslatef(0.525, 83.25, -50.5);
		glRotatef(-90, 0, 1, 0);
		glRotatef(90, 0, 0, 1);
		fig3.prisma(0.6, 13.0, 13.0, t_escalon.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		//glDisable(GL_LIGHTING);
		glDisable(GL_LIGHTING);
		glColor4f(1.0, 1.0, 1.0, 0.1f);
		glTranslatef(0.525, 77.25, -50.25);
		glRotatef(-90, 0, 1, 0);
		glRotatef(90, 0, 0, 1);
		fig3.prisma(1.0, 2.0, 17.0, t_escalon.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


//reloj
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(22.025, 75.5, 13.0);
		//glRotatef(180, 1, 0, 0);
		glRotatef(100, 1, 0, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(4.0, 0.5, 30, t_gold.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(22.025, 79, 13.2);
		//glRotatef(90, 1, 0, 0);
		//glRotatef(100, 1, 0, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.15, 3.0, 30, t_gold.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(22.025, 69, 12.2);
		//glRotatef(90, 1, 0, 0);
		//glRotatef(100, 1, 0, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.15, 3.0, 30, t_gold.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(18.125, 75.5, 13.0);
		glRotatef(90, 0, 0, 1);
		//glRotatef(100, 1, 0, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.15, 3.0, 30, t_gold.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(28.825, 75.5, 13.0);
		glRotatef(90, 0, 0, 1);
		//glRotatef(100, 1, 0, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.15, 3.0, 30, t_gold.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(22.025, 75.5, 12.9);
		glRotatef(90, 0, 0, 1);
		//glRotatef(100, 1, 0, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.15, 3.0, 30, negro.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(22.025, 75.5, 12.9);
		glRotatef(45, 0, 0, 1);
		//glRotatef(100, 1, 0, 0);
		//glScaled(15.0, 0.5, 5.0);
		fig3.cilindro(0.15, 3.0, 30, negro.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
	glTranslatef(0.0f, 76.5f, 14.0f);
	glRotatef(180, 0, 1, 0);
	glScaled(80, 50.0, 8.0);
	glDisable(GL_LIGHTING);
	prismat(t_pared.GLindex, t_pared.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 65.7f, 13.9f);
	glRotatef(-180, 0, 1, 0);
	glRotatef(-180, 1, 0, 0);
	glScaled(15, 30.0, 8.0);
	glDisable(GL_LIGHTING);
	prismat(t_puerta.GLindex,t_pared.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	///////////////////////////////////////////////////////////////////////////////FACHADA///////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glScalef(1, 2, 1);
	//	escaleras
	glPushMatrix();
	glTranslatef(18.80f, 7.0f, 22.85f);
	glScaled(12.0f, 12.5f, 1.5f);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.20f, 5.75f, 24.35f);
	glScaled(12.0f, 10.0f, 1.5f);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80f, 4.5f, 25.85f);
	glScaled(12.0f, 7.5f, 1.5f);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80f, 3.25f, 27.35f);
	glScaled(12.0f, 5.0f, 1.0f);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80f, 2.0f, 28.85f);
	glScaled(12.0f, 2.5f, 1.0f);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//fin escaleras

	//prisma escalom
	glPushMatrix();
	glTranslatef(10.65f, 8.5f, 26.6f);
	//glRotatef(45, 1, 0, 0);
	glScaled(4.5f, 15.0f, 9.0f);
	glDisable(GL_LIGHTING);
	prismae(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.15f, 11.2f, 27.15f);
	glRotatef(52.0, 1, 0, 0);
	glScaled(5.0f, 1.0f, 15.5f);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.0f, 8.5f, 26.6f);
	//glRotatef(45, 1, 0, 0);
	glScaled(4.5f, 15.0f, 9.0f);
	glDisable(GL_LIGHTING);
	prismae(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(26.75f, 11.2f, 26.15f);
	glRotatef(52.0, 1, 0, 0);
	glScaled(5.0f, 1.0f, 15.5f);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_paredr.GLindex);
	glTranslatef(32.65, 50.25, 15.35);
	glRotatef(20, 0, 1, 0);
	glScaled(12.0, 98.5, 10.0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(33.85, 4, 21.0);
	glRotatef(20, 0, 1, 0);
	glScaled(12.9, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34.85, 97.5, 20.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(-20, 0, 1, 0);
	glScaled(12.9, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_tub.GLindex, t_tub.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//////////////////////////////////////////////////////////////////
	glPushMatrix();
	glScalef(1, 2, 1);
	glPushMatrix();
	glTranslatef(32.65, 40.0, 21.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(20, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.65, 37.5, 21.0);
	glRotatef(20, 0, 1, 0);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.65, 34.75, 21.0);
	glRotatef(20, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(32.65, 40.0, 21.2);
	glRotatef(20, 0, 1, 0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.65, 37.5, 21.2);
	glRotatef(20, 0, 1, 0);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.65, 40.0, 21.2);
	glRotatef(20, 0, 1, 0);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.95, 16.0, 21.2);
	glRotatef(20, 0, 1, 0);
	glScaled(4.0, 7.0, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_poster.GLindex, t_poster.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPopMatrix();

	///////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_paredr.GLindex);
	glTranslatef(18.80, 50.25, 17.1);
	glScaled(20.0, 98.5, 10.0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 97.5, 22.0);
	glRotatef(180, 1, 0, 0);
	glScaled(20.0, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_tub.GLindex, t_tub.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	////////////////////////////////////////////
	glPushMatrix();
	glScalef(1, 2, 1);
	glPushMatrix();
	glTranslatef(18.80, 41.5, 22.5);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 39.0, 22.5);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 36.25, 22.5);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(18.80, 41.5, 22.7);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 39.0, 22.7);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 41.5, 22.7);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

//porton

	glPushMatrix();
	glTranslatef(18.80, 25.0, 23.7);
	glRotated(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(10, 0.2, 40, t_rocas.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 19.0, 23.7);
	//glRotated(-90, 1, 0, 0);
	glScaled(20.0, 12.0, 0.2);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 25.0, 23.9);
	glRotated(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(6, 0.1, 40, t_porton.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 25.0, 23.9);
	glRotated(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(1, 0.1, 40, t_porton1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18.80, 24.5, 24.0);
	//glRotated(-90, 1, 0, 0);
	glScaled(2.0, 1.0, 0.2);
	glDisable(GL_LIGHTING);
	prisma(t_porton1.GLindex, t_porton1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(23.80, 18.5, 24.0);
	//glRotated(-90, 1, 0, 0);
	glScaled(0.5, 1.0, 0.2);
	glDisable(GL_LIGHTING);
	prismas(black);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(18.80, 19.0, 23.9);
	//glRotated(-90, 1, 0, 0);
	glScaled(12.0, 12.0, 0.2);
	glDisable(GL_LIGHTING);
	prisma(t_porton.GLindex, t_porton.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_paredr.GLindex);
	glTranslatef(4.95, 50.25, 15.35);
	glRotatef(-20, 0, 1, 0);
	glScaled(12.0, 98.5, 10.0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.15, 4, 21.0);
	glRotatef(-20, 0, 1, 0);
	glScaled(12.9, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.15, 97.5, 20.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(20, 0, 1, 0);
	glScaled(11.9, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_tub.GLindex, t_tub.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



/////////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glScalef(1, 2, 1);

	glPushMatrix();
	glTranslatef(4.95, 40.0, 21.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-20, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.95, 37.5, 21.0);
	glRotatef(-20, 0, 1, 0);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.95, 34.75, 21.0);
	glRotatef(-20, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(4.95, 40.0, 21.2);
	glRotatef(-20, 0, 1, 0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.95, 37.5, 21.2);
	glRotatef(-20, 0, 1, 0);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.95, 40.0, 21.2);
	glRotatef(-20, 0, 1, 0);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.95, 18.0, 21.2);
	glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 3.0, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_piz.GLindex, t_piz.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

	//techo

	glPushMatrix();
	glTranslatef(0.0, 104.75, -17.0);
	glScaled(40.0, 7.5, 35.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	techo(t_techo.GLindex);
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 4, -16.5);
	//glRotatef(-20, 0, 1, 0);
	glScaled(0.35, 6.0, 70);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-40.25, 97.5, -16.75);
	glRotatef(180, 0, 0, 1);
	glScaled(0.35, 6.0, 70.5);
	glDisable(GL_LIGHTING);
	prisma(t_tub.GLindex, t_tub.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glScalef(1, 2, 1);
	//ventanas lado izq

	glPushMatrix();
	glTranslatef(-41, 13.0, 7.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41, 10.5, 7.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41, 7.75, 7.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(-41, 13.0, 7);
	glRotatef(-90, 0, 1, 0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41.5, 10.5, 7.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41, 13.0, 7.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
/////////////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslatef(-41, 13.0, -15.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41, 10.5, -15.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41, 7.75, -15.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(-41, 13.0, -15);
	glRotatef(-90, 0, 1, 0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41.5, 10.5, -15.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41, 13.0, -15.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
///////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-41.0, 40.0, 1.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41.0, 40.0, 1.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(-41.0, 40.0, 1.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();
//////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-41.0, 40.0, -35.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-41.0, 40.0, -35.0);
	glRotatef(-90, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(-41.0, 40.0, -35.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPopMatrix();

glPushMatrix();
glTranslatef(20, 0, 0);
glScalef(1.5, 2.0, 1);
	//escaleras
	glPushMatrix();
	glTranslatef(-42.5, 33.0, -9.5);
	glScaled(4.0, 1.0, 45.0);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1f);
	glDisable(GL_LIGHTING);
	prisma(t_metal.GLindex, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	//glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(-44.0, 35.0, -10.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(1.0, 4.0, 52.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(-42.5, 35.0, 13.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(-42.5, 35.0, -32.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
//////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-42.5, 20.5, -3.875);
	glScaled(4.0, 1.0, 33.75);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1f);
	glDisable(GL_LIGHTING);
	prisma(t_metal.GLindex, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	//glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(-44.0, 22.5, -4.375);
	//glRotatef(-20, 0, 1, 0);
	glScaled(1.0, 4.0, 40.75);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(-42.5, 22.5, 13.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(-42.5, 22.5, -20.75);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_lad.GLindex);
	glTranslatef(-42.5, 27.0, -20.75);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 13.5, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_lad.GLindex);
	glTranslatef(-42.5, 16.25, 10.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 8.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

glPopMatrix();


	glPushMatrix();
	glTranslatef(40.5, 4, -16.5);
	//glRotatef(-20, 0, 1, 0);
	glScaled(0.35, 6.0, 70);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.5, 97.5, -16.75);
	glRotatef(180, 1,0, 0);
	glScaled(0.35, 6.0, 70.5);
	glDisable(GL_LIGHTING);
	prisma(t_tub.GLindex, t_tub.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

////////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glScalef(1, 2, 1);
//ventanas lado derecho
	glPushMatrix();
	glTranslatef(41, 40.0, 1.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41, 37.5, 1.0);
	glRotatef(90, 0, 1, 0);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41, 34.75, 1.0);
	glRotatef(90, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(41.25, 40.0, 1.0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-180, 1, 0, 0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41.25, 37.5, 1.0);
	glRotatef(90, 0, 1, 0);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41, 40.0, 1.0);
	glRotatef(90, 0, 1, 0);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	/////////////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslatef(41, 40.0, -21.0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41, 37.5, -21.0);
	glRotatef(90, 0, 1, 0);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41, 34.75, -21.0);
	glRotatef(90, 0, 1, 0);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(41.25, 40.0, -21);
	glRotatef(90, 0, 1, 0);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41.25, 37.5, -21.0);
	glRotatef(90, 0, 1, 0);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41, 40.0, -21.0);
	glRotatef(90, 0, 1, 0);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
glPopMatrix();

//////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
glTranslatef(-20, 0, 0);
glScalef(1.5, 2.0, 1);
	glPushMatrix();
	glTranslatef(42.0, 33.0, -9.5);
	glScaled(4.0, 1.0, 45.0);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1f);
	glDisable(GL_LIGHTING);
	prisma(t_metal.GLindex, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	//glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(44.5, 35.0, -10.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(1.0, 4.0, 52.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(42.0, 35.0, 13.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(42.0, 35.0, -32.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
/////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(42.0, 20.5, -9.5);
	glScaled(4.0, 1.0, 45.0);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1f);
	glDisable(GL_LIGHTING);
	prisma(t_metal.GLindex, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	//glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(44.5, 22.5, -10.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(1.0, 4.0, 52.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(42.0, 22.5, 13.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_barandal.GLindex);
	glTranslatef(42.0, 22.5, -32.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 4.0, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t_lad.GLindex);
	glTranslatef(42.0, 20.75, 13.0);
	//glRotatef(-20, 0, 1, 0);
	glScaled(4.0, 24.5, 1.0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

//ventanas
	glPushMatrix();
	glScalef(1, 2, 1);
	glPushMatrix();
	glTranslatef(-34.0, 40.0, 18.5);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-34.0, 40.0, 18.5);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(-34.0, 40.0, 18.7);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();
//////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-16.0, 40.0, 18.5);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 37.5, 18.5);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 34.75, 18.5);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(-16.0, 40.0, 18.7);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 37.5, 18.7);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 40.0, 18.7);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

///////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-25.0, 40.0, 18.5);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(3.0, 0.2, 30, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25.0, 37.5, 18.5);
	glScaled(6.0, 5.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25.0, 34.75, 18.5);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.9f);*/
	glDisable(GL_LIGHTING);
	glTranslatef(-25.0, 40.0, 18.7);
	//glScaled(80.0, 50.0, 70.0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(2.5, 0.1, 30, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	/*glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);*/
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25.0, 37.5, 18.7);
	glScaled(5.0, 5.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25.0, 40.0, 18.7);
	glScaled(5.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

//division
	glPushMatrix();
	glTranslatef(-21.0, 27, 18.7);
	glScaled(38.0, 2.0, 0.35);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

//ventanas de abajo

	glPushMatrix();
	glTranslatef(-25.0, 19.5, 18.5);
	glScaled(6.0, 9.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25.0, 14.75, 18.5);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25.0, 19.5, 18.7);
	glScaled(5.0, 8.5, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25.0, 19.55, 18.7);
	glScaled(6.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-16.0, 19.5, 18.5);
	glScaled(6.0, 9.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 14.75, 18.5);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 19.5, 18.7);
	glScaled(5.0, 8.5, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 19.55, 18.7);
	glScaled(6.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
////////////////////////////////////////////////////////////7
	glPushMatrix();
	glTranslatef(-34.0, 19.5, 18.5);
	glScaled(6.0, 9.0, 0.2);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-34.0, 14.75, 18.5);
	glScaled(7.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-34.0, 19.5, 18.7);
	glScaled(5.0, 8.5, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-34.0, 19.55, 18.7);
	glScaled(6.0, 0.5, 0.5);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
//////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-6.0, 19.55, 18.7);
	//glScaled(6.0, 0.5, 0.5);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	fig3.cilindro(1.5, 0.5, 40, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.0, 19.55, 18.7);
	//glScaled(6.0, 0.5, 0.5);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	fig3.cilindro(1.0, 0.5, 40, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

//cemento bajo

	glPushMatrix();
	glTranslatef(-21.0, 4, 18.7);
	glScaled(38.0, 6.0, 0.35);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-21, 97.5, 18.0);
	glRotatef(180, 1, 0, 0);
	glScaled(38, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_tub.GLindex, t_tub.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-17.0, 4, 18.9);
	//glScaled(38.0, 2.0, 0.35);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(6.0, 0.35, 40, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-17.0, 4, 19.4);
	//glScaled(38.0, 2.0, 0.35);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(5.0, 0.1, 40, t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-17.0, 3, 19.4);
	glScaled(10.0, 3.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_plat.GLindex, t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-17.0, 4, 19.8);
	//glScaled(38.0, 2.0, 0.35);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	cil(4.0, 0.1, 70, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-17.0, 4, 19.8);
	glScaled(8.0, 2.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_ven.GLindex, t_ven.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-17.0, 4, 20.0);
	glScaled(1.0, 8.0, 0.1);
	//glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	prisma(t_plat.GLindex, t_plat.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 4, -52.5);
	//glRotatef(-20, 0, 1, 0);
	glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_cem.GLindex, t_cem.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 97.5, -52.5);
	//glRotatef(-20, 0, 1, 0);
	glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	prisma(t_tub.GLindex, t_tub.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//silla arnold
	glPushMatrix();
	glTranslatef(25.5, 67, -22.0);
	glRotated(90, 0, 1, 0);
	glRotated(-110, 1, 0, 0);
	glScaled(4.5, 1.0, 8.0);
	glDisable(GL_LIGHTING);
	prisma(t_silla.GLindex, t_silla.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.0, 61.25, -22.0);
	glRotated(90, 0, 1, 0);
	glRotated(-100, 1, 0, 0);
	glScaled(0.5, 2.0, 6.0);
	glDisable(GL_LIGHTING);
	prisma(t_compu.GLindex, t_compu.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(29.5, 56.5, -22.0);
	//glRotated(90, 0, 1, 0);
	//glRotated(-110, 1, 0, 0);
	//glScaled(0.5, 1.0, 3.0);
	glDisable(GL_LIGHTING);
	fig3.cilindro(4, 2.0, 40, t_silla.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(26.5, 54.5, -23.0);
	glRotated(-270, 1, 0, 0);
	glScaled(0.5, 1.0, 5.0);
	glDisable(GL_LIGHTING);
	trapecio(t_silla.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(29.5, 54.5, -23.0);
	glRotated(-270, 1, 0, 0);
	glScaled(0.5, 1.0, 5.0);
	glDisable(GL_LIGHTING);
	trapecio(t_silla.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.0, 54.5, -20.5);
	glRotated(-270, 1, 0, 0);
	glScaled(0.5, 1.0, 5.0);
	glDisable(GL_LIGHTING);
	trapecio(t_silla.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(29.0, 54.5, -20.5);
	glRotated(-270, 1, 0, 0);
	glScaled(0.5, 1.0, 6.0);
	glDisable(GL_LIGHTING);
	trapecio(t_silla.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

//////////////lampara
	glPushMatrix();
	glScalef(1, 2, 1);
	glPushMatrix();
	glTranslatef(50.80, 2.0, 23.9);
	//glRotatef(-20, 0, 1, 0);
	//glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	fig3.cono(6, 2, 30, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50.80, 6.0, 23.9);
	//glRotatef(-20, 0, 1, 0);
	//glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	fig3.cilindro(1, 20, 30, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1f);
	glTranslatef(50.80, 29.0, 23.9);
	//glRotatef(-20, 0, 1, 0);
	//glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	fig3.esfera(3, 30, 30, t_techo.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, 0.5f);
	glTranslatef(50.80, 29.0, 23.9);
	fig3.esfera(2.9, 30, 30, t_ven.GLindex);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
	glPopMatrix();

/////bote
	glPushMatrix();
	glScalef(1, 1.5, 1);
	glPushMatrix();
	glTranslatef(-50.80, 12.0, 21.9);
	glRotatef(180, 1, 0, 0);
	//glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	fig3.cono(26, 4, 30, t_tub1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50.80, 12.0, 21.9);
	glRotatef(180, 1, 0, 0);
	//glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	fig3.cilindro(5, 1, 30, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50.80, 12.5, 21.9);
	glRotatef(180, 1, 0, 0);
	//glScaled(80, 6.0, 0.35);
	glDisable(GL_LIGHTING);
	fig3.prisma(1.5, 2, 1.5, t_metal.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

//prisma cuarto Andy
glPushMatrix();
glTranslatef(0.0, 27.0, -17.0);
glScaled(78.0, 48.0, 68.0);
glDisable(GL_LIGHTING);
prisA(TapizAndy.GLindex, pisoAndy.GLindex, t_techocuarto.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//pelota
glPushMatrix();
glTranslatef(21.5, 11.0, -17.0);
glDisable(GL_LIGHTING);
fig3.esfera(2, 60, 60, pelota.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//puerta entrada+
glPushMatrix();

glPushMatrix();
glTranslatef(0.0, 17.5, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(14.0, 28.0, 0.5);
glDisable(GL_LIGHTING);
prisma(t_puerta.GLindex, t_puerta.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 32.5, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(14.5, 2.0, 0.6);
glDisable(GL_LIGHTING);
prismas(white);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 33.0, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(15.0, 1.0, 0.7);
glDisable(GL_LIGHTING);
prismas(white);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 34.0, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(15.5, 1.0, 0.8);
glDisable(GL_LIGHTING);
prismas(white);
glEnable(GL_LIGHTING);
glPopMatrix();

glPopMatrix();

//closet
glPushMatrix();
glTranslatef(-22.5, 0.0, -5.0);
glRotatef(-90, 0, 1, 0);
glPushMatrix();
glTranslatef(0.0, 17.5, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(14.0, 28.0, 0.5);
glDisable(GL_LIGHTING);
prisma(t_puerta.GLindex, t_puerta.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 32.5, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(14.5, 2.0, 0.6);
glDisable(GL_LIGHTING);
prismas(white);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 33.0, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(15.0, 1.0, 0.7);
glDisable(GL_LIGHTING);
prismas(white);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 34.0, 16.0);
//glRotatef(180, 0, 1, 0);
glScaled(15.5, 1.0, 0.8);
glDisable(GL_LIGHTING);
prismas(white);
glEnable(GL_LIGHTING);
glPopMatrix();

glPopMatrix();

//cajonera
glPushMatrix();
glTranslatef(-26.5f, 2.0, 14.5);
glRotatef(270, 0, 1, 0);
glScaled(1.0, 4.5, 4.0);
glPushMatrix();//Top
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 4.5, 0.5);
glScalef(4.0, 0.5, 5.5);
glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Botom
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 0.5, 0.5);
glScalef(4.0, 0.5, 5.5);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Izq
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.5, -1.55);
glScalef(4.0, 4.5, 0.5);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Der
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.5, 2.57);
glScalef(4.0, 4.5, 0.5);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Back
glColor3f(1.0, 1.0, 1.0);
glTranslatef(2.0, 2.5, 0.7);
glRotatef(90, 0, 1, 0);
glScalef(4.0, 4.5, 0.5);
glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Front
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-1.3, 2.5, 0.5);
glRotatef(90, 0, 1, 0);
glScalef(4.0, 4.5, 0.5);
glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//cajon1
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-1.5, 1.3, 0.5);
glRotatef(90, 0, 1, 0);
glScalef(3.5, 0.8, 0.5);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera2.GLindex);
//glEnable(GL_LIGHTING);
glTranslatef(0.0f, 0.0f, -0.7f);//agarradera
fig1.esfera(0.1f, 25, 20, t_cajonera.GLindex);
glPopMatrix();

glPushMatrix();//cajon2
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-1.5, 2.3, 0.5);
glRotatef(90, 0, 1, 0);
glScalef(3.5, 0.8, 0.5);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera2.GLindex);
//glEnable(GL_LIGHTING);
glTranslatef(0.0f, 0.0f, -0.7f);//agarradera
fig1.esfera(0.1f, 25, 20, t_cajonera.GLindex);
glPopMatrix();

glPushMatrix();//cajon3
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-1.5, 3.3, 0.5);
glRotatef(90, 0, 1, 0);
glScalef(3.5, 0.8, 0.5);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_cajonera2.GLindex);
//glEnable(GL_LIGHTING);
glTranslatef(0.0f, 0.0f, -0.7f);//agarradera
fig1.esfera(0.1f, 25, 20, t_cajonera.GLindex);
glPopMatrix();

glPopMatrix();

/////////////////////cama Andy
glPushMatrix();
glTranslatef(22.0, 8.0, -16.0);
glRotatef(-90, 0, 1, 0);
glScaled(3.5,8.0, 5.0);
glPushMatrix();//Base
glTranslatef(-5.5, -0.1, transZ);
glTranslatef(0.0, 0.0, 15.0f);
glScaled(9.0f, 0.5f, 4.0f);
prisma(t_tapizcama.GLindex, t_tapizcama.GLindex);
glPopMatrix();


glPushMatrix();	//Pata1 Cabecera 
glTranslatef(-9.85f, 0.2f, transZ);
glTranslatef(0.0f, 0.0f, 12.92f);
glScaled(0.4f, 1.68f, 0.4f);
prisma(t_tapizcama.GLindex, t_tapizcama.GLindex);
//cilindro
glTranslatef(-0.0f, 0.5f, 0.0f);
fig1.cilindro(0.3f, 0.4f, 20, t_tapizcama.GLindex);
//esfera
glTranslatef(0.0f, 0.6f, 0.0f);
fig1.esfera(0.2f, 25, 20, t_tapizcama.GLindex);
glPopMatrix();


glPushMatrix();	//Pata2 Cabecera
glTranslatef(-9.85, 0.2f, transZ);
glTranslatef(0.0f, 0.0f, 17.0f);
glScaled(0.4f, 1.68f, 0.4f);
prisma(t_tapizcama.GLindex, t_tapizcama.GLindex);
//cilindro
glTranslatef(0.0f, 0.5f, 0.0f);
fig1.cilindro(0.3f, 0.4f, 20, t_tapizcama.GLindex);
//esfera
glTranslatef(0.0f, 0.6f, 0.0f);
fig1.esfera(0.2f, 25, 20, t_tapizcama.GLindex);
glPopMatrix();

glPushMatrix();//union patas cabecera
glTranslatef(-9.85, 0.9f, transZ);
glTranslatef(0.0, 0.0, 15.0f);
glScaled(0.2f, 0.2f, 4.0f);
prisma(t_tapizcama.GLindex, t_tapizcama.GLindex);
glPopMatrix();

glPushMatrix();//Pata 3 Tracera
glTranslatef(-1.0, 0.2f, transZ);
glTranslatef(0.0f, 0.0f, 17.0f);
glScaled(0.4f, 1.68f, 0.4f);
prisma(t_tapizcama.GLindex, t_tapizcama.GLindex);
//esfera
glTranslatef(0.0f, 0.7f, 0.0f);
fig1.esfera(0.2f, 25, 20, t_tapizcama.GLindex);
glPopMatrix();

glPushMatrix();//Pata 4 Tracera
glTranslatef(-1.0f, 0.2f, transZ);
glTranslatef(0.0f, 0.0f, 12.92f);
glScaled(0.4f, 1.68f, 0.4f);
prisma(t_tapizcama.GLindex, t_tapizcama.GLindex);
//esfera
glTranslatef(0.0f, 0.7f, 0.0f);
fig1.esfera(0.2f, 25, 20, t_tapizcama.GLindex);
glPopMatrix();

glPushMatrix();//Colchon
glTranslatef(-5.5, 0.3, transZ);
glTranslatef(0.0, 0.0, 15.0f);
glScaled(9.0f, 0.2f, 4.0f);
prisma(t_tapizcolchon.GLindex, t_tapizcolchon.GLindex);
glPopMatrix();

glPushMatrix();//colcha 
glTranslatef(-5.5, 0.4, transZ);
glTranslatef(0.0, 0.0, 15.0f);
glScaled(9.0f, 0.03f, 4.0f);
glDisable(GL_LIGHTING);
prisma(t_colcha.GLindex, t_colcha.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();
glPushMatrix();
glTranslatef(-5.5, 0.01, transZ);
glTranslatef(0.0, 0.0, 12.97f);
glScaled(9.0f, 0.8f, 0.03f);
prisma(t_colcha.GLindex, t_colcha.GLindex);
glPopMatrix();
glPushMatrix();
glTranslatef(-5.5, 0.01, transZ);
glTranslatef(0.0, 0.0, 17.02f);
glScaled(9.0f, 0.8f, 0.03f);
prisma(t_colcha.GLindex, t_colcha.GLindex);
glPopMatrix();
glPushMatrix();//buzz
glBindTexture(GL_TEXTURE_2D, t_buzz.GLindex);
glTranslatef(-5.5, 0.5, transZ);
glTranslatef(0.0, 0.0, 15.0f);
glRotated(90, 0.0, 1.0, 0.0);
glScaled(4.0f, 0.03f, 5.0f);
glDisable(GL_LIGHTING);
glEnable(GL_ALPHA_TEST);
glAlphaFunc(GL_GREATER, 0.1f);
glBegin(GL_POLYGON);
glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
glEnd();
glDisable(GL_ALPHA_TEST);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Almohada
glTranslatef(-9.0, 0.5, transZ);
glTranslatef(0.0, 0.0, 14.0f);
glRotated(90, 1.0, 0.0, 0.0);
glScaled(1.5f, 5.0f, 2.0f);
fig1.cilindro(0.3f, 0.4f, 20, t_tapizcolchon.GLindex);
glPopMatrix();

glPopMatrix();

///////////////////////////////////escritorio Andy
glPushMatrix();
glTranslatef(36.0, 2.5, -30.0);
glRotatef(-90, 0, 1, 0);
glScalef(4.0, 5.0, 4.0);
glPushMatrix();//Base
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.0, 0.5);
glScalef(2.5, 4.0, 4.0);
/*glDisable(GL_LIGHTING);*/
casa.prisma(0.5, 1.0, 0.5, t_escritorio2.GLindex);
/*glEnable(GL_LIGHTING);*/
glPopMatrix();

glPushMatrix();//cajon1
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 0.6, 1.5);
glScalef(1.6, 0.6, 0.2);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_escritorio3.GLindex);
//glEnable(GL_LIGHTING);
glTranslatef(0.0f, 0.0f, 0.6f);//agarradera
fig1.esfera(0.1f, 25, 20, t_escritorio2.GLindex);
glPopMatrix();

glPushMatrix();//cajon2
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.4, 1.5);
glScalef(1.6, 0.6, 0.2);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_escritorio3.GLindex);
//glEnable(GL_LIGHTING);
glTranslatef(0.0f, 0.0f, 0.6f);//agarradera
fig1.esfera(0.1f, 25, 20, t_escritorio2.GLindex);
glPopMatrix();

glPushMatrix();//Tabla
glColor3f(1.0, 1.0, 1.0);
glTranslatef(1.7, 2.0, 0.5);
glScalef(5.0, 0.2, 2.7);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_escritorio.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Tabla der
glColor3f(1.0, 1.0, 1.0);
glTranslatef(3.9, 1.0, 0.5);
glScalef(0.2, 2.0, 2.5);
//glDisable(GL_LIGHTING);
casa.prisma(1.0, 1.0, 1.0, t_escritorio2.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPopMatrix();

//**********************************Television *********************************************

glPushMatrix();
glTranslatef(38.5, 8.5, -14.0); //trasladar television
glRotated(-125.0, 0.0, 1.0, 0.0);
glScalef(4.0, 4.0, 2.0); //escalar television
glPushMatrix();//1
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.2, 4.1);
glScalef(1.8, 0.3, 0.3);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 0.5, 0.5, t_tv2.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//1
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.8, 4.1);
glScalef(1.8, 0.3, 0.3);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 0.5, 0.5, t_tv2.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//2
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.1, 1.5, 4.1);
glScalef(0.3, 1.0, 0.3);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 0.5, 0.5, t_tv2.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//2
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.9, 1.5, 4.1);
glScalef(0.3, 1.0, 0.3);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 0.5, 0.5, t_tv2.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Pantalla
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.5, 4.1);
glScalef(0.7, 0.5, 0.3);
glRotatef(90, 1, 0, 0);
glDisable(GL_LIGHTING);
fig3.prisma_anun(pantalla.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//caja
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.5, 3.0);
glScalef(1.0, 1.5, 4.3);
glDisable(GL_LIGHTING);
poster1.prisma(0.5, 1.0, 0.5, t_tv.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();



glPopMatrix();

//****************************************Lámpara******************************************************

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(32.0, 12.9, -26.5);
glDisable(GL_LIGHTING);
fig3.cilindro(1, 0.25, 40, t_metalr.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(32.0, 13.1, -26.5);
glDisable(GL_LIGHTING);
fig3.cilindro(0.15, 1.9, 40, t_metalr.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(32.0, 14.9, -26.5);
glRotatef(-30, 1, 0, 0);
glDisable(GL_LIGHTING);
fig3.cilindro(0.15, 1.9, 40, t_metalr.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(32.0, 16.45, -27.5);
glRotatef(30, 0, 0, 1);
glRotatef(30, 1, 0, 0);
glDisable(GL_LIGHTING);
fig3.cilindro(0.15, 1.9, 40, t_metalr.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(31.0, 17.6, -26.1);
glRotatef(-30, 0, 0, 1);
glRotatef(-40, 1, 0, 0);
glDisable(GL_LIGHTING);
fig3.cilindro(0.5, 0.9, 40, t_metalr.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(30.6, 17.4, -25.9);
glRotatef(-30, 0, 0, 1);
glRotatef(-40, 1, 0, 0);
glDisable(GL_LIGHTING);
esf(0.75, 30, 30, t_metalr.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(30.6, 17.4, -25.9);
glRotatef(-30, 0, 0, 1);
glRotatef(-40, 1, 0, 0);
glDisable(GL_LIGHTING);
fig3.cilindro(0.7, 0.1, 30, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

//****************************************FinLámpara***************************************************

//******************************************Silla************************************************************

glPushMatrix();
glTranslatef(21.7, -3.0, -22.5); //mover silla completa
glRotated(225, 0.0, 1.0, 0.0);
glScalef(6.0, 6.0, 6.0);
glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.0, 1.5, 0.0);
glScalef(0.1, 2.0, 0.1);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tv.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.0, 1.5, -1.0);
glScalef(0.1, 2.0, 0.1);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tv.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(1.0, 1.5, -1.0);
glScalef(0.1, 2.0, 0.1);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tv.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(1.0, 1.5, -0.0);
glScalef(0.1, 2.0, 0.1);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tv.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Asiento
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.0, -0.5);
glScalef(1.3, 0.3, 2.0);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_escritorio.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Respaldo1
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.0, 2.45, 0.0);
glScalef(0.1, 1.5, 0.1);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tv.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Respaldo2
glColor3f(1.0, 1.0, 1.0);
glTranslatef(1.0, 2.45, -0.0);
glScalef(0.1, 1.5, 0.1);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tv.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Respaldo
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.5, -0.1);
glScalef(1.3, 1.0, 0.2);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_escritorio.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();


glPopMatrix();

//******************************************Mesa************************************************************

glPushMatrix();//MESA
glTranslatef(-8.7, 1.0, -45.8); //mover mesa completa
glScalef(4.0, 4.0, 5.5);
glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.0, 1.5, -0.25);
glScalef(0.2, 4.0, 0.3);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_cajonera.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.0, 1.5, -0.7);
glScalef(0.2, 4.0, 0.3);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(1.0, 1.5, -0.7);
glScalef(0.2, 4.0, 0.3);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(1.0, 1.5, -0.25);
glScalef(0.2, 4.0, 0.3);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Base
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.725, -0.5);
glScalef(1.3, 1.0, 1.3);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Base
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.9525, -0.5);
glScalef(1.55, 0.5, 1.55);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_cajonera.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPopMatrix();

//**************************lampara2******************************************************************
glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-6.6, 14.60, -48.0);
glDisable(GL_LIGHTING);
fig3.esfera(2.0, 60, 60, t_metalr.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-6.6, 16.10, -48.0);
glDisable(GL_LIGHTING);
fig3.cono(3, 2.5, 60, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

//************************************baul*********************************************************
glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-25.6, 5.60, -15.0);
glScalef(15, 5, 6);
glDisable(GL_LIGHTING);
fig3.prisma2(baul.GLindex, baul.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-18.1, 8.0, -14.8);
glRotatef(-90, 1, 0, 0);
glRotatef(90, 0, 0, 1);
glDisable(GL_LIGHTING);
cil(3, 15, 50, lona.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();
//******************************************Libreo************************************************************

glPushMatrix();
glTranslatef(20.7, 2.6, 16.0);
//glRotatef(90, 0.0, 1.0, 0.0);
glScalef(5.0, 5.0, 5.0);
glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-1.0, 1.8, -1.0);
glScalef(0.2, 7.0, 0.2);
glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tapizcama.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(2.0, 1.8, -1.0);
glScalef(0.2, 7.0, 0.2);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tapizcama.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-1.0, 1.8, 0.0);
glScalef(0.2, 7.0, 0.2);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tapizcama.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Patas
glColor3f(1.0, 1.0, 1.0);
glTranslatef(2.0, 1.8, 0.0);
glScalef(0.2, 7.0, 0.2);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tapizcama.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Repisa1
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 0.525, -0.5);
glScalef(3.5, 0.3, 2.5);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tapizcama.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Repisa2
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.525, -0.5);
glScalef(3.5, 0.3, 2.5);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tapizcama.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Repisa3
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.525, -0.5);
glScalef(3.5, 0.3, 2.5);
//glDisable(GL_LIGHTING);
casa.prisma(0.5, 1.0, 0.5, t_tapizcama.GLindex);
//glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Libros1
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 1.0, -0.5);
glScalef(2.5, 2.0, 1.5);
glDisable(GL_LIGHTING);
glEnable(GL_ALPHA_TEST);
glAlphaFunc(GL_GREATER, 0.1f);
casa.prisma(0.5, 1.0, 0.5, t_librero2.GLindex);
glDisable(GL_ALPHA_TEST);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//Libros2
glColor3f(1.0, 1.0, 1.0);
glTranslatef(0.5, 2.0, -0.5);
glScalef(2.5, 2.0, 1.5);
glDisable(GL_LIGHTING);
glEnable(GL_ALPHA_TEST);
glAlphaFunc(GL_GREATER, 0.1f);
casa.prisma(0.5, 1.0, 0.5, t_librero1.GLindex);
glDisable(GL_ALPHA_TEST);
glEnable(GL_LIGHTING);
glPopMatrix();

glPopMatrix();

//**********************************Posters*****************************************************

glPushMatrix();//ABC
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-38.5, 30.9, -27.75);
glRotated(90, 0.0, 1.0, 0.0);
glScalef(12.0, 16.0, 0.1);
glDisable(GL_LIGHTING);
poster1.prisma(0.5, 1.0, 0.5, t_posterabc.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();//buzz
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-23.8, 30.9, -45.5);
glScalef(12, 16, 0.1);
glDisable(GL_LIGHTING);
poster1.prisma(0.5, 1.0, 0.5, t_posterbuzz.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//**********************************FIN Posters*****************************************************

///////////////////////////////prisma arnold
glPushMatrix();
glTranslatef(0.0, 75.5, -17.0);
glScaled(78.0, 48.0, 68.0);
glDisable(GL_LIGHTING);
prisAR(t_pared.GLindex, t_lib.GLindex, t_piso.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//prisma casa
	glPushMatrix();
	glTranslatef(0.0, 50.25, -17.0);
	glScaled(80.0, 98.5, 70.0);
	glDisable(GL_LIGHTING);
	prisAR(t_paredr.GLindex, t_paredr.GLindex, t_paredr.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();




			glColor3f(1.0, 1.0, 1.0);

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	
		fig3.text_izq-= 0.007;
		fig3.text_der-= 0.007;
		if(fig3.text_izq<-1)
			fig3.text_izq=0;
		if(fig3.text_der<0)
			fig3.text_der=1;


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
