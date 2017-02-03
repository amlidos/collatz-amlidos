for f in collatz-tests/*.in; do
    filename="${f%.*}"
    touch $filename.diff
    chmod +x $filename.diff
    diff $filename.out <(./RunCollatz < $filename.in) > $filename.diff
    if [ -s $filename.diff ]
    then
	echo [FAILED] $filename
    else
	echo [PASSED] $filename
    fi
done