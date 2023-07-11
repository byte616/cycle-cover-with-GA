#!/bin/bash
make
g++ prim.cpp -o prim
g++ MST.cpp -o MST
touch answer stdout stderr
rm answer stdout stderr
touch answer stdout stderr
for i in {1..50}
do
    ./cycle_cover --constructor="name=min-deploy B=1200 n=300 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=1800 n=300 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=2400 n=300 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=3000 n=300 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
    ./cycle_cover --constructor="name=min-deploy B=3600 n=300 problem=mccp solver='name=mccp demo=1'" --result >> answer 2> testcase
    ./prim < testcase >> stdout 2>> stderr
    ./MST < testcase >> stdout2 2>> stderr2
done
cat answer | grep "AVG" > record1
cat stdout | grep "AVG" >> record1
cat stdout2 | grep "AVG" >> record1
cat answer | grep "ANS" > record2
cat stdout | grep "ANS" >> record2
cat stdout2 | grep "ANS" >> record2
g++ sum_b.cpp -o sum_b
./sum_b < record2 > nodes_uavs.ans
./sum_b < record1 > nodes_uavs_tour.ans
