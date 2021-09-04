try
{
  verifyUser();
  console.log("After verifyUser");
}
catch (exception)
{
  console.log("Exception caught");
  console.log("Name: " + exception.name); // Type of exception
  console.log("Message: " + exception.message);
}

console.log("I'm still running..");