#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Linux Kernel and System Information using System Calls\n");

    // Display Kernel Version
    system("echo -n 'Kernel Version: '; cat /proc/sys/kernel/osrelease");

    // Display Kernel Architecture
    system("echo -e '\nKernel Architecture: '; uname -m");

    // Display Kernel Compile Time
    system("echo -e '\nKernel Compile Time: '; uname -v");

    // Display CPU Model
    system("echo -e '\nCPU Model: '; cat /proc/cpuinfo | grep -m1 'model name'");

    // Display CPU Architecture
    system("echo -e '\nCPU Architecture: '; cat /proc/cpuinfo | grep -m1 'architecture'");

    // Display Number of CPU Cores
    system("echo -e '\nNumber of CPU Cores: '; nproc");

    // Display Total Memory
    system("echo -e '\nTotal Memory: '; cat /proc/meminfo | grep -m1 'MemTotal'");

    // Display Free Memory
    system("echo -e '\nFree Memory: '; cat /proc/meminfo | grep -m1 'MemFree'");

    // Display Swap Information
    system("echo -e '\nSwap Information: '; cat /proc/meminfo | grep -m1 'SwapTotal'");

    return 0;
}
