#include<iostream>
using namespace std;
#include<Windows.h>
//#include<MMSytem.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include <gl/glut.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<string.h>
#define SPACEBAR 32


bool red=true;
bool red2=true;
bool red3=true;
bool red4=true;
bool red5=true;
bool green=true;
bool green2=true;
bool green3=true;
bool green4=true;
bool green5=true;
bool blue=true;
bool yellow=true;
bool check=true;
bool orange=false;
float rt1=0.0f;
float rt2=0.0f;
float rt3=0.0f;
float rt4=0.0f;
float rt5=0.0f;
float rt6=0.0f;
float rt7=0.0f;
float rt8=0.0f;
float rt9=0.0f;
float xe;
float xe2;
float xe3;
float xe4;
float xe5=0.55f;
float laddpay=0.00;
float laddpax=0.00;
float x=0.0f;
float zx=0.02f;
float zx2=0.02f;
float zx3=0.02f;
float zx4=0.02f;
float zx5=0.02f;
//
float bx=0.0f;
float bx2=0.0f;
float ex=0.0f;

GLfloat xx = 0.0f;
GLfloat yy=0.0f;
GLfloat xp=0.0f;
void bulletupdate(int);
void enemybulletupdate(int);
void enemybulletupdate2(int);
void enemybulletupdate3(int);

//indicating the last boundary;
GLfloat bulletpos=0.00f;
GLfloat bulletspeed=0.0f;
//indicating jump variable;
GLfloat jumpposition=0.0f;
//distance count for enemy
GLfloat enemydis;
GLfloat enemydis2;
GLfloat enemydis3;
GLfloat enemydis4;
GLfloat bossdis;
//distance count for player
GLfloat playerdis;
GLfloat playerdis2;
GLfloat playerdis3;
GLfloat playerdis4;
GLfloat playerdis5;
GLfloat playerdis6;
GLfloat playerdis7;
GLfloat playerdis8;

//enemy  health
int ehealth=15;
int ehealth2=15;
int ehealth3=15;
int ehealth4=15;
int bosshealth=50;
//player health
int phealth=20;
//indicating enemy bullet variable
GLfloat enemybulletposition=0.00f;
GLfloat enemybulletposition2=0.00f;
GLfloat enemybulletposition3=0.00f;
GLfloat enemybulletposition4=0.00f;
GLfloat bossbulletposition=0.00f;
bool s=true;
float c;
void displaylife()
{
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(76,0,153);
    if(phealth<16)
    glColor3ub(255,255,51);


     glBegin(GL_POLYGON);
            glVertex2f(0.890,0.90);
            glVertex2f(0.905,0.90);
            glVertex2f(0.905,0.94);
            glVertex2f(0.890,0.94);
        glEnd();
        glColor3ub(76,0,153);
         if( phealth<11)
    glColor3ub(255,255,51);



     glBegin(GL_POLYGON);
            glVertex2f(0.890+0.03,0.90);
            glVertex2f(0.905+0.03,0.90);
            glVertex2f(0.905+0.03,0.94);
            glVertex2f(0.890+0.03,0.94);
        glEnd();
           glColor3ub(76,0,153);
            if( phealth<6 )
    glColor3ub(255,255,51);



     glBegin(GL_POLYGON);
            glVertex2f(0.890+0.06,0.90);
            glVertex2f(0.905+0.06,0.90);
            glVertex2f(0.905+0.06,0.94);
            glVertex2f(0.890+0.06,0.94);
        glEnd();
                glColor3ub(76,0,153);
                 if( phealth<1)
    glColor3ub(255,255,51);



     glBegin(GL_POLYGON);
            glVertex2f(0.890+0.09,0.90);
            glVertex2f(0.905+0.09,0.90);
            glVertex2f(0.905+0.09,0.94);
            glVertex2f(0.890+0.09,0.94);
        glEnd();





}
void displayRasterText(float x ,float y ,float z ,char *stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
		length = strlen(stringToDisplay);

	for(int i=0 ;i<length ;i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,stringToDisplay[i]);
	}
}
void gamewindisplay()
{
    char temp[80];
	glColor3f(255 ,0 ,0);
	sprintf(temp,"MISSION COMPLETED");
	displayRasterText(-0.20 ,0.1 ,0 ,temp);


}
void gameoverscreen()
{


        char temp[80];
	glColor3f(255 ,0 ,0);
	sprintf(temp,"MISSION FAILED");
	displayRasterText(-0.20 ,0.1 ,0 ,temp);


}
void bossbulletupdate(int value)
{
    glutTimerFunc(10,bossbulletupdate,0.0f);
    if(bossbulletposition<2.80)
    {
        bossbulletposition=bossbulletposition-zx5;
    }
    glutPostRedisplay();
}
void enemybulletupdate(int value)
{

    glutTimerFunc(12,enemybulletupdate,0.0f);
    if(enemybulletposition<2.80)
    {
        enemybulletposition=enemybulletposition+zx;
    }
    if(enemybulletposition<0.02 && enemybulletposition>0 )
    {

       PlaySound(TEXT("Silencer-SoundBible.com-1632156458.wav"), NULL, SND_ASYNC);
    }

glutPostRedisplay();
}
void enemybulletupdate2(int value)
{

    glutTimerFunc(12,enemybulletupdate2,0.0f);
    if(enemybulletposition2<2.80)
    {
        enemybulletposition2=enemybulletposition2+zx2;
    }

glutPostRedisplay();
}
void enemybulletupdate3(int value)
{

    glutTimerFunc(12,enemybulletupdate3,0.0f);
    if(enemybulletposition3<2.80)
    {
        enemybulletposition3=enemybulletposition3-zx3;
    }

glutPostRedisplay();
}
void enemybulletupdate4(int value)
{

    glutTimerFunc(12,enemybulletupdate4,0.0f);
    if(enemybulletposition4<2.80)
    {
        enemybulletposition4=enemybulletposition4-zx4;
    }

glutPostRedisplay();
}






