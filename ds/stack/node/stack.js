var stack = function(){
	this.top = null;
	this.bottom = null;
	this.length = 0;	
}

stack.prototype.createFirstNode = function(value){
	var newNode = this.createNode(null,null,value);
	this.top = newNode;
	this.bottom = null;
}

stack.prototype.isEmpty = function(){
	if(this.top == null){
		return true;
	}
	return false;
}
stack.prototype.size = function(){
	return this.length;
}

stack.prototype.readTop = function(){
	if(this.isEmpty()){
		console.log("Empty stack")
		return null;
	}else{
		return this.top.value;
	}
}

stack.prototype.push = function(value){
	console.log("+:"+value)
	if(this.isEmpty()){
		this.createFirstNode(value);
	}else{
		var newNode = this.createNode(null,this.top,value);
		this.top = newNode;
	}
	this.length++;
}

stack.prototype.print = function(value){
	if(this.isEmpty()){
		console.log("Empty stack");
	}else{
		var node = this.top;
		var i=0;
		while(node != null){
			console.log("Stack["+i+"]:"+node.value);
			node = node.bottom;
			i++;
		}
	}
}

stack.prototype.pop = function(){	
	if(this.isEmpty()){
		console.log("Empty stack")
		return null;
	}else{
		var nodeToPop = this.top;
		this.top = nodeToPop.bottom;
		this.length--;
		console.log("-:"+nodeToPop.value)
		return nodeToPop.value;
	}
}

stack.prototype.createNode = function(top,bottom,data){
	var node = {};
	node.top = top;
	node.bottom = bottom;
	node.value = data;
	return node;
}

module.exports = stack;
