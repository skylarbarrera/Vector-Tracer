//Vector Tracer by Skylar Barrera
//CS 312 Assignment #5
//Date: 3/24/2017
//Program initializes and envirnmont and then casts rays
// to see if objects are hit  then prints them into a 2d image

#include "rt.h"
#include "light.h"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void read_objs(OBJ_T** list){
//reading obj
double ctx;
double cty;
double ctz;
double rad;
double colR;
double colG;
double colB;
//loops through inputs
while (scanf("%lf %lf %lf %lf %lf %lf %lf", &ctx , &cty,&ctz,&rad,&colR,&colG,&colB) ==7){
  OBJ_T *node = (OBJ_T*)malloc(sizeof(OBJ_T));
  node -> sphere.center.x = ctx;
  node -> sphere.center.y = cty;
  node -> sphere.center.z = ctz;
  node -> sphere.radius = rad;
  node -> color.R = colR;
  node -> color.G = colG;
  node -> color.B = colB;

//Links node to list
  node -> next = *list;
    *list = node;


}

}

COLOR_T trace(RAY_T ray, OBJ_T *list, LIGHT_T light){
 //printf("new ray\n\n");

 double tmin = 9999;
 double t = 0;
 OBJ_T *curr;
 COLOR_T Color = {0,0,0};
 for(curr = list; curr != NULL; curr = curr->next){


   VEC_T int_pt ={};
   VEC_T normal  ={};
   if (intersect_sphere(ray, curr->sphere, &t,&int_pt,&normal) == 1){
    //checks which circle is closer and then sets color
     if (t < tmin){
       tmin = t;

       Color = illuminate(ray,light,list,curr->color,int_pt,normal);



   }
  }
}
COLOR_T Final = {Color.R*255,Color.G*255,Color.B*255};

 return Final;
}



int main() {
  OBJ_T *list = NULL;
  read_objs(&list);
  printf("P6\n 1000 1000 255\n");

  LIGHT_T light = {{5,10,0}};

  VEC_T testo = {0,0,0};
  testo = normalize(testo);
  for (double y = 0; y < 1000; y++){
    for (double x = 0; x < 1000 ; x++){

      //inialize
      double x3d = -0.5 + (x/1000);
      double y3d = 0.5 - (y/1000);
      VEC_T testd = {x3d,y3d,1};
      RAY_T testies = {testo,normalize(testd)};
      COLOR_T color = trace(testies,list,light);

      //printing pixels
      printf("%c%c%c",(unsigned char)color.R , (unsigned char)color.G, (unsigned char)color.B);





    }
  }

  //for (int i = 0; i < 1000 * 1000; i++) {
    //printf("%c%c%c", 255, 255, 0);

//}
//freeing list
OBJ_T *curr;
OBJ_T *tmp;
for(curr = list; curr != NULL;){
  tmp = curr->next;
  free(curr);
  curr = tmp;
}
free(curr);
free(tmp);
return 0;
}