void bulletupdate(int value)
{

    if(rt1==0.0 )
    {

    bulletpos -= bulletspeed;

    }

    if(rt1>0 )
    bulletpos += bulletspeed;


	glutPostRedisplay();


	glutTimerFunc(2, bulletupdate, 0);
}
void jumpupdate(int value)
{
    if(jumpposition!=0)
    {
        jumpposition-=0.008f;
    }
    if(jumpposition<=0)
    {
        jumpposition=0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(18,jumpupdate,0);
}
void enemyupdate(int value)
{
    glutPostRedisplay();
    glutTimerFunc(40,enemyupdate,0);
    if(xe<=0)
    {
        xe=xe+0.02;
    }
}
void enemyupdate2(int value)
{
    glutPostRedisplay();
    glutTimerFunc(40,enemyupdate2,0);
    if(xe2<=0)
    {
        xe2=xe2+0.02;
    }
}
void enemyupdate3(int value)
{
    glutPostRedisplay();
    glutTimerFunc(40,enemyupdate3,0);
    if(xe3>=0)
    {
        xe3=xe3-0.02;
    }
}
void enemyupdate4(int value)
{
    glutPostRedisplay();
    glutTimerFunc(40,enemyupdate4,0);
    if(xe4>=0)
    {
        xe4=xe4-0.02;
    }
}
void bossupdate(int value)
{
    glutPostRedisplay();
    glutTimerFunc(30,bossupdate,0);
    if(xe5>=0 && red4==false)
    {
        xe5=xe5-0.01;

            ex=ex+0.01;

    }
}
//activating button
void keyboardKeys(unsigned char key,int x,int y)
{
     switch(key)
    {
    case 'a':
        if(bulletpos==0)
        {
             if(xx>-1.86 && yy<0.01 || xx>-1.86 &&yy>0.49 && yy<0.51f|| xx>-1.86 &&yy>0.99&& yy<1.00f|| xx>-1.86 &&yy>1.49 &&yy<1.50  )
        {
            if(rt1>0)
            {
                rt1=0.0f;
                rt2=0.0f;
                rt3=0.0f;
                rt4=0.0f;
                rt5=0.0f;
                rt6=0.0f;
                rt7=0.0f;
                rt8=0.0f;
                rt9=0.0f;
            }


        xx-=0.01f;

        }


        }








        glutPostRedisplay();
        break;
    case 'd':
        if(bulletpos==0)
        {
            if(xx<0.035 &&yy<0.01|| xx<0.035 &&yy>0.49&& yy<0.50f|| xx<0.035 &&yy>0.99 && yy<1.00f|| xx<0.035 &&yy>1.49 &&yy<1.50  )
        {
            if(rt1<0.05)
        {
            rt1=0.05;
        }
        if(rt2<0.077)
        {
            rt2=0.104;
        }
        if(rt3<0.13)
        {
            rt3=0.13;
        }
        if(rt4<0.126)
        {
            rt4=0.114;
        }
        if(rt5<0.158)
        {
            rt5=0.160;
        }
        if(rt6<0.015)
        {
            rt6=0.015;
        }
        if(rt7<0.033)
        {
            rt7=0.033;

        }
        if(rt8<0.123)
        {
            rt8=0.123;
        }
        if(rt9<0.151)
        {
            rt9=0.151;
        }
        xx+=0.01f;




        }



        }


        glutPostRedisplay();



        break;
    case 'w':
        if(xx<=-1.770&&xx>=-1.83&&yy<=0.491 || xx>-0.12 && xx<-0.07 && yy>=0.491 &&yy<=0.99 || xx<=-1.770 && xx>=-1.83 && yy>=0.99 &&yy<=1.49 )
            yy+=0.01f;
            break;

    case 'j':




  PlaySound(TEXT("GunShot2.wav"), NULL, SND_ASYNC );
        bulletspeed=0.005f;



        glutPostRedisplay();
        break;
    case SPACEBAR:
        jumpposition=0.28f;
        glutPostRedisplay();
        break;

    }

}
void createenemy()
{
    enemydis=-1.73-xx+xe;
    float angl;
     glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(76,0,153);
     //left leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.90+xe,-1);
            glVertex2f(-0.88+xe,-1);
            glVertex2f(-0.88+xe,-0.935);
            glVertex2f(-0.90+xe,-0.935);
        glEnd();
        //leftshoe
        glBegin(GL_POLYGON);
            glVertex2f(-0.90+xe,-1);
            glVertex2f(-0.90+xe,-0.970);
            glVertex2f(-0.865+xe,-1);

        glEnd();

        //right leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.865+xe,-1);
            glVertex2f(-0.845+xe,-1);
            glVertex2f(-0.845+xe,-0.935);
            glVertex2f(-0.865+xe,-0.935);
        glEnd();
        //rightshoe
        glBegin(GL_POLYGON);
            glVertex2f(-0.865+xe,-1);
            glVertex2f(-0.865+xe,-0.970);
            glVertex2f(-0.830+xe,-1);

        glEnd();
        //body
         glColor3ub(255,0,0);
          glBegin(GL_POLYGON);

            glVertex2f(-0.905+xe,-0.935);
            glVertex2f(-0.840+xe,-0.935);
            glVertex2f(-0.840+xe,-0.860);
            glVertex2f(-0.905+xe,-0.860);
        glEnd();
        //shoulder
        glColor3ub(255,0,0);
         glBegin(GL_POLYGON);

            glVertex2f(-0.905+xe,-0.86);
            glVertex2f(-0.870+xe,-0.840);
            glVertex2f(-0.875+xe,-0.840);
            glVertex2f(-0.840+xe,-0.86);
        glEnd();
        //hand
        glBegin(GL_POLYGON);

            glVertex2f(-0.840+xe,-0.860);
            glVertex2f(-0.840+xe,-0.873);
            glVertex2f(-0.800+xe,-0.873);
            glVertex2f(-0.800+xe,-0.860);
        glEnd();
        //weapon
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);

            glVertex2f(-0.802+xe,-0.862);
            glVertex2f(-0.802+xe,-0.850);
            glVertex2f(-0.7750+xe,-0.850);
            glVertex2f(-0.7750+xe,-0.862);
        glEnd();
        //palm
        glColor3ub(148,10,0);
         glBegin(GL_POLYGON);

            glVertex2f(-0.800+xe,-0.873);
            glVertex2f(-0.790+xe,-0.873);
            glVertex2f(-0.790+xe,-0.858);
            glVertex2f(-0.800+xe,-0.858);
        glEnd();
        //head
glBegin(GL_POLYGON);
            glColor3ub(148,10,0);

            for(int i=0;i<360;i++)
            {
                angl=i*3.142/180;
                glVertex2f(-0.8725+xe+.018*cos(angl),-0.830+.018*sin(angl));
            }
            glEnd();
            glPopMatrix();
             if(bulletpos<enemydis && bulletpos!=0)
   {
          bulletpos=0.0f;
          bulletspeed=0.0f;
          ehealth=ehealth-5;



          if(ehealth==0)
          {

           xe=-0.30f;



          }
           if(ehealth==-15.0)
              {
                 xe=-0.30f;
              }
              if(ehealth==-30.0)
              {
                 red=false;

                 zx=-2.0f;
              }
            if(red==false)
            {
                orange=true;
                green=false;
                enemybulletposition=0.0f;
            }


   }
   glEnd();


}
void createenemy2()
{
    enemydis2=-1.73-xx+xe2;
    float angll;

    glPushMatrix();
     glColor3ub(76,0,153);
     //left leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.90+xe2,-1+1);
            glVertex2f(-0.88+xe2,-1+1);
            glVertex2f(-0.88+xe2,-0.935+1);
            glVertex2f(-0.90+xe2,-0.935+1);
        glEnd();
        //leftshoe
        glBegin(GL_POLYGON);
            glVertex2f(-0.90+xe2,-1+1);
            glVertex2f(-0.90+xe2,-0.970+1);
            glVertex2f(-0.865+xe2,-1+1);

        glEnd();

        //right leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.865+xe2,-1+1);
            glVertex2f(-0.845+xe2,-1+1);
            glVertex2f(-0.845+xe2,-0.935+1);
            glVertex2f(-0.865+xe2,-0.935+1);
        glEnd();
        //rightshoe
        glBegin(GL_POLYGON);
            glVertex2f(-0.865+xe2,-1+1);
            glVertex2f(-0.865+xe2,-0.970+1);
            glVertex2f(-0.830+xe2,-1+1);

        glEnd();
        //body
         glColor3ub(255,0,0);
          glBegin(GL_POLYGON);

            glVertex2f(-0.905+xe2,-0.935+1);
            glVertex2f(-0.840+xe2,-0.935+1);
            glVertex2f(-0.840+xe2,-0.860+1);
            glVertex2f(-0.905+xe2,-0.860+1);
        glEnd();
        //shoulder
        glColor3ub(255,0,0);
         glBegin(GL_POLYGON);

            glVertex2f(-0.905+xe2,-0.86+1);
            glVertex2f(-0.870+xe2,-0.840+1);
            glVertex2f(-0.875+xe2,-0.840+1);
            glVertex2f(-0.840+xe2,-0.86+1);
        glEnd();
        //hand
        glBegin(GL_POLYGON);

            glVertex2f(-0.840+xe2,-0.860+1);
            glVertex2f(-0.840+xe2,-0.873+1);
            glVertex2f(-0.800+xe2,-0.873+1);
            glVertex2f(-0.800+xe2,-0.860+1);
        glEnd();
        //weapon
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);

            glVertex2f(-0.802+xe2,-0.862+1);
            glVertex2f(-0.802+xe2,-0.850+1);
            glVertex2f(-0.7750+xe2,-0.850+1);
            glVertex2f(-0.7750+xe2,-0.862+1);
        glEnd();
        //palm
        glColor3ub(148,10,0);
         glBegin(GL_POLYGON);

            glVertex2f(-0.800+xe2,-0.873+1);
            glVertex2f(-0.790+xe2,-0.873+1);
            glVertex2f(-0.790+xe2,-0.858+1);
            glVertex2f(-0.800+xe2,-0.858+1);
        glEnd();
        //head
