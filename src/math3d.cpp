#include <cmath>
#include "math3d.h"

int WIDTH = 320;
int HEIGHT = 240;

Point2D toScreen(const Point2D& p) {
  return {
    WIDTH  / 2.0f + p.x * (WIDTH  / 2.0f),
    HEIGHT / 2.0f - p.y * (HEIGHT / 2.0f)
  };
}

Point2D project(const Point3D& p, float focal) {
  return {
    (p.x * focal) / p.z,
    (p.y * focal) / p.z
  };
}

Point3D rotateX(const Point3D& p, float rotX) {
  float cosv = cosf(rotX);
  float sinv = sinf(rotX);

  return {
    p.x,
    p.y * cosv - p.z * sinv,
    p.y * sinv + p.z * cosv
  };
}

Point3D rotateY(const Point3D& p, float rotY) {
  float cosv = cosf(rotY);
  float sinv = sinf(rotY);

  return {
    p.x * cosv + p.z * sinv,
    p.y,
    -p.x * sinv + p.z * cosv
  };
}

Point3D scalePoint(const Point3D& p, const Point3D& s) {
  return {
    p.x * s.x,
    p.y * s.y,
    p.z * s.z
  };
}

Point3D sub(const Point3D& a, const Point3D& b) {
  return {
    a.x - b.x,
    a.y - b.y,
    a.z - b.z
  };
}

Point3D add(const Point3D& a, const Point3D& b) {
  return {
    a.x + b.x,
    a.y + b.y,
    a.z + b.z
  };
}

Point3D rotateAroundY(const Point3D& point, const Point3D& ref, float angle) {
  Point3D v = sub(point, ref);
  v = rotateY(v, angle);

  return add(v, ref);
}

Mesh rotateObjY(const Mesh& obj, const Point3D& ref, float angle) {
  Mesh transformed = obj;

  for (int i = 0; i < obj.count; i++) {
    transformed.triangles[i].v1 = rotateAroundY(obj.triangles[i].v1, ref, angle);
    transformed.triangles[i].v2 = rotateAroundY(obj.triangles[i].v2, ref, angle);
    transformed.triangles[i].v3 = rotateAroundY(obj.triangles[i].v3, ref, angle);
  }

  return transformed;
}