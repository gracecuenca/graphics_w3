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

  printf("===== testing matrix * edges creation =====\n");
  struct matrix *edges;
  struct matrix *mult;

  edges = new_matrix(4, 4);
  mult = new_matrix(4,4);

  add_edge(edges, 50.0,50.0,0.0,100.0,50.0,0.0);
  add_edge(edges, 100.0,50.0,0.0,100.0,100.0,0.0);
  add_edge(edges,100.0,100.0,0.0,50.0,100.0,0.0);
  add_edge(edges,50.0, 100.0, 0.0,50.0, 50.0, 0.0);

  printf("===== testing matrix * edges printing =====\n");
  print_matrix(edges);

  draw_lines(edges, s, c);
  display(s);

  printf("===== testing matrix multiplication: edges * =====\n");

  printf("===== testing identity matrix =====\n");


  free_matrix(edges);
}
