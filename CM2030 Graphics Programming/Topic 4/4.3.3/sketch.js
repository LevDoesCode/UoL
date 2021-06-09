let Engine = Matter.Engine,
  Render = Matter.Render,
  World = Matter.World,
  Bodies = Matter.Bodies,
  Constraint = Matter.Constraint,
  MouseConstraint = Matter.MouseConstraint;
  Mouse = Matter.Mouse;
let engine;
let ground1;
let constraint1;
let constraint2;
let constraint3;
let poly1A;
let poly1B;
let poly2;
let poly3;
let canvas;


function setup() {
  canvas = createCanvas(900, 600);
  // create engine
  engine = Engine.create();

  poly1A = Bodies.polygon(700, 100, 6, 20);
  poly1B = Bodies.polygon(700, 200, 1, 30);
  constraint1 = Constraint.create({
    bodyA: poly1A,
    pointA: {x: 0, y: 0},
    bodyB: poly1B,
    pointB: {x: 0, y: 0},
    stiffness: 0.01
  });

  poly2 = Bodies.polygon(300, 200, 5, 40);
  constraint2 = Constraint.create({
    bodyB: poly2,
    pointA: {x: 150, y: 50},
    pointB: {x: 0, y: 0},
  });

  poly3 = Bodies.polygon(300, 100, 4, 30);
  constraint3 = Constraint.create({
    pointA: {x: 400, y: 120},
    bodyB: poly3,
    pointB: {x: 0, y: 0},
    stiffness: 0.001,
    damping: 0.001
  });

  ground1 = Bodies.rectangle(width/2, height - 20, width, 10, {
    isStatic: true,
  });
  // add bodies to world
  World.add(engine.world, [ground1, poly1A, poly1B, constraint1, poly2, constraint2, poly3, constraint3]);
  let mouse = Mouse.create(canvas.elt);
  let mouseParams = {mouse: mouse};
  let mouseConstraint = MouseConstraint.create(engine, mouseParams);
  mouseConstraint.mouse.pixelRatio = pixelDensity();
  World.add(engine.world, mouseConstraint);
}

function draw() {
  background(0);
  Engine.update(engine);

  noStroke();
  fill(255);
  drawVertices(ground1.vertices);
  drawVertices(poly1A.vertices);
  drawVertices(poly1B.vertices);
  drawVertices(poly2.vertices);
  drawVertices(poly3.vertices);
  stroke(128);
  strokeWeight(3);
  drawConstraint(constraint1);
  drawConstraint(constraint2);
  drawConstraint(constraint3);

  //generateRect(width / 2, 0);
  //generateEllipse(width/2, -50);
}

function isOffScreen(body) {
  let pos = body.position;
  return pos.y > height || pos.x < 0 || pos.x > width;
}

function generateRect(x, y) {
  let b = Bodies.rectangle(x, y, random(10, 30), random(10, 30), {
    restitution: 1.2,
    friction: 0.5,
  });
  Matter.Body.setMass(b, 1);
  boxes.push(b);
  World.add(engine.world, [b]);
  colorBoxes.push("rgba(" + Math.trunc(random(100, 250)).toString() + "," + Math.trunc(random(100, 250)).toString() + "," + Math.trunc(random(100, 250)).toString() + ", 0.5)");
}

function generateEllipse(x, y) {
  let b = Bodies.circle(x, y, random(10, 30), {
    restitution: 1.2,
    friction: 0.5,
  });
  Matter.Body.setMass(b, 1);
  circles.push(b);
  World.add(engine.world, [b]);
  colorCircles.push("rgba(" + Math.trunc(random(100, 250)).toString() + "," + Math.trunc(random(100, 250)).toString() + "," + Math.trunc(random(100, 250)).toString() + ", 0.5)");
}

function drawVertices(vertices) {
  beginShape();
  for (let i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape();
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