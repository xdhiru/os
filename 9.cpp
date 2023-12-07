#include <iostream>
using namespace std;

struct Process
{
    int pid, arrival, burst, completion, turnaround, waiting;
    bool completed = false;
    Process(){};
    Process(int _arrival, int _burst);
};

int process_count = 0;
Process process_list[100];

Process::Process(int _arrival, int _burst) : pid(++process_count), arrival(_arrival), burst(_burst)
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
        //selecting shortest process that has arrived
        Process* shortest_process=nullptr;
        for (int i = 0; i < process_count; i++)
        {
            Process* process=&process_list[i];
            if (!process->completed && process->arrival<=clock)
            {
                if (!shortest_process){
                    shortest_process=process;
                }else if(process->burst<shortest_process->burst){
                    shortest_process=process;
                }
            }
        }
        //execute shortest process
        if (shortest_process){
            clock+=shortest_process->burst;
            shortest_process->completion=clock;
            shortest_process->turnaround=shortest_process->completion-shortest_process->arrival;
            shortest_process->waiting=shortest_process->turnaround-shortest_process->burst;
            shortest_process->completed=true;
            
        }
    }
}

void InitialProcessTable()
{
    cout << "\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting" << endl;
    for (int process_id = 0; process_id < process_count; process_id++)
    {
        Process *process = &process_list[process_id];
        cout << "P" << process->pid << "\t" << process->arrival << "\t" << process->burst << endl;
    }
}

void FinalProcessTable()
{
    cout << "\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting" << endl;
    float total_turnaround = 0;
    float total_waiting = 0;
    for (int process_id = 0; process_id < process_count; process_id++)
    {
        Process *process = &process_list[process_id];
        cout << "P" << process->pid << "\t" << process->arrival << "\t" << process->burst << "\t" << process->completion << "\t\t" << process->turnaround << "\t\t" << process->waiting << "\t" << endl;
        total_turnaround += process->turnaround;
        total_waiting += process->waiting;
    }
    cout << "\nAverage turnaround time : " << total_turnaround / process_count;
    cout << "\nAverage waiting time : " << total_waiting / process_count;
}

int main()
{
    Process p1(1, 3);
    Process p2(2, 4);
    Process p3(1, 2);
    Process p4(4, 4);
    InitialProcessTable();
    SJF();
    FinalProcessTable();
    return 0;
}