// Example is based on examples from:
// http://brm.io/matter-js/
// https://github.com/shiffman/p5-matter
// https://github.com/b-g/p5-matter-examples

// module aliases
let Engine = Matter.Engine;
let Render = Matter.Render;
let World = Matter.World;
let Bodies = Matter.Bodies;
let Composites = Matter.Composites;
let Composite = Matter.Composite;
let Body = Matter.Body;

let engine;
let ball;
let ground;
let stack;

function setup() {
  createCanvas(1200, 600);

  // create an engine
  engine = Engine.create();

  ball = Bodies.circle(30, 0, 20, {
    restitution: 1,
    friction: 0,
    density: 0.003,
  });

  let options = { isStatic: true, angle: Math.PI * 0 };
  ground = Bodies.rectangle(width / 2, 500, width, 10, options);
  smallGround = Bodies.rectangle(50, 470, 100, 10, {
    isStatic: true,
    angle: Math.PI * 0.2,
  });

  // add all of the bodies to the world
  World.add(engine.world, [ground, ball, smallGround]);

  setupDominoes();
}
/////////////////////////////////////////////////////////
function draw() {
  background(0);
  Engine.update(engine);

  fill(255);
  drawVertices(ball.vertices);

  drawDominoes();

  fill(128);
  drawVertices(ground.vertices);
  drawVertices(smallGround.vertices);
}
/////////////////////////////////////////////////////////
function setupDominoes() {
  let size = 10;
  stack = Composites.stack(200, height - 305, 30,1,20,0,
    function (x, y) {
      let partA = Bodies.rectangle(x, y, 10, 200);
      return Body.create({ parts: [partA] });
    }
  );
  Composite.add(engine.world, [stack]);
}
/////////////////////////////////////////////////////////
function drawDominoes() {
  fill(255);
  for (let i = 0; i < stack.bodies.length; i++) {
    drawVertices(stack.bodies[i].vertices);
  }
}
/////////////////////////////////////////////////////////
// ********* HELPER FUNCTIONS **********
/////////////////////////////////////////////////////////
function drawVertices(vertices) {
  beginShape();
  for (let i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape(CLOSE);
}