glBegin(GL_POLYGON);
            glColor3ub(148,10,0);

            for(int i=0;i<360;i++)
            {
                angll=i*3.142/180;
                glVertex2f(-0.8725+xe2+.018*cos(angll),-0.830+1+.018*sin(angll));
            }
            glEnd();
            glPopMatrix();
            if(bulletpos<enemydis2 )
   {
       if(yy>0.98)
       {
            bulletpos=0.0f;
          bulletspeed=0.0f;
          ehealth2=ehealth2-5;



           if(ehealth2==0)
          {

           xe2=-0.30f;



          }
           if(ehealth2==-15.0)
              {
                 xe2=-0.30f;
              }
              if(ehealth2==-30.0)
              {
                 red2=false;

                 zx2=-2.0f;
              }
            if(red2==false)
            {
                green2=false;
                enemybulletposition2=0.0f;
            }


       }


   }



}

void createenemy3()
{
    enemydis3=-(0.31+xx+xe3);
    float angl;
     glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(76,0,153);
     //left leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.90+1.60+xe3,-1+0.50);
            glVertex2f(-0.88+1.60+xe3,-1+0.50);
            glVertex2f(-0.88+1.60+xe3,-0.935+0.50);
            glVertex2f(-0.90+1.60+xe3,-0.935+0.50);
        glEnd();
        //leftshoe
        glBegin(GL_POLYGON);
            glVertex2f(0.70+0.020-0.02+xe3,-1+0.50);
            glVertex2f(0.70+0.0200-0.02+xe3,-0.985+0.50);
            glVertex2f(0.665+0.0200+xe3,-1+0.50);

        glEnd();

        //right leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.865+1.60+xe3,-1+0.50);
            glVertex2f(-0.845+1.60+xe3,-1+0.50);
            glVertex2f(-0.845+1.60+xe3,-0.935+0.50);
            glVertex2f(-0.865+1.60+xe3,-0.935+0.50);
        glEnd();
        //rightshoe
        glBegin(GL_POLYGON);
            glVertex2f(0.735+0.0200-0.02+xe3,-1+0.50);
            glVertex2f(0.735+0.0200-0.02+xe3,-0.985+0.50);
            glVertex2f(0.700+0.0200+xe3,-1+0.50);

        glEnd();
        //body
         glColor3ub(102,0,51);
          glBegin(GL_POLYGON);

            glVertex2f(-0.905+1.60+xe3,-0.935+0.50);
            glVertex2f(-0.840+1.60+xe3,-0.935+0.50);
            glVertex2f(-0.840+1.60+xe3,-0.860+0.50);
            glVertex2f(-0.905+1.60+xe3,-0.860+0.50);
        glEnd();
        //shoulder
        glColor3ub(102,0,51);
         glBegin(GL_POLYGON);

            glVertex2f(-0.905+1.60+xe3,-0.86+0.50);
            glVertex2f(-0.870+1.60+xe3,-0.840+0.50);
            glVertex2f(-0.875+1.60+xe3,-0.840+0.50);
            glVertex2f(-0.840+1.60+xe3,-0.86+0.50);
        glEnd();
        //hand
        glBegin(GL_POLYGON);

            glVertex2f(0.76-0.065+xe3,-0.860+0.50);
            glVertex2f(0.76-0.065+xe3,-0.873+0.50);
            glVertex2f(0.800-0.145+xe3,-0.873+0.50);
            glVertex2f(0.800-0.145+xe3,-0.860+0.50);
        glEnd();
        //weapon
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);

            glVertex2f(-0.802-0.140+1.60+xe3,-0.862+0.50);
            glVertex2f(-0.802-0.140+1.60+xe3,-0.850+0.50);
            glVertex2f(-0.7750-0.195+1.60+xe3,-0.850+0.50);
            glVertex2f(-0.7750-0.195+1.60+xe3,-0.862+0.50);
        glEnd();
        //palm
        glColor3ub(255,51,51);
         glBegin(GL_POLYGON);

            glVertex2f(-0.800-0.155+1.60+xe3,-0.873+0.50);
            glVertex2f(-0.790-0.145+1.60+xe3,-0.873+0.50);
            glVertex2f(-0.790-0.145+1.60+xe3,-0.858+0.50);
            glVertex2f(-0.800-0.155+1.60+xe3,-0.858+0.50);
        glEnd();
        //head
