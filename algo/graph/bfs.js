var GraphMod = require('../../ds/graph/node/graph.js');
var DequeMod = require('../../ds/double_ended_que/node/deque.js');

var bfsGraph = function (graph,startVertex) {
	console.log("\n=================BFS: StartVertex: "+startVertex );
	if(graph == null || graph.isEmpty()){
		console.log("Graph is Empty");
		return;
	}
	var visited = new Array(graph.size());
	for(var i=0;i<visited.length;i++){visited[i] = false;}
	var dq = new DequeMod();
	dq.pushBack(startVertex);
	visited[startVertex] = true;
	while(!dq.isEmpty()){
		var currentVertex = dq.popFront();
		console.log("BFS: Visiting: " + currentVertex);
		var edgeList = graph.getEdgeList(currentVertex);
		for(var i=0;i<edgeList.length;i++){
			if(visited[edgeList[i]] == false){
				visited[edgeList[i]] = true;
				dq.pushBack(edgeList[i]);
			}
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
bfsGraph(graph,2);
bfsGraph(graph,0);
bfsGraph(graph,1);
bfsGraph(graph,3);
