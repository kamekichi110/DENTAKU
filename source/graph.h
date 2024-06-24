#ifndef GRAPH_H
#define GRAPH_H

#include <3ds.h>
#include <citro2d.h>

extern C3D_RenderTarget* top;
extern C3D_RenderTarget* bottom;

void draw_graph(const char* function);

#endif // GRAPH_H
