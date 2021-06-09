let Engine = Matter.Engine,
    Render = Matter.Render,
    World  = Matter.World,
    Bodies = Matter.Bodies;
let engine;
let box1;
let box2;
let ground;

function setup() {
  createCanvas(900, 600);
  // create engine
  engine = Engine.create();
  box1 = Bodies.rectangle(200, 200, 80, 80, {restitution: .8, friction: 0.5});

  let options = {isStatic: true, angle: Math.PI * 0.06};
  ground1 = Bodies.rectangle(100, 350, 500, 10, {isStatic: true, angle: Math.PI * 0.06});
  ground2 = Bodies.rectangle(500, 500, 500, 10, {isStatic: true, angle: Math.PI * -0.06});
  // add bodies to world
  World.add(engine.world, [box1, ground1, ground2]);
}

function draw() {
  background(0);
  Engine.update(engine);
  
  fill(255);
  drawVertices(box1.vertices);

  fill(150, 50, 50);
  drawVertices(ground1.vertices);
  
  fill(50, 150, 50);
  drawVertices(ground2.vertices);
}

function drawVertices(vertices)
{
  beginShape();
  for (let i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape();
}