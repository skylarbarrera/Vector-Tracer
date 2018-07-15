
#ifndef OBJ_H
#define OBJ_H
#include"rt.h"
#include"sphere.h"

typedef struct{
  SPHERE_T sphere;
  COLOR_T color;
  void *next;
}OBJ_T;

#endif
