var grapMod = require('./graph.js');
var graph = new grapMod(5);
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 2);
graph.addEdge(2, 0);
graph.addEdge(2, 3);
graph.addEdge(3, 3);
console.log("graph - " + graph + " graph.isEmpty" + graph.isEmpty());

