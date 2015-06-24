#!/bin/bash
WORKSPACE=${1}
BUILD=$WORKSPACE"/build/"
REPORT=$WORKSPACE"/report/"

echo "Lancement des tests unitaire "
mkdir $REPORT
cd $BUILD

cp $WORKSPACE"/bin/test/TestConfig.config" .

make UnitTester_coverage
mv *.xml $REPORT

cppcheck $WORKSPACE"/src" --enable=all --quiet --xml 2> $REPORT"cppcheck-result.xml"




