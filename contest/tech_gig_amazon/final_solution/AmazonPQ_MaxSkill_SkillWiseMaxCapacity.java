
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class AmazonPQ_MaxSkill_SkillWiseMaxCapacity {
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

	public static int findMaxSkill(String[] input1,ArrayList<Worker> workerLinkedList){
		int maxSkillCount=0;
		for(int i=0;i<input1.length;i++){
			String current = input1[i];
			StringTokenizer st = new StringTokenizer(current,"#");
			Worker worker = new Worker();
			worker.id = (int)Integer.parseInt(new StringBuilder((String)st.nextElement()).deleteCharAt(0).toString()); 
			worker.id--;
			worker.skill = (int)Integer.parseInt(new StringBuilder((String)st.nextElement()).deleteCharAt(0).toString()); 
			if(worker.skill > maxSkillCount){
				maxSkillCount = worker.skill;
			}
			worker.skill--;
			workerLinkedList.add(worker);
		}
		return maxSkillCount;
	}

	public static int[] calculateWorkerPerSkill(ArrayList<Worker> workerLinkedList,int maxSkill){
		int workerPerSkill[] = new int[maxSkill];
		for(Worker worker : workerLinkedList){
			workerPerSkill[worker.skill]++;
		}
		return workerPerSkill;
	}	

	public static int[] calculateJobsPerSkill(ArrayList<Job> jobLinkedList,int maxSkill){
		int jobsPerSkill[] = new int[maxSkill];
		for(Job job : jobLinkedList){
			if(job.skill<maxSkill){
				jobsPerSkill[job.skill]++;
			}
		}
		return jobsPerSkill;
	}

	public static void analizeWorkerList(ArrayList<Worker> workerLinkedList,ArrayList<MyBinaryHeap<Worker>> workers,int workerPerSkill[]){		
		for(Worker worker : workerLinkedList){
			if(worker.skill > (workers.size()-1)){
				MyBinaryHeap<Worker> workerPQ = new MyBinaryHeap<Worker>(workerPerSkill[worker.skill]);
				workerPQ.add(worker);
				workers.add(worker.skill,workerPQ);
			}else{
				MyBinaryHeap<Worker> workerPQ = workers.get(worker.skill);
				workerPQ.add(worker);
			}
		}
	}

	public static void analizeJobsList(String[] input2,ArrayList<Job> jobLinkedList){
		for(int i=0;i<input2.length;i++){
			String current = input2[i];
			StringTokenizer st = new StringTokenizer(current,"#");
			Job job = new Job();
			job.skill = (int)Integer.parseInt(new StringBuilder((String)st.nextElement()).deleteCharAt(0).toString()); 
			job.pri = (int)Integer.parseInt((String)st.nextElement()); 
			job.time = (int)Integer.parseInt((String)st.nextElement()); 
			job.id = (int)Integer.parseInt((String)st.nextElement());
			job.skill--;
			// int skillIndex = job.skill - 1;
			// if(skillIndex > (jobLinkedList.size()-1)){
			// 	ArrayList<Job> jobList = new ArrayList<Job>();
			// 	jobList.add(job);
			// 	jobLinkedList.addLast(jobList);
			// }else{
			// 	ArrayList<Job> jobList = jobLinkedList.get(skillIndex);
			// 	jobList.add(job);
			// }
			jobLinkedList.add(job);
		}
	}

	public static void setJobsBasedOnSkill(ArrayList<Job> jobLinkedList,ArrayList<ArrayList<Job>> jobs,int jobsPerSkill[],int maxSkill){
		ArrayList<Job> jobList = null;
		for(Job job : jobLinkedList){
			if(job.skill <maxSkill){
				if((job.skill > (jobs.size()-1)) || (jobs.get(job.skill) == null)){
					jobList = new ArrayList<Job>(jobsPerSkill[job.skill]);
					jobs.add(job.skill,jobList);
				}else{
					jobList = jobs.get(job.skill);
				}
				jobList.add(job);
			}
		}
	}

	public static void assignJobs(ArrayList<ArrayList<Job>> jobs, ArrayList<MyBinaryHeap<Worker>> workers,int maxSkill){
		for(int i=0;(i<jobs.size()) && (i<maxSkill);i++){
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

		ArrayList<Worker> workerArrayList = new ArrayList<Worker>();	
		ArrayList<Job> jobArrayList = new ArrayList<Job>();	
		
		int maxSkill = findMaxSkill(input1,workerArrayList); //W
		int workerPerSkill[] = calculateWorkerPerSkill(workerArrayList,maxSkill);
		System.out.println("maxSkill: "+maxSkill);
		
		ArrayList<MyBinaryHeap<Worker>>  workers = new ArrayList<MyBinaryHeap<Worker>> (maxSkill);	
		analizeWorkerList(workerArrayList,workers,workerPerSkill);  //J*()
		ArrayList<ArrayList<Job>> jobs = new ArrayList<ArrayList<Job>>(maxSkill);
		analizeJobsList(input2,jobArrayList);
		int jobsPerSkill[] = calculateJobsPerSkill(jobArrayList,maxSkill);
		setJobsBasedOnSkill(jobArrayList,jobs,jobsPerSkill,maxSkill);
		sortJobs(jobs); //J*log(J)
		//printJobList(jobs);
		assignJobs(jobs,workers,maxSkill); //J*log(W)

		return generateOutputString(workerArrayList);
	}

	public static String[] generateOutputString(ArrayList<Worker> workerLinkedList){

		ArrayList<String> output = new ArrayList<String>();
		for(Worker currentWoker : workerLinkedList){
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
		for(int i=1;i<=1000;i++){
			String worker = "W"+(i+1)+"#S1";
			workers.add(worker);
		}
		for(int i=1001;i<=2000;i++){
			String worker = "W"+(i+1)+"#S2";
			workers.add(worker);
		}
		for(int i=2001;i<=3000;i++){
			String worker = "W"+(i+1)+"#S3";
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
		for(int i=1;i<=100000;i++){
			double radians = Math.toRadians(i);	
			double sine = Math.sin(radians);
			double time = (100*sine);
			double priority = Math.abs(sine*100);
			String job = "S2#"+((int)priority)+"#"+((int)time)+"#"+(i+1);
			jobs.add(job);
		}
		for(int i=1;i<=100000;i++){
			double radians = Math.toRadians(i);	
			double sine = Math.sin(radians);
			double time = (100*sine);
			double priority = Math.abs(sine*100);
			String job = "S3#"+((int)priority)+"#"+((int)time)+"#"+(i+1);
			jobs.add(job);
		}
		for(int i=1;i<=100000;i++){
			double radians = Math.toRadians(i);	
			double sine = Math.sin(radians);
			double time = (100*sine);
			double priority = Math.abs(sine*100);
			String job = "S4#"+((int)priority)+"#"+((int)time)+"#"+(i+1);
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