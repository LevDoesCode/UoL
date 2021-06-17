#include <assert.h>

int main()
{
  double sensorReading = 165500;
  unsigned short storedValue = sensorReading;

  assert(storedValue == sensorReading);

  return 0;
}