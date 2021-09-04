function verifyUser(username, password)
{
  // code here
  throw{name:"DatabaseError", message: "Could not connect to database"}
}

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