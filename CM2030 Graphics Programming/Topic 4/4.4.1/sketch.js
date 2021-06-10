let Engine = Matter.Engine,
  Render = Matter.Render,
  World = Matter.World,
  Bodies = Matter.Bodies,
  Body = Matter.Body;
let engine;
let box1;
let box2;
let ground1;
let ground2;
let ground3;
let circle, polygon;
let boxes = [];
let circles = [];
let colorBoxes = [];
let colorCircles = [];
let angle = 0;
let angleSpeed = 0.02;
let propeller;

function setup() {
  createCanvas(900, 600);
  // create engine
  engine = Engine.create();
  box1 = Bodies.rectangle(200, 200, 80, 80, {
    restitution: 0.8,
    friction: 0.5,
  });

  propeller = Bodies.rectangle(width/2, height/2, 300, 15, {isStatic: true});

  ground1 = Bodies.rectangle(200, 450, 200, 10, {
    isStatic: true
  });

  ground2 = Bodies.rectangle(500, 500, 200, 10, {
    isStatic: true
  });
  ground3 = Bodies.rectangle(850, 450, 200, 10, {
    isStatic: true
  });
  // add bodies to world
  World.add(engine.world, [box1, ground1, ground2, ground3, propeller]);
}

function draw() {
  background(0);
  Engine.update(engine);

  fill(50, 150, 50);
  drawVertices(ground1.vertices);
  drawVertices(ground2.vertices);
  drawVertices(ground3.vertices);
  drawVertices(propeller.vertices);
  Body.setAngle(propeller, angle += angleSpeed);
  Body.setAngularVelocity(propeller, angleSpeed);

  generateRect(width / 2, 0);
  generateEllipse(width/2, -50);

  for (let i = 0; i < boxes.length; i++) {
    fill(colorBoxes[i]);
    drawVertices(boxes[i].vertices);
    if (isOffScreen(boxes[i])) {
      World.remove(engine.world, boxes[i]);
      boxes.splice(i, 1);
      colorBoxes.splice(i, 1);
      i--;
    }
  }

  for (let i = 0; i < circles.length; i++) {
    fill(colorCircles[i]);
    drawVertices(circles[i].vertices);
    if (isOffScreen(circles[i])) {
      World.remove(engine.world, circles[i]);
      circles.splice(i, 1);
      colorCircles.splice(i, 1);
      i--;
    }
  }

  console.log("Boxes: " + boxes.length);
  console.log("Circles: " + circles.length);
  console.log("Engine bodies: " + engine.world.bodies.length);
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
