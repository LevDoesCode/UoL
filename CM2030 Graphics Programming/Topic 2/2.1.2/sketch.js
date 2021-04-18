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
        this.speedX = random(-5, 5);
        this.speedY = random(-5, 5);
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
        ellipse(this.locX, this.locY, 40, 40);
    }

    move()
    {
        this.locX += this.speedX;
        this.locY += this.speedY;
    }

    bounce()
    {
        if(this.locX < 0 || this.locX > this.maxW) this.speedX *= -1;
        if(this.locY < 0 || this.locY > this.maxH) this.speedY *= -1;
    }
}