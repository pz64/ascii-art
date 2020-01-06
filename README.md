# ascii-art-generator

ASCIIArt Generator class generate ascii-art for imput image.

[written in c++, microsoft visualstudio 2019 Comunity Edition.]

ascii-art example :


```cpp
#include "image.h"
#include "fontrender.h"
#include "pixelbrightness.h"
#include "asciiart.h"

int main()
{
    /*
    uses default font:
    "./fonts/Roboto-Regular.ttf
    */
    FontRender robotoDefault;

    Image plant("../out/photo_1.jpg");
    plant.resizeWrtWidth(80);

    ASCIIArt art(&plant,&robotoDefault);
    art.generateArt();
}
```
## input
<img src="./out/photo_1.jpg" />

## output
with image width 80
<img src="./out/screenshot_1.jpg" />

## output
with image width 300
<img src="./out/screenshot_2.jpg" />
