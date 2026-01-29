#include <cmath>
#include "eadkpp.h"
#include "palette.h"
#include "utils.h"
#include "math3d.h"
#include "assets.h"

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "App";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main(int argc, char * argv[]) {
  Entity heart = {
    &heartMesh,
    { { -3, 0, 3 }, { 0,0,0 }, { 1,1,1 } },
    { 0.0f, 0.14f, 0.5f }
  };

  Entity cube2 = {
    &cubeMesh,
    { {  0, 0, 6 }, { 0,0,0 }, { 1,1,1 } },
    { 0.5f, 0.5f, 0.5f }
  };

  Entity cube3 = {
    &cubeMesh,
    { {  0, 0, 6 }, { 0,0,0 }, { 1,1,1 } },
    { 0.5f, 0.5f, 0.5f }
  };

  Entity cube4 = {
    &cubeMesh,
    { {  0, 0, 6 }, { 0,0,0 }, { 1,1,1 } },
    { 0.5f, 0.5f, 0.5f }
  };
  
  float t = 0.0f;

  while (true) {
    t += 0.03f;

    heart.transform.rot.y += 0.03f;
    cube2.transform.pos.x = sinf(t) * 4.0f;
    cube3.transform.pos.y = sinf(t) * 4.0f;
    cube4.transform.pos.z = sinf(t) * 4.0f + 6.0f;

    EADK::Display::pushRectUniform(EADK::Screen::Rect, Black);

    float cosResult = (float)cos(rotY) * 0.1;
    float sinResult = (float)sin(rotY) * 0.1;

    EADK::Keyboard::State currentState = EADK::Keyboard::scan();

    if (currentState.keyDown(EADK::Keyboard::Key::Toolbox)) {
      camPosZ += cosResult;
      camPosX -= sinResult;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Comma)) {
      camPosZ -= cosResult;
      camPosX += sinResult;
    } else if (currentState.keyDown(EADK::Keyboard::Key::OK)) {
      camPosZ -= sinResult;
      camPosX -= cosResult;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Back)) {
      camPosZ += sinResult;
      camPosX += cosResult;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Backspace)) {
      camPosY += 0.1f;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Power)) {
      camPosY -= 0.1f;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Left)) {
      rotY += 0.1f;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Right)) {
      rotY -= 0.1f;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Up)) {
      rotX += 0.1f;
    } else if (currentState.keyDown(EADK::Keyboard::Key::Down)) {
      rotX -= 0.1f;
    }

    drawObject(heart);
    drawObject(cube2);
    drawObject(cube3);
    drawObject(cube4);

    eadk_display_wait_for_vblank();
  }

  return 0;
}