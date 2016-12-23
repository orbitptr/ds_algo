var deque_module = require('../../ds/double_ended_que/node/deque.js');
var dq = new deque_module();
//var arr = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13];
var arr = [12, 1, 78, 90, 57, 89, 56];
var k = 3;
var n = arr.length;
for(var i=0;i<k;i++){
	while(!dq.isEmpty() && (arr[i] >= arr[dq.readBack()])){
		dq.popBack();
	}
	dq.pushBack(i);
}
for(;i<n;i++){
	console.log("Maximum Element in this window - " + arr[dq.readFront()]);
	while(!dq.isEmpty() && (dq.readFront() <= (i-k))){
		dq.popFront();
	}
	while(!dq.isEmpty() && (arr[i] >= arr[dq.readBack()])){
		dq.popBack();
	}
	dq.pushBack(i);	
}
console.log("Maximum Element in this window - " + arr[dq.readFront()]);