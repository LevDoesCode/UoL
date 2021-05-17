function getHighest(input)
{
	let max = input.length - 1;

	for(let i = 0; i < input.length; i++)
    if(input[i] > max) max = input[i];
  return max;
}

function testCorrectRes()
{
  let input = [1, 2, 4, 5, 6];
  let res = getHighest(input);
  
  let max = Math.max.apply(null, input);
  if(res == max) return true;
  else return false;
}

function testResInArray()
{
  let input = [1, 2, 4, 5, 6];
  let res = getHighest(input);
  
  if(input.includes(res)) return true;
  else return false;
}

function testRetVal()
{
  let input = [1, 2, 4, 5, 6];
  let res = getHighest(input);

  if(res == undefined) return false;
  else return true;
}

let res = testRetVal();
if(res) console.log('testRetVal passed');
else console.log('testRetVal failed');

res = testResInArray();
if(res) console.log('testResInArray passed');
else console.log('testResInArray failed');

res = testCorrectRes();
if(res) console.log('testCorrectRes passed');
else console.log('testCorrectRes failed');