for ((i = 1; i <= 27; i++)); do
    echo $i
    diff -w <(./sol < ./sms/tests/$i) <(cat < ./sms/tests/$i.a) || break
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    # diff -w <(./sol < in) <(./test < in) || break
done

