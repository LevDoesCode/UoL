let imgIn;
let imgOut;

function preload()
{
    imgIn = loadImage("assets/seaNettles.jpg");
}

function setup() {
    createCanvas(imgIn.width * 2, imgIn.height);
    pixelDensity(1);
}

function draw()
{
    background(255, 0, 255);
    image(imgIn, 0, 0);
    image(invertFilter(imgIn), imgIn.width, 0);
    noLoop();
}

function invertFilter(img) {
    
    imgOut = createImage(img.width, img.height);
    imgOut.loadPixels();
    img.loadPixels();

    for(let y=0; y<img.height; y++)
    {
        for(let x=0; x<img.width; x++)
        {
            let index = (img.width * y + x) * 4;
            imgOut.pixels[index + 0] = 255 - img.pixels[index + 0]
            imgOut.pixels[index + 1] = 255 - img.pixels[index + 1]
            imgOut.pixels[index + 2] = 255 - img.pixels[index + 2]
            imgOut.pixels[index + 3] = 255;
        }
    }
    imgOut.updatePixels();
    return imgOut;
}