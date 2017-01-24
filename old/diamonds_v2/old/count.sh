echo "-----$1-----"
under=$(grep -c "slot-result-under" $1)
over=$(grep -c "slot-result-over" $1)
one=$(grep -c "slot-result-wildcard" $1)
between=$(grep -c "slot-result-mid" $1)
total=$(grep -c "slot-result" $1)

echo "Rolls that were <47.50: $under"
echo "Rolls that were >52.50: $over"
echo "Rolls that were <1.00: $one"
echo "Rolls that were 47.50<roll<52.50: $between"

r_under=$(echo "$under/$total*100" | bc -l)
echo "%under=$r_under"

r_over=$(echo "$over/$total*100" | bc -l)
echo "%over=$r_over"

r_one=$(echo "$one/$total*100" | bc -l)
echo "%one=$r_one"

r_between=$(echo "$between/$total*100" | bc -l)
echo "%between=$r_between"

#if [ "$r_under -gt $r_over" ]; then
#  echo "more unders than over, BET OVER"
#fi

echo "-------------------------"


