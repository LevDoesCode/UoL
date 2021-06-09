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
  ground = Bodies.rectangle(400, 500, 810, 10, options);  
  // add bodies to world
  World.add(engine.world, [box1, ground]);
}

function draw() {
  background(0);
  Engine.update(engine);
  rectMode(CENTER);
  push();
  let pos = box1.position;
  translate(pos.x, pos.y);
  rotate(box1.angle);
  rect(0, 0, 80, 80);
  pop();

  push();
  pos = ground.position;
  translate(pos.x, pos.y);
  rotate(ground.angle);
  rect(0, 0, 810, 10);
  pop();
}
