#pragma once

#include "eadkpp.h"
#include "types.h"

extern const float PI;
extern const float FOV_DEGREES;
extern const float FOV;

extern float camPosX;
extern float camPosY;
extern float camPosZ;

extern float rotX;
extern float rotY;

void drawPoint(const Point2D& p);
void drawLine(const Point2D& p0, const Point2D& p1);
void drawTriangle(const Triangle& triangle, EADK::Color color);
void drawObject(const Entity& obj);