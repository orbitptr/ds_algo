var GraphMod = require('../../ds/graph/node/graph.js');
var DequeMod = require('../../ds/double_ended_que/node/deque.js');
var visited = null;
var solutionSpace = [];

var dfsGraph = function (graph,currentVertex) {
	if(graph == null || graph.isEmpty()){
		console.log("Graph is Empty");
		return;
	}
	if(visited == null){
		visited = new Array(graph.size());
		for(var i=0;i<visited.length;i++){visited[i] = false;}
	}
	solutionSpace.push(currentVertex);
	visited[currentVertex] = true;
	var edgeList = graph.getEdgeList(currentVertex);
	for(var i=0;i<edgeList.length;i++){
		if(visited[edgeList[i]] == false){
			dfsGraph(graph,edgeList[i]);
		}
	}
}

var graph = new GraphMod(5);
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 2);
graph.addEdge(2, 0);
graph.addEdge(2, 3);
graph.addEdge(3, 3);


dfsGraph(graph,2);
console.log("StartingVertex:2 " + solutionSpace);
solutionSpace.length = 0;
visited=null;

dfsGraph(graph,0);
console.log("StartingVertex:0 " + solutionSpace);
solutionSpace.length = 0;
visited=null;

dfsGraph(graph,1);
console.log("StartingVertex:1 " + solutionSpace);
solutionSpace.length = 0;
visited=null;

dfsGraph(graph,3);
console.log("StartingVertex:3 " + solutionSpace);
solutionSpace.length = 0;
visited=null;
