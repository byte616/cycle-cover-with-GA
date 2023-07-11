#!/bin/bash
make
g++ prim.cpp -o prim
g++ MST.cpp -o MST
touch answer stdout stderr
rm answer stdout stderr
touch answer stdout stderr
for i in {1..50}
do
    ./cycle_cover --constructor="name=min-deploy B=1800 n=100 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=200 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=300 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=400 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=500 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
done
cat answer | grep "AVG" > record1
cat stdout | grep "AVG" >> record1
cat stdout2 | grep "AVG" >> record1
cat answer | grep "ANS" > record2
cat stdout | grep "ANS" >> record2
cat stdout2 | grep "ANS" >> record2
g++ sum_n.cpp -o sum_n
./sum_n < record2 > nodes_uavs.ans
./sum_n < record1 > nodes_uavs_tour.ans
