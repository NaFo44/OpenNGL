#pragma once

#include "types.h"

extern int WIDTH;
extern int HEIGHT;

Point3D rotateX(const Point3D& p, float rotX);
Point3D rotateY(const Point3D& p, float rotY);
Point2D project(const Point3D& p, float focal);
Point2D toScreen(const Point2D& p);
Mesh rotateObjY(const Mesh& obj, const Point3D& ref, float angle);
Point3D scalePoint(const Point3D& p, const Point3D& s);
Point3D add(const Point3D& a, const Point3D& b);
Point3D sub(const Point3D& a, const Point3D& b);