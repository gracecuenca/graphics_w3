#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);

  color c;
  c.red = 255;
  c.green = 255;
  c.blue = 255;

  printf("===== matrix * edges created =====\n");
  printf("===== matrix * mult created =====\n");
  struct matrix *edges;
  struct matrix *mult;
  struct matrix *other;
  edges = new_matrix(4, 4);
  mult = new_matrix(4,1);
  other = new_matrix(4,4);

  printf("===== adding points to matrix * other =====\n");
  add_point(other, 0.0,0.0,0.0);
  add_point(other, 50.0,0.0,0.0);
  add_point(other, 50.0,50.0,0.0);
  add_point(other, 0.0,50.0,0.0);

  printf("===== printing matrix * other =====\n");
  print_matrix(other);

  printf("===== turning matrix * other to identity matrix =====\n");
  ident(other);

  printf("===== printing matrix * other =====\n");
  print_matrix(other);

  printf("===== adding point to matrix * mult =====\n");
  add_point(mult, 1.0, 3.0, 0.0);

  printf("===== adding edges to matrix * edges =====\n");

  add_edge(edges, 50.0,50.0,0.0,100.0,50.0,0.0);
  add_edge(edges, 100.0,50.0,0.0,100.0,100.0,0.0);
  add_edge(edges,100.0,100.0,0.0,50.0,100.0,0.0);
  add_edge(edges,50.0, 100.0, 0.0,50.0, 50.0, 0.0);

  printf("===== printing matrix * edges =====\n");
  print_matrix(edges);

  printf("===== testing matrix multiplication: edges * mult =====\n");
  matrix_mult(mult, edges);

  printf("===== printing matrix * edges =====\n");
  print_matrix(edges);

  printf("===== generating image matrix * edges =====\n");
  draw_lines(edges, s, c);
  display(s);

  free_matrix(edges);
  free_matrix(mult);
  free_matrix(other);
}
