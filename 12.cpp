#include <iostream>
using namespace std;

const int MAX = 100;

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;

        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "First Fit Allocation: " << endl;
    cout << "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}


void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;

        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "Best Fit Allocation: " << endl;
    cout << "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}


void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;

        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1)
                    worstIdx = j;
                else if (blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "Worst Fit Allocation: " << endl;
    cout << "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int blockSize[MAX], processSize[MAX], m, n, choice;
    cout << "Enter the number of memory blocks: ";
    cin >> m;
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the size of memory blocks: ";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    cout << "Enter the size of processes: ";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    cout << "Choose the allocation strategy: " << endl;
    cout << "1. First Fit" << endl;
    cout << "2. Best Fit" << endl;
    cout << "3. Worst Fit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            firstFit(blockSize, m, processSize, n);
            break;
        case 2:
            bestFit(blockSize, m, processSize, n);
            break;
        case 3:
            worstFit(blockSize, m, processSize, n);
            break;
        default:
            cout << "Invalid Choice";
    }

    return 0;
}


/*
OUTPUT:
Enter the number of memory blocks: 5
Enter the number of processes: 4
Enter the size of memory blocks: 2
5
4
7
3
Enter the size of processes: 4
5
9
2
Choose the allocation strategy: 
1. First Fit
2. Best Fit
3. Worst Fit
Enter your choice: 2
Best Fit Allocation: 
Process No.     Process Size    Block no.
 1              4               3
 2              5               2
 3              9               Not Allocated
 4              2               1



*/