// Example is based on examples from:
// http://brm.io/matter-js/
// https://github.com/shiffman/p5-matter
// https://github.com/b-g/p5-matter-examples

// module aliases
let Engine = Matter.Engine;
let Render = Matter.Render;
let World = Matter.World;
let Bodies = Matter.Bodies;
let Constraint = Matter.Constraint;

let engine;
let ground;

let ball1;
let ball2;

let catapult;
let catapultSpacer;
let constraint;

function setup() {
  createCanvas(800, 600);
  engine = Engine.create(); // create an engine
  setupCatapult();
  setupBalls();
  setupGround();
}
/////////////////////////////////////////////////////////////
function draw() {
  background(0);
  Engine.update(engine);
  drawBalls();
  drawCatapult();
  drawGround();
}

function mouseClicked() {
  if(ball2 == null)
  {
    ball2 = Bodies.circle(mouseX, mouseY, 50, {density: 0.01});
    World.add(engine.world, [ball2]);
  }
}

/////////////////////////////////////////////////////////////
function setupCatapult(){
  catapult = Bodies.rectangle(width/2, height - 85, width * 0.75, 10);
  constraint = Constraint.create({
    bodyB: catapult,
    pointA: {x: width/2, y: height - 85},
    stiffness: 1
  });
  catapultSpacer = Bodies.rectangle(150, height - 50, 10, 60, {isStatic: true});
  World.add(engine.world, [catapult, constraint, catapultSpacer]);
}
/////////////////////////////////////////////////////////////
function drawCatapult(){
  fill(255);
  drawVertices(catapult.vertices);
  fill(255, 0, 0);
  drawVertices(catapultSpacer.vertices);
}
/////////////////////////////////////////////////////////////
function setupBalls(){
  let radius1 = 15;
  ball1 = Bodies.circle(150, height - 50 - 55, radius1);
  World.add(engine.world, [ball1]);
}
/////////////////////////////////////////////////////////////
function drawBalls(){
  fill(0, 255, 0);
  drawVertices(ball1.vertices);
  if(ball2 != null)
    drawVertices(ball2.vertices);
}
/////////////////////////////////////////////////////////////
function setupGround(){
  ground = Bodies.rectangle(400, height-10, 810, 25, {isStatic: true});
  World.add(engine.world, [ground]);
}
/////////////////////////////////////////////////////////////
function drawGround(){
  noStroke();
  fill(128);
  drawVertices(ground.vertices);
}
////////////////////////////////////////////////////////////////
// ******* HELPER FUNCTIONS *********
// DO NOT WRITE BELOW HERE
/////////////////////////////////////////////////////////////
function drawVertices(vertices) {
  beginShape();
  for (let i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape(CLOSE);
}

function drawConstraint(constraint) {
  var offsetA = constraint.pointA;
  var posA = {x:0, y:0};
  if (constraint.bodyA) {
    posA = constraint.bodyA.position;
  }
  var offsetB = constraint.pointB;
  var posB = {x:0, y:0};
  if (constraint.bodyB) {
    posB = constraint.bodyB.position;
  }
  line(
    posA.x + offsetA.x,
    posA.y + offsetA.y,
    posB.x + offsetB.x,
    posB.y + offsetB.y
  );
}