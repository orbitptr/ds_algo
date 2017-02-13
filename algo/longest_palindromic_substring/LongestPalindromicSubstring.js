var deque_module = require('../../ds/double_ended_que/node/deque.js');
var debug = false;

var dq1 = new deque_module();
var dq2 = new deque_module();

var answer = new deque_module();
var arr = [1,1,1,1,1,2,3,4,5,4,3,10,2,1];
var arr = [1,1,1,1,1,2,2,2,2,2,2,2,2,6,2,3,4,5,4,3,10,2,1];
var arr = [1,2,3,10,2,3,3,4,4,5,4,4,2];
var arr = [1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,6,6,2,6,6,6,6,6,6,6];
var arr = [2,1,1,1,1,1,1,1,1,1,1,1];
var arr = [1,2,3,10,2,3,3,4,4,4,4,5,4,4,2];
var arr = [1,2,3,4,5,4,3,10,2,1];
var arr = [1,1,3,2,2,1,1,2,2];
var arr = [1,1,3,2,2,1,1,2,2,3,3,3,100];
var arr = [5,6,7,5,7,7,7,6,5,6,8];

var arr = [1,1,1,1,1,1,1,67,1,1,1,1,1,1,1,1,1,10,3,2,2,1,1,2,2,3,3,3,4,4,99,7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,7,7,7];
dq1.pushBack(arr[0]);
var lastElem = null;
var isSeries= false;

for(var i=1;i<arr.length;i++){
	var elem = arr[i];
	if(debug)console.log("START:"+elem);
	if(dq1.readIndexFromBack(0) == elem){
		if(debug)console.log("CASE1:");
		if(dq2.isEmpty() && lastElem == null){
			if(debug)console.log("CASE2:");
			isSeries = true;
			lastElem = elem;
		}else if(!dq2.isEmpty() && lastElem != elem){
			if(debug)console.log("CASE3:");
			isSeries = false;
			lastElem = null;
		}
		dq2.pushFront(dq1.popBack());
		dq2.pushBack(elem);
	}else if(dq2.isEmpty() && dq1.readIndexFromBack(1) == elem){
		if(debug)console.log("CASE4:");
		dq2.pushFront(dq1.popBack());
		dq2.pushFront(dq1.popBack());
		dq2.pushBack(elem);
	}else if(dq2.isEmpty() == false){
		if(debug)console.log("CASE5:");
		if(debug)console.log("palindrom ==========");
		if(isSeries && dq2.readIndexFromBack(0) == elem){
			if(debug)console.log("CASE6:");
			dq2.pushBack(elem);
		}else{
			if(debug)console.log("CASE7:");
			isSeries = false;
			if(debug)dq2.print();
			if(answer.size()<=dq2.size()){
				answer.clear();
				answer.addAllBack(dq2);
			}
			dq1.addAllBack(dq2);
			dq2.clear();
			i--;
		}			
	}else{
		if(debug)console.log("CASE8:");
		dq1.pushBack(elem);
	}
}
if(debug)console.log("Last print");
if(debug)dq2.print();

if(answer.size()<=dq2.size()){
	answer.clear();
	answer.addAllBack(dq2);
}
console.log("\nAnswer is ===============");
answer.print();






/*TAKE FIRST ELEMENT IN THE STACK
run a loop from 1 to last element
if new element is equal to the top of the stack
	if(s2 is empty then this s begining)
		series = true
		lastelem = newele
	else aleady some series is goin on then put these two element in s2
if new element is equal to second element and s2 is empty 
	then start of new element
if both are false
	then if s2 is not empty then some series is going on 
		check if series == true then compare the top element of s2 to newelem and put on its
		else series is fully broken. its neither a contineuous series nor a palidrom series so print the palindrom and update answer and add all the element of s2 to s1 and recheck with the same answer

else there is no series started nor one is running then put on the s1 and carryon*/
/*

keep a boolean if contineuous = false
put first 2 element in a stack
loop through the arry from 3rd element
if its equal to the top element of the stack then contineuous = true
	and pop the element from dq1 and put both in dq2
if its equal to the second element of the stack then contineuous = false
	and do the needful

if its contineuous and  equal to the top of the dq2 put on dq2 and carryon

else if dq2 is not empty new palindrom 
	print and transfer all element to dq1 and i--
else just put on the stack of dq1
	*/
