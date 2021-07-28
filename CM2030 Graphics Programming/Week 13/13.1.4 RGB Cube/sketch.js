let sun;
let earth;
let moon;
let myStars;
let starsBack;


function setup() {
  createCanvas(800, 800, WEBGL);
  angleMode(DEGREES);  
}

function draw() {
  background(150);
  ambientLight(255);
  ambientMaterial(100, 150, 200);
  
  let max = 10;
  noStroke();
  rotateY(frameCount);
  rotateZ(frameCount);
  translate(-30*max/2, -30*max/2, -30*max/2);
  for(let x=0; x<max; x++)
  {
    for(let y=0; y<max; y++)
    {
      for(let z=0; z<max; z++)
      {
        push();
        ambientMaterial(map(x, 0, max, 0, 255), map(y, 0, max, 0, 255), map(z, 0, max, 0, 255));
        translate(x * 30, y * 30, z * 30);
        box(30, 30, 30);
        pop();
      }
    }
  }
}