import java.util.ArrayList;
class Graph{
	int v=0;
	ArrayList<ArrayList<Integer>> adjList = null;

	Graph(int v){
		this.v = v;
		this.adjList = new ArrayList<>();
		for(int i=0;i<v;i++){
			this.adjList.add(new ArrayList<Integer>());
		}
	}

	public int size(){
		return v;
	}

	public ArrayList<Integer> getAdjList(int vertex){
		return this.adjList.get(vertex);
	}

	public void addUndirectedEdge(int start,int end){
		start--;
		end--;
		this.adjList.get(start).add(end);
		this.adjList.get(end).add(start);
	}
}

public class MaximumTourism{
	public static void main(String[] args){
		int n=8,m=5;
		System.out.println("this is test");
		Graph g = new Graph(n);
		
		g.addUndirectedEdge(1, 2);
		g.addUndirectedEdge(7, 4);
		g.addUndirectedEdge(7, 3);
		g.addUndirectedEdge(5, 8);
		g.addUndirectedEdge(1, 3);

		 // g.addUndirectedEdge(4, 4);
		 // g.addUndirectedEdge(2, 3);
		 // g.addUndirectedEdge(2, 3);
		 // g.addUndirectedEdge(2, 5);
		 // g.addUndirectedEdge(2, 7);
		 // g.addUndirectedEdge(5, 7);
		 // g.addUndirectedEdge(6, 8);
		
		int maxCity = 0;
		for(int i=0;i<n;i++){
			int current = BFS(g,i);
			//System.out.println("current:"+current);
			if(maxCity< current){
				maxCity = current;
			}
		}

		System.out.println("maxCity:"+maxCity);
	}

	public static int BFS(Graph g,int start){
		int visitedCount = 0;
		boolean[] visitedArray = new boolean[g.size()];
		ArrayList<Integer> queue = new ArrayList<Integer>();
		queue.add(start);
		visitedArray[start]= true;
		while(!queue.isEmpty()){
			int current = queue.get(0);
			queue.remove(0);
			queue.trimToSize();			
			visitedCount++;
			ArrayList<Integer> adjList = g.getAdjList(current);
			if(adjList != null){
				for(int i=0;i<adjList.size();i++){
					if(visitedArray[adjList.get(i)] == false){
						visitedArray[adjList.get(i)]= true;
						queue.add(adjList.get(i));
					}
				}
			}
		}
		return visitedCount;
	}
}