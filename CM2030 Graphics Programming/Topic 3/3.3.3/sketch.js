//////////////////////////////////
// COURSERA GRAPHICS PROGRAMMING
//////////////////////////////////
// Adapted from https://github.com/nature-of-code/
// released under MIT license

var ball;
///////////////////////////////////////////////
function setup() {
  createCanvas(900, 600);
  balls = [];
}
///////////////////////////////////////////////
function draw() {
  background(0);

  fill(255, 0, 0, 150);
  rectMode(CENTER);
  let boxW = 100;
  rect(width/2, height/2, boxW, boxW);

  let gravity = createVector(0, 0.1);
  for (let i = 0; i < balls.length; i++) {
    let ball = balls[i];

    //collision with red box
      //ball y location
      let ballY = ball.location.y;
      let ballX = ball.location.x;
      let ballRadius = ball.size/2;
      let boxUpperY = height/2 - boxW/2;
      let boxLowerY = height/2 + boxW/2;
      let boxRightX = width/2 + boxW/2;
      let boxLeftX = width/2 - boxW/2;

    if(ballY + ballRadius >= boxUpperY && ballX + ballRadius >= boxLeftX && ballX - ballRadius <= boxRightX)
      ball.color = '#FF0000';
    //accelerations
    let friction = ball.velocity.copy();
    friction.mult(-1);
    friction.normalize();
    friction.mult(0.03);

    ball.applyForce(gravity);
    ball.applyForce(friction);
    ball.run();
  }
}

function mouseClicked() {
  //ball.location = new createVector(width / 2, height / 2);
  mouseDragged();
}

function mouseDragged() {

  if(mouseButton === LEFT)
    balls.push(new Ball(mouseX, mouseY));
  else
    balls = [];
}

///////////////////////////////////////////////
class Ball {
  color = "#666666";
  constructor(x, y) {
    this.acceleration = new createVector(0, 0);
    this.velocity = new createVector(random(-3, 3), random(-3, 3));
    this.location = new createVector(x, y);
    this.size = random (10, 60);
  }

  run() {
    this.draw();
    this.move();
    this.bounce();
  }

  draw() {
    fill(this.color);
    ellipse(this.location.x, this.location.y, this.size, this.size);
  }

  move() {
    this.velocity.add(this.acceleration);
    this.location.add(this.velocity);
    this.acceleration.mult(0);
  }

  bounce() {
    if (this.location.x > width - this.size / 2) {
      this.location.x = width - this.size / 2;
      this.velocity.x *= -1;
    } else if (this.location.x < this.size / 2) {
      this.velocity.x *= -1;
      this.location.x = this.size / 2;
    }
    if (this.location.y > height - this.size / 2) {
      this.velocity.y *= -1;
      this.location.y = height - this.size / 2;
    }
  }
  applyForce(force) {
    this.acceleration.add(force);
  }
}