glBegin(GL_POLYGON);
            glColor3ub(255,51,51);

            for(int i=0;i<360;i++)
            {
                angl=i*3.142/180;
                glVertex2f(-0.8725+1.60+xe3+.018*cos(angl),-0.830+0.50+.018*sin(angl));
            }
            glEnd();
            glPopMatrix();

   glEnd();
       if(bulletpos>enemydis3 && bulletpos!=0)
   {
       if(yy>0.48)
       {
            bulletpos=0.0f;
          bulletspeed=0.0f;
          ehealth3=ehealth3-5;



            if(ehealth3==0)
          {

           xe3=0.36f;



          }
           if(ehealth3==-15.0)
              {
                 xe3=0.36f;
              }
              if(ehealth3==-30.0)
              {
                 red3=false;

                 zx3=-2.0f;
              }
            if(red3==false)
            {
                green3=false;
                enemybulletposition3=0.0f;
            }


       }


   }


}
void createenemy4()
{
    enemydis4=-(0.31+xx+xe4);
    float angl;
     glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(76,0,153);
     //left leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.90+1.60+xe4,-1+0.50+1);
            glVertex2f(-0.88+1.60+xe4,-1+0.50+1);
            glVertex2f(-0.88+1.60+xe4,-0.935+0.50+1);
            glVertex2f(-0.90+1.60+xe4,-0.935+0.50+1);
        glEnd();
        //leftshoe
        glBegin(GL_POLYGON);
            glVertex2f(0.70+0.020-0.02+xe4,-1+0.50+1);
            glVertex2f(0.70+0.0200-0.02+xe4,-0.985+0.50+1);
            glVertex2f(0.665+0.0200+xe4,-1+0.50+1);

        glEnd();

        //right leg

     glBegin(GL_POLYGON);
            glVertex2f(-0.865+1.60+xe4,-1+0.50+1);
            glVertex2f(-0.845+1.60+xe4,-1+0.50+1);
            glVertex2f(-0.845+1.60+xe4,-0.935+0.50+1);
            glVertex2f(-0.865+1.60+xe4,-0.935+0.50+1);
        glEnd();
        //rightshoe
        glBegin(GL_POLYGON);
            glVertex2f(0.735+0.0200-0.02+xe4,-1+0.50+1);
            glVertex2f(0.735+0.0200-0.02+xe4,-0.985+0.50+1);
            glVertex2f(0.700+0.0200+xe4,-1+0.50+1);

        glEnd();
        //body
         glColor3ub(102,0,51);
          glBegin(GL_POLYGON);

            glVertex2f(-0.905+1.60+xe4,-0.935+0.50+1);
            glVertex2f(-0.840+1.60+xe4,-0.935+0.50+1);
            glVertex2f(-0.840+1.60+xe4,-0.860+0.50+1);
            glVertex2f(-0.905+1.60+xe4,-0.860+0.50+1);
        glEnd();
        //shoulder
        glColor3ub(102,0,51);
         glBegin(GL_POLYGON);

            glVertex2f(-0.905+1.60+xe4,-0.86+0.50+1);
            glVertex2f(-0.870+1.60+xe4,-0.840+0.50+1);
            glVertex2f(-0.875+1.60+xe4,-0.840+0.50+1);
            glVertex2f(-0.840+1.60+xe4,-0.86+0.50+1);
        glEnd();
        //hand
        glBegin(GL_POLYGON);

            glVertex2f(0.76-0.065+xe4,-0.860+0.50+1);
            glVertex2f(0.76-0.065+xe4,-0.873+0.50+1);
            glVertex2f(0.800-0.145+xe4,-0.873+0.50+1);
            glVertex2f(0.800-0.145+xe4,-0.860+0.50+1);
        glEnd();
        //weapon
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);

            glVertex2f(-0.802-0.140+1.60+xe4,-0.862+0.50+1);
            glVertex2f(-0.802-0.140+1.60+xe4,-0.850+0.50+1);
            glVertex2f(-0.7750-0.195+1.60+xe4,-0.850+0.50+1);
            glVertex2f(-0.7750-0.195+1.60+xe4,-0.862+0.50+1);
        glEnd();
        //palm
        glColor3ub(255,51,51);
         glBegin(GL_POLYGON);

            glVertex2f(-0.800-0.155+1.60+xe4,-0.873+0.50+1);
            glVertex2f(-0.790-0.145+1.60+xe4,-0.873+0.50+1);
            glVertex2f(-0.790-0.145+1.60+xe4,-0.858+0.50+1);
            glVertex2f(-0.800-0.155+1.60+xe4,-0.858+0.50+1);
        glEnd();
        //head
