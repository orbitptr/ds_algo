#include <iostream>
#include <string>
#include <list>
using namespace std;
class Worker{
public:
	int skill;
	int waitingTime ;
	int desig;
public:
	Worker(int desig,int skill){
		//cout<<"Worker Constructor is called with desig:"<<desig<<" skill:"<<skill;
		waitingTime = 0;
		this->desig = desig;
		this->skill = skill;
	}
};

class Job{	
public:
	int runTime ;
	int skill;
	int id;
	Job(int id,int skill,int runTime){
		//cout<<"Job Constructor is called with id:"<<id<<" skill:"<<skill<<"Runtime"<<runTime;
		this->runTime = runTime;
		this->id = id;
		this->skill = skill;
	}
};



void printWorkers(vector< vector<Worker> > workers){
	cout<<endl<<"=======Printing workers"<<endl;
	cout<<endl<<"workers size:"<<workers.size()<<endl;
	vector< vector<Worker> >::iterator it;
	it=workers.begin();
	while(it!=workers.end()){
		std::vector<Worker> workerlist = *it;
		cout<<endl<<"workerlist size:"<<workerlist.size()<<endl;
		vector<Worker>::iterator workersIt = workerlist.begin();
		while(workersIt != workerlist.end()){
			Worker worker = *workersIt;
			cout<<endl<<"Worker Desig:"<<worker.desig<<" Skill: "<<worker.skill;
			workersIt++;
		}
		it++;
	}
}


list< list<Worker> > processWokers(const char** inworkers,int w){
	list< list<Worker> > workers;
	for(int i=0;i<w;i++){
		string worker_str(inworkers[i]);
		string desig_str = worker_str.substr(1,worker_str.find_first_of('#') -1);
		string skill_str = worker_str.substr(worker_str.find_first_of('#') +2,worker_str.length());
		//cout<<endl<<"desig str:"<<desig_str<<endl;
		//cout<<"skill str:"<<skill_str<<endl;
		int desig = stoi(desig_str);
		int skill = stoi(skill_str);
		//cout<<"desig int:"<<desig<<endl;
		//cout<<"skill int:"<<skill<<endl;
		//cout<<"workers size:"<<workers->size()<<endl;
		int skillindex = skill - 1;
		cout<<endl<<"skillindex:"<<skillindex;
		std::vector<Worker> workerlist;
		Worker worker(desig,skill);
		try{
			workerlist = workers.at(skillindex);
			workerlist.push_back(worker);
			cout<<endl<<"skill--->"<<skillindex<<"present in list"<<endl;
		}catch(...){
			cout<<endl<<"skill--->"<<skillindex<<"not in list"<<endl;
			workerlist.push_back(worker);
			workers.insert(workers.begin()+skillindex,workerlist);
		}
		cout<<endl<<"(*workerlist) size before push--->"<<workerlist.size()<<endl;		
	}
	return workers;
}

int main(){
	const char* inworkers[] = {"W1#S1","W2#S2","W3#S3","W4#S1"};
	const char* injobs[] = {
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
	int w = (sizeof(inworkers)/sizeof(char*));
	int j = (sizeof(injobs)/sizeof(char*));
	cout<<"sizeof(workers): "<<w<<endl;
	cout<<"sizeof(jobs): "<<j<<endl;

	list< list<Worker> > workers = processWokers(inworkers,w);
	printWorkers(workers);
	return 0;
}











