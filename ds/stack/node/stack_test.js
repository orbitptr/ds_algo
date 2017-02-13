var stack_module = require('./stack.js');
var stack = new stack_module();
console.log("Top is " + stack.readTop());
stack.push(23);
stack.push(34);
stack.push(38);
stack.push(48);
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);
stack.print();
console.log("Popping")
stack.pop();
stack.pop();
stack.print();