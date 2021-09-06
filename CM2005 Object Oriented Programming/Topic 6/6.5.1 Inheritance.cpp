#include <iostream>

class Vehicle
{
  public:
    Vehicle();
    float getspeed();
    void accelerate();
    void beepHorn();
  private:
    float speed;
};

class Train : public Vehicle
{
  public:
    Train();
    void beepHorn();
};

Train::Train()
{
  std::cout << "Train constructor" << std::endl;
}

void Train::beepHorn()
{
  if(getspeed() < 0.5)
  {
    std::cout << "bip" << std::endl;
  }
  else
  {
    std::cout << "BOOP BIP" << std::endl;
  }
}

Vehicle::Vehicle() : speed(0.0f)
{
  std::cout << "Vehicle constructor" << std::endl;
}

float Vehicle::getspeed()
{
  return speed;
}

void Vehicle::accelerate()
{
  speed += 0.5f;
}

void Vehicle::beepHorn()
{
  std::cout << "meep meep" << std::endl;
}

int main()
{
  Vehicle v;
  v.beepHorn();

  Train t;
  t.beepHorn();
  t.accelerate();
  t.beepHorn();
}