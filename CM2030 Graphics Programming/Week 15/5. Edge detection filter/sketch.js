let imgIn;
// vertical edges
let matrixVer =[
  [-1, -2, -1],
  [ 0,  0,  0],
  [ 1,  2,  1]
];

// horizontal edges
let matrixHor =[
  [ 1,  0, -1],
  [ 2,  0, -2],
  [ 1,  0, -1]
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
  imgIn.filter('GRAY');
  image(imgIn, 0, 0);
  image(edgeFilter(imgIn), imgIn.width + 20, 0);
  noLoop();
}

function edgeFilter(img) {
  let imgOut = createImage(img.width, img.height);
  imgOut.loadPixels();
  img.loadPixels();

  let matrixSizeVer = matrixVer.length;
  let matrixSizeHor = matrixHor.length;

  for (let y = 0; y < img.height; y++) {
    for (let x = 0; x < img.width; x++) {

      let index = (img.width * y + x) * 4;
      let cX = convolution(x, y, matrixVer, matrixSizeVer, img);
      // max will be (1+2+1)*255 = 1020
      cX = map(abs(cX[0]), 0, 1020, 0, 255);

      let cY = convolution(x, y, matrixHor, matrixSizeHor, img);
      // max will be (1+2+1)*255 = 1020
      cY = map(abs(cY[0]), 0, 1020, 0, 255);

      let combo = cX + cY;

      imgOut.pixels[index + 0] = combo;
      imgOut.pixels[index + 1] = combo;
      imgOut.pixels[index + 2] = combo;
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