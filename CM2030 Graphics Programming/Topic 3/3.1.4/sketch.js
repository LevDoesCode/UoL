//////////////////////////////////
// COURSERA GRAPHICS PROGRAMMING
//////////////////////////////////
// Adapted from https://github.com/nature-of-code/
// released under MIT license

var ball;
////////////////////////////////////////////////////
function setup()
{
  createCanvas(900, 600);
  ball = new Ball();
}
////////////////////////////////////////////////////
function draw()
{
  background(0);

  let mouse = createVector(mouseX, mouseY);
  let dir = p5.Vector.sub(mouse, ball.location);
  dir.normalize();
  dir.mult(0.3);
  ball.applyForce(dir);

  ball.run();
}
//////////////////////////////////////////////////////
class Ball
{
  constructor()
  {
    this.acceleration = new createVector(0, 0);
    this.velocity = new createVector(0, 0);
    this.location = new createVector(width/2, height/2);
    this.size = 40;
  }

  run()
  {
    this.draw();
    this.move();
    this.bounce();
  }

  draw()
  {
    fill(125);
    ellipse(this.location.x, this.location.y, this.size, this.size);
  }

  move()
  {
    this.velocity.add(this.acceleration);
    this.location.add(this.velocity);
    this.acceleration.mult(0);
    this.velocity.limit(10);
  }

  bounce()
  {
    if (this.location.x > width - this.size / 2)
    {
      this.location.x = width - this.size / 2;
      this.velocity.x *= -1;
    }
    else if (this.location.x < this.size / 2)
    {
      this.velocity.x *= -1;
      this.location.x = this.size / 2;
    }

    if (this.location.y > height - this.size / 2)
    {
      this.velocity.y *= -1;
      this.location.y = height - this.size / 2;
    }
    else if(this.location.y < this.size /2)
    {
      this.velocity.y *= -1;
      this.location.y = this.size/2;
    }
  }

  applyForce(force) {
    this.acceleration.add(force);
  }
}
