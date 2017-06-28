
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class CandidateCode {
	/*
	 * Complete the function below.
	*/

	public static class Job{
		public int pri;
		public int skill;
		public int time;
		public int id;
		@Override
		public String toString(){
			String str = " pri:"+pri + " time:"+ time+" id:"+id;
			return str;
		}
	}

	public static class Worker{
		public ArrayList<Job> jobList = null;
		public int waitTime = 0;
		int id;
		int skill;
	}

	public static void analizeWorkerList(String[] input1,ArrayList<Worker> workerListByDesignation,ArrayList<ArrayList<Worker>> workers){
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
				ArrayList<Worker> workerList = new ArrayList<Worker>();
				workerList.add(worker);
				workers.add(workerList);
			}else{
				ArrayList<Worker> workerList = workers.get(skillIndex);
				workerList.add(worker);
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
	public static void assignJobs(ArrayList<ArrayList<Job>> jobs, ArrayList<ArrayList<Worker>> workers){
		for(int i=0;i<jobs.size();i++){
			ArrayList<Job> currentJobList = jobs.get(i);
			ArrayList<Worker> workerList = workers.get(i);
			for(int j=0;j<currentJobList.size();j++){
				Job currentJob = currentJobList.get(j);
				if(i>=0 && i<workers.size()){    				
					Worker selectedWorker =  workerList.get(0);
					if(selectedWorker != null){
						if(selectedWorker.jobList == null){
							selectedWorker.jobList = new ArrayList<Job>();
						}
						selectedWorker.jobList.add(currentJob);
						selectedWorker.waitTime+= currentJob.time;
					}
					//optimize here
					workerList.remove(0);
					workerList.trimToSize();
					binarySearchAndInsert(workerList,selectedWorker);
					// WorkerWaitingTimeComparator wokerComp = new WorkerWaitingTimeComparator();
					// Collections.sort(workerList,wokerComp);
				}
			}
		}
	}

	public static void binarySearchAndInsert(ArrayList<Worker> workerList,Worker newItem){
		int positionToInsert = -1;
		int start = 0;
		int end = workerList.size()-1;
		while(true){
			if(start>end){
				positionToInsert = start;
				break;
			}
			int middle = (end+start)/2;
			Worker middleElem = workerList.get(middle);
			if(middleElem.waitTime == newItem.waitTime){
				if(newItem.id < middleElem.id){
					end = middle-1;
				}else if( newItem.id> middleElem.id){
					start = middle+1;
				}
			}else if(newItem.waitTime < middleElem.waitTime){
				end = middle-1;
			}else if(newItem.waitTime>middleElem.waitTime){
				start = middle+1;
			}   		
		}
		//if(newItem.skill ==0 || newItem.skill == 3)
		System.out.println("newItem.skill : " + newItem.skill  + "positionToInsert is :"+positionToInsert);
		workerList.add(positionToInsert,newItem);
	}

	public static void sortJobs(ArrayList<ArrayList<Job>> jobs){
		JobsComparator comp = new JobsComparator();
		for(int i=0;i<jobs.size();i++){
			ArrayList<Job> jobList = jobs.get(i);
			Collections.sort(jobList,comp );
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
		ArrayList<ArrayList<Worker>> workers = new ArrayList<ArrayList<Worker>>();	
		ArrayList<ArrayList<Job>> jobs = new ArrayList<ArrayList<Job>>();
		analizeWorkerList(input1,workerListByDesignation,workers); 
		analizeJobsList(input2,jobs);
		sortJobs(jobs); //J*log(J)
		printJobList(jobs);
		assignJobs(jobs,workers);	
		return generateOutputString(workerListByDesignation);
	}

	public static String[] generateOutputString(ArrayList<Worker> workerListByDesignation){
		ArrayList<String> output = new ArrayList<String>();
		for(int i=0;i<workerListByDesignation.size();i++){
			Worker currentWoker = workerListByDesignation.get(i);
			if(currentWoker.jobList != null && currentWoker.jobList.size()>0){
				// String currentJobList = "W";
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

	public static  class WorkerWaitingTimeComparator implements Comparator<Worker> {
		@Override
		public  int  compare(Worker worker1, Worker worker2) {
			if(worker1.waitTime != worker2.waitTime){
				return (worker1.waitTime)-(worker2.waitTime);
			}else{
				return (worker1.id)-(worker2.id);
			}
		}
	}


	public static  class JobsComparator implements Comparator<Job> {
		@Override
		public  int  compare(Job job1, Job job2) {
			if(job1.pri != job2.pri){
				return (job2.pri)-(job1.pri);
			}else{
				return (job1.time)-(job2.time);
			}
		}
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
		// Scanner in = new Scanner(System.in);
		String[] output = null;
		// int ip1_size = 0;
		// ip1_size = Integer.parseInt(in.nextLine().trim());
		// String[] ip1 = new String[ip1_size];
		// String ip1_item;
		// for(int ip1_i = 0; ip1_i < ip1_size; ip1_i++) {
		//     try {
		// ip1_item = in.nextLine();
		//     } catch (Exception e) {
		// ip1_item = null;
		//     }
		//     ip1[ip1_i] = ip1_item;
		// }
		// int ip2_size = 0;
		// ip2_size = Integer.parseInt(in.nextLine().trim());
		// String[] ip2 = new String[ip2_size];
		// String ip2_item;
		// for(int ip2_i = 0; ip2_i < ip2_size; ip2_i++) {
		//     try {
		// ip2_item = in.nextLine();
		//     } catch (Exception e) {
		// ip2_item = null;
		//     }
		//     ip2[ip2_i] = ip2_item;
		// }
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
		// {
		// 	"S1#40#10#101",
		// 	"S1#10#5#102",
		// 	"S1#90#15#103",
		// 	"S1#91#20#104",
		// 	"S1#20#5#105",
		// 	"S1#20#10#106",
		// 	"S1#90#15#107",
		// 	"S1#30#20#108",
		// 	"S1#40#5#109",
		// 	"S1#50#5#110"};
			output = warehouseScalability(ip1,ip2);
			for(int output_i=0; output_i < output.length; output_i++) {
				System.out.println(String.valueOf(output[output_i]));
			}
		}
	}