var init = function(){
	var dq = {};
	dq.front = null;
	dq.back = null;
	dq.createFirstNode = function(value){
		var newNode = this.createNode(null,null,value);
		this.front = newNode;
		this.back = newNode;
	}
	dq.isEmpty = function(){
		if(this.front == null || this.back == null){
			return true;
		}
		return false;
	}
	dq.readFront = function(){
		if(this.isEmpty()){
			console.log("Front is NULL, EMPTY DEQUE")
			return null;
		}else{
			return this.front.value;
		}
	}
	dq.readBack = function(){
		if(this.isEmpty()){
			console.log("Back is NULL, EMPTY DEQUE")
			return null;
		}else{
			return this.back.value;
		}
	}
	dq.pushFront = function(value){
		if(this.isEmpty()){
			this.createFirstNode(value);
		}else{
			var previousFrontNode = this.front;
			var newNode = this.createNode(null,previousFrontNode,value);
			previousFrontNode.front = newNode;
			this.front = newNode;
		}
	}
	dq.pushBack = function(value){
		if(this.isEmpty()){
			this.createFirstNode(value);
		}else{
			var previousBackNode = this.back;
			var newNode = this.createNode(previousBackNode,null,value);
			previousBackNode.back = newNode;
			this.back = newNode;
		}
	}
	dq.popFront = function(){
		if(this.isEmpty()){
			console.log("Front is NULL, EMPTY DEQUE");
			return null;
		}else{
			var nodeToPop = this.front;
			var nextNode = nodeToPop.back;
			if(nextNode != null){
				nextNode.front = null;
			}
			this.front = nextNode;
			return nodeToPop.value;
		}
	}
	dq.popBack = function(){
		if(this.isEmpty()){
			console.log("back is NULL, EMPTY DEQUE");
			return null;
		}else{
			var nodeToPop = this.back;
			var previousNode = nodeToPop.front;
			if(previousNode != null){
				previousNode.back = null;
			}
			this.back = previousNode;
			return nodeToPop.value;
		}
	}
	dq.createNode = function(frontPtr,backPtr,data){
		var node = {};
		node.front = frontPtr;
		node.back = backPtr;
		node.value = data;
		return node;
	}
	return dq;
}

module.exports = init;