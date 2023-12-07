#include <iostream>
using namespace std;

struct Process
{
    int pid, priority, arrival, burst, completion, turnaround, waiting;
    bool completed = false;
    Process(){};
    Process(int _priority, int _arrival, int _burst);
};

int process_count = 0;
Process process_list[100];

Process::Process(int _priority,int _arrival, int _burst) : pid(++process_count), priority(_priority), arrival(_arrival), burst(_burst)
{
    process_list[process_count - 1] = *this;
}

void SJF()
{
    int clock=0;
    while (true)
    {
        // check exit condition
        bool exit = true;
        for (int i = 0; i < process_count; i++)
        {
            if (!process_list[i].completed)
            {
                exit = false;
                break;
            }
        }
        if (exit)
        {
            break;
        }
        // clock time+1 if no process has arrived yet
        bool idle = true;
        for (int i = 0; i < process_count; i++)
        {
            if (!process_list[i].completed && process_list[i].arrival <= clock)
            {
                idle = false;
                break;
            }
        }
        if (idle)
        {
            clock++;
        }
        //selecting priority process that has arrived
        Process* priority_process=nullptr;
        for (int i = 0; i < process_count; i++)
        {
            Process* process=&process_list[i];
            if (!process->completed && process->arrival<=clock)
            {
                if (!priority_process){
                    priority_process=process;
                }else if(process->priority<priority_process->priority){
                    priority_process=process;
                }
            }
        }
        //execute priority process
        if (priority_process){
            clock+=priority_process->burst;
            priority_process->completion=clock;
            priority_process->turnaround=priority_process->completion-priority_process->arrival;
            priority_process->waiting=priority_process->turnaround-priority_process->burst;
            priority_process->completed=true;
            
        }
    }
}

void InitialProcessTable()
{
    cout << "\nPID\tPriorityArrival\tBurst\tCompletion\tTurnaround\tWaiting" << endl;
    for (int process_id = 0; process_id < process_count; process_id++)
    {
        Process *process = &process_list[process_id];
        cout << "P" << process->pid << "\t"<< process->priority << "\t" << process->arrival << "\t" << process->burst << endl;
    }
}

void FinalProcessTable()
{
    cout << "\nPID\tPriorityArrival\tBurst\tCompletion\tTurnaround\tWaiting" << endl;
    float total_turnaround = 0;
    float total_waiting = 0;
    for (int process_id = 0; process_id < process_count; process_id++)
    {
        Process *process = &process_list[process_id];
        cout << "P" << process->pid << "\t"<< process->priority << "\t" << process->arrival << "\t" << process->burst << "\t" << process->completion << "\t\t" << process->turnaround << "\t\t" << process->waiting << "\t" << endl;
        total_turnaround += process->turnaround;
        total_waiting += process->waiting;
    }
    cout << "\nAverage turnaround time : " << total_turnaround / process_count;
    cout << "\nAverage waiting time : " << total_waiting / process_count;
}

int main()
{
    Process p1(1, 0,6);
    Process p2(2, 0,4);
    Process p3(3, 0,5);
    Process p4(4, 0,2);
    Process p5(5, 0,1);
    InitialProcessTable();
    SJF();
    FinalProcessTable();
    return 0;
}