glBegin(GL_POLYGON);
            glColor3ub(255,51,51);

            for(int i=0;i<360;i++)
            {
                angl=i*3.142/180;
                glVertex2f(-0.8725+1.60+xe4+.018*cos(angl),-0.830+0.50+1+.018*sin(angl));
            }
            glEnd();
            glPopMatrix();

   glEnd();
       if(bulletpos>enemydis4 && bulletpos!=0)
   {
       if(yy>1.48)
       {
            bulletpos=0.0f;
          bulletspeed=0.0f;
          ehealth4=ehealth4-5;



            if(ehealth4==0)
          {

           xe4=0.36f;



          }
           if(ehealth4==-15.0)
              {
                 xe4=0.36f;
              }
              if(ehealth4==-30.0)
              {
                 red4=false;

                 zx4=-2.0f;
              }
            if(red4==false)
            {
                green4=false;
                enemybulletposition4=0.0f;
                //ex=0.55;
            }


       }


   }


}
void createboss()
{
    bossdis=-(0.31+xx+xe5);
    float angl;
     glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
     glColor3ub(76,0,153);
     //left leg

     glBegin(GL_POLYGON);
            glVertex2f(0.695+xe5,0.50);
            glVertex2f(0.720+xe5,0.50);
            glVertex2f(0.720+xe5,0.575);
            glVertex2f(0.695+xe5,0.575);
        glEnd();
        //leftshoe
        glBegin(GL_POLYGON);
            glVertex2f(0.695+xe5,0.50);
            glVertex2f(0.695+xe5,0.520);
            glVertex2f(0.675+xe5,0.50);

        glEnd();

        //right leg

     glBegin(GL_POLYGON);
            glVertex2f(0.733+xe5,0.50);
            glVertex2f(0.758+xe5,0.50);
            glVertex2f(0.758+xe5,0.575);
            glVertex2f(0.733+xe5,0.575);
        glEnd();
        //rightshoe
        glBegin(GL_POLYGON);
            glVertex2f(0.735+xe5,0.50);
            glVertex2f(0.735+xe5,0.520);
            glVertex2f(0.715+xe5,0.50);

        glEnd();
        //body
         glColor3ub(102,0,51);
          glBegin(GL_POLYGON);

            glVertex2f(0.688+xe5,0.565);
            glVertex2f(0.762+xe5,0.565);
            glVertex2f(0.762+xe5,0.66);
            glVertex2f(0.688+xe5,0.66);
        glEnd();
        //shoulder
        glColor3ub(102,0,51);
         glBegin(GL_POLYGON);

            glVertex2f(0.688+xe5,0.66);
            glVertex2f(0.762+xe5,0.66);
            glVertex2f(0.732+xe5,0.682);
            glVertex2f(0.718+xe5,0.682);
        glEnd();
        //hand
        glBegin(GL_POLYGON);

            glVertex2f(0.688+xe5,0.66);
            glVertex2f(0.688+xe5,0.641);
            glVertex2f(0.643+xe5,0.641);
            glVertex2f(0.643+xe5,0.66);
        glEnd();
        //weapon
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);

            glVertex2f(0.640+xe5,0.655);
            glVertex2f(0.640+xe5,0.670);
            glVertex2f(0.612+xe5,0.670);
            glVertex2f(0.612+xe5,0.655);
        glEnd();
        //palm
        glColor3ub(255,51,51);
         glBegin(GL_POLYGON);

            glVertex2f(0.643+xe5,0.641);
            glVertex2f(0.628+xe5,0.641);
            glVertex2f(0.628+xe5,0.6625);
            glVertex2f(0.643+xe5,0.6625);
        glEnd();
        //head
glBegin(GL_POLYGON);
            glColor3ub(255,51,51);

            for(int i=0;i<360;i++)
            {
                angl=i*3.142/180;
                glVertex2f(0.725+xe5+.021*cos(angl),0.695+.021*sin(angl));
            }
            glEnd();
            glPopMatrix();
            if(bulletpos>bossdis&& bulletpos!=0 && red4==false)
   {
       if(yy>1.48)
       {
            bulletpos=0.0f;
          bulletspeed=0.0f;
          bosshealth=bosshealth-5;



            if(bosshealth==0)
          {

           red5=false;



          }

            if(red5==false)
            {
                green5=false;
                bossbulletposition=0.0f;
                //ex=0.55;
            }


       }


   }




}





//player
void createplayer()
{
    if(yy>1.47)
    {
        bx=-0.197;
        bx2=-0.237;
    }


    playerdis=1.67+xx;
    playerdis2=1.71+xx;
    playerdis3=0.31+xx-xe3;
    playerdis4=0.26+xx-xe3;
     playerdis5=0.31+xx-xe4;
    playerdis6=0.26+xx-xe4;
    playerdis7=bx+xx+ex;
    playerdis8=bx2+xx+ex;

    float ang;
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glColor3ub(0,0,0);


//right leg

     glTranslatef(xx,jumpposition,0.0);
     glBegin(GL_POLYGON);
            glVertex2f(0.96,-1+yy);
            glVertex2f(0.945,-1+yy);
            glVertex2f(0.945,-0.925+yy);
            glVertex2f(0.96,-0.925+yy);
        glEnd();
//right shoe
glBegin(GL_POLYGON);
            glVertex2f(0.945+rt6,-1+yy);
            glVertex2f(0.945+rt6,-0.985+yy);
            glVertex2f(0.936+rt7,-1+yy);

        glEnd();
//left leg
       glBegin(GL_POLYGON);
            glVertex2f(0.935,-1+yy);
            glVertex2f(0.92,-1+yy);
            glVertex2f(0.92,-0.925+yy);
            glVertex2f(0.935,-0.925+yy);
        glEnd();
//left shoe
       glBegin(GL_POLYGON);
            glVertex2f(0.920+rt6,-1+yy);
            glVertex2f(0.920+rt6,-0.985+yy);
            glVertex2f(0.911+rt7,-1+yy);
        glEnd();
//body

     glBegin(GL_POLYGON);

            glVertex2f(0.965,-0.925+yy);
            glVertex2f(0.915,-0.925+yy);
            glVertex2f(0.915,-0.850+yy);
            glVertex2f(0.965,-0.850+yy);
        glEnd();
//shoulder
      glBegin(GL_POLYGON);

            glVertex2f(0.915,-0.850+yy);
            glVertex2f(0.935,-0.835+yy);
            glVertex2f(0.945,-0.835+yy);
            glVertex2f(0.965,-0.850+yy);
        glEnd();
//hand
         glBegin(GL_POLYGON);


            glVertex2f(0.915+rt1,-0.850+yy);
            glVertex2f(0.888+rt2,-0.850+yy);
            glVertex2f(0.888+rt2,-0.865+yy);
            glVertex2f(0.915+rt1,-0.865+yy);
        glEnd();
//palm
        glBegin(GL_POLYGON);
        glColor3ub(210,105,30);

           glVertex2f(0.888+rt2,-0.847+yy);
            glVertex2f(0.875+rt3,-0.847+yy);
            glVertex2f(0.875+rt3,-0.865+yy);
            glVertex2f(0.888+rt2,-0.865+yy);
        glEnd();

//head
glBegin(GL_POLYGON);
            glColor3ub(210,105,30);

            for(int i=0;i<360;i++)
            {
                ang=i*3.142/180;
                glVertex2f(0.940+.016*cos(ang),-0.818+yy+.016*sin(ang));
            }
            glEnd();

//weapon

 glBegin(GL_POLYGON);
        glColor3ub(0,0,0);

           glVertex2f(0.883+rt4,-0.847+yy);
            glVertex2f(0.883+rt4,-0.833+yy);
            glVertex2f(0.860+rt5,-0.833+yy);
            glVertex2f(0.860+rt5,-0.847+yy);
        glEnd();
        glPopMatrix();
        if(enemybulletposition>playerdis && enemybulletposition<playerdis2)
        {
            if(jumpposition<0.14 && jumpposition>0 )
            {
                  enemybulletposition=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }
            if(jumpposition==0)
            {
                  enemybulletposition=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }

        }
        //for enemy2
        if(enemybulletposition2>playerdis && enemybulletposition2<playerdis2 && yy>0.98)
        {
            if(jumpposition<0.14 && jumpposition>0 )
            {
                  enemybulletposition2=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }
            if(jumpposition==0)
            {
                  enemybulletposition2=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }

        }
        //for enemy3
       if(enemybulletposition3<playerdis3 && enemybulletposition3>playerdis4 )
        {
            if(jumpposition<0.14 && jumpposition>0 )
            {
                  enemybulletposition3=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }
            if(jumpposition==0)
            {
                  enemybulletposition3=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }

        }
        //for enemy4
           if(enemybulletposition4<playerdis5 && enemybulletposition4>playerdis6 )
        {
            if(jumpposition<0.14 && jumpposition>0 )
            {
                  enemybulletposition4=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }
            if(jumpposition==0)
            {
                  enemybulletposition4=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }

        }
//for boss

if(bossbulletposition<playerdis7 && bossbulletposition>playerdis8 )
        {
            if(jumpposition<0.14 && jumpposition>0 )
            {
                  bossbulletposition=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }
            if(jumpposition==0)
            {
                  bossbulletposition=0.0f;
            phealth=phealth-5;
                 if(phealth==0)
        {
            blue=false;
            yellow=false;
        }


            }

        }




}
void createfloor()
{

        glColor3ub(0,0,0);
        for(float a=0.0;a<=1.00;a=a+0.50)
        {
             glBegin(GL_POLYGON);
            glVertex2f(1,-0.50+a);
            glVertex2f(-1,-0.50+a);
            glVertex2f(-1,-0.52+a);
            glVertex2f(1,-0.52+a);
            glEnd();

        }





}
void createenemybullet3()
{
    glColor3ub(0,0,0);
    //bullet

glPushMatrix();
glTranslatef(enemybulletposition3,0.0,0.0);

glBegin(GL_POLYGON);

            glVertex2f(-0.780+1.435+xe3,-0.862+0.50);
            glVertex2f(-0.780+1.435+xe3,-0.850+0.50);
            glVertex2f(-0.755+1.435+xe3,-0.850+0.50);
            glVertex2f(-0.755+1.435+xe3,-0.862+0.50);
        glEnd();

          glPopMatrix();

       if(enemybulletposition3<-2.78)
    {
        enemybulletposition3=0.0f;
        createenemybullet3();
    }
    if(red3==false)
    {
        green3=false;
        enemybulletposition3=0.0f;
    }

   }
   void createenemybullet4()
{
    glColor3ub(0,0,0);
    //bullet

glPushMatrix();
glTranslatef(enemybulletposition4,0.0,0.0);

glBegin(GL_POLYGON);

            glVertex2f(-0.780+1.435+xe4,-0.862+0.50+1);
            glVertex2f(-0.780+1.435+xe4,-0.850+0.50+1);
            glVertex2f(-0.755+1.435+xe4,-0.850+0.50+1);
            glVertex2f(-0.755+1.435+xe4,-0.862+0.50+1);
        glEnd();

          glPopMatrix();

       if(enemybulletposition4<-2.78)
    {
        enemybulletposition4=0.0f;
        createenemybullet4();
    }
    if(red4==false)
    {
        green4=false;
        enemybulletposition4=0.0f;
    }

   }
    void createbossbullet()
{
    glColor3ub(0,0,0);
    //bullet

glPushMatrix();
glTranslatef(bossbulletposition,0.0,0.0);

glBegin(GL_POLYGON);

            glVertex2f(0.612+xe5,0.670);
            glVertex2f(0.612+xe5,0.655);
            glVertex2f(0.630+xe5,0.655);
            glVertex2f(0.630+xe5,0.670);
        glEnd();

          glPopMatrix();

       if(bossbulletposition<-2.78)
    {
        bossbulletposition=0.0f;
        createboss();
    }


   }

void createenemybullet2()
{
    glColor3ub(0,0,0);
    //bullet

glPushMatrix();
glTranslatef(enemybulletposition2,0.0,0.0);

glBegin(GL_POLYGON);

            glVertex2f(-0.780+xe2,-0.862+1);
            glVertex2f(-0.780+xe2,-0.850+1);
            glVertex2f(-0.755+xe2,-0.850+1);
            glVertex2f(-0.755+xe2,-0.862+1);
        glEnd();

          glPopMatrix();

       if(enemybulletposition2>2.78)
    {
        enemybulletposition2=0.0f;
        createenemybullet2();
    }
    if(red2==false)
    {
        green2=false;
        enemybulletposition2=0.0f;
    }

   }

void createenemybullet()
{
    glColor3ub(0,0,0);
    //bullet

glPushMatrix();
glTranslatef(enemybulletposition,0.0,0.0);
glBegin(GL_POLYGON);

            glVertex2f(-0.780,-0.862);
            glVertex2f(-0.780,-0.850);
            glVertex2f(-0.755,-0.850);
            glVertex2f(-0.755,-0.862);
        glEnd();

          glPopMatrix();

       if(enemybulletposition>2.78)
    {
        enemybulletposition=0.0f;
        createenemybullet();
    }
    if(red==false)
    {
        green=false;
        orange==true;
        enemybulletposition=0.0f;
    }

   //}
}
createback()
{
    glColor3ub(167,220,245);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,-1.0);
    glEnd();

    glColor3ub(147,146,141);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8,-1);
    glVertex2f(-0.8,0.45);
    glVertex2f(-0.5,0.15);
    glVertex2f(-0.5,-1);
    glEnd();

    glColor3ub(147,146,141);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3,-1);
    glVertex2f(-0.3,0.2);
    glVertex2f(-0.1,0.6);
    glVertex2f(0.1,0.2);
    glVertex2f(0.1,-1);
    glEnd();

    glColor3ub(147,146,141);
    glBegin(GL_POLYGON);
    glVertex2f(0.3,-1);
    glVertex2f(0.3,0.6);
    glVertex2f(0.4,0.8);
    glVertex2f(0.5,0.6);
    glVertex2f(0.5,-1);
    glEnd();

    glColor3ub(147,146,141);
    glBegin(GL_POLYGON);
    glVertex2f(0.6,-1);
    glVertex2f(0.6,0.1);
    glVertex2f(0.9,0.4);
    glVertex2f(0.9,-1);
    glEnd();
}


