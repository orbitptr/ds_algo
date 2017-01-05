var init = function(vertexCount){
	var graph = {};
	if(vertexCount != null){
		graph.vc = vertexCount;
		graph.edges = [];
		for(var i=0;i<graph.vc;i++){
			graph.edges.push([]);
		}
	}else{
		graph.vc = null;
	}
	
	graph.addEdge = function(start,end){
		var edgeList = this.edges[start];
		for(var i=0;i<edgeList.length;i++){
			if(edgeList[i] == end){
				return;
			}
		}
		edgeList.push(end);
	}

	graph.getEdgeList = function(vertex){
		if(this.isEmpty() == false){
			return this.edges[vertex];
		}else{
			console.log("ERROR: Graph is empty");
			return null;
		}
	}

	graph.size = function(start,end){
		if(this.vc != null){
			return this.vc;
		}
		return 0;
	}


	graph.isEmpty = function(){
		if(this.vc == null || this.vc == 0){
			return true;
		}
		return false;
	}
	return graph;
}

module.exports = init;