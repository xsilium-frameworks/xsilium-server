#!/bin/bash
WORKSPACE=${1}
BUILD=$WORKSPACE"/build/"
REPORT=$WORKSPACE"/report/"

echo "Lancement des tests unitaire "

if [ ! -d "$REPORT" ]; then
    mkdir $REPORT
fi
cd $BUILD

cp $WORKSPACE"/src/Test/TestConfig.config" .

make UnitTester_coverage
mv *.xml $REPORT

cppcheck $WORKSPACE"/src" --enable=all --quiet --xml 2> $REPORT"cppcheck-result.xml"




