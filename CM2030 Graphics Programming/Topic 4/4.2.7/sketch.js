// Example is based on examples from:
// http://brm.io/matter-js/
// https://github.com/shiffman/p5-matter
// https://github.com/b-g/p5-matter-examples

// module aliases
let Engine = Matter.Engine;
let Render = Matter.Render;
let World = Matter.World;
let Bodies = Matter.Bodies;

let engine;
let balls = [];
let ground;
let plinkos = [];

function setup() {
  createCanvas(900, 600);

  engine = Engine.create(); // create an engine

  setupGround();
  setupPins();
  generateNewBall();
}
///////////////////////////////////////////////////////////
function draw() {
  background(0);
  Engine.update(engine);

  drawPins();
  drawBalls();
  drawGround();
  console.log("# Balls: ", balls.length);
}
///////////////////////////////////////////////////////////
function keyPressed(){
  generateNewBall();
}
///////////////////////////////////////////////////////////
function setupGround(){
  let groundWidth = 10;
  ground = Bodies.rectangle(width/2, height - groundWidth * 2, width, groundWidth, {isStatic: true});
  World.add(engine.world, [ground]);
}
///////////////////////////////////////////////////////////
function drawGround(){
  fill(125);
  drawVertices(ground.vertices);
}
///////////////////////////////////////////////////////////
function setupPins(){
  //plinko wall
  let options = {isStatic: true, restitution: 1};
  let cols = 15;
  let rows = 9;
  let spacing = width / cols;
  for (let j = 0; j < rows; j++) {
    for (let i = 0; i < cols; i++) {
      let x = i * spacing;
      if (j % 2 == 0) {
        x += spacing / 2;
      }
      let y = spacing + j * spacing;

      let p = Bodies.circle(x, y, 10, options);
      World.add(engine.world, [p]);
      plinkos.push(p);
    }
  }
}
///////////////////////////////////////////////////////////
function drawPins(){
  fill(255,200,0);
  for (let i=0; i<plinkos.length; i++){
    drawVertices(plinkos[i].vertices);
  }
}
///////////////////////////////////////////////////////////
function generateNewBall(){
  let newBall = Bodies.circle(random(5, width - 5), 0, 10, {restitution: 1});
  World.add(engine.world, [newBall]);
  balls.push(newBall);
}
///////////////////////////////////////////////////////////
function drawBalls(){
  fill('red');
  for (let i = 0; i < balls.length; i++) {
    drawVertices(balls[i].vertices);
    if(isOffScreen(balls[i]))
    {
      World.remove(engine.world, balls[i]);
      balls.splice(i, 1);
      i--;
    }
  }
}

///////////////////////////////////////////////////////////
// **** HELPER FUNCTIONS ****
// DO NOT WRITE BELOW THIS LINE
///////////////////////////////////////////////////////////
function drawVertices(vertices) {
  beginShape();
  for (let i = 0; i < vertices.length; i++) {
    vertex(vertices[i].x, vertices[i].y);
  }
  endShape(CLOSE);
}

function isOffScreen(body) {
  let pos = body.position;
  return pos.y > height || pos.x < 0 || pos.x > width;
}