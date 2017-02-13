var queue = function(){
	this.front = null;
	this.rear = null;
	this.length = 0;	
}

queue.prototype.createFirstNode = function(value){
	var newNode = this.createNode(null,null,value);
	this.front = newNode;
	this.rear = newNode;
}

queue.prototype.isEmpty = function(){
	if(this.front == null && this.rear == null){
		return true;
	}
	return false;
}

queue.prototype.size = function(){
	return this.length;
}

queue.prototype.readFront = function(){
	if(this.isEmpty()){
		console.log("Empty queue")
		return null;
	}else{
		return this.front.value;
	}
}

queue.prototype.enque = function(value){
	console.log("+:"+value)
	if(this.isEmpty()){
		this.createFirstNode(value);
	}else{
		var newNode = this.createNode(this.rear,null,value);
		this.rear.rear = newNode;
		this.rear = newNode;
	}
	this.length++;
}


queue.prototype.deque = function(){	
	if(this.isEmpty()){
		console.log("Empty queue")
		return null;
	}else{
		var nodeToDeque = this.front;
		this.front = this.front.rear;
		this.length--;
		console.log("-:"+nodeToDeque.value)
		return nodeToDeque.value;
	}
}

queue.prototype.createNode = function(front,rear,data){
	var node = {};
	node.front = front;
	node.rear = rear;
	node.value = data;
	return node;
}

queue.prototype.print = function(value){
	if(this.isEmpty()){
		console.log("Empty queue");
	}else{
		var node = this.front;
		var i=0;
		while(node != null){
			console.log("Queue["+i+"]:"+node.value);
			node = node.rear;
			i++;
		}
	}
}

module.exports = queue;
