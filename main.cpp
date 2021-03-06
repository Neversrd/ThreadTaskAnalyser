#include "Record.h"
#include "Util.h"
#include "ThreadTaskAnalyser.h"

int main(int argc, char **argv){
    /* test Record ------ right
    std::string testStr1("           <idle>-0     (-----) [003] d..3 2074248.139074: sched_switch: prev_comm=swapper/3 prev_pid=0 prev_prio=120 prev_state=R ==> next_comm=rcu_sched next_pid=8 next_prio=120");
    std::string testStr2(" 16444    SensorService-1328  ( 1205) [007] ...1 2074248.140149: tracing_mark_write: E");
    std::string testStr3("           <idle>-0     (-----) [005] dnh4 2074248.140180: sched_wakeup: comm=CDU-0-FrameProc pid=12774 prio=120 target_cpu=005");
    Record testRec1(testStr1);
    Record testRec2(testStr2);
    Record testRec3(testStr3);
    testRec1.print();
    testRec2.print();
    testRec3.print();*/
    ThreadTaskAnalyser analyser;
    std::string inFilename, outFilename;
    if(argc == 3){
        inFilename = std::string(*(argv + 1));
        outFilename = std::string(*(argv + 2));
    }else if(argc == 2){
        inFilename = std::string(*(argv + 1));
        std::cout << "Input the output filename you want to analyse:" << std::endl;
        std::cin >> outFilename;
    }else{
        std::cout << "Input the input and output filename you want to analyse:" << std::endl;
        std::cin >> inFilename;
        std::cin >> outFilename;
    }
    analyser.loadFile(inFilename, outFilename);
    return 0;
}