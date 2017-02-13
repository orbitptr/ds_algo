var deque = function(debug){
	this.init(debug);	
}

deque.prototype.init = function(debug) {
	this.front = null;
	this.back = null;
	this.length = 0;
	this.isDebug = debug;
}

deque.prototype.createFirstNode = function(value){
	var newNode = this.createNode(null,null,value);
	this.front = newNode;
	this.back = newNode;
}

deque.prototype.isEmpty = function(){
	if(this.front == null || this.back == null){
		return true;
	}
	return false;
}
deque.prototype.size = function(){
	return this.length;
}

deque.prototype.readFront = function(){
	if(this.isEmpty()){
		if(this.isDebug)console.log("Front is NULL, EMPTY DEQUE")
		return null;
	}else{
		return this.front.value;
	}
}

deque.prototype.readIndexFromFront = function(index){
	if(this.isEmpty()){
		if(this.isDebug)console.log("readFrontAt is NULL, EMPTY DEQUE")
		return null;
	}else{
		if(index < this.length){
			var current = this.front;
			for(var i=0;i<index;i++){
				current = current.back;
			}
			return current.value;
		}else{
			return null;
		}
	}
}

deque.prototype.readIndexFromBack = function(indexFromBack){
	if(this.isEmpty()){
		if(this.isDebug)console.log("readFrontAt is NULL, EMPTY DEQUE")
		return null;
	}else{
		if(indexFromBack < this.length){
			var current = this.back;
			for(var i=0;i<indexFromBack;i++){
				current = current.front;
			}
			return current.value;
		}else{
			return null;
		}
	}
}

deque.prototype.pushFront = function(value){
	if(this.isEmpty()){
		this.createFirstNode(value);
	}else{
		var previousFrontNode = this.front;
		var newNode = this.createNode(null,previousFrontNode,value);
		previousFrontNode.front = newNode;
		this.front = newNode;
	}
	this.length++;
}

deque.prototype.pushBack = function(value){
	if(this.isEmpty()){
		this.createFirstNode(value);
	}else{
		var previousBackNode = this.back;
		var newNode = this.createNode(previousBackNode,null,value);
		previousBackNode.back = newNode;
		this.back = newNode;
	}
	this.length++;
}

deque.prototype.popFront = function(){	
	if(this.isEmpty()){
		if(this.isDebug)console.log("Front is NULL, EMPTY DEQUE")
		return null;
	}else{
		var nodeToPop = this.front;
		var nextNode = nodeToPop.back;
		if(nextNode != null){
			nextNode.front = null;
		}
		this.front = nextNode;
		this.length--;
		return nodeToPop.value;
	}
}

deque.prototype.popBack = function(){
	if(this.isEmpty()){
		if(this.isDebug)console.log("back is NULL, EMPTY DEQUE")
		return null;
	}else{
		var nodeToPop = this.back;
		var previousNode = nodeToPop.front;
		if(previousNode != null){
			previousNode.back = null;
		}
		this.length--;
		this.back = previousNode;
		return nodeToPop.value;
	}
}

deque.prototype.createNode = function(frontPtr,backPtr,data){
	var node = {};
	node.front = frontPtr;
	node.back = backPtr;
	node.value = data;
	return node;
}

deque.prototype.addAllBack = function(inputDeque){
	if(inputDeque.isEmpty() ){
		if(this.isDebug)console.log("EMPTY DEQUE")
		return null;
	}else{
		var node = inputDeque.front;
		while(node != null){
			this.pushBack(node.value);
			node = node.back;
		}
	}
}

deque.prototype.clear = function(inputDeque){
	this.init(this.isDebug);
}

deque.prototype.print = function(){
	if(this.isEmpty()){
		if(this.isDebug)console.log("Dque Empty")
		return null;
	}else{
		var node = this.front;
		var i=0;
		while(node != null){
			console.log("Deque["+i+"]:"+node.value);
			node = node.back;
			i++;
		}
	}
}

module.exports = deque;
