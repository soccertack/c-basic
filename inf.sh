#/bin/bash
while [ 1 ]
do
    ./r
    err=$?
    if [[ $err != 0 ]]; then
        break
    fi
done
