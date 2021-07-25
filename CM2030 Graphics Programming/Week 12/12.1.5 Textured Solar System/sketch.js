let sun;
let earth;
let moon;
let myStars;
let starsBack;

function preload() {
  sun = loadImage('/assets/sun.jpg');
  earth = loadImage('/assets/earth.jpg');
  moon = loadImage('/assets/moon.jpg');
}

function setup() {
  createCanvas(900, 600, WEBGL);
  angleMode(DEGREES);
  myStars = new stars();
  noStroke();
  
}

function draw() {
  background(0);
  myStars.show(starsBack);

  push();
  texture(sun);
  rotateY(frameCount / 3);
  sphere(100, 30, 30);
  pop();

  pointLight(255, 255, 255, 0, 0, 0);
  pointLight(255, 255, 255, 0, 0, 0);

  push();
  texture(earth);
  translate(cos(frameCount/2) * 300, 0, sin(frameCount/2) * 300);
  rotateY(frameCount / 2);
  sphere(50, 30, 30);
  pop();


  push();
  translate(cos(frameCount/2) * 300, 0, sin(frameCount/2) * 300);
  translate(cos(frameCount * 2) * 100, 0, sin(frameCount * 2) * 100);
  rotateY(frameCount);
  texture(moon);
  sphere(20, 30, 30);
  pop();


  camera(0, -250, 800);
  //noLoop();
}

function stars() {
  background(0);
  starArray = [];
  let maxLife = 500;
  let starNum = 100;
  for(let i=0; i<starNum; ++i)
  {
    let ranX = random(-width, width);
    let ranY = random(-height, height);
    starArray.push({x: ranX, y: ranY, life:random(Math.floor(maxLife*0.25), maxLife)});
  }
  this.show = function()
  {
    for(let i=0; i<starArray.length; ++i)
    {
      fill(255);
      ellipse(starArray[i].x, starArray[i].y, 3, 3);
      starArray[i].life += 1;
      if(starArray[i].life >= maxLife)
      {
        starArray[i].x = random(-width, width);
        starArray[i].y = random(-height, height);
        starArray[i].life = 0;
      }
    }
  }
}
