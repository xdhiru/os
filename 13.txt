//Ques8: Write a program to implement First come First Serve (FCFS) scheduling algorithm.


#include<iostream>
using namespace std;

void WaitingTime(int processes[], int n, 
						int bt[], int wt[])
{

	wt[0] = 0;


	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}


void TurnAroundTime( int processes[], int n, 
				int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void avgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;


	WaitingTime(processes, n, bt, wt);

	TurnAroundTime(processes, n, bt, wt, tat);


	cout <<"Processes "<<" Burst time "
		<<" Waiting time "<<"Turn around time\n";


	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}


int main()
{
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	int burst_time[] = {11, 4, 7};

	avgTime(processes, n, burst_time);
	return 0;
}


//Ques: 9 Write a program to implement Shortest Job First (SJF) scheduling algorithm.

#include <iostream>
using namespace std;

int main() {

	int A[100][4];
	int i,j,n,total= 0,index,temp;
	float avg_wt, avg_tat;

	cout<<"Enter number of process: ";
	cin>>n;

	cout<<"Enter Burst Time:"<<endl;


	for (i = 0; i < n; i++) {
		cout << "P" << i + 1 << ": ";
		cin >> A[i][1];
		A[i][0] = i + 1;
	}


	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}

	A[0][2] = 0;

	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}

	avg_wt = (float)total/n;
	total = 0;
	cout << "P	 BT	 WT	 TAT" << endl;

	for (i = 0; i<n;i++) {
		A[i][3] = A[i][1] + A[i][2];
		total +=A[i][3];
		cout<<"P" << A[i][0]<<"	 "<<A[i][1]<<"	 "<< A[i][2] <<"	 "<<A[i][3]<<endl;
	}

	avg_tat=(float)total / n;
	cout<<"Average Waiting Time= "<<avg_wt<<endl;
	cout<<"Average Turnaround Time= "<<avg_tat<<endl;
}


//Ques10: Write a program to implement non-preemptive priority based scheduling algorithm. Solution

#include<iostream>
using namespace std;

struct Process {
    int pid;
    int priority;
    int burst_time;
};

void priorityScheduling(Process proc[], int n) {
    int total_wt_time=0;
    int total_ta_time=0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;j++) {
            if (proc[i].priority>proc[j].priority) {
                swap(proc[i], proc[j]);
            }
        }
    }

    cout<<"Priority Scheduling: "<<endl;
    cout<<"Process ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;

    int total_time = 0;
    for (int i = 0; i<n;i++) {
        total_time += proc[i].burst_time;
        int wt_time = total_time - proc[i].burst_time;
        int ta_time = total_time;

        total_wt_time += wt_time;
        total_ta_time += ta_time;

        cout << proc[i].pid<<"\t\t"<<proc[i].priority<<"\t\t"<<proc[i].burst_time<<"\t\t"<<wt_time<<"\t\t"<<ta_time<<endl;
    }

    double avg_wt_time = (double)total_wt_time/n;
    double avg_ta_time = (double)total_ta_time/n;
    cout<<"Average Waiting Time: "<<avg_wt_time<<endl;
    cout<<"Average Turnaround Time: "<<avg_ta_time<<endl;
}

int main() {
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    Process proc[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter Process ID, Priority, and Burst Time for Process "<<i + 1<<" : ";
        cin>>proc[i].pid>>proc[i].priority>>proc[i].burst_time;
    }

    priorityScheduling(proc, n);

    return 0;
}

