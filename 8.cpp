#include <iostream>
using namespace std;

struct Process
{
    int pid, arrival, burst, completion, turnaround, waiting; // all processes time values
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

void FCFS()
{
    int clock = 0;
    while (true)
    {
        // algorithm exit condition
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

        // selecting process that has arrived first
        Process *former_process = nullptr;
        for (int i = 0; i < process_count; i++)
        {
            Process *process = &process_list[i];
            if (!process->completed && process->arrival <= clock)
            {
                if (!former_process)
                {
                    former_process = process;
                }
                else if (former_process->arrival > process->arrival)
                {
                    former_process = process;
                }
            }
        }
        if (former_process)
        {
            clock += former_process->burst;
            former_process->completion = clock;
            former_process->turnaround = former_process->completion - former_process->arrival;
            former_process->waiting = former_process->turnaround - former_process->burst;
            former_process->completed = true;
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
    Process p1(0, 11);
    Process p2(0, 4);
    Process p3(0, 7);
    //Process p4(0, 4);
    InitialProcessTable();
    FCFS();
    FinalProcessTable();
    return 0;
}