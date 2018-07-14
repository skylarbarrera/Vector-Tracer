

#ifndef SPHERE_C
#define SPHERE_C
#include<math.h>
#include"sphere.h"


int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t,VEC_T *int_pt, VEC_T *normal){

//sets up for quadratic
double  b =  (2*(ray.direction.x * ( - sphere.center.x))) + (2*(ray.direction.y * (- sphere.center.y)))  + (2*(ray.direction.z * (- sphere.center.z)));
double c = ((- sphere.center.x)*(- sphere.center.x)) + ((- sphere.center.y)*(- sphere.center.y)) + ((- sphere.center.z)*(- sphere.center.z)) - ((sphere.radius)*(sphere.radius));
double d = b*b - 4*c;

///checks discriment
if (d < 0){

  return 0;
} else {
  d = sqrt(d);

}



//outputs
double tt = (-b + d)/(2);
double t1 = (-b - d)/(2);
if (tt<0 && t1 <0){
  return 0;
}
//printf("tt %f , t1  %f\n", tt, t1);
if (tt<t1){
  //printf("no fucking way");
}
if (tt > t1){
    if(tt < 0){
      return 0;
    }else {
      if (t1 > 0){
      //printf("t1 = %f\n",t1);
      *t= t1;

      int_pt -> x = ray.direction.x *(*t);
      int_pt -> y = ray.direction.y *(*t);
      int_pt -> z = ray.direction.z *(*t);

      normal -> x = (int_pt -> x - sphere.center.x)/sphere.radius;
      normal -> y =(int_pt->y - sphere.center.y)/sphere.radius;
      normal -> z = (int_pt->z - sphere.center.z)/sphere.radius;
      return 1;
    }
  }
}
 else {
  *t = tt;

  int_pt -> x = ray.direction.x *(*t);
  int_pt -> y = ray.direction.y *(*t);
  int_pt -> z = ray.direction.z *(*t);
  normal -> x = (int_pt->x - sphere.center.x)/sphere.radius;
  normal -> y =(int_pt->y - sphere.center.y)/sphere.radius;
  normal -> z = (int_pt->z - sphere.center.z)/sphere.radius;

  return 1;
}
//printf("none found returning 0\n");
return 0;
}





#endif
