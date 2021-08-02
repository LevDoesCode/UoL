let imgIn;
let imgOut;
let clicked = false;

function preload() {
  imgIn = loadImage("assets/seaNettles.jpg");
}

function setup() {
  createCanvas(imgIn.width * 2, imgIn.height);
  pixelDensity(1);
}

function draw() {
  background(255, 0, 255);
  image(imgIn, 0, 0);
  image(grayScaleFilter(imgIn), imgIn.width, 0);
  //noLoop();
}

function grayScaleFilter(img) {
  imgOut = createImage(img.width, img.height);
  imgOut.loadPixels();
  img.loadPixels();

  for (let y = 0; y < img.height; y++) {
    for (let x = 0; x < img.width; x++) {
      let index = (img.width * y + x) * 4;
      let r = img.pixels[index + 0];
      let g = img.pixels[index + 1];
      let b = img.pixels[index + 2];
      let gray;
      if (clicked == true)
        gray = r * 0.299 + g * 0.587 + b * 0.114;
      else
        gray = (r + g + b) / 3;
      
      let threshold = constrain(map(mouseX, 0, width, 0, 255), 0, 255);
      
      if(gray>threshold)
        gray = 255;
      else
        gray = 0;

      imgOut.pixels[index + 0] = gray;
      imgOut.pixels[index + 1] = gray;
      imgOut.pixels[index + 2] = gray;
      imgOut.pixels[index + 3] = 255;
    }
  }
  imgOut.updatePixels();
  return imgOut;
}

function mouseClicked() {
  clicked = !clicked;
}
