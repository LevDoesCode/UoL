let imgIn;
let matrix =[
  [1/9, 1/9, 1/9],
  [1/9, 1/9, 1/9],
  [1/9, 1/9, 1/9]
];

function preload() {
  imgIn = loadImage("assets/seaNettles.jpg");
}

function setup() {
  createCanvas(imgIn.width * 2 + 20, imgIn.height);
  pixelDensity(1);
}

function draw() {
  background(255);
  image(imgIn, 0, 0);
  image(blurFilter(imgIn), imgIn.width + 20, 0);
  noLoop();
}

function blurFilter(img) {
  let imgOut = createImage(img.width, img.height);
  imgOut.loadPixels();
  img.loadPixels();

  let matrixSize = matrix.length;

  for (let y = 0; y < img.height; y++) {
    for (let x = 0; x < img.width; x++) {

      let index = (img.width * y + x) * 4;

      let c = convolution(x, y, matrix, matrixSize, imgIn)

      imgOut.pixels[index + 0] = c[0];
      imgOut.pixels[index + 1] = c[1];
      imgOut.pixels[index + 2] = c[2];
      imgOut.pixels[index + 3] = 255;
    }
  }
  imgOut.updatePixels();
  return imgOut;
}

function convolution(x, y, matrix, matrixSize, img)
{
  let totalRed = 0;
  let totalGrn = 0;
  let totalBlu = 0;

  let offset = floor(matrixSize/2);

  for (let i=0; i<matrixSize; i++)
  {
    for(let j=0; j<matrixSize; j++)
    {
      let xloc = x + i - offset;
      let yloc = y + j - offset;

      let index = (img.width * yloc + xloc) * 4;
      index = constrain(index, 0, img.pixels.length - 1);
      totalRed += img.pixels[index + 0] * matrix[i][j];
      totalGrn += img.pixels[index + 1] * matrix[i][j];
      totalBlu += img.pixels[index + 2] * matrix[i][j];
    }
  }
  return [totalRed, totalGrn, totalBlu];
}