var queue_module = require('./queue.js');
var queue = new queue_module();
console.log("Top is " + queue.readFront());
queue.enque(23);
queue.enque(34);
queue.enque(38);
queue.enque(48);
queue.enque(1);
queue.enque(2);
queue.enque(3);
queue.enque(4);
queue.print();
console.log("Deque")
queue.deque();
queue.deque();
queue.print();