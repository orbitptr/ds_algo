
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class AmazonPQ {
	/*
	 * Complete the function below.
	*/
	public static class Job implements Comparable<Job>{
		public int pri;
		public int skill;
		public int time;
		public int id;
		@Override
		public String toString(){
			String str = " pri:"+pri + " time:"+ time+" id:"+id;
			return str;
		}

		    @Override
		    public int compareTo(Job job2) {
		    	if(this.pri != job2.pri){
				return (job2.pri)-(this.pri);
			}else{
				return (this.time)-(job2.time);
			}
		    }
	}

	public static class Worker implements Comparable<Worker>{
		public ArrayList<Job> jobList = null;
		public int waitTime = 0;
		int id;
		int skill;
		
		@Override
		 public int compareTo(Worker worker2) {
		    	if(this.waitTime != worker2.waitTime){
				return (this.waitTime)-(worker2.waitTime);
			}else{
				return (this.id)-(worker2.id);
			}
		 }
	}

	public static void analizeWorkerList(String[] input1,ArrayList<Worker> workerListByDesignation,ArrayList<MyBinaryHeap<Worker>> workers){
		for(int i=0;i<input1.length;i++){
			String current = input1[i];
			StringTokenizer st = new StringTokenizer(current,"#");
			Worker worker = new Worker();
			worker.id = (int)Integer.parseInt(new StringBuilder((String)st.nextElement()).deleteCharAt(0).toString()); 
			worker.id--;
			worker.skill = (int)Integer.parseInt(new StringBuilder((String)st.nextElement()).deleteCharAt(0).toString()); 
			worker.skill--;
			int skillIndex = worker.skill;
			if(skillIndex > (workers.size()-1)){
				MyBinaryHeap<Worker> workerPQ = new MyBinaryHeap<Worker>();
				workerPQ.add(worker);
				workers.add(workerPQ);
			}else{
				MyBinaryHeap<Worker> workerPQ = workers.get(skillIndex);
				workerPQ.add(worker);
			}
			workerListByDesignation.add(worker);
		}
	}

	public static void analizeJobsList(String[] input2,ArrayList<ArrayList<Job>> jobs){
		for(int i=0;i<input2.length;i++){
			String current = input2[i];
			StringTokenizer st = new StringTokenizer(current,"#");
			Job job = new Job();
			job.skill = (int)Integer.parseInt(new StringBuilder((String)st.nextElement()).deleteCharAt(0).toString()); 
			job.pri = (int)Integer.parseInt((String)st.nextElement()); 
			job.time = (int)Integer.parseInt((String)st.nextElement()); 
			job.id = (int)Integer.parseInt((String)st.nextElement());
			int skillIndex = job.skill - 1;
			if(skillIndex > (jobs.size()-1)){
				ArrayList<Job> jobList = new ArrayList<Job>();
				jobList.add(job);
				jobs.add(jobList);
			}else{
				ArrayList<Job> jobList = jobs.get(skillIndex);
				jobList.add(job);
			}
		}
	}

	public static void assignJobs(ArrayList<ArrayList<Job>> jobs, ArrayList<MyBinaryHeap<Worker>> workers){
		for(int i=0;i<jobs.size();i++){
			ArrayList<Job> currentJobList = jobs.get(i);
			MyBinaryHeap<Worker> workerPQ= workers.get(i);
			for(int j=0;j<currentJobList.size();j++){
				Job currentJob = currentJobList.get(j);
				if(i>=0 && i<workers.size()){
					Worker selectedWorker =  null;
					selectedWorker = workerPQ.peek();
					if(selectedWorker != null){
						if(selectedWorker.jobList == null){
							selectedWorker.jobList = new ArrayList<Job>();
						}
						selectedWorker.jobList.add(currentJob);
						selectedWorker.waitTime+= currentJob.time;
					}
					workerPQ.restoreHeapProperty();
				}
			}
		}
	}

	public static void sortJobs(ArrayList<ArrayList<Job>> jobs){
		for(int i=0;i<jobs.size();i++){
			ArrayList<Job> jobList = jobs.get(i);
			Collections.sort(jobList );
		}
	}

	public static String[] warehouseScalability(String[] input1,String[] input2)
	{
		if(input1 == null || input1.length ==0){
			return new String[0];
		}
		if(input2 == null || input2.length ==0){
			return new String[0];
		}
		ArrayList<Worker> workerListByDesignation = new ArrayList<Worker>();
		ArrayList<MyBinaryHeap<Worker>>  workers = new ArrayList<MyBinaryHeap<Worker>> ();	
		ArrayList<ArrayList<Job>> jobs = new ArrayList<ArrayList<Job>>();
		analizeWorkerList(input1,workerListByDesignation,workers);  
		analizeJobsList(input2,jobs);
		sortJobs(jobs); //J*log(J)
		printJobList(jobs);
		assignJobs(jobs,workers); //J*log(W)
		return generateOutputString(workerListByDesignation);
	}

	public static String[] generateOutputString(ArrayList<Worker> workerListByDesignation){
		ArrayList<String> output = new ArrayList<String>();
		for(int i=0;i<workerListByDesignation.size();i++){
			Worker currentWoker = workerListByDesignation.get(i);
			if(currentWoker.jobList != null && currentWoker.jobList.size()>0){
				StringBuilder sb=new StringBuilder("W");  
				sb.append(currentWoker.id+1);
				for(int j=0;j<currentWoker.jobList.size();j++){
					sb.append("#");
					sb.append(currentWoker.jobList.get(j).id);
				}
				output.add(sb.toString());
			}
		}
		String[] outputStringArray = new String[output.size()];
		for(int i=0;i<output.size();i++){
			outputStringArray[i] = output.get(i);
		}
		return outputStringArray;    	
	}

	static void  printJobList(ArrayList<ArrayList<Job>> jobList){
		System.out.println("printJobList ");
		if(jobList != null){
			for(int i=0;i<jobList.size();i++){
				ArrayList<Job> jobs = jobList.get(i);
				System.out.println("Skill "+(i+1));
				for(int j=0;j<jobs.size();j++){
					Job job = jobs.get(j);
					System.out.println(" pri:"+job.pri + " time:"+ job.time+" id:"+job.id);
				}
			}
		}
	}

	static void  printWorkerList(ArrayList<ArrayList<Worker>> workerList){
		System.out.println("printWorkerList  \n \n");
		if(workerList != null){
			for(int i=0;i<workerList.size();i++){
				ArrayList<Worker> workers = workerList.get(i);
				System.out.println("Skill "+(i+1));
				for(int j=0;j<workers.size();j++){
					Worker worker = workers.get(j);
					System.out.println("Desig:" + worker.id);
					System.out.println("Jobs:" + worker.jobList);
				}
			}
		}
	}

	// @SuppressWarnings("deprecation")
	public static void main(String[] args) throws IOException{
		long startTime = System.currentTimeMillis();		
		String[] output = null;
		String[] ip1 = {"W1#S1","W2#S2","W3#S3","W4#S1"};
		String[] ip2 = 
		{
			"S1#40#10#101",
			"S2#10#5#102",
			"S3#90#15#103",
			"S3#91#20#104",
			"S2#20#5#105",
			"S1#20#10#106",
			"S1#90#15#107",
			"S2#30#20#108",
			"S3#40#5#109",
			"S1#50#5#110"};

		ArrayList<String> workers = new ArrayList<String>();
		ArrayList<String> jobs = new ArrayList<String>();
		for(int i=0;i<1000;i++){
			String worker = "W"+(i+1)+"#S1";
			workers.add(worker);
		}
		for(int i=1;i<=100000;i++){
			double radians = Math.toRadians(i);	
			double sine = Math.sin(radians);
			double time = (100*sine);
			double priority = Math.abs(sine*100);
			String job = "S1#"+((int)priority)+"#"+((int)time)+"#"+(i+1);
			jobs.add(job);
		}


		ip1 = workers.toArray(new String[workers.size()]);
		ip2 = jobs.toArray(new String[jobs.size()]);

		output = warehouseScalability(ip1,ip2);
		for(int output_i=0; output_i < output.length; output_i++) {
			System.out.println(String.valueOf(output[output_i]));
		}

		long endTime   = System.currentTimeMillis();
		long totalTime = endTime - startTime;
		System.out.println("Total time:" + totalTime);
	}
}