
#include "vec.h"
#include<math.h>
#include<stdio.h>

#ifndef VEC_C
#define VEC_C




VEC_T normalize(VEC_T v){
  double len = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
  //printf("len = %f", len);
  v.x /=  len;
  v.y /=  len;
  v.z /=  len;
  //printf(" norm'd x  %f, y  %f,z  %f\n",v.x,v.y,v.z);
  return v;
}

double dot(VEC_T v1, VEC_T v2){

return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;

}
#endif


/*int main() {
  VEC_T v = {12,32,3};
  VEC_T w = {1,50,7};
  //double d = dot(v,w);
  v = normalize(w);
  //w = normalize(w);
  //d = dot(v,w);
  //printf("dot prod = %f", d);

  return 0;
}
*/
