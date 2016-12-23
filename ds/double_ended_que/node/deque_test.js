var deque_module = require('./deque.js');
var dq = new deque_module();
console.log("Front is " + dq.readFront());
dq.pushBack(23);
dq.pushBack(34);
dq.pushBack(38);
console.log("Front is " + dq.readFront());
console.log("Back is " + dq.readBack());
