let ball;

function setup() {
    createCanvas(900, 600);
    background(0);
    ball = new Ball(width, height);
}

function draw()
{
    background('red');
    ball.run();
}

class Ball
{
    constructor(w, h)
    {
        this.velocity = new createVector(random(-5, 2), random(-5, 20));
        this.location = new createVector(random(w), random(h));
        this.locX = random(w);
        this.locY = random(h);
        this.maxW = w;
        this.maxH = h;
    }

    run()
    {
        this.bounce();
        this.draw();
        this.move();
    }

    draw()
    {
        fill(125);
        ellipse(this.location.x, this.location.y, 40, 40);
    }

    move()
    {
        this.location.add(this.velocity);
        //console.log(this.location);
    }

    bounce()
    {
        if(this.location.x < 0 || this.location.x > this.maxW) this.velocity.x *= -1;
        if(this.location.y < 0 || this.location.y > this.maxH) this.velocity.y *= -1;
        console.log(this.velocity);
    }
}