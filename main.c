#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges, *edges2;

  color c;

  c.red = MAX_COLOR;
  c.green = 50;
  c.blue = 100;
  
  edges = new_matrix(4, 4);
  edges2 = new_matrix(4,2);
  
  printf("First matrix: 4X4\n");
  print_matrix(edges);

  printf("Second matrix: 4x2\n");
  print_matrix(edges2);


  printf("Add_edge (1,5,8) (3,2,5)\n");
  add_edge(edges,1,5,8,3,2,5);
  print_matrix(edges);

  printf("Add_edge second (2,4,6) (1,2,3) \n");
  add_edge(edges2,2,4,6,1,2,3);
  print_matrix(edges2);
  
  printf("Ident\n");
  ident(edges);
  print_matrix(edges);

  printf("Matrix mult. First and Second \n");
  matrix_mult(edges2,edges);
  print_matrix(edges2);
  
  free_matrix(edges);
  free_matrix(edges2);

  clear_screen(s);

  edges = new_matrix(4,4);

  add_edge(edges,100,100,0,100,400,0);
 add_edge(edges,100,400,0,400,400,0);
  add_edge(edges,400,400,0,400,100,0);
 add_edge(edges,400,100,0,100,100,0);
 add_edge(edges,120,350,0,200,350,0);
 add_edge(edges,300,350,0,380,350,0);
  add_edge(edges,180,150,0,320,150,0);
  
  draw_lines(edges,s,c);

  display(s);
  save_extension(s,"image.png");
  free_matrix(edges);
}  
