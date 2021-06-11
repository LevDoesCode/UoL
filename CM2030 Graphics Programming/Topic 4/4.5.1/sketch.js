// Example is based on examples from: http://brm.io/matter-js/, https://github.com/shiffman/p5-matter
// add also Benedict Gross credit

let Engine = Matter.Engine;
let Render = Matter.Render;
let World = Matter.World;
let Bodies = Matter.Bodies;
let Body = Matter.Body;
let Constraint = Matter.Constraint;
let Mouse = Matter.Mouse;
let MouseConstraint = Matter.MouseConstraint;
let Composites = Matter.Composites;
let Composite = Matter.Composite;

let engine;
let propeller;
let boxes = [];
let birds = [];
let colors = [];
let ground;
let slingshotBirds = [];
let slingshotConstraint;
let angle=0;
let angleSpeed=0.01;
let canvas;

let pinkSprite = [];
let pinkFrame = [];
let greenSprite = [];
let greenFrame = [];
let redSprite = [];
let redFrame = [];
////////////////////////////////////////////////////////////
function preload()
{
  // Bird art by bevouliin.com
  // https://opengameart.org/content/fat-bird-sprite-sheets-for-gamedev
  // https://opengameart.org/content/pink-flappy-bird-sprite-sheets
  https://opengameart.org/content/bevouliin-free-red-flappy-bee-bird-game-character-sprite-sheets-for-game-developers
  pinkSprite.push(loadImage('/pink/frame-1.png'));
  pinkSprite.push(loadImage('/pink/frame-2.png'));
  pinkSprite.push(loadImage('/pink/frame-3.png'));
  pinkSprite.push(loadImage('/pink/frame-4.png'));
  greenSprite.push(loadImage('/green/frame-1.png'));
  greenSprite.push(loadImage('/green/frame-2.png'));
  greenSprite.push(loadImage('/green/frame-3.png'));
  greenSprite.push(loadImage('/green/frame-4.png'));
  redSprite.push(loadImage('/red/frame-1.png'));
  redSprite.push(loadImage('/red/frame-2.png'));
  redSprite.push(loadImage('/red/frame-3.png'));
  redSprite.push(loadImage('/red/frame-4.png'));
}
////////////////////////////////////////////////////////////
function setup() {
  canvas = createCanvas(1000, 600);

  engine = Engine.create();  // create an engine

  setupGround();

  setupPropeller();

  setupTower();

  setupSlingshot();

  setupMouseInteraction();
}
////////////////////////////////////////////////////////////
function draw() {
  background(0);

  Engine.update(engine);

  drawGround();

  drawPropeller();

  drawTower();

  drawBirds();

  drawSlingshot();
}
////////////////////////////////////////////////////////////
//use arrow keys to control propeller
function keyPressed(){
  if (keyCode == LEFT_ARROW){
    angleSpeed += 0.01;
  }
  else if (keyCode == RIGHT_ARROW){
    angleSpeed -= 0.01;
  }
}
////////////////////////////////////////////////////////////
function keyTyped(){
  //if 'b' create a new bird to use with propeller
  if (key==='b'){
    setupBird();
  }

  //if 'r' reset the slingshot
  if (key==='r'){
    //removeFromWorld(slingshotBird);
    removeFromWorld(slingshotConstraint);
    setupSlingshot();
  }
}

//**********************************************************************
//  HELPER FUNCTIONS - DO NOT WRITE BELOW THIS line
//**********************************************************************

//if mouse is released destroy slingshot constraint so that
//slingshot bird can fly off
function mouseReleased(){
  setTimeout(() => {
    slingshotConstraint.bodyB = null;
    slingshotConstraint.pointA = { x: 0, y: 0 };
  }, 100);
}
////////////////////////////////////////////////////////////
//tells you if a body is off-screen
function isOffScreen(body){
  let pos = body.position;
  return (pos.y > height)
  // Modified so bodies don't disappear when they're not completely off the screen yet
}
////////////////////////////////////////////////////////////
//removes a body from the physics world
function removeFromWorld(body) {
  if(body != null)
    World.remove(engine.world, body);
}
////////////////////////////////////////////////////////////
function drawVertices(vertices) {
  beginShape();
  for (let i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape(CLOSE);
}
////////////////////////////////////////////////////////////
function drawConstraint(constraint) {
  push();
  let offsetA = constraint.pointA;
  let posA = {x:0, y:0};
  if (constraint.bodyA) {
    posA = constraint.bodyA.position;
  }
  let offsetB = constraint.pointB;
  let posB = {x:0, y:0};
  if (constraint.bodyB) {
    posB = constraint.bodyB.position;
  }
  strokeWeight(5);
  stroke(255);
  line(
    posA.x + offsetA.x,
    posA.y + offsetA.y,
    posB.x + offsetB.x,
    posB.y + offsetB.y
  );
  pop();
}
