# Tiny 3D Engine

This is a C++ app to use on a [NumWorks calculator](https://www.numworks.com).

```cpp

// triangles coordinates
Triangle planeTriangles[] = {
    {{0,0,0}, {1,0,0}, {0,1,0}},
    {{1,1,0}, {1,0,0}, {0,1,0}}
};

// new mesh : triangles, triangles count
Mesh placeMesh = { planeTriangles, 2};

// new entity : position, rotation, scale, and pivot point
Entity plane = {
  &placeMesh,
  { { 0,0,0 }, { 0,0,0 }, { 1,1,1 } },
  { 0.0f, 0.0f, 0.0f }
};

int main() {
  while(true) {
    drawObject(plane);
  }
  
  return 0;
}
```

## Keyboard

- Forward : Toolbox
- Backward : comma
- Camera movements : directionnal arrows
- Go left : OK key
- Go right : back
- Go up : backspace
- Go down : power

## Build the app

To build this sample app, you will need to install the [embedded ARM toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) and [Node.js](https://nodejs.org/en/). The C SDK for Epsilon apps is shipped as an npm module called [nwlink](https://www.npmjs.com/package/nwlink) that will automatically be installed at compile time.

```shell
brew install numworks/tap/arm-none-eabi-gcc node # Or equivalent on your OS
make
```

You should now have a `target/render.nwa` file that you can distribute! Anyone can now install it on their calculator from the [NumWorks online uploader](https://my.numworks.com/apps).

## Run the app locally

To run the app on your development machine, you can use the following command

```shell
# Now connect your NumWorks calculator to your computer using the USB cable
make run
```
