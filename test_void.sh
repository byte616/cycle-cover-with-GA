#!/bin/bash
make
g++ prim.cpp -o prim
g++ MST.cpp -o MST
touch answer stdout stderr stdout2 stderr2
rm answer stdout stderr stdout2 stderr2
touch answer stdout stderr stdout2 stderr2
for i in {1..2}
do
    ./cycle_cover --constructor="name=min-deploy B=1800 n=300 VOID=500 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=300 VOID=1000 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=300 VOID=1500 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=300 VOID=2000 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=300 VOID=2500 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
done
cat answer | grep "ANS2:" > record1
cat stdout2 | grep "ANS:" >> record1
cat stdout | grep "ANS:" >> record1
cat answer | grep "MIN_IOT" > record2
cat stdout2 | grep "MIN_IOT" >> record2
cat stdout | grep "MIN_IOT" >> record2
cat answer | grep "MAX_IOT:" > record3
cat stdout2 | grep "MAX_IOT:" >> record3
cat stdout | grep "MAX_IOT:" >> record3
cat answer | grep "AVG_IOT:" > record4
cat stdout2 | grep "AVG_IOT:" >> record4
cat stdout | grep "AVG_IOT:" >> record4

g++ sum_void.cpp -o sum_void
./sum_void < record1 > nodes_uavs.ans
./sum_void < record2 > nodes_uavs_min.ans
./sum_void < record3 > nodes_uavs_max.ans
./sum_void < record4 > nodes_uavs_avg.ans
