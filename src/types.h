#pragma once

#define MAX_TRIANGLES 128

struct Point2D {
  float x;
  float y;
};

struct Point3D {
  float x;
  float y;
  float z;
};

struct Triangle {
  Point3D v1;
  Point3D v2;
  Point3D v3;
};

struct Transform {
  Point3D pos;
  Point3D rot;
  Point3D scale;
};

struct Mesh {
  Triangle* triangles;
  int count;
};

struct Entity {
  Mesh* mesh;
  Transform transform;
  Point3D center;
};