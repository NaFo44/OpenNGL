#include <cmath>
#include "eadkpp.h"
#include "palette.h"
#include "math3d.h"

const float PI = 3.14159265358979323846f;
const float FOV_DEGREES = 90.0f;
const float FOV = FOV_DEGREES * PI / 180.0f;

float camPosX = 0.0f;
float camPosY = 0.0f;
float camPosZ = -3.0f;

float rotX = 0.0f;
float rotY = 0.0f;

void drawPoint(const Point2D& p) {
  int px = (int)p.x;
  int py = (int)p.y;

  if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT) return;
  EADK::Display::pushRectUniform(EADK::Rect(px, py, 1, 1), White);
}

void drawLine(const Point2D& p0, const Point2D& p1) {
  float dx = p1.x - p0.x;
  float dy = p1.y - p0.y;

  float steps = fabsf(dx) > fabsf(dy) ? fabsf(dx) : fabsf(dy);
  if (steps < 1.0f) steps = 1.0f;

  float xInc = dx / steps;
  float yInc = dy / steps;

  float x = p0.x;
  float y = p0.y;

  for (int i = 0; i <= (int)steps; i++) {
    Point2D p = { x, y };
    drawPoint(p);
    x += xInc;
    y += yInc;
  }
}

void drawTriangle(const Triangle& triangle, EADK::Color color) {
  float focal = 1.0f / tanf(FOV * 0.5f);

  Point3D vertices[3] = { triangle.v1, triangle.v2, triangle.v3 };
  Point2D screenCoords[3];
  const float nearPlane = 0.01f;

  for (uint8_t i = 0; i < 3; i++) {
    Point3D worldPos = {
      vertices[i].x - camPosX,
      vertices[i].y - camPosY,
      vertices[i].z - camPosZ
    };
    
    Point3D rotated = rotateX(rotateY(worldPos, rotY), rotX);

    // todo : implement true clipping algorithm
    if (rotated.z <= nearPlane) return;

    Point2D projected = project(rotated, focal);
    screenCoords[i] = toScreen(projected);
  }
  
  drawLine(screenCoords[0], screenCoords[1]);
  drawLine(screenCoords[1], screenCoords[2]);
  drawLine(screenCoords[2], screenCoords[0]);
}

void drawObject(const Entity& obj) {
  for (int i = 0; i < obj.mesh->count; i++) {
    Triangle t = obj.mesh->triangles[i];
    
    Point3D verts[3] = { t.v1, t.v2, t.v3 };

    for (int v = 0; v < 3; v++) {

      // move origin
      verts[v] = sub(verts[v], obj.center);

      // scale
      verts[v] = scalePoint(verts[v], obj.transform.scale);

      // rotate
      verts[v] = rotateX(verts[v], obj.transform.rot.x);
      verts[v] = rotateY(verts[v], obj.transform.rot.y);

      // adjust origin
      verts[v] = add(verts[v], obj.center);

      // translate world
      verts[v] = add(verts[v], obj.transform.pos);
    }

    Triangle transformed = { verts[0], verts[1], verts[2] };

    drawTriangle(transformed, White);
  }
}