void createbullet()
{
    glColor3ub(0,0,0);
    //bullet
glPushMatrix();
glTranslatef(bulletpos,jumpposition,0.0);
  glBegin(GL_POLYGON);


            glVertex2f(0.874+rt8+xx,-0.834+yy);
            glVertex2f(0.874+rt8+xx,-0.846+yy);
            glVertex2f(0.860+rt9+xx,-0.846+yy);
            glVertex2f(0.860+rt9+xx,-0.834+yy);
        glEnd();

          glPopMatrix();

          if(bulletpos+xx<-1.86 || bulletpos+xx>0.035)
   {
       bulletpos=0.0f;
        bulletspeed=0.0f;
        createbullet();


   }
}
void createladder()
{
     glColor3ub(77,74,74);

     for(int i=1;i<=3;i++)
     {
         if(i==2)
         {
             laddpax=1.70f;
             laddpay=0.50f;
             glTranslatef(laddpax,laddpay,0.0f);
         }
         if(i==3)
         {
             laddpax=-1.70f;
             glTranslatef(laddpax,laddpay,0.0f);

         }

            glPushMatrix();






//left stick
         glBegin(GL_POLYGON);


            glVertex2f(-0.92,-1.00);
            glVertex2f(-0.92,-1.00);
            glVertex2f(-0.92,-0.50);
            glVertex2f(-0.91,-0.50);
            glVertex2f(-0.91,-1.00);
        glEnd();
//right stick
 glBegin(GL_POLYGON);


            glVertex2f(-0.81,-1.00);
            glVertex2f(-0.81,-0.50);
            glVertex2f(-0.80,-0.50);
            glVertex2f(-0.80,-1.00);
        glEnd();
//inner stick
for(float b=0.0;b<=0.40;b=b+0.10)
{
    glBegin(GL_POLYGON);


            glVertex2f(-0.93,-0.90+b);
            glVertex2f(-0.90,-0.90+b);
            glVertex2f(-0.79,-0.88+b);
            glVertex2f(-0.82,-0.88+b);
        glEnd();

}

            glPopMatrix();

     }









}






void drawScene()
{


    glClearColor(102.0f, 255.0f, 255.0f,1.0f);

    glClear(GL_COLOR_BUFFER_BIT );
    glLoadIdentity();
    createback();
    glMatrixMode(GL_MODELVIEW);

    displaylife();
    if(yellow==true)
    {
        createbullet();

    }



   if(green==true)
   {
       createenemybullet();

   }
   if(green2==true && yy>0.80)
   {

    createenemybullet2();



   }
   if(green3==true &&yy>0.48)
   {
       createenemybullet3();

   }






   createfloor();
   createladder();


   if(red==true)
   {
       createenemy();

   }



if(blue==true)
{
     createplayer();

}

if(red2==true)
   {
       createenemy2();
   }

if(red3==true)
{
    createenemy3();
}
if(red5==true)
createboss();
if(red5==false)
{
    gamewindisplay();
    bossbulletposition=3.80;

}


if(red4==true)
{
    createenemy4();
}

  if(green4==true && yy>1.48 )
   {
       createenemybullet4();

   }
   if(red4==false && green5==true)
   createbossbullet();
   if(blue==false)
{
    gameoverscreen();
}













  glutSwapBuffers();








}





int main(int argc, char** argv) {


	glutInit(&argc, argv);
	glEnable(GL_DEPTH_TEST);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(850, 650);
	glutCreateWindow("Transformation");
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(keyboardKeys);

	glutTimerFunc(2, bulletupdate, 0);
	glutTimerFunc(18,jumpupdate,0);
	glutTimerFunc(40,enemyupdate,0);
	glutTimerFunc(40,enemyupdate2,0);
	glutTimerFunc(40,enemyupdate3,0);
	glutTimerFunc(40,enemyupdate4,0);
	glutTimerFunc(30,bossupdate,0);

         glutTimerFunc(12,enemybulletupdate,0);
        glutTimerFunc(12,enemybulletupdate2,0);

            glutTimerFunc(12,enemybulletupdate3,0);
            glutTimerFunc(12,enemybulletupdate4,0);

            glutTimerFunc(10,bossbulletupdate,0);



	glutMainLoop();
	return 0;
}
