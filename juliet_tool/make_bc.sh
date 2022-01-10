#!/bin/bash

set -e

if [ "$#" -lt 1 ]; then
    echo "Usage: ./$0 <target_dir>"
    exit
fi

base_dir=$1
cd $base_dir

for dname in $base_dir/*; do
    cd $dname
    echo $dname
    rm -rf klee-*
    #rm *.bc

    path=$dname/s01
    if [ -d "$path" ]; then
        for subname in $dname/*; do
            cd $subname
            rm -rf klee-*
            find . -executable -type f | xargs -I '{}' extract-bc '{}'

            #cp ~/testing-env.sh .
            #env -i /bin/bash -c '(source testing-env.sh; env >test.env)'
        done
    else
        find . -executable -type f | xargs -I '{}' extract-bc '{}'

        #cp ~/testing-env.sh .
        #env -i /bin/bash -c '(source testing-env.sh; env >test.env)'

    fi

done